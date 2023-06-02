/*************************************************************************//*!
					
					@file	ShaderLinkerBase.inl
					@brief	シェーダー基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CShaderLinkerBase::SetName(LPCMofChar pName) {
	return FALSE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CShaderLinkerBase::GetName(void) {
	return m_pShader->GetName();
}
/*************************************************************************//*!
		@brief			変数とのリンクの取得
		@param			None

		@return			変数とのリンク
*//**************************************************************************/
FORCE_INLINE IShaderLinker::LPLinkArray CShaderLinkerBase::GetLink(void) {
	return m_pLink;
}
/*************************************************************************//*!
		@brief			テクスチャとのリンクの取得
		@param			None

		@return			テクスチャとのリンク
*//**************************************************************************/
FORCE_INLINE IShaderLinker::LPLinkTextureArray CShaderLinkerBase::GetTextureLink(void) {
	return m_pLinkTexture;
}
/*************************************************************************//*!
		@brief			シェーダーの取得
		@param			None

		@return			シェーダー
*//**************************************************************************/
FORCE_INLINE LPShader CShaderLinkerBase::GetShader(void) {
	return m_pShader;
}
/*************************************************************************//*!
		@brief			シェーダーバインドの取得
		@param			None

		@return			シェーダーバインド
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderLinkerBase::GetShaderBind(void) {
	return m_pShaderBind;
}

//[EOF]