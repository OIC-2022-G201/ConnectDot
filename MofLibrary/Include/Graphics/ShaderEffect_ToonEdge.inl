/*************************************************************************//*!
					
					@file	ShaderEffect_ToonEdge.inl
					@brief	�G�b�W�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.22
*//**************************************************************************/

/*************************************************************************//*!
@brief			�e�N�X�`���̕`��
@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
@param[in]		pTex		�e�N�X�`��
@param[in]		pEffect		�G�b�W�`�揀���V�F�[�_�[
				
@return			TRUE		����<br>
				����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ToonEdge::Render(LPTexture pTargetTex,LPTexture pTex,LPShaderEffect_EdgeBaseOutput pEffect){
	if(
		!SetDepthNormalTexture(pEffect->GetDepthNormalTexture()) ||
		!SetMaskTexture(pEffect->GetMaskTexture())
	){
		return FALSE;
	}
	return CShaderEffect_2DBase::Render(pTargetTex,pTex);
}
/*************************************************************************//*!
@brief			�[�x�e�N�X�`���̐ݒ�
@param[in]		pTex		�[�x�e�N�X�`��
				
@return			TRUE		����<br>
				����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ToonEdge::SetDepthNormalTexture(LPTexture pTex){
	return m_pShaderBind->SetTexture(1,pTex);
}
/*************************************************************************//*!
@brief			�}�X�N�e�N�X�`���̐ݒ�
@param[in]		pTex		�}�X�N�e�N�X�`��
				
@return			TRUE		����<br>
				����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ToonEdge::SetMaskTexture(LPTexture pTex){
	return m_pShaderBind->SetTexture(2,pTex);
}

//[EOF]