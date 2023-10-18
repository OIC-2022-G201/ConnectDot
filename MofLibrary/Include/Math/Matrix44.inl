/*************************************************************************//*!
					
					@file	Matrix44.inl
					@brief	4×4行列演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Matrix44
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Matrix44::Matrix44(){
	_11 = 1;	_12 = 0;	_13 = 0;	_14 = 0;
	_21 = 0;	_22 = 1;	_23 = 0;	_24 = 0;
	_31 = 0;	_32 = 0;	_33 = 1;	_34 = 0;
	_41 = 0;	_42 = 0;	_43 = 0;	_44 = 1;
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
		@param[in]		f44			43成分
		@param[in]		f44			44成分

		@return			None
*//**************************************************************************/
FORCE_INLINE Matrix44::Matrix44(	MofFloat f11 ,MofFloat f12 ,MofFloat f13 ,MofFloat f14,
									MofFloat f21 ,MofFloat f22 ,MofFloat f23 ,MofFloat f24,
									MofFloat f31 ,MofFloat f32 ,MofFloat f33 ,MofFloat f34,
									MofFloat f41 ,MofFloat f42 ,MofFloat f43 ,MofFloat f44 ){
	_11 = f11;	_12 = f12;	_13 = f13;	_14 = f14;
	_21 = f21;	_22 = f22;	_23 = f23;	_24 = f24;
	_31 = f31;	_32 = f32;	_33 = f33;	_34 = f34;
	_41 = f41;	_42 = f42;	_43 = f43;	_44 = f44;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pf			パラメーター（16個以上の配列であること）

		@return			None
*//**************************************************************************/
FORCE_INLINE Matrix44::Matrix44( MofFloat* pf ){
	memcpy(&_11,pf,sizeof(Matrix44));
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー行列

		@return			None
*//**************************************************************************/
FORCE_INLINE Matrix44::Matrix44( const Matrix33& pObj ){
	_11 = pObj._11;	_12 = pObj._12;	_13 = pObj._13;	_14 = 0.0f;
	_21 = pObj._21;	_22 = pObj._22;	_23 = pObj._23;	_24 = 0.0f;
	_31 = pObj._31;	_32 = pObj._32;	_33 = pObj._33;	_34 = 0.0f;
	_41 = 0.0f;		_42 = 0.0f;		_43 = 0.0f;		_44 = 1.0f;
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー行列

		@return			None
*//**************************************************************************/
FORCE_INLINE Matrix44::Matrix44( const Matrix44& pObj ){
	_11 = pObj._11;	_12 = pObj._12;	_13 = pObj._13;	_14 = pObj._14;
	_21 = pObj._21;	_22 = pObj._22;	_23 = pObj._23;	_24 = pObj._24;
	_31 = pObj._31;	_32 = pObj._32;	_33 = pObj._33;	_34 = pObj._34;
	_41 = pObj._41;	_42 = pObj._42;	_43 = pObj._43;	_44 = pObj._44;
}
/*************************************************************************//*!
		@brief			floatキャスト<br>
						内部の座標をfloatポインタとしてそのまま返す。
*//**************************************************************************/
FORCE_INLINE Matrix44::operator MofFloat * (){
	return (MofFloat*)&_11;
}
/*************************************************************************//*!
		@brief			+取得
*//**************************************************************************/
FORCE_INLINE Matrix44 Matrix44::operator + () const{
	return Matrix44((MofFloat*)&_11);
}
/*************************************************************************//*!
		@brief			-取得
*//**************************************************************************/
FORCE_INLINE Matrix44 Matrix44::operator - () const{
	return Matrix44(	-_11,-_12,-_13,-_14,
						-_21,-_22,-_23,-_24,
						-_31,-_32,-_33,-_34,
						-_41,-_42,-_43,-_44);
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE Matrix44& Matrix44::operator = ( const Matrix33& m ){
	_11 = m._11;	_12 = m._12;	_13 = m._13;
	_21 = m._21;	_22 = m._22;	_23 = m._23;
	_31 = m._31;	_32 = m._32;	_33 = m._33;
	return *this;
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Matrix44& Matrix44::operator += (const Matrix44 &m){
	_11 += m._11; _12 += m._12; _13 += m._13; _14 += m._14;
	_21 += m._21; _22 += m._22; _23 += m._23; _24 += m._24;
	_31 += m._31; _32 += m._32; _33 += m._33; _34 += m._34;
	_41 += m._41; _42 += m._42; _43 += m._43; _44 += m._44;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Matrix44& Matrix44::operator -= (const Matrix44 &m){
	_11 -= m._11; _12 -= m._12; _13 -= m._13; _14 -= m._14;
	_21 -= m._21; _22 -= m._22; _23 -= m._23; _24 -= m._24;
	_31 -= m._31; _32 -= m._32; _33 -= m._33; _34 -= m._34;
	_41 -= m._41; _42 -= m._42; _43 -= m._43; _44 -= m._44;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの*=演算
*//**************************************************************************/
FORCE_INLINE Matrix44& Matrix44::operator *= (const MofFloat m){
	_11 *= m; _12 *= m; _13 *= m; _14 *= m;
	_21 *= m; _22 *= m; _23 *= m; _24 *= m;
	_31 *= m; _32 *= m; _33 *= m; _34 *= m;
	_41 *= m; _42 *= m; _43 *= m; _44 *= m;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの/=演算
*//**************************************************************************/
FORCE_INLINE Matrix44& Matrix44::operator /= (const MofFloat m){
	_11 /= m; _12 /= m; _13 /= m; _14 /= m;
	_21 /= m; _22 /= m; _23 /= m; _24 /= m;
	_31 /= m; _32 /= m; _33 /= m; _34 /= m;
	_41 /= m; _42 /= m; _43 /= m; _44 /= m;
	return *this;
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Matrix44 Matrix44::operator + (const Matrix44& m) const{
	return Matrix44(	_11 + m._11,_12 + m._12,_13 + m._13,_14 + m._14,
						_21 + m._21,_22 + m._22,_23 + m._23,_24 + m._24,
						_31 + m._31,_32 + m._32,_33 + m._33,_34 + m._34,
						_41 + m._41,_42 + m._42,_43 + m._43,_44 + m._44);
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Matrix44 Matrix44::operator - (const Matrix44& m) const{
	return Matrix44(	_11 - m._11,_12 - m._12,_13 - m._13,_14 - m._14,
						_21 - m._21,_22 - m._22,_23 - m._23,_24 - m._24,
						_31 - m._31,_32 - m._32,_33 - m._33,_34 - m._34,
						_41 - m._41,_42 - m._42,_43 - m._43,_44 - m._44);
}
/*************************************************************************//*!
		@brief			floatとの*演算
*//**************************************************************************/
FORCE_INLINE Matrix44 Matrix44::operator * (const MofFloat m) const{
	return Matrix44(	_11 * m,_12 * m,_13 * m,_14 * m,
						_21 * m,_22 * m,_23 * m,_24 * m,
						_31 * m,_32 * m,_33 * m,_34 * m,
						_41 * m,_42 * m,_43 * m,_44 * m);
}
/*************************************************************************//*!
		@brief			floatとの/演算
*//**************************************************************************/
FORCE_INLINE Matrix44 Matrix44::operator / (const MofFloat m) const{
	return Matrix44(	_11 / m,_12 / m,_13 / m,_14 / m,
						_21 / m,_22 / m,_23 / m,_24 / m,
						_31 / m,_32 / m,_33 / m,_34 / m,
						_41 / m,_42 / m,_43 / m,_44 / m);
}
/*************************************************************************//*!
		@brief			配列指定によるMatrix44メンバへのアクセス
*//**************************************************************************/
FORCE_INLINE MofFloat& Matrix44::operator [] ( int i ){
	return val[i];
}
/*************************************************************************//*!
		@brief			配列指定によるMatrix44メンバへのアクセス
*//**************************************************************************/
FORCE_INLINE const MofFloat& Matrix44::operator [] ( int i ) const{
	return val[i];
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool Matrix44::operator == (const Matrix44& m) const{
	return 0 == memcmp(val, &m.val, sizeof(MofFloat) * 16);
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool Matrix44::operator != (const Matrix44& m) const{
	return 0 != memcmp(val, &m.val, sizeof(MofFloat) * 16);
}

//--------------------------------------------------------------------------------------------
//CMatrix44Utilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			単位行列設定
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Identity(Matrix44& OutMat){
	OutMat._11 = 1;	OutMat._12 = 0;	OutMat._13 = 0;	OutMat._14 = 0;
	OutMat._21 = 0;	OutMat._22 = 1;	OutMat._23 = 0;	OutMat._24 = 0;
	OutMat._31 = 0;	OutMat._32 = 0;	OutMat._33 = 1;	OutMat._34 = 0;
	OutMat._41 = 0;	OutMat._42 = 0;	OutMat._43 = 0;	OutMat._44 = 1;
}
/*************************************************************************//*!
		@brief			転置行列設定<br>
						入力行列と出力行列に同じ参照を設定する場合、引数が一つの方を利用すること
		@param[in]		InMat		入力行列
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Transpose(const Matrix44& InMat,Matrix44& OutMat){
	MofFloat _12 = InMat._12; MofFloat _13 = InMat._13; MofFloat _14 = InMat._14;
	MofFloat _21 = InMat._21; MofFloat _23 = InMat._23; MofFloat _24 = InMat._24;
	MofFloat _31 = InMat._31; MofFloat _32 = InMat._32; MofFloat _34 = InMat._34;
	MofFloat _41 = InMat._41; MofFloat _42 = InMat._42; MofFloat _43 = InMat._43;

	OutMat._11 = InMat._11;
	OutMat._22 = InMat._22;
	OutMat._33 = InMat._33;
	OutMat._44 = InMat._44;
	OutMat._12 = _21; OutMat._13 = _31; OutMat._14 = _41;
	OutMat._21 = _12; OutMat._23 = _32; OutMat._24 = _42;
	OutMat._31 = _13; OutMat._32 = _23; OutMat._34 = _43;
	OutMat._41 = _14; OutMat._42 = _24; OutMat._43 = _34;
}
/*************************************************************************//*!
		@brief			転置行列設定
		@param[in,out]	OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Transpose(Matrix44& OutMat){
	MofFloat _12 = OutMat._12; MofFloat _13 = OutMat._13; MofFloat _14 = OutMat._14;
	MofFloat _21 = OutMat._21; MofFloat _23 = OutMat._23; MofFloat _24 = OutMat._24;
	MofFloat _31 = OutMat._31; MofFloat _32 = OutMat._32; MofFloat _34 = OutMat._34;
	MofFloat _41 = OutMat._41; MofFloat _42 = OutMat._42; MofFloat _43 = OutMat._43;

	OutMat._12 = _21; OutMat._13 = _31; OutMat._14 = _41;
	OutMat._21 = _12; OutMat._23 = _32; OutMat._24 = _42;
	OutMat._31 = _13; OutMat._32 = _23; OutMat._34 = _43;
	OutMat._41 = _14; OutMat._42 = _24; OutMat._43 = _34;
}
/*************************************************************************//*!
		@brief			平行移動行列計算
		@param[in]		Pos			座標
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Translation(const Vector3& v,Matrix44& OutMat){
	OutMat._11 = OutMat._12 = OutMat._13 =
	OutMat._21 = OutMat._22 = OutMat._23 =
	OutMat._31 = OutMat._32 = OutMat._33 = 0.0f;
	OutMat._11 = OutMat._22 = OutMat._33 = OutMat._44 = 1.0f;
	OutMat._41 = v.x; OutMat._42 = v.y; OutMat._43 = v.z;
	return;
}
/*************************************************************************//*!
		@brief			平行移動行列計算
		@param[in]		x			X座標
		@param[in]		y			Y座標
		@param[in]		z			Z座標
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Translation(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
	OutMat._11 = OutMat._12 = OutMat._13 =
	OutMat._21 = OutMat._22 = OutMat._23 =
	OutMat._31 = OutMat._32 = OutMat._33 = 0.0f;
	OutMat._11 = OutMat._22 = OutMat._33 = OutMat._44 = 1.0f;
	OutMat._41 = x; OutMat._42 = y; OutMat._43 = z;
	return;
}
/*************************************************************************//*!
		@brief			平行移動行列計算<br>
						元行列 × 平行移動行列の結果を結果行列に設定する。
		@param[in]		InMat		元行列
		@param[in]		v			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Translation(const Matrix44& InMat,const Vector3& v,Matrix44& OutMat){
	OutMat._11 = InMat._11 + InMat._14 * v.x;	OutMat._12 = InMat._12 + InMat._14 * v.y;	OutMat._13 = InMat._13 + InMat._14 * v.z;	OutMat._14 = InMat._14;
	OutMat._21 = InMat._21 + InMat._24 * v.x;	OutMat._22 = InMat._22 + InMat._24 * v.y;	OutMat._23 = InMat._23 + InMat._24 * v.z;	OutMat._24 = InMat._24;
	OutMat._31 = InMat._31 + InMat._34 * v.x;	OutMat._32 = InMat._32 + InMat._34 * v.y;	OutMat._33 = InMat._33 + InMat._34 * v.z;	OutMat._34 = InMat._34;
	OutMat._41 = InMat._41 + InMat._44 * v.x;	OutMat._42 = InMat._42 + InMat._44 * v.y;	OutMat._43 = InMat._43 + InMat._44 * v.z;	OutMat._44 = InMat._44;
	return;
}
/*************************************************************************//*!
		@brief			平行移動行列計算<br>
						元行列 × 平行移動行列の結果を結果行列に設定する。
		@param[in]		InMat		元行列
		@param[in]		x			X座標
		@param[in]		y			Y座標
		@param[in]		z			Z座標

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Translation(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
	OutMat._11 = InMat._11 + InMat._14 * x;		OutMat._12 = InMat._12 + InMat._14 * y;		OutMat._13 = InMat._13 + InMat._14 * z;		OutMat._14 = InMat._14;
	OutMat._21 = InMat._21 + InMat._24 * x;		OutMat._22 = InMat._22 + InMat._24 * y;		OutMat._23 = InMat._23 + InMat._24 * z;		OutMat._24 = InMat._24;
	OutMat._31 = InMat._31 + InMat._34 * x;		OutMat._32 = InMat._32 + InMat._34 * y;		OutMat._33 = InMat._33 + InMat._34 * z;		OutMat._34 = InMat._34;
	OutMat._41 = InMat._41 + InMat._44 * x;		OutMat._42 = InMat._42 + InMat._44 * y;		OutMat._43 = InMat._43 + InMat._44 * z;		OutMat._44 = InMat._44;
	return;
}
		
/*************************************************************************//*!
		@brief			平行移動行列計算<br>
						平行移動行列 × 元行列の結果を結果行列に設定する。
		@param[in]		v			座標
		@param[in]		InMat		元行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Translation(const Vector3& v,const Matrix44& InMat,Matrix44& OutMat){
	OutMat._11 = InMat._11;	OutMat._12 = InMat._12;	OutMat._13 = InMat._13;	OutMat._14 = InMat._14;
	OutMat._21 = InMat._21;	OutMat._22 = InMat._22;	OutMat._23 = InMat._23;	OutMat._24 = InMat._24;
	OutMat._31 = InMat._31;	OutMat._32 = InMat._32;	OutMat._33 = InMat._33;	OutMat._34 = InMat._34;
	OutMat._41 = InMat._41 + v.x * InMat._11 + v.y * InMat._21 + v.z * InMat._31;
	OutMat._42 = InMat._42 + v.x * InMat._12 + v.y * InMat._22 + v.z * InMat._32;
	OutMat._43 = InMat._43 + v.x * InMat._13 + v.y * InMat._23 + v.z * InMat._33;
	OutMat._44 = InMat._44 + v.x * InMat._14 + v.y * InMat._24 + v.z * InMat._34;
	return;
}
/*************************************************************************//*!
		@brief			平行移動行列計算<br>
						平行移動行列 × 元行列の結果を結果行列に設定する。
		@param[in]		x			X座標
		@param[in]		y			Y座標
		@param[in]		z			Z座標
		@param[in]		InMat		元行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Translation(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat,Matrix44& OutMat){
	OutMat._11 = InMat._11;	OutMat._12 = InMat._12;	OutMat._13 = InMat._13;	OutMat._14 = InMat._14;
	OutMat._21 = InMat._21;	OutMat._22 = InMat._22;	OutMat._23 = InMat._23;	OutMat._24 = InMat._24;
	OutMat._31 = InMat._31;	OutMat._32 = InMat._32;	OutMat._33 = InMat._33;	OutMat._34 = InMat._34;
	OutMat._41 = InMat._41 + x * InMat._11 + y * InMat._21 + z * InMat._31;
	OutMat._42 = InMat._42 + x * InMat._12 + y * InMat._22 + z * InMat._32;
	OutMat._43 = InMat._43 + x * InMat._13 + y * InMat._23 + z * InMat._33;
	OutMat._44 = InMat._44 + x * InMat._14 + y * InMat._24 + z * InMat._34;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		v			倍率
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Scaling(const Vector3& v,Matrix44& OutMat){
	OutMat._12 = OutMat._13 = OutMat._14 =
	OutMat._21 = OutMat._23 = OutMat._24 =
	OutMat._31 = OutMat._32 = OutMat._34 =
	OutMat._41 = OutMat._42 = OutMat._43 = 0.0f;
	OutMat._11 = v.x; OutMat._22 = v.y; OutMat._33 = v.z; OutMat._44 = 1.0f;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		s			倍率
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::Scaling(const MofFloat s,Matrix44& OutMat){
	OutMat._12 = OutMat._13 = OutMat._14 =
	OutMat._21 = OutMat._23 = OutMat._24 =
	OutMat._31 = OutMat._32 = OutMat._34 =
	OutMat._41 = OutMat._42 = OutMat._43 = 0.0f;
	OutMat._11 = OutMat._22 = OutMat._33 = s; OutMat._44 = 1.0f;
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
FORCE_INLINE void CMatrix44Utilities::Scaling(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
	OutMat._12 = OutMat._13 = OutMat._14 =
	OutMat._21 = OutMat._23 = OutMat._24 =
	OutMat._31 = OutMat._32 = OutMat._34 =
	OutMat._41 = OutMat._42 = OutMat._43 = 0.0f;
	OutMat._11 = x; OutMat._22 = y; OutMat._33 = z; OutMat._44 = 1.0f;
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
FORCE_INLINE void CMatrix44Utilities::Scaling(const Matrix44& InMat,const Vector3& v,Matrix44& OutMat){
	OutMat._11 = InMat._11 * v.x;	OutMat._12 = InMat._12 * v.y;	OutMat._13 = InMat._13 * v.z;	OutMat._14 = InMat._14;
	OutMat._21 = InMat._21 * v.x;	OutMat._22 = InMat._22 * v.y;	OutMat._23 = InMat._23 * v.z;	OutMat._24 = InMat._24;
	OutMat._31 = InMat._31 * v.x;	OutMat._32 = InMat._32 * v.y;	OutMat._33 = InMat._33 * v.z;	OutMat._34 = InMat._34;
	OutMat._41 = InMat._41 * v.x;	OutMat._42 = InMat._42 * v.y;	OutMat._43 = InMat._43 * v.z;	OutMat._44 = InMat._44;
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
FORCE_INLINE void CMatrix44Utilities::Scaling(const Matrix44& InMat,const MofFloat s,Matrix44& OutMat){
	OutMat._11 = InMat._11 * s;		OutMat._12 = InMat._12 * s;		OutMat._13 = InMat._13 * s;		OutMat._14 = InMat._14;
	OutMat._21 = InMat._21 * s;		OutMat._22 = InMat._22 * s;		OutMat._23 = InMat._23 * s;		OutMat._24 = InMat._24;
	OutMat._31 = InMat._31 * s;		OutMat._32 = InMat._32 * s;		OutMat._33 = InMat._33 * s;		OutMat._34 = InMat._34;
	OutMat._41 = InMat._41 * s;		OutMat._42 = InMat._42 * s;		OutMat._43 = InMat._43 * s;		OutMat._44 = InMat._44;
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
FORCE_INLINE void CMatrix44Utilities::Scaling(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
	OutMat._11 = InMat._11 * x;		OutMat._12 = InMat._12 * y;		OutMat._13 = InMat._13 * z;		OutMat._14 = InMat._14;
	OutMat._21 = InMat._21 * x;		OutMat._22 = InMat._22 * y;		OutMat._23 = InMat._23 * z;		OutMat._24 = InMat._24;
	OutMat._31 = InMat._31 * x;		OutMat._32 = InMat._32 * y;		OutMat._33 = InMat._33 * z;		OutMat._34 = InMat._34;
	OutMat._41 = InMat._41 * x;		OutMat._42 = InMat._42 * y;		OutMat._43 = InMat._43 * z;		OutMat._44 = InMat._44;
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
FORCE_INLINE void CMatrix44Utilities::Scaling(const Vector3& v,const Matrix44& InMat,Matrix44& OutMat){
	OutMat._11 = InMat._11 * v.x;	OutMat._12 = InMat._12 * v.x;	OutMat._13 = InMat._13 * v.x;	OutMat._14 = InMat._14 * v.x;
	OutMat._21 = InMat._21 * v.y;	OutMat._22 = InMat._22 * v.y;	OutMat._23 = InMat._23 * v.y;	OutMat._24 = InMat._24 * v.y;
	OutMat._31 = InMat._31 * v.z;	OutMat._32 = InMat._32 * v.z;	OutMat._33 = InMat._33 * v.z;	OutMat._34 = InMat._34 * v.z;
	OutMat._41 = InMat._41;			OutMat._42 = InMat._42;			OutMat._43 = InMat._43;			OutMat._44 = InMat._44;
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
FORCE_INLINE void CMatrix44Utilities::Scaling(const MofFloat s,const Matrix44& InMat,Matrix44& OutMat){
	OutMat._11 = InMat._11 * s;		OutMat._12 = InMat._12 * s;		OutMat._13 = InMat._13 * s;		OutMat._14 = InMat._14 * s;
	OutMat._21 = InMat._21 * s;		OutMat._22 = InMat._22 * s;		OutMat._23 = InMat._23 * s;		OutMat._24 = InMat._24 * s;
	OutMat._31 = InMat._31 * s;		OutMat._32 = InMat._32 * s;		OutMat._33 = InMat._33 * s;		OutMat._34 = InMat._34 * s;
	OutMat._41 = InMat._41;			OutMat._42 = InMat._42;			OutMat._43 = InMat._43;			OutMat._44 = InMat._44;
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
FORCE_INLINE void CMatrix44Utilities::Scaling(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat,Matrix44& OutMat){
	OutMat._11 = InMat._11 * x;		OutMat._12 = InMat._12 * x;		OutMat._13 = InMat._13 * x;		OutMat._14 = InMat._14 * x;
	OutMat._21 = InMat._21 * y;		OutMat._22 = InMat._22 * y;		OutMat._23 = InMat._23 * y;		OutMat._24 = InMat._24 * y;
	OutMat._31 = InMat._31 * z;		OutMat._32 = InMat._32 * z;		OutMat._33 = InMat._33 * z;		OutMat._34 = InMat._34 * z;
	OutMat._41 = InMat._41;			OutMat._42 = InMat._42;			OutMat._43 = InMat._43;			OutMat._44 = InMat._44;
	return;
}

/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Y→Zの順で回転を行う
		@param[in]		v			回転
		@param[out]		OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::RotationXYZ(const Vector3& v,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationXYZ(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationXZY(const Vector3& v,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationXZY(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationYXZ(const Vector3& v,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationYXZ(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationYZX(const Vector3& v,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationYZX(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationZXY(const Vector3& v,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationZXY(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationZYX(const Vector3& v,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationZYX(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
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
FORCE_INLINE void CMatrix44Utilities::RotationX(const MofFloat ax,Matrix44& OutMat){
	MofFloat sina = MOF_SIN(ax);
	MofFloat cosa = MOF_COS(ax);
	OutMat._12 = OutMat._13 = OutMat._14 =
	OutMat._21 = OutMat._24 =
	OutMat._31 = OutMat._34 =
	OutMat._41 = OutMat._42 = OutMat._43 = 0.0f;
	OutMat._11 = OutMat._44 = 1.0f;
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
FORCE_INLINE void CMatrix44Utilities::RotationY(const MofFloat ay,Matrix44& OutMat){
	MofFloat sina = MOF_SIN(ay);
	MofFloat cosa = MOF_COS(ay);
	OutMat._12 = OutMat._14 =
	OutMat._21 = OutMat._23 = OutMat._24 =
	OutMat._32 = OutMat._34 =
	OutMat._41 = OutMat._42 = OutMat._43 = 0.0f;
	OutMat._22 = OutMat._44 = 1.0f;
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
FORCE_INLINE void CMatrix44Utilities::RotationZ(const MofFloat az,Matrix44& OutMat){
	MofFloat sina = MOF_SIN(az);
	MofFloat cosa = MOF_COS(az);
	OutMat._13 = OutMat._14 =
	OutMat._23 = OutMat._24 =
	OutMat._31 = OutMat._32 = OutMat._34 =
	OutMat._41 = OutMat._42 = OutMat._43 = 0.0f;
	OutMat._33 = OutMat._44 = 1.0f;
	OutMat._12 = sina;
	OutMat._21 = -sina;
	OutMat._11 = OutMat._22 = cosa;
	return;
}
/*************************************************************************//*!
		@brief			結果行列の平行移動ベクトル設定
		@param[in]		v			平行移動
		@param[in,out]	OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::SetTranslation(const Vector3& v,Matrix44& OutMat){
	OutMat._41 = v.x;
	OutMat._42 = v.y;
	OutMat._43 = v.z;
	return;
}
/*************************************************************************//*!
		@brief			結果行列の平行移動ベクトル設定
		@param[in]		x			X座標
		@param[in]		y			Y座標
		@param[in]		z			Z座標
		@param[in,out]	OutMat		結果行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::SetTranslation(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat){
	OutMat._41 = x;
	OutMat._42 = y;
	OutMat._43 = z;
	return;
}
/*************************************************************************//*!
		@brief			元行列の平行移動ベクトル取得
		@param[in]		InMat		元行列
		@param[out]		v			平行移動

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::GetTranslation(const Matrix44& InMat,Vector3& v){
	v.x = InMat._41;
	v.y = InMat._42;
	v.z = InMat._43;
	return;
}
/*************************************************************************//*!
		@brief			元行列の拡大ベクトル取得
		@param[in]		InMat		元行列
		@param[out]		v			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44Utilities::GetScaling(const Matrix44& InMat,Vector3& v){
	v.x = MOF_SQRT(InMat._11 * InMat._11 + InMat._12 * InMat._12 + InMat._13 * InMat._13);
	v.y = MOF_SQRT(InMat._21 * InMat._21 + InMat._22 * InMat._22 + InMat._23 * InMat._23);
	v.z = MOF_SQRT(InMat._31 * InMat._31 + InMat._32 * InMat._32 + InMat._33 * InMat._33);
	return;
}

//--------------------------------------------------------------------------------------------
//CMatrix44
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix44::CMatrix44() :
Matrix44() {
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
FORCE_INLINE CMatrix44::CMatrix44(	MofFloat f11 ,MofFloat f12 ,MofFloat f13 ,MofFloat f14,
									MofFloat f21 ,MofFloat f22 ,MofFloat f23 ,MofFloat f24,
									MofFloat f31 ,MofFloat f32 ,MofFloat f33 ,MofFloat f34,
									MofFloat f41 ,MofFloat f42 ,MofFloat f43 ,MofFloat f44 ){
	_11 = f11;	_12 = f12;	_13 = f13;	_14 = f14;
	_21 = f21;	_22 = f22;	_23 = f23;	_24 = f24;
	_31 = f31;	_32 = f32;	_33 = f33;	_34 = f34;
	_41 = f41;	_42 = f42;	_43 = f43;	_44 = f44;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pf			パラメーター（16個以上の配列であること）

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix44::CMatrix44( MofFloat* pf ) :
Matrix44(pf) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー行列

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix44::CMatrix44( const Matrix33& pObj ) :
Matrix44(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー行列

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix44::CMatrix44( const CMatrix33& pObj ) :
Matrix44(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー行列

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix44::CMatrix44( const Matrix44& pObj ) :
Matrix44(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー行列

		@return			None
*//**************************************************************************/
FORCE_INLINE CMatrix44::CMatrix44( const CMatrix44& pObj ) :
Matrix44(pObj) {
}
/*************************************************************************//*!
		@brief			単位行列設定
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Identity(void){
	_11 = 1;	_12 = 0;	_13 = 0;	_14 = 0;
	_21 = 0;	_22 = 1;	_23 = 0;	_24 = 0;
	_31 = 0;	_32 = 0;	_33 = 1;	_34 = 0;
	_41 = 0;	_42 = 0;	_43 = 0;	_44 = 1;
}
/*************************************************************************//*!
		@brief			転置行列設定
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Transpose(void){
	MofFloat M12 = _12; MofFloat M13 = _13; MofFloat M14 = _14;
	MofFloat M21 = _21; MofFloat M23 = _23; MofFloat M24 = _24;
	MofFloat M31 = _31; MofFloat M32 = _32; MofFloat M34 = _34;
	MofFloat M41 = _41; MofFloat M42 = _42; MofFloat M43 = _43;

	_12 = M21; _13 = M31; _14 = M41;
	_21 = M12; _23 = M32; _24 = M42;
	_31 = M13; _32 = M23; _34 = M43;
	_41 = M14; _42 = M24; _43 = M34;
}
/*************************************************************************//*!
		@brief			平行移動行列計算
		@param[in]		Pos			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Translation(const Vector3& v){
	_11 = _12 = _13 =
	_21 = _22 = _23 =
	_31 = _32 = _33 = 0.0f;
	_11 = _22 = _33 = _44 = 1.0f;
	_41 = v.x; _42 = v.y; _43 = v.z;
	return;
}
/*************************************************************************//*!
		@brief			平行移動行列計算
		@param[in]		x			X座標
		@param[in]		y			Y座標
		@param[in]		z			Z座標

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Translation(const MofFloat x,const MofFloat y,const MofFloat z){
	_11 = _12 = _13 =
	_21 = _22 = _23 =
	_31 = _32 = _33 = 0.0f;
	_11 = _22 = _33 = _44 = 1.0f;
	_41 = x; _42 = y; _43 = z;
	return;
}
/*************************************************************************//*!
		@brief			平行移動行列計算<br>
						元行列 × 平行移動行列の結果を自身に設定する。
		@param[in]		InMat		元行列
		@param[in]		v			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Translation(const Matrix44& InMat,const Vector3& v){
	_11 = InMat._11 + InMat._14 * v.x;	_12 = InMat._12 + InMat._14 * v.y;	_13 = InMat._13 + InMat._14 * v.z;	_14 = InMat._14;
	_21 = InMat._21 + InMat._24 * v.x;	_22 = InMat._22 + InMat._24 * v.y;	_23 = InMat._23 + InMat._24 * v.z;	_24 = InMat._24;
	_31 = InMat._31 + InMat._34 * v.x;	_32 = InMat._32 + InMat._34 * v.y;	_33 = InMat._33 + InMat._34 * v.z;	_34 = InMat._34;
	_41 = InMat._41 + InMat._44 * v.x;	_42 = InMat._42 + InMat._44 * v.y;	_43 = InMat._43 + InMat._44 * v.z;	_44 = InMat._44;
	return;
}
/*************************************************************************//*!
		@brief			平行移動行列計算<br>
						元行列 × 平行移動行列の結果を自身に設定する。
		@param[in]		InMat		元行列
		@param[in]		x			X座標
		@param[in]		y			Y座標
		@param[in]		z			Z座標

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Translation(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z){
	_11 = InMat._11 + InMat._14 * x;	_12 = InMat._12 + InMat._14 * y;	_13 = InMat._13 + InMat._14 * z;	_14 = InMat._14;
	_21 = InMat._21 + InMat._24 * x;	_22 = InMat._22 + InMat._24 * y;	_23 = InMat._23 + InMat._24 * z;	_24 = InMat._24;
	_31 = InMat._31 + InMat._34 * x;	_32 = InMat._32 + InMat._34 * y;	_33 = InMat._33 + InMat._34 * z;	_34 = InMat._34;
	_41 = InMat._41 + InMat._44 * x;	_42 = InMat._42 + InMat._44 * y;	_43 = InMat._43 + InMat._44 * z;	_44 = InMat._44;
	return;
}
		
/*************************************************************************//*!
		@brief			平行移動行列計算<br>
						平行移動行列 × 元行列の結果を自身に設定する。
		@param[in]		v			座標
		@param[in]		InMat		元行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Translation(const Vector3& v,const Matrix44& InMat){
	_11 = InMat._11;	_12 = InMat._12;	_13 = InMat._13;	_14 = InMat._14;
	_21 = InMat._21;	_22 = InMat._22;	_23 = InMat._23;	_24 = InMat._24;
	_31 = InMat._31;	_32 = InMat._32;	_33 = InMat._33;	_34 = InMat._34;
	_41 = InMat._41 + v.x * InMat._11 + v.y * InMat._21 + v.z * InMat._31;
	_42 = InMat._42 + v.x * InMat._12 + v.y * InMat._22 + v.z * InMat._32;
	_43 = InMat._43 + v.x * InMat._13 + v.y * InMat._23 + v.z * InMat._33;
	_44 = InMat._44 + v.x * InMat._14 + v.y * InMat._24 + v.z * InMat._34;
	return;
}
/*************************************************************************//*!
		@brief			平行移動行列計算<br>
						平行移動行列 × 元行列の結果を自身に設定する。
		@param[in]		x			X座標
		@param[in]		y			Y座標
		@param[in]		z			Z座標
		@param[in]		InMat		元行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Translation(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat){
	_11 = InMat._11;	_12 = InMat._12;	_13 = InMat._13;	_14 = InMat._14;
	_21 = InMat._21;	_22 = InMat._22;	_23 = InMat._23;	_24 = InMat._24;
	_31 = InMat._31;	_32 = InMat._32;	_33 = InMat._33;	_34 = InMat._34;
	_41 = InMat._41 + x * InMat._11 + y * InMat._21 + z * InMat._31;
	_42 = InMat._42 + x * InMat._12 + y * InMat._22 + z * InMat._32;
	_43 = InMat._43 + x * InMat._13 + y * InMat._23 + z * InMat._33;
	_44 = InMat._44 + x * InMat._14 + y * InMat._24 + z * InMat._34;
	return;
}

/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		v			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Scaling(const Vector3& v){
	_12 = _13 = _14 =
	_21 = _23 = _24 =
	_31 = _32 = _34 =
	_41 = _42 = _43 = 0.0f;
	_11 = v.x; _22 = v.y; _33 = v.z; _44 = 1.0f;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		s			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Scaling(const MofFloat s){
	_12 = _13 = _14 =
	_21 = _23 = _24 =
	_31 = _32 = _34 =
	_41 = _42 = _43 = 0.0f;
	_11 = _22 = _33 = s; _44 = 1.0f;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算
		@param[in]		x			X倍率
		@param[in]		y			Y倍率
		@param[in]		z			Z倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Scaling(const MofFloat x,const MofFloat y,const MofFloat z){
	_12 = _13 = _14 =
	_21 = _23 = _24 =
	_31 = _32 = _34 =
	_41 = _42 = _43 = 0.0f;
	_11 = x; _22 = y; _33 = z; _44 = 1.0f;
	return;
}
		
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						元行列 × 拡大行列の結果を自身に設定する。
		@param[in]		InMat		元行列
		@param[in]		v			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Scaling(const Matrix44& InMat,const Vector3& v){
	_11 = InMat._11 * v.x;	_12 = InMat._12 * v.y;	_13 = InMat._13 * v.z;	_14 = InMat._14;
	_21 = InMat._21 * v.x;	_22 = InMat._22 * v.y;	_23 = InMat._23 * v.z;	_24 = InMat._24;
	_31 = InMat._31 * v.x;	_32 = InMat._32 * v.y;	_33 = InMat._33 * v.z;	_34 = InMat._34;
	_41 = InMat._41 * v.x;	_42 = InMat._42 * v.y;	_43 = InMat._43 * v.z;	_44 = InMat._44;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						元行列 × 拡大行列の結果を自身に設定する。
		@param[in]		InMat		元行列
		@param[in]		s			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Scaling(const Matrix44& InMat,const MofFloat s){
	_11 = InMat._11 * s;	_12 = InMat._12 * s;	_13 = InMat._13 * s;	_14 = InMat._14;
	_21 = InMat._21 * s;	_22 = InMat._22 * s;	_23 = InMat._23 * s;	_24 = InMat._24;
	_31 = InMat._31 * s;	_32 = InMat._32 * s;	_33 = InMat._33 * s;	_34 = InMat._34;
	_41 = InMat._41 * s;	_42 = InMat._42 * s;	_43 = InMat._43 * s;	_44 = InMat._44;
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
FORCE_INLINE void CMatrix44::Scaling(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z){
	_11 = InMat._11 * x;	_12 = InMat._12 * y;	_13 = InMat._13 * z;	_14 = InMat._14;
	_21 = InMat._21 * x;	_22 = InMat._22 * y;	_23 = InMat._23 * z;	_24 = InMat._24;
	_31 = InMat._31 * x;	_32 = InMat._32 * y;	_33 = InMat._33 * z;	_34 = InMat._34;
	_41 = InMat._41 * x;	_42 = InMat._42 * y;	_43 = InMat._43 * z;	_44 = InMat._44;
	return;
}

/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						拡大行列 × 元行列の結果を自身に設定する。
		@param[in]		v			倍率
		@param[in]		InMat		元行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Scaling(const Vector3& v,const Matrix44& InMat){
	_11 = InMat._11 * v.x;	_12 = InMat._12 * v.x;	_13 = InMat._13 * v.x;	_14 = InMat._14 * v.x;
	_21 = InMat._21 * v.y;	_22 = InMat._22 * v.y;	_23 = InMat._23 * v.y;	_24 = InMat._24 * v.y;
	_31 = InMat._31 * v.z;	_32 = InMat._32 * v.z;	_33 = InMat._33 * v.z;	_34 = InMat._34 * v.z;
	_41 = InMat._41;		_42 = InMat._42;		_43 = InMat._43;		_44 = InMat._44;
	return;
}
/*************************************************************************//*!
		@brief			スケーリング行列計算<br>
						拡大行列 × 元行列の結果を自身に設定する。
		@param[in]		s			倍率
		@param[in]		InMat		元行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::Scaling(const MofFloat s,const Matrix44& InMat){
	_11 = InMat._11 * s;	_12 = InMat._12 * s;	_13 = InMat._13 * s;	_14 = InMat._14 * s;
	_21 = InMat._21 * s;	_22 = InMat._22 * s;	_23 = InMat._23 * s;	_24 = InMat._24 * s;
	_31 = InMat._31 * s;	_32 = InMat._32 * s;	_33 = InMat._33 * s;	_34 = InMat._34 * s;
	_41 = InMat._41;		_42 = InMat._42;		_43 = InMat._43;		_44 = InMat._44;
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
FORCE_INLINE void CMatrix44::Scaling(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat){
	_11 = InMat._11 * x;	_12 = InMat._12 * x;	_13 = InMat._13 * x;	_14 = InMat._14 * x;
	_21 = InMat._21 * y;	_22 = InMat._22 * y;	_23 = InMat._23 * y;	_24 = InMat._24 * y;
	_31 = InMat._31 * z;	_32 = InMat._32 * z;	_33 = InMat._33 * z;	_34 = InMat._34 * z;
	_41 = InMat._41;		_42 = InMat._42;		_43 = InMat._43;		_44 = InMat._44;
	return;
}

/*************************************************************************//*!
		@brief			回転行列計算<br>
						X→Y→Zの順で回転を行う
		@param[in]		v			回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::RotationXYZ(const Vector3& v){
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
FORCE_INLINE void CMatrix44::RotationXYZ(const MofFloat x,const MofFloat y,const MofFloat z){
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
FORCE_INLINE void CMatrix44::RotationXZY(const Vector3& v){
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
FORCE_INLINE void CMatrix44::RotationXZY(const MofFloat x,const MofFloat y,const MofFloat z){
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
FORCE_INLINE void CMatrix44::RotationYXZ(const Vector3& v){
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
FORCE_INLINE void CMatrix44::RotationYXZ(const MofFloat x,const MofFloat y,const MofFloat z){
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
FORCE_INLINE void CMatrix44::RotationYZX(const Vector3& v){
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
FORCE_INLINE void CMatrix44::RotationYZX(const MofFloat x,const MofFloat y,const MofFloat z){
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
FORCE_INLINE void CMatrix44::RotationZXY(const Vector3& v){
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
FORCE_INLINE void CMatrix44::RotationZXY(const MofFloat x,const MofFloat y,const MofFloat z){
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
FORCE_INLINE void CMatrix44::RotationZYX(const Vector3& v){
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
FORCE_INLINE void CMatrix44::RotationZYX(const MofFloat x,const MofFloat y,const MofFloat z){
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
FORCE_INLINE void CMatrix44::RotationXY(const MofFloat x,const MofFloat y) {
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
FORCE_INLINE void CMatrix44::RotationXZ(const MofFloat x,const MofFloat z) {
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
FORCE_INLINE void CMatrix44::RotationYX(const MofFloat x,const MofFloat y) {
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
FORCE_INLINE void CMatrix44::RotationYZ(const MofFloat y,const MofFloat z) {
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
FORCE_INLINE void CMatrix44::RotationZX(const MofFloat x,const MofFloat z) {
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
FORCE_INLINE void CMatrix44::RotationZY(const MofFloat y,const MofFloat z) {
	RotationZ(z);
	RotationY(*this, y);
	return;
}
/*************************************************************************//*!
		@brief			X軸回転行列計算
		@param[in]		ax			X回転

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::RotationX(const MofFloat ax){
	MofFloat sina = MOF_SIN(ax);
	MofFloat cosa = MOF_COS(ax);
	_12 = _13 = _14 =
	_21 = _24 =
	_31 = _34 =
	_41 = _42 = _43 = 0.0f;
	_11 = _44 = 1.0f;
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
FORCE_INLINE void CMatrix44::RotationY(const MofFloat ay){
	MofFloat sina = MOF_SIN(ay);
	MofFloat cosa = MOF_COS(ay);
	_12 = _14 =
	_21 = _23 = _24 =
	_32 = _34 =
	_41 = _42 = _43 = 0.0f;
	_22 = _44 = 1.0f;
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
FORCE_INLINE void CMatrix44::RotationZ(const MofFloat az){
	MofFloat sina = MOF_SIN(az);
	MofFloat cosa = MOF_COS(az);
	_13 = _14 =
	_23 = _24 =
	_31 = _32 = _34 =
	_41 = _42 = _43 = 0.0f;
	_33 = _44 = 1.0f;
	_12 = sina;
	_21 = -sina;
	_11 = _22 = cosa;
	return;
}
/*************************************************************************//*!
		@brief			値の設定
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
FORCE_INLINE void CMatrix44::SetValue(	MofFloat f11 ,MofFloat f12 ,MofFloat f13 ,MofFloat f14,
										MofFloat f21 ,MofFloat f22 ,MofFloat f23 ,MofFloat f24,
										MofFloat f31 ,MofFloat f32 ,MofFloat f33 ,MofFloat f34,
										MofFloat f41 ,MofFloat f42 ,MofFloat f43 ,MofFloat f44 ){
	_11 = f11;	_12 = f12;	_13 = f13;	_14 = f14;
	_21 = f21;	_22 = f22;	_23 = f23;	_24 = f24;
	_31 = f31;	_32 = f32;	_33 = f33;	_34 = f34;
	_41 = f41;	_42 = f42;	_43 = f43;	_44 = f44;
}
/*************************************************************************//*!
		@brief			内部平行移動ベクトル設定
		@param[in]		v			平行移動

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::SetTranslation(const Vector3& v){
	_41 = v.x;
	_42 = v.y;
	_43 = v.z;
	return;
}
/*************************************************************************//*!
		@brief			内部平行移動ベクトル設定
		@param[in]		x			X座標
		@param[in]		y			Y座標
		@param[in]		z			Z座標

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::SetTranslation(const MofFloat x,const MofFloat y,const MofFloat z){
	_41 = x;
	_42 = y;
	_43 = z;
	return;
}
/*************************************************************************//*!
		@brief			内部3×3行列取得
		@param[out]		m			3×3行列

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::GetMatrix33(Matrix33& m) const{
	m._11 = _11;	m._12 = _12;	m._13 = _13;
	m._21 = _21;	m._22 = _22;	m._23 = _23;
	m._31 = _31;	m._32 = _32;	m._33 = _33;
}
/*************************************************************************//*!
		@brief			内部平行移動ベクトル取得
		@param[out]		v			平行移動

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::GetTranslation(Vector3& v) const{
	v.x = _41;
	v.y = _42;
	v.z = _43;
	return;
}
/*************************************************************************//*!
		@brief			内部拡大ベクトル取得
		@param[out]		v			倍率

		@return			None
*//**************************************************************************/
FORCE_INLINE void CMatrix44::GetScaling(Vector3& v) const{
	v.x = MOF_SQRT(_11 * _11 + _12 * _12 + _13 * _13);
	v.y = MOF_SQRT(_21 * _21 + _22 * _22 + _23 * _23);
	v.z = MOF_SQRT(_31 * _31 + _32 * _32 + _33 * _33);
	return;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CMatrix44& CMatrix44::operator = ( const Matrix33& m ){
	_11 = m._11;	_12 = m._12;	_13 = m._13;
	_21 = m._21;	_22 = m._22;	_23 = m._23;
	_31 = m._31;	_32 = m._32;	_33 = m._33;
	return *this;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CMatrix44& CMatrix44::operator = ( const Matrix44& m ){
	_11 = m._11;	_12 = m._12;	_13 = m._13;	_14 = m._14;
	_21 = m._21;	_22 = m._22;	_23 = m._23;	_24 = m._24;
	_31 = m._31;	_32 = m._32;	_33 = m._33;	_34 = m._34;
	_41 = m._41;	_42 = m._42;	_43 = m._43;	_44 = m._44;
	return *this;
}

//[EOF]