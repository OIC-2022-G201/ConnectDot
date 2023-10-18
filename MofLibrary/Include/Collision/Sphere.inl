/*************************************************************************//*!
					
					@file	Sphere.inl
					@brief	球演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Sphere
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Sphere::Sphere() :
x(0.0f) ,
y(0.0f) ,
z(0.0f) ,
r(0.0f) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		cx			Ｘ座標
		@param[in]		cy			Ｙ座標
		@param[in]		cz			Ｚ座標
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE Sphere::Sphere(MofFloat cx,MofFloat cy,MofFloat cz,MofFloat cr) :
x(cx) ,
y(cy) ,
z(cz) ,
r(cr) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pos			座標
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE Sphere::Sphere(const Vector3& pos,MofFloat cr) :
x(pos.x) ,
y(pos.y) ,
z(pos.z) ,
r(cr) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE Sphere::Sphere(LPMofFloat pv) : 
x(pv[0]) ,
y(pv[1]) ,
z(pv[2]) ,
r(pv[3]) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE Sphere::Sphere(const Sphere& pObj) :
x(pObj.x) ,
y(pObj.y) ,
z(pObj.z) ,
r(pObj.r) {
}
/*************************************************************************//*!
		@brief			floatキャスト<br>
						内部の座標をfloatポインタとしてそのまま返す。
*//**************************************************************************/
FORCE_INLINE Sphere::operator LPMofFloat (){
	return (LPMofFloat)&Position;
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator += (const Vector3& v){
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator += (const Sphere& v){
	x += v.x;
	y += v.y;
	z += v.z;
	r += v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator -= (const Vector3& v){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator -= ( const Sphere& v ){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	r -= v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの*=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator *= ( const MofFloat v ){
	x *= v;
	y *= v;
	z *= v;
	r *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3との*=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator *= (const Vector3& v){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			Sphereとの*=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator *= ( const Sphere& v ){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	r *= v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			Matrix44との*演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator *= ( const Matrix44& v ){
	CVector3 sv;
	CMatrix44Utilities::GetScaling(v, sv);
	CVector3Utilities::TransformCoord(Position, v, Position);
	r *= sv.GetMaxAbsValue();
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの/=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator /= ( const MofFloat v ){
	if(v == 0)
	{
		return *this;
	}
	MofFloat tmp = 1.0f  / v;
	x *= tmp;
	y *= tmp;
	z *= tmp;
	r *= tmp;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3との/=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator /= (const Vector3& v){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	z /= ((v.z == 0) ? 1.0f : v.z);
	return *this;
}
/*************************************************************************//*!
		@brief			Sphereとの/=演算
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator /= (const Sphere& v){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	z /= ((v.z == 0) ? 1.0f : v.z);
	r /= ((v.r == 0) ? 1.0f : v.r);
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3との+演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator + ( const Vector3& v ) const{
	return Sphere(x + v.x,y + v.y,z + v.z,r);
}
/*************************************************************************//*!
		@brief			Sphereとの+演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator + ( const Sphere& v ) const{
	return Sphere(x + v.x,y + v.y,z + v.z,r + v.r);
}
/*************************************************************************//*!
		@brief			Vector3との-演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator - ( const Vector3& v ) const{
	return Sphere(x - v.x,y - v.y,z - v.z,r);
}
/*************************************************************************//*!
		@brief			Sphereとの-演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator - ( const Sphere& v ) const{
	return Sphere(x - v.x,y - v.y,z - v.z,r - v.r);
}
/*************************************************************************//*!
		@brief			floatとの*演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator * ( const MofFloat v ) const{
	return Sphere(x * v,y * v,z * v,r * v);
}
/*************************************************************************//*!
		@brief			Vector3との*演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator * ( const Vector3& v ) const{
	return Sphere(x * v.x,y * v.y,z * v.z,r);
}
/*************************************************************************//*!
		@brief			Matrix44との*演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator * ( const Matrix44& v ) const{
	Vector3Impl op;
	CVector3 sv;
	CMatrix44Utilities::GetScaling(v, sv);
	CVector3Utilities::TransformCoord(Position, v, op);
	return Sphere(op.x, op.y, op.z, r * sv.GetMaxAbsValue());
}
/*************************************************************************//*!
		@brief			Sphereとの*演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator * ( const Sphere& v ) const{
	return Sphere(x * v.x,y * v.y,z * v.z,r * v.r);
}
/*************************************************************************//*!
		@brief			floatとの/演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Sphere(x / v,y / v,z / v,r / v);
}
/*************************************************************************//*!
		@brief			Vector3との/演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator / ( const Vector3& v ) const{
	return Sphere(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),z / ((v.z == 0) ? 1.0f : v.z),r);
}
/*************************************************************************//*!
		@brief			Sphereとの/演算
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator / ( const Sphere& v ) const{
	return Sphere(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),z / ((v.z == 0) ? 1.0f : v.z),r / ((v.r == 0) ? 1.0f : v.r));
}
/*************************************************************************//*!
		@brief			配列指定によるSphereメンバへのアクセス
*//**************************************************************************/
FORCE_INLINE MofFloat& Sphere::operator [] ( int i ){
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			配列指定によるSphereメンバへのアクセス
*//**************************************************************************/
FORCE_INLINE const MofFloat& Sphere::operator [] ( int i ) const{
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool Sphere::operator == ( const Sphere& v ) const{
	return x == v.x && y == v.y && z == v.z && r == v.r;
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool Sphere::operator != ( const Sphere& v ) const{
	return x != v.x || y != v.y || z != v.z || r != v.r;
}
//--------------------------------------------------------------------------------------------
//CSphereUtilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector3（ポイント）が球の中に入っているかを判定する
		@param[in]		px			判定X位置
		@param[in]		py			判定Y位置
		@param[in]		pz			判定Z位置

		@return			TRUE		球の中に点がある
						FALSE		球の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CSphereUtilities::CollisionPoint(const Sphere& r,const MofFloat px,const MofFloat py,const MofFloat pz){
	MofFloat d = (MOF_SQUARE(r.x - px)) + (MOF_SQUARE(r.y - py)) + (MOF_SQUARE(r.z - pz));
	if(d <= MOF_SQUARE(r.r))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector3（ポイント）が球の中に入っているかを判定する
		@param[in]		p			判定位置

		@return			TRUE		球の中に点がある
						FALSE		球の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CSphereUtilities::CollisionPoint(const Sphere& r,const Vector3& p){
	MofFloat d = (MOF_SQUARE(r.x - p.x)) + (MOF_SQUARE(r.y - p.y)) + (MOF_SQUARE(r.z - p.z));
	if(d <= MOF_SQUARE(r.r))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定した二つのSphere（球）が接触しているかを判定する
		@param[in]		r1			判定球
		@param[in]		r2			判定球
		
		@return			TRUE		接触
						FALSE		範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CSphereUtilities::CollisionSphere(const Sphere& r1,const Sphere& r2){
	MofFloat d = (MOF_SQUARE(r1.x - r2.x)) + (MOF_SQUARE(r1.y - r2.y)) + (MOF_SQUARE(r1.z - r2.z));
	if(d <= MOF_SQUARE(r1.r + r2.r))
	{
		return TRUE;
	}
	return FALSE;
}
//--------------------------------------------------------------------------------------------
//CSphere
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere() :
Sphere() {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		cx			Ｘ座標
		@param[in]		cy			Ｙ座標
		@param[in]		cz			Ｚ座標
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(MofFloat cx,MofFloat cy,MofFloat cz,MofFloat cr) :
Sphere(cx,cy,cz,cr) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pos			座標
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(const Vector3& pos,MofFloat cr) :
Sphere(pos,cr) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(LPMofFloat pv) :
Sphere(pv) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー球

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(const Sphere& pObj) :
Sphere(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー球

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(const CSphere& pObj) :
Sphere(pObj) {
}
/*************************************************************************//*!
		@brief			移動<br>
						m移動する。
		@param[in]		m			移動量
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CSphere::Translation(const Vector3& m) {
	x += m.x;
	y += m.y;
	z += m.z;
	return;
}
/*************************************************************************//*!
		@brief			移動<br>
						posの位置に移動する。
		@param[in]		pos			位置
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CSphere::SetPosition(const Vector3& pos){
	x = pos.x;
	y = pos.y;
	z = pos.z;
	return;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector3（ポイント）が球の中に入っているかを判定する
		@param[in]		px			判定X位置
		@param[in]		py			判定Y位置
		@param[in]		pz			判定Z位置

		@return			TRUE		球の中に点がある
						FALSE		球の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CSphere::CollisionPoint(const MofFloat px,const MofFloat py,const MofFloat pz) const {
	MofFloat d = (MOF_SQUARE(x - px)) + (MOF_SQUARE(y - py)) + (MOF_SQUARE(z - pz));
	if(d <= MOF_SQUARE(r))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector3（ポイント）が球の中に入っているかを判定する
		@param[in]		p			判定位置

		@return			TRUE		球の中に点がある
						FALSE		球の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CSphere::CollisionPoint(const Vector3& p) const {
	MofFloat d = (MOF_SQUARE(x - p.x)) + (MOF_SQUARE(y - p.y)) + (MOF_SQUARE(z - p.z));
	if(d <= MOF_SQUARE(r))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したSphere（球）が接触しているかを判定する
		@param[in]		cx			判定Ｘ位置
		@param[in]		cy			判定Ｙ位置
		@param[in]		cz			判定Ｚ位置
		@param[in]		cr			判定半径
		
		@return			TRUE		接触
						FALSE		範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CSphere::CollisionSphere(const MofFloat cx,const MofFloat cy,const MofFloat cz,const MofFloat cr) const {
	MofFloat d = (MOF_SQUARE(x - cx)) + (MOF_SQUARE(y - cy)) + (MOF_SQUARE(y - cz));
	if(d <= MOF_SQUARE(r + cr))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したSphere（球）が接触しているかを判定する
		@param[in]		c			判定球
		
		@return			TRUE		接触
						FALSE		範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CSphere::CollisionSphere(const Sphere& c) const {
	MofFloat d = (MOF_SQUARE(x - c.x)) + (MOF_SQUARE(y - c.y)) + (MOF_SQUARE(z - c.z));
	if(d <= MOF_SQUARE(r + c.r))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			数値の設定
		@param[in]		cx			Ｘ座標
		@param[in]		cy			Ｙ座標
		@param[in]		cz			Ｚ座標
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE void CSphere::SetValue(MofFloat cx,MofFloat cy,MofFloat cz,MofFloat cr){
	x = cx;
	y = cy;
	z = cz;
	r = cr;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CSphere& CSphere::operator = ( const Sphere& v ){
	Position = v.Position;
	r = v.r;
	return *this;
}

//[EOF]