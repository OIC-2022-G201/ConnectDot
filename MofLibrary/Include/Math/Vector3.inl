/*************************************************************************//*!
					
					@file	Vector3.inl
					@brief	3Dベクトル演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Vector3
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector3::Vector3(){
	x =	0.0f;
	y =	0.0f;
	z =	0.0f;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector3::Vector3(MofFloat vx,MofFloat vy,MofFloat vz){
	x = vx;
	y = vy;
	z = vz;
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector3::Vector3(LPMofFloat pv){
	x = pv[0];
	y = pv[1];
	z = pv[2];
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector3::Vector3(const Vector3& pObj){
	x = pObj.x;
	y = pObj.y;
	z = pObj.z;
}
/*************************************************************************//*!
		@brief			floatキャスト<br>
						内部の座標をfloatポインタとしてそのまま返す。
*//**************************************************************************/
FORCE_INLINE Vector3::operator LPMofFloat (){
	return (LPMofFloat)&x;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator = ( const Vector3Impl& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator = ( const Vector2Impl& v ){
	x = v.x;
	y = v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			+取得
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator + () const{
	return Vector3(x,y,z);
}
/*************************************************************************//*!
		@brief			-取得
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator - () const{
	return Vector3(-x,-y,-z);
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator += ( const Vector3Impl& v ){
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator -= ( const Vector3Impl& v ){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの*=演算
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator *= ( const MofFloat v ){
	x *= v;
	y *= v;
	z *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3との*=演算
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator *= ( const Vector3Impl& v ){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの/=演算
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator /= ( const MofFloat v ){
	if (v == 0)
	{
		return *this;
	}
	MofFloat tmp = 1.0f  / v;
	x *= tmp;
	y *= tmp;
	z *= tmp;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3との/=演算
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator /= ( const Vector3Impl& v ){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	z /= ((v.z == 0) ? 1.0f : v.z);
	return *this;
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator + ( const Vector3Impl& v ) const{
	return Vector3(x + v.x,y + v.y,z + v.z);
}
/*************************************************************************//*!
		@brief			-演算
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator - ( const Vector3Impl& v ) const{
	return Vector3(x - v.x,y - v.y,z - v.z);
}
/*************************************************************************//*!
		@brief			floatとの*演算
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator * ( const MofFloat v ) const{
	return Vector3(x * v,y * v,z * v);
}
/*************************************************************************//*!
		@brief			Vector3との*演算
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator * ( const Vector3Impl& v ) const{
	return Vector3(x * v.x,y * v.y,z * v.z);
}
/*************************************************************************//*!
		@brief			floatとの/演算
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Vector3(x / v,y / v,z / v);
}
/*************************************************************************//*!
		@brief			Vector3との/演算
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator / ( const Vector3Impl& v ) const{
	return Vector3(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),z / ((v.z == 0) ? 1.0f : v.z));
}
/*************************************************************************//*!
		@brief			配列指定によるVector3メンバへのアクセス
*//**************************************************************************/
FORCE_INLINE MofFloat& Vector3::operator [] ( int i ){
	return fv[i];
}
/*************************************************************************//*!
		@brief			配列指定によるVector3メンバへのアクセス
*//**************************************************************************/
FORCE_INLINE const MofFloat& Vector3::operator [] ( int i ) const{
	return fv[i];
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool Vector3::operator == ( const Vector3Impl& v ) const{
	return x == v.x && y == v.y && z == v.z;
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool Vector3::operator != ( const Vector3Impl& v ) const{
	return x != v.x || y != v.y || z != v.z;
}

/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Vector3 operator + (const Vector3Impl& v1, const Vector3Impl& v2){
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
/*************************************************************************//*!
		@brief			+演算
*//**************************************************************************/
FORCE_INLINE Vector3 operator - (const Vector3Impl& v1, const Vector3Impl& v2){
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
//--------------------------------------------------------------------------------------------
//CVector3Utilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			ベクトルの長さを調べる
		@param[in]		v			調べるベクトル

		@return			引数ベクトルの長さ
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3Utilities::Length(const Vector3Impl& v){
	return MOF_SQRT(v.x * v.x + v.y * v.y + v.z * v.z);
}
/*************************************************************************//*!
		@brief			ベクトルの長さの2乗を調べる
		@param[in]		v			調べるベクトル

		@return			引数ベクトルの長さの2乗
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3Utilities::LengthSquare(const Vector3Impl& v){
	return v.x * v.x + v.y * v.y + v.z * v.z;
}
/*************************************************************************//*!
		@brief			ベクトル間の距離を調べる
		@param[in]		v1			調べるベクトル
		@param[in]		v2			調べるベクトル

		@return			引数ベクトルの長さ
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3Utilities::Distance(const Vector3Impl& v1, const Vector3Impl& v2) {
	float svx = v1.x - v2.x;
	float svy = v1.y - v2.y;
	float svz = v1.z - v2.z;
	return MOF_SQRT(svx * svx + svy * svy + svz * svz);
}
/*************************************************************************//*!
		@brief			ベクトルの内積を求める
		@param[in]		v1			計算ベクトル１
		@param[in]		v2			計算ベクトル２

		@return			内積
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3Utilities::Dot(const Vector3Impl& v1,const Vector3Impl& v2){
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
/*************************************************************************//*!
		@brief			ベクトルの内積から二つのベクトルのなす角度をラジアン単位で求める
		@param[in]		v1			計算ベクトル１
		@param[in]		v2			計算ベクトル２

		@return			角度
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3Utilities::DotAngle(const Vector3Impl& v1,const Vector3Impl& v2){
	MofFloat Len = Length(v1) * Length(v2);
	if(Len <= 0)
	{
		return 0.0f;
	}
	MofFloat dir = Dot(v1,v2) / Len;
	if(dir < -1.0f)
	{
		dir = -1.0f;
	}
	else if(dir > 1.0f)
	{
		dir = 1.0f;
	}
	return MOF_ACOS(dir);
}
/*************************************************************************//*!
		@brief			単位ベクトルを求める
		@param[in]		v1			計算ベクトル
		@param[out]		OutVec		出力ベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3Utilities::Normal(const Vector3Impl& v1,Vector3Impl& OutVec){
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
	return;
}
/*************************************************************************//*!
		@brief			ベクトルの外積を求める
		@param[in]		v1			計算ベクトル１
		@param[in]		v2			計算ベクトル２
		@param[out]		OutVec		出力ベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3Utilities::Cross(const Vector3Impl& v1, const Vector3Impl& v2, Vector3Impl& OutVec){
	Vector3Impl re;
	re.x = v1.y * v2.z - v1.z * v2.y;
	re.y = v1.z * v2.x - v1.x * v2.z;
	re.z = v1.x * v2.y - v1.y * v2.x;
	OutVec = re;
	return;
}

//--------------------------------------------------------------------------------------------
//CVector3
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3() :
Vector3() {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3(MofFloat vx,MofFloat vy,MofFloat vz) :
Vector3(vx,vy,vz) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3(LPMofFloat pv) : 
Vector3(pv) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3(const Vector3& pObj) :
Vector3(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3(const CVector3& pObj) :
Vector3(pObj) {
}
/*************************************************************************//*!
		@brief			デストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::~CVector3(){
}
/*************************************************************************//*!
		@brief			ベクトルの長さを調べる
		@param			None

		@return			ベクトルの長さ
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::Length(void) const{
	return MOF_SQRT(x * x + y * y + z * z);
}
/*************************************************************************//*!
		@brief			ベクトルの長さの2乗を調べる
		@param			None

		@return			ベクトルの長さの2乗
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::LengthSquare(void) const{
	return x * x + y * y + z * z;
}
/*************************************************************************//*!
		@brief			ベクトルの内積を求める
		@param[in]		v			計算ベクトル

		@return			内積
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::Dot(const Vector3& v) const{
	return x * v.x + y * v.y + z * v.z;
}
/*************************************************************************//*!
		@brief			ベクトルの内積から二つのベクトルのなす角度をラジアン単位で求める
		@param[in]		v			計算ベクトル

		@return			角度
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::DotAngle(const Vector3& v) const{
	MofFloat Len = Length() * CVector3Utilities::Length(v);
	if(Len <= 0)
	{
		return 0.0f;
	}
	MofFloat dir = Dot(v) / Len;
	if(dir < -1.0f)
	{
		dir = -1.0f;
	}
	else if(dir > 1.0f)
	{
		dir = 1.0f;
	}
	return MOF_ACOS(dir);
}
/*************************************************************************//*!
		@brief			単位ベクトルを求める
		@param[out]		OutVec		出力ベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3::Normal(Vector3& OutVec) const{
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
	return;
}
/*************************************************************************//*!
		@brief			ベクトルの外積を求める
		@param[in]		v			計算ベクトル
		@param[out]		OutVec		出力ベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3::Cross(const Vector3& v, Vector3& OutVec) const{
	Vector3Impl re;
	re.x = y * v.z - z * v.y;
	re.y = z * v.x - x * v.z;
	re.z = x * v.y - y * v.x;
	OutVec = re;
	return;
}
/*************************************************************************//*!
		@brief			値を絶対値にする
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3::Absolute(void){
	x = MOF_ABS(x);
	y = MOF_ABS(y);
	z = MOF_ABS(z);
	return;
}
/*************************************************************************//*!
		@brief			値のクリッピング
		@param[in]		l			最小値
		@param[in]		h			最大値

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3::Cliping(const MofFloat l,const MofFloat h){
	x = MOF_CLIPING(x,l,h);
	y = MOF_CLIPING(y,l,h);
	z = MOF_CLIPING(z,l,h);
	return;
}
/*************************************************************************//*!
		@brief			値のクリッピング
		@param[in]		l			最小値
		@param[in]		h			最大値

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3::Cliping(const Vector3& l,const Vector3& h){
	x = MOF_CLIPING(x,l.x,h.x);
	y = MOF_CLIPING(y,l.y,h.y);
	z = MOF_CLIPING(z,l.z,h.z);
	return;
}
/*************************************************************************//*!
		@brief			数値の設定
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3::SetValue(MofFloat vx,MofFloat vy,MofFloat vz){
	x = vx;
	y = vy;
	z = vz;
	return;
}
/*************************************************************************//*!
		@brief			ベクトルの大きさを設定
		@param[in]		l			大きさ

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3::SetLength(MofFloat l) {
	MofFloat d = Length();
	if (d > 0)
	{
		d = (1 / d) * l;
		x *= d;
		y *= d;
		z *= d;
	}
	else
	{
		x = 0;
		y = 0;
		z = 0;
	}
	return;
}
/*************************************************************************//*!
		@brief			最大の数値の取得
		@param			None

		@return			X,Y,Zの最大値
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::GetMaxValue(void) const {
	MofFloat m = MOF_MAX(x,y);
	return MOF_MAX(z,m);
}
/*************************************************************************//*!
		@brief			絶対値の最大の数値の取得
		@param			None

		@return			X,Y,Zの絶対値の最大値
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::GetMaxAbsValue(void) const {
	MofFloat m = MOF_MAX(MOF_ABS(x),MOF_ABS(y));
	return MOF_MAX(MOF_ABS(z),m);
}
/*************************************************************************//*!
		@brief			最低の数値の取得
		@param			None

		@return			X,Y,Zの最小値
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::GetMinValue(void) const {
	MofFloat m = MOF_MIN(x,y);
	return MOF_MIN(z,m);
}
/*************************************************************************//*!
		@brief			絶対値の最低の数値の取得
		@param			None

		@return			X,Y,Zの絶対値の最小値
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::GetMinAbsValue(void) const {
	MofFloat m = MOF_MIN(MOF_ABS(x),MOF_ABS(y));
	return MOF_MIN(MOF_ABS(z),m);
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CVector3& CVector3::operator = (const Vector2Impl& v) {
	x = v.x;
	y = v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CVector3& CVector3::operator = (const Vector3Impl& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CVector3& CVector3::operator = ( const Vector3& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

//[EOF]