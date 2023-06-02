/*************************************************************************//*!
					
					@file	SpritePartMotionController.inl
					@brief	スプライトパーツモーション管理クラス。<br>
							スプライトパーツアニメーションの時間と状態を管理する。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			現在のモーションが終了しているかを判定する。<br>
						モーションがループする場合はTRUEになることはない
		@param			None
				
		@return			TRUE			終了済み<br>
						FALE			まだ終了していない
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartMotionController::IsEndMotion(void){
	for(MofU32 i = 0;i < m_pPartState->GetArrayCount();i++)
	{
		LPPARTMOTIONSTATE pBS = m_pPartState->GetData(i);
		if (!pBS->pNowAnimation)
		{
			continue;
		}
		if(pBS->pNowAnimation->IsLoop() || pBS->AnimationTime < pBS->pNowAnimation->GetEndTime())
		{
			return FALSE;
		}
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			現在のモーション時間を設定
		@param[in]		t				設定時間
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartMotionController::SetTime(MofFloat t){
	m_MotionTime = t;
	for (MofU32 i = 0; i < m_pPartState->GetArrayCount(); i++)
	{
		LPPARTMOTIONSTATE pPS = m_pPartState->GetData(i);
		pPS->AnimationTime = t;
	}
	return Refresh();
}
/*************************************************************************//*!
		@brief			現在のモーション時間取得
		@param			None

		@return			現在のモーション時間
*//**************************************************************************/
FORCE_INLINE MofFloat CSpritePartMotionController::GetTime(void) const{
	return m_MotionTime;
}
/*************************************************************************//*!
		@brief			現在のモーション番号取得
		@param			None

		@return			現在のモーション番号
*//**************************************************************************/
FORCE_INLINE MofS32 CSpritePartMotionController::GetMotionNo(void) const {
	return m_MotionNo;
}
/*************************************************************************//*!
		@brief			登録されているモーション数取得
		@param			None

		@return			登録されているモーション数
*//**************************************************************************/
FORCE_INLINE MofS32 CSpritePartMotionController::GetMotionCount(void) const {
	return m_pAnimation->GetArrayCount();
}

//[EOF]