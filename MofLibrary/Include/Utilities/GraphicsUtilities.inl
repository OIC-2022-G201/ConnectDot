/*************************************************************************//*!
					
					@file	GraphicsUtilities.inl
					@brief	描画関連の汎用処理をまとめたスタティッククラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			線の描画
		@param[in]		sv			開始位置
		@param[in]		ev			終了位置
		@param[in]		col			描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLine(const Vector2& sv,const Vector2& ev,MofU32 col){
	return RenderLine(sv.x,sv.y,ev.x,ev.y,col);
}
/*************************************************************************//*!
		@brief			線の描画
		@param[in]		sv			開始位置
		@param[in]		ev			終了位置
		@param[in]		col			描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLine(const Vector3& sv,const Vector3& ev,MofU32 col){
	return RenderLine(sv.x,sv.y,sv.z,ev.x,ev.y,ev.z,col);
}
/*************************************************************************//*!
		@brief			グリッドの描画
		@param[in]		bet			間隔
		@param[in]		s			サイズ
		@param[in]		col			描画色
		@param[in]		plane		表示平面
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderGrid(MofFloat bet, MofFloat s, MofU32 col, PlaneAxis plane){
	return RenderGrid(Vector3(0, 0, 0), bet, s, col, plane);
}
/*************************************************************************//*!
		@brief			矩形の描画
		@param[in]		rec			矩形
		@param[in]		col			描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRect(const Rectangle& rec,MofU32 col){
	return RenderRect(rec.Left,rec.Top,rec.Right,rec.Bottom,col);
}
/*************************************************************************//*!
		@brief			塗りつぶし矩形の描画
		@param[in]		rec			矩形
		@param[in]		col			描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillRect(const Rectangle& rec,MofU32 col){
	return RenderFillRect(rec.Left,rec.Top,rec.Right,rec.Bottom,col,col,col,col);
}
/*************************************************************************//*!
		@brief			塗りつぶし矩形の描画
		@param[in]		rec			矩形
		@param[in]		ltc			左上描画色
		@param[in]		lbc			左下描画色
		@param[in]		rtc			右上描画色
		@param[in]		rbc			右下描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillRect(const Rectangle& rec,MofU32 ltc,MofU32 lbc,MofU32 rtc,MofU32 rbc){
	return RenderFillRect(rec.Left,rec.Top,rec.Right,rec.Bottom,ltc,lbc,rtc,rbc);
}
/*************************************************************************//*!
		@brief			塗りつぶし矩形の描画
		@param[in]		l			左
		@param[in]		t			上
		@param[in]		r			右
		@param[in]		b			下
		@param[in]		col			描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b,MofU32 col){
	return RenderFillRect(l,t,r,b,col,col,col,col);
}
/*************************************************************************//*!
		@brief			円の描画
		@param[in]		c			描画円
		@param[in]		col			描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderCircle(const Circle& c,MofU32 col){
	return RenderCircle(c.x,c.y,c.r,col);
}
/*************************************************************************//*!
		@brief			塗りつぶし円の描画
		@param[in]		c			描画円
		@param[in]		col			描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillCircle(const Circle& c,MofU32 col){
	return RenderFillCircle(c.x,c.y,c.r,col,col);
}
/*************************************************************************//*!
		@brief			塗りつぶし円の描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		r			描画半径
		@param[in]		col			描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillCircle(MofFloat px,MofFloat py,MofFloat r,MofU32 col){
	return RenderFillCircle(px,py,r,col,col);
}
/*************************************************************************//*!
		@brief			塗りつぶし円の描画
		@param[in]		c			描画円
		@param[in]		Ccol		中心描画色
		@param[in]		Ocol		外周描画色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillCircle(const Circle& c,MofU32 Ccol,MofU32 Ocol){
	return RenderFillCircle(c.x,c.y,c.r,Ccol,Ocol);
}

/*************************************************************************//*!
		@brief			3D箱の描画
		@param[in]		b			AABB
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLineBox(const BoxAABB& b){
	Matrix44 m;
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderLineBox(m);
}
/*************************************************************************//*!
		@brief			3D箱の描画
		@param[in]		b			OBB
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLineBox(const BoxOBB& b){
	Matrix44 m;
	CMatrix44Utilities::RotationZXY(b.Angle,m);
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderLineBox(m);
}

/*************************************************************************//*!
		@brief			3D箱の描画
		@param[in]		b			AABB
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderBox(const BoxAABB& b){
	Matrix44 m;
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderBox(m);
}
/*************************************************************************//*!
		@brief			3D箱の描画
		@param[in]		b			AABB
		@param[in]		col			色補正
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderBox(const BoxAABB& b, const Vector4& col){
	Matrix44 m;
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderBox(m,col);
}
/*************************************************************************//*!
		@brief			3D箱の描画
		@param[in]		b			OBB
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderBox(const BoxOBB& b){
	Matrix44 m;
	CMatrix44Utilities::RotationZXY(b.Angle,m);
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderBox(m);
}
/*************************************************************************//*!
		@brief			3D箱の描画
		@param[in]		b			OBB
		@param[in]		col			色補正
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderBox(const BoxOBB& b, const Vector4& col){
	Matrix44 m;
	CMatrix44Utilities::RotationZXY(b.Angle,m);
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderBox(m, col);
}

/*************************************************************************//*!
		@brief			3D球の描画
		@param[in]		s			球体
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLineSphere(const Sphere& s){
	Matrix44 m;
	CMatrix44Utilities::Scaling(s.r,m);
	CMatrix44Utilities::SetTranslation(s.x,s.y,s.z,m);
	return RenderLineSphere(m);
}
/*************************************************************************//*!
		@brief			3D球の描画
		@param[in]		s			球体
		@param[in]		col			色補正
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLineSphere(const Sphere& s, const Vector4& col){
	Matrix44 m;
	CMatrix44Utilities::Scaling(s.r,m);
	CMatrix44Utilities::SetTranslation(s.x,s.y,s.z,m);
	return RenderLineSphere(m, col);
}

/*************************************************************************//*!
		@brief			3D球の描画
		@param[in]		s			球体
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderSphere(const Sphere& s){
	Matrix44 m;
	CMatrix44Utilities::Scaling(s.r,m);
	CMatrix44Utilities::SetTranslation(s.x,s.y,s.z,m);
	return RenderSphere(m);
}
/*************************************************************************//*!
		@brief			3D球の描画
		@param[in]		s			球体
		@param[in]		col			色補正
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderSphere(const Sphere& s, const Vector4& col){
	Matrix44 m;
	CMatrix44Utilities::Scaling(s.r,m);
	CMatrix44Utilities::SetTranslation(s.x,s.y,s.z,m);
	return RenderSphere(m,col);
}

/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,LPTexture pTex){
	return RenderTexture(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		pTex		テクスチャ
		@param[in]		pShader		シェーダー
		@param[in]		pShaderBind	シェーダーバインド
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind){
	return RenderTexture(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex,pShader,pShaderBind);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px				描画X座標
		@param[in]		py				描画Y座標
		@param[in]		pTex			テクスチャ
		@param[in]		pShaderEffect	シェーダー
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,LPTexture pTex,LPShaderEffect pShaderEffect){
	return RenderTexture(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex,pShaderEffect->GetShader(), pShaderEffect->GetShaderBind());
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,MofU32 col,LPTexture pTex){
	return RenderTexture(px,py,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,TextureAlignment Alignment,LPTexture pTex){
	return RenderTexture(px,py,MOF_COLOR_WHITE,Alignment,pTex);
}
		


/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		srec		画像表示矩形
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,LPTexture pTex){
	return RenderTexture(px,py,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		srec		画像表示矩形
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderTexture(px,py,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		srec		画像表示矩形
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderTexture(px,py,srec,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		drec		描画矩形
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Rectangle& drec,LPTexture pTex){
	return RenderTexture(drec,MOF_COLOR_WHITE,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		drec		描画矩形
		@param[in]		pTex		テクスチャ
		@param[in]		pShader		シェーダー
		@param[in]		pShaderBind	シェーダーバインド
		
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Rectangle& drec,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind){
	return RenderTexture(drec,MOF_COLOR_WHITE,pTex,pShader,pShaderBind);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		drec		描画矩形
		@param[in]		srec		画像表示矩形
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Rectangle& drec,const Rectangle& srec,LPTexture pTex){
	return RenderTexture(drec,srec,MOF_COLOR_WHITE,pTex);
}

/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		drec		描画矩形
		@param[in]		srec		画像表示矩形
		@param[in]		pTex		テクスチャ
		@param[in]		pShader		シェーダー
		@param[in]		pShaderBind	シェーダーバインド

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Rectangle& drec, const Rectangle& srec, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind) {
	return RenderTexture(drec, srec, MOF_COLOR_WHITE, pTex, pShader, pShaderBind);
}


/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,MofU32 col,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,MOF_COLOR_WHITE,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		col			描画色
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,MofU32 col,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,col,Alignment,pTex);
}


		
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		srec		画像表示矩形
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		srec		画像表示矩形
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		srec		画像表示矩形
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,srec,MOF_COLOR_WHITE,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		srec		画像表示矩形
		@param[in]		col			描画色
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,srec,col,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		srec		画像表示矩形
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		srec		画像表示矩形
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		srec		画像表示矩形
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,srec,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		ang			回転角度
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		ang			回転角度
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		ang			回転角度
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,TextureAlignment Alignment,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,srec,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		ang			回転角度
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		ang			回転角度
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		ang			回転角度
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,MOF_COLOR_WHITE,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		ang			回転角度
		@param[in]		col			描画色
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,col,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		ang			回転角度
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		ang			回転角度
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		ang			回転角度
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,srec,MOF_COLOR_WHITE,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		s			拡大倍率
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		col			描画色
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,srec,col,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		sx			Ｘ拡大倍率
		@param[in]		sy			Ｙ拡大倍率
		@param[in]		ang			回転角度
		@param[in]		srec		画像表示矩形
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,srec,MOF_COLOR_WHITE,Alignment,pTex);
}

/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		wMat		変換行列
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Matrix44& wMat,LPTexture pTex){
	return RenderTexture(wMat,MOF_COLOR_WHITE,TRUE,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		wMat		変換行列
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Matrix44& wMat,MofU32 col,LPTexture pTex){
	return RenderTexture(wMat,col,TRUE,pTex);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		wMat		変換行列
		@param[in]		srec		画像表示矩形
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Matrix44& wMat,const Rectangle& srec,LPTexture pTex){
	return RenderTexture(wMat,srec,MOF_COLOR_WHITE,TRUE,pTex);
}

/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		wMat		変換行列
		@param[in]		srec		画像表示矩形
		@param[in]		col			描画色
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Matrix44& wMat,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderTexture(wMat,srec,col,TRUE,pTex);
}

/*************************************************************************//*!
		@brief			描画用グラフィックスを設定する
		@param[in]		pg				グラフィックス

		@return			None
*//**************************************************************************/
FORCE_INLINE void CGraphicsUtilities::SetGraphics(LPGraphics pg){
	m_pGraphics = pg;
	return;
}
/*************************************************************************//*!
		@brief			描画用グラフィックスコマンドプロキシを設定する
		@param[in]		pg				グラフィックスコマンドプロキシ

		@return			None
*//**************************************************************************/
FORCE_INLINE void CGraphicsUtilities::SetCommandProxy(LPRenderCommandProxy pg){
	m_pCommandProxy = pg;
	if (m_pCommandProxy)
	{
		m_pCommandProxy->SetStatus(m_pGraphics->GetStatus());
	}
	return;
}
/*************************************************************************//*!
		@brief			描画用グラフィックスを取得する
		@param			None

		@return			描画用グラフィックス
*//**************************************************************************/
FORCE_INLINE  LPGraphics CGraphicsUtilities::GetGraphics(void){
	return m_pGraphics;
}
/*************************************************************************//*!
		@brief			描画用グラフィックスコマンドプロキシを取得する
		@param			None

		@return			描画用グラフィックスコマンドプロキシ
*//**************************************************************************/
FORCE_INLINE LPRenderCommandProxy CGraphicsUtilities::GetCommandProxy(void){
	return m_pCommandProxy;
}
/*************************************************************************//*!
		@brief			描画用カメラを取得する
		@param			None

		@return			描画用カメラ
*//**************************************************************************/
FORCE_INLINE LPCamera CGraphicsUtilities::GetCamera(void){
	return m_pCamera;
}
/*************************************************************************//*!
		@brief			描画用基本ライトを取得する
		@param			None

		@return			描画用基本ライト
*//**************************************************************************/
FORCE_INLINE LPDirectionalLight CGraphicsUtilities::GetDirectionalLight(void){
	return m_pDirectionalLight;
}

//[EOF]