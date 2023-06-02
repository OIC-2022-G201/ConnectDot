/*************************************************************************//*!
					
					@file	MeshAnimationBase.inl
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
FORCE_INLINE MofBool CMeshAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			モーションのループフラグの設定
		@param[in]		bLoop			ループフラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMeshAnimation::SetLoop(MofBool bLoop){
	if(!m_pBoneAnimation)
	{
		return FALSE;
	}
	for(MofU32 i = 0;i < m_pBoneAnimation->GetArrayCount();i++)
	{
		m_pBoneAnimation->GetData(i)->SetLoop(bLoop);
	}
	for (MofU32 i = 0; i < m_pMorphingAnimation->GetArrayCount(); i++)
	{
		m_pMorphingAnimation->GetData(i)->SetLoop(bLoop);
	}
	return TRUE;
}

/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CMeshAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			アニメーションでの動作ボーン情報取得
		@param			None

		@return			アニメーションでの動作ボーン情報配列
*//**************************************************************************/
FORCE_INLINE LPMeshBoneAnimationArray CMeshAnimation::GetBoneAnimation(void){
	return m_pBoneAnimation;
}
/*************************************************************************//*!
		@brief			アニメーションでの動作モーフィング情報取得
		@param			None

		@return			アニメーションでの動作モーフィング情報配列
*//**************************************************************************/
FORCE_INLINE LPMeshMorphingAnimationArray CMeshAnimation::GetMorphingAnimation(void) {
	return m_pMorphingAnimation;
}

//[EOF]