/*************************************************************************//*!
					
					@file	Matrix33.inl
					@brief	3×3行列演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Matrix33
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Matrix33::Matrix33(){
	_11 = 1;	_12 = 0;	_13 = 0;
	_21 = 0;	_22 = 1;	_23 = 0;
	_31 = 0;	_32 = 0;	_33 = 1;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		f11			11成分
		@param[in]		f12			12成分
		@param[in]		f13			13成分
		@param[in]		f21			21成分
		@param[in]		f22			22成分
		@param[in]		f23			23成分
		@param[in]		f31			31成分
		@param[in]		f32			32成分
		@param[in]		f33			33成分

		@return			None
*//**************************************************************************/
FORCE_INLINE Matrix33::Matrix33(	MofFloat f11 ,MofFloat f12 ,MofFloat f13,
									MofFloat f21 ,MofFloat f22 ,MofFloat f23,
									MofFloat f31 ,MofFloat f32 ,MofFloat f33 ){
	_11 = f11;	_12 = f12;	_13 = f13;
	_21 = f21;	_22 = f22;	_23 = f23;
	_31 = f31;	_32 = f32;	_33 = f33;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pf			パラメーター（16個以上の配列であること）

		@return			None
*//**************************************************************************/
FORCE_INLINE Matrix33::Matrix33( MofFloat* pf ){
	memcpy(&_11,pf,sizeof(Matrix33));
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー行列

		@return			None
*//**************************************************************************/
FORCE_INLINE Matrix33::Matrix33( const Matrix33& pObj ){
	_11 = pObj._11;	_12 = pObj._12;	_13 = pObj._13;
	_21 = pObj._21;	_22 = pObj._22;	_23 = pObj._23;
	_31 = pObj._31;	_32 = pObj._32;	_33 = pObj._33;
}
/*************************************************************************//*!
		@brief			floatキャスト<br>
						内部の座標をfloatポインタとしてそのまま返す。
*//**************************************************************************/
FORCE_INLINE Matrix33::operator MofFloat * (){
	return (MofFloat*)&_11;
}
/*************************************************************************//*!
		@brief			+取得
*//**************************************************************************/
FORCE_INLINE Matrix33 Matrix33::operator + () const{
	return Matrix33((MofFloat*)&_11);
}
/*************************************************************************//*!
		@brief			-取得
*//**************************************************************************/
FORCE_INLINE Matrix33 Matrix33::operator - () const{
	return Matrix33(	-_11,-_12,-_13,
						-_21,-_22,-_23,
						-_31,-_32,-_33);
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Matrix33& Matrix33::operator += (const Matrix33 &m){
	_11 += m._11; _12 += m._12; _13 += m._13;
	_21 += m._21; _22 += m._22; _23 += m._23;
	_31 += m._31; _32 += m._32; _33 += m._33;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Matrix33& Matrix33::operator -= (const Matrix33 &m){
	_11 -= m._11; _12 -= m._12; _13 -= m._13;
	_21 -= m._21; _22 -= m._22; _23 -= m._23;
	_31 -= m._31; _32 -= m._32; _33 -= m._33;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの*=演算
*//**************************************************************************/
FORCE_INLINE Matrix33& Matrix33::operator *= (const MofFloat m){
	_11 *= m; _12 *= m; _13 *= m;
	_21 *= m; _22 *= m; _23 *= m;
	_31 *= m; _32 *= m; _33 *= m;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの/=演算
*//**************************************************************************/
FORCE_INLINE Matrix33& Matrix33::operator /= (const MofFloat m){
	_11 /= m; _12 /= m; _13 /= m;
	_21 /= m; _22 /= m; _23 /= m;
	_31 /= m; _32 /= m; _33 /= m;
	return *this;
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Matrix33 Matrix33::operator + (const Matrix33& m) const{
	return Matrix33(	_11 + m._11,_12 + m._12,_13 + m._13,
						_21 + m._21,_22 + m._22,_23 + m._23,
						_31 + m._31,_32 + m._32,_33 + m._33);
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Matrix33 Matrix33::operator - (const Matrix33& m) const{
	return Matrix33(	_11 - m._11,_12 - m._12,_13 - m._13,
						_21 - m._21,_22 - m._22,_23 - m._23,
						_31 - m._31,_32 - m._32,_33 - m._33);
}
/*************************************************************************//*!
		@brief			floatとの*演算
*//**************************************************************************/
FORCE_INLINE Matrix33 Matrix33::operator * (const MofFloat m) const{
	return Matrix33(	_11 * m,_12 * m,_13 * m,
						_21 * m,_22 * m,_23 * m,
						_31 * m,_32 * m,_33 * m);
}
/*************************************************************************//*!
		@brief			floatとの/演算
*//**************************************************************************/
FORCE_INLINE Matrix33 Matrix33::operator / (const MofFloat m) const{
	return Matrix33(	_11 / m,_12 / m,_13 / m,
						_21 / m,_22 / m,_23 / m,
						_31 / m,_32 / m,_33 / m);
}
/*************************************************************************//*!
		@brief			配列指定によるMatrix33メンバへのアクセス
*//**************************************************************************/
FORCE_INLINE MofFloat& Matrix33::operator [] ( int i ){
	return val[i];
}
/*************************************************************************//*!
		@brief			配列指定によるMatrix33メンバへのアクセス
*//**************************************************************************/
FORCE_INLINE const MofFloat& Matrix33::operator [] ( int i ) const{
	return val[i];
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool Matrix33::operator == (const Matrix33& m) const{
	return 0 == memcmp(val, &m.val, sizeof(MofFloat) * 9);
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool Matrix33::operator != (const Matrix33& m) const{
	return 0 != memcmp(val, &m.val, sizeof(MofFloat) * 9);
}
//--------------------------------------------------------------------------------------------
//CMatrix33Utilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			単位行列設定
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Identity(Matrix33& OutMat){
	OutMat._11 = 1;	OutMat._12 = 0;	OutMat._13 = 0;
	OutMat._21 = 0;	OutMat._22 = 1;	OutMat._23 = 0;
	OutMat._31 = 0;	OutMat._32 = 0;	OutMat._33 = 1;
}
/*************************************************************************//*!
		@brief			転置行列設定<br>
						入力行列と出力行列に同じ参照を設定する場合、引数が一つの方を利用すること
		@param[in]		InMat		入力行列
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Transpose(const Matrix33& InMat,Matrix33& OutMat){
	MofFloat _12 = InMat._12; MofFloat _13 = InMat._13;
	MofFloat _21 = InMat._21; MofFloat _23 = InMat._23;
	MofFloat _31 = InMat._31; MofFloat _32 = InMat._32;
	
	OutMat._11 = InMat._11;
	OutMat._22 = InMat._22;
	OutMat._33 = InMat._33;
	OutMat._12 = _21; OutMat._13 = _31;
	OutMat._21 = _12; OutMat._23 = _32;
	OutMat._31 = _13; OutMat._32 = _23;
}
/*************************************************************************//*!
		@brief			転置行列設定
		@param[in,out]	OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Transpose(Matrix33& OutMat){
	MofFloat _12 = OutMat._12; MofFloat _13 = OutMat._13;
	MofFloat _21 = OutMat._21; MofFloat _23 = OutMat._23;
	MofFloat _31 = OutMat._31; MofFloat _32 = OutMat._32;

	OutMat._12 = _21; OutMat._13 = _31;
	OutMat._21 = _12; OutMat._23 = _32;
	OutMat._31 = _13; OutMat._32 = _23;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		v			倍率
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Scaling(const Vector3& v,Matrix33& OutMat){
	OutMat._12 = OutMat._13 = 
	OutMat._21 = OutMat._23 = 
	OutMat._31 = OutMat._32 = 0.0f;
	OutMat._11 = v.x; OutMat._22 = v.y; OutMat._33 = v.z;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		s			倍率
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Scaling(const MofFloat s,Matrix33& OutMat){
	OutMat._12 = OutMat._13 =
	OutMat._21 = OutMat._23 =
	OutMat._31 = OutMat._32 = 0.0f;
	OutMat._11 = OutMat._22 = OutMat._33 = s;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		x			X倍率
		@param[in]		y			Y倍率
		@param[in]		z			Z倍率
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Scaling(const MofFloat x,const MofFloat y,const MofFloat z,Matrix33& OutMat){
	OutMat._12 = OutMat._13 = 
	OutMat._21 = OutMat._23 = 
	OutMat._31 = OutMat._32 = 0.0f;
	OutMat._11 = x; OutMat._22 = y; OutMat._33 = z;
	return;
}

		
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						元行列 × 拡大行列の結果を結果行列に設定する。
		@param[in]		InMat		元行列
		@param[in]		v			倍率
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Scaling(const Matrix33& InMat,const Vector3& v,Matrix33& OutMat){
	OutMat._11 = InMat._11 * v.x;	OutMat._12 = InMat._12 * v.y;	OutMat._13 = InMat._13 * v.z;
	OutMat._21 = InMat._21 * v.x;	OutMat._22 = InMat._22 * v.y;	OutMat._23 = InMat._23 * v.z;
	OutMat._31 = InMat._31 * v.x;	OutMat._32 = InMat._32 * v.y;	OutMat._33 = InMat._33 * v.z;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						元行列 × 拡大行列の結果を結果行列に設定する。
		@param[in]		InMat		元行列
		@param[in]		s			倍率
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Scaling(const Matrix33& InMat,const MofFloat s,Matrix33& OutMat){
	OutMat._11 = InMat._11 * s;		OutMat._12 = InMat._12 * s;		OutMat._13 = InMat._13 * s;
	OutMat._21 = InMat._21 * s;		OutMat._22 = InMat._22 * s;		OutMat._23 = InMat._23 * s;
	OutMat._31 = InMat._31 * s;		OutMat._32 = InMat._32 * s;		OutMat._33 = InMat._33 * s;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						元行列 × 拡大行列の結果を結果行列に設定する。
		@param[in]		InMat		元行列
		@param[in]		x			X倍率
		@param[in]		y			Y倍率
		@param[in]		z			Z倍率
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Scaling(const Matrix33& InMat,const MofFloat x,const MofFloat y,const MofFloat z,Matrix33& OutMat){
	OutMat._11 = InMat._11 * x;		OutMat._12 = InMat._12 * y;		OutMat._13 = InMat._13 * z;
	OutMat._21 = InMat._21 * x;		OutMat._22 = InMat._22 * y;		OutMat._23 = InMat._23 * z;
	OutMat._31 = InMat._31 * x;		OutMat._32 = InMat._32 * y;		OutMat._33 = InMat._33 * z;
	return;
}

/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						拡大行列 × 元行列の結果を結果行列に設定する。
		@param[in]		v			倍率
		@param[in]		InMat		元行列
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Scaling(const Vector3& v,const Matrix33& InMat,Matrix33& OutMat){
	OutMat._11 = InMat._11 * v.x;	OutMat._12 = InMat._12 * v.x;	OutMat._13 = InMat._13 * v.x;
	OutMat._21 = InMat._21 * v.y;	OutMat._22 = InMat._22 * v.y;	OutMat._23 = InMat._23 * v.y;
	OutMat._31 = InMat._31 * v.z;	OutMat._32 = InMat._32 * v.z;	OutMat._33 = InMat._33 * v.z;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						拡大行列 × 元行列の結果を結果行列に設定する。
		@param[in]		s			倍率
		@param[in]		InMat		元行列
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Scaling(const MofFloat s,const Matrix33& InMat,Matrix33& OutMat){
	OutMat._11 = InMat._11 * s;		OutMat._12 = InMat._12 * s;		OutMat._13 = InMat._13 * s;
	OutMat._21 = InMat._21 * s;		OutMat._22 = InMat._22 * s;		OutMat._23 = InMat._23 * s;
	OutMat._31 = InMat._31 * s;		OutMat._32 = InMat._32 * s;		OutMat._33 = InMat._33 * s;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						拡大行列 × 元行列の結果を結果行列に設定する。
		@param[in]		x			X倍率
		@param[in]		y			Y倍率
		@param[in]		z			Z倍率
		@param[in]		InMat		元行列
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::Scaling(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix33& InMat,Matrix33& OutMat){
	OutMat._11 = InMat._11 * x;		OutMat._12 = InMat._12 * x;		OutMat._13 = InMat._13 * x;	
	OutMat._21 = InMat._21 * y;		OutMat._22 = InMat._22 * y;		OutMat._23 = InMat._23 * y;	
	OutMat._31 = InMat._31 * z;		OutMat._32 = InMat._32 * z;		OutMat._33 = InMat._33 * z;
	return;
}

/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Y→Zの順で回転を行う
		@param[in]		v			回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationXYZ(const Vector3& v,Matrix33& OutMat){
	RotationX(v.x,OutMat);
	RotationY(OutMat,v.y,OutMat);
	RotationZ(OutMat,v.z,OutMat);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Y→Zの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationXYZ(const MofFloat x,const MofFloat y,const MofFloat z,Matrix33& OutMat){
	RotationX(x,OutMat);
	RotationY(OutMat,y,OutMat);
	RotationZ(OutMat,z,OutMat);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Z→Yの順で回転を行う
		@param[in]		v			回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationXZY(const Vector3& v,Matrix33& OutMat){
	RotationX(v.x,OutMat);
	RotationZ(OutMat,v.z,OutMat);
	RotationY(OutMat,v.y,OutMat);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Z→Yの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationXZY(const MofFloat x,const MofFloat y,const MofFloat z,Matrix33& OutMat){
	RotationX(x,OutMat);
	RotationZ(OutMat,z,OutMat);
	RotationY(OutMat,y,OutMat);
	return;
}

/*************************************************************************//*!
		@brief			回転行列計算<br>
						Y→X→Zの順で回転を行う
		@param[in]		v			回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationYXZ(const Vector3& v,Matrix33& OutMat){
	RotationY(v.y,OutMat);
	RotationX(OutMat,v.x,OutMat);
	RotationZ(OutMat,v.z,OutMat);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Y→X→Zの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationYXZ(const MofFloat x,const MofFloat y,const MofFloat z,Matrix33& OutMat){
	RotationY(y,OutMat);
	RotationX(OutMat,x,OutMat);
	RotationZ(OutMat,z,OutMat);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Y→Z→Xの順で回転を行う
		@param[in]		v			回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationYZX(const Vector3& v,Matrix33& OutMat){
	RotationY(v.y,OutMat);
	RotationZ(OutMat,v.z,OutMat);
	RotationX(OutMat,v.x,OutMat);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Y→Z→Xの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationYZX(const MofFloat x,const MofFloat y,const MofFloat z,Matrix33& OutMat){
	RotationY(y,OutMat);
	RotationZ(OutMat,z,OutMat);
	RotationX(OutMat,x,OutMat);
	return;
}

/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→X→Yの順で回転を行う
		@param[in]		v			回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationZXY(const Vector3& v,Matrix33& OutMat){
	RotationZ(v.z,OutMat);
	RotationX(OutMat,v.x,OutMat);
	RotationY(OutMat,v.y,OutMat);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→X→Yの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationZXY(const MofFloat x,const MofFloat y,const MofFloat z,Matrix33& OutMat){
	RotationZ(z,OutMat);
	RotationX(OutMat,x,OutMat);
	RotationY(OutMat,y,OutMat);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→Y→Xの順で回転を行う
		@param[in]		v			回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationZYX(const Vector3& v,Matrix33& OutMat){
	RotationZ(v.z,OutMat);
	RotationY(OutMat,v.y,OutMat);
	RotationX(OutMat,v.x,OutMat);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→Y→Xの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationZYX(const MofFloat x,const MofFloat y,const MofFloat z,Matrix33& OutMat){
	RotationZ(z,OutMat);
	RotationY(OutMat,y,OutMat);
	RotationX(OutMat,x,OutMat);
	return;
}

/*************************************************************************//*!
		@brief			X軸回転行列計算
		@param[in]		ax			X回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationX(const MofFloat ax,Matrix33& OutMat){
	MofFloat sina = MOF_SIN(ax);
	MofFloat cosa = MOF_COS(ax);
	OutMat._12 = OutMat._13 = OutMat._21 = OutMat._31 = 0.0f;
	OutMat._11 = 1.0f;
	OutMat._23 = sina;
	OutMat._32 = -sina;
	OutMat._22 = OutMat._33 = cosa;
	return;
}
/*************************************************************************//*!
		@brief			Y軸回転行列計算
		@param[in]		ay			Y回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationY(const MofFloat ay,Matrix33& OutMat){
	MofFloat sina = MOF_SIN(ay);
	MofFloat cosa = MOF_COS(ay);
	OutMat._12 = OutMat._21 = OutMat._23 = OutMat._32 = 0.0f;
	OutMat._22 = 1.0f;
	OutMat._13 = -sina;
	OutMat._31 = sina;
	OutMat._11 = OutMat._33 = cosa;
	return;
}
/*************************************************************************//*!
		@brief			Z軸回転行列計算
		@param[in]		az			Z回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::RotationZ(const MofFloat az,Matrix33& OutMat){
	MofFloat sina = MOF_SIN(az);
	MofFloat cosa = MOF_COS(az);
	OutMat._13 = OutMat._23 = OutMat._31 = OutMat._32 = 0.0f;
	OutMat._33 = 1.0f;
	OutMat._12 = sina;
	OutMat._21 = -sina;
	OutMat._11 = OutMat._22 = cosa;
	return;
}
/*************************************************************************//*!
		@brief			元行列の拡大ベクトル取得
		@param[in]		InMat		元行列
		@param[out]		v			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33Utilities::GetScaling(const Matrix33& InMat,Vector3& v){
	v.x = MOF_SQRT(InMat._11 * InMat._11 + InMat._12 * InMat._12 + InMat._13 * InMat._13);
	v.y = MOF_SQRT(InMat._21 * InMat._21 + InMat._22 * InMat._22 + InMat._23 * InMat._23);
	v.z = MOF_SQRT(InMat._31 * InMat._31 + InMat._32 * InMat._32 + InMat._33 * InMat._33);
	return;
}
//--------------------------------------------------------------------------------------------
//CMatrix33
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix33::CMatrix33() :
Matrix33() {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		f11			11成分
		@param[in]		f12			12成分
		@param[in]		f13			13成分
		@param[in]		f14			14成分
		@param[in]		f21			21成分
		@param[in]		f22			22成分
		@param[in]		f23			23成分
		@param[in]		f24			24成分
		@param[in]		f31			31成分
		@param[in]		f32			32成分
		@param[in]		f33			33成分
		@param[in]		f34			34成分
		@param[in]		f41			41成分
		@param[in]		f42			42成分
		@param[in]		f43			43成分
		@param[in]		f44			44成分

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix33::CMatrix33(	MofFloat f11 ,MofFloat f12 ,MofFloat f13,
									MofFloat f21 ,MofFloat f22 ,MofFloat f23,
									MofFloat f31 ,MofFloat f32 ,MofFloat f33){
	_11 = f11;	_12 = f12;	_13 = f13;
	_21 = f21;	_22 = f22;	_23 = f23;
	_31 = f31;	_32 = f32;	_33 = f33;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pf			パラメーター（16個以上の配列であること）

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix33::CMatrix33( MofFloat* pf ) :
Matrix33(pf) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー行列

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix33::CMatrix33( const Matrix33& pObj ) :
Matrix33(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー行列

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix33::CMatrix33( const CMatrix33& pObj ) :
Matrix33(pObj) {
}
/*************************************************************************//*!
		@brief			単位行列設定
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Identity(void){
	_11 = 1;	_12 = 0;	_13 = 0;
	_21 = 0;	_22 = 1;	_23 = 0;
	_31 = 0;	_32 = 0;	_33 = 1;
}
/*************************************************************************//*!
		@brief			転置行列設定
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Transpose(void){
	MofFloat M12 = _12; MofFloat M13 = _13;
	MofFloat M21 = _21; MofFloat M23 = _23;
	MofFloat M31 = _31; MofFloat M32 = _32;

	_12 = M21; _13 = M31;
	_21 = M12; _23 = M32;
	_31 = M13; _32 = M23;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		v			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Scaling(const Vector3& v){
	_12 = _13 =
	_21 = _23 =
	_31 = _32 = 0.0f;
	_11 = v.x; _22 = v.y; _33 = v.z;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		s			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Scaling(const MofFloat s){
	_12 = _13 = 
	_21 = _23 = 
	_31 = _32 = 0.0f;
	_11 = _22 = _33 = s;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		x			X倍率
		@param[in]		y			Y倍率
		@param[in]		z			Z倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Scaling(const MofFloat x,const MofFloat y,const MofFloat z){
	_12 = _13 = 
	_21 = _23 = 
	_31 = _32 = 0.0f;
	_11 = x; _22 = y; _33 = z;
	return;
}
		
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						元行列 × 拡大行列の結果を自身に設定する。
		@param[in]		InMat		元行列
		@param[in]		v			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Scaling(const Matrix33& InMat,const Vector3& v){
	_11 = InMat._11 * v.x;	_12 = InMat._12 * v.y;	_13 = InMat._13 * v.z;
	_21 = InMat._21 * v.x;	_22 = InMat._22 * v.y;	_23 = InMat._23 * v.z;
	_31 = InMat._31 * v.x;	_32 = InMat._32 * v.y;	_33 = InMat._33 * v.z;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						元行列 × 拡大行列の結果を自身に設定する。
		@param[in]		InMat		元行列
		@param[in]		s			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Scaling(const Matrix33& InMat,const MofFloat s){
	_11 = InMat._11 * s;	_12 = InMat._12 * s;	_13 = InMat._13 * s;
	_21 = InMat._21 * s;	_22 = InMat._22 * s;	_23 = InMat._23 * s;
	_31 = InMat._31 * s;	_32 = InMat._32 * s;	_33 = InMat._33 * s;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						元行列 × 拡大行列の結果を自身に設定する。
		@param[in]		InMat		元行列
		@param[in]		x			X倍率
		@param[in]		y			Y倍率
		@param[in]		z			Z倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Scaling(const Matrix33& InMat,const MofFloat x,const MofFloat y,const MofFloat z){
	_11 = InMat._11 * x;	_12 = InMat._12 * y;	_13 = InMat._13 * z;
	_21 = InMat._21 * x;	_22 = InMat._22 * y;	_23 = InMat._23 * z;
	_31 = InMat._31 * x;	_32 = InMat._32 * y;	_33 = InMat._33 * z;
	return;
}

/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						拡大行列 × 元行列の結果を自身に設定する。
		@param[in]		v			倍率
		@param[in]		InMat		元行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Scaling(const Vector3& v,const Matrix33& InMat){
	_11 = InMat._11 * v.x;	_12 = InMat._12 * v.x;	_13 = InMat._13 * v.x;
	_21 = InMat._21 * v.y;	_22 = InMat._22 * v.y;	_23 = InMat._23 * v.y;
	_31 = InMat._31 * v.z;	_32 = InMat._32 * v.z;	_33 = InMat._33 * v.z;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						拡大行列 × 元行列の結果を自身に設定する。
		@param[in]		s			倍率
		@param[in]		InMat		元行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Scaling(const MofFloat s,const Matrix33& InMat){
	_11 = InMat._11 * s;	_12 = InMat._12 * s;	_13 = InMat._13 * s;
	_21 = InMat._21 * s;	_22 = InMat._22 * s;	_23 = InMat._23 * s;
	_31 = InMat._31 * s;	_32 = InMat._32 * s;	_33 = InMat._33 * s;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						拡大行列 × 元行列の結果を自身に設定する。
		@param[in]		x			X倍率
		@param[in]		y			Y倍率
		@param[in]		z			Z倍率
		@param[in]		InMat		元行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::Scaling(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix33& InMat){
	_11 = InMat._11 * x;	_12 = InMat._12 * x;	_13 = InMat._13 * x;
	_21 = InMat._21 * y;	_22 = InMat._22 * y;	_23 = InMat._23 * y;
	_31 = InMat._31 * z;	_32 = InMat._32 * z;	_33 = InMat._33 * z;
	return;
}

/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Y→Zの順で回転を行う
		@param[in]		v			回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationXYZ(const Vector3& v){
	RotationX(v.x);
	RotationY(*this,v.y);
	RotationZ(*this,v.z);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Y→Zの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationXYZ(const MofFloat x,const MofFloat y,const MofFloat z){
	RotationX(x);
	RotationY(*this,y);
	RotationZ(*this,z);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Z→Yの順で回転を行う
		@param[in]		v			回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationXZY(const Vector3& v){
	RotationX(v.x);
	RotationZ(*this,v.z);
	RotationY(*this,v.y);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Z→Yの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationXZY(const MofFloat x,const MofFloat y,const MofFloat z){
	RotationX(x);
	RotationZ(*this,z);
	RotationY(*this,y);
	return;
}

/*************************************************************************//*!
		@brief			回転行列計算<br>
						Y→X→Zの順で回転を行う
		@param[in]		v			回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationYXZ(const Vector3& v){
	RotationY(v.y);
	RotationX(*this,v.x);
	RotationZ(*this,v.z);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Y→X→Zの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationYXZ(const MofFloat x,const MofFloat y,const MofFloat z){
	RotationY(y);
	RotationX(*this,x);
	RotationZ(*this,z);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Y→Z→Xの順で回転を行う
		@param[in]		v			回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationYZX(const Vector3& v){
	RotationY(v.y);
	RotationZ(*this,v.z);
	RotationX(*this,v.x);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Y→Z→Xの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationYZX(const MofFloat x,const MofFloat y,const MofFloat z){
	RotationY(y);
	RotationZ(*this,z);
	RotationX(*this,x);
	return;
}

/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→X→Yの順で回転を行う
		@param[in]		v			回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationZXY(const Vector3& v){
	RotationZ(v.z);
	RotationX(*this,v.x);
	RotationY(*this,v.y);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→X→Yの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationZXY(const MofFloat x,const MofFloat y,const MofFloat z){
	RotationZ(z);
	RotationX(*this,x);
	RotationY(*this,y);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→Y→Xの順で回転を行う
		@param[in]		v			回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationZYX(const Vector3& v){
	RotationZ(v.z);
	RotationY(*this,v.y);
	RotationX(*this,v.x);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→Y→Xの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationZYX(const MofFloat x,const MofFloat y,const MofFloat z){
	RotationZ(z);
	RotationY(*this,y);
	RotationX(*this,x);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Yの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationXY(const MofFloat x,const MofFloat y) {
	RotationX(x);
	RotationY(*this, y);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Zの順で回転を行う
		@param[in]		x			X回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationXZ(const MofFloat x,const MofFloat z) {
	RotationX(x);
	RotationZ(*this, z);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Yの順で回転を行う
		@param[in]		x			X回転
		@param[in]		y			Y回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationYX(const MofFloat x,const MofFloat y) {
	RotationY(y);
	RotationX(*this, x);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Y→Zの順で回転を行う
		@param[in]		y			Y回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationYZ(const MofFloat y,const MofFloat z) {
	RotationY(y);
	RotationZ(*this, z);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→Xの順で回転を行う
		@param[in]		x			X回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationZX(const MofFloat x,const MofFloat z) {
	RotationZ(z);
	RotationX(*this, x);
	return;
}
/*************************************************************************//*!
		@brief			回転行列計算<br>
						Z→Yの順で回転を行う
		@param[in]		y			Y回転
		@param[in]		z			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationZY(const MofFloat y,const MofFloat z) {
	RotationZ(z);
	RotationY(*this, y);
	return;
}

/*************************************************************************//*!
		@brief			X軸回転行列計算
		@param[in]		ax			X回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationX(const MofFloat ax){
	MofFloat sina = MOF_SIN(ax);
	MofFloat cosa = MOF_COS(ax);
	_12 = _13 = _21 = _31 = 0.0f;
	_11 = 1.0f;
	_23 = sina;
	_32 = -sina;
	_22 = _33 = cosa;
	return;
}
/*************************************************************************//*!
		@brief			Y軸回転行列計算
		@param[in]		ay			Y回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationY(const MofFloat ay){
	MofFloat sina = MOF_SIN(ay);
	MofFloat cosa = MOF_COS(ay);
	_12 = _21 = _23 = _32 = 0.0f;
	_22 = 1.0f;
	_13 = -sina;
	_31 = sina;
	_11 = _33 = cosa;
	return;
}
/*************************************************************************//*!
		@brief			Z軸回転行列計算
		@param[in]		az			Z回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::RotationZ(const MofFloat az){
	MofFloat sina = MOF_SIN(az);
	MofFloat cosa = MOF_COS(az);
	_13 = _23 = _31 = _32 = 0.0f;
	_33 = 1.0f;
	_12 = sina;
	_21 = -sina;
	_11 = _22 = cosa;
	return;
}
/*************************************************************************//*!
		@brief			内部拡大ベクトル取得
		@param[out]		v			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix33::GetScaling(Vector3& v) const{
	v.x = MOF_SQRT(_11 * _11 + _12 * _12 + _13 * _13);
	v.y = MOF_SQRT(_21 * _21 + _22 * _22 + _23 * _23);
	v.z = MOF_SQRT(_31 * _31 + _32 * _32 + _33 * _33);
	return;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CMatrix33& CMatrix33::operator = ( const Matrix33& m ){
	_11 = m._11;	_12 = m._12;	_13 = m._13;
	_21 = m._21;	_22 = m._22;	_23 = m._23;
	_31 = m._31;	_32 = m._32;	_33 = m._33;
	return *this;
}

//[EOF]