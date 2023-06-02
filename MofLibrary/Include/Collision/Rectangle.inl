/*************************************************************************//*!
					
					@file	Rectangle.inl
					@brief	矩形演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Rectangle
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Rectangle::Rectangle() :
Left(0.0f) ,
Top(0.0f) ,
Right(0.0f) ,
Bottom(0.0f) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		l			左
		@param[in]		t			上
		@param[in]		r			右
		@param[in]		b			下

		@return			None
*//**************************************************************************/
FORCE_INLINE Rectangle::Rectangle(MofFloat l,MofFloat t,MofFloat r,MofFloat b) :
Left(l) ,
Top(t) ,
Right(r) ,
Bottom(b) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		lt			左上
		@param[in]		rb			右下

		@return			None
*//**************************************************************************/
FORCE_INLINE Rectangle::Rectangle(const Vector2& lt,const Vector2& rb) :
Left(lt.x) ,
Top(lt.y) ,
Right(rb.x) ,
Bottom(rb.y) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE Rectangle::Rectangle(LPMofFloat pv) : 
Left(pv[0]) ,
Top(pv[1]) ,
Right(pv[2]) ,
Bottom(pv[3]) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピーベクトル

		@return			None
*//**************************************************************************/
FORCE_INLINE Rectangle::Rectangle(const Rectangle& pObj) :
Left(pObj.Left) ,
Top(pObj.Top) ,
Right(pObj.Right) ,
Bottom(pObj.Bottom) {
}
/*************************************************************************//*!
		@brief			floatキャスト<br>
						内部の座標をfloatポインタとしてそのまま返す。
*//**************************************************************************/
FORCE_INLINE Rectangle::operator LPMofFloat (){
	return (LPMofFloat)&Left;
}
/*************************************************************************//*!
		@brief			+取得
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator + () const{
	return Rectangle(*this);
}
/*************************************************************************//*!
		@brief			-取得
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator - () const{
	return Rectangle(-Left,-Top,-Right,-Bottom);
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator += ( const Vector2& v ){
	Left += v.x;
	Top += v.y;
	Right += v.x;
	Bottom += v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			+=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator += ( const Rectangle& v ){
	Left += v.Left;
	Top += v.Top;
	Right += v.Right;
	Bottom += v.Bottom;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator -= ( const Vector2& v ){
	Left -= v.x;
	Top -= v.y;
	Right -= v.x;
	Bottom -= v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			-=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator -= ( const Rectangle& v ){
	Left -= v.Left;
	Top -= v.Top;
	Right -= v.Right;
	Bottom -= v.Bottom;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの*=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator *= ( const MofFloat v ){
	Left *= v;
	Top *= v;
	Right *= v;
	Bottom *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2との*=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator *= ( const Vector2& v ){
	Left *= v.x;
	Top *= v.y;
	Right *= v.x;
	Bottom *= v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			Rectangleとの*=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator *= ( const Rectangle& v ){
	Left *= v.Left;
	Top *= v.Top;
	Right *= v.Right;
	Bottom *= v.Bottom;
	return *this;
}
/*************************************************************************//*!
		@brief			floatとの/=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator /= ( const MofFloat v ){
	if(v == 0)
	{
		return *this;
	}
	MofFloat tmp = 1.0f  / v;
	Left *= tmp;
	Top *= tmp;
	Right *= tmp;
	Bottom *= tmp;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2との/=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator /= ( const Vector2& v ){
	Left /= ((v.x == 0) ? 1.0f : v.x);
	Top /= ((v.y == 0) ? 1.0f : v.y);
	Right /= ((v.x == 0) ? 1.0f : v.x);
	Bottom /= ((v.y == 0) ? 1.0f : v.y);
	return *this;
}
/*************************************************************************//*!
		@brief			Rectangleとの/=演算
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator /= ( const Rectangle& v ){
	Left /= ((v.Left == 0) ? 1.0f : v.Left);
	Top /= ((v.Top == 0) ? 1.0f : v.Top);
	Right /= ((v.Right == 0) ? 1.0f : v.Right);
	Bottom /= ((v.Bottom == 0) ? 1.0f : v.Bottom);
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2との+演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator + ( const Vector2& v ) const{
	return Rectangle(Left + v.x,Top + v.y,Right + v.x,Bottom + v.y);
}
/*************************************************************************//*!
		@brief			Rectangleとの+演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator + ( const Rectangle& v ) const{
	return Rectangle(Left + v.Left,Top + v.Top,Right + v.Right,Bottom + v.Bottom);
}
/*************************************************************************//*!
		@brief			Vector2との-演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator - ( const Vector2& v ) const{
	return Rectangle(Left - v.x,Top - v.y,Right - v.x,Bottom - v.y);
}
/*************************************************************************//*!
		@brief			Rectangleとの-演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator - ( const Rectangle& v ) const{
	return Rectangle(Left - v.Left,Top - v.Top,Right - v.Right,Bottom - v.Bottom);
}
/*************************************************************************//*!
		@brief			floatとの*演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator * ( const MofFloat v ) const{
	return Rectangle(Left * v,Top * v,Right * v,Bottom * v);
}
/*************************************************************************//*!
		@brief			Vector2との*演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator * ( const Vector2& v ) const{
	return Rectangle(Left * v.x,Top * v.y,Right * v.x,Bottom * v.y);
}
/*************************************************************************//*!
		@brief			Rectangleとの*演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator * ( const Rectangle& v ) const{
	return Rectangle(Left * v.Left,Top * v.Top,Right * v.Right,Bottom * v.Bottom);
}
/*************************************************************************//*!
		@brief			floatとの/演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Rectangle(Left / v,Top / v,Right / v,Bottom / v);
}
/*************************************************************************//*!
		@brief			Vector2との/演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator / ( const Vector2& v ) const{
	return Rectangle(Left / ((v.x == 0) ? 1.0f : v.x),Top / ((v.y == 0) ? 1.0f : v.y),
					Right / ((v.x == 0) ? 1.0f : v.x),Bottom / ((v.y == 0) ? 1.0f : v.y));
}
/*************************************************************************//*!
		@brief			Rectangleとの/演算
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator / ( const Rectangle& v ) const{
	return Rectangle(Left / ((v.Left == 0) ? 1.0f : v.Left),Top / ((v.Top == 0) ? 1.0f : v.Top),
					Right / ((v.Right == 0) ? 1.0f : v.Right),Bottom / ((v.Bottom == 0) ? 1.0f : v.Bottom));
}
/*************************************************************************//*!
		@brief			配列指定によるRectangleメンバへのアクセス
*//**************************************************************************/
FORCE_INLINE MofFloat& Rectangle::operator [] ( int i ){
	return (&Left)[i];
}
/*************************************************************************//*!
		@brief			配列指定によるRectangleメンバへのアクセス
*//**************************************************************************/
FORCE_INLINE const MofFloat& Rectangle::operator [] ( int i ) const{
	return (&Left)[i];
}
/*************************************************************************//*!
		@brief			==判断
*//**************************************************************************/
FORCE_INLINE bool Rectangle::operator == ( const Rectangle& v ) const{
	return Left == v.Left && Top == v.Top && Right == v.Right && Bottom == v.Bottom;
}
/*************************************************************************//*!
		@brief			!=判断
*//**************************************************************************/
FORCE_INLINE bool Rectangle::operator != ( const Rectangle& v ) const{
	return Left != v.Left || Top != v.Top || Right != v.Right || Bottom != v.Bottom;
}
//--------------------------------------------------------------------------------------------
//CRectangleUtilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector2（ポイント）が矩形の中に入っているかを判定する
		@param[in]		px			判定X位置
		@param[in]		py			判定Y位置

		@return			TRUE		矩形の中に点がある
						FALSE		矩形の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CRectangleUtilities::CollisionPoint(const Rectangle& r,const MofFloat px,const MofFloat py){
	if(px >= r.Left && px <= r.Right && py >= r.Top && py <= r.Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector2（ポイント）が矩形の中に入っているかを判定する
		@param[in]		p			判定位置

		@return			TRUE		矩形の中に点がある
						FALSE		矩形の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CRectangleUtilities::CollisionPoint(const Rectangle& r,const Vector2& p){
	if(p.x >= r.Left && p.x <= r.Right && p.y >= r.Top && p.y <= r.Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定した二つのRectangle（矩形）が接触しているかを判定する
		@param[in]		r1			判定矩形
		@param[in]		r2			判定矩形

		@return			TRUE		矩形の中に点がある
						FALSE		矩形の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CRectangleUtilities::CollisionRect(const Rectangle& r1,const Rectangle& r2){
	if(r1.Right >= r2.Left && r1.Left <= r2.Right && r1.Bottom >= r2.Top && r1.Top <= r2.Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
//--------------------------------------------------------------------------------------------
//CRectangle
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			コンストラクタ
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle() :
Rectangle() {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		l			左
		@param[in]		t			上
		@param[in]		r			右
		@param[in]		b			下

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(MofFloat l,MofFloat t,MofFloat r,MofFloat b) :
Rectangle(l,t,r,b) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		lt			左上
		@param[in]		rb			右下

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(const Vector2& lt,const Vector2& rb) :
Rectangle(lt,rb) {
}
/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		pv			座標

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(LPMofFloat pv) :
Rectangle(pv) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー矩形

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(const Rectangle& pObj) :
Rectangle(pObj) {
}
/*************************************************************************//*!
		@brief			コピーコンストラクタ
		@param[in]		pObj		コピー矩形

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(const CRectangle& pObj) :
Rectangle(pObj) {
}
/*************************************************************************//*!
		@brief			矩形拡張<br>
						Left,Topに-e、Right,Bottomに+eを行う
		@param[in]		e			拡張サイズ

		@return			None
*//**************************************************************************/
FORCE_INLINE void CRectangle::Expansion(const MofFloat e){
	Left -= e;
	Top -= e;
	Right += e;
	Bottom += e;
	return;
}
/*************************************************************************//*!
		@brief			矩形拡張<br>
						Left,Topに-ex、Right,Bottomに+eyを行う
		@param[in]		ex			X拡張サイズ
		@param[in]		ey			Y拡張サイズ

		@return			None
*//**************************************************************************/
FORCE_INLINE void CRectangle::Expansion(const MofFloat ex,const MofFloat ey){
	Left -= ex;
	Top -= ey;
	Right += ex;
	Bottom += ey;
	return;
}
/*************************************************************************//*!
		@brief			移動<br>
						矩形の幅と高さをそのままにm移動する。
		@param[in]		m			移動量
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CRectangle::Translation(const Vector2& m) {
	MofFloat w = Right - Left;
	MofFloat h = Bottom - Top;
	Left += m.x;
	Top += m.y;
	Right = Left + w;
	Bottom = Top + h;
	return;
}
/*************************************************************************//*!
		@brief			移動<br>
						矩形の幅と高さをそのままにposの位置に移動する。
		@param[in]		pos			位置
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CRectangle::SetPosition(const Vector2& pos){
	MofFloat w = Right - Left;
	MofFloat h = Bottom - Top;
	Left = pos.x;
	Top = pos.y;
	Right = Left + w;
	Bottom = Top + h;
	return;
}
/*************************************************************************//*!
		@brief			幅<br>
						矩形の幅を変更する。
		@param[in]		w			幅
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CRectangle::SetWidth(const MofFloat w) {
	Right = Left + w;
	return;
}
/*************************************************************************//*!
		@brief			高さ<br>
						矩形の高さを変更する。
		@param[in]		h			高さ
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CRectangle::SetHeight(const MofFloat h) {
	Bottom = Top + h;
	return;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector2（ポイント）が矩形の中に入っているかを判定する
		@param[in]		px			判定X位置
		@param[in]		py			判定Y位置

		@return			TRUE		矩形の中に点がある
						FALSE		矩形の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CRectangle::CollisionPoint(const MofFloat px,const MofFloat py) const {
	if(px >= Left && px <= Right && py >= Top && py <= Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したVector2（ポイント）が矩形の中に入っているかを判定する
		@param[in]		p			判定位置

		@return			TRUE		矩形の中に点がある
						FALSE		矩形の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CRectangle::CollisionPoint(const Vector2& p) const {
	if(p.x >= Left && p.x <= Right && p.y >= Top && p.y <= Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したRectangle（矩形）が接触しているかを判定する
		@param[in]		l			判定左位置
		@param[in]		t			判定上位置
		@param[in]		r			判定右位置
		@param[in]		b			判定下位置

		@return			TRUE		矩形の中に点がある
						FALSE		矩形の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CRectangle::CollisionRect(const MofFloat l,const MofFloat t,const MofFloat r,const MofFloat b) const {
	if(r >= Left && l <= Right && b >= Top && t <= Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			あたり判定<br>
						指定したRectangle（矩形）が接触しているかを判定する
		@param[in]		r			判定矩形

		@return			TRUE		矩形の中に点がある
						FALSE		矩形の範囲外
*//**************************************************************************/
FORCE_INLINE MofBool CRectangle::CollisionRect(const Rectangle& r) const {
	if(r.Right >= Left && r.Left <= Right && r.Bottom >= Top && r.Top <= Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			数値の設定
		@param[in]		l			左
		@param[in]		t			上
		@param[in]		r			右
		@param[in]		b			下

		@return			None
*//**************************************************************************/
FORCE_INLINE void CRectangle::SetValue(MofFloat l,MofFloat t,MofFloat r,MofFloat b){
	Left = l;
	Top = t;
	Right = r;
	Bottom = b;
	return;
}
/*************************************************************************//*!
		@brief			幅取得
		@param			None

		@return			幅の取得
*//**************************************************************************/
FORCE_INLINE MofFloat CRectangle::GetWidth(void) const{
	return Right - Left;
}
/*************************************************************************//*!
		@brief			高さ取得
		@param			None

		@return			高さの取得
*//**************************************************************************/
FORCE_INLINE MofFloat CRectangle::GetHeight(void) const{
	return Bottom - Top;
}
/*************************************************************************//*!
		@brief			中心取得
		@param			None

		@return			中心取得
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetCenter(void) const{
	return Vector2((Left + Right) * 0.5f,(Top + Bottom) * 0.5f);
}
/*************************************************************************//*!
		@brief			左上取得
		@param			None

		@return			左上取得
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetTopLeft(void) const{
	return Vector2(Left,Top);
}
/*************************************************************************//*!
		@brief			右上取得
		@param			None

		@return			右上取得
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetTopRight(void) const{
	return Vector2(Right,Top);
}
/*************************************************************************//*!
		@brief			左下取得
		@param			None

		@return			左下取得
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetBottomLeft(void) const{
	return Vector2(Left,Bottom);
}
/*************************************************************************//*!
		@brief			右下取得
		@param			None

		@return			右下取得
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetBottomRight(void) const{
	return Vector2(Right,Bottom);
}
/*************************************************************************//*!
		@brief			代入
*//**************************************************************************/
FORCE_INLINE CRectangle& CRectangle::operator = ( const Rectangle& v ){
	Left = v.Left;
	Right = v.Right;
	Top = v.Top;
	Bottom = v.Bottom;
	return *this;
}

//[EOF]