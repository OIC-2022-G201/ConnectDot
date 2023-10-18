/*************************************************************************//*!
					
					@file	MeshMotionController.inl
					@brief	メッシュモーション管理クラス。<br>
							メッシュアニメーションの時間と状態を管理する。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			現在のモーションを変更
		@param[in]		n				モーション番号
		@param[in]		spd				モーション再生速度
		@param[in]		bLoop			ループフラグ
		@param[in]		bSame			同一モーションでの更新フラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMeshMotionController::ChangeMotion(MofU32 n, MofFloat spd, MofBool bLoop, MofBool bSame){
	return ChangeMotion(n, 0.0f, spd, 0.0f, bLoop, MOTIONLOCK_OFF, bSame);
}
/*************************************************************************//*!
		@brief			現在のモーション時間を設定
		@param[in]		t				設定時間
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMeshMotionController::SetTime(MofFloat t){
	m_MotionTime = t;
	for (MofU32 i = 0; i < m_pBoneState->GetArrayCount(); i++)
	{
		LPBONEMOTIONSTATE pBS = m_pBoneState->GetData(i);
		pBS->AnimationTime = m_MotionTime;
	}
	return Refresh();
}
/*************************************************************************//*!
		@brief			現在のモーション時間取得
		@param			None

		@return			現在のモーション時間
*//**************************************************************************/
FORCE_INLINE MofFloat CMeshMotionController::GetTime(void) const{
	return m_MotionTime;
}
/*************************************************************************//*!
		@brief			現在のモーション番号取得
		@param			None

		@return			現在のモーション番号
*//**************************************************************************/
FORCE_INLINE MofS32 CMeshMotionController::GetMotionNo(void) const {
	return m_MotionNo;
}
/*************************************************************************//*!
		@brief			登録されているモーション数取得
		@param			None

		@return			登録されているモーション数
*//**************************************************************************/
FORCE_INLINE MofS32 CMeshMotionController::GetMotionCount(void) const {
	return m_pAnimation->GetArrayCount();
}
/*************************************************************************//*!
		@brief			登録されているボーン数取得
		@param			None

		@return			登録されているボーン数
*//**************************************************************************/
FORCE_INLINE MofS32 CMeshMotionController::GetBoneCount(void){
	return m_pBoneState->GetArrayCount();
}
/*************************************************************************//*!
		@brief			登録されているモーション取得
		@param[in]		n				モーション番号

		@return			登録されているモーション
*//**************************************************************************/
FORCE_INLINE LPMeshAnimation CMeshMotionController::GetMotion(MofU32 n){
	return m_pAnimation->GetData(n);
}
/*************************************************************************//*!
		@brief			登録されているモーション取得
		@param[in]		pName			モーション名

		@return			登録されているモーション
*//**************************************************************************/
FORCE_INLINE LPMeshAnimation CMeshMotionController::GetMotionByName(LPCMofChar pName) {
	if(!pName)
	{
		return NULL;
	}
	LPMeshAnimation* pf = m_pAnimation->Find(pName);
	if(!pf)
	{
		return NULL;
	}
	return *pf;
}
/*************************************************************************//*!
		@brief			登録されているモーション取得
		@param[in]		pName			モーション名


		@return			登録されているモーションの番号
						MOF_U32_MAX		指定名のモーションが登録されていない
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshMotionController::GetMotionNoByName(LPCMofChar pName) const {
	if (!pName)
	{
		return MOF_U32_MAX;
	}
	for (MofU32 i = 0; i < m_pAnimation->GetArrayCount(); i++)
	{
		if (m_pAnimation->GetData(i)->GetName()->CompareCase(pName) == 0)
		{
			return i;
		}
	}
	return MOF_U32_MAX;
}
/*************************************************************************//*!
		@brief			ボーン状態取得
		@param[in]		n				ボーン番号

		@return			ボーン状態
*//**************************************************************************/
FORCE_INLINE LPBONEMOTIONSTATE CMeshMotionController::GetBoneState(MofU32 n){
	return m_pBoneState->GetData(n);
}
/*************************************************************************//*!
		@brief			ボーン状態取得
		@param[in]		Name			検索するボーン名

		@return			ボーン状態
*//**************************************************************************/
FORCE_INLINE LPBONEMOTIONSTATE CMeshMotionController::GetBoneState(LPCMofChar Name){
	if(!Name)
	{
		return NULL;
	}
	LPBONEMOTIONSTATE* pf = m_pBoneState->Find(Name);
	if(!pf)
	{
		return NULL;
	}
	return *pf;
}
/*************************************************************************//*!
		@brief			ワールドマトリクス取得
		@param[in]		None

		@return			ワールドマトリクス
*//**************************************************************************/
FORCE_INLINE CMatrix44& CMeshMotionController::GetWorldMatrix(void){
	return m_WorldMatrix;
}

//[EOF]