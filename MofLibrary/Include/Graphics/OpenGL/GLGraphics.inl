/*************************************************************************//*!
					
					@file	GLGraphics.inl
					@brief	OpenGLでのグラフィックスの処理を行う基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			グラフィックスデバイス取得
		@param			None

		@return			グラフィックスデバイス
*//**************************************************************************/
FORCE_INLINE MofGraphicsDevice CGLGraphics::GetDevice(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			スワップチェイン取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			スワップチェイン
*//**************************************************************************/
FORCE_INLINE MofSwapChain CGLGraphics::GetSwapChain(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			コンテキスト取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			コンテキスト
*//**************************************************************************/
FORCE_INLINE MofDeviceContext CGLGraphics::GetDeviceContext(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			サンプラーステート取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			サンプラーステート
*//**************************************************************************/
FORCE_INLINE MofSamplerState CGLGraphics::GetSamplerState(MofU32 s){
	return NULL;
}
/*************************************************************************//*!
		@brief			ターゲットウインドウの幅取得
		@param			None

		@return			ターゲットウインドウの幅
*//**************************************************************************/
FORCE_INLINE MofS32 CGLGraphics::GetTargetWidth(void){
	return m_Status.ScreenWidth;
}
/*************************************************************************//*!
		@brief			ターゲットウインドウの高さ取得
		@param			None

		@return			ターゲットウインドウの高さ
*//**************************************************************************/
FORCE_INLINE MofS32 CGLGraphics::GetTargetHeight(void){
	return m_Status.ScreenHeight;
}
/*************************************************************************//*!
		@brief			対応画面サイズリスト取得設定
		@param[out]		pList		インデックスバッファ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGLGraphics::GetDisplayModeList(LPDISPLAYMODELIST pList){
	return NULL;
}
/*************************************************************************//*!
		@brief			設定情報取得
		@param			None
				
		@return			グラフィック設定
*//**************************************************************************/
FORCE_INLINE const GRAPHICSSTATUS& CGLGraphics::GetStatus(void){
	return m_Status;
}
/*************************************************************************//*!
		@brief			現在の描画ターゲット取得
		@param[out]		None
				
		@return			現在の描画ターゲット
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CGLGraphics::GetRenderTarget(void){
	return m_Status.pRenderTargets[0];
}
/*************************************************************************//*!
		@brief			指定した番号の描画ターゲット取得
		@param[in]		index		
				
		@return			現在の描画ターゲット
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CGLGraphics::GetRenderTargetAt(MofU32 index){
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
FORCE_INLINE MofU32 CGLGraphics::GetRenderTargetCount(void){
	return m_Status.RenderTargetCount;
}
/*************************************************************************//*!
		@brief			現在の深度ターゲット取得
		@param[out]		None
				
		@return			現在の深度ターゲット
*//**************************************************************************/
FORCE_INLINE LPDepthTarget CGLGraphics::GetDepthTarget(void){
	return m_Status.pDepthTarget;
}
/*************************************************************************//*!
		@brief			ブレンドステート取得
		@param[out]		None
				
		@return			現在のブレンドステート
*//**************************************************************************/
FORCE_INLINE Blending CGLGraphics::GetBlending(void){
	return m_Status.BlendType;
}

//[EOF]