/*************************************************************************//*!
					
					@file	ShaderBase.inl
					@brief	シェーダー基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CShaderBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			テクニック設定
		@param[in]		tn			テクニック番号
					
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderBase::SetTechnique(MofU32 tn){
	m_NowTechnique = tn;
	return TRUE;
}
/*************************************************************************//*!
		@brief			テクニック設定
		@param[in]		pName		テクニック名
					
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderBase::SetTechniqueByName(LPCMofChar pName){
	if (!m_pTechniqueArray || !pName)
	{
		return FALSE;
	}
	for (MofU32 i = 0; i < m_pTechniqueArray->GetArrayCount(); i++)
	{
		if (m_pTechniqueArray->GetData(i)->GetName()->Compare(pName) == 0)
		{
			m_NowTechnique = i;
			return TRUE;
		}
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CShaderBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			テクニックの数取得
		@param			None

		@return			テクニックの数
*//**************************************************************************/
FORCE_INLINE MofU32 CShaderBase::GetTechniqueCount(void) const{
	if(!m_pTechniqueArray)
	{
		return 0;
	}
	return m_pTechniqueArray->GetArrayCount();
}
/*************************************************************************//*!
		@brief			テクニック取得
		@param			None

		@return			テクニック<br>
						存在しない場合NULL
*//**************************************************************************/
FORCE_INLINE LPShaderTechnique CShaderBase::GetTechnique(void){
	if (!m_pTechniqueArray)
	{
		return NULL;
	}
	if (m_NowTechnique >= m_pTechniqueArray->GetArrayCount())
	{
		return NULL;
	}
	return m_pTechniqueArray->GetData(m_NowTechnique);
}
/*************************************************************************//*!
		@brief			テクニック取得
		@param[in]		n			テクニック

		@return			テクニック<br>
						存在しない場合NULL
*//**************************************************************************/
FORCE_INLINE LPShaderTechnique CShaderBase::GetTechnique(MofU32 n){
	if(!m_pTechniqueArray)
	{
		return NULL;
	}
	if(n >= m_pTechniqueArray->GetArrayCount())
	{
		return NULL;
	}
	return m_pTechniqueArray->GetData(n);
}
/*************************************************************************//*!
		@brief			テクニック取得
		@param[in]		pName		テクニック名

		@return			テクニック<br>
						存在しない場合NULL
*//**************************************************************************/
FORCE_INLINE LPShaderTechnique CShaderBase::GetTechniqueByName(LPCMofChar pName){
	if(!m_pTechniqueArray || !pName)
	{
		return NULL;
	}
	for(MofU32 i = 0;i < m_pTechniqueArray->GetArrayCount();i++)
	{
		if(m_pTechniqueArray->GetData(i)->GetName()->Compare(pName) == 0)
		{
			return m_pTechniqueArray->GetData(i);
		}
	}
	return NULL;
}

//[EOF]