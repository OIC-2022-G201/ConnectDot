/*************************************************************************//*!
					
					@file	MeshMorphingAnimationBase.inl
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
FORCE_INLINE MofBool CMeshMorphingAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			パラメーターキー設定<br>
						古いデータがある場合解放される
		@param[in]		pKey			設定するキー
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshMorphingAnimation::SetParameterKey(LPFloatKeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pParameterKey);
	m_pParameterKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			モーションのループフラグの設定
		@param[in]		bLoop			ループフラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMeshMorphingAnimation::SetLoop(MofBool bLoop){
	if(m_pParameterKey)
	{
		m_pParameterKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CMeshMorphingAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			パラメーターキー取得
		@param			None

		@return			パラメーターキー
*//**************************************************************************/
FORCE_INLINE LPFloatKeyFrameArray CMeshMorphingAnimation::GetParameterKey(void){
	return m_pParameterKey;
}

//[EOF]