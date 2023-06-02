/*************************************************************************//*!
					
					@file	ShaderEffect_Bloom.h
					@brief	Bloom�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.11.09
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTex		�e�N�X�`��
		
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_Bloom::Render(LPTexture pTex){
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
FORCE_INLINE MofBool CShaderEffect_Bloom::Render(LPTexture pTargetTex,LPTexture pTex){
	MofFloat steps[] = { 1,2 };
	return Render(pTargetTex,pTex,2,steps);
}
/*************************************************************************//*!
		@brief			���P�x�����o�̃p�����[�^�ݒ�
		@param[in]		Threshold			臒l
			
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_Bloom::SetBrightPassParam(MofFloat Threshold){
	m_pBrightPass->SetThreshold(Threshold);
	return TRUE;
}


//[EOF]