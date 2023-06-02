/*************************************************************************//*!
					
					@file	Vector4.inl
					@brief	4Dベクトル演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Vector4
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector4::Vector4(){
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z
		@param[in]		vw			W

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector4::Vector4(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw){
	x = vx;
	y = vy;
	z = vz;
	w = vw;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector4::Vector4(LPMofFloat pv){
	x = pv[0];
	y = pv[1];
	z = pv[2];
	w = pv[3];
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector4::Vector4(const Vector4& pObj){
	x = pObj.x;
	y = pObj.y;
	z = pObj.z;
	w = pObj.w;
}
/*************************************************************************//*!
		@brief			floatキャスト<br>
						内部の座標をfloatポインタとしてそのまま返す。
*//**************************************************************************/
FORCE_INLINE Vector4::operator LPMofFloat (){
	return (LPMofFloat)&x;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator = ( const Vector4Impl& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator = ( const Vector2Impl& v ){
	x = v.x;
	y = v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator = ( const Vector3Impl& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			+取得
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator + () const{
	return Vector4(x,y,z,w);
}
/*************************************************************************//*!
		@brief			-取得
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator - () const{
	return Vector4(-x,-y,-z,-w);
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator += ( const Vector4Impl& v ){
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator -= ( const Vector4Impl& v ){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの*=演算
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator *= ( const MofFloat v ){
	x *= v;
	y *= v;
	z *= v;
	w *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector4との*=演算
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator *= ( const Vector4Impl& v ){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの/=演算
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator /= ( const MofFloat v ){
	if(v == 0)
	{
		return *this;
	}
	MofFloat tmp = 1.0f  / v;
	x *= tmp;
	y *= tmp;
	z *= tmp;
	w *= tmp;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector4との/=演算
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator /= ( const Vector4Impl& v ){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	z /= ((v.z == 0) ? 1.0f : v.z);
	w /= ((v.w == 0) ? 1.0f : v.w);
	return *this;
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator + ( const Vector4Impl& v ) const{
	return Vector4(x + v.x,y + v.y,z + v.z,w + v.w);
}
/*************************************************************************//*!
		@brief			-演算
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator - ( const Vector4Impl& v ) const{
	return Vector4(x - v.x,y - v.y,z - v.z,w - v.w);
}
/*************************************************************************//*!
		@brief			floatとの*演算
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator * ( const MofFloat v ) const{
	return Vector4(x * v,y * v,z * v,w * v);
}
/*************************************************************************//*!
		@brief			Vector4との*演算
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator * ( const Vector4Impl& v ) const{
	return Vector4(x * v.x,y * v.y,z * v.z,w * v.w);
}
/*************************************************************************//*!
		@brief			floatとの/演算
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Vector4(x / v,y / v,z / v,w / v);
}
/*************************************************************************//*!
		@brief			Vector4との/演算
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator / ( const Vector4Impl& v ) const{
	return Vector4(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),z / ((v.z == 0) ? 1.0f : v.z),w / ((v.w == 0) ? 1.0f : v.w));
}
/*************************************************************************//*!
		@brief			配列指定によるVector4メンバへのアクセス
*//**************************************************************************/
FORCE_INLINE MofFloat& Vector4::operator [] ( int i ){
	return fv[i];
}
/*************************************************************************//*!
		@brief			配列指定によるVector4メンバへのアクセス
*//**************************************************************************/
FORCE_INLINE const MofFloat& Vector4::operator [] ( int i ) const{
	return fv[i];
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool Vector4::operator == ( const Vector4Impl& v ) const{
	return x == v.x && y == v.y && z == v.z && w == v.w;
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool Vector4::operator != ( const Vector4Impl& v ) const{
	return x != v.x || y != v.y || z != v.z || w != v.w;
}


/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Vector4 operator + (const Vector4Impl& v1, const Vector4Impl& v2){
	return Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Vector4 operator - (const Vector4Impl& v1, const Vector4Impl& v2){
	return Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

//--------------------------------------------------------------------------------------------
//CVector4Utilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			ベクトルの長さを調べる
		@param[in]		v			調べるベクトル

		@return			引数ベクトルの長さ
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4Utilities::Length(const Vector4Impl& v){
	return MOF_SQRT(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}
/*************************************************************************//*!
		@brief			ベクトルの長さの2乗を調べる
		@param[in]		v			調べるベクトル

		@return			引数ベクトルの長さの2乗
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4Utilities::LengthSquare(const Vector4Impl& v){
	return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}
/*************************************************************************//*!
		@brief			ベクトルの内積を求める
		@param[in]		v1			計算ベクトル１
		@param[in]		v2			計算ベクトル２

		@return			内積
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4Utilities::Dot(const Vector4Impl& v1,const Vector4Impl& v2){
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}
/*************************************************************************//*!
		@brief			単位ベクトルを求める
		@param[in]		v1			計算ベクトル
		@param[out]		OutVec		出力ベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4Utilities::Normal(const Vector4Impl& v1,Vector4Impl& OutVec){
	MofFloat d = Length(v1);
	if(d > 0)
	{
		d = 1 / d;
	}
	else
	{
		d = 0;
	}
	OutVec.x = v1.x * d;
	OutVec.y = v1.y * d;
	OutVec.z = v1.z * d;
	OutVec.w = v1.w * d;
	return;
}
/*************************************************************************//*!
		@brief			U32カラーから変換
		@param[in]		col			色
		@param[out]		OutVec		出力ベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4Utilities::SetU32Color(MofU32 col,Vector4Impl& OutVec){
	OutVec.x = MOF_GetRed(col) / 255.0f;
	OutVec.y = MOF_GetGreen(col) / 255.0f;
	OutVec.z = MOF_GetBlue(col) / 255.0f;
	OutVec.w = MOF_GetAlpha(col) / 255.0f;
	return;
}
/*************************************************************************//*!
		@brief			U32カラーへの変換
		@param[in]		v			変換ベクトル

		@return			U32カラー
*//**************************************************************************/
FORCE_INLINE MofU32 CVector4Utilities::ToU32Color(const Vector4Impl& v){
	MofU8 r = MOF_FToColor(v.x);
	MofU8 g = MOF_FToColor(v.y);
	MofU8 b = MOF_FToColor(v.z);
	MofU8 a = MOF_FToColor(v.w);
	return MOF_ARGB(a,r,g,b);
}

//--------------------------------------------------------------------------------------------
//CVector4
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4() :
Vector4() {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z
		@param[in]		vw			W

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw) :
Vector4(vx,vy,vz,vw) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4(LPMofFloat pv) : 
Vector4(pv) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4(const Vector4& pObj) :
Vector4(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4(const CVector4& pObj) :
Vector4(pObj) {
}
/*************************************************************************//*!
		@brief			デストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::~CVector4(){
}
/*************************************************************************//*!
		@brief			ベクトルの長さを調べる
		@param			None

		@return			ベクトルの長さ
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::Length(void) const{
	return MOF_SQRT(x * x + y * y + z * z + w * w);
}
/*************************************************************************//*!
		@brief			ベクトルの長さの2乗を調べる
		@param			None

		@return			ベクトルの長さの2乗
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::LengthSquare(void) const{
	return x * x + y * y + z * z + w * w;
}
/*************************************************************************//*!
		@brief			ベクトルの内積を求める
		@param[in]		v			計算ベクトル

		@return			内積
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::Dot(const Vector4& v) const{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}
/*************************************************************************//*!
		@brief			単位ベクトルを求める
		@param[out]		OutVec		出力ベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::Normal(Vector4& OutVec) const{
	MofFloat d = Length();
	if(d > 0)
	{
		d = 1 / d;
	}
	else
	{
		d = 0;
	}
	OutVec.x = x * d;
	OutVec.y = y * d;
	OutVec.z = z * d;
	OutVec.w = w * d;
	return;
}
/*************************************************************************//*!
		@brief			U32カラーから変換
		@param[in]		col			色

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::SetU32Color(MofU32 col){
	x = MOF_GetRed(col) / 255.0f;
	y = MOF_GetGreen(col) / 255.0f;
	z = MOF_GetBlue(col) / 255.0f;
	w = MOF_GetAlpha(col) / 255.0f;
	return;
}
/*************************************************************************//*!
		@brief			U32カラーへの変換
		@param			None

		@return			U32カラー
*//**************************************************************************/
FORCE_INLINE MofU32 CVector4::ToU32Color(void) const{
	MofU8 r = MOF_FToColor(x);
	MofU8 g = MOF_FToColor(y);
	MofU8 b = MOF_FToColor(z);
	MofU8 a = MOF_FToColor(w);
	return MOF_ARGB(a,r,g,b);
}
/*************************************************************************//*!
		@brief			値を絶対値にする
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::Absolute(void){
	x = MOF_ABS(x);
	y = MOF_ABS(y);
	z = MOF_ABS(z);
	w = MOF_ABS(w);
	return;
}
/*************************************************************************//*!
		@brief			値のクリッピング
		@param[in]		l			最小値
		@param[in]		h			最大値

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::Cliping(const MofFloat l,const MofFloat h){
	x = MOF_CLIPING(x,l,h);
	y = MOF_CLIPING(y,l,h);
	z = MOF_CLIPING(z,l,h);
	w = MOF_CLIPING(w,l,h);
	return;
}
/*************************************************************************//*!
		@brief			値のクリッピング
		@param[in]		l			最小値
		@param[in]		h			最大値

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::Cliping(const Vector4& l,const Vector4& h){
	x = MOF_CLIPING(x,l.x,h.x);
	y = MOF_CLIPING(y,l.y,h.y);
	z = MOF_CLIPING(z,l.z,h.z);
	w = MOF_CLIPING(w,l.w,h.w);
	return;
}
/*************************************************************************//*!
		@brief			数値の設定
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z
		@param[in]		vw			W

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::SetValue(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw){
	x = vx;
	y = vy;
	z = vz;
	w = vw;
	return;
}
/*************************************************************************//*!
		@brief			最大の数値の取得
		@param			None

		@return			X,Y,Z,Wの最大値
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::GetMaxValue(void) const {
	MofFloat m = MOF_MAX(x,y);
	m = MOF_MAX(z,m);
	return MOF_MAX(w,m);
}
/*************************************************************************//*!
		@brief			絶対値の最大の数値の取得
		@param			None

		@return			X,Y,Z,Wの絶対値の最大値
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::GetMaxAbsValue(void) const {
	MofFloat m = MOF_MAX(MOF_ABS(x),MOF_ABS(y));
	m = MOF_MAX(MOF_ABS(z),m);
	return MOF_MAX(MOF_ABS(w),m);
}
/*************************************************************************//*!
		@brief			最低の数値の取得
		@param			None

		@return			X,Y,Z,Wの最小値
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::GetMinValue(void) const {
	MofFloat m = MOF_MIN(x,y);
	m = MOF_MIN(z,m);
	return MOF_MIN(w,m);
}
/*************************************************************************//*!
		@brief			絶対値の最低の数値の取得
		@param			None

		@return			X,Y,Z,Wの絶対値の最小値
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::GetMinAbsValue(void) const {
	MofFloat m = MOF_MIN(MOF_ABS(x),MOF_ABS(y));
	m = MOF_MIN(MOF_ABS(z),m);
	return MOF_MIN(MOF_ABS(w),m);
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CVector4& CVector4::operator = (const Vector2Impl& v) {
	x = v.x;
	y = v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CVector4& CVector4::operator = (const Vector3Impl& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CVector4& CVector4::operator = (const Vector4Impl& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CVector4& CVector4::operator = ( const Vector4& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}

//[EOF]