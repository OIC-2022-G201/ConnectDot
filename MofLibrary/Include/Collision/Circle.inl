/*************************************************************************//*!
					
					@file	Circle.inl
					@brief	�~���Z�֘A

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Circle
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle() :
x(0.0f) ,
y(0.0f) ,
r(0.0f) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		cx			�w���W
		@param[in]		cy			�x���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle(MofFloat cx,MofFloat cy,MofFloat cr) :
x(cx) ,
y(cy) ,
r(cr) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pos			���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle(const Vector2& pos,MofFloat cr) :
x(pos.x) ,
y(pos.y) ,
r(cr) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle(LPMofFloat pv) : 
x(pv[0]) ,
y(pv[1]) ,
r(pv[2]) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE Circle::Circle(const Circle& pObj) :
x(pObj.x) ,
y(pObj.y) ,
r(pObj.r) {
}
/*************************************************************************//*!
		@brief			float�L���X�g<br>
						�����̍��W��float�|�C���^�Ƃ��Ă��̂܂ܕԂ��B
*//**************************************************************************/
FORCE_INLINE Circle::operator LPMofFloat (){
	return (LPMofFloat)&x;
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator += ( const Vector2& v ){
	x += v.x;
	y += v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator += ( const Circle& v ){
	x += v.x;
	y += v.y;
	r += v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator -= ( const Vector2& v ){
	x -= v.x;
	y -= v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator -= ( const Circle& v ){
	x -= v.x;
	y -= v.y;
	r -= v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator *= ( const MofFloat v ){
	x *= x;
	y *= y;
	r *= r;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator *= ( const Vector2& v ){
	x *= v.x;
	y *= v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			Circle�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator *= ( const Circle& v ){
	x *= v.x;
	y *= v.y;
	r *= v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�/=���Z
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
		@brief			Vector2�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator /= ( const Vector2& v ){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	return *this;
}
/*************************************************************************//*!
		@brief			Circle�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Circle& Circle::operator /= ( const Circle& v ){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	r /= ((v.r == 0) ? 1.0f : v.r);
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�+���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator + ( const Vector2& v ) const{
	return Circle(x + v.x,y + v.y,r);
}
/*************************************************************************//*!
		@brief			Circle�Ƃ�+���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator + ( const Circle& v ) const{
	return Circle(x + v.x,y + v.y,r + v.r);
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�-���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator - ( const Vector2& v ) const{
	return Circle(x - v.x,y - v.y,r);
}
/*************************************************************************//*!
		@brief			Circle�Ƃ�-���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator - ( const Circle& v ) const{
	return Circle(x - v.x,y - v.y,r - v.r);
}
/*************************************************************************//*!
		@brief			float�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator * ( const MofFloat v ) const{
	return Circle(x * v,y * v,r * v);
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator * ( const Vector2& v ) const{
	return Circle(x * v.x,y * v.y,r);
}
/*************************************************************************//*!
		@brief			Circle�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator * ( const Circle& v ) const{
	return Circle(x * v.x,y * v.y,r * v.r);
}
/*************************************************************************//*!
		@brief			float�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Circle(x / v,y / v,r / v);
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator / ( const Vector2& v ) const{
	return Circle(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),r);
}
/*************************************************************************//*!
		@brief			Circle�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Circle Circle::operator / ( const Circle& v ) const{
	return Circle(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),r / ((v.r == 0) ? 1.0f : v.r));
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Circle�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE MofFloat& Circle::operator [] ( int i ){
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Circle�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE const MofFloat& Circle::operator [] ( int i ) const{
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
FORCE_INLINE bool Circle::operator == ( const Circle& v ) const{
	return x == v.x && y == v.y && r == v.r;
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
FORCE_INLINE bool Circle::operator != ( const Circle& v ) const{
	return x != v.x || y != v.y || r != v.r;
}
//--------------------------------------------------------------------------------------------
//CCircleUtilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Vector2�i�|�C���g�j���~�̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		px			����X�ʒu
		@param[in]		py			����Y�ʒu

		@return			TRUE		�~�̒��ɓ_������
						FALSE		�~�͈̔͊O
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
		@brief			�����蔻��<br>
						�w�肵��Vector2�i�|�C���g�j���~�̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		p			����ʒu

		@return			TRUE		�~�̒��ɓ_������
						FALSE		�~�͈̔͊O
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
		@brief			�����蔻��<br>
						�w�肵�����Circle�i�~�j���ڐG���Ă��邩�𔻒肷��
		@param[in]		r1			����~
		@param[in]		r2			����~

		@return			TRUE		�~�̒��ɓ_������
						FALSE		�~�͈̔͊O
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
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle() :
Circle() {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		cx			�w���W
		@param[in]		cy			�x���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(MofFloat cx,MofFloat cy,MofFloat cr) :
Circle(cx,cy,cr) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pos			���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(const Vector2& pos,MofFloat cr) :
Circle(pos,cr) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(LPMofFloat pv) :
Circle(pv) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�~

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(const Circle& pObj) :
Circle(pObj) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�~

		@return			None
*//**************************************************************************/
FORCE_INLINE CCircle::CCircle(const CCircle& pObj) :
Circle(pObj) {
}
/*************************************************************************//*!
		@brief			�ړ�<br>
						m�ړ�����B
		@param[in]		m			�ړ���
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CCircle::Translation(const Vector2& m) {
	x += m.x;
	y += m.y;
	return;
}
/*************************************************************************//*!
		@brief			�ړ�<br>
						pos�̈ʒu�Ɉړ�����B
		@param[in]		pos			�ʒu
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CCircle::SetPosition(const Vector2& pos){
	x = pos.x;
	y = pos.y;
	return;
}
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Vector2�i�|�C���g�j���~�̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		px			����X�ʒu
		@param[in]		py			����Y�ʒu

		@return			TRUE		�~�̒��ɓ_������
						FALSE		�~�͈̔͊O
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
		@brief			�����蔻��<br>
						�w�肵��Vector2�i�|�C���g�j���~�̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		p			����ʒu

		@return			TRUE		�~�̒��ɓ_������
						FALSE		�~�͈̔͊O
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
		@brief			�����蔻��<br>
						�w�肵��Circle�i�~�j���ڐG���Ă��邩�𔻒肷��
		@param[in]		cx			����w�ʒu
		@param[in]		cy			����x�ʒu
		@param[in]		cr			���蔼�a

		@return			TRUE		�~�̒��ɓ_������
						FALSE		�~�͈̔͊O
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
		@brief			�����蔻��<br>
						�w�肵��Circle�i�~�j���ڐG���Ă��邩�𔻒肷��
		@param[in]		c			����~

		@return			TRUE		�~�̒��ɓ_������
						FALSE		�~�͈̔͊O
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
		@brief			���l�̐ݒ�
		@param[in]		cx			�w���W
		@param[in]		cy			�x���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE void CCircle::SetValue(MofFloat cx,MofFloat cy,MofFloat cr){
	x = cx;
	y = cy;
	r = cr;
	return;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CCircle& CCircle::operator = ( const Circle& v ){
	x = v.x;
	y = v.y;
	r = v.r;
	return *this;
}

//[EOF]