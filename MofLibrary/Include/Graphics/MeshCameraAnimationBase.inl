/*************************************************************************//*!
					
					@file	MeshCameraAnimationBase.inl
					@brief	メッシュアニメーション基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			座標キー設定<br>
						古いデータがある場合解放される
		@param[in]		pKey			設定するキー
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetPositionKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pPositionKey);
	m_pPositionKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			ターゲットキー設定<br>
						古いデータがある場合解放される
		@param[in]		pKey			設定するキー
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetTargetKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pTargetKey);
	m_pTargetKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			上方キー設定<br>
						古いデータがある場合解放される
		@param[in]		pKey			設定するキー
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetUpKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pUpKey);
	m_pUpKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			視野角キー設定<br>
						古いデータがある場合解放される
		@param[in]		pKey			設定するキー
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetFovKey(LPFloatKeyFrameArray pKey) {
	MOF_SAFE_DELETE(m_pFovKey);
	m_pFovKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			モーションのループフラグの設定
		@param[in]		bLoop			ループフラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetLoop(MofBool bLoop){
	if (m_pPositionKey)
	{
		m_pPositionKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if(m_pTargetKey)
	{
		m_pTargetKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if (m_pUpKey)
	{
		m_pUpKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if (m_pFovKey)
	{
		m_pFovKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CMeshCameraAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			座標キー取得
		@param			None

		@return			座標キー
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshCameraAnimation::GetPositionKey(void){
	return m_pPositionKey;
}
/*************************************************************************//*!
		@brief			ターゲットキー取得
		@param			None

		@return			ターゲットキー
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshCameraAnimation::GetTargetKey(void){
	return m_pTargetKey;
}
/*************************************************************************//*!
		@brief			上方キー取得
		@param			None

		@return			上方キー
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshCameraAnimation::GetUpKey(void){
	return m_pUpKey;
}
/*************************************************************************//*!
		@brief			視野角キー取得
		@param			None

		@return			視野角キー
*//**************************************************************************/
FORCE_INLINE LPFloatKeyFrameArray CMeshCameraAnimation::GetFovKey(void) {
	return m_pFovKey;
}

//[EOF]