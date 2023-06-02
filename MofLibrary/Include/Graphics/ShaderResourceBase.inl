/*************************************************************************//*!
					
					@file	ShaderResourceBase.inl
					@brief	シェーダーリソースクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CShaderResourceBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			リソースの設定
		@param[in]		pTex		データ
					
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderResourceBase::SetResource(LPTexture pTex) {
	m_pTexture = pTex;
	return TRUE;
}

/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CShaderResourceBase::GetName(void){
	return &m_Name;
}

//[EOF]