/*************************************************************************//*!
					
					@file	MeshBoneAnimationBase.inl
					@brief	メッシュアニメーション基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			ループフラグがあるかを判定する
		@param			None
				
		@return			TRUE			ループする<br>
						FALSE			ループしない
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::IsLoop(void){
	MofBool re = FALSE;
	if(m_pPositionKey)
	{
		re |= m_pPositionKey->IsLoop();
	}
	if(m_pScalingKey)
	{
		re |= m_pScalingKey->IsLoop();
	}
	if(m_pRotationKey)
	{
		re |= m_pRotationKey->IsLoop();
	}
	return re;
}
/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			モーションのフラグの設定
		@param[in]		f				フラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetFlag(MofU32 f) {
	m_Flag = f;
	return TRUE;
}
/*************************************************************************//*!
		@brief			座標キー設定<br>
						古いデータがある場合解放される
		@param[in]		pKey			設定するキー
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetPositionKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pPositionKey);
	m_pPositionKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			拡大キー設定<br>
						古いデータがある場合解放される
		@param[in]		pKey			設定するキー
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetScalingKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pScalingKey);
	m_pScalingKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			回転キー設定<br>
						古いデータがある場合解放される
		@param[in]		pKey			設定するキー
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetRotationKey(LPQuaternionKeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pRotationKey);
	m_pRotationKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			モーションのループフラグの設定
		@param[in]		bLoop			ループフラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetLoop(MofBool bLoop){
	if(m_pPositionKey)
	{
		m_pPositionKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if(m_pScalingKey)
	{
		m_pScalingKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if(m_pRotationKey)
	{
		m_pRotationKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CMeshBoneAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			座標キー取得
		@param			None

		@return			座標キー
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshBoneAnimation::GetPositionKey(void){
	return m_pPositionKey;
}
/*************************************************************************//*!
		@brief			拡大キー取得
		@param			None

		@return			拡大キー
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshBoneAnimation::GetScalingKey(void){
	return m_pScalingKey;
}
/*************************************************************************//*!
		@brief			回転キー取得
		@param			None

		@return			回転キー
*//**************************************************************************/
FORCE_INLINE LPQuaternionKeyFrameArray CMeshBoneAnimation::GetRotationKey(void){
	return m_pRotationKey;
}
/*************************************************************************//*!
		@brief			アニメーションのフラグ取得
		@param			None

		@return			アニメーションのフラグ
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshBoneAnimation::GetFlag(void) {
	return m_Flag;
}

//[EOF]