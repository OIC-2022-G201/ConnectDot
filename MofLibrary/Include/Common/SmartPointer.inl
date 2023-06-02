/*************************************************************************//*!
					
					@file	SmartPointer.cpp
					@brief	スマートポインタクラス

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template< typename T > FORCE_INLINE CSmartPointer< T >::CSmartPointer() :
m_pPtr(NULL) ,
m_pRefCount(NULL) {
}

/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		p		保存データ

		@return			None
*//**************************************************************************/
template< typename T > FORCE_INLINE CSmartPointer< T >::CSmartPointer(T* p) :
m_pPtr(p) ,
m_pRefCount(NULL) {
	AddRef();
}

/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj			コピーオブジェクト

		@return			None
*//**************************************************************************/
template< typename T > FORCE_INLINE CSmartPointer< T >::CSmartPointer(const CSmartPointer<T>& pObj) :
m_pPtr(pObj.m_pPtr) ,
m_pRefCount(pObj.m_pRefCount) {
	AddRef();
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ<br>
						自分の保存している型と自動変換可能な場合のみ
		@param[in]		pObj			コピーオブジェクト

		@return			None
*//**************************************************************************/
template< typename T > template< typename U > FORCE_INLINE CSmartPointer< T >::CSmartPointer(const CSmartPointer<U>& pObj) :
m_pPtr(pObj.m_pPtr) ,
m_pRefCount(pObj.m_pRefCount) {
	AddRef();
}
/*************************************************************************//*!
		@brief			デストラクタ
		@param			None

		@return			None
*//**************************************************************************/
template< typename T > FORCE_INLINE CSmartPointer< T >::~CSmartPointer(){
	Release();
}
/*************************************************************************//*!
		@brief			参集数の追加<br>
						現在のデータ参照数を増加させる。<br>
						作成時、コピー時に内部で自動的に実行される。
		@param			None

		@return			None
*//**************************************************************************/
template< typename T > FORCE_INLINE void CSmartPointer< T >::AddRef(void){
	if(m_pRefCount)
	{
		(*m_pRefCount)++;
	}
	else
	{
		m_pRefCount = (MofU32*)MOF_ALLOCATOR(sizeof(MofU32),"CSmartPointer");
		(*m_pRefCount)++;
	}
	return;
}
/*************************************************************************//*!
		@brief			解放
		@param[in]		pData			解放追加データ

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
template< typename T > FORCE_INLINE MofBool CSmartPointer< T >::Release(LPMofVoid pData){
	if(m_pRefCount)
	{
		(*m_pRefCount)--;
		if(*m_pRefCount <= 0)
		{
			MOF_SAFE_DELETE(m_pPtr);
			MOF_SAFE_FREE(m_pRefCount,"CSmartPointer");
		}
	}
	m_pPtr = NULL;
	m_pRefCount = NULL;
	return TRUE;
}
/*************************************************************************//*!
		@brief			参照取得
		@param			None

		@return			参照
*//**************************************************************************/
template< typename T > FORCE_INLINE T* CSmartPointer< T >::GetPointer(void){
	return m_pPtr;
}
/*************************************************************************//*!
		@brief			参照数取得
		@param			None

		@return			参照数
*//**************************************************************************/
template< typename T > FORCE_INLINE MofU32 CSmartPointer< T >::GetReferenceCounter(void){
	if(m_pRefCount)
	{
		return (*m_pRefCount);
	}
	return 0;
}
/*************************************************************************//*!
		@brief			代入<br>
						内部参照を変更して代入対象の参照を増加させる。
*//**************************************************************************/
template < typename T > FORCE_INLINE CSmartPointer<T>& CSmartPointer< T >::operator = (T* p){
	//同じでない場合に限る
	if(m_pPtr == p)
	{
		return (*this);
	}
	//古いの削除
	Release();
	//参照代入
	if(p)
	{
		m_pPtr = p;
		AddRef();
	}
	return (*this);
}
/*************************************************************************//*!
		@brief			代入<br>
						内部参照を変更して代入対象の参照を増加させる。
*//**************************************************************************/
template < typename T > FORCE_INLINE CSmartPointer<T>& CSmartPointer< T >::operator = (const CSmartPointer<T>& p){
	//同じでない場合に限る
	if(m_pPtr == p.m_pPtr)
	{
		return (*this);
	}
	//古いの削除
	Release();
	//参照代入
	if(p.m_pPtr)
	{
		m_pPtr = p.m_pPtr;
		m_pRefCount = p.m_pRefCount;
		AddRef();
	}
	return (*this);
}
/*************************************************************************//*!
		@brief			代入<br>
						内部参照を変更して代入対象の参照を増加させる。
*//**************************************************************************/
template < typename T > template< typename U > FORCE_INLINE CSmartPointer<T>& CSmartPointer< T >::operator = (const CSmartPointer<U>& p){
	//同じでない場合に限る
	if(m_pPtr == p.m_pPtr)
	{
		return (*this);
	}
	//古いの削除
	Release();
	//参照代入
	if(p.m_pPtr)
	{
		m_pPtr = p.m_pPtr;
		m_pRefCount = p.m_pRefCount;
		AddRef();
	}
	return (*this);
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
template < typename T > FORCE_INLINE bool CSmartPointer< T >::operator == (const CSmartPointer<T>& p) const{
	if(m_pPtr == p.m_pPtr)
	{
		return true;
	}
	return false;
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
template < typename T > FORCE_INLINE bool CSmartPointer< T >::operator == (T* p) const{
	if(m_pPtr == p)
	{
		return true;
	}
	return false;
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
template < typename T > FORCE_INLINE bool CSmartPointer< T >::operator != (const CSmartPointer<T>& p) const{
	if(m_pPtr != p.m_pPtr)
	{
		return true;
	}
	return false;
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
template < typename T > FORCE_INLINE bool CSmartPointer< T >::operator != (T* p) const{
	if(m_pPtr != p)
	{
		return true;
	}
	return false;
}
/*************************************************************************//*!
		@brief			内部ポインタへのアクセス<br>
						参照の外部での直接解放は行わないこと
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CSmartPointer< T >::operator * (){
	return *m_pPtr;
}
/*************************************************************************//*!
		@brief			内部ポインタへのアクセス<br>
						参照の外部での直接解放は行わないこと
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CSmartPointer< T >::operator * () const {
	return *m_pPtr;
}
/*************************************************************************//*!
		@brief			内部ポインタデータへのアクセス<br>
						参照の外部での直接解放は行わないこと
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CSmartPointer< T >::operator -> (){
	return m_pPtr;
}
/*************************************************************************//*!
		@brief			内部ポインタデータへのアクセス<br>
						参照の外部での直接解放は行わないこと
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CSmartPointer< T >::operator -> () const {
	return m_pPtr;
}

//[EOF]