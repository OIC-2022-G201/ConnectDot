/*************************************************************************//*!
					
					@file	MaterialBase.inl
					@brief	マテリアル基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetName(LPCMofChar pName){
	return Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			ディフューズ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetDiffuse(const Vector4& c){
	Diffuse = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			ディフューズ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetDiffuse(const MofU32 c){
	Diffuse.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			アンビエント色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetAmbient(const Vector4& c){
	Ambient = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			アンビエント色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetAmbient(const MofU32 c){
	Ambient.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			スペキュラ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetSpeculer(const Vector4& c){
	Speculer = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			スペキュラ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetSpeculer(const MofU32 c){
	Speculer.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			エミッシブ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetEmissive(const Vector4& c){
	Emissive = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			エミッシブ色設定
		@param[in]		c			色
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetEmissive(const MofU32 c){
	Emissive.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			スペキュラ強度取得
		@param			pow			強度
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetPower(MofFloat pow){
	Power = pow;
	return TRUE;
}
/*************************************************************************//*!
		@brief			ブレンディング取得
		@param			bld			ブレンディング
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetBlending(Blending bld){
	Blend = bld;
	return TRUE;
}
/*************************************************************************//*!
		@brief			テクスチャ設定
		@param			pTex		テクスチャ
		@param			n			番号
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetTexture(LPTexture pTex, MofU32 n) {
	pTextureArray->SetData(pTex, n);
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CMaterialBase::GetName(void){
	return &Name;
}
/*************************************************************************//*!
		@brief			ディフューズ色取得
		@param			None

		@return			ディフューズ色
*//**************************************************************************/
FORCE_INLINE CVector4& CMaterialBase::GetDiffuse(void){
	return Diffuse;
}
/*************************************************************************//*!
		@brief			ディフューズ色取得
		@param			None

		@return			ディフューズ色
*//**************************************************************************/
FORCE_INLINE const CVector4& CMaterialBase::GetDiffuse(void) const {
	return Diffuse;
}
/*************************************************************************//*!
		@brief			ディフューズ色取得
		@param			None

		@return			ディフューズ色
*//**************************************************************************/
FORCE_INLINE MofU32 CMaterialBase::GetDiffuseU32(void) const{
	return Diffuse.ToU32Color();
}
/*************************************************************************//*!
		@brief			アンビエント色取得
		@param			None

		@return			アンビエント色
*//**************************************************************************/
FORCE_INLINE CVector4& CMaterialBase::GetAmbient(void){
	return Ambient;
}
/*************************************************************************//*!
		@brief			アンビエント色取得
		@param			None

		@return			アンビエント色
*//**************************************************************************/
FORCE_INLINE const CVector4& CMaterialBase::GetAmbient(void) const {
	return Ambient;
}
/*************************************************************************//*!
		@brief			アンビエント色取得
		@param			None

		@return			アンビエント色
*//**************************************************************************/
FORCE_INLINE MofU32 CMaterialBase::GetAmbientU32(void) const{
	return Ambient.ToU32Color();
}
/*************************************************************************//*!
		@brief			スペキュラ色取得
		@param			None

		@return			スペキュラ色
*//**************************************************************************/
FORCE_INLINE CVector4& CMaterialBase::GetSpeculer(void){
	return Speculer;
}
/*************************************************************************//*!
		@brief			スペキュラ色取得
		@param			None

		@return			スペキュラ色
*//**************************************************************************/
FORCE_INLINE const CVector4& CMaterialBase::GetSpeculer(void) const {
	return Speculer;
}
/*************************************************************************//*!
		@brief			スペキュラ色取得
		@param			None

		@return			スペキュラ色
*//**************************************************************************/
FORCE_INLINE MofU32 CMaterialBase::GetSpeculerU32(void) const{
	return Speculer.ToU32Color();
}
/*************************************************************************//*!
		@brief			エミッシブ色取得
		@param			None

		@return			エミッシブ色
*//**************************************************************************/
FORCE_INLINE CVector4& CMaterialBase::GetEmissive(void){
	return Emissive;
}
/*************************************************************************//*!
		@brief			エミッシブ色取得
		@param			None

		@return			エミッシブ色
*//**************************************************************************/
FORCE_INLINE const CVector4& CMaterialBase::GetEmissive(void) const {
	return Emissive;
}
/*************************************************************************//*!
		@brief			エミッシブ色取得
		@param			None

		@return			エミッシブ色
*//**************************************************************************/
FORCE_INLINE MofU32 CMaterialBase::GetEmissiveU32(void) const{
	return Emissive.ToU32Color();
}
/*************************************************************************//*!
		@brief			スペキュラ強度取得
		@param			None

		@return			スペキュラ強度
*//**************************************************************************/
FORCE_INLINE MofFloat CMaterialBase::GetPower(void) const{
	return Power;
}
/*************************************************************************//*!
		@brief			ブレンディング取得
		@param			None

		@return			ブレンディング
*//**************************************************************************/
FORCE_INLINE Blending CMaterialBase::GetBlending(void) const{
	return Blend;
}
/*************************************************************************//*!
		@brief			テクスチャ配列取得
		@param			None

		@return			テクスチャ配列
*//**************************************************************************/
FORCE_INLINE LPTextureArray CMaterialBase::GetTextureArray(void){
	return pTextureArray;
}
/*************************************************************************//*!
		@brief			テクスチャ取得
		@param			n			番号
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE LPTexture CMaterialBase::GetTexture(MofU32 n) {
	if (n >= pTextureArray->GetArrayCount())
	{
		return NULL;
	}
	return pTextureArray->GetData(n);
}
/*************************************************************************//*!
		@brief			テクスチャ取得
		@param			n			番号

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE const LPTexture CMaterialBase::GetTexture(MofU32 n) const {
	if (n >= pTextureArray->GetArrayCount())
	{
		return NULL;
	}
	return pTextureArray->GetData(n);
}

//[EOF]