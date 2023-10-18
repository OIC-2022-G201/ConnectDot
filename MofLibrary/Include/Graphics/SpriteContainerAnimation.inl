/*************************************************************************//*!
					
					@file	SpriteContainerAnimation.inl
					@brief	スプライトコンテナアニメーション基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteContainerAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			モーションのループフラグの設定
		@param[in]		bLoop			ループフラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteContainerAnimation::SetLoop(MofBool bLoop){
	if(!m_pPartAnimation)
	{
		return FALSE;
	}
	for(MofU32 i = 0;i < m_pPartAnimation->GetArrayCount();i++)
	{
		m_pPartAnimation->GetData(i)->SetLoop(bLoop);
	}
	return TRUE;
}

/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CSpriteContainerAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			アニメーションでの動作パーツ情報取得
		@param			None

		@return			アニメーションでの動作パーツ情報配列
*//**************************************************************************/
FORCE_INLINE LPSpritePartAnimationArray CSpriteContainerAnimation::GetPartAnimation(void){
	return m_pPartAnimation;
}

//[EOF]