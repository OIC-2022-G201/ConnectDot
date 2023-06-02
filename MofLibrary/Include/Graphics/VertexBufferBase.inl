/*************************************************************************//*!
					
					@file	VertexBufferBase.inl
					@brief	頂点バッファ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			頂点サイズの計算
		@param[in]		Flag			計算するフラグの組み合わせ

		@return			必要なサイズ
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::CalculateVertexSize(VertexFlag Flag){
	//サイズ
	MofU32 Size = 0;
	//頂点座標
	if(Flag & VERTEXFLAG_POSITION)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//法線
	if(Flag & VERTEXFLAG_NORMAL)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//接線
	if(Flag & VERTEXFLAG_TANGENT)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//従法線
	if(Flag & VERTEXFLAG_BINORMAL)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//ＵＶ
	if(Flag & VERTEXFLAG_TEXTURECOORDS1)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS2)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS3)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS4)
	{
		Size += sizeof(MofFloat) * 2;
	}
	//色
	if(Flag & VERTEXFLAG_COLOR1)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF1)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(Flag & VERTEXFLAG_COLOR2)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF2)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(Flag & VERTEXFLAG_COLOR3)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF3)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(Flag & VERTEXFLAG_COLOR4)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF4)
	{
		Size += sizeof(MofFloat) * 4;
	}
	//ウェイト
	if(Flag & VERTEXFLAG_WAIT1)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (Flag & VERTEXFLAG_WAIT2)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (Flag & VERTEXFLAG_WAIT3)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (Flag & VERTEXFLAG_WAIT4)
	{
		Size += sizeof(MofFloat) * 5;
	}
	//頂点サイズ
	if(Flag & VERTEXFLAG_POINTSIZE)
	{
		Size += sizeof(MofFloat);
	}
	//マトリクス
	if (Flag & VERTEXFLAG_MATRIX)
	{
		Size += sizeof(MofFloat) * 16;
	}
	return Size;
}
/*************************************************************************//*!
		@brief			頂点フラグ数の計算
		@param[in]		Flag			計算するフラグの組み合わせ

		@return			必要なフラグ数
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::CalculateVertexFlagCount(VertexFlag Flag){
	//数
	MofU32 Count = 0;
	//頂点座標
	if(Flag & VERTEXFLAG_POSITION)
	{
		Count++;
	}
	//法線
	if(Flag & VERTEXFLAG_NORMAL)
	{
		Count++;
	}
	//接線
	if(Flag & VERTEXFLAG_TANGENT)
	{
		Count++;
	}
	//従法線
	if(Flag & VERTEXFLAG_BINORMAL)
	{
		Count++;
	}
	//ＵＶ
	if(Flag & VERTEXFLAG_TEXTURECOORDS1)
	{
		Count++;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS2)
	{
		Count++;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS3)
	{
		Count++;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS4)
	{
		Count++;
	}
	//色
	if((Flag & VERTEXFLAG_COLOR1) || (Flag & VERTEXFLAG_COLORF1))
	{
		Count++;
	}
	if((Flag & VERTEXFLAG_COLOR2) || (Flag & VERTEXFLAG_COLORF2))
	{
		Count++;
	}
	if((Flag & VERTEXFLAG_COLOR3) || (Flag & VERTEXFLAG_COLORF3))
	{
		Count++;
	}
	if((Flag & VERTEXFLAG_COLOR4) || (Flag & VERTEXFLAG_COLORF4))
	{
		Count++;
	}
	//ウェイト
	if(Flag & VERTEXFLAG_WAIT1)
	{
		Count++;
		Count++;
	}
	if (Flag & VERTEXFLAG_WAIT2)
	{
		Count++;
		Count++;
	}
	if (Flag & VERTEXFLAG_WAIT3)
	{
		Count++;
		Count++;
	}
	if (Flag & VERTEXFLAG_WAIT4)
	{
		Count++;
		Count++;
	}
	//頂点サイズ
	if(Flag & VERTEXFLAG_POINTSIZE)
	{
		Count++;
	}
	//マトリクス
	if (Flag & VERTEXFLAG_MATRIX)
	{
		Count++;
	}
	return Count;
}
/*************************************************************************//*!
		@brief			特定フラグのオフセット位置の計算
		@param[in]		OFlag			調べたいフラグ

		@return			フラグのオフセット位置
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::CalculateVertexOffset(VertexFlag OFlag){
	return CalculateVertexOffset(m_Flag, OFlag);
}
/*************************************************************************//*!
		@brief			特定フラグのオフセット位置の計算
		@param[in]		Flag			計算するフラグの組み合わせ
		@param[in]		OFlag			調べたいフラグ

		@return			フラグのオフセット位置
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::CalculateVertexOffset(VertexFlag Flag,VertexFlag OFlag){
	//サイズ
	MofU32 Size = 0;
	//頂点座標
	if(OFlag == VERTEXFLAG_POSITION)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_POSITION)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//法線
	if(OFlag == VERTEXFLAG_NORMAL)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_NORMAL)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//接線
	if(OFlag == VERTEXFLAG_TANGENT)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TANGENT)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//従法線
	if(OFlag == VERTEXFLAG_BINORMAL)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_BINORMAL)
	{
		Size += sizeof(MofFloat) * 3;
	}
	//ＵＶ
	if(OFlag == VERTEXFLAG_TEXTURECOORDS1)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS1)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(OFlag == VERTEXFLAG_TEXTURECOORDS2)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS2)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(OFlag == VERTEXFLAG_TEXTURECOORDS3)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS3)
	{
		Size += sizeof(MofFloat) * 2;
	}
	if(OFlag == VERTEXFLAG_TEXTURECOORDS4)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_TEXTURECOORDS4)
	{
		Size += sizeof(MofFloat) * 2;
	}
	//色
	if(OFlag == VERTEXFLAG_COLOR1 || OFlag == VERTEXFLAG_COLORF1)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_COLOR1)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF1)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(OFlag == VERTEXFLAG_COLOR2 || OFlag == VERTEXFLAG_COLORF2)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_COLOR2)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF2)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(OFlag == VERTEXFLAG_COLOR3 || OFlag == VERTEXFLAG_COLORF3)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_COLOR3)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF3)
	{
		Size += sizeof(MofFloat) * 4;
	}
	if(OFlag == VERTEXFLAG_COLOR4 || OFlag == VERTEXFLAG_COLORF4)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_COLOR4)
	{
#ifdef		MOFLIB_OPENGL
		Size += sizeof(MofFloat) * 4;
#else
		Size += sizeof(MofU32);
#endif
	}
	else if(Flag & VERTEXFLAG_COLORF4)
	{
		Size += sizeof(MofFloat) * 4;
	}
	//ウェイト
	if(OFlag == VERTEXFLAG_WAIT1)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_WAIT1)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if(OFlag == VERTEXFLAG_WAIT2)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_WAIT2)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (OFlag == VERTEXFLAG_WAIT3)
	{
		return Size;
	}
	if (Flag & VERTEXFLAG_WAIT3)
	{
		Size += sizeof(MofFloat) * 5;
	}
	if (OFlag == VERTEXFLAG_WAIT4)
	{
		return Size;
	}
	if (Flag & VERTEXFLAG_WAIT4)
	{
		Size += sizeof(MofFloat) * 5;
	}
	//頂点サイズ
	if(OFlag == VERTEXFLAG_POINTSIZE)
	{
		return Size;
	}
	if(Flag & VERTEXFLAG_POINTSIZE)
	{
		Size += sizeof(MofFloat);
	}
	//マトリクス
	if (OFlag == VERTEXFLAG_MATRIX)
	{
		return Size;
	}
	if (Flag & VERTEXFLAG_MATRIX)
	{
		Size += sizeof(MofFloat) * 16;
	}
	return Size;
}
/*************************************************************************//*!
		@brief			バッファの設定
		@param[in]		Usage			利用方法
				
		@return			TRUE			正常終了<br>
						それ以外		エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CVertexBufferBase::SetUsage(const BufferAccess Usage) {
	m_Usage = Usage;
	return TRUE;
}
/*************************************************************************//*!
		@brief			頂点取得
		@param			None

		@return			頂点の取得
*//**************************************************************************/
FORCE_INLINE LPMofVoid CVertexBufferBase::GetVertex(void) const{
	return m_pVertex;
}
/*************************************************************************//*!
		@brief			頂点サイズ取得
		@param			None

		@return			頂点サイズの取得
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::GetVertexSize(void) const{
	return m_Size;
}
/*************************************************************************//*!
		@brief			頂点属性数取得
		@param			None

		@return			頂点属性数の取得
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::GetVertexElementCount(void) const{
	return m_ElementCount;
}
/*************************************************************************//*!
		@brief			頂点フラグ取得
		@param			None

		@return			頂点フラグの取得
*//**************************************************************************/
FORCE_INLINE VertexFlag CVertexBufferBase::GetVertexFlag(void) const{
	return m_Flag;
}
/*************************************************************************//*!
		@brief			頂点数取得
		@param			None

		@return			頂点数の取得
*//**************************************************************************/
FORCE_INLINE MofU32 CVertexBufferBase::GetVertexCount(void) const{
	return m_Count;
}

//[EOF]