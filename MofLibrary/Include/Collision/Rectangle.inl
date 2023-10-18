/*************************************************************************//*!
					
					@file	Rectangle.inl
					@brief	��`���Z�֘A

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//Rectangle
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�R���X�g���N�^
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
		@brief			�R���X�g���N�^
		@param[in]		l			��
		@param[in]		t			��
		@param[in]		r			�E
		@param[in]		b			��

		@return			None
*//**************************************************************************/
FORCE_INLINE Rectangle::Rectangle(MofFloat l,MofFloat t,MofFloat r,MofFloat b) :
Left(l) ,
Top(t) ,
Right(r) ,
Bottom(b) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		lt			����
		@param[in]		rb			�E��

		@return			None
*//**************************************************************************/
FORCE_INLINE Rectangle::Rectangle(const Vector2& lt,const Vector2& rb) :
Left(lt.x) ,
Top(lt.y) ,
Right(rb.x) ,
Bottom(rb.y) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE Rectangle::Rectangle(LPMofFloat pv) : 
Left(pv[0]) ,
Top(pv[1]) ,
Right(pv[2]) ,
Bottom(pv[3]) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�x�N�g��

		@return			None
*//**************************************************************************/
FORCE_INLINE Rectangle::Rectangle(const Rectangle& pObj) :
Left(pObj.Left) ,
Top(pObj.Top) ,
Right(pObj.Right) ,
Bottom(pObj.Bottom) {
}
/*************************************************************************//*!
		@brief			float�L���X�g<br>
						�����̍��W��float�|�C���^�Ƃ��Ă��̂܂ܕԂ��B
*//**************************************************************************/
FORCE_INLINE Rectangle::operator LPMofFloat (){
	return (LPMofFloat)&Left;
}
/*************************************************************************//*!
		@brief			+�擾
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator + () const{
	return Rectangle(*this);
}
/*************************************************************************//*!
		@brief			-�擾
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator - () const{
	return Rectangle(-Left,-Top,-Right,-Bottom);
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator += ( const Vector2& v ){
	Left += v.x;
	Top += v.y;
	Right += v.x;
	Bottom += v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			+=���Z
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator += ( const Rectangle& v ){
	Left += v.Left;
	Top += v.Top;
	Right += v.Right;
	Bottom += v.Bottom;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator -= ( const Vector2& v ){
	Left -= v.x;
	Top -= v.y;
	Right -= v.x;
	Bottom -= v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			-=���Z
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator -= ( const Rectangle& v ){
	Left -= v.Left;
	Top -= v.Top;
	Right -= v.Right;
	Bottom -= v.Bottom;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator *= ( const MofFloat v ){
	Left *= v;
	Top *= v;
	Right *= v;
	Bottom *= v;
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator *= ( const Vector2& v ){
	Left *= v.x;
	Top *= v.y;
	Right *= v.x;
	Bottom *= v.y;
	return *this;
}
/*************************************************************************//*!
		@brief			Rectangle�Ƃ�*=���Z
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator *= ( const Rectangle& v ){
	Left *= v.Left;
	Top *= v.Top;
	Right *= v.Right;
	Bottom *= v.Bottom;
	return *this;
}
/*************************************************************************//*!
		@brief			float�Ƃ�/=���Z
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
		@brief			Vector2�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator /= ( const Vector2& v ){
	Left /= ((v.x == 0) ? 1.0f : v.x);
	Top /= ((v.y == 0) ? 1.0f : v.y);
	Right /= ((v.x == 0) ? 1.0f : v.x);
	Bottom /= ((v.y == 0) ? 1.0f : v.y);
	return *this;
}
/*************************************************************************//*!
		@brief			Rectangle�Ƃ�/=���Z
*//**************************************************************************/
FORCE_INLINE Rectangle& Rectangle::operator /= ( const Rectangle& v ){
	Left /= ((v.Left == 0) ? 1.0f : v.Left);
	Top /= ((v.Top == 0) ? 1.0f : v.Top);
	Right /= ((v.Right == 0) ? 1.0f : v.Right);
	Bottom /= ((v.Bottom == 0) ? 1.0f : v.Bottom);
	return *this;
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�+���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator + ( const Vector2& v ) const{
	return Rectangle(Left + v.x,Top + v.y,Right + v.x,Bottom + v.y);
}
/*************************************************************************//*!
		@brief			Rectangle�Ƃ�+���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator + ( const Rectangle& v ) const{
	return Rectangle(Left + v.Left,Top + v.Top,Right + v.Right,Bottom + v.Bottom);
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�-���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator - ( const Vector2& v ) const{
	return Rectangle(Left - v.x,Top - v.y,Right - v.x,Bottom - v.y);
}
/*************************************************************************//*!
		@brief			Rectangle�Ƃ�-���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator - ( const Rectangle& v ) const{
	return Rectangle(Left - v.Left,Top - v.Top,Right - v.Right,Bottom - v.Bottom);
}
/*************************************************************************//*!
		@brief			float�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator * ( const MofFloat v ) const{
	return Rectangle(Left * v,Top * v,Right * v,Bottom * v);
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator * ( const Vector2& v ) const{
	return Rectangle(Left * v.x,Top * v.y,Right * v.x,Bottom * v.y);
}
/*************************************************************************//*!
		@brief			Rectangle�Ƃ�*���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator * ( const Rectangle& v ) const{
	return Rectangle(Left * v.Left,Top * v.Top,Right * v.Right,Bottom * v.Bottom);
}
/*************************************************************************//*!
		@brief			float�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator / ( const MofFloat v ) const{
	if(v == 0)
	{
		return *this;
	}
	return Rectangle(Left / v,Top / v,Right / v,Bottom / v);
}
/*************************************************************************//*!
		@brief			Vector2�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator / ( const Vector2& v ) const{
	return Rectangle(Left / ((v.x == 0) ? 1.0f : v.x),Top / ((v.y == 0) ? 1.0f : v.y),
					Right / ((v.x == 0) ? 1.0f : v.x),Bottom / ((v.y == 0) ? 1.0f : v.y));
}
/*************************************************************************//*!
		@brief			Rectangle�Ƃ�/���Z
*//**************************************************************************/
FORCE_INLINE Rectangle Rectangle::operator / ( const Rectangle& v ) const{
	return Rectangle(Left / ((v.Left == 0) ? 1.0f : v.Left),Top / ((v.Top == 0) ? 1.0f : v.Top),
					Right / ((v.Right == 0) ? 1.0f : v.Right),Bottom / ((v.Bottom == 0) ? 1.0f : v.Bottom));
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Rectangle�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE MofFloat& Rectangle::operator [] ( int i ){
	return (&Left)[i];
}
/*************************************************************************//*!
		@brief			�z��w��ɂ��Rectangle�����o�ւ̃A�N�Z�X
*//**************************************************************************/
FORCE_INLINE const MofFloat& Rectangle::operator [] ( int i ) const{
	return (&Left)[i];
}
/*************************************************************************//*!
		@brief			==���f
*//**************************************************************************/
FORCE_INLINE bool Rectangle::operator == ( const Rectangle& v ) const{
	return Left == v.Left && Top == v.Top && Right == v.Right && Bottom == v.Bottom;
}
/*************************************************************************//*!
		@brief			!=���f
*//**************************************************************************/
FORCE_INLINE bool Rectangle::operator != ( const Rectangle& v ) const{
	return Left != v.Left || Top != v.Top || Right != v.Right || Bottom != v.Bottom;
}
//--------------------------------------------------------------------------------------------
//CRectangleUtilities
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Vector2�i�|�C���g�j����`�̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		px			����X�ʒu
		@param[in]		py			����Y�ʒu

		@return			TRUE		��`�̒��ɓ_������
						FALSE		��`�͈̔͊O
*//**************************************************************************/
FORCE_INLINE MofBool CRectangleUtilities::CollisionPoint(const Rectangle& r,const MofFloat px,const MofFloat py){
	if(px >= r.Left && px <= r.Right && py >= r.Top && py <= r.Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Vector2�i�|�C���g�j����`�̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		p			����ʒu

		@return			TRUE		��`�̒��ɓ_������
						FALSE		��`�͈̔͊O
*//**************************************************************************/
FORCE_INLINE MofBool CRectangleUtilities::CollisionPoint(const Rectangle& r,const Vector2& p){
	if(p.x >= r.Left && p.x <= r.Right && p.y >= r.Top && p.y <= r.Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵�����Rectangle�i��`�j���ڐG���Ă��邩�𔻒肷��
		@param[in]		r1			�����`
		@param[in]		r2			�����`

		@return			TRUE		��`�̒��ɓ_������
						FALSE		��`�͈̔͊O
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
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle() :
Rectangle() {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		l			��
		@param[in]		t			��
		@param[in]		r			�E
		@param[in]		b			��

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(MofFloat l,MofFloat t,MofFloat r,MofFloat b) :
Rectangle(l,t,r,b) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		lt			����
		@param[in]		rb			�E��

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(const Vector2& lt,const Vector2& rb) :
Rectangle(lt,rb) {
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		pv			���W

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(LPMofFloat pv) :
Rectangle(pv) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[��`

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(const Rectangle& pObj) :
Rectangle(pObj) {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[��`

		@return			None
*//**************************************************************************/
FORCE_INLINE CRectangle::CRectangle(const CRectangle& pObj) :
Rectangle(pObj) {
}
/*************************************************************************//*!
		@brief			��`�g��<br>
						Left,Top��-e�ARight,Bottom��+e���s��
		@param[in]		e			�g���T�C�Y

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
		@brief			��`�g��<br>
						Left,Top��-ex�ARight,Bottom��+ey���s��
		@param[in]		ex			X�g���T�C�Y
		@param[in]		ey			Y�g���T�C�Y

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
		@brief			�ړ�<br>
						��`�̕��ƍ��������̂܂܂�m�ړ�����B
		@param[in]		m			�ړ���
				
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
		@brief			�ړ�<br>
						��`�̕��ƍ��������̂܂܂�pos�̈ʒu�Ɉړ�����B
		@param[in]		pos			�ʒu
				
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
		@brief			��<br>
						��`�̕���ύX����B
		@param[in]		w			��
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CRectangle::SetWidth(const MofFloat w) {
	Right = Left + w;
	return;
}
/*************************************************************************//*!
		@brief			����<br>
						��`�̍�����ύX����B
		@param[in]		h			����
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CRectangle::SetHeight(const MofFloat h) {
	Bottom = Top + h;
	return;
}
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Vector2�i�|�C���g�j����`�̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		px			����X�ʒu
		@param[in]		py			����Y�ʒu

		@return			TRUE		��`�̒��ɓ_������
						FALSE		��`�͈̔͊O
*//**************************************************************************/
FORCE_INLINE MofBool CRectangle::CollisionPoint(const MofFloat px,const MofFloat py) const {
	if(px >= Left && px <= Right && py >= Top && py <= Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Vector2�i�|�C���g�j����`�̒��ɓ����Ă��邩�𔻒肷��
		@param[in]		p			����ʒu

		@return			TRUE		��`�̒��ɓ_������
						FALSE		��`�͈̔͊O
*//**************************************************************************/
FORCE_INLINE MofBool CRectangle::CollisionPoint(const Vector2& p) const {
	if(p.x >= Left && p.x <= Right && p.y >= Top && p.y <= Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Rectangle�i��`�j���ڐG���Ă��邩�𔻒肷��
		@param[in]		l			���荶�ʒu
		@param[in]		t			�����ʒu
		@param[in]		r			����E�ʒu
		@param[in]		b			���艺�ʒu

		@return			TRUE		��`�̒��ɓ_������
						FALSE		��`�͈̔͊O
*//**************************************************************************/
FORCE_INLINE MofBool CRectangle::CollisionRect(const MofFloat l,const MofFloat t,const MofFloat r,const MofFloat b) const {
	if(r >= Left && l <= Right && b >= Top && t <= Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�����蔻��<br>
						�w�肵��Rectangle�i��`�j���ڐG���Ă��邩�𔻒肷��
		@param[in]		r			�����`

		@return			TRUE		��`�̒��ɓ_������
						FALSE		��`�͈̔͊O
*//**************************************************************************/
FORCE_INLINE MofBool CRectangle::CollisionRect(const Rectangle& r) const {
	if(r.Right >= Left && r.Left <= Right && r.Bottom >= Top && r.Top <= Bottom)
	{
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			���l�̐ݒ�
		@param[in]		l			��
		@param[in]		t			��
		@param[in]		r			�E
		@param[in]		b			��

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
		@brief			���擾
		@param			None

		@return			���̎擾
*//**************************************************************************/
FORCE_INLINE MofFloat CRectangle::GetWidth(void) const{
	return Right - Left;
}
/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			�����̎擾
*//**************************************************************************/
FORCE_INLINE MofFloat CRectangle::GetHeight(void) const{
	return Bottom - Top;
}
/*************************************************************************//*!
		@brief			���S�擾
		@param			None

		@return			���S�擾
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetCenter(void) const{
	return Vector2((Left + Right) * 0.5f,(Top + Bottom) * 0.5f);
}
/*************************************************************************//*!
		@brief			����擾
		@param			None

		@return			����擾
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetTopLeft(void) const{
	return Vector2(Left,Top);
}
/*************************************************************************//*!
		@brief			�E��擾
		@param			None

		@return			�E��擾
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetTopRight(void) const{
	return Vector2(Right,Top);
}
/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			�����擾
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetBottomLeft(void) const{
	return Vector2(Left,Bottom);
}
/*************************************************************************//*!
		@brief			�E���擾
		@param			None

		@return			�E���擾
*//**************************************************************************/
FORCE_INLINE Vector2 CRectangle::GetBottomRight(void) const{
	return Vector2(Right,Bottom);
}
/*************************************************************************//*!
		@brief			���
*//**************************************************************************/
FORCE_INLINE CRectangle& CRectangle::operator = ( const Rectangle& v ){
	Left = v.Left;
	Right = v.Right;
	Top = v.Top;
	Bottom = v.Bottom;
	return *this;
}

//[EOF]