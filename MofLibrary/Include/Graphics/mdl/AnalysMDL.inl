/*************************************************************************//*!
					
					@file	AnalysMDL.inl
					@brief	MDLファイルの解析を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			MDLファイルかを判定する
		@param			None
				
		@return			TRUE		MDLファイル<br>
						それ以外	MDLファイルではない
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMDL::IsMeshFile(void){
	if(memcmp(m_pBuffer,MBSMODEL_FILE_HEADER,MBSMODEL_FILE_HEADERLEN))
	{
		return FALSE;
	}
	return TRUE;
}

//[EOF]