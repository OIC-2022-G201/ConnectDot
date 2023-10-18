/*************************************************************************//*!
					
					@file	ShaderEffect_DepthOfField.h
					@brief	��ʊE�[�x�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.04.29
*//**************************************************************************/

/*************************************************************************//*!
@brief			�e�N�X�`���̕`��
@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
@param[in]		pTex		�e�N�X�`��
@param[in]		pDepthTex	�[�x�e�N�X�`��
				
@return			TRUE		����<br>
				����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_DepthOfField::Render(LPTexture pTargetTex,LPTexture pTex,LPTexture pDepthTex){
	if(!SetDepthTexture(pDepthTex))
	{
		return FALSE;
	}
	return Render(pTargetTex,pTex);
}

/*************************************************************************//*!
@brief			�[�x�e�N�X�`���̐ݒ�
@param[in]		pTex		�[�x�e�N�X�`��
				
@return			TRUE		����<br>
				����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_DepthOfField::SetDepthTexture(LPTexture pTex){
	return m_pShaderBind->SetTexture(2,pTex);
}

//[EOF]