/*************************************************************************//*!
					
					@file	GLDepthTarget.inl
					@brief	OpenGL深度ターゲットクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			クリア深度値取得設定
		@param			Value	クリア深度値

		@return			None
*//**************************************************************************/
FORCE_INLINE void CGLDepthTarget::SetClearDepth(MofFloat Value){
	m_ClearDepth = Value;
}
/*************************************************************************//*!
		@brief			クリアステンシル値設定
		@param			Stensil	クリアステンシル値

		@return			None
*//**************************************************************************/
FORCE_INLINE void CGLDepthTarget::SetClearStencil(MofU32 Value){
	m_ClearStensil = Value;
}
/*************************************************************************//*!
		@brief			深度ターゲット取得
		@param			None

		@return			深度ターゲット
*//**************************************************************************/
FORCE_INLINE MofDepthTarget CGLDepthTarget::GetTarget(void){
	return m_depthId;
}
/*************************************************************************//*!
		@brief			クリア深度値取得
		@param			None

		@return			クリア深度値
*//**************************************************************************/
FORCE_INLINE MofFloat CGLDepthTarget::GetClearDepth(void){
	return m_ClearDepth;
}
/*************************************************************************//*!
		@brief			クリアステンシル値取得
		@param			None

		@return			クリアステンシル値
*//**************************************************************************/
FORCE_INLINE MofU32 CGLDepthTarget::GetClearStencil(void){
	return m_ClearStensil;
}

//[EOF]
