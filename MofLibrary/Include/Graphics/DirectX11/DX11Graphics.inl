/*************************************************************************//*!
					
					@file	DX11Graphics.inl
					@brief	DirectX11でのグラフィックスの処理を行う基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			グラフィックスデバイス取得
		@param			None

		@return			グラフィックスデバイス
*//**************************************************************************/
FORCE_INLINE MofGraphicsDevice CDX11Graphics::GetDevice(void){
	return m_pDevice;
}
/*************************************************************************//*!
		@brief			スワップチェイン取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			スワップチェイン
*//**************************************************************************/
FORCE_INLINE MofSwapChain CDX11Graphics::GetSwapChain(void){
	return m_pSwapChain;
}
/*************************************************************************//*!
		@brief			コンテキスト取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			コンテキスト
*//**************************************************************************/
FORCE_INLINE MofDeviceContext CDX11Graphics::GetDeviceContext(void){
	return m_pContext;
}
/*************************************************************************//*!
		@brief			サンプラーステート取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param[in]		s		取得するサンプルタイプ(tag_SAMPLER列挙体の値を設定する)

		@return			サンプラーステート
*//**************************************************************************/
FORCE_INLINE MofSamplerState CDX11Graphics::GetSamplerState(MofU32 s){
	if(s >= SAMPLER_MAX)
	{
		return NULL;
	}
	return m_pSamplerState[s];
}
/*************************************************************************//*!
		@brief			ターゲットウインドウの幅取得
		@param			None

		@return			ターゲットウインドウの幅
*//**************************************************************************/
FORCE_INLINE MofS32 CDX11Graphics::GetTargetWidth(void){
	if(m_Status.pWindow)
	{
		return m_Status.pWindow->GetWidth();
	}
	return -1;
}
/*************************************************************************//*!
		@brief			ターゲットウインドウの高さ取得
		@param			None

		@return			ターゲットウインドウの高さ
*//**************************************************************************/
FORCE_INLINE MofS32 CDX11Graphics::GetTargetHeight(void){
	if(m_Status.pWindow)
	{
		return m_Status.pWindow->GetHeight();
	}
	return -1;
}
/*************************************************************************//*!
		@brief			設定情報取得
		@param			None
				
		@return			グラフィック設定
*//**************************************************************************/
FORCE_INLINE const GRAPHICSSTATUS& CDX11Graphics::GetStatus(void){
	return m_Status;
}
/*************************************************************************//*!
		@brief			現在の描画ターゲット取得
		@param[out]		None
				
		@return			現在の描画ターゲット
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CDX11Graphics::GetRenderTarget(void){
	return m_Status.pRenderTargets[0];
}
/*************************************************************************//*!
		@brief			指定した番号の描画ターゲット取得
		@param[in]		index		
				
		@return			現在の描画ターゲット
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CDX11Graphics::GetRenderTargetAt(MofU32 index){
	if(m_Status.RenderTargetCount <= index)
	{
		return NULL;
	}
	return m_Status.pRenderTargets[index];
}
/*************************************************************************//*!
		@brief			現在の描画ターゲット数を取得
		@param			None
				
		@return			現在の描画ターゲット数
*//**************************************************************************/
FORCE_INLINE MofU32 CDX11Graphics::GetRenderTargetCount(void){
	return m_Status.RenderTargetCount;
}
/*************************************************************************//*!
		@brief			現在の深度ターゲット取得
		@param[out]		None
				
		@return			現在の深度ターゲット
*//**************************************************************************/
FORCE_INLINE LPDepthTarget CDX11Graphics::GetDepthTarget(void){
	return m_Status.pDepthTarget;
}
/*************************************************************************//*!
		@brief			ブレンドステート取得
		@param[out]		None
				
		@return			現在のブレンドステート
*//**************************************************************************/
FORCE_INLINE Blending CDX11Graphics::GetBlending(void){
	return m_Status.BlendType[0];
}

//[EOF]