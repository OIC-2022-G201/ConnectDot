/*************************************************************************//*!
					
					@file	ShaderEffect_EdgeMaskOutput.h
					@brief	�}���`�����_�����O�ɂ��[�x���@���e�N�X�`���`��V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.11.02
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_EdgeMaskOutput::Create(){
	return Create(PIXELFORMAT_D24S8_UNORM,FALSE);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̎擾
		@param[in]		n			�ԍ�
			
		@return			�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeMaskOutput::GetTexture(MofU32 n){
	switch(n)
	{
	case 0:
		return m_pMaskTex;
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�}�X�N�e�N�X�`���̎擾
		@param			None
		
		@return			�}�X�N�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeMaskOutput::GetMaskTexture(){
	return m_pMaskTex;
}

//[EOF]