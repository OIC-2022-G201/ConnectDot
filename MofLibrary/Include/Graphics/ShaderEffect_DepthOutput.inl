/*************************************************************************//*!
					
					@file	ShaderEffect_DepthOutput.h
					@brief	�}���`�����_�����O�ɂ��[�x�e�N�X�`���`��V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.01
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_DepthOutput::Create(){
	return Create(PIXELFORMAT_R32_FLOAT,PIXELFORMAT_D24S8_UNORM,TRUE);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̎擾
		@param[in]		n			�ԍ�
			
		@return			�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_DepthOutput::GetTexture(MofU32 n){
	if(n == 0)
	{
		return m_pDepthTex;
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�[�x�e�N�X�`���̎擾
		@param			None
		
		@return			�[�x�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_DepthOutput::GetDepthTexture(){
	return m_pDepthTex;
}

//[EOF]