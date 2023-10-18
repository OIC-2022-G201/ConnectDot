/*************************************************************************//*!
					
					@file	Queue.inl
					@brief	�L���[

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�R���X�g���N�^
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
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CQueue< T >::~CQueue(){
	Release();
}
		
/*************************************************************************//*!
		@brief			�f�[�^�̒ǉ�
		@param[in]		val				�ǉ��f�[�^

		@return			TRUE			����I��<br>
						����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
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
		@brief			�f�[�^�̎��o��
		@param			None

		@return			�m�[�h�f�[�^
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
		@brief			���
		@param[in]		pData			����ǉ��f�[�^

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
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
		@brief			�m�[�h�����擾
		@param			None

		@return			�m�[�h����
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CQueue< T >::GetCount(void){
	m_Lock.Lock();
	MofU32 re = m_Count;
	m_Lock.UnLock();
	return re;
}

//[EOF]