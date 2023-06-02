/*************************************************************************//*!
					
					@file	PolyCircle.inl
					@brief	ポリサークルジオメトリ。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			周囲色設定
		@param[in]		cn				周番号
		@param[in]		c				色

		@return			TRUE			正常終了<br>
		それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CPolyCircle::SetColor(MofU32 cn, CVector4& c){
	//編集用情報取り出し
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	if (cn >= mc)
	{
		return FALSE;
	}
	pPoint[cn].Color = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			周囲半径設定
		@param[in]		cn				周番号
		@param[in]		r				半径

		@return			TRUE			正常終了<br>
		それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CPolyCircle::SetRadius(MofU32 cn, MofFloat r){
	//編集用情報取り出し
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	if (cn >= mc)
	{
		return FALSE;
	}
	pPoint[cn].Radius = r;
	return TRUE;
}
/*************************************************************************//*!
		@brief			周囲半径比率維持設定
		@param[in]		cn				周番号
		@param[in]		r				半径

		@return			TRUE			正常終了<br>
		それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CPolyCircle::SetRadiusRatio(MofU32 cn, MofFloat r){
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	if (cn >= mc)
	{
		return FALSE;
	}
	MofFloat ar = GetRadius();
	MofFloat outr = ar - pPoint[cn].Radius;
	MofFloat nor = ar - r;
	for (MofU32 i = 1; i < mc; i++)
	{
		if (i == cn)
		{
			pPoint[i].Radius = r;
		}
		else
		{
			pPoint[i].Radius = nor * (pPoint[i].Radius / outr);
		}
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			合計半径取得
		@param			None

		@return			合計半径
*//**************************************************************************/
FORCE_INLINE MofFloat CPolyCircle::GetRadius(void){
	//編集用情報取り出し
	MofFloat re = 0.0f;
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	for (MofU32 i = 1; i < mc; i++)
	{
		re += pPoint[i].Radius;
	}
	return re;
}
/*************************************************************************//*!
		@brief			半径取得
		@param[in]		cn				周番号

		@return			半径
*//**************************************************************************/
FORCE_INLINE MofFloat CPolyCircle::GetRadius(MofU32 cn){
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	if (cn >= mc)
	{
		return 0.0f;
	}
	return pPoint[cn].Radius;
}
/*************************************************************************//*!
		@brief			円周の数取得
		@param			None

		@return			円周の数
*//**************************************************************************/
FORCE_INLINE MofU32 CPolyCircle::GetCircleCount(void){
	return m_pPointArray->GetArrayCount();
}
/*************************************************************************//*!
		@brief			円周取得
		@param			None

		@return			円周
*//**************************************************************************/
FORCE_INLINE LPPOLYCIRCLEPOINT CPolyCircle::GetCircleArray(void){
	return m_pPointArray->GetArray();
}

//[EOF]