/*************************************************************************//*!
					
					@file	DX11DepthTarget.inl
					@brief	DirectX11�[�x�^�[�Q�b�g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�N���A�[�x�l�擾�ݒ�
		@param			Value			�N���A�[�x�l

		@return			None
*//**************************************************************************/
FORCE_INLINE void CDX11DepthTarget::SetClearDepth(MofFloat Value){
	m_ClearDepth = Value;
}
/*************************************************************************//*!
		@brief			�N���A�X�e���V���l�ݒ�
		@param			Value			�N���A�X�e���V���l

		@return			None
*//**************************************************************************/
FORCE_INLINE void CDX11DepthTarget::SetClearStencil(MofU32 Value){
	m_ClearStensil = Value;
}
/*************************************************************************//*!
		@brief			�[�x�^�[�Q�b�g�擾
		@param			None

		@return			�[�x�^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE MofDepthTarget CDX11DepthTarget::GetTarget(void){
	return m_pDepthStencilView;
}
/*************************************************************************//*!
		@brief			�N���A�[�x�l�擾
		@param			None

		@return			�N���A�[�x�l
*//**************************************************************************/
FORCE_INLINE MofFloat CDX11DepthTarget::GetClearDepth(void){
	return m_ClearDepth;
}
/*************************************************************************//*!
		@brief			�N���A�X�e���V���l�擾
		@param			None

		@return			�N���A�X�e���V���l
*//**************************************************************************/
FORCE_INLINE MofU32 CDX11DepthTarget::GetClearStencil(void){
	return m_ClearStensil;
}

//[EOF]