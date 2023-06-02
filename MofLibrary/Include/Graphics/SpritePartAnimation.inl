/*************************************************************************//*!
					
					@file	SpritePartAnimation.inl
					@brief	スプライトパーツアニメーション基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			ループフラグがあるかを判定する
		@param			None
				
		@return			TRUE			ループする<br>
						FALSE			ループしない
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartAnimation::IsLoop(void){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->IsLoop())
		{
			return TRUE;
		}
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			モーションのループフラグの設定
		@param[in]		bLoop			ループフラグ
				
		@return			TRUE			成功<br>
						それ以外		失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartAnimation::SetLoop(MofBool bLoop){
	if(!m_pAnimationKey)
	{
		return FALSE;
	}
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		m_pAnimationKey->GetData(i)->SetLoop(bLoop);
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CSpritePartAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			キー取得
		@param			None

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPSpriteAnimationKeyArray CSpritePartAnimation::GetAnimationKey(void){
	return m_pAnimationKey;
}
/*************************************************************************//*!
		@brief			キー取得
		@param[in]		t				キータイプ

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPFloatKeyFrameArray CSpritePartAnimation::GetAnimationFloatKey(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pFloatKey;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			キー取得
		@param[in]		t				キータイプ

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPBoolKeyFrameArray CSpritePartAnimation::GetAnimationBoolKey(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pBoolKey;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			キー取得
		@param[in]		t				キータイプ

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPS32KeyFrameArray CSpritePartAnimation::GetAnimationS32Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pS32Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			キー取得
		@param[in]		t				キータイプ

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPU32KeyFrameArray CSpritePartAnimation::GetAnimationU32Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pU32Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			キー取得
		@param[in]		t				キータイプ

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPRectangleKeyFrameArray CSpritePartAnimation::GetAnimationRectKey(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pRectKey;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			キー取得
		@param[in]		t				キータイプ

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CSpritePartAnimation::GetAnimationVector3Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pVector3Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			キー取得
		@param[in]		t				キータイプ

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPVector2KeyFrameArray CSpritePartAnimation::GetAnimationVector2Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pVector2Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			キー取得
		@param[in]		t				キータイプ

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPVector4KeyFrameArray CSpritePartAnimation::GetAnimationVector4Key(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pVector4Key;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			キー取得
		@param[in]		t				キータイプ

		@return			キーの取得
*//**************************************************************************/
FORCE_INLINE LPQuaternionKeyFrameArray CSpritePartAnimation::GetAnimationQuaternionKey(SpriteAnimationKeyType t){
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		if(m_pAnimationKey->GetData(i)->Type == t)
		{
			return m_pAnimationKey->GetData(i)->pQuaternionKey;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			アニメーションの終了時間取得<br>
						ループをする場合でも最終のフレームの時間を返す
		@param			None
				
		@return			アニメーションの終了時間
*//**************************************************************************/
FORCE_INLINE MofFloat CSpritePartAnimation::GetEndTime(void){
	//時間
	MofFloat Time = 0.0f;
	for(MofU32 i = 0;i < m_pAnimationKey->GetArrayCount();i++)
	{
		Time = MOF_MAX(Time,m_pAnimationKey->GetData(i)->GetLastKeyTime());
	}
	return Time;
}

//[EOF]