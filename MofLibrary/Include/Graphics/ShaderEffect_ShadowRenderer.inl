/*************************************************************************//*!
					
					@file	ShaderEffect_ShadowRenderer.h
					@brief	�V���h�E�}�b�v�ɂ��e�`��V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.04
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�C�v�V�����̐ݒ�
		@param[in]		Epsilon			�e�����炷��
		
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_ShadowRenderer::SetEpsilon(MofFloat Epsilon){
	m_ShadowEpsilon = Epsilon;
}

//[EOF]