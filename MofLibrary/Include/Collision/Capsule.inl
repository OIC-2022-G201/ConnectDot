/*************************************************************************//*!
					
					@file	Capsule.inl
					@brief	カプセル演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Capsule
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Capsule::Capsule() :
Position() ,
Angle() ,
r(0.0f) ,
h(0.0f) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		cx			Ｘ座標
		@param[in]		cy			Ｙ座標
		@param[in]		cz			Ｚ座標
		@param[in]		cr			半径
		@param[in]		ch			高さ

		@return			None
*//**************************************************************************/
FORCE_INLINE Capsule::Capsule(MofFloat cx, MofFloat cy, MofFloat cz, MofFloat cr, MofFloat ch) :
Position(cx,cy,cz) ,
Angle() ,
r(cr) ,
h(ch) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pos			座標
		@param[in]		ang			向き
		@param[in]		cr			半径
		@param[in]		ch			高さ

		@return			None
*//**************************************************************************/
FORCE_INLINE Capsule::Capsule(const Vector3& pos, const Vector3& ang, MofFloat cr, MofFloat ch) :
Position(pos),
Angle(ang),
r(cr) ,
h(ch) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE Capsule::Capsule(LPMofFloat pv) :
Position(pv[0], pv[1], pv[2]),
Angle(pv[3],pv[4],pv[5]),
r(pv[6]),
h(pv[7]) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE Capsule::Capsule(const Capsule& pObj) :
Position(pObj.Position) ,
Angle(pObj.Angle) ,
r(pObj.r) ,
h(pObj.h) {
}
/*************************************************************************//*!
		@brief			floatキャスト<br>
						内部の座標をfloatポインタとしてそのまま返す。
*//**************************************************************************/
FORCE_INLINE Capsule::operator LPMofFloat (){
	return (LPMofFloat)&Position.x;
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator += (const Vector3& v){
	Position.x += v.x;
	Position.y += v.y;
	Position.z += v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator += (const Capsule& v){
	Position.x += v.Position.x;
	Position.y += v.Position.y;
	Position.z += v.Position.z;
	Angle.x += v.Angle.x;
	Angle.y += v.Angle.y;
	Angle.z += v.Angle.z;
	r += v.r;
	h += v.h;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator -= (const Vector3& v){
	Position.x -= v.x;
	Position.y -= v.y;
	Position.z -= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator -= ( const Capsule& v ){
	Position.x -= v.Position.x;
	Position.y -= v.Position.y;
	Position.z -= v.Position.z;
	Angle.x -= v.Angle.x;
	Angle.y -= v.Angle.y;
	Angle.z -= v.Angle.z;
	r -= v.r;
	h -= v.h;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの*=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator *= ( const MofFloat v ){
	Position.x *= v;
	Position.y *= v;
	Position.z *= v;
	r *= v;
	h *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3との*=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator *= (const Vector3& v){
	Position.x *= v.x;
	Position.y *= v.y;
	Position.z *= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			Capsuleとの*=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator *= ( const Capsule& v ){
	Position.x *= v.Position.x;
	Position.y *= v.Position.y;
	Position.z *= v.Position.z;
	Angle.x *= v.Angle.x;
	Angle.y *= v.Angle.y;
	Angle.z *= v.Angle.z;
	r *= v.r;
	h *= v.h;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの/=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator /= ( const MofFloat v ){
	if(v == 0)
	{
		return *this;
	}
	MofFloat tmp = 1.0f  / v;
	Position.x *= tmp;
	Position.y *= tmp;
	Position.z *= tmp;
	r *= tmp;
	h *= tmp;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3との/=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator /= (const Vector3& v){
	Position.x /= ((v.x == 0) ? 1.0f : v.x);
	Position.y /= ((v.y == 0) ? 1.0f : v.y);
	Position.z /= ((v.z == 0) ? 1.0f : v.z);
	return *this;
}
/*************************************************************************//*!
		@brief			Capsuleとの/=演算
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator /= (const Capsule& v){
	Position.x /= ((v.Position.x == 0) ? 1.0f : v.Position.x);
	Position.y /= ((v.Position.y == 0) ? 1.0f : v.Position.y);
	Position.z /= ((v.Position.z == 0) ? 1.0f : v.Position.z);
	Angle.x /= ((v.Angle.x == 0) ? 1.0f : v.Angle.x);
	Angle.y /= ((v.Angle.y == 0) ? 1.0f : v.Angle.y);
	Angle.z /= ((v.Angle.z == 0) ? 1.0f : v.Angle.z);
	r /= ((v.r == 0) ? 1.0f : v.r);
	h /= ((v.h == 0) ? 1.0f : v.h);
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3との+演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator + ( const Vector3& v ) const{
	return Capsule(Position + v,Angle, r, h);
}
/*************************************************************************//*!
		@brief			Capsuleとの+演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator + ( const Capsule& v ) const{
	return Capsule(Position + v.Position, Angle + v.Angle, r + v.r, h + v.h);
}
/*************************************************************************//*!
		@brief			Vector3との-演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator - ( const Vector3& v ) const{
	return Capsule(Position - v, Angle, r, h);
}
/*************************************************************************//*!
		@brief			Capsuleとの-演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator - ( const Capsule& v ) const{
	return Capsule(Position - v.Position, Angle - v.Angle, r - v.r, h - v.h);
}
/*************************************************************************//*!
		@brief			floatとの*演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator * ( const MofFloat v ) const{
	return Capsule(Position * v, Angle, r * v, h * v);
}
/*************************************************************************//*!
		@brief			Vector3との*演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator * ( const Vector3& v ) const{
	return Capsule(Position * v, Angle, r, h);
}
/*************************************************************************//*!
		@brief			Capsuleとの*演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator * ( const Capsule& v ) const{
	return Capsule(Position * v.Position, Angle * v.Angle, r * v.r, h * v.h);
}
/*************************************************************************//*!
		@brief			floatとの/演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Capsule(Position / v, Angle, r / v, h / v);
}
/*************************************************************************//*!
		@brief			Vector3との/演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator / ( const Vector3& v ) const{
	return Capsule(Position / v, Angle, r, h);
}
/*************************************************************************//*!
		@brief			Capsuleとの/演算
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator / ( const Capsule& v ) const{
	return Capsule(Position / v.Position, Angle / v.Angle, r / ((v.r == 0) ? 1.0f : v.r), h / ((v.h == 0) ? 1.0f : v.h));
}
/*************************************************************************//*!
		@brief			配列指定によるCapsuleメンバへのアクセス
*//**************************************************************************/
FORCE_INLINE MofFloat& Capsule::operator [] ( int i ){
	return (&Position.x)[i];
}
/*************************************************************************//*!
		@brief			配列指定によるCapsuleメンバへのアクセス
*//**************************************************************************/
FORCE_INLINE const MofFloat& Capsule::operator [] ( int i ) const{
	return (&Position.x)[i];
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool Capsule::operator == ( const Capsule& v ) const{
	return Position.x == v.Position.x && Position.y == v.Position.y && Position.z == v.Position.z &&
		Angle.x == v.Angle.x && Angle.y == v.Angle.y && Angle.z == v.Angle.z && r == v.r && h == v.h;
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool Capsule::operator != ( const Capsule& v ) const{
	return Position.x != v.Position.x || Position.y != v.Position.y || Position.z != v.Position.z ||
		Angle.x != v.Angle.x || Angle.y != v.Angle.y || Angle.z != v.Angle.z || r != v.r || h != v.h;
}
//--------------------------------------------------------------------------------------------
//CCapsule
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule() :
Capsule() {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		cx			Ｘ座標
		@param[in]		cy			Ｙ座標
		@param[in]		cz			Ｚ座標
		@param[in]		cr			半径
		@param[in]		ch			高さ

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(MofFloat cx, MofFloat cy, MofFloat cz, MofFloat cr, MofFloat ch) :
Capsule(cx,cy,cz,cr,ch) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pos			座標
		@param[in]		ang			向き
		@param[in]		cr			半径
		@param[in]		ch			高さ

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(const Vector3& pos, const Vector3& ang, MofFloat cr, MofFloat ch) :
Capsule(pos, ang, cr, ch) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(LPMofFloat pv) :
Capsule(pv) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーカプセル

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(const Capsule& pObj) :
Capsule(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーカプセル

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(const CCapsule& pObj) :
Capsule(pObj) {
}
/*************************************************************************//*!
		@brief			移動<br>
						m移動する。
		@param[in]		m			移動量
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CCapsule::Translation(const Vector3& m) {
	Position += m;
	return;
}
/*************************************************************************//*!
		@brief			移動<br>
						posの位置に移動する。
		@param[in]		pos			位置
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CCapsule::SetPosition(const Vector3& pos){
	Position = pos;
	return;
}
/*************************************************************************//*!
		@brief			数値の設定
		@param[in]		cx			Ｘ座標
		@param[in]		cy			Ｙ座標
		@param[in]		cz			Ｚ座標
		@param[in]		ax			Ｘ角度
		@param[in]		ay			Ｙ角度
		@param[in]		az			Ｚ角度
		@param[in]		cr			半径
		@param[in]		ch			高さ

		@return			None
*//**************************************************************************/
FORCE_INLINE void CCapsule::SetValue(MofFloat cx, MofFloat cy, MofFloat cz, MofFloat ax, MofFloat ay, MofFloat az, MofFloat cr, MofFloat ch){
	Position.x = cx;
	Position.y = cy;
	Position.z = cz;
	Angle.x = ax;
	Angle.y = ay;
	Angle.z = az;
	r = cr;
	h = ch;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CCapsule& CCapsule::operator = ( const Capsule& v ){
	Position = v.Position;
	r = v.r;
	h = v.h;
	return *this;
}

//[EOF]