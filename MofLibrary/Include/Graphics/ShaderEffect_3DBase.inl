/*************************************************************************//*!
					
					@file	ShaderEffect_3DBase.h
					@brief	3D用シェーダー効果基底クラス。

															@author	CDW
															@date	2015.05.01
*//**************************************************************************/

/*************************************************************************//*!
		@brief			3Dプリミティブ描画用シェーダーを取得する
		@param			None

		@return			3Dプリミティブ描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_3DBase::GetShader(void){
	return m_p3DPrimitiveShader;
}
/*************************************************************************//*!
		@brief			3Dプリミティブ描画用シェーダーを取得する
		@param			None

		@return			3Dプリミティブ描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_3DBase::GetShaderBind(void){
	return m_p3DPrimitiveBind;
}

/*************************************************************************//*!
		@brief			3Dスキニング描画用シェーダーを取得する
		@param			None

		@return			3Dスキニング描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_3DBase::Get3DPrimitiveShader(void){
	return GetShader();
}
/*************************************************************************//*!
		@brief			3Dスキニング描画用シェーダーを取得する
		@param			None

		@return			3Dスキニング描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_3DBase::Get3DPrimitiveBind(void){
	return GetShaderBind();
}

/*************************************************************************//*!
		@brief			3Dスキニング描画用シェーダーを取得する
		@param			None

		@return			3Dスキニング描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_3DBase::GetSkinGeometryShader(void){
	return m_pSkinGeometryShader;
}
/*************************************************************************//*!
		@brief			3Dスキニング描画用シェーダーを取得する
		@param			None

		@return			3Dスキニング描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_3DBase::GetSkinGeometryBind(void){
	return m_pSkinGeometryBind;
}

/*************************************************************************//*!
		@brief			テクスチャの取得
		@param[in]		n			番号
			
		@return			テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_3DBase::GetTexture(MofU32 n){
	return NULL;
}

//[EOF]