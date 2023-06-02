/*************************************************************************//*!
					
					@file	CRC32.inl
					@brief	CRC32ハッシュ生成を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			ハッシュ生成
		@param[in]		pStr			ハッシュ生成文字列

		@return			発生したハッシュコードを返す
*//**************************************************************************/
FORCE_INLINE MofU32 CCRC32::CreateHash(LPCMofChar pStr){
	if(!pStr)
	{
		return MOF_U32_MAX;
	}
	return CreateHash(pStr,MOF_StrLength(pStr));
}
/*************************************************************************//*!
		@brief			ハッシュ生成
		@param[in]		pStr			ハッシュ生成文字列

		@return			発生したハッシュコードを返す
*//**************************************************************************/
FORCE_INLINE MofU32 CCRC32::CreateHash(const LPString pStr){
	if(!pStr)
	{
		return MOF_U32_MAX;
	}
	return CreateHash(pStr->GetString(),pStr->GetStringSize());
}

//[EOF]