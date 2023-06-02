/*************************************************************************//*!
					
					@file	SpritePartAnimation.inl
					@brief	�X�v���C�g�p�[�c�A�j���[�V�������N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���[�v�t���O�����邩�𔻒肷��
		@param			None
				
		@return			TRUE			���[�v����<br>
						FALSE			���[�v���Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartAnimation::IsLoop(void){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->IsLoop())
		{
			return TRUE;
		}
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���[�V�����̃��[�v�t���O�̐ݒ�
		@param[in]		bLoop			���[�v�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartAnimation::SetLoop(MofBool bLoop){
	if(!m_pAnimationKey)
	{
		return FALSE;
	}
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		m_pAnimationKey->GetData(i)->SetLoop(bLoop);
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CSpritePartAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param			None

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPSpriteAnimationKeyArray CSpritePartAnimation::GetAnimationKey(void){
	return m_pAnimationKey;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param[in]		t				�L�[�^�C�v

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPFloatKeyFrameArray CSpritePartAnimation::GetAnimationFloatKey(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pFloatKey;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param[in]		t				�L�[�^�C�v

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPBoolKeyFrameArray CSpritePartAnimation::GetAnimationBoolKey(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pBoolKey;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param[in]		t				�L�[�^�C�v

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPS32KeyFrameArray CSpritePartAnimation::GetAnimationS32Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pS32Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param[in]		t				�L�[�^�C�v

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPU32KeyFrameArray CSpritePartAnimation::GetAnimationU32Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pU32Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param[in]		t				�L�[�^�C�v

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPRectangleKeyFrameArray CSpritePartAnimation::GetAnimationRectKey(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pRectKey;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param[in]		t				�L�[�^�C�v

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CSpritePartAnimation::GetAnimationVector3Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pVector3Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param[in]		t				�L�[�^�C�v

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPVector2KeyFrameArray CSpritePartAnimation::GetAnimationVector2Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pVector2Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param[in]		t				�L�[�^�C�v

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPVector4KeyFrameArray CSpritePartAnimation::GetAnimationVector4Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pVector4Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�L�[�擾
		@param[in]		t				�L�[�^�C�v

		@return			�L�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPQuaternionKeyFrameArray CSpritePartAnimation::GetAnimationQuaternionKey(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pQuaternionKey;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�A�j���[�V�����̏I�����Ԏ擾<br>
						���[�v������ꍇ�ł��ŏI�̃t���[���̎��Ԃ�Ԃ�
		@param			None
				
		@return			�A�j���[�V�����̏I������
*//**************************************************************************/
FORCE_INLINE MofFloat CSpritePartAnimation::GetEndTime(void){
	//����
	MofFloat Time = 0.0f;
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		Time = MOF_MAX(Time,m_pAnimationKey->GetData(i)->GetLastKeyTime());
	}
	return Time;
}

//[EOF]