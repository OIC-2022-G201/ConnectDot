/*************************************************************************//*!
					
					@file	Vector4.inl
					@brief	4D�x�N�g�����Z�֘A

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Vector4
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector4::Vector4(){
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z
		@param[in]		vw			W

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector4::Vector4(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw){
	x = vx;
	y = vy;
	z = vz;
	w = vw;
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector4::Vector4(LPMofFloat pv){
	x = pv[0];
	y = pv[1];
	z = pv[2];
	w = pv[3];
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE Vector4::Vector4(const Vector4& pObj){
	x = pObj.x;
	y = pObj.y;
	z = pObj.z;
	w = pObj.w;
}
/*************************************************************************//*!
		@brief			float�L���X�g<br>
						�����̍��W��float�|�C���^�Ƃ��Ă��̂܂ܕԂ��B
*//**************************************************************************/
FORCE_INLINE Vector4::operator LPMofFloat (){
	return (LPMofFloat)&x;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator = ( const Vector4Impl& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator = ( const Vector2Impl& v ){
	x = v.x;
	y = v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator = ( const Vector3Impl& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			+�擾
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator + () const{
	return Vector4(x,y,z,w);
}
/*************************************************************************//*!
		@brief			-�擾
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator - () const{
	return Vector4(-x,-y,-z,-w);
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator += ( const Vector4Impl& v ){
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator -= ( const Vector4Impl& v ){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator *= ( const MofFloat v ){
	x *= v;
	y *= v;
	z *= v;
	w *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector4�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator *= ( const Vector4Impl& v ){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator /= ( const MofFloat v ){
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
		@brief			Vector4�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Vector4& Vector4::operator /= ( const Vector4Impl& v ){
	x /= ((v.x == 0) ? 1.0f : v.x);
	y /= ((v.y == 0) ? 1.0f : v.y);
	z /= ((v.z == 0) ? 1.0f : v.z);
	w /= ((v.w == 0) ? 1.0f : v.w);
	return *this;
}
/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator + ( const Vector4Impl& v ) const{
	return Vector4(x + v.x,y + v.y,z + v.z,w + v.w);
}
/*************************************************************************//*!
		@brief			-���Z
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator - ( const Vector4Impl& v ) const{
	return Vector4(x - v.x,y - v.y,z - v.z,w - v.w);
}
/*************************************************************************//*!
		@brief			float�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator * ( const MofFloat v ) const{
	return Vector4(x * v,y * v,z * v,w * v);
}
/*************************************************************************//*!
		@brief			Vector4�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator * ( const Vector4Impl& v ) const{
	return Vector4(x * v.x,y * v.y,z * v.z,w * v.w);
}
/*************************************************************************//*!
		@brief			float�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Vector4(x / v,y / v,z / v,w / v);
}
/*************************************************************************//*!
		@brief			Vector4�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Vector4 Vector4::operator / ( const Vector4Impl& v ) const{
	return Vector4(x / ((v.x == 0) ? 1.0f : v.x),y / ((v.y == 0) ? 1.0f : v.y),z / ((v.z == 0) ? 1.0f : v.z),w / ((v.w == 0) ? 1.0f : v.w));
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Vector4�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE MofFloat& Vector4::operator [] ( int i ){
	return fv[i];
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Vector4�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE const MofFloat& Vector4::operator [] ( int i ) const{
	return fv[i];
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
FORCE_INLINE bool Vector4::operator == ( const Vector4Impl& v ) const{
	return x == v.x && y == v.y && z == v.z && w == v.w;
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
FORCE_INLINE bool Vector4::operator != ( const Vector4Impl& v ) const{
	return x != v.x || y != v.y || z != v.z || w != v.w;
}


/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE Vector4 operator + (const Vector4Impl& v1, const Vector4Impl& v2){
	return Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}
/*************************************************************************//*!
		@brief			+���Z
*//**************************************************************************/
FORCE_INLINE Vector4 operator - (const Vector4Impl& v1, const Vector4Impl& v2){
	return Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

//--------------------------------------------------------------------------------------------
//CVector4Utilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�x�N�g���̒����𒲂ׂ�
		@param[in]		v			���ׂ�x�N�g��

		@return			�����x�N�g���̒���
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4Utilities::Length(const Vector4Impl& v){
	return MOF_SQRT(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}
/*************************************************************************//*!
		@brief			�x�N�g���̒�����2��𒲂ׂ�
		@param[in]		v			���ׂ�x�N�g��

		@return			�����x�N�g���̒�����2��
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4Utilities::LengthSquare(const Vector4Impl& v){
	return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}
/*************************************************************************//*!
		@brief			�x�N�g���̓��ς����߂�
		@param[in]		v1			�v�Z�x�N�g���P
		@param[in]		v2			�v�Z�x�N�g���Q

		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4Utilities::Dot(const Vector4Impl& v1,const Vector4Impl& v2){
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}
/*************************************************************************//*!
		@brief			�P�ʃx�N�g�������߂�
		@param[in]		v1			�v�Z�x�N�g��
		@param[out]		OutVec		�o�̓x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4Utilities::Normal(const Vector4Impl& v1,Vector4Impl& OutVec){
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
	OutVec.w = v1.w * d;
	return;
}
/*************************************************************************//*!
		@brief			U32�J���[����ϊ�
		@param[in]		col			�F
		@param[out]		OutVec		�o�̓x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4Utilities::SetU32Color(MofU32 col,Vector4Impl& OutVec){
	OutVec.x = MOF_GetRed(col) / 255.0f;
	OutVec.y = MOF_GetGreen(col) / 255.0f;
	OutVec.z = MOF_GetBlue(col) / 255.0f;
	OutVec.w = MOF_GetAlpha(col) / 255.0f;
	return;
}
/*************************************************************************//*!
		@brief			U32�J���[�ւ̕ϊ�
		@param[in]		v			�ϊ��x�N�g��

		@return			U32�J���[
*//**************************************************************************/
FORCE_INLINE MofU32 CVector4Utilities::ToU32Color(const Vector4Impl& v){
	MofU8 r = MOF_FToColor(v.x);
	MofU8 g = MOF_FToColor(v.y);
	MofU8 b = MOF_FToColor(v.z);
	MofU8 a = MOF_FToColor(v.w);
	return MOF_ARGB(a,r,g,b);
}

//--------------------------------------------------------------------------------------------
//CVector4
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4() :
Vector4() {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z
		@param[in]		vw			W

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw) :
Vector4(vx,vy,vz,vw) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4(LPMofFloat pv) : 
Vector4(pv) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4(const Vector4& pObj) :
Vector4(pObj) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::CVector4(const CVector4& pObj) :
Vector4(pObj) {
}
/*************************************************************************//*!
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CVector4::~CVector4(){
}
/*************************************************************************//*!
		@brief			�x�N�g���̒����𒲂ׂ�
		@param			None

		@return			�x�N�g���̒���
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::Length(void) const{
	return MOF_SQRT(x * x + y * y + z * z + w * w);
}
/*************************************************************************//*!
		@brief			�x�N�g���̒�����2��𒲂ׂ�
		@param			None

		@return			�x�N�g���̒�����2��
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::LengthSquare(void) const{
	return x * x + y * y + z * z + w * w;
}
/*************************************************************************//*!
		@brief			�x�N�g���̓��ς����߂�
		@param[in]		v			�v�Z�x�N�g��

		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::Dot(const Vector4& v) const{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}
/*************************************************************************//*!
		@brief			�P�ʃx�N�g�������߂�
		@param[out]		OutVec		�o�̓x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::Normal(Vector4& OutVec) const{
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
	OutVec.w = w * d;
	return;
}
/*************************************************************************//*!
		@brief			U32�J���[����ϊ�
		@param[in]		col			�F

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::SetU32Color(MofU32 col){
	x = MOF_GetRed(col) / 255.0f;
	y = MOF_GetGreen(col) / 255.0f;
	z = MOF_GetBlue(col) / 255.0f;
	w = MOF_GetAlpha(col) / 255.0f;
	return;
}
/*************************************************************************//*!
		@brief			U32�J���[�ւ̕ϊ�
		@param			None

		@return			U32�J���[
*//**************************************************************************/
FORCE_INLINE MofU32 CVector4::ToU32Color(void) const{
	MofU8 r = MOF_FToColor(x);
	MofU8 g = MOF_FToColor(y);
	MofU8 b = MOF_FToColor(z);
	MofU8 a = MOF_FToColor(w);
	return MOF_ARGB(a,r,g,b);
}
/*************************************************************************//*!
		@brief			�l���Βl�ɂ���
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::Absolute(void){
	x = MOF_ABS(x);
	y = MOF_ABS(y);
	z = MOF_ABS(z);
	w = MOF_ABS(w);
	return;
}
/*************************************************************************//*!
		@brief			�l�̃N���b�s���O
		@param[in]		l			�ŏ��l
		@param[in]		h			�ő�l

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::Cliping(const MofFloat l,const MofFloat h){
	x = MOF_CLIPING(x,l,h);
	y = MOF_CLIPING(y,l,h);
	z = MOF_CLIPING(z,l,h);
	w = MOF_CLIPING(w,l,h);
	return;
}
/*************************************************************************//*!
		@brief			�l�̃N���b�s���O
		@param[in]		l			�ŏ��l
		@param[in]		h			�ő�l

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::Cliping(const Vector4& l,const Vector4& h){
	x = MOF_CLIPING(x,l.x,h.x);
	y = MOF_CLIPING(y,l.y,h.y);
	z = MOF_CLIPING(z,l.z,h.z);
	w = MOF_CLIPING(w,l.w,h.w);
	return;
}
/*************************************************************************//*!
		@brief			���l�̐ݒ�
		@param[in]		vx			X
		@param[in]		vy			Y
		@param[in]		vz			Z
		@param[in]		vw			W

		@return			None
*//**************************************************************************/
FORCE_INLINE void CVector4::SetValue(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw){
	x = vx;
	y = vy;
	z = vz;
	w = vw;
	return;
}
/*************************************************************************//*!
		@brief			�ő�̐��l�̎擾
		@param			None

		@return			X,Y,Z,W�̍ő�l
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::GetMaxValue(void) const {
	MofFloat m = MOF_MAX(x,y);
	m = MOF_MAX(z,m);
	return MOF_MAX(w,m);
}
/*************************************************************************//*!
		@brief			��Βl�̍ő�̐��l�̎擾
		@param			None

		@return			X,Y,Z,W�̐�Βl�̍ő�l
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::GetMaxAbsValue(void) const {
	MofFloat m = MOF_MAX(MOF_ABS(x),MOF_ABS(y));
	m = MOF_MAX(MOF_ABS(z),m);
	return MOF_MAX(MOF_ABS(w),m);
}
/*************************************************************************//*!
		@brief			�Œ�̐��l�̎擾
		@param			None

		@return			X,Y,Z,W�̍ŏ��l
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::GetMinValue(void) const {
	MofFloat m = MOF_MIN(x,y);
	m = MOF_MIN(z,m);
	return MOF_MIN(w,m);
}
/*************************************************************************//*!
		@brief			��Βl�̍Œ�̐��l�̎擾
		@param			None

		@return			X,Y,Z,W�̐�Βl�̍ŏ��l
*//**************************************************************************/
FORCE_INLINE MofFloat CVector4::GetMinAbsValue(void) const {
	MofFloat m = MOF_MIN(MOF_ABS(x),MOF_ABS(y));
	m = MOF_MIN(MOF_ABS(z),m);
	return MOF_MIN(MOF_ABS(w),m);
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CVector4& CVector4::operator = (const Vector2Impl& v) {
	x = v.x;
	y = v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CVector4& CVector4::operator = (const Vector3Impl& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CVector4& CVector4::operator = (const Vector4Impl& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CVector4& CVector4::operator = ( const Vector4& v ){
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}

//[EOF]