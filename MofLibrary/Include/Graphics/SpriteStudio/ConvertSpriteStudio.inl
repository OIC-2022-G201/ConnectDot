/*************************************************************************//*!
					
					@file	ConvertSpriteStudio.inl
					@brief	スプライトスタジオのssaeファイルの変換を行うためのクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			スプライトタイプを独自形式に変換する
		@param[in]		t			SpriteStudioのスプライトタイプ
				
		@return			独自形式でのスプライトタイプ
*//**************************************************************************/
FORCE_INLINE MofU32 CConvertSpriteStudio::ConvertSpriteType(SsPartType::_enum t){
	switch(t)
	{
		case SsPartType::normal:
			return SPRITETYPE_NORMAL;
		case SsPartType::effect:
			return SPRITETYPE_EMITTER;
	}
	return SPRITETYPE_NULL;
}
/*************************************************************************//*!
		@brief			エフェクトタイプを独自形式に変換する
		@param[in]		t			SpriteStudioのエフェクトタイプ
				
		@return			独自形式でのスプライトタイプ
*//**************************************************************************/
FORCE_INLINE MofU32 CConvertSpriteStudio::ConvertEffectType(SsEffectNodeType::_enum t){
	switch(t)
	{
		case SsEffectNodeType::emmiter:
			return SPRITETYPE_EMITTER;
		case SsEffectNodeType::particle:
			return SPRITETYPE_PARTICLE;
	}
	return SPRITETYPE_NULL;
}
/*************************************************************************//*!
		@brief			ブレンディング方法を独自形式に変換する
		@param[in]		t			SpriteStudioのブレンディングタイプ
				
		@return			独自形式でのブレンディング方法
*//**************************************************************************/
FORCE_INLINE MofU32 CConvertSpriteStudio::ConvertBlendingType(SsBlendType::_enum t){
	switch(t)
	{
		case SsBlendType::mix:
			return BLEND_NORMAL;
		case SsBlendType::mul:
			return BLEND_MULTIPLY;
		case SsBlendType::add:
			return BLEND_ADD;
		case SsBlendType::sub:
			return BLEND_SUB;
	}
	return BLEND_USER;
}
/*************************************************************************//*!
		@brief			ブレンディング方法を独自形式に変換する
		@param[in]		t			SpriteStudioのブレンディングタイプ
				
		@return			独自形式でのブレンディング方法
*//**************************************************************************/
FORCE_INLINE MofU32 CConvertSpriteStudio::ConvertBlendingType(SsRenderBlendType::_enum t) {
	switch (t)
	{
	case SsRenderBlendType::Mix:
		return BLEND_NORMAL;
	case SsRenderBlendType::Add:
		return BLEND_ADD;
	}
	return BLEND_USER;
}
/*************************************************************************//*!
		@brief			キータイプを独自形式に変換する
		@param[in]		t			SpriteStudioのキータイプ
				
		@return			独自形式でのキータイプ
*//**************************************************************************/
FORCE_INLINE MofU32 CConvertSpriteStudio::ConvertKeyType(SsAttributeKind::_enum t){
	switch(t)
	{
		case SsAttributeKind::posx:		///<位置X
			return MOFSPRITE_ANIMATIONKEY_TRANSLATIONX;
		case SsAttributeKind::posy:		///<位置Y
			return MOFSPRITE_ANIMATIONKEY_TRANSLATIONY;
		case SsAttributeKind::posz:		///<位置Z
			return MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ;

		case SsAttributeKind::sclx:		///<スケールX
			return MOFSPRITE_ANIMATIONKEY_SCALINGX;
		case SsAttributeKind::scly:		///<スケールY
			return MOFSPRITE_ANIMATIONKEY_SCALINGY;
			
		case SsAttributeKind::rotx:		///<回転X
			return MOFSPRITE_ANIMATIONKEY_ROTATIONX;
		case SsAttributeKind::roty:		///<回転Y
			return MOFSPRITE_ANIMATIONKEY_ROTATIONY;
		case SsAttributeKind::rotz:		///<回転Z
			return MOFSPRITE_ANIMATIONKEY_ROTATIONZ;
			
		case SsAttributeKind::alpha:	///<不透明度
			return MOFSPRITE_ANIMATIONKEY_COLORA;

		case SsAttributeKind::prio:		//!<優先順位
			return MOFSPRITE_ANIMATIONKEY_PRIORITY;
			
		case SsAttributeKind::pivotx:	///<オフセットX
			return MOFSPRITE_ANIMATIONKEY_ALIGNMENTX;
		case SsAttributeKind::pivoty:	///<オフセットY
			return MOFSPRITE_ANIMATIONKEY_ALIGNMENTY;

		case SsAttributeKind::sizex:	///<サイズX
			return MOFSPRITE_ANIMATIONKEY_SIZEX;
		case SsAttributeKind::sizey:	///<サイズY
			return MOFSPRITE_ANIMATIONKEY_SIZEY;

		case SsAttributeKind::anchorx:	///<アンカーX
			return MOFSPRITE_ANIMATIONKEY_ANCHORX;
		case SsAttributeKind::anchory:	///<アンカーY
			return MOFSPRITE_ANIMATIONKEY_ANCHORY;
			
		case SsAttributeKind::hide:		///<非表示
			return MOFSPRITE_ANIMATIONKEY_SHOW;

		case SsAttributeKind::fliph:	///<左右反転(セルの原点を軸にする)
		case SsAttributeKind::imgfliph:	///<イメージ左右反転(常にイメージの中央を原点とする)
			return MOFSPRITE_ANIMATIONKEY_XREVERSE;

		case SsAttributeKind::flipv:	///<上下反転(セルの原点を軸にする)
		case SsAttributeKind::imgflipv:	///<イメージ上下反転(常にイメージの中央を原点とする)
			return MOFSPRITE_ANIMATIONKEY_YREVERSE;

		case SsAttributeKind::vertex:	///< 頂点変形
			return MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1;

		case SsAttributeKind::color:	///< 頂点変形
			return MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1;

		case SsAttributeKind::uvtx:		///< UVアニメ.移動.X
			return MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX;
		case SsAttributeKind::uvty:		///< UVアニメ.移動.Y
			return MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY;
		case SsAttributeKind::uvrz:		///< UVアニメ.回転
			return MOFSPRITE_ANIMATIONKEY_UVROTATION;
		case SsAttributeKind::uvsx:		///< UVアニメ.スケール.X
			return MOFSPRITE_ANIMATIONKEY_UVSIZEX;
		case SsAttributeKind::uvsy:		///< UVアニメ.スケール.Y
			return MOFSPRITE_ANIMATIONKEY_UVSIZEY;

		case SsAttributeKind::effect:	//!<エフェクトパラメーター
			return MOFSPRITE_ANIMATIONKEY_EFFECTTIME;
	}
	return BLEND_NONE;
}
/*************************************************************************//*!
		@brief			キー補間タイプを独自形式に変換する
		@param[in]		t			SpriteStudioのキー補間タイプ
				
		@return			独自形式でのキータイプ
*//**************************************************************************/
FORCE_INLINE MofU32 CConvertSpriteStudio::ConvertKeyInterpolationType(SsInterpolationType::_enum t){
	switch(t)
	{
		case SsInterpolationType::none:
			return KEYINTERPOLATION_NONE;
		case SsInterpolationType::linear:
			return KEYINTERPOLATION_LINEAR;
		case SsInterpolationType::acceleration:
		case SsInterpolationType::deceleration:
			return KEYINTERPOLATION_EASE;
		case SsInterpolationType::hermite:
			return KEYINTERPOLATION_HERMITE;
		case SsInterpolationType::bezier:
			return KEYINTERPOLATION_BEZIER1;
	}
	return KEYINTERPOLATION_LINEAR;
}

//[EOF]