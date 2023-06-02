/*************************************************************************//*!
					
					@file	CameraBase.inl
					@brief	�J�������N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�X�N���[�����W��3D��ԏ�̃��C�ɕϊ�����
		@param[in]		p			���W
		@param[out]		Out			3D���W�o��

		@return			None
*//**************************************************************************/
FORCE_INLINE void CCamera::ScreenToWorld(const Vector2& p,Vector3& Out){
	ScreenToWorld(p.x,p.y,Out);
	return;
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���W�n�ݒ�
		@param[in]		c			���W�n
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetCoordinateType(const CoordinateType c){
	m_Coordinate = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�r���[�|�[�g�ݒ�
		@param[in]		r			��ʋ�`
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetViewPort(const Rectangle& r){
	m_ViewPort.x = r.Left;
	m_ViewPort.y = r.Top;
	m_ViewPort.w = r.Right - r.Left;
	m_ViewPort.h = r.Bottom - r.Top;
	m_ViewPort.n = 0.0f;
	m_ViewPort.f = 1.0f;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�r���[�|�[�g�ݒ�
		@param[in]		px			X�ʒu
		@param[in]		py			Y�ʒu
		@param[in]		w			��
		@param[in]		h			����
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetViewPort(const MofFloat px,const MofFloat py,const MofFloat w,const MofFloat h){
	m_ViewPort.x = px;
	m_ViewPort.y = py;
	m_ViewPort.w = w;
	m_ViewPort.h = h;
	m_ViewPort.n = 0.0f;
	m_ViewPort.f = 1.0f;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�r���[�|�[�g�ݒ�
		@param[in]		px			X�ʒu
		@param[in]		py			Y�ʒu
		@param[in]		w			��
		@param[in]		h			����
		@param[in]		n			�ŋ�
		@param[in]		f			�ŉ�
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetViewPort(const MofFloat px,const MofFloat py,const MofFloat w,const MofFloat h,const MofFloat n,const MofFloat f){
	m_ViewPort.x = px;
	m_ViewPort.y = py;
	m_ViewPort.w = w;
	m_ViewPort.h = h;
	m_ViewPort.n = n;
	m_ViewPort.f = f;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�r���[�|�[�g�ݒ�
		@param[in]		v			�r���[�|�[�g
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetViewPort(const ViewPort& v){
	m_ViewPort = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�J�������W�ݒ�
		@param[in]		v			�ݒ���W
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetViewPosition(const Vector3& v){
	m_Position = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�J�������W�ݒ�
		@param[in]		x			�ݒ�X���W
		@param[in]		y			�ݒ�Y���W
		@param[in]		z			�ݒ�Z���W
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetViewPosition(MofFloat x, MofFloat y, MofFloat z){
	m_Position.SetValue(x,y,z);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�J���������_�ݒ�
		@param[in]		v			�ݒ���W
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetTargetPosition(const Vector3& v){
	m_Target = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�J���������_�ݒ�
		@param[in]		x			�ݒ�X���W
		@param[in]		y			�ݒ�Y���W
		@param[in]		z			�ݒ�Z���W
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetTargetPosition(MofFloat x, MofFloat y, MofFloat z){
	m_Target.SetValue(x, y, z);
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CCamera::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�J�����ʒu�擾
		@param			None

		@return			�J�����ʒu
*//**************************************************************************/
FORCE_INLINE CVector3& CCamera::GetViewPosition(void){
	return m_Position;
}
/*************************************************************************//*!
		@brief			�J�����ʒu�擾
		@param			None

		@return			�J�����ʒu
*//**************************************************************************/
FORCE_INLINE const CVector3& CCamera::GetViewPosition(void) const {
	return m_Position;
}
/*************************************************************************//*!
		@brief			�����_�擾
		@param			None

		@return			�����_
*//**************************************************************************/
FORCE_INLINE CVector3& CCamera::GetTargetPosition(void){
	return m_Target;
}
/*************************************************************************//*!
		@brief			�����_�擾
		@param			None

		@return			�����_
*//**************************************************************************/
FORCE_INLINE const CVector3& CCamera::GetTargetPosition(void) const {
	return m_Target;
}
/*************************************************************************//*!
		@brief			�����x�N�g���擾
		@param			None

		@return			�����x�N�g��
*//**************************************************************************/
FORCE_INLINE CVector3& CCamera::GetViewFront(void){
	return m_ViewFront;
}
/*************************************************************************//*!
		@brief			�����x�N�g���擾
		@param			None

		@return			�����x�N�g��
*//**************************************************************************/
FORCE_INLINE const CVector3& CCamera::GetViewFront(void) const {
	return m_ViewFront;
}
/*************************************************************************//*!
		@brief			����x�N�g���擾
		@param			None

		@return			����x�N�g��
*//**************************************************************************/
FORCE_INLINE CVector3& CCamera::GetViewUp(void){
	return m_ViewUp;
}
/*************************************************************************//*!
		@brief			����x�N�g���擾
		@param			None

		@return			����x�N�g��
*//**************************************************************************/
FORCE_INLINE const CVector3& CCamera::GetViewUp(void) const {
	return m_ViewUp;
}
/*************************************************************************//*!
		@brief			�r���[�|�[�g�ݒ�擾
		@param			None

		@return			�r���[�|�[�g
*//**************************************************************************/
FORCE_INLINE LPViewPort CCamera::GetViewPort(void){
	return &m_ViewPort;
}
/*************************************************************************//*!
		@brief			�r���[�s��擾
		@param			None

		@return			�r���[�s��
*//**************************************************************************/
FORCE_INLINE CMatrix44& CCamera::GetViewMatrix(void){
	return m_ViewMatrix;
}
/*************************************************************************//*!
		@brief			�r���[�s��擾
		@param			None

		@return			�r���[�s��
*//**************************************************************************/
FORCE_INLINE const CMatrix44& CCamera::GetViewMatrix(void) const {
	return m_ViewMatrix;
}
/*************************************************************************//*!
		@brief			�r���{�[�h�s��擾
		@param			None

		@return			�r���{�[�h�s��
*//**************************************************************************/
FORCE_INLINE CMatrix33& CCamera::GetBillBoardMatrix(void){
	return m_BillBoardMatrix;
}
/*************************************************************************//*!
		@brief			�r���{�[�h�s��擾
		@param			None

		@return			�r���{�[�h�s��
*//**************************************************************************/
FORCE_INLINE const CMatrix33& CCamera::GetBillBoardMatrix(void) const {
	return m_BillBoardMatrix;
}
/*************************************************************************//*!
		@brief			�v���W�F�N�V�����s��擾
		@param			None

		@return			�v���W�F�N�V�����s��
*//**************************************************************************/
FORCE_INLINE CMatrix44& CCamera::GetProjectionMatrix(void){
	return m_ProjectionMatrix;
}
/*************************************************************************//*!
		@brief			�v���W�F�N�V�����s��擾
		@param			None

		@return			�v���W�F�N�V�����s��
*//**************************************************************************/
FORCE_INLINE const CMatrix44& CCamera::GetProjectionMatrix(void) const {
	return m_ProjectionMatrix;
}
/*************************************************************************//*!
		@brief			�r���[�v���W�F�N�V�����s��擾
		@param			None

		@return			�r���[�v���W�F�N�V�����s��
*//**************************************************************************/
FORCE_INLINE CMatrix44& CCamera::GetViewProjectionMatrix(void){
	return m_ViewProjectionMatrix;
}
/*************************************************************************//*!
		@brief			�r���[�v���W�F�N�V�����s��擾
		@param			None

		@return			�r���[�v���W�F�N�V�����s��
*//**************************************************************************/
FORCE_INLINE const CMatrix44& CCamera::GetViewProjectionMatrix(void) const {
	return m_ViewProjectionMatrix;
}
/*************************************************************************//*!
		@brief			���W�n�擾
		@param			None

		@return			���W�n
*//**************************************************************************/
FORCE_INLINE CoordinateType CCamera::GetCoordinateType(void) const{
	return m_Coordinate;
}
/*************************************************************************//*!
		@brief			�v���W�F�N�V�������\���̎擾
		@param			None

		@return			���W�n
*//**************************************************************************/
FORCE_INLINE const CCamera::Projection& CCamera::GetProjectionInfo(void) const{
	return m_Projection;
}

//[EOF]