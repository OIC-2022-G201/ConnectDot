/*************************************************************************//*!
					
					@file	GeometryInstancedBase.inl
					@brief	ジオメトリインスタンス基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			インスタンス用バッファ設定
		@param[in]		pBuff			設定バッファ
				
		@return			TRUE			正常終了<br>
						それ以外		エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryInstancedBase::SetInstancedBuffer(LPVertexBuffer pBuff){
	m_pInstancedBuffer = pBuff;
	return TRUE;
}
/*************************************************************************//*!
		@brief			頂点バッファ取得
		@param			None

		@return			頂点バッファ
*//**************************************************************************/
FORCE_INLINE LPVertexBuffer CGeometryInstancedBase::GetVertexBuffer(void){
	return m_pVertexBuffer;
}
/*************************************************************************//*!
		@brief			頂点バッファ取得
		@param[in,out]	pOut			頂点バッファ配列<br>
										出力用のポインタがNULLなら格納されない。
		@param[in,out]	cnt				頂点バッファの数<br>
										実行時にはpOutの格納最大数を指定する。

		@return			TRUE			正常終了<br>
						それ以外		エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryInstancedBase::GetVertexBuffer(LPVertexBuffer* pOut, MofU32& cnt){
	if (!pOut)
	{
		cnt = 2;
	}
	else
	{
		if (cnt > 0){ pOut[0] = m_pVertexBuffer; }
		if (cnt > 1){ pOut[1] = m_pInstancedBuffer; }
		cnt = 2;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			頂点バッファフラグ取得
		@param			None

		@return			頂点バッファフラグ
*//**************************************************************************/
FORCE_INLINE VertexFlag CGeometryInstancedBase::GetVertexFlag(void){
	return (VertexFlag)(m_pVertexBuffer->GetVertexFlag() | m_pInstancedBuffer->GetVertexFlag());
}
/*************************************************************************//*!
		@brief			インスタンス用バッファ取得
		@param			None

		@return			インスタンス用バッファ
*//**************************************************************************/
FORCE_INLINE LPVertexBuffer CGeometryInstancedBase::GetInstancedBuffer(void){
	return m_pInstancedBuffer;
}

//[EOF]