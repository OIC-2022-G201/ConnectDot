/*************************************************************************//*!
					
					@file	ShaderEffect_ShadowMap.inl
					@brief	�V���h�E�}�b�v�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.13
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::Create(){
	return Create(512,PIXELFORMAT_R32_FLOAT);
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param[in]		TexSize �V���h�E�}�b�v�p�e�N�X�`���T�C�Y

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::Create(MofU32 TexSize){
	return Create(TexSize, PIXELFORMAT_R32_FLOAT);
}
/*************************************************************************//*!
		@brief			�[�x�e�N�X�`���쐬�J�n
		@param			None
		
		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::BeginTexture(){
	return m_pShadowTexture->Begin();
}
/*************************************************************************//*!
		@brief			�[�x�e�N�X�`���쐬�I��
		@param			None
		
		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::EndTexture(){
	return m_pShadowTexture->End();
}
/*************************************************************************//*!
		@brief			�e��K�p������ʕ`��J�n
		@param			None
		
		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::BeginRenderer(){
	m_pShadowRenderer->SetShadowMap(m_pShadowTexture);
	return m_pShadowRenderer->Begin();
}
/*************************************************************************//*!
		@brief			�e��K�p������ʕ`��I��
		@param			None
		
		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::EndRenderer(){
	return m_pShadowRenderer->End();
}
/*************************************************************************//*!
		@brief			�V���h�E�}�b�v�͈̔͂�ݒ�
		@param[in]		Range		�V���h�E�}�b�v�ɕ`�悷��͈�
		@param[in]		Near		�V���h�E�}�b�v�ɕ`�悷��ŏ�����
		@param[in]		Far			�V���h�E�}�b�v�ɕ`�悷��ő勗��
			
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_ShadowMap::SetShadowMapParam(MofFloat Range,MofFloat Near,MofFloat Far,MofFloat Epsilon){
	m_pShadowTexture->SetShadowMapParam(Range,Near,Far);
	m_pShadowRenderer->SetEpsilon(Epsilon);
}
/*************************************************************************//*!
		@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�v���~�e�B�u�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_ShadowMap::GetShader(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�v���~�e�B�u�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_ShadowMap::GetShaderBind(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			�[�x�e�N�X�`���̎擾
		@param			None
		
		@return			�[�x�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_ShadowMap::GetShadowMapTexture(){
	return m_pShadowTexture->GetShadowMapTexture();
}

//[EOF]