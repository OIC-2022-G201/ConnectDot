/*************************************************************************//*!
					
					@file	Sprite2DContainer.inl
					@brief	スプライトコンテナクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			現在のモーションを変更
		@param[in]		n				モーション番号
		@param[in]		bSame			同一モーションでの更新フラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CSprite2DContainer::ChangeMotion(MofU32 n,MofBool bSame){
	if(m_pMotionController)
	{
		return m_pMotionController->ChangeMotion(n,bSame);
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			現在のモーションを変更
		@param[in]		str				モーション名
		@param[in]		bSame			同一モーションでの更新フラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CSprite2DContainer::ChangeMotionByName(LPCMofChar str,MofBool bSame){
	if(m_pMotionController)
	{
		return m_pMotionController->ChangeMotionByName(str,bSame);
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			時間を設定する
		@param[in]		t				内部アニメーション時間
				
		@return			TRUE			正常終了<br>
						それ以外		エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CSprite2DContainer::SetTime(MofFloat t) {
	if (m_pMotionController)
	{
		return m_pMotionController->SetTime(t);
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			テクスチャ配列取得
		@param			None

		@return			テクスチャ配列
*//**************************************************************************/
FORCE_INLINE LPTextureArray CSprite2DContainer::GetTextureArray(void){
	return m_pTextureArray;
}
/*************************************************************************//*!
		@brief			スプライトアニメーションリスト取得
		@param			None

		@return			スプライトアニメーションリスト
*//**************************************************************************/
FORCE_INLINE LPSpriteContainerAnimationArray CSprite2DContainer::GetAnimation(void){
	return m_pAnimation;
}
/*************************************************************************//*!
		@brief			スプライトアニメーションコントローラー取得
		@param			None

		@return			スプライトアニメーションコントローラー
*//**************************************************************************/
FORCE_INLINE LPSpritePartMotionController CSprite2DContainer::GetMotionController(void){
	return m_pMotionController;
}

//[EOF]