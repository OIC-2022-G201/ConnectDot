/*************************************************************************//*!
					
					@file	DShowMovie.h
					@brief	DirectShow動画クラス。

															@author	CDW
															@date	2015.11.23
*//**************************************************************************/

/*************************************************************************//*!
		@brief			レート設定
		@param[in]		Rate			レート
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CDShowMovie::SetRate(MofDouble Rate){
	HRESULT hr = m_pMP->put_Rate(Rate);
	if(FAILED(hr))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			音量設定
		@param[in]		Vol				音量(0.0(無音)～1.0(通常))
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CDShowMovie::SetVolume(MofFloat Vol){
	long lv = MOF_CLIPING(1.0f-Vol,0.0f,1.0f)*-10000;
	HRESULT hr = m_pBA->put_Volume(lv);
	if(FAILED(hr))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			
		@param			None

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CDShowMovie::SetForeground(void){
	//前面に持っていく
	HRESULT hr = m_pVW->SetWindowForeground(OATRUE);
	if(FAILED(hr))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			現在位置取得
		@param			None

		@return			現在位置
*//**************************************************************************/
FORCE_INLINE MofDouble CDShowMovie::GetPosition(void){
	if (!m_pMP)
	{
		return 0.0f;
	}
	//現在再生位置
	REFTIME Pos;
	m_pMP->get_CurrentPosition(&Pos);
	return Pos;
}
/*************************************************************************//*!
		@brief			終了時間取得
		@param			None

		@return			終了時間
*//**************************************************************************/
FORCE_INLINE MofDouble CDShowMovie::GetEndTime(void){
	if (!m_pMP)
	{
		return 0.0f;
	}
	//終了時間
	REFTIME Time = 0;
	m_pMP->get_StopTime(&Time);
	return Time;
}
/*************************************************************************//*!
		@brief			レート取得
		@param			None

		@return			レート
*//**************************************************************************/
FORCE_INLINE MofDouble CDShowMovie::GetRate(void){
	//レート
	REFTIME Rate = 0;
	m_pMP->get_Rate(&Rate);
	return Rate;
}
/*************************************************************************//*!
		@brief			音量取得
		@param			None

		@return			音量(0.0(無音)～1.0(通常))
*//**************************************************************************/
FORCE_INLINE MofFloat CDShowMovie::GetVolume(void){
	//音量
	long lv = 0;
	m_pBA->get_Volume(&lv);
	return 1.0f-((float)lv/-10000);
}
/*************************************************************************//*!
		@brief			子供フラグ取得
		@param			None

		@return			子供フラグ
*//**************************************************************************/
FORCE_INLINE MofBool CDShowMovie::GetChildFlag(void){
	return m_ChildWindow;
}
/*************************************************************************//*!
		@brief			バッファのサイズを取得
		@param			None

		@return			バッファのサイズ
*//**************************************************************************/
FORCE_INLINE MofU32 CDShowMovie::GetSamplesBufferSize(void){
	return m_BufferSize;
}
/*************************************************************************//*!
		@brief			テクスチャ取得
		@param			None

		@return			テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CDShowMovie::GetTexture(void){
	return m_pTexture;
}
