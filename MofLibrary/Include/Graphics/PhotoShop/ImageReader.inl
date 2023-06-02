/*************************************************************************//*!
					
					@file	ImageReader.inl
					@brief	PSD内部画像保存用クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CImageReader::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CImageReader::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			イメージ配列取得
		@param			None

		@return			イメージ配列
*//**************************************************************************/
FORCE_INLINE LPImageDataArray CImageReader::GetImage(void){
	return &m_ImageData;
}
/*************************************************************************//*!
		@brief			イメージ名取得
		@param[in]		Index			配列内番号

		@return			イメージ名
*//**************************************************************************/
FORCE_INLINE LPString CImageReader::GetImageName(MofS32 Index){
	if(Index >= GetImageCount())
	{
		return NULL;
	}
	LPMOFIMAGEDATA pData = m_ImageData.GetData(Index);
	return &pData->Name;
}
/*************************************************************************//*!
		@brief			イメージデータ取得
		@param[in]		Index			配列内番号

		@return			イメージデータ
*//**************************************************************************/
FORCE_INLINE MofU8* CImageReader::GetImageData(MofS32 Index){
	if(Index >= GetImageCount())
	{
		return NULL;
	}
	LPMOFIMAGEDATA pData = m_ImageData.GetData(Index);
	return pData->pData;
}
/*************************************************************************//*!
		@brief			イメージデータサイズ取得
		@param[in]		Index			配列内番号

		@return			イメージデータサイズ
*//**************************************************************************/
FORCE_INLINE MofU32 CImageReader::GetImageDataSize(MofS32 Index){
	if(Index >= GetImageCount())
	{
		return NULL;
	}
	LPMOFIMAGEDATA pData = m_ImageData.GetData(Index);
	return pData->Size;
}
/*************************************************************************//*!
		@brief			イメージデータ配列数取得
		@param			None

		@return			イメージデータ配列数
*//**************************************************************************/
FORCE_INLINE MofU32 CImageReader::GetImageCount(void) const {
	return m_ImageData.GetArrayCount();
}

//[EOF]