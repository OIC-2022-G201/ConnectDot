/*************************************************************************//*!
					
					@file	ShaderEffect_HDR.h
					@brief	HDR�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.15
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTex		�e�N�X�`��
		
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_HDR::Render(LPTexture pTex){
	MofFloat steps[] = { 1,2 };
	return Render(NULL,pTex,2,steps);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
		@param[in]		pTex		�e�N�X�`��
		
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_HDR::Render(LPTexture pTargetTex,LPTexture pTex){
	MofFloat steps[] = { 1,2 };
	return Render(pTargetTex,pTex,2,steps);
}
/*************************************************************************//*!
		@brief			�����V�~�����[�V�����̕ω����x
		@param[in]		MiddleGray	0.0f�`1.0f�̕ω����x
			
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_HDR::SetLumTransitionSpeed(MofFloat Speed){
	m_LumTransitionSpeed = MOF_CLIPING(Speed, 0, 1);
	return TRUE;
}
/*************************************************************************//*!
		@brief			���P�x�����o�̃p�����[�^�ݒ�
		@param[in]		Threshold			臒l
			
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_HDR::SetBrightPassParam(MofFloat Threshold){
	return ((m_bToneMap) ? m_pToneBrightPass->SetThreshold(Threshold) : m_pBrightPass->SetThreshold(Threshold));
}

/*************************************************************************//*!
		@brief			���P�x�����o�̃p�����[�^�ݒ�
		@param[in]		Threshold			臒l
		@param[in]		MiddleGray			���邳�̊�l
		@param[in]		BrightPassOffset	�␳
			
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_HDR::SetBrightPassParam(MofFloat Threshold,MofFloat MiddleGray,MofFloat BrightPassOffset){
	return ((m_bToneMap) ? m_pToneBrightPass->SetHDRBrightPassParam(Threshold,MiddleGray,BrightPassOffset) : m_pBrightPass->SetThreshold(Threshold));
}


//[EOF]