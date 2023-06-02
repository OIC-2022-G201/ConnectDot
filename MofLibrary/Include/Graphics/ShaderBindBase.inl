/*************************************************************************//*!
					
					@file	ShaderBindBase.inl
					@brief	シェーダーバインド基底インターフェイス。<br>
							各設定バッファや入力レイアウトを定義し各利用シェーダー毎にパイプラインに設定する。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			設定パラメーターを取得する
		@param			None

		@return			パラメーター
*//**************************************************************************/
FORCE_INLINE LPShaderBufferArray CShaderBindBase::GetShaderBuffer(void){
	return m_pBufferArray;
}
/*************************************************************************//*!
		@brief			設定パラメーターを取得する
		@param[in]		n				番号

		@return			パラメーター
*//**************************************************************************/
FORCE_INLINE LPShaderBuffer CShaderBindBase::GetShaderBuffer(MofU32 n){
	return m_pBufferArray->GetData(n);
}
/*************************************************************************//*!
		@brief			設定パラメーターを取得する
		@param[in]		pName			名前

		@return			パラメーター
*//**************************************************************************/
FORCE_INLINE LPShaderBuffer CShaderBindBase::GetShaderBufferByName(LPCMofChar pName){
	LPShaderBuffer* re = m_pBufferArray->Find(pName);
	if (!re)
	{
		return NULL;
	}
	return *re;
}
/*************************************************************************//*!
		@brief			設定リソースを取得する
		@param			None

		@return			リソース
*//**************************************************************************/
FORCE_INLINE LPShaderResourceArray CShaderBindBase::GetShaderResource(void) {
	return m_pResourceArray;
}
/*************************************************************************//*!
		@brief			設定リソースを取得する
		@param[in]		n				番号

		@return			リソース
*//**************************************************************************/
FORCE_INLINE LPShaderResource CShaderBindBase::GetShaderResource(MofU32 n) {
	return m_pResourceArray->GetData(n);
}
/*************************************************************************//*!
		@brief			設定リソースを取得する
		@param[in]		pName			名前

		@return			リソース
*//**************************************************************************/
FORCE_INLINE LPShaderResource CShaderBindBase::GetShaderResourceByName(LPCMofChar pName){
	LPShaderResource* re = m_pResourceArray->Find(pName);
	if (!re)
	{
		return NULL;
	}
	return *re;
}

//[EOF]