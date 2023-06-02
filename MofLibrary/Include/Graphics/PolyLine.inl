/*************************************************************************//*!
					
					@file	PolyLine.inl
					@brief	ポリラインジオメトリ。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			先頭座標取得
		@param			None

		@return			先頭座標
*//**************************************************************************/
FORCE_INLINE CVector3& CPolyLine::GetFirstPosition(void){
	return m_pPointArray->GetData(0).Position;
}
/*************************************************************************//*!
		@brief			終端座標取得
		@param			None

		@return			終端座標
*//**************************************************************************/
FORCE_INLINE CVector3& CPolyLine::GetLastPosition(void){
	return m_pPointArray->GetData(m_pPointArray->GetArrayCount() - 1).Position;
}

//[EOF]