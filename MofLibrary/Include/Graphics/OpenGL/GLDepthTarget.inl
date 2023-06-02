/*************************************************************************//*!
					
					@file	GLDepthTarget.inl
					@brief	OpenGL�[�x�^�[�Q�b�g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�N���A�[�x�l�擾�ݒ�
		@param			Value	�N���A�[�x�l

		@return			None
*//**************************************************************************/
FORCE_INLINE void CGLDepthTarget::SetClearDepth(MofFloat Value){
	m_ClearDepth = Value;
}
/*************************************************************************//*!
		@brief			�N���A�X�e���V���l�ݒ�
		@param			Stensil	�N���A�X�e���V���l

		@return			None
*//**************************************************************************/
FORCE_INLINE void CGLDepthTarget::SetClearStencil(MofU32 Value){
	m_ClearStensil = Value;
}
/*************************************************************************//*!
		@brief			�[�x�^�[�Q�b�g�擾
		@param			None

		@return			�[�x�^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE MofDepthTarget CGLDepthTarget::GetTarget(void){
	return m_depthId;
}
/*************************************************************************//*!
		@brief			�N���A�[�x�l�擾
		@param			None

		@return			�N���A�[�x�l
*//**************************************************************************/
FORCE_INLINE MofFloat CGLDepthTarget::GetClearDepth(void){
	return m_ClearDepth;
}
/*************************************************************************//*!
		@brief			�N���A�X�e���V���l�擾
		@param			None

		@return			�N���A�X�e���V���l
*//**************************************************************************/
FORCE_INLINE MofU32 CGLDepthTarget::GetClearStencil(void){
	return m_ClearStensil;
}

//[EOF]
