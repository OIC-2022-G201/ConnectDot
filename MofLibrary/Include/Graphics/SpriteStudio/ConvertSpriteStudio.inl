/*************************************************************************//*!
					
					@file	ConvertSpriteStudio.inl
					@brief	�X�v���C�g�X�^�W�I��ssae�t�@�C���̕ϊ����s�����߂̃N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�X�v���C�g�^�C�v��Ǝ��`���ɕϊ�����
		@param[in]		t			SpriteStudio�̃X�v���C�g�^�C�v
				
		@return			�Ǝ��`���ł̃X�v���C�g�^�C�v
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
		@brief			�G�t�F�N�g�^�C�v��Ǝ��`���ɕϊ�����
		@param[in]		t			SpriteStudio�̃G�t�F�N�g�^�C�v
				
		@return			�Ǝ��`���ł̃X�v���C�g�^�C�v
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
		@brief			�u�����f�B���O���@��Ǝ��`���ɕϊ�����
		@param[in]		t			SpriteStudio�̃u�����f�B���O�^�C�v
				
		@return			�Ǝ��`���ł̃u�����f�B���O���@
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
		@brief			�u�����f�B���O���@��Ǝ��`���ɕϊ�����
		@param[in]		t			SpriteStudio�̃u�����f�B���O�^�C�v
				
		@return			�Ǝ��`���ł̃u�����f�B���O���@
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
		@brief			�L�[�^�C�v��Ǝ��`���ɕϊ�����
		@param[in]		t			SpriteStudio�̃L�[�^�C�v
				
		@return			�Ǝ��`���ł̃L�[�^�C�v
*//**************************************************************************/
FORCE_INLINE MofU32 CConvertSpriteStudio::ConvertKeyType(SsAttributeKind::_enum t){
	switch(t)
	{
		case SsAttributeKind::posx:		///<�ʒuX
			return MOFSPRITE_ANIMATIONKEY_TRANSLATIONX;
		case SsAttributeKind::posy:		///<�ʒuY
			return MOFSPRITE_ANIMATIONKEY_TRANSLATIONY;
		case SsAttributeKind::posz:		///<�ʒuZ
			return MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ;

		case SsAttributeKind::sclx:		///<�X�P�[��X
			return MOFSPRITE_ANIMATIONKEY_SCALINGX;
		case SsAttributeKind::scly:		///<�X�P�[��Y
			return MOFSPRITE_ANIMATIONKEY_SCALINGY;
			
		case SsAttributeKind::rotx:		///<��]X
			return MOFSPRITE_ANIMATIONKEY_ROTATIONX;
		case SsAttributeKind::roty:		///<��]Y
			return MOFSPRITE_ANIMATIONKEY_ROTATIONY;
		case SsAttributeKind::rotz:		///<��]Z
			return MOFSPRITE_ANIMATIONKEY_ROTATIONZ;
			
		case SsAttributeKind::alpha:	///<�s�����x
			return MOFSPRITE_ANIMATIONKEY_COLORA;

		case SsAttributeKind::prio:		//!<�D�揇��
			return MOFSPRITE_ANIMATIONKEY_PRIORITY;
			
		case SsAttributeKind::pivotx:	///<�I�t�Z�b�gX
			return MOFSPRITE_ANIMATIONKEY_ALIGNMENTX;
		case SsAttributeKind::pivoty:	///<�I�t�Z�b�gY
			return MOFSPRITE_ANIMATIONKEY_ALIGNMENTY;

		case SsAttributeKind::sizex:	///<�T�C�YX
			return MOFSPRITE_ANIMATIONKEY_SIZEX;
		case SsAttributeKind::sizey:	///<�T�C�YY
			return MOFSPRITE_ANIMATIONKEY_SIZEY;

		case SsAttributeKind::anchorx:	///<�A���J�[X
			return MOFSPRITE_ANIMATIONKEY_ANCHORX;
		case SsAttributeKind::anchory:	///<�A���J�[Y
			return MOFSPRITE_ANIMATIONKEY_ANCHORY;
			
		case SsAttributeKind::hide:		///<��\��
			return MOFSPRITE_ANIMATIONKEY_SHOW;

		case SsAttributeKind::fliph:	///<���E���](�Z���̌��_�����ɂ���)
		case SsAttributeKind::imgfliph:	///<�C���[�W���E���](��ɃC���[�W�̒��������_�Ƃ���)
			return MOFSPRITE_ANIMATIONKEY_XREVERSE;

		case SsAttributeKind::flipv:	///<�㉺���](�Z���̌��_�����ɂ���)
		case SsAttributeKind::imgflipv:	///<�C���[�W�㉺���](��ɃC���[�W�̒��������_�Ƃ���)
			return MOFSPRITE_ANIMATIONKEY_YREVERSE;

		case SsAttributeKind::vertex:	///< ���_�ό`
			return MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1;

		case SsAttributeKind::color:	///< ���_�ό`
			return MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1;

		case SsAttributeKind::uvtx:		///< UV�A�j��.�ړ�.X
			return MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX;
		case SsAttributeKind::uvty:		///< UV�A�j��.�ړ�.Y
			return MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY;
		case SsAttributeKind::uvrz:		///< UV�A�j��.��]
			return MOFSPRITE_ANIMATIONKEY_UVROTATION;
		case SsAttributeKind::uvsx:		///< UV�A�j��.�X�P�[��.X
			return MOFSPRITE_ANIMATIONKEY_UVSIZEX;
		case SsAttributeKind::uvsy:		///< UV�A�j��.�X�P�[��.Y
			return MOFSPRITE_ANIMATIONKEY_UVSIZEY;

		case SsAttributeKind::effect:	//!<�G�t�F�N�g�p�����[�^�[
			return MOFSPRITE_ANIMATIONKEY_EFFECTTIME;
	}
	return BLEND_NONE;
}
/*************************************************************************//*!
		@brief			�L�[��ԃ^�C�v��Ǝ��`���ɕϊ�����
		@param[in]		t			SpriteStudio�̃L�[��ԃ^�C�v
				
		@return			�Ǝ��`���ł̃L�[�^�C�v
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