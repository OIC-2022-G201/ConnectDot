/*************************************************************************//*!
					
					@file	CameraBase.inl
					@brief	カメラ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			スクリーン座標を3D空間上のレイに変換する
		@param[in]		p			座標
		@param[out]		Out			3D座標出力

		@return			None
*//**************************************************************************/
FORCE_INLINE void CCamera::ScreenToWorld(const Vector2& p,Vector3& Out){
	ScreenToWorld(p.x,p.y,Out);
	return;
}
/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			座標系設定
		@param[in]		c			座標系
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetCoordinateType(const CoordinateType c){
	m_Coordinate = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			ビューポート設定
		@param[in]		r			画面矩形
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
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
		@brief			ビューポート設定
		@param[in]		px			X位置
		@param[in]		py			Y位置
		@param[in]		w			幅
		@param[in]		h			高さ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
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
		@brief			ビューポート設定
		@param[in]		px			X位置
		@param[in]		py			Y位置
		@param[in]		w			幅
		@param[in]		h			高さ
		@param[in]		n			最近
		@param[in]		f			最遠
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
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
		@brief			ビューポート設定
		@param[in]		v			ビューポート
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetViewPort(const ViewPort& v){
	m_ViewPort = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			カメラ座標設定
		@param[in]		v			設定座標
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetViewPosition(const Vector3& v){
	m_Position = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			カメラ座標設定
		@param[in]		x			設定X座標
		@param[in]		y			設定Y座標
		@param[in]		z			設定Z座標
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetViewPosition(MofFloat x, MofFloat y, MofFloat z){
	m_Position.SetValue(x,y,z);
	return TRUE;
}
/*************************************************************************//*!
		@brief			カメラ注視点設定
		@param[in]		v			設定座標
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetTargetPosition(const Vector3& v){
	m_Target = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			カメラ注視点設定
		@param[in]		x			設定X座標
		@param[in]		y			設定Y座標
		@param[in]		z			設定Z座標
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CCamera::SetTargetPosition(MofFloat x, MofFloat y, MofFloat z){
	m_Target.SetValue(x, y, z);
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CCamera::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			カメラ位置取得
		@param			None

		@return			カメラ位置
*//**************************************************************************/
FORCE_INLINE CVector3& CCamera::GetViewPosition(void){
	return m_Position;
}
/*************************************************************************//*!
		@brief			カメラ位置取得
		@param			None

		@return			カメラ位置
*//**************************************************************************/
FORCE_INLINE const CVector3& CCamera::GetViewPosition(void) const {
	return m_Position;
}
/*************************************************************************//*!
		@brief			注視点取得
		@param			None

		@return			注視点
*//**************************************************************************/
FORCE_INLINE CVector3& CCamera::GetTargetPosition(void){
	return m_Target;
}
/*************************************************************************//*!
		@brief			注視点取得
		@param			None

		@return			注視点
*//**************************************************************************/
FORCE_INLINE const CVector3& CCamera::GetTargetPosition(void) const {
	return m_Target;
}
/*************************************************************************//*!
		@brief			視線ベクトル取得
		@param			None

		@return			視線ベクトル
*//**************************************************************************/
FORCE_INLINE CVector3& CCamera::GetViewFront(void){
	return m_ViewFront;
}
/*************************************************************************//*!
		@brief			視線ベクトル取得
		@param			None

		@return			視線ベクトル
*//**************************************************************************/
FORCE_INLINE const CVector3& CCamera::GetViewFront(void) const {
	return m_ViewFront;
}
/*************************************************************************//*!
		@brief			上方ベクトル取得
		@param			None

		@return			上方ベクトル
*//**************************************************************************/
FORCE_INLINE CVector3& CCamera::GetViewUp(void){
	return m_ViewUp;
}
/*************************************************************************//*!
		@brief			上方ベクトル取得
		@param			None

		@return			上方ベクトル
*//**************************************************************************/
FORCE_INLINE const CVector3& CCamera::GetViewUp(void) const {
	return m_ViewUp;
}
/*************************************************************************//*!
		@brief			ビューポート設定取得
		@param			None

		@return			ビューポート
*//**************************************************************************/
FORCE_INLINE LPViewPort CCamera::GetViewPort(void){
	return &m_ViewPort;
}
/*************************************************************************//*!
		@brief			ビュー行列取得
		@param			None

		@return			ビュー行列
*//**************************************************************************/
FORCE_INLINE CMatrix44& CCamera::GetViewMatrix(void){
	return m_ViewMatrix;
}
/*************************************************************************//*!
		@brief			ビュー行列取得
		@param			None

		@return			ビュー行列
*//**************************************************************************/
FORCE_INLINE const CMatrix44& CCamera::GetViewMatrix(void) const {
	return m_ViewMatrix;
}
/*************************************************************************//*!
		@brief			ビルボード行列取得
		@param			None

		@return			ビルボード行列
*//**************************************************************************/
FORCE_INLINE CMatrix33& CCamera::GetBillBoardMatrix(void){
	return m_BillBoardMatrix;
}
/*************************************************************************//*!
		@brief			ビルボード行列取得
		@param			None

		@return			ビルボード行列
*//**************************************************************************/
FORCE_INLINE const CMatrix33& CCamera::GetBillBoardMatrix(void) const {
	return m_BillBoardMatrix;
}
/*************************************************************************//*!
		@brief			プロジェクション行列取得
		@param			None

		@return			プロジェクション行列
*//**************************************************************************/
FORCE_INLINE CMatrix44& CCamera::GetProjectionMatrix(void){
	return m_ProjectionMatrix;
}
/*************************************************************************//*!
		@brief			プロジェクション行列取得
		@param			None

		@return			プロジェクション行列
*//**************************************************************************/
FORCE_INLINE const CMatrix44& CCamera::GetProjectionMatrix(void) const {
	return m_ProjectionMatrix;
}
/*************************************************************************//*!
		@brief			ビュープロジェクション行列取得
		@param			None

		@return			ビュープロジェクション行列
*//**************************************************************************/
FORCE_INLINE CMatrix44& CCamera::GetViewProjectionMatrix(void){
	return m_ViewProjectionMatrix;
}
/*************************************************************************//*!
		@brief			ビュープロジェクション行列取得
		@param			None

		@return			ビュープロジェクション行列
*//**************************************************************************/
FORCE_INLINE const CMatrix44& CCamera::GetViewProjectionMatrix(void) const {
	return m_ViewProjectionMatrix;
}
/*************************************************************************//*!
		@brief			座標系取得
		@param			None

		@return			座標系
*//**************************************************************************/
FORCE_INLINE CoordinateType CCamera::GetCoordinateType(void) const{
	return m_Coordinate;
}
/*************************************************************************//*!
		@brief			プロジェクション情報構造体取得
		@param			None

		@return			座標系
*//**************************************************************************/
FORCE_INLINE const CCamera::Projection& CCamera::GetProjectionInfo(void) const{
	return m_Projection;
}

//[EOF]