/*************************************************************************//*!
					
					@file	AnalysX.h
					@brief	Xファイルの解析を行いCXModelクラスに設定を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			Xファイルかを判定する<br>
						ファイルの先頭がxofから始まればXファイル
		@param			None
				
		@return			TRUE		Xファイル<br>
						それ以外	Xファイルではない
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysX::IsXFile(void){
	//最初かxofじゃなければXファイルじゃない
	if(memcmp(m_pBuffer,MOFSTR("xof "),4 * sizeof(MofChar)))
	{
		return FALSE;
	}
	return TRUE;
}

/*************************************************************************//*!
		@brief			テキスト形式のXファイルかを判定する<br>
						ファイルの先頭がxofから始まりtxt指定があればテキスト形式のXファイル
		@param			None
				
		@return			TRUE		テキスト形式のXファイル<br>
						それ以外	テキスト形式のXファイルではない
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysX::IsTextXFile(void){
	//Xファイルか判断
	if(!IsXFile())
	{
		return FALSE;
	}
	//txtか判断
	if(memcmp(m_pBuffer + 8 * sizeof(MofChar),MOFSTR("txt "),4 * sizeof(MofChar)))
	{
		return FALSE;
	}
	return TRUE;
}

//[EOF]