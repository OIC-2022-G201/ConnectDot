/*************************************************************************//*!
					
					@file	MeshContainerBase.inl
					@brief	メッシュ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			基本描画
		@param[in]		pos				座標
		@param[in]		scl				スケール
		@param[in]		rot				回転
				
		@return			TRUE			正常終了<br>
						それ以外			解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshContainerBase::Render(const Vector3& pos, const Vector3& scl, const Vector3& rot){
	CMatrix44 mat;
	mat.RotationZXY(rot);
	mat.Scaling(scl, mat);
	mat.SetTranslation(pos);
	return Render(mat);
}
/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshContainerBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CMeshContainerBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			メッシュリスト取得
		@param			None

		@return			メッシュリスト
*//**************************************************************************/
FORCE_INLINE LPMeshArray CMeshContainerBase::GetMesh(void){
	return m_pMesh;
}
/*************************************************************************//*!
		@brief			メッシュ登録数取得
		@param			None

		@return			メッシュ登録数
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshContainerBase::GetMeshCount(void) const {
	return m_pMesh->GetArrayCount();
}
/*************************************************************************//*!
		@brief			メッシュ取得
		@param[in]		pName			メッシュ番号

		@return			メッシュ
						見つからなかった場合NULLを返す
*//**************************************************************************/
FORCE_INLINE LPMesh CMeshContainerBase::GetMesh(MofU32 No){
	if (No >= m_pMesh->GetArrayCount())
	{
		return NULL;
	}
	return m_pMesh->GetData(No);
}
/*************************************************************************//*!
		@brief			メッシュ取得
		@param[in]		pName			探すメッシュ名

		@return			メッシュ
						見つからなかった場合NULLを返す
*//**************************************************************************/
FORCE_INLINE LPMesh CMeshContainerBase::GetMesh(LPCMofChar pName){
	LPMesh* re = m_pMesh->Find(pName);
	if(!re)
	{
		return NULL;
	}
	return *re;
}
/*************************************************************************//*!
		@brief			ジオメトリ登録数取得
		@param			None

		@return			ジオメトリ登録数
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshContainerBase::GetGeometryCount(void) const {
	MofU32 re = 0;
	for (MofU32 i = 0; i < m_pMesh->GetArrayCount(); i++)
	{
		re += m_pMesh->GetData(i)->GetGeometryCount();
	}
	return re;
}
/*************************************************************************//*!
		@brief			ジオメトリ取得
		@param[in]		No				ジオメトリ番号

		@return			ジオメトリ
						見つからなかった場合NULLを返す
*//**************************************************************************/
FORCE_INLINE LPGeometry CMeshContainerBase::GetGeometry(MofU32 No){
	MofU32 n = No;
	for (MofU32 i = 0; i < m_pMesh->GetArrayCount(); i++)
	{
		MofU32 cnt = m_pMesh->GetData(i)->GetGeometryCount();
		if (n < cnt)
		{
			return m_pMesh->GetData(i)->GetGeometry(n);
		}
		else
		{
			n -= cnt;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			ジオメトリ取得
		@param[in]		pName			探すジオメトリ名

		@return			ジオメトリ
						見つからなかった場合NULLを返す
*//**************************************************************************/
FORCE_INLINE LPGeometry CMeshContainerBase::GetGeometryByName(LPCMofChar pName){
	for(MofU32 i = 0;i < m_pMesh->GetArrayCount();i++)
	{
		LPGeometry re = m_pMesh->GetData(i)->GetGeometryByName(pName);
		if(re)
		{
			return re;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			ボーンリスト取得
		@param			None

		@return			ボーンリスト
*//**************************************************************************/
FORCE_INLINE LPBoneArray CMeshContainerBase::GetBone(void){
	return m_pBone;
}
/*************************************************************************//*!
		@brief			メッシュアニメーションリスト取得
		@param			None

		@return			メッシュアニメーションリスト
*//**************************************************************************/
FORCE_INLINE LPMeshAnimationArray CMeshContainerBase::GetAnimation(void){
	return m_pAnimation;
}
/*************************************************************************//*!
		@brief			剛体情報リスト取得
		@param			None

		@return			剛体情報リスト
*//**************************************************************************/
FORCE_INLINE LPPhysicsActorInfoArray CMeshContainerBase::GetRigidInfo(void) {
	return m_pRigid;
}
/*************************************************************************//*!
		@brief			ジョイント情報リスト取得
		@param			None

		@return			ジョイント情報リスト
*//**************************************************************************/
FORCE_INLINE LPPhysicsJointInfoArray CMeshContainerBase::GetJointInfo(void) {
	return m_pJoint;
}
/*************************************************************************//*!
		@brief			カメラリスト取得
		@param			None

		@return			カメラリスト
*//**************************************************************************/
FORCE_INLINE LPMeshCameraArray CMeshContainerBase::GetCamera(void) {
	return m_pCamera;
}
/*************************************************************************//*!
		@brief			カメラ取得
		@param[in]		pName			探すカメラ名

		@return			カメラ
						見つからなかった場合NULLを返す
*//**************************************************************************/
FORCE_INLINE LPMeshCamera CMeshContainerBase::GetCamera(LPCMofChar pName){
	LPMeshCamera* re = m_pCamera->Find(pName);
	if(!re)
	{
		return NULL;
	}
	return *re;
}

//[EOF]