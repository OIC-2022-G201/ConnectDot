/*************************************************************************//*!
					
					@file	DX11Font.cpp
					@brief	DirectX11フォントクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			文字描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		pText		描画文字列
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CDX11Font::RenderString(MofFloat px,MofFloat py,LPCMofChar pText){
	return RenderString(px, py, m_DefaultColor, pText);
}
/*************************************************************************//*!
		@brief			文字描画
		@param[in]		drec		描画矩形
		@param[in]		pText		描画文字列
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CDX11Font::RenderString(Rectangle& drec,LPCMofChar pText){
	return RenderString(drec, m_DefaultColor, pText);
}
/*************************************************************************//*!
		@brief			文字描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		scl			描画スケール
		@param[in]		pText		描画文字列
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CDX11Font::RenderStringScale(MofFloat px, MofFloat py, MofFloat scl, LPCMofChar pText) {
	return RenderStringScale(px, py, m_DefaultColor, pText);
}
/*************************************************************************//*!
		@brief			登録テクスチャを取得
		@param			None

		@return			登録テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CDX11Font::GetTexture(void) {
	return m_pTexture;
}