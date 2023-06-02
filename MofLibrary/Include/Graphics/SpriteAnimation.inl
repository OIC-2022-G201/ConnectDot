/*************************************************************************//*!
					
					@file	SpriteAnimation.inl
					@brief	スプライトアニメーションクラス。<br>
							スプライトの矩形変化でのアニメーションを行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			コンストラクタ
		@param[in]		frm				フレーム

		@return			None
*//**************************************************************************/
template < int N > FORCE_INLINE CSpriteAnimation::CSpriteAnimation(SpriteAnimationCreateFrame< N >& frm) : 
m_Name(frm.Name) {
	MofS32 nc;
	for(nc = 0;nc < N && frm.Pattern[nc].Wait > 0;nc++);
	m_RectKeyFrame.ReSize(nc + 1);
	m_RectKeyFrame.SetFlag(((frm.bLoop) ? KEYFRAMEARRAY_ARRAYMEMBERDELETE | KEYFRAMEARRAY_LOOPALLFRAME | KEYFRAMEARRAY_ARRAYMEMBERCOPY : KEYFRAMEARRAY_ARRAYMEMBERDELETE | KEYFRAMEARRAY_ARRAYMEMBERCOPY));
	MofFloat wt = 0.0f;
	MofFloat ft = ((CUtilities::GetRestrictFPS() <= 0) ? 1.0f : 1.0f / CUtilities::GetRestrictFPS());
	for(int i = 0;i <= nc;i++)
	{
		if(i == nc)
		{
			MofFloat ox = frm.OffsetX + frm.Width * frm.Pattern[i - 1].No;
			MofFloat oy = frm.OffsetY + frm.Height * frm.Pattern[i - 1].Step;
			Rectangle r(ox,oy,ox + frm.Width,oy + frm.Height);
			LPRectangleKeyFrame pKey = new CRectangleKeyFrame(r,wt,0,KEYINTERPOLATION_NONE,NULL);
			m_RectKeyFrame.SetData(pKey,i);
		}
		else
		{
			MofFloat ox = frm.OffsetX + frm.Width * frm.Pattern[i].No;
			MofFloat oy = frm.OffsetY + frm.Height * frm.Pattern[i].Step;
			Rectangle r(ox,oy,ox + frm.Width,oy + frm.Height);
			LPRectangleKeyFrame pKey = new CRectangleKeyFrame(r,wt,0,KEYINTERPOLATION_NONE,NULL);
			m_RectKeyFrame.SetData(pKey,i);
			wt += frm.Pattern[i].Wait * ft;
		}
	}
}
/*************************************************************************//*!
		@brief			現在のモーションがループするかを判定する。
		@param			None
				
		@return			TRUE			ループする<br>
						FALE			ループしない
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteAnimation::IsLoop(void){
	return ((m_RectKeyFrame.GetFlag() & KEYFRAMEARRAY_LOOPFLAG) ? TRUE  : FALSE);
}
/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			モーションのループフラグの設定
		@param[in]		bLoop			ループフラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteAnimation::SetLoop(MofBool bLoop){
	return m_RectKeyFrame.SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CSpriteAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			指定時間での矩形取得
		@param[in]		t				時間
		@param[out]		oRec			出力矩形
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteAnimation::GetTimeRect(const MofFloat t,Rectangle& oRec){
	return m_RectKeyFrame.GetTimeState(t,oRec);
}
/*************************************************************************//*!
		@brief			指定時間でのフレーム番号取得
		@param[in]		t				時間

		@return			フレーム番号
*//**************************************************************************/
FORCE_INLINE MofU32 CSpriteAnimation::GetTimeFrameNo(const MofFloat t) {
	return m_RectKeyFrame.GetNowKeyFrameNo(t);
}
/*************************************************************************//*!
		@brief			アニメーションの終了時間取得<br>
						ループをする場合でも最終のフレームの時間を返す
		@param			None
				
		@return			アニメーションの終了時間
*//**************************************************************************/
FORCE_INLINE MofFloat CSpriteAnimation::GetEndTime(void){
	return m_RectKeyFrame.GetLastKeyTime();
}

//[EOF]