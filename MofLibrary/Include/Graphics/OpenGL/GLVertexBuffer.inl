/*************************************************************************//*!
					
					@file	GLVertexBuffer.inl
					@brief	OpenGL頂点バッファクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			頂点バッファ取得
		@param			None

		@return			頂点バッファの取得
*//**************************************************************************/
FORCE_INLINE MofVertexBuffer CGLVertexBuffer::GetBuffer(void) const{
	return m_Buffer;
}

//[EOF]