/*************************************************************************//*!
					
					@file	ShaderEffect_EdgeBaseOutput.h
					@brief	�}���`�����_�����O�ɂ��[�x���@���e�N�X�`���`��V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.29
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_EdgeBaseOutput::Create(){
	return Create(PIXELFORMAT_R32G32B32A32_FLOAT,PIXELFORMAT_D24S8_UNORM,TRUE);
}
/*************************************************************************//*!
		@brief			�J�n
		@param			None
		
		@return			None
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_EdgeBaseOutput::BeginMask(){
	return m_pEdgeMask->Begin();
}
/*************************************************************************//*!
		@brief			�I��
		@param			None
		
		@return			None
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_EdgeBaseOutput::EndMask(){
	return m_pEdgeMask->End();
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̎擾
		@param[in]		n			�ԍ�
			
		@return			�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeBaseOutput::GetTexture(MofU32 n){
	switch(n) {
	case 0:
		return m_pDepthNormalTex;
	case 1:
		return m_pEdgeMask->GetMaskTexture();
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�[�x�e�N�X�`���̎擾
		@param			None
		
		@return			�[�x�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeBaseOutput::GetDepthNormalTexture(){
	return m_pDepthNormalTex;
}
/*************************************************************************//*!
		@brief			�}�X�N�e�N�X�`���̎擾
		@param			None
		
		@return			�}�X�N�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeBaseOutput::GetMaskTexture(){
	return m_pEdgeMask->GetMaskTexture();
}

//[EOF]