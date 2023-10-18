/*************************************************************************//*!
					
					@file	RenderCommand.inl
					@brief	描画コマンドクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			コマンド用のメモリ確保
		@param			None

		@return			メモリポインタ
*//**************************************************************************/
template < typename T > FORCE_INLINE LPMofVoid CRenderCommandList::AllocateCommandSpace(void){
	size_t alignedSize = sizeof(T);
	if ((m_Size - m_Offset) < alignedSize + sizeof(MofU32))
	{
		return NULL;
	}
	*reinterpret_cast< MofU32* >(m_pBuffer + m_Offset) = static_cast< MofU32 >(alignedSize);
	m_Offset += sizeof(MofU32);
	LPMofVoid pAllocation = m_pBuffer + m_Offset;
	m_Offset += alignedSize;
	return pAllocation;
}

/*************************************************************************//*!
		@brief			コマンドの追加
		@param			None

		@return			TRUE		成功<br>
		それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T > FORCE_INLINE T* CRenderCommandList::AddCommand(void){
	void* pAddress = AllocateCommandSpace< T >();
	return new (pAddress) T ();
}
/*************************************************************************//*!
		@brief			コマンドの追加
		@param[in]		p0			設定パラメーター

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T, typename P0 > FORCE_INLINE T* CRenderCommandList::AddCommand(P0& p0){
	void* pAddress = AllocateCommandSpace< T >();
	return new (pAddress) T(p0);
}
/*************************************************************************//*!
		@brief			コマンドの追加
		@param[in]		p0			設定パラメーター
		@param[in]		p1			設定パラメーター

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T, typename P0, typename P1 > FORCE_INLINE T* CRenderCommandList::AddCommand(P0& p0, P1& p1){
	void* pAddress = AllocateCommandSpace< T >();
	return new (pAddress)T(p0,p1);
}
/*************************************************************************//*!
		@brief			コマンドの追加
		@param[in]		p0			設定パラメーター
		@param[in]		p1			設定パラメーター
		@param[in]		p2			設定パラメーター

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T, typename P0, typename P1, typename P2 > FORCE_INLINE T* CRenderCommandList::AddCommand(P0& p0, P1& p1, P2& p2){
	void* pAddress = AllocateCommandSpace< T >();
	return new (pAddress)T(p0, p1, p2);
}
/*************************************************************************//*!
		@brief			コマンドの追加
		@param[in]		p0			設定パラメーター
		@param[in]		p1			設定パラメーター
		@param[in]		p2			設定パラメーター
		@param[in]		p3			設定パラメーター

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T, typename P0, typename P1, typename P2, typename P3 > FORCE_INLINE T* CRenderCommandList::AddCommand(P0& p0, P1& p1, P2& p2, P3& p3){
	void* pAddress = AllocateCommandSpace< T >();
	return new (pAddress)T(p0, p1, p2, p3);
}
/*************************************************************************//*!
		@brief			コマンドの追加
		@param[in]		p0			設定パラメーター
		@param[in]		p1			設定パラメーター
		@param[in]		p2			設定パラメーター
		@param[in]		p3			設定パラメーター
		@param[in]		p4			設定パラメーター

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T, typename P0, typename P1, typename P2, typename P3, typename P4 > FORCE_INLINE T* CRenderCommandList::AddCommand(P0& p0, P1& p1, P2& p2, P3& p3, P4& p4){
	void* pAddress = AllocateCommandSpace< T >();
	return new (pAddress)T(p0, p1, p2, p3, p4);
}
/*************************************************************************//*!
		@brief			コマンドの追加
		@param[in]		p0			設定パラメーター
		@param[in]		p1			設定パラメーター
		@param[in]		p2			設定パラメーター
		@param[in]		p3			設定パラメーター
		@param[in]		p4			設定パラメーター
		@param[in]		p5			設定パラメーター

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
template < typename T, typename P0, typename P1, typename P2, typename P3, typename P4, typename P5 > FORCE_INLINE T* CRenderCommandList::AddCommand(P0& p0, P1& p1, P2& p2, P3& p3, P4& p4, P5& p5){
	void* pAddress = AllocateCommandSpace< T >();
	return new (pAddress)T(p0, p1, p2, p3, p4, p5);
}

//[EOF]