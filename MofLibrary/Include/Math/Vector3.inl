/*************************************************************************//*!
					
					@file	Vector3.inl
					@brief	3D�x�N�g�����Z�֘A

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Vector3
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector3::Vector3(){
	x =	0.0f;
	y =	0.0f;
	z =	0.0f;
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
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
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector3::Vector3(LPMofFloat pv){
	x = pv[0];
	y = pv[1];
	z = pv[2];
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector3::Vector3(const Vector3& pObj){
	x = pObj.x;
	y = pObj.y;
	z = pObj.z;
}
/*************************************************************************//*!
		@brief			float�L���X�g<br>
						�����̍��W��float�|�C���^�Ƃ��Ă��̂܂ܕԂ��B
*//**************************************************************************/
FORCE_INLINE Vector3::operator LPMofFloat (){
	return (LPMofFloat)&x;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator = ( const Vector3Impl& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator = ( const Vector2Impl& v ){
	x = v.x;
	y = v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			+�擾
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator + () const{
	return Vector3(x,y,z);
}
/*************************************************************************//*!
		@brief			-�擾
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator - () const{
	return Vector3(-x,-y,-z);
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator += ( const Vector3Impl& v ){
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator -= ( const Vector3Impl& v ){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator *= ( const MofFloat v ){
	x *= v;
	y *= v;
	z *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator *= ( const Vector3Impl& v ){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�/=���Z
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
		@brief			Vector3�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Vector3& Vector3::operator /= ( const Vector3Impl& v ){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	z /= ((v.z == 0) ? 1.0f : v.z);
	return *this;
}
/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator + ( const Vector3Impl& v ) const{
	return Vector3(x + v.x,y + v.y,z + v.z);
}
/*************************************************************************//*!
		@brief			-���Z
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator - ( const Vector3Impl& v ) const{
	return Vector3(x - v.x,y - v.y,z - v.z);
}
/*************************************************************************//*!
		@brief			float�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator * ( const MofFloat v ) const{
	return Vector3(x * v,y * v,z * v);
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator * ( const Vector3Impl& v ) const{
	return Vector3(x * v.x,y * v.y,z * v.z);
}
/*************************************************************************//*!
		@brief			float�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Vector3(x / v,y / v,z / v);
}
/*************************************************************************//*!
		@brief			Vector3�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Vector3 Vector3::operator / ( const Vector3Impl& v ) const{
	return Vector3(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),z / ((v.z == 0) ? 1.0f : v.z));
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Vector3�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE MofFloat& Vector3::operator [] ( int i ){
	return fv[i];
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Vector3�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE const MofFloat& Vector3::operator [] ( int i ) const{
	return fv[i];
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
FORCE_INLINE bool Vector3::operator == ( const Vector3Impl& v ) const{
	return x == v.x && y == v.y && z == v.z;
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
FORCE_INLINE bool Vector3::operator != ( const Vector3Impl& v ) const{
	return x != v.x || y != v.y || z != v.z;
}

/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE Vector3 operator + (const Vector3Impl& v1, const Vector3Impl& v2){
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE Vector3 operator - (const Vector3Impl& v1, const Vector3Impl& v2){
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
//--------------------------------------------------------------------------------------------
//CVector3Utilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�x�N�g���̒����𒲂ׂ�
		@param[in]		v			���ׂ�x�N�g��

		@return			�����x�N�g���̒���
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3Utilities::Length(const Vector3Impl& v){
	return MOF_SQRT(v.x * v.x + v.y * v.y + v.z * v.z);
}
/*************************************************************************//*!
		@brief			�x�N�g���̒�����2��𒲂ׂ�
		@param[in]		v			���ׂ�x�N�g��

		@return			�����x�N�g���̒�����2��
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3Utilities::LengthSquare(const Vector3Impl& v){
	return v.x * v.x + v.y * v.y + v.z * v.z;
}
/*************************************************************************//*!
		@brief			�x�N�g���Ԃ̋����𒲂ׂ�
		@param[in]		v1			���ׂ�x�N�g��
		@param[in]		v2			���ׂ�x�N�g��

		@return			�����x�N�g���̒���
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3Utilities::Distance(const Vector3Impl& v1, const Vector3Impl& v2) {
	float svx = v1.x - v2.x;
	float svy = v1.y - v2.y;
	float svz = v1.z - v2.z;
	return MOF_SQRT(svx * svx + svy * svy + svz * svz);
}
/*************************************************************************//*!
		@brief			�x�N�g���̓��ς����߂�
		@param[in]		v1			�v�Z�x�N�g���P
		@param[in]		v2			�v�Z�x�N�g���Q

		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3Utilities::Dot(const Vector3Impl& v1,const Vector3Impl& v2){
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
/*************************************************************************//*!
		@brief			�x�N�g���̓��ς����̃x�N�g���̂Ȃ��p�x�����W�A���P�ʂŋ��߂�
		@param[in]		v1			�v�Z�x�N�g���P
		@param[in]		v2			�v�Z�x�N�g���Q

		@return			�p�x
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
		@brief			�P�ʃx�N�g�������߂�
		@param[in]		v1			�v�Z�x�N�g��
		@param[out]		OutVec		�o�̓x�N�g��

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
		@brief			�x�N�g���̊O�ς����߂�
		@param[in]		v1			�v�Z�x�N�g���P
		@param[in]		v2			�v�Z�x�N�g���Q
		@param[out]		OutVec		�o�̓x�N�g��

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
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3() :
Vector3() {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3(MofFloat vx,MofFloat vy,MofFloat vz) :
Vector3(vx,vy,vz) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3(LPMofFloat pv) : 
Vector3(pv) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3(const Vector3& pObj) :
Vector3(pObj) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::CVector3(const CVector3& pObj) :
Vector3(pObj) {
}
/*************************************************************************//*!
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector3::~CVector3(){
}
/*************************************************************************//*!
		@brief			�x�N�g���̒����𒲂ׂ�
		@param			None

		@return			�x�N�g���̒���
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::Length(void) const{
	return MOF_SQRT(x * x + y * y + z * z);
}
/*************************************************************************//*!
		@brief			�x�N�g���̒�����2��𒲂ׂ�
		@param			None

		@return			�x�N�g���̒�����2��
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::LengthSquare(void) const{
	return x * x + y * y + z * z;
}
/*************************************************************************//*!
		@brief			�x�N�g���̓��ς����߂�
		@param[in]		v			�v�Z�x�N�g��

		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::Dot(const Vector3& v) const{
	return x * v.x + y * v.y + z * v.z;
}
/*************************************************************************//*!
		@brief			�x�N�g���̓��ς����̃x�N�g���̂Ȃ��p�x�����W�A���P�ʂŋ��߂�
		@param[in]		v			�v�Z�x�N�g��

		@return			�p�x
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
		@brief			�P�ʃx�N�g�������߂�
		@param[out]		OutVec		�o�̓x�N�g��

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
		@brief			�x�N�g���̊O�ς����߂�
		@param[in]		v			�v�Z�x�N�g��
		@param[out]		OutVec		�o�̓x�N�g��

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
		@brief			�l���Βl�ɂ���
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
		@brief			�l�̃N���b�s���O
		@param[in]		l			�ŏ��l
		@param[in]		h			�ő�l

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3::Cliping(const MofFloat l,const MofFloat h){
	x = MOF_CLIPING(x,l,h);
	y = MOF_CLIPING(y,l,h);
	z = MOF_CLIPING(z,l,h);
	return;
}
/*************************************************************************//*!
		@brief			�l�̃N���b�s���O
		@param[in]		l			�ŏ��l
		@param[in]		h			�ő�l

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector3::Cliping(const Vector3& l,const Vector3& h){
	x = MOF_CLIPING(x,l.x,h.x);
	y = MOF_CLIPING(y,l.y,h.y);
	z = MOF_CLIPING(z,l.z,h.z);
	return;
}
/*************************************************************************//*!
		@brief			���l�̐ݒ�
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
		@brief			�x�N�g���̑傫����ݒ�
		@param[in]		l			�傫��

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
		@brief			�ő�̐��l�̎擾
		@param			None

		@return			X,Y,Z�̍ő�l
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::GetMaxValue(void) const {
	MofFloat m = MOF_MAX(x,y);
	return MOF_MAX(z,m);
}
/*************************************************************************//*!
		@brief			��Βl�̍ő�̐��l�̎擾
		@param			None

		@return			X,Y,Z�̐�Βl�̍ő�l
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::GetMaxAbsValue(void) const {
	MofFloat m = MOF_MAX(MOF_ABS(x),MOF_ABS(y));
	return MOF_MAX(MOF_ABS(z),m);
}
/*************************************************************************//*!
		@brief			�Œ�̐��l�̎擾
		@param			None

		@return			X,Y,Z�̍ŏ��l
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::GetMinValue(void) const {
	MofFloat m = MOF_MIN(x,y);
	return MOF_MIN(z,m);
}
/*************************************************************************//*!
		@brief			��Βl�̍Œ�̐��l�̎擾
		@param			None

		@return			X,Y,Z�̐�Βl�̍ŏ��l
*//**************************************************************************/
FORCE_INLINE MofFloat CVector3::GetMinAbsValue(void) const {
	MofFloat m = MOF_MIN(MOF_ABS(x),MOF_ABS(y));
	return MOF_MIN(MOF_ABS(z),m);
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CVector3& CVector3::operator = (const Vector2Impl& v) {
	x = v.x;
	y = v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CVector3& CVector3::operator = (const Vector3Impl& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CVector3& CVector3::operator = ( const Vector3& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

//[EOF]