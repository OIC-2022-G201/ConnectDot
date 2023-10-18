/*************************************************************************//*!
					
					@file	Capsule.inl
					@brief	�J�v�Z�����Z�֘A

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Capsule
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
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
		@brief			�R���X�g���N�^
		@param[in]		cx			�w���W
		@param[in]		cy			�x���W
		@param[in]		cz			�y���W
		@param[in]		cr			���a
		@param[in]		ch			����

		@return			None
*//**************************************************************************/
FORCE_INLINE Capsule::Capsule(MofFloat cx, MofFloat cy, MofFloat cz, MofFloat cr, MofFloat ch) :
Position(cx,cy,cz) ,
Angle() ,
r(cr) ,
h(ch) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pos			���W
		@param[in]		ang			����
		@param[in]		cr			���a
		@param[in]		ch			����

		@return			None
*//**************************************************************************/
FORCE_INLINE Capsule::Capsule(const Vector3& pos, const Vector3& ang, MofFloat cr, MofFloat ch) :
Position(pos),
Angle(ang),
r(cr) ,
h(ch) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE Capsule::Capsule(LPMofFloat pv) :
Position(pv[0], pv[1], pv[2]),
Angle(pv[3],pv[4],pv[5]),
r(pv[6]),
h(pv[7]) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE Capsule::Capsule(const Capsule& pObj) :
Position(pObj.Position) ,
Angle(pObj.Angle) ,
r(pObj.r) ,
h(pObj.h) {
}
/*************************************************************************//*!
		@brief			float�L���X�g<br>
						�����̍��W��float�|�C���^�Ƃ��Ă��̂܂ܕԂ��B
*//**************************************************************************/
FORCE_INLINE Capsule::operator LPMofFloat (){
	return (LPMofFloat)&Position.x;
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator += (const Vector3& v){
	Position.x += v.x;
	Position.y += v.y;
	Position.z += v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			+=���Z
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
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator -= (const Vector3& v){
	Position.x -= v.x;
	Position.y -= v.y;
	Position.z -= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
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
		@brief			float�Ƃ�*=���Z
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
		@brief			Vector3�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator *= (const Vector3& v){
	Position.x *= v.x;
	Position.y *= v.y;
	Position.z *= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			Capsule�Ƃ�*=���Z
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
		@brief			float�Ƃ�/=���Z
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
		@brief			Vector3�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Capsule& Capsule::operator /= (const Vector3& v){
	Position.x /= ((v.x == 0) ? 1.0f : v.x);
	Position.y /= ((v.y == 0) ? 1.0f : v.y);
	Position.z /= ((v.z == 0) ? 1.0f : v.z);
	return *this;
}
/*************************************************************************//*!
		@brief			Capsule�Ƃ�/=���Z
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
		@brief			Vector3�Ƃ�+���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator + ( const Vector3& v ) const{
	return Capsule(Position + v,Angle, r, h);
}
/*************************************************************************//*!
		@brief			Capsule�Ƃ�+���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator + ( const Capsule& v ) const{
	return Capsule(Position + v.Position, Angle + v.Angle, r + v.r, h + v.h);
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�-���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator - ( const Vector3& v ) const{
	return Capsule(Position - v, Angle, r, h);
}
/*************************************************************************//*!
		@brief			Capsule�Ƃ�-���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator - ( const Capsule& v ) const{
	return Capsule(Position - v.Position, Angle - v.Angle, r - v.r, h - v.h);
}
/*************************************************************************//*!
		@brief			float�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator * ( const MofFloat v ) const{
	return Capsule(Position * v, Angle, r * v, h * v);
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator * ( const Vector3& v ) const{
	return Capsule(Position * v, Angle, r, h);
}
/*************************************************************************//*!
		@brief			Capsule�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator * ( const Capsule& v ) const{
	return Capsule(Position * v.Position, Angle * v.Angle, r * v.r, h * v.h);
}
/*************************************************************************//*!
		@brief			float�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Capsule(Position / v, Angle, r / v, h / v);
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator / ( const Vector3& v ) const{
	return Capsule(Position / v, Angle, r, h);
}
/*************************************************************************//*!
		@brief			Capsule�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Capsule Capsule::operator / ( const Capsule& v ) const{
	return Capsule(Position / v.Position, Angle / v.Angle, r / ((v.r == 0) ? 1.0f : v.r), h / ((v.h == 0) ? 1.0f : v.h));
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Capsule�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE MofFloat& Capsule::operator [] ( int i ){
	return (&Position.x)[i];
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Capsule�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE const MofFloat& Capsule::operator [] ( int i ) const{
	return (&Position.x)[i];
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
FORCE_INLINE bool Capsule::operator == ( const Capsule& v ) const{
	return Position.x == v.Position.x && Position.y == v.Position.y && Position.z == v.Position.z &&
		Angle.x == v.Angle.x && Angle.y == v.Angle.y && Angle.z == v.Angle.z && r == v.r && h == v.h;
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
FORCE_INLINE bool Capsule::operator != ( const Capsule& v ) const{
	return Position.x != v.Position.x || Position.y != v.Position.y || Position.z != v.Position.z ||
		Angle.x != v.Angle.x || Angle.y != v.Angle.y || Angle.z != v.Angle.z || r != v.r || h != v.h;
}
//--------------------------------------------------------------------------------------------
//CCapsule
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule() :
Capsule() {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		cx			�w���W
		@param[in]		cy			�x���W
		@param[in]		cz			�y���W
		@param[in]		cr			���a
		@param[in]		ch			����

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(MofFloat cx, MofFloat cy, MofFloat cz, MofFloat cr, MofFloat ch) :
Capsule(cx,cy,cz,cr,ch) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pos			���W
		@param[in]		ang			����
		@param[in]		cr			���a
		@param[in]		ch			����

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(const Vector3& pos, const Vector3& ang, MofFloat cr, MofFloat ch) :
Capsule(pos, ang, cr, ch) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(LPMofFloat pv) :
Capsule(pv) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�J�v�Z��

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(const Capsule& pObj) :
Capsule(pObj) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�J�v�Z��

		@return			None
*//**************************************************************************/
FORCE_INLINE CCapsule::CCapsule(const CCapsule& pObj) :
Capsule(pObj) {
}
/*************************************************************************//*!
		@brief			�ړ�<br>
						m�ړ�����B
		@param[in]		m			�ړ���
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CCapsule::Translation(const Vector3& m) {
	Position += m;
	return;
}
/*************************************************************************//*!
		@brief			�ړ�<br>
						pos�̈ʒu�Ɉړ�����B
		@param[in]		pos			�ʒu
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CCapsule::SetPosition(const Vector3& pos){
	Position = pos;
	return;
}
/*************************************************************************//*!
		@brief			���l�̐ݒ�
		@param[in]		cx			�w���W
		@param[in]		cy			�x���W
		@param[in]		cz			�y���W
		@param[in]		ax			�w�p�x
		@param[in]		ay			�x�p�x
		@param[in]		az			�y�p�x
		@param[in]		cr			���a
		@param[in]		ch			����

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
		@brief			���
*//**************************************************************************/
FORCE_INLINE CCapsule& CCapsule::operator = ( const Capsule& v ){
	Position = v.Position;
	r = v.r;
	h = v.h;
	return *this;
}

//[EOF]