/*************************************************************************//*!
					
					@file	ShaderEffect_CascadedShadowMap.h
					@brief	カスケードシャドウマップシェーダー。

															@author	CDW
															@date	2015.06.03
*//**************************************************************************/

/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_CascadedShadowMap::Create(){
	return Create(512,TRUE,PIXELFORMAT_R32G32_FLOAT,PIXELFORMAT_D24S8_UNORM);
}
/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param[in]		TexSize シャドウマップ用テクスチャサイズ

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_CascadedShadowMap::Create(MofU32 TexSize){
	return Create(TexSize,TRUE,PIXELFORMAT_R32G32_FLOAT,PIXELFORMAT_D24S8_UNORM);
}
/*************************************************************************//*!
		@brief			カスケード分割位置の設定
		@param[in]		Index			カスケード番号
		@param[in]		PartitionDepth	分割位置
		
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_CascadedShadowMap::SetCascadePartition(MofU32 Index,MofFloat PartitionDepth){
	if(Index < 0 || MAX_CASCADES <= Index)
	{
		return FALSE;
	}
	m_CascadePartitions[Index] = PartitionDepth;
	return TRUE;
}
/*************************************************************************//*!
		@brief			影のぼかし幅の設定
		@param[in]		BlurStep		影のぼかし幅
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetBlurStep(MofFloat BlurStep){
	m_BlurStep = BlurStep;
}
/*************************************************************************//*!
		@brief			カスケード境界のぼかし具合の設定
		@param[in]		CascadeBlendArea	カスケード境界のぼかし具合
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetCascadeBlendArea(MofFloat CascadeBlendArea){
	m_CascadeBlendArea = CascadeBlendArea;
}
/*************************************************************************//*!
		@brief			ライトブリーディングを抑えるための値を設定
		@param[in]		ShadowPower		ライトブリーディングを抑えるための値
		
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetShadowPower(MofFloat ShadowPower){
	m_ShadowPower = ShadowPower;
}
/*************************************************************************//*!
		@brief			シャドウマップのNear設定
		@param[in]		ShadowNear		シャドウマップのNear
		
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetShadowNear(MofFloat ShadowNear){
	m_ShadowNear = ShadowNear;
}
/*************************************************************************//*!
		@brief			シャドウマップのFar設定
		@param[in]		ShadowFar	シャドウマップのFar
		
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetShadowFar(MofFloat ShadowFar){
	m_ShadowFar = ShadowFar;
}
/*************************************************************************//*!
		@brief			3Dプリミティブ描画用シェーダーを取得する
		@param			None

		@return			3Dプリミティブ描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_CascadedShadowMap::GetShader(void){
	return m_pShadowRenderer->GetShader();
}
/*************************************************************************//*!
		@brief			3Dプリミティブ描画用シェーダーを取得する
		@param			None

		@return			3Dプリミティブ描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_CascadedShadowMap::GetShaderBind(void){
	return m_pShadowRenderer->GetShaderBind();
}
/*************************************************************************//*!
		@brief			深度テクスチャの取得
		@param[in]		n				エフェクト番号
				
		@return			深度テクスチャ
*//**************************************************************************/
FORCE_INLINE LPShaderEffect_ShadowTexture CShaderEffect_CascadedShadowMap::GetShadowMap(MofU32 n){
	return m_pShadowTextures[n];
}
/*************************************************************************//*!
		@brief			深度テクスチャの取得
		@param[in]		n				エフェクト番号
		
		@return			深度テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_CascadedShadowMap::GetShadowMapTexture(MofU32 n){
	return m_pShadowTextures[n]->GetShadowMapTexture();
}
/*************************************************************************//*!
		@brief			カスケードシャドウマップの段階数取得
		@param			None
		
		@return			カスケードシャドウマップの段階数
*//**************************************************************************/
FORCE_INLINE MofU32 CShaderEffect_CascadedShadowMap::GetCascadeLevels(void){
	return MAX_CASCADES;
}
/*************************************************************************//*!
		@brief			ライト視点のビュー行列取得
		@param			None

		@return			ライト視点のビュー行列
*//**************************************************************************/
FORCE_INLINE CMatrix44& CShaderEffect_CascadedShadowMap::GetLightViewMatrix(void){
	return m_matShadowView;
}
/*************************************************************************//*!
		@brief			カスケードプロジェクション行列の取得
		@param[in]		n				エフェクト番号
				
		@return			カスケードプロジェクション行列
*//**************************************************************************/
FORCE_INLINE CMatrix44& CShaderEffect_CascadedShadowMap::GetCascadeProjectionMatrix(MofU32 n){
	return m_matShadowProj[n];
}
/*************************************************************************//*!
		@brief			影のぼかし幅の取得
		@param			None
				
		@return			影のぼかし幅
*//**************************************************************************/
FORCE_INLINE MofFloat CShaderEffect_CascadedShadowMap::GetBlurStep(void){
	return m_BlurStep;
}
/*************************************************************************//*!
		@brief			カスケード境界のぼかし具合の取得
		@param			None
				
		@return			カスケード境界のぼかし具合
*//**************************************************************************/
FORCE_INLINE MofFloat CShaderEffect_CascadedShadowMap::GetCascadeBlendArea(void){
	return m_CascadeBlendArea;
}
/*************************************************************************//*!
		@brief			ライトブリーディングを抑えるための値を取得
		@param			None
				
		@return			ライトブリーディングを抑えるための値
*//**************************************************************************/
FORCE_INLINE MofFloat CShaderEffect_CascadedShadowMap::GetShadowPower(void){
	return m_ShadowPower;
}

//[EOF]
