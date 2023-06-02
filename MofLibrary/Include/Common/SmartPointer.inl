/*************************************************************************//*!
					
					@file	SmartPointer.cpp
					@brief	�X�}�[�g�|�C���^�N���X

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
template< typename T > FORCE_INLINE CSmartPointer< T >::CSmartPointer() :
m_pPtr(NULL) ,
m_pRefCount(NULL) {
}

/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		p		�ۑ��f�[�^

		@return			None
*//**************************************************************************/
template< typename T > FORCE_INLINE CSmartPointer< T >::CSmartPointer(T* p) :
m_pPtr(p) ,
m_pRefCount(NULL) {
	AddRef();
}

/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj			�R�s�[�I�u�W�F�N�g

		@return			None
*//**************************************************************************/
template< typename T > FORCE_INLINE CSmartPointer< T >::CSmartPointer(const CSmartPointer<T>& pObj) :
m_pPtr(pObj.m_pPtr) ,
m_pRefCount(pObj.m_pRefCount) {
	AddRef();
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^<br>
						�����̕ۑ����Ă���^�Ǝ����ϊ��\�ȏꍇ�̂�
		@param[in]		pObj			�R�s�[�I�u�W�F�N�g

		@return			None
*//**************************************************************************/
template< typename T > template< typename U > FORCE_INLINE CSmartPointer< T >::CSmartPointer(const CSmartPointer<U>& pObj) :
m_pPtr(pObj.m_pPtr) ,
m_pRefCount(pObj.m_pRefCount) {
	AddRef();
}
/*************************************************************************//*!
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
template< typename T > FORCE_INLINE CSmartPointer< T >::~CSmartPointer(){
	Release();
}
/*************************************************************************//*!
		@brief			�Q�W���̒ǉ�<br>
						���݂̃f�[�^�Q�Ɛ��𑝉�������B<br>
						�쐬���A�R�s�[���ɓ����Ŏ����I�Ɏ��s�����B
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
		@brief			���
		@param[in]		pData			����ǉ��f�[�^

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
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
		@brief			�Q�Ǝ擾
		@param			None

		@return			�Q��
*//**************************************************************************/
template< typename T > FORCE_INLINE T* CSmartPointer< T >::GetPointer(void){
	return m_pPtr;
}
/*************************************************************************//*!
		@brief			�Q�Ɛ��擾
		@param			None

		@return			�Q�Ɛ�
*//**************************************************************************/
template< typename T > FORCE_INLINE MofU32 CSmartPointer< T >::GetReferenceCounter(void){
	if(m_pRefCount)
	{
		return (*m_pRefCount);
	}
	return 0;
}
/*************************************************************************//*!
		@brief			���<br>
						�����Q�Ƃ�ύX���đ���Ώۂ̎Q�Ƃ𑝉�������B
*//**************************************************************************/
template < typename T > FORCE_INLINE CSmartPointer<T>& CSmartPointer< T >::operator = (T* p){
	//�����łȂ��ꍇ�Ɍ���
	if(m_pPtr == p)
	{
		return (*this);
	}
	//�Â��̍폜
	Release();
	//�Q�Ƒ��
	if(p)
	{
		m_pPtr = p;
		AddRef();
	}
	return (*this);
}
/*************************************************************************//*!
		@brief			���<br>
						�����Q�Ƃ�ύX���đ���Ώۂ̎Q�Ƃ𑝉�������B
*//**************************************************************************/
template < typename T > FORCE_INLINE CSmartPointer<T>& CSmartPointer< T >::operator = (const CSmartPointer<T>& p){
	//�����łȂ��ꍇ�Ɍ���
	if(m_pPtr == p.m_pPtr)
	{
		return (*this);
	}
	//�Â��̍폜
	Release();
	//�Q�Ƒ��
	if(p.m_pPtr)
	{
		m_pPtr = p.m_pPtr;
		m_pRefCount = p.m_pRefCount;
		AddRef();
	}
	return (*this);
}
/*************************************************************************//*!
		@brief			���<br>
						�����Q�Ƃ�ύX���đ���Ώۂ̎Q�Ƃ𑝉�������B
*//**************************************************************************/
template < typename T > template< typename U > FORCE_INLINE CSmartPointer<T>& CSmartPointer< T >::operator = (const CSmartPointer<U>& p){
	//�����łȂ��ꍇ�Ɍ���
	if(m_pPtr == p.m_pPtr)
	{
		return (*this);
	}
	//�Â��̍폜
	Release();
	//�Q�Ƒ��
	if(p.m_pPtr)
	{
		m_pPtr = p.m_pPtr;
		m_pRefCount = p.m_pRefCount;
		AddRef();
	}
	return (*this);
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
template < typename T > FORCE_INLINE bool CSmartPointer< T >::operator == (const CSmartPointer<T>& p) const{
	if(m_pPtr == p.m_pPtr)
	{
		return true;
	}
	return false;
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
template < typename T > FORCE_INLINE bool CSmartPointer< T >::operator == (T* p) const{
	if(m_pPtr == p)
	{
		return true;
	}
	return false;
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
template < typename T > FORCE_INLINE bool CSmartPointer< T >::operator != (const CSmartPointer<T>& p) const{
	if(m_pPtr != p.m_pPtr)
	{
		return true;
	}
	return false;
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
template < typename T > FORCE_INLINE bool CSmartPointer< T >::operator != (T* p) const{
	if(m_pPtr != p)
	{
		return true;
	}
	return false;
}
/*************************************************************************//*!
		@brief			�����|�C���^�ւ̃A�N�Z�X<br>
						�Q�Ƃ̊O���ł̒��ډ���͍s��Ȃ�����
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CSmartPointer< T >::operator * (){
	return *m_pPtr;
}
/*************************************************************************//*!
		@brief			�����|�C���^�ւ̃A�N�Z�X<br>
						�Q�Ƃ̊O���ł̒��ډ���͍s��Ȃ�����
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CSmartPointer< T >::operator * () const {
	return *m_pPtr;
}
/*************************************************************************//*!
		@brief			�����|�C���^�f�[�^�ւ̃A�N�Z�X<br>
						�Q�Ƃ̊O���ł̒��ډ���͍s��Ȃ�����
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CSmartPointer< T >::operator -> (){
	return m_pPtr;
}
/*************************************************************************//*!
		@brief			�����|�C���^�f�[�^�ւ̃A�N�Z�X<br>
						�Q�Ƃ̊O���ł̒��ډ���͍s��Ȃ�����
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CSmartPointer< T >::operator -> () const {
	return m_pPtr;
}

//[EOF]