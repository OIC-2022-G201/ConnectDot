/*************************************************************************//*!
					
					@file	PSDReader.inl
					@brief	PSD読み込み用クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			コピーライト読み込み
		@param			None
				
		@return			読み込んだデータサイズを返す
*//**************************************************************************/
FORCE_INLINE MofS32 CPSDReader::ReadCopyright(void){
	MofS16 Value = GetShort(m_SwapEndian);
	if(Value)
	{
		m_Copyright = TRUE;
	}
	return sizeof(MofS16);
}
/*************************************************************************//*!
		@brief			グローバルアングル読み込み
		@param			None
				
		@return			読み込んだデータサイズを返す
*//**************************************************************************/
FORCE_INLINE MofS32 CPSDReader::ReadGlobalAngle(void){
	m_GlobalAngle = GetLong(m_SwapEndian);
	return sizeof(MofS32);
}
/*************************************************************************//*!
		@brief			色数読み込み
		@param			None
				
		@return			読み込んだデータサイズを返す
*//**************************************************************************/
FORCE_INLINE MofS32 CPSDReader::ReadColorCount(void){
	m_ColorCount = GetShort(m_SwapEndian);
	return sizeof(MofS16);
}
/*************************************************************************//*!
		@brief			インデックス読み込み
		@param			None
				
		@return			読み込んだデータサイズを返す
*//**************************************************************************/
FORCE_INLINE MofS32 CPSDReader::ReadTransparentIndex(void){
	m_TransparentIndex = GetShort(m_SwapEndian);
	return sizeof(MofS16);
}
/*************************************************************************//*!
		@brief			読み込みリソース情報を初期化する
		@param[in,out]	pResource	出力リソース
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CPSDReader::ResourceReset(PSD_IMAGE_RESOURCE* pResource){
	if(!pResource)
	{
		return FALSE;
	}
	pResource->Length = -1;
	pResource->Type = 0;
	pResource->ID = -1;
	pResource->Size = -1;
	MOF_SAFE_FREE(pResource->pName,"CPSDReader ResourceReset");
	return TRUE;
}
/*************************************************************************//*!
		@brief			PSDヘッダー取得
		@param			None

		@return			PSDヘッダー
*//**************************************************************************/
FORCE_INLINE LPPSD_HEADER CPSDReader::GetHeader(void){
	return &m_Header;
}
/*************************************************************************//*!
		@brief			PSDレイヤー情報取得
		@param			None

		@return			PSDレイヤー情報
*//**************************************************************************/
FORCE_INLINE LPPSDLayerInfoArray CPSDReader::GetPSDLayerInfoList(void){
	return &m_LayerInfo;
}

//[EOF]