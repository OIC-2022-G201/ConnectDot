/*************************************************************************//*!
					
					@file	Quaternion.inl
					@brief	�N�I�[�^�j�I�����Z�֘A

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Quaternion
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Quaternion::Quaternion() :
x(0.0f) ,
y(0.0f) ,
z(0.0f) ,
w(0.0f) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z
		@param[in]		vw			W

		@return			None
*//**************************************************************************/
FORCE_INLINE Quaternion::Quaternion(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw) :
x(vx) ,
y(vy) ,
z(vz) ,
w(vw) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE Quaternion::Quaternion(LPMofFloat pv) : 
x(pv[0]) ,
y(pv[1]) ,
z(pv[2]) ,
w(pv[3]) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�N�I�[�^�j�I��

		@return			None
*//**************************************************************************/
FORCE_INLINE Quaternion::Quaternion(const Quaternion& pObj) :
x(pObj.x) ,
y(pObj.y) ,
z(pObj.z) ,
w(pObj.w) {
}
/*************************************************************************//*!
		@brief			float�L���X�g<br>
						�����̍��W��float�|�C���^�Ƃ��Ă��̂܂ܕԂ��B
*//**************************************************************************/
FORCE_INLINE Quaternion::operator LPMofFloat (){
	return (LPMofFloat)&x;
}
/*************************************************************************//*!
		@brief			+�擾
*//**************************************************************************/
FORCE_INLINE Quaternion Quaternion::operator + () const{
	return Quaternion(x,y,z,w);
}
/*************************************************************************//*!
		@brief			-�擾
*//**************************************************************************/
FORCE_INLINE Quaternion Quaternion::operator - () const{
	return Quaternion(-x,-y,-z,-w);
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Quaternion& Quaternion::operator += ( const Quaternion& v ){
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Quaternion& Quaternion::operator -= ( const Quaternion& v ){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Quaternion& Quaternion::operator *= ( const MofFloat v ){
	x *= v;
	y *= v;
	z *= v;
	w *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Quaternion�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Quaternion& Quaternion::operator *= ( const Vector3& v ){
	MofFloat tmpx = w * v.x + y * v.z - z * v.y;
	MofFloat tmpy = w * v.y + z * v.x - x * v.z;
	MofFloat tmpz = w * v.z + x * v.y - y * v.x;
	w = -(x * v.x - y * v.y - z * v.z);
	x = tmpx;
	y = tmpy;
	z = tmpz;
	return *this;
}
/*************************************************************************//*!
		@brief			Quaternion�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Quaternion& Quaternion::operator *= ( const Quaternion& v ){
	MofFloat tmpx = w * v.x + x * v.w + y * v.z - z * v.y;
	MofFloat tmpy = w * v.y + y * v.w + z * v.x - x * v.z;
	MofFloat tmpz = w * v.z + z * v.w + x * v.y - y * v.x;
	w = w * v.w - x * v.x - y * v.y - z * v.z;
	x = tmpx;
	y = tmpy;
	z = tmpz;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Quaternion& Quaternion::operator /= ( const MofFloat v ){
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
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE Quaternion Quaternion::operator + ( const Quaternion& v ) const{
	return Quaternion(x + v.x,y + v.y,z - v.z,w - v.w);
}
/*************************************************************************//*!
		@brief			-���Z
*//**************************************************************************/
FORCE_INLINE Quaternion Quaternion::operator - ( const Quaternion& v ) const{
	return Quaternion(x - v.x,y - v.y,z - v.z,w - v.w);
}
/*************************************************************************//*!
		@brief			float�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Quaternion Quaternion::operator * ( const MofFloat v ) const{
	return Quaternion(x * v,y * v,z * v,w * v);
}
/*************************************************************************//*!
		@brief			Quaternion�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Quaternion Quaternion::operator * ( const Vector3& v ) const{
	return Quaternion(w * v.x + y * v.z - z * v.y,w * v.y + z * v.x - x * v.z,
						  w * v.z + x * v.y - y * v.x,-(x * v.x - y * v.y - z * v.z));
}
/*************************************************************************//*!
		@brief			Quaternion�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Quaternion Quaternion::operator * ( const Quaternion& v ) const{
	return Quaternion(w * v.x + x * v.w + y * v.z - z * v.y,
						  w * v.y + y * v.w + z * v.x - x * v.z,
						  w * v.z + z * v.w + x * v.y - y * v.x,
						  w * v.w - x * v.x - y * v.y - z * v.z);
}
/*************************************************************************//*!
		@brief			float�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Quaternion Quaternion::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Quaternion(x / v,y / v,z / v,w / v);
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Quaternion�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE MofFloat& Quaternion::operator [] ( int i ){
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Quaternion�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE const MofFloat& Quaternion::operator [] ( int i ) const{
	return (&x)[i];
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
FORCE_INLINE bool Quaternion::operator == ( const Quaternion& v ) const{
	return x == v.x && y == v.y && z == v.z && w == v.w;
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
FORCE_INLINE bool Quaternion::operator != ( const Quaternion& v ) const{
	return x != v.x || y != v.y || z != v.z || w != v.w;
}

//--------------------------------------------------------------------------------------------
//CQuaternionUtilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�N�I�[�^�j�I���̒����𒲂ׂ�
		@param[in]		v			���ׂ�N�I�[�^�j�I��

		@return			�����N�I�[�^�j�I���̒���
*//**************************************************************************/
FORCE_INLINE MofFloat CQuaternionUtilities::Length(const Quaternion& v){
	return MOF_SQRT(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}
/*************************************************************************//*!
		@brief			�N�I�[�^�j�I���̒�����2��𒲂ׂ�
		@param[in]		v			���ׂ�N�I�[�^�j�I��

		@return			�����N�I�[�^�j�I���̒�����2��
*//**************************************************************************/
FORCE_INLINE MofFloat CQuaternionUtilities::LengthSquare(const Quaternion& v){
	return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}
/*************************************************************************//*!
		@brief			�N�I�[�^�j�I���̓��ς����߂�
		@param[in]		q1			�v�Z�N�I�[�^�j�I���P
		@param[in]		q2			�v�Z�N�I�[�^�j�I���Q

		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CQuaternionUtilities::Dot(const Quaternion& q1,const Quaternion& q2){
	return q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
}
/*************************************************************************//*!
		@brief			�P�ʃN�I�[�^�j�I�������߂�
		@param[in]		q1			�v�Z�N�I�[�^�j�I��
		@param[out]		OutQut		�o�̓N�I�[�^�j�I��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CQuaternionUtilities::Normal(const Quaternion& q1,Quaternion& OutQut){
	MofFloat d = Length(q1);
	if(d > 0)
	{
		d = 1 / d;
	}
	else
	{
		d = 0;
	}
	OutQut.x = q1.x * d;
	OutQut.y = q1.y * d;
	OutQut.z = q1.z * d;
	OutQut.w = q1.w * d;
	return;
}
/*************************************************************************//*!
		@brief			�N�I�[�^�j�I���̋t�������߂�
		@param[in]		q1			�v�Z�N�I�[�^�j�I��
		@param[out]		OutQut		�o�̓N�I�[�^�j�I��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CQuaternionUtilities::Inverse(const Quaternion& q1,Quaternion& OutQut){
	MofFloat d = q1.x * q1.x + q1.y * q1.y + q1.z * q1.z + q1.w * q1.w;
	if(d == 1)
	{
		OutQut.x = -q1.x;
		OutQut.y = -q1.y;
		OutQut.z = -q1.z;
		OutQut.w = q1.w;
	}
	else
	{
		OutQut.x = -q1.x / d;
		OutQut.y = -q1.y / d;
		OutQut.z = -q1.z / d;
		OutQut.w = q1.w / d;
	}
	return;
}
/*************************************************************************//*!
		@brief			�ߎ��N�I�[�^�j�I�������߂�
		@param[in]		q1			�v�Z�N�I�[�^�j�I��
		@param[in]		q2			�v�Z�N�I�[�^�j�I��
		@param[out]		OutQut		�o�̓N�I�[�^�j�I��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CQuaternionUtilities::Nearest(const Quaternion& q1,const Quaternion& q2,Quaternion& OutQut){
	Quaternion diff = q1 - q2;
	Quaternion sum = q1 + q2;
	if(LengthSquare(diff) < LengthSquare(sum))
	{
		OutQut = q2;
	}
	else
	{
		OutQut = -q2;
	}
	return;
}
//--------------------------------------------------------------------------------------------
//CQuaternion
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CQuaternion::CQuaternion() :
Quaternion() {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z
		@param[in]		vw			W

		@return			None
*//**************************************************************************/
FORCE_INLINE CQuaternion::CQuaternion(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw) :
Quaternion(vx,vy,vz,vw) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE CQuaternion::CQuaternion(LPMofFloat pv) : 
Quaternion(pv) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�N�I�[�^�j�I��

		@return			None
*//**************************************************************************/
FORCE_INLINE CQuaternion::CQuaternion(const Quaternion& pObj) :
Quaternion(pObj) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�N�I�[�^�j�I��

		@return			None
*//**************************************************************************/
FORCE_INLINE CQuaternion::CQuaternion(const CQuaternion& pObj) :
Quaternion(pObj) {
}
/*************************************************************************//*!
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CQuaternion::~CQuaternion(){
}
/*************************************************************************//*!
		@brief			�N�I�[�^�j�I���̒����𒲂ׂ�
		@param			None

		@return			�N�I�[�^�j�I���̒���
*//**************************************************************************/
FORCE_INLINE MofFloat CQuaternion::Length(void) const{
	return MOF_SQRT(x * x + y * y + z * z + w * w);
}
/*************************************************************************//*!
		@brief			�N�I�[�^�j�I���̒�����2��𒲂ׂ�
		@param			None

		@return			�N�I�[�^�j�I���̒�����2��
*//**************************************************************************/
FORCE_INLINE MofFloat CQuaternion::LengthSquare(void) const{
	return x * x + y * y + z * z + w * w;
}
/*************************************************************************//*!
		@brief			�N�I�[�^�j�I���̓��ς����߂�
		@param[in]		v			�v�Z�N�I�[�^�j�I��

		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CQuaternion::Dot(const Quaternion& v) const{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}
/*************************************************************************//*!
		@brief			�P�ʃN�I�[�^�j�I�������߂�
		@param[out]		OutQut		�o�̓N�I�[�^�j�I��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CQuaternion::Normal(Quaternion& OutQut) const{
	MofFloat d = Length();
	if(d > 0)
	{
		d = 1 / d;
	}
	else
	{
		d = 0;
	}
	OutQut.x = x * d;
	OutQut.y = y * d;
	OutQut.z = z * d;
	OutQut.w = w * d;
	return;
}
/*************************************************************************//*!
		@brief			�N�I�[�^�j�I���̋t�������߂�
		@param[out]		OutQut		�o�̓N�I�[�^�j�I��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CQuaternion::Inverse(Quaternion& OutQut) const{
	MofFloat d = x * x + y * y + z * z + w * w;
	if(d == 1)
	{
		OutQut.x = -x;
		OutQut.y = -y;
		OutQut.z = -z;
		OutQut.w = w;
	}
	else
	{
		OutQut.x = -x / d;
		OutQut.y = -y / d;
		OutQut.z = -z / d;
		OutQut.w = w / d;
	}
	return;
}
/*************************************************************************//*!
		@brief			�ߎ��N�I�[�^�j�I�����g�ɐݒ肷��
		@param[in]		q1			�v�Z�N�I�[�^�j�I��
		@param[in]		q2			�v�Z�N�I�[�^�j�I��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CQuaternion::Nearest(const Quaternion& q1,const Quaternion& q2){
	CQuaternion diff = q1 - q2;
	CQuaternion sum = q1 + q2;
	if(diff.LengthSquare() < sum.LengthSquare())
	{
		x = q2.x;
		y = q2.y;
		z = q2.z;
		w = q2.w;
	}
	else
	{
		x = -q2.x;
		y = -q2.y;
		z = -q2.z;
		w = -q2.w;
	}
	return;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CQuaternion& CQuaternion::operator = ( const Quaternion& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}

//[EOF]