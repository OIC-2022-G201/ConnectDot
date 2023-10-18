/*************************************************************************//*!
					
					@file	SpriteMotionController.inl
					@brief	スプライトモーション管理クラス。<br>
							スプライトアニメーションの時間と状態を管理する。

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
FORCE_INLINE MofBool CSpriteMotionController::IsEndMotion(void){
	LPSpriteAnimation pAnim = m_pAnimation->GetData(m_MotionNo);
	return ((!pAnim->IsLoop() && m_MotionTime >= pAnim->GetEndTime()) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			現在のモーション時間を設定
		@param[in]		t				設定時間
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteMotionController::SetTime(MofFloat t){
	m_MotionTime = t;
	return Refresh();
}
/*************************************************************************//*!
		@brief			現在のモーション時間取得
		@param			None

		@return			現在のモーション時間
*//**************************************************************************/
FORCE_INLINE MofFloat CSpriteMotionController::GetTime(void) const {
	return m_MotionTime;
}
/*************************************************************************//*!
		@brief			現在のモーション番号取得
		@param			None

		@return			現在のモーション番号
*//**************************************************************************/
FORCE_INLINE MofS32 CSpriteMotionController::GetMotionNo(void) const {
	return m_MotionNo;
}
/*************************************************************************//*!
		@brief			登録されているモーション数取得
		@param			None

		@return			登録されているモーション数
*//**************************************************************************/
FORCE_INLINE MofS32 CSpriteMotionController::GetMotionCount(void) const {
	return m_pAnimation->GetArrayCount();
}
/*************************************************************************//*!
		@brief			現在のフレーム番号取得
		@param			None

		@return			現在のフレーム番号
*//**************************************************************************/
FORCE_INLINE MofS32 CSpriteMotionController::GetFrameNo(void) {
	LPSpriteAnimation pAnim = m_pAnimation->GetData(m_MotionNo);
	return pAnim->GetTimeFrameNo(m_MotionTime);
}
/*************************************************************************//*!
		@brief			現在のアニメーション矩形取得
		@param			None

		@return			現在のアニメーション矩形
*//**************************************************************************/
FORCE_INLINE CRectangle& CSpriteMotionController::GetSrcRect(void){
	return m_SrcRect;
}
/*************************************************************************//*!
		@brief			現在のアニメーション矩形取得
		@param			None

		@return			現在のアニメーション矩形
*//**************************************************************************/
FORCE_INLINE const CRectangle& CSpriteMotionController::GetSrcRect(void) const {
	return m_SrcRect;
}

//[EOF]