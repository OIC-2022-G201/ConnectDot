/*************************************************************************//*!
					
					@file	Thread.inl
					@brief	�X���b�h���쐬���s���邽�߂̊��C���^�[�t�F�C�X�ƃN���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���
		@param[in]		pData			����ǉ��f�[�^

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CThread::Release(LPMofVoid pData){
	return Join();
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CThread::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CThread::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CRunnable::CRunnable() {
}
/*************************************************************************//*!
		@brief			���
		@param[in]		pData			����ǉ��f�[�^

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CRunnable::Release(LPMofVoid pData){
	return TRUE;
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			pRunnable		�����̏�������

		@return			None
*//**************************************************************************/
FORCE_INLINE CRunnableThread::CRunnableThread(LPRunnable pRunnable) : 
CThread() ,
m_pRunnable(pRunnable) {
}
/*************************************************************************//*!
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CRunnableThread::~CRunnableThread(){
	Release();
}
/*************************************************************************//*!
		@brief			�X���b�h�̓������s����<br>
						�R���X�g���N�^�ŗ^����ꂽ��CRunnable��Run�����s����B
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CRunnableThread::Run(void){
	if(m_pRunnable)
	{
		m_pRunnable->Run();
	}
	return;
}
/*************************************************************************//*!
		@brief			���
		@param[in]		pData			����ǉ��f�[�^

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CRunnableThread::Release(LPMofVoid pData){
	if(Join())
	{
		MOF_SAFE_DELETE(m_pRunnable);
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			f				�����̏����R�[���o�b�N

		@return			None
*//**************************************************************************/
template < typename Func > FORCE_INLINE CCallbackThread::CCallbackThread(Func f) :
CThread() ,
m_pFunc(new CallbackFuncImpl<Func>(f)) {
}
/*************************************************************************//*!
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CCallbackThread::~CCallbackThread(){
	Release();
}
/*************************************************************************//*!
		@brief			�X���b�h�̓������s����<br>
						�R���X�g���N�^�ŗ^����ꂽ��CRunnable��Run�����s����B
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CCallbackThread::Run(void){
	(*m_pFunc)();
}
/*************************************************************************//*!
		@brief			���
		@param[in]		pData			����ǉ��f�[�^

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCallbackThread::Release(LPMofVoid pData){
	if(Join())
	{
		MOF_SAFE_DELETE(m_pFunc);
		return TRUE;
	}
	return FALSE;
}

//[EOF]