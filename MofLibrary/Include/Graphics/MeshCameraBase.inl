/*************************************************************************//*!
					
					@file	MeshCameraBase.inl
					@brief	メッシュカメラ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCamera::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CMeshCamera::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			カメラ情報取得
		@param			None

		@return			カメラ情報
*//**************************************************************************/
FORCE_INLINE MOMCAMERAINFO& CMeshCamera::GetInfo(void) {
	return m_Info;
}
/*************************************************************************//*!
		@brief			アニメーションでの動作モーフィング情報取得
		@param			None

		@return			アニメーションでの動作モーフィング情報配列
*//**************************************************************************/
FORCE_INLINE LPMeshCameraAnimationArray CMeshCamera::GetAnimation(void) {
	return m_pAnimation;
}
/*************************************************************************//*!
		@brief			登録されていアニメーション取得
		@param[in]		pName			アニメーション名

		@return			アニメーション
*//**************************************************************************/
FORCE_INLINE LPMeshCameraAnimation CMeshCamera::GetAnimation(LPCMofChar pName) {
	if (!pName)
	{
		return NULL;
	}
	LPMeshCameraAnimation* pf = m_pAnimation->Find(pName);
	if (!pf)
	{
		return NULL;
	}
	return *pf;
}
/*************************************************************************//*!
		@brief			アニメーション登録数取得
		@param			None

		@return			アニメーション登録数
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshCamera::GetAnimationCount(void) {
	return m_pAnimation->GetArrayCount();
}

//[EOF]