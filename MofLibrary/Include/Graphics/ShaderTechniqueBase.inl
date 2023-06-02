/*************************************************************************//*!
					
					@file	ShaderTechniqueBase.inl
					@brief	シェーダーテクニック基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CShaderTechniqueBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CShaderTechniqueBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			パスの数取得
		@param			None

		@return			パスの数
*//**************************************************************************/
FORCE_INLINE MofU32 CShaderTechniqueBase::GetPassCount(void) const{
	if(!m_pPassArray)
	{
		return 0;
	}
	return m_pPassArray->GetArrayCount();
}
/*************************************************************************//*!
		@brief			パスの取得
		@param[in]		n			パス番号

		@return			パス
*//**************************************************************************/
FORCE_INLINE LPShaderPass CShaderTechniqueBase::GetPass(MofU32 n){
	if(!m_pPassArray)
	{
		return NULL;
	}
	if(n >= m_pPassArray->GetArrayCount())
	{
		return NULL;
	}
	return m_pPassArray->GetData(n);
}

//[EOF]