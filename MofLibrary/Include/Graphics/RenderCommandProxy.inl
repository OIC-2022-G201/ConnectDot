/*************************************************************************//*!
					
					@file	RenderCommandProxy.inl
					@brief	描画コマンドクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			保存状態の設定
		@param[in]		st			設定
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CRenderCommandProxy::SetStatus(const GRAPHICSSTATUS& st){
	m_ProxyStatus = st;
	return TRUE;
}
/*************************************************************************//*!
		@brief			現在の描画ターゲット取得
		@param[out]		None
				
		@return			現在の描画ターゲット
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CRenderCommandProxy::GetRenderTarget(void){
	return m_ProxyStatus.pRenderTargets[0];
}
/*************************************************************************//*!
		@brief			指定した番号の描画ターゲット取得
		@param[in]		index		
				
		@return			現在の描画ターゲット
*//**************************************************************************/
FORCE_INLINE LPRenderTarget CRenderCommandProxy::GetRenderTargetAt(MofU32 index){
	if(m_ProxyStatus.RenderTargetCount <= index)
	{
		return NULL;
	}
	return m_ProxyStatus.pRenderTargets[index];
}
/*************************************************************************//*!
		@brief			現在の描画ターゲット数を取得
		@param			None
				
		@return			現在の描画ターゲット数
*//**************************************************************************/
FORCE_INLINE MofU32 CRenderCommandProxy::GetRenderTargetCount(void){
	return m_ProxyStatus.RenderTargetCount;
}
/*************************************************************************//*!
		@brief			現在の深度ターゲット取得
		@param[out]		None
				
		@return			現在の深度ターゲット
*//**************************************************************************/
FORCE_INLINE LPDepthTarget CRenderCommandProxy::GetDepthTarget(void){
	return m_ProxyStatus.pDepthTarget;
}
/*************************************************************************//*!
		@brief			ブレンドステート取得
		@param[out]		None
				
		@return			現在のブレンドステート
*//**************************************************************************/
FORCE_INLINE Blending CRenderCommandProxy::GetBlending(void){
	return m_ProxyStatus.BlendType[0];
}

//[EOF]