/*************************************************************************//*!
					
					@file	Circle.inl
					@brief	円演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Circle
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle() :
x(0.0f) ,
y(0.0f) ,
r(0.0f) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		cx			Ｘ座標
		@param[in]		cy			Ｙ座標
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle(MofFloat cx,MofFloat cy,MofFloat cr) :
x(cx) ,
y(cy) ,
r(cr) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pos			座標
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle(const Vector2& pos,MofFloat cr) :
x(pos.x) ,
y(pos.y) ,
r(cr) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle(LPMofFloat pv) : 
x(pv[0]) ,
y(pv[1]) ,
r(pv[2]) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle(const Circle& pObj) :
x(pObj.x) ,
y(pObj.y) ,
r(pObj.r) {
}
/*************************************************************************//*!
		@brief			floatキャスト<br>
						内部の座標をfloatポインタとしてそのまま返す。
*//**************************************************************************/
FORCE_INLINE Circle::operator LPMofFloat (){
	return (LPMofFloat)&x;
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator += ( const Vector2& v ){
	x += v.x;
	y += v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator += ( const Circle& v ){
	x += v.x;
	y += v.y;
	r += v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator -= ( const Vector2& v ){
	x -= v.x;
	y -= v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator -= ( const Circle& v ){
	x -= v.x;
	y -= v.y;
	r -= v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの*=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator *= ( const MofFloat v ){
	x *= x;
	y *= y;
	r *= r;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2との*=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator *= ( const Vector2& v ){
	x *= v.x;
	y *= v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			Circleとの*=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator *= ( const Circle& v ){
	x *= v.x;
	y *= v.y;
	r *= v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの/=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator /= ( const MofFloat v ){
	if(v == 0)
	{
		return *this;
	}
	MofFloat tmp = 1.0f  / v;
	x *= tmp;
	y *= tmp;
	r *= tmp;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2との/=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator /= ( const Vector2& v ){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	return *this;
}
/*************************************************************************//*!
		@brief			Circleとの/=演算
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator /= ( const Circle& v ){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	r /= ((v.r == 0) ? 1.0f : v.r);
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2との+演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator + ( const Vector2& v ) const{
	return Circle(x + v.x,y + v.y,r);
}
/*************************************************************************//*!
		@brief			Circleとの+演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator + ( const Circle& v ) const{
	return Circle(x + v.x,y + v.y,r + v.r);
}
/*************************************************************************//*!
		@brief			Vector2との-演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator - ( const Vector2& v ) const{
	return Circle(x - v.x,y - v.y,r);
}
/*************************************************************************//*!
		@brief			Circleとの-演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator - ( const Circle& v ) const{
	return Circle(x - v.x,y - v.y,r - v.r);
}
/*************************************************************************//*!
		@brief			floatとの*演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator * ( const MofFloat v ) const{
	return Circle(x * v,y * v,r * v);
}
/*************************************************************************//*!
		@brief			Vector2との*演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator * ( const Vector2& v ) const{
	return Circle(x * v.x,y * v.y,r);
}
/*************************************************************************//*!
		@brief			Circleとの*演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator * ( const Circle& v ) const{
	return Circle(x * v.x,y * v.y,r * v.r);
}
/*************************************************************************//*!
		@brief			floatとの/演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Circle(x / v,y / v,r / v);
}
/*************************************************************************//*!
		@brief			Vector2との/演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator / ( const Vector2& v ) const{
	return Circle(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),r);
}
/*************************************************************************//*!
		@brief			Circleとの/演算
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator / ( const Circle& v ) const{
	return Circle(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),r / ((v.r == 0) ? 1.0f : v.r));
}
/*************************************************************************//*!
		@brief			配列指定によるCircleメンバへのアクセス
*//**************************************************************************/
FORCE_INLINE MofFloat& Circle::operator [] ( int i ){
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			配列指定によるCircleメンバへのアクセス
*//**************************************************************************/
FORCE_INLINE const MofFloat& Circle::operator [] ( int i ) const{
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool Circle::operator == ( const Circle& v ) const{
	return x == v.x && y == v.y && r == v.r;
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool Circle::operator != ( const Circle& v ) const{
	return x != v.x || y != v.y || r != v.r;
}
//--------------------------------------------------------------------------------------------
//CCircleUtilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector2（ポイント）が円の中に入っているかを判定する
		@param[in]		px			判定X位置
		@param[in]		py			判定Y位置

		@return			TRUE		円の中に点がある
						FALSE		円の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CCircleUtilities::CollisionPoint(const Circle& r,const MofFloat px,const MofFloat py){
	MofFloat d = (MOF_SQUARE(r.x - px)) + (MOF_SQUARE(r.y - py));
	if(d <= MOF_SQUARE(r.r))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector2（ポイント）が円の中に入っているかを判定する
		@param[in]		p			判定位置

		@return			TRUE		円の中に点がある
						FALSE		円の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CCircleUtilities::CollisionPoint(const Circle& r,const Vector2& p){
	MofFloat d = (MOF_SQUARE(r.x - p.x)) + (MOF_SQUARE(r.y - p.y));
	if(d <= MOF_SQUARE(r.r))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定した二つのCircle（円）が接触しているかを判定する
		@param[in]		r1			判定円
		@param[in]		r2			判定円

		@return			TRUE		円の中に点がある
						FALSE		円の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CCircleUtilities::CollisionCircle(const Circle& r1,const Circle& r2){
	MofFloat d = (MOF_SQUARE(r1.x - r2.x)) + (MOF_SQUARE(r1.y - r2.y));
	if(d <= MOF_SQUARE(r1.r + r2.r))
	{
		return TRUE;
	}
	return FALSE;
}
//--------------------------------------------------------------------------------------------
//CCircle
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle() :
Circle() {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		cx			Ｘ座標
		@param[in]		cy			Ｙ座標
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(MofFloat cx,MofFloat cy,MofFloat cr) :
Circle(cx,cy,cr) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pos			座標
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(const Vector2& pos,MofFloat cr) :
Circle(pos,cr) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(LPMofFloat pv) :
Circle(pv) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー円

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(const Circle& pObj) :
Circle(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー円

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(const CCircle& pObj) :
Circle(pObj) {
}
/*************************************************************************//*!
		@brief			移動<br>
						m移動する。
		@param[in]		m			移動量
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CCircle::Translation(const Vector2& m) {
	x += m.x;
	y += m.y;
	return;
}
/*************************************************************************//*!
		@brief			移動<br>
						posの位置に移動する。
		@param[in]		pos			位置
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CCircle::SetPosition(const Vector2& pos){
	x = pos.x;
	y = pos.y;
	return;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector2（ポイント）が円の中に入っているかを判定する
		@param[in]		px			判定X位置
		@param[in]		py			判定Y位置

		@return			TRUE		円の中に点がある
						FALSE		円の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CCircle::CollisionPoint(const MofFloat px,const MofFloat py) const {
	MofFloat d = (MOF_SQUARE(x - px)) + (MOF_SQUARE(y - py));
	if(d <= MOF_SQUARE(r))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector2（ポイント）が円の中に入っているかを判定する
		@param[in]		p			判定位置

		@return			TRUE		円の中に点がある
						FALSE		円の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CCircle::CollisionPoint(const Vector2& p) const {
	MofFloat d = (MOF_SQUARE(x - p.x)) + (MOF_SQUARE(y - p.y));
	if(d <= MOF_SQUARE(r))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したCircle（円）が接触しているかを判定する
		@param[in]		cx			判定Ｘ位置
		@param[in]		cy			判定Ｙ位置
		@param[in]		cr			判定半径

		@return			TRUE		円の中に点がある
						FALSE		円の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CCircle::CollisionCircle(const MofFloat cx,const MofFloat cy,const MofFloat cr) const {
	MofFloat d = (MOF_SQUARE(x - cx)) + (MOF_SQUARE(y - cy));
	if(d <= MOF_SQUARE(r + cr))
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したCircle（円）が接触しているかを判定する
		@param[in]		c			判定円

		@return			TRUE		円の中に点がある
						FALSE		円の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CCircle::CollisionCircle(const Circle& c) const {
	MofFloat d = (MOF_SQUARE(x - c.x)) + (MOF_SQUARE(y - c.y));
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
		@param[in]		cr			半径

		@return			None
*//**************************************************************************/
FORCE_INLINE void CCircle::SetValue(MofFloat cx,MofFloat cy,MofFloat cr){
	x = cx;
	y = cy;
	r = cr;
	return;
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CCircle& CCircle::operator = ( const Circle& v ){
	x = v.x;
	y = v.y;
	r = v.r;
	return *this;
}

//[EOF]