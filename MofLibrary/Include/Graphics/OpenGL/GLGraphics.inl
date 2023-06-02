/*************************************************************************//*!
					
					@file	GLGraphics.inl
					@brief	OpenGL�ł̃O���t�B�b�N�X�̏������s�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�O���t�B�b�N�X�f�o�C�X�擾
		@param			None

		@return			�O���t�B�b�N�X�f�o�C�X
*//**************************************************************************/
FORCE_INLINE MofGraphicsDevice CGLGraphics::GetDevice(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			�X���b�v�`�F�C���擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�X���b�v�`�F�C��
*//**************************************************************************/
FORCE_INLINE MofSwapChain CGLGraphics::GetSwapChain(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			�R���e�L�X�g�擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�R���e�L�X�g
*//**************************************************************************/
FORCE_INLINE MofDeviceContext CGLGraphics::GetDeviceContext(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			�T���v���[�X�e�[�g�擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�T���v���[�X�e�[�g
*//**************************************************************************/
FORCE_INLINE MofSamplerState CGLGraphics::GetSamplerState(MofU32 s){
	return NULL;
}
/*************************************************************************//*!
		@brief			�^�[�Q�b�g�E�C���h�E�̕��擾
		@param			None

		@return			�^�[�Q�b�g�E�C���h�E�̕�
*//**************************************************************************/
FORCE_INLINE MofS32 CGLGraphics::GetTargetWidth(void){
	return m_Status.ScreenWidth;
}
/*************************************************************************//*!
		@brief			�^�[�Q�b�g�E�C���h�E�̍����擾
		@param			None

		@return			�^�[�Q�b�g�E�C���h�E�̍���
*//**************************************************************************/
FORCE_INLINE MofS32 CGLGraphics::GetTargetHeight(void){
	return m_Status.ScreenHeight;
}
/*************************************************************************//*!
		@brief			�Ή���ʃT�C�Y���X�g�擾�ݒ�
		@param[out]		pList		�C���f�b�N�X�o�b�t�@
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGLGraphics::GetDisplayModeList(LPDISPLAYMODELIST pList){
	return NULL;
}
/*************************************************************************//*!
		@brief			�ݒ���擾
		@param			None
				
		@return			�O���t�B�b�N�ݒ�
*//**************************************************************************/
FORCE_INLINE const GRAPHICSSTATUS& CGLGraphics::GetStatus(void){
	return m_Status;
}
/*************************************************************************//*!
		@brief			���݂̕`��^�[�Q�b�g�擾
		@param[out]		None
				
		@return			���݂̕`��^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CGLGraphics::GetRenderTarget(void){
	return m_Status.pRenderTargets[0];
}
/*************************************************************************//*!
		@brief			�w�肵���ԍ��̕`��^�[�Q�b�g�擾
		@param[in]		index		
				
		@return			���݂̕`��^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CGLGraphics::GetRenderTargetAt(MofU32 index){
	if(m_Status.RenderTargetCount <= index)
	{
		return NULL;
	}
	return m_Status.pRenderTargets[index];
}
/*************************************************************************//*!
		@brief			���݂̕`��^�[�Q�b�g�����擾
		@param			None
				
		@return			���݂̕`��^�[�Q�b�g��
*//**************************************************************************/
FORCE_INLINE MofU32 CGLGraphics::GetRenderTargetCount(void){
	return m_Status.RenderTargetCount;
}
/*************************************************************************//*!
		@brief			���݂̐[�x�^�[�Q�b�g�擾
		@param[out]		None
				
		@return			���݂̐[�x�^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPDepthTarget CGLGraphics::GetDepthTarget(void){
	return m_Status.pDepthTarget;
}
/*************************************************************************//*!
		@brief			�u�����h�X�e�[�g�擾
		@param[out]		None
				
		@return			���݂̃u�����h�X�e�[�g
*//**************************************************************************/
FORCE_INLINE Blending CGLGraphics::GetBlending(void){
	return m_Status.BlendType;
}

//[EOF]