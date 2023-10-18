/*************************************************************************//*!
					
					@file	AnalysSprite.inl
					@brief	MOSファイルの解析を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			読み込みブロックの移動
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysSprite::MoveBlockOffset(void){
	if(m_Header.BlockSize <= 0)
	{
		return TRUE;
	}
	MofU32 st = m_Header.BlockSize - (m_Offset % m_Header.BlockSize);
	m_Offset += st;
	return TRUE;
}
/*************************************************************************//*!
		@brief			MOSファイルかを判定する<br>
						ファイルの先頭がMOFSPRITE_FILE_HEADERから始まればMOSファイル
		@param			None
				
		@return			TRUE		MOSファイル<br>
						それ以外	MOSファイルではない
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysSprite::IsMOSFile(void){
	if(memcmp(m_pBuffer,MOFSPRITE_FILE_HEADER,MOFSPRITE_FILE_HEADERLEN))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			MOSファイルフッターまで解析したかを判定する<br>
						現在位置からMOFSPRITE_FILE_FOOTERのデータになっていればフッター
		@param			None
				
		@return			TRUE							フッター<br>
						それ以外						まだフッターではない<br>
						MOFSPRITE_RESULTERROR_NOTFOOTER	フッターじゃないのにファイルが終了している
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysSprite::IsMOSFooter(void){
	//ファイルサイズ超過
	if(m_Offset >= m_Size)
	{
		return MOFSPRITE_RESULTERROR_NOTFOOTER;
	}
	if(memcmp(&m_pBuffer[m_Offset],MOFSPRITE_FILE_FOOTER,MOFSPRITE_FILE_FOOTERLEN))
	{
		return FALSE;
	}
	return TRUE;
}

//[EOF]