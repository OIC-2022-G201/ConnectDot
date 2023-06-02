/*************************************************************************//*!
					
					@file	IndexBufferBase.inl
					@brief	インデックスバッファ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			インデックス取得
		@param			None

		@return			インデックスの取得
*//**************************************************************************/
FORCE_INLINE LPMofVoid CIndexBufferBase::GetIndex(void) const{
	return m_pIndex;
}
/*************************************************************************//*!
		@brief			インデックス取得
		@param			None

		@return			インデックスの取得<br>
						サイズが16bitインデックスではない場合NULL
*//**************************************************************************/
FORCE_INLINE LPMofU16 CIndexBufferBase::GetIndexU16(void){
	if(m_Size != sizeof(MofU16))
	{
		return NULL;
	}
	return (LPMofU16)m_pIndex;
}
/*************************************************************************//*!
		@brief			インデックス取得
		@param			None

		@return			インデックスの取得<br>
						サイズが32bitインデックスではない場合NULL
*//**************************************************************************/
FORCE_INLINE LPMofU32 CIndexBufferBase::GetIndexU32(void){
	if(m_Size != sizeof(MofU32))
	{
		return NULL;
	}
	return (LPMofU32)m_pIndex;
}
/*************************************************************************//*!
		@brief			インデックスサイズ取得
		@param			None

		@return			インデックスサイズの取得
*//**************************************************************************/
FORCE_INLINE MofU32 CIndexBufferBase::GetIndexSize(void) const{
	return m_Size;
}
/*************************************************************************//*!
		@brief			インデックス数取得
		@param			None

		@return			インデックス数の取得
*//**************************************************************************/
FORCE_INLINE MofU32 CIndexBufferBase::GetIndexCount(void) const{
	return m_Count;
}

//[EOF]