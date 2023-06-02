/*************************************************************************//*!
					
					@file	Sphere.inl
					@brief	�����Z�֘A

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Sphere
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
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
		@brief			�R���X�g���N�^
		@param[in]		cx			�w���W
		@param[in]		cy			�x���W
		@param[in]		cz			�y���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE Sphere::Sphere(MofFloat cx,MofFloat cy,MofFloat cz,MofFloat cr) :
x(cx) ,
y(cy) ,
z(cz) ,
r(cr) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pos			���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE Sphere::Sphere(const Vector3& pos,MofFloat cr) :
x(pos.x) ,
y(pos.y) ,
z(pos.z) ,
r(cr) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE Sphere::Sphere(LPMofFloat pv) : 
x(pv[0]) ,
y(pv[1]) ,
z(pv[2]) ,
r(pv[3]) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE Sphere::Sphere(const Sphere& pObj) :
x(pObj.x) ,
y(pObj.y) ,
z(pObj.z) ,
r(pObj.r) {
}
/*************************************************************************//*!
		@brief			float�L���X�g<br>
						�����̍��W��float�|�C���^�Ƃ��Ă��̂܂ܕԂ��B
*//**************************************************************************/
FORCE_INLINE Sphere::operator LPMofFloat (){
	return (LPMofFloat)&Position;
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator += (const Vector3& v){
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator += (const Sphere& v){
	x += v.x;
	y += v.y;
	z += v.z;
	r += v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator -= (const Vector3& v){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator -= ( const Sphere& v ){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	r -= v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator *= ( const MofFloat v ){
	x *= v;
	y *= v;
	z *= v;
	r *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator *= (const Vector3& v){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			Sphere�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator *= ( const Sphere& v ){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	r *= v.r;
	return *this;
}
/*************************************************************************//*!
		@brief			Matrix44�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator *= ( const Matrix44& v ){
	CVector3 sv;
	CMatrix44Utilities::GetScaling(v, sv);
	CVector3Utilities::TransformCoord(Position, v, Position);
	r *= sv.GetMaxAbsValue();
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�/=���Z
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
		@brief			Vector3�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator /= (const Vector3& v){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	z /= ((v.z == 0) ? 1.0f : v.z);
	return *this;
}
/*************************************************************************//*!
		@brief			Sphere�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Sphere& Sphere::operator /= (const Sphere& v){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	z /= ((v.z == 0) ? 1.0f : v.z);
	r /= ((v.r == 0) ? 1.0f : v.r);
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�+���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator + ( const Vector3& v ) const{
	return Sphere(x + v.x,y + v.y,z + v.z,r);
}
/*************************************************************************//*!
		@brief			Sphere�Ƃ�+���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator + ( const Sphere& v ) const{
	return Sphere(x + v.x,y + v.y,z + v.z,r + v.r);
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�-���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator - ( const Vector3& v ) const{
	return Sphere(x - v.x,y - v.y,z - v.z,r);
}
/*************************************************************************//*!
		@brief			Sphere�Ƃ�-���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator - ( const Sphere& v ) const{
	return Sphere(x - v.x,y - v.y,z - v.z,r - v.r);
}
/*************************************************************************//*!
		@brief			float�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator * ( const MofFloat v ) const{
	return Sphere(x * v,y * v,z * v,r * v);
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator * ( const Vector3& v ) const{
	return Sphere(x * v.x,y * v.y,z * v.z,r);
}
/*************************************************************************//*!
		@brief			Matrix44�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator * ( const Matrix44& v ) const{
	Vector3Impl op;
	CVector3 sv;
	CMatrix44Utilities::GetScaling(v, sv);
	CVector3Utilities::TransformCoord(Position, v, op);
	return Sphere(op.x, op.y, op.z, r * sv.GetMaxAbsValue());
}
/*************************************************************************//*!
		@brief			Sphere�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator * ( const Sphere& v ) const{
	return Sphere(x * v.x,y * v.y,z * v.z,r * v.r);
}
/*************************************************************************//*!
		@brief			float�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Sphere(x / v,y / v,z / v,r / v);
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator / ( const Vector3& v ) const{
	return Sphere(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),z / ((v.z == 0) ? 1.0f : v.z),r);
}
/*************************************************************************//*!
		@brief			Sphere�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Sphere Sphere::operator / ( const Sphere& v ) const{
	return Sphere(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),z / ((v.z == 0) ? 1.0f : v.z),r / ((v.r == 0) ? 1.0f : v.r));
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Sphere�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE MofFloat& Sphere::operator [] ( int i ){
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Sphere�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE const MofFloat& Sphere::operator [] ( int i ) const{
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
FORCE_INLINE bool Sphere::operator == ( const Sphere& v ) const{
	return x == v.x && y == v.y && z == v.z && r == v.r;
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
FORCE_INLINE bool Sphere::operator != ( const Sphere& v ) const{
	return x != v.x || y != v.y || z != v.z || r != v.r;
}
//--------------------------------------------------------------------------------------------
//CSphereUtilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Vector3�i�|�C���g�j�����̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		px			����X�ʒu
		@param[in]		py			����Y�ʒu
		@param[in]		pz			����Z�ʒu

		@return			TRUE		���̒��ɓ_������
						FALSE		���͈̔͊O
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
		@brief			�����蔻��<br>
						�w�肵��Vector3�i�|�C���g�j�����̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		p			����ʒu

		@return			TRUE		���̒��ɓ_������
						FALSE		���͈̔͊O
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
		@brief			�����蔻��<br>
						�w�肵�����Sphere�i���j���ڐG���Ă��邩�𔻒肷��
		@param[in]		r1			���苅
		@param[in]		r2			���苅
		
		@return			TRUE		�ڐG
						FALSE		�͈͊O
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
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere() :
Sphere() {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		cx			�w���W
		@param[in]		cy			�x���W
		@param[in]		cz			�y���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(MofFloat cx,MofFloat cy,MofFloat cz,MofFloat cr) :
Sphere(cx,cy,cz,cr) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pos			���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(const Vector3& pos,MofFloat cr) :
Sphere(pos,cr) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(LPMofFloat pv) :
Sphere(pv) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[��

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(const Sphere& pObj) :
Sphere(pObj) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[��

		@return			None
*//**************************************************************************/
FORCE_INLINE CSphere::CSphere(const CSphere& pObj) :
Sphere(pObj) {
}
/*************************************************************************//*!
		@brief			�ړ�<br>
						m�ړ�����B
		@param[in]		m			�ړ���
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CSphere::Translation(const Vector3& m) {
	x += m.x;
	y += m.y;
	z += m.z;
	return;
}
/*************************************************************************//*!
		@brief			�ړ�<br>
						pos�̈ʒu�Ɉړ�����B
		@param[in]		pos			�ʒu
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CSphere::SetPosition(const Vector3& pos){
	x = pos.x;
	y = pos.y;
	z = pos.z;
	return;
}
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Vector3�i�|�C���g�j�����̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		px			����X�ʒu
		@param[in]		py			����Y�ʒu
		@param[in]		pz			����Z�ʒu

		@return			TRUE		���̒��ɓ_������
						FALSE		���͈̔͊O
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
		@brief			�����蔻��<br>
						�w�肵��Vector3�i�|�C���g�j�����̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		p			����ʒu

		@return			TRUE		���̒��ɓ_������
						FALSE		���͈̔͊O
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
		@brief			�����蔻��<br>
						�w�肵��Sphere�i���j���ڐG���Ă��邩�𔻒肷��
		@param[in]		cx			����w�ʒu
		@param[in]		cy			����x�ʒu
		@param[in]		cz			����y�ʒu
		@param[in]		cr			���蔼�a
		
		@return			TRUE		�ڐG
						FALSE		�͈͊O
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
		@brief			�����蔻��<br>
						�w�肵��Sphere�i���j���ڐG���Ă��邩�𔻒肷��
		@param[in]		c			���苅
		
		@return			TRUE		�ڐG
						FALSE		�͈͊O
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
		@brief			���l�̐ݒ�
		@param[in]		cx			�w���W
		@param[in]		cy			�x���W
		@param[in]		cz			�y���W
		@param[in]		cr			���a

		@return			None
*//**************************************************************************/
FORCE_INLINE void CSphere::SetValue(MofFloat cx,MofFloat cy,MofFloat cz,MofFloat cr){
	x = cx;
	y = cy;
	z = cz;
	r = cr;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CSphere& CSphere::operator = ( const Sphere& v ){
	Position = v.Position;
	r = v.r;
	return *this;
}

//[EOF]