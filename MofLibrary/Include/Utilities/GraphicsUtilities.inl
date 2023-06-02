/*************************************************************************//*!
					
					@file	GraphicsUtilities.inl
					@brief	�`��֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���̕`��
		@param[in]		sv			�J�n�ʒu
		@param[in]		ev			�I���ʒu
		@param[in]		col			�`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLine(const Vector2& sv,const Vector2& ev,MofU32 col){
	return RenderLine(sv.x,sv.y,ev.x,ev.y,col);
}
/*************************************************************************//*!
		@brief			���̕`��
		@param[in]		sv			�J�n�ʒu
		@param[in]		ev			�I���ʒu
		@param[in]		col			�`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLine(const Vector3& sv,const Vector3& ev,MofU32 col){
	return RenderLine(sv.x,sv.y,sv.z,ev.x,ev.y,ev.z,col);
}
/*************************************************************************//*!
		@brief			�O���b�h�̕`��
		@param[in]		bet			�Ԋu
		@param[in]		s			�T�C�Y
		@param[in]		col			�`��F
		@param[in]		plane		�\������
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderGrid(MofFloat bet, MofFloat s, MofU32 col, PlaneAxis plane){
	return RenderGrid(Vector3(0, 0, 0), bet, s, col, plane);
}
/*************************************************************************//*!
		@brief			��`�̕`��
		@param[in]		rec			��`
		@param[in]		col			�`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRect(const Rectangle& rec,MofU32 col){
	return RenderRect(rec.Left,rec.Top,rec.Right,rec.Bottom,col);
}
/*************************************************************************//*!
		@brief			�h��Ԃ���`�̕`��
		@param[in]		rec			��`
		@param[in]		col			�`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillRect(const Rectangle& rec,MofU32 col){
	return RenderFillRect(rec.Left,rec.Top,rec.Right,rec.Bottom,col,col,col,col);
}
/*************************************************************************//*!
		@brief			�h��Ԃ���`�̕`��
		@param[in]		rec			��`
		@param[in]		ltc			����`��F
		@param[in]		lbc			�����`��F
		@param[in]		rtc			�E��`��F
		@param[in]		rbc			�E���`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillRect(const Rectangle& rec,MofU32 ltc,MofU32 lbc,MofU32 rtc,MofU32 rbc){
	return RenderFillRect(rec.Left,rec.Top,rec.Right,rec.Bottom,ltc,lbc,rtc,rbc);
}
/*************************************************************************//*!
		@brief			�h��Ԃ���`�̕`��
		@param[in]		l			��
		@param[in]		t			��
		@param[in]		r			�E
		@param[in]		b			��
		@param[in]		col			�`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b,MofU32 col){
	return RenderFillRect(l,t,r,b,col,col,col,col);
}
/*************************************************************************//*!
		@brief			�~�̕`��
		@param[in]		c			�`��~
		@param[in]		col			�`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderCircle(const Circle& c,MofU32 col){
	return RenderCircle(c.x,c.y,c.r,col);
}
/*************************************************************************//*!
		@brief			�h��Ԃ��~�̕`��
		@param[in]		c			�`��~
		@param[in]		col			�`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillCircle(const Circle& c,MofU32 col){
	return RenderFillCircle(c.x,c.y,c.r,col,col);
}
/*************************************************************************//*!
		@brief			�h��Ԃ��~�̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		r			�`�攼�a
		@param[in]		col			�`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillCircle(MofFloat px,MofFloat py,MofFloat r,MofU32 col){
	return RenderFillCircle(px,py,r,col,col);
}
/*************************************************************************//*!
		@brief			�h��Ԃ��~�̕`��
		@param[in]		c			�`��~
		@param[in]		Ccol		���S�`��F
		@param[in]		Ocol		�O���`��F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderFillCircle(const Circle& c,MofU32 Ccol,MofU32 Ocol){
	return RenderFillCircle(c.x,c.y,c.r,Ccol,Ocol);
}

/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		b			AABB
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLineBox(const BoxAABB& b){
	Matrix44 m;
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderLineBox(m);
}
/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		b			OBB
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLineBox(const BoxOBB& b){
	Matrix44 m;
	CMatrix44Utilities::RotationZXY(b.Angle,m);
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderLineBox(m);
}

/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		b			AABB
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderBox(const BoxAABB& b){
	Matrix44 m;
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderBox(m);
}
/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		b			AABB
		@param[in]		col			�F�␳
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderBox(const BoxAABB& b, const Vector4& col){
	Matrix44 m;
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderBox(m,col);
}
/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		b			OBB
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderBox(const BoxOBB& b){
	Matrix44 m;
	CMatrix44Utilities::RotationZXY(b.Angle,m);
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderBox(m);
}
/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		b			OBB
		@param[in]		col			�F�␳
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderBox(const BoxOBB& b, const Vector4& col){
	Matrix44 m;
	CMatrix44Utilities::RotationZXY(b.Angle,m);
	CMatrix44Utilities::Scaling(b.Size.x * 2,b.Size.y * 2,b.Size.z * 2,m,m);
	CMatrix44Utilities::SetTranslation(b.Position,m);
	return RenderBox(m, col);
}

/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		s			����
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLineSphere(const Sphere& s){
	Matrix44 m;
	CMatrix44Utilities::Scaling(s.r,m);
	CMatrix44Utilities::SetTranslation(s.x,s.y,s.z,m);
	return RenderLineSphere(m);
}
/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		s			����
		@param[in]		col			�F�␳
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderLineSphere(const Sphere& s, const Vector4& col){
	Matrix44 m;
	CMatrix44Utilities::Scaling(s.r,m);
	CMatrix44Utilities::SetTranslation(s.x,s.y,s.z,m);
	return RenderLineSphere(m, col);
}

/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		s			����
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderSphere(const Sphere& s){
	Matrix44 m;
	CMatrix44Utilities::Scaling(s.r,m);
	CMatrix44Utilities::SetTranslation(s.x,s.y,s.z,m);
	return RenderSphere(m);
}
/*************************************************************************//*!
		@brief			3D���̕`��
		@param[in]		s			����
		@param[in]		col			�F�␳
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderSphere(const Sphere& s, const Vector4& col){
	Matrix44 m;
	CMatrix44Utilities::Scaling(s.r,m);
	CMatrix44Utilities::SetTranslation(s.x,s.y,s.z,m);
	return RenderSphere(m,col);
}

/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,LPTexture pTex){
	return RenderTexture(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		pTex		�e�N�X�`��
		@param[in]		pShader		�V�F�[�_�[
		@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind){
	return RenderTexture(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex,pShader,pShaderBind);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px				�`��X���W
		@param[in]		py				�`��Y���W
		@param[in]		pTex			�e�N�X�`��
		@param[in]		pShaderEffect	�V�F�[�_�[
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,LPTexture pTex,LPShaderEffect pShaderEffect){
	return RenderTexture(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex,pShaderEffect->GetShader(), pShaderEffect->GetShaderBind());
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,MofU32 col,LPTexture pTex){
	return RenderTexture(px,py,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,TextureAlignment Alignment,LPTexture pTex){
	return RenderTexture(px,py,MOF_COLOR_WHITE,Alignment,pTex);
}
		


/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		srec		�摜�\����`
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,LPTexture pTex){
	return RenderTexture(px,py,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		srec		�摜�\����`
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderTexture(px,py,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		srec		�摜�\����`
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderTexture(px,py,srec,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		drec		�`���`
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Rectangle& drec,LPTexture pTex){
	return RenderTexture(drec,MOF_COLOR_WHITE,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		drec		�`���`
		@param[in]		pTex		�e�N�X�`��
		@param[in]		pShader		�V�F�[�_�[
		@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
		
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Rectangle& drec,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind){
	return RenderTexture(drec,MOF_COLOR_WHITE,pTex,pShader,pShaderBind);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		drec		�`���`
		@param[in]		srec		�摜�\����`
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Rectangle& drec,const Rectangle& srec,LPTexture pTex){
	return RenderTexture(drec,srec,MOF_COLOR_WHITE,pTex);
}

/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		drec		�`���`
		@param[in]		srec		�摜�\����`
		@param[in]		pTex		�e�N�X�`��
		@param[in]		pShader		�V�F�[�_�[
		@param[in]		pShaderBind	�V�F�[�_�[�o�C���h

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Rectangle& drec, const Rectangle& srec, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind) {
	return RenderTexture(drec, srec, MOF_COLOR_WHITE, pTex, pShader, pShaderBind);
}


/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,MofU32 col,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,MOF_COLOR_WHITE,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		col			�`��F
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,MofU32 col,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,col,Alignment,pTex);
}


		
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		srec		�摜�\����`
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		srec		�摜�\����`
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		srec		�摜�\����`
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,srec,MOF_COLOR_WHITE,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		srec		�摜�\����`
		@param[in]		col			�`��F
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,s,s,srec,col,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		srec		�摜�\����`
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		srec		�摜�\����`
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		srec		�摜�\����`
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleTexture(px,py,sx,sy,srec,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		ang			��]�p�x
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		ang			��]�p�x
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		ang			��]�p�x
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,TextureAlignment Alignment,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderRotateTexture(px,py,ang,srec,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,MOF_COLOR_WHITE,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		col			�`��F
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,col,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,MOF_COLOR_WHITE,Alignment,pTex);
}



/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,srec,MOF_COLOR_WHITE,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		s			�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		col			�`��F
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,s,s,ang,srec,col,Alignment,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,srec,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,srec,col,TEXTUREALIGNMENT_TOPLEFT,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		sx			�w�g��{��
		@param[in]		sy			�x�g��{��
		@param[in]		ang			��]�p�x
		@param[in]		srec		�摜�\����`
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex){
	return RenderScaleRotateTexture(px,py,sx,sy,ang,srec,MOF_COLOR_WHITE,Alignment,pTex);
}

/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		wMat		�ϊ��s��
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Matrix44& wMat,LPTexture pTex){
	return RenderTexture(wMat,MOF_COLOR_WHITE,TRUE,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		wMat		�ϊ��s��
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Matrix44& wMat,MofU32 col,LPTexture pTex){
	return RenderTexture(wMat,col,TRUE,pTex);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		wMat		�ϊ��s��
		@param[in]		srec		�摜�\����`
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Matrix44& wMat,const Rectangle& srec,LPTexture pTex){
	return RenderTexture(wMat,srec,MOF_COLOR_WHITE,TRUE,pTex);
}

/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		wMat		�ϊ��s��
		@param[in]		srec		�摜�\����`
		@param[in]		col			�`��F
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGraphicsUtilities::RenderTexture(const Matrix44& wMat,const Rectangle& srec,MofU32 col,LPTexture pTex){
	return RenderTexture(wMat,srec,col,TRUE,pTex);
}

/*************************************************************************//*!
		@brief			�`��p�O���t�B�b�N�X��ݒ肷��
		@param[in]		pg				�O���t�B�b�N�X

		@return			None
*//**************************************************************************/
FORCE_INLINE void CGraphicsUtilities::SetGraphics(LPGraphics pg){
	m_pGraphics = pg;
	return;
}
/*************************************************************************//*!
		@brief			�`��p�O���t�B�b�N�X�R�}���h�v���L�V��ݒ肷��
		@param[in]		pg				�O���t�B�b�N�X�R�}���h�v���L�V

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
		@brief			�`��p�O���t�B�b�N�X���擾����
		@param			None

		@return			�`��p�O���t�B�b�N�X
*//**************************************************************************/
FORCE_INLINE  LPGraphics CGraphicsUtilities::GetGraphics(void){
	return m_pGraphics;
}
/*************************************************************************//*!
		@brief			�`��p�O���t�B�b�N�X�R�}���h�v���L�V���擾����
		@param			None

		@return			�`��p�O���t�B�b�N�X�R�}���h�v���L�V
*//**************************************************************************/
FORCE_INLINE LPRenderCommandProxy CGraphicsUtilities::GetCommandProxy(void){
	return m_pCommandProxy;
}
/*************************************************************************//*!
		@brief			�`��p�J�������擾����
		@param			None

		@return			�`��p�J����
*//**************************************************************************/
FORCE_INLINE LPCamera CGraphicsUtilities::GetCamera(void){
	return m_pCamera;
}
/*************************************************************************//*!
		@brief			�`��p��{���C�g���擾����
		@param			None

		@return			�`��p��{���C�g
*//**************************************************************************/
FORCE_INLINE LPDirectionalLight CGraphicsUtilities::GetDirectionalLight(void){
	return m_pDirectionalLight;
}

//[EOF]