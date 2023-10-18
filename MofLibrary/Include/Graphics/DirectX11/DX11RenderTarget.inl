/*************************************************************************//*!
					
					@file	DX11RenderTarget.inl
					@brief	DirectX11描画ターゲットクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			クリアカラー設定
		@param[in]		Color	クリアカラー

		@return			None
*//**************************************************************************/
FORCE_INLINE void CDX11RenderTarget::SetClearColor(Vector4& Color){
	m_ClearColor = Color;
}
/*************************************************************************//*!
		@brief			描画ターゲット取得
		@param			None

		@return			描画ターゲット
*//**************************************************************************/
FORCE_INLINE MofRenderTarget CDX11RenderTarget::GetTarget(void){
	return m_pRenderTargetView;
}
/*************************************************************************//*!
		@brief			クリアカラー取得
		@param			None

		@return			クリアカラー
*//**************************************************************************/
FORCE_INLINE const Vector4& CDX11RenderTarget::GetClearColor(void)const{
	return m_ClearColor;
}

//[EOF]