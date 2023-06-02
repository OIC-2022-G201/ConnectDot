/*************************************************************************//*!
					
					@file	Queue.inl
					@brief	キュー

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CQueue< T >::CQueue() :
m_pHead(NULL) ,
m_pTail(NULL) ,
m_Count(0) ,
m_Lock() {
}
/*************************************************************************//*!
		@brief			デストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CQueue< T >::~CQueue(){
	Release();
}
		
/*************************************************************************//*!
		@brief			データの追加
		@param[in]		val				追加データ

		@return			TRUE			正常終了<br>
						それ以外		エラー、エラーコードを返す。
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CQueue< T >::Push(T val){
	m_Lock.Lock();
	LPNODE pNode = new NODE();
	pNode->Value = val;
	pNode->pNext = NULL;
	if (m_pTail)
	{
		m_pTail->pNext = pNode;
	}
	else
	{
		m_pTail = pNode;
	}
	if (!m_pHead)
	{
		m_pHead = pNode;
	}
	m_pTail = pNode;
	m_Count++;
	m_Lock.UnLock();
	return TRUE;
}
/*************************************************************************//*!
		@brief			データの取り出し
		@param			None

		@return			ノードデータ
*//**************************************************************************/
template < typename T > FORCE_INLINE T CQueue< T >::Pop(void){
	T pr = T();
	m_Lock.Lock();
	if (m_pHead)
	{
		LPNODE tmp = m_pHead;
		pr = m_pHead->Value;
		if (m_pHead->pNext)
		{
			m_pHead = m_pHead->pNext;
		}
		else
		{
			m_pHead = NULL;
			m_pTail = NULL;
		}
		m_Count--;
		MOF_SAFE_DELETE(tmp);
	}
	m_Lock.UnLock();
	return pr;
}
		
/*************************************************************************//*!
		@brief			解放
		@param[in]		pData			解放追加データ

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CQueue< T >::Release(LPMofVoid pData){
	m_Lock.Lock();
	while (m_pHead)
	{
		LPNODE tmp = m_pHead;
		m_pHead = m_pHead->pNext;
		MOF_SAFE_DELETE(tmp);
	}
	m_Lock.UnLock();
	m_Count = 0;
	return TRUE;
}
/*************************************************************************//*!
		@brief			ノード件数取得
		@param			None

		@return			ノード件数
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CQueue< T >::GetCount(void){
	m_Lock.Lock();
	MofU32 re = m_Count;
	m_Lock.UnLock();
	return re;
}

//[EOF]