/*************************************************************************//*!
					
					@file	DX11Graphics.inl
					@brief	DirectX11�ł̃O���t�B�b�N�X�̏������s�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�O���t�B�b�N�X�f�o�C�X�擾
		@param			None

		@return			�O���t�B�b�N�X�f�o�C�X
*//**************************************************************************/
FORCE_INLINE MofGraphicsDevice CDX11Graphics::GetDevice(void){
	return m_pDevice;
}
/*************************************************************************//*!
		@brief			�X���b�v�`�F�C���擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�X���b�v�`�F�C��
*//**************************************************************************/
FORCE_INLINE MofSwapChain CDX11Graphics::GetSwapChain(void){
	return m_pSwapChain;
}
/*************************************************************************//*!
		@brief			�R���e�L�X�g�擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�R���e�L�X�g
*//**************************************************************************/
FORCE_INLINE MofDeviceContext CDX11Graphics::GetDeviceContext(void){
	return m_pContext;
}
/*************************************************************************//*!
		@brief			�T���v���[�X�e�[�g�擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param[in]		s		�擾����T���v���^�C�v(tag_SAMPLER�񋓑̂̒l��ݒ肷��)

		@return			�T���v���[�X�e�[�g
*//**************************************************************************/
FORCE_INLINE MofSamplerState CDX11Graphics::GetSamplerState(MofU32 s){
	if(s >= SAMPLER_MAX)
	{
		return NULL;
	}
	return m_pSamplerState[s];
}
/*************************************************************************//*!
		@brief			�^�[�Q�b�g�E�C���h�E�̕��擾
		@param			None

		@return			�^�[�Q�b�g�E�C���h�E�̕�
*//**************************************************************************/
FORCE_INLINE MofS32 CDX11Graphics::GetTargetWidth(void){
	if(m_Status.pWindow)
	{
		return m_Status.pWindow->GetWidth();
	}
	return -1;
}
/*************************************************************************//*!
		@brief			�^�[�Q�b�g�E�C���h�E�̍����擾
		@param			None

		@return			�^�[�Q�b�g�E�C���h�E�̍���
*//**************************************************************************/
FORCE_INLINE MofS32 CDX11Graphics::GetTargetHeight(void){
	if(m_Status.pWindow)
	{
		return m_Status.pWindow->GetHeight();
	}
	return -1;
}
/*************************************************************************//*!
		@brief			�ݒ���擾
		@param			None
				
		@return			�O���t�B�b�N�ݒ�
*//**************************************************************************/
FORCE_INLINE const GRAPHICSSTATUS& CDX11Graphics::GetStatus(void){
	return m_Status;
}
/*************************************************************************//*!
		@brief			���݂̕`��^�[�Q�b�g�擾
		@param[out]		None
				
		@return			���݂̕`��^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CDX11Graphics::GetRenderTarget(void){
	return m_Status.pRenderTargets[0];
}
/*************************************************************************//*!
		@brief			�w�肵���ԍ��̕`��^�[�Q�b�g�擾
		@param[in]		index		
				
		@return			���݂̕`��^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CDX11Graphics::GetRenderTargetAt(MofU32 index){
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
FORCE_INLINE MofU32 CDX11Graphics::GetRenderTargetCount(void){
	return m_Status.RenderTargetCount;
}
/*************************************************************************//*!
		@brief			���݂̐[�x�^�[�Q�b�g�擾
		@param[out]		None
				
		@return			���݂̐[�x�^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPDepthTarget CDX11Graphics::GetDepthTarget(void){
	return m_Status.pDepthTarget;
}
/*************************************************************************//*!
		@brief			�u�����h�X�e�[�g�擾
		@param[out]		None
				
		@return			���݂̃u�����h�X�e�[�g
*//**************************************************************************/
FORCE_INLINE Blending CDX11Graphics::GetBlending(void){
	return m_Status.BlendType[0];
}

//[EOF]