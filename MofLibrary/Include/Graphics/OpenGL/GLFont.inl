/*************************************************************************//*!
					
					@file	GLFont.h
					@brief	OpenGLフォントクラス。

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
FORCE_INLINE MofBool CGLFont::RenderString(MofFloat px,MofFloat py,LPCMofChar pText){
	return RenderString(px, py, m_DefaultColor, pText);
}
/*************************************************************************//*!
		@brief			文字描画
		@param[in]		drec		描画矩形
		@param[in]		pText		描画文字列
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGLFont::RenderString(Rectangle& drec,LPCMofChar pText){
	return RenderString(drec, m_DefaultColor, pText);
}

//[EOF]