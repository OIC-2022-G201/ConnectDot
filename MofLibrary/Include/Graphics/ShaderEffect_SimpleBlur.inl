/*************************************************************************//*!
					
					@file	ShaderEffect_SimpleBlur.inl
					@brief	�P���ڂ����V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.06.17
*//**************************************************************************/

/*************************************************************************//*!
@brief			�e�N�X�`���̕`��
@param[in]		px			�`��X���W
@param[in]		py			�`��Y���W
@param[in]		pTex		�e�N�X�`��
				
@return			TRUE		����<br>
				����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_SimpleBlur::Render(MofFloat px,MofFloat py,LPTexture pTex){
	return Render(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}

/*************************************************************************//*!
		@brief			�ڂ����̃p�����[�^�̐ݒ�
		@param[in]		SampleStepX		�T���v�����O����s�N�Z���̉��Ԋu
		@param[in]		SampleStepY		�T���v�����O����s�N�Z���̏c�Ԋu

		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_SimpleBlur::SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY){
	SetBlurParam(SampleStepX,SampleStepY,m_TexWidth,m_TexHeight);
}

//[EOF]