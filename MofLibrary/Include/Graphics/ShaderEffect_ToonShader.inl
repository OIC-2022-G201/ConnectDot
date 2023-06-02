/*************************************************************************//*!
					
					@file	ShaderEffect_ToonShader.h
					@brief	�g�D�[�������_�����O�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.27
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�g�D�[���}�b�v�e�N�X�`���ݒ�
		@param[in]		pTex			�g�D�[���}�b�v�e�N�X�`��
		
		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ToonShader::SetToonMapTexture(LPTexture pTex){
	
	return (
		m_p3DPrimitiveBind->SetTexture(1,pTex) &&
		m_pSkinGeometryBind->SetTexture(1,pTex)
	);
}

//[EOF]