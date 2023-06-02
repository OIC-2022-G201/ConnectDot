/*************************************************************************//*!
					
					@file	DX11DepthTarget.inl
					@brief	DirectX11深度ターゲットクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			クリア深度値取得設定
		@param			Value			クリア深度値

		@return			None
*//**************************************************************************/
FORCE_INLINE void CDX11DepthTarget::SetClearDepth(MofFloat Value){
	m_ClearDepth = Value;
}
/*************************************************************************//*!
		@brief			クリアステンシル値設定
		@param			Value			クリアステンシル値

		@return			None
*//**************************************************************************/
FORCE_INLINE void CDX11DepthTarget::SetClearStencil(MofU32 Value){
	m_ClearStensil = Value;
}
/*************************************************************************//*!
		@brief			深度ターゲット取得
		@param			None

		@return			深度ターゲット
*//**************************************************************************/
FORCE_INLINE MofDepthTarget CDX11DepthTarget::GetTarget(void){
	return m_pDepthStencilView;
}
/*************************************************************************//*!
		@brief			クリア深度値取得
		@param			None

		@return			クリア深度値
*//**************************************************************************/
FORCE_INLINE MofFloat CDX11DepthTarget::GetClearDepth(void){
	return m_ClearDepth;
}
/*************************************************************************//*!
		@brief			クリアステンシル値取得
		@param			None

		@return			クリアステンシル値
*//**************************************************************************/
FORCE_INLINE MofU32 CDX11DepthTarget::GetClearStencil(void){
	return m_ClearStensil;
}

//[EOF]