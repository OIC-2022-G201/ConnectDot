/*************************************************************************//*!
					
					@file	Utilities.inl
					@brief	�ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�^�C�}�[�̍X�V<br>
						�^�C�}�[�̍X�V���s���B<br>
						�O�񂱂̊֐����Ăяo����Ă���A������s�����܂ł̎��Ԃ��v�����t���[�����Ԃɐݒ肷��B<br>
						bWait��TRUE�Ȃ�ݒ肳��Ă���FPS�܂ł̗]�莞�ԕ���sleep�ɂ��ҋ@����B<br>
						FPS���ݒ肳��Ă��Ȃ��ꍇ��bWait��FALSE�̏ꍇ�͑ҋ@�����͍s���Ȃ��B
		@param[in]		bWait		FPS�E�F�C�g�t���O
			
		@return			None
*//**************************************************************************/
FORCE_INLINE void CUtilities::UpdateTimer(MofBool bWait){
	if(!m_pFrameTimer)
	{
		return;
	}
	return m_pFrameTimer->Update(bWait);
}
/*************************************************************************//*!
		@brief			��������
		@param			None

		@return			��������������Ԃ�
*//**************************************************************************/
FORCE_INLINE  MofU32 CUtilities::Random(void){
	return m_Random.Random();
}
/*************************************************************************//*!
		@brief			��������<br>
						0�`�����̍ő�l�����͈̗̔͂�������������
		@param[in]		h				�ő�l

		@return			��������������Ԃ�
*//**************************************************************************/
FORCE_INLINE  MofU32 CUtilities::Random(MofU32 h){
	return m_Random.Random(h);
}
/*************************************************************************//*!
		@brief			��������<br>
						�����̍ŏ��l�`�����̍ő�l�����͈̗̔͂�������������
		@param[in]		l				�ŏ��l
		@param[in]		h				�ő�l

		@return			��������������Ԃ�
*//**************************************************************************/
FORCE_INLINE  MofU32 CUtilities::Random(MofU32 l,MofU32 h){
	return m_Random.Random(l,h);
}
/*************************************************************************//*!
		@brief			(0.0f�`1.0f)�͈̗̔͂�������
		@param			None

		@return			��������������Ԃ�
*//**************************************************************************/
FORCE_INLINE  MofFloat CUtilities::RandomFloat(void){
	return m_Random.RandomFloat();
}
/*************************************************************************//*!
		@brief			�t���[�����[�N��ݒ肷��
		@param[in]		pfw			�t���[�����[�N
				
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CUtilities::SetFramework(LPFramework pfw){
	m_pFramework = pfw;
	return TRUE;
}
/*************************************************************************//*!
		@brief			FPS�̐ݒ�<br>
						FPS�̌Œ������ꍇ�ɐݒ���s���B<br>
						������FPS��0��ݒ肷��ƌŒ�Ȃ��̎��Ԍv���݂̂̏����ɂȂ�B
		@param[in]		s			FPS
			
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CUtilities::SetFPS(MofU32 s){
	if(!m_pFrameTimer)
	{
		return FALSE;
	}
	return m_pFrameTimer->SetFPS(s);
}
/*************************************************************************//*!
		@brief			�t���[�����Ԃ̐ݒ�<br>
						���̃^�C�}�[�Ōo�߂����t���[�����Ԃ������̃~���b�ɍ����ւ���B
		@param[in]		s			�t���[������(msec)
			
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CUtilities::SetFrameMSecond(MofU32 s){
	if(!m_pFrameTimer)
	{
		return FALSE;
	}
	return m_pFrameTimer->SetFrameMSecond(s);
}
/*************************************************************************//*!
		@brief			�����̎��ݒ肷��
		@param[in]		s				��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CUtilities::SetSeed(MofU32 s){
	return m_Random.SetSeed(s);
}
/*************************************************************************//*!
		@brief			�t���[�����[�N���擾����
		@param			None

		@return			�t���[�����[�N
*//**************************************************************************/
FORCE_INLINE LPFramework CUtilities::GetFramework(void){
	return m_pFramework;
}
/*************************************************************************//*!
		@brief			�C���X�^���X�n���h���擾����
		@param			None

		@return			�C���X�^���X�n���h��
*//**************************************************************************/
FORCE_INLINE MofInstanceHandle CUtilities::GetInstanceHandle(void){
	return m_pFramework->GetHandle();
}
/*************************************************************************//*!
		@brief			����FPS�擾
		@param			None

		@return			FPS�̐����l
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetRestrictFPS(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetRestrictFPS();
}
/*************************************************************************//*!
		@brief			�����t���[�����Ԏ擾
		@param			None

		@return			�t���[�����Ԃ̐����l
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetRestrictFrameTime(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetRestrictFrameTime();
}
/*************************************************************************//*!
		@brief			FPS�擾
		@param			None

		@return			�v�����ꂽFPS
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetFPS(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetFPS();
}
/*************************************************************************//*!
		@brief			�t���[�����Ԏ擾<br>
						�擾����t���[�����Ԃ̒P�ʂ̓~���b
		@param			None

		@return			�t���[������(msec)
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetUpdateFrameTime(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetUpdateFrameTime();
}
/*************************************************************************//*!
		@brief			�t���[�����Ԏ擾<br>
						�擾����t���[�����Ԃ̒P�ʂ̓~���b
		@param			None

		@return			�t���[������(msec)
*//**************************************************************************/
FORCE_INLINE MofU32 CUtilities::GetFrameMSecond(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetFrameMSecond();
}
/*************************************************************************//*!
		@brief			�t���[�����Ԏ擾<br>
						�擾����t���[�����Ԃ̒P�ʂ͕b
		@param			None

		@return			�t���[������(sec)
*//**************************************************************************/
FORCE_INLINE MofFloat CUtilities::GetFrameSecond(void){
	if(!m_pFrameTimer)
	{
		return 0;
	}
	return m_pFrameTimer->GetFrameSecond();
}
/*************************************************************************//*!
		@brief			�J�����g�f�B���N�g�����擾����
		@param			None
				
		@return			�J�����g�f�B���N�g���̃p�X
*//**************************************************************************/
FORCE_INLINE LPMofChar CUtilities::GetCurrentDirectory(void){
	return m_CurrentDirectory.GetString();
}

#ifdef		MOFLIB_ANDROID
/*************************************************************************//*!
		@brief			JNI�Ăяo�����ݒ�

						JNI�Ăяo������ݒ肵�܂�

		@param[in]		env				JNI
		@param[in]		obj				JNI�Ăяo���I�u�W�F�N�g

		@return			None
*//**************************************************************************/
FORCE_INLINE void CUtilities::SetJNICall(JNIEnv* env,jobject obj){
	m_Env = env;
	m_Thiz = obj;
	return;
}
/*************************************************************************//*!
		@brief			JNI�Ăяo�����擾

						JNI�Ăяo�������擾���܂�

		@param			None

		@return			JNI
*//**************************************************************************/
FORCE_INLINE JNIEnv* CUtilities::GetJNIEnv(void){
	return m_Env;
}
/*************************************************************************//*!
		@brief			JNI�Ăяo�����擾

						JNI�Ăяo�������擾���܂�

		@param			None

		@return			JNI
*//**************************************************************************/
FORCE_INLINE jobject CUtilities::GetJNIObject(void){
	return m_Thiz;
}

#endif

//[EOF]