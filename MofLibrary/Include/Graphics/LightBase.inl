/*************************************************************************//*!
					
					@file	LightBase.inl
					@brief	ライト基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			ディフューズ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetDiffuse(const Vector4& c){
	m_Diffuse = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			ディフューズ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetDiffuse(const MofU32 c){
	m_Diffuse.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			アンビエント色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetAmbient(const Vector4& c){
	m_Ambient = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			アンビエント色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetAmbient(const MofU32 c){
	m_Ambient.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			スペキュラ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetSpeculer(const Vector4& c){
	m_Speculer = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			スペキュラ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetSpeculer(const MofU32 c){
	m_Speculer.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CLightBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			ディフューズ色取得
		@param			None

		@return			ディフューズ色
*//**************************************************************************/
FORCE_INLINE CVector4& CLightBase::GetDiffuse(void){
	return m_Diffuse;
}
/*************************************************************************//*!
		@brief			ディフューズ色取得
		@param			None

		@return			ディフューズ色
*//**************************************************************************/
FORCE_INLINE const CVector4& CLightBase::GetDiffuse(void) const {
	return m_Diffuse;
}
/*************************************************************************//*!
		@brief			ディフューズ色取得
		@param			None

		@return			ディフューズ色
*//**************************************************************************/
FORCE_INLINE MofU32 CLightBase::GetDiffuseU32(void) const{
	return m_Diffuse.ToU32Color();
}
/*************************************************************************//*!
		@brief			アンビエント色取得
		@param			None

		@return			アンビエント色
*//**************************************************************************/
FORCE_INLINE CVector4& CLightBase::GetAmbient(void){
	return m_Ambient;
}
/*************************************************************************//*!
		@brief			アンビエント色取得
		@param			None

		@return			アンビエント色
*//**************************************************************************/
FORCE_INLINE const CVector4& CLightBase::GetAmbient(void) const {
	return m_Ambient;
}
/*************************************************************************//*!
		@brief			アンビエント色取得
		@param			None

		@return			アンビエント色
*//**************************************************************************/
FORCE_INLINE MofU32 CLightBase::GetAmbientU32(void) const{
	return m_Ambient.ToU32Color();
}
/*************************************************************************//*!
		@brief			スペキュラ色取得
		@param			None

		@return			スペキュラ色
*//**************************************************************************/
FORCE_INLINE CVector4& CLightBase::GetSpeculer(void){
	return m_Speculer;
}
/*************************************************************************//*!
		@brief			スペキュラ色取得
		@param			None

		@return			スペキュラ色
*//**************************************************************************/
FORCE_INLINE const CVector4& CLightBase::GetSpeculer(void) const {
	return m_Speculer;
}
/*************************************************************************//*!
		@brief			スペキュラ色取得
		@param			None

		@return			スペキュラ色
*//**************************************************************************/
FORCE_INLINE MofU32 CLightBase::GetSpeculerU32(void) const{
	return m_Speculer.ToU32Color();
}

//[EOF]