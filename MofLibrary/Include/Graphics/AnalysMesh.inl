/*************************************************************************//*!
					
					@file	AnalysMesh.inl
					@brief	MOMファイルの解析を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			読み込みブロックの移動
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMesh::MoveBlockOffset(void){
	if(m_Header.BlockSize <= 0)
	{
		return TRUE;
	}
	MofU32 st = m_Header.BlockSize - (m_Offset % m_Header.BlockSize);
	m_Offset += st;
	return TRUE;
}
/*************************************************************************//*!
		@brief			MOMファイルかを判定する<br>
						ファイルの先頭がMOFMODEL_FILE_HEADERから始まればMOMファイル
		@param			None
				
		@return			TRUE		MOMファイル<br>
						それ以外	MOMファイルではない
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMesh::IsMOMFile(void){
	if(memcmp(m_pBuffer,MOFMODEL_FILE_HEADER,MOFMODEL_FILE_HEADERLEN))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			MOMファイルフッターまで解析したかを判定する<br>
						現在位置からMOFMODEL_FILE_FOOTERのデータになっていればフッター
		@param			None
				
		@return			TRUE							フッター<br>
						それ以外						まだフッターではない<br>
						MOFMODEL_RESULTERROR_NOTFOOTER	フッターじゃないのにファイルが終了している
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMesh::IsMOMFooter(void){
	//ファイルサイズ超過
	if(m_Offset >= m_Size)
	{
		return MOFMODEL_RESULTERROR_NOTFOOTER;
	}
	if(memcmp(&m_pBuffer[m_Offset],MOFMODEL_FILE_FOOTER,MOFMODEL_FILE_FOOTERLEN))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			テクスチャ検索配列設定
		@param[in]		pTex		テクスチャ検索配列
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMesh::SetTextureArray(LPTextureArray pTex){
	m_pTextureArray = pTex;
	return TRUE;
}

//[EOF]