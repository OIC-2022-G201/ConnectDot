/*************************************************************************//*!
					
					@file	ShaderEffect_2DBase.h
					@brief	2D�p�V�F�[�_�[���ʊ��N���X�B

															@author	CDW
															@date	2015.04.22
*//**************************************************************************/

/*************************************************************************//*!
@brief			�e�N�X�`���̕`��
@param[in]		px			�`��X���W
@param[in]		py			�`��Y���W
@param[in]		pTex		�e�N�X�`��
				
@return			TRUE		����<br>
				����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_2DBase::Render(MofFloat px,MofFloat py,LPTexture pTex){
	return Render(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}

/*************************************************************************//*!
		@brief			�V�F�[�_�[�̎擾
		@param			None
				
		@return			�V�F�[�_�[��Ԃ��B
						���s�̏ꍇNULL�ɂȂ�B
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_2DBase::GetShader(void){
	return m_pShader;
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�o�C���h�̎擾
		@param			None
				
		@return			�V�F�[�_�[�o�C���h��Ԃ��B
						���s�̏ꍇNULL�ɂȂ�B
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_2DBase::GetShaderBind(void){
	return m_pShaderBind;
}

//[EOF]