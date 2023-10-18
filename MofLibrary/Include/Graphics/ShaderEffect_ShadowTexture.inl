/*************************************************************************//*!
					
					@file	ShaderEffect_ShadowTexture.h
					@brief	�V���h�E�}�b�v�p�[�x�e�N�X�`���`��V�F�[�_�[�B

															@author	CDW
															@date	2015.05.13
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowTexture::Create(){
	return Create(512,SHADOW_NORMAL,PIXELFORMAT_R32_FLOAT,PIXELFORMAT_D24S8_UNORM);
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param[in]		TexSize �V���h�E�}�b�v�p�e�N�X�`���T�C�Y

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowTexture::Create(MofU32 TexSize){
	return Create(TexSize,SHADOW_NORMAL,PIXELFORMAT_R32_FLOAT,PIXELFORMAT_D24S8_UNORM);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̎擾
		@param[in]		n			�ԍ�
			
		@return			�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_ShadowTexture::GetTexture(MofU32 n){
	if(n == 0)
	{
		return m_pShadowMapTex;
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�[�x�e�N�X�`���̎擾
		@param			None
		
		@return			�[�x�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_ShadowTexture::GetShadowMapTexture(){
	return m_pShadowMapTex;
}
/*************************************************************************//*!
		@brief			���C�g���_�̃J����
		@param			None

		@return			���C�g���_�̃J����
*//**************************************************************************/
FORCE_INLINE LPCamera CShaderEffect_ShadowTexture::GetCamera(void){
	return &m_LightCam;
}
/*************************************************************************//*!
		@brief			���C�g���_�̃r���[�v���W�F�N�V�����s��擾
		@param			None

		@return			���C�g���_�̃r���[�v���W�F�N�V�����s��
*//**************************************************************************/
FORCE_INLINE CMatrix44& CShaderEffect_ShadowTexture::GetLightViewProjectionMatrix(void){
	return m_LightCam.GetViewProjectionMatrix();
}
/*************************************************************************//*!
		@brief			�V���h�E�}�b�v�͈̔͂�ݒ�
		@param[in]		Range		�V���h�E�}�b�v�ɕ`�悷��͈�
		@param[in]		Near		�V���h�E�}�b�v�ɕ`�悷��ŏ�����
		@param[in]		Far			�V���h�E�}�b�v�ɕ`�悷��ő勗��
			
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_ShadowTexture::SetShadowMapParam(MofFloat Range,MofFloat Near,MofFloat Far){
	m_LightMapRange = Range;
	m_LightMapNear = Near;
	m_LightMapFar = Far;
}

//[EOF]