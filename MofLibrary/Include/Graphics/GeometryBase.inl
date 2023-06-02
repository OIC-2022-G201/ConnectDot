/*************************************************************************//*!
					
					@file	GeometryBase.inl
					@brief	ジオメトリ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			変換行列設定
		@param[in]		mat				設定する変換行列
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetMatrix(CMatrix44& mat){
	m_Matrix = mat;
	MOF_SAFE_DELETE(m_pCollisionCache);
	return TRUE;
}
/*************************************************************************//*!
		@brief			描画方式設定
		@param[in]		Topology		描画方式
				
		@return			TRUE			正常終了<br>
						それ以外		エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetTopology(PrimitiveTopology Topology){
	m_Topology = Topology;
	return TRUE;
}
/*************************************************************************//*!
		@brief			頂点バッファ設定
		@param[in]		pBuff			設定バッファ
				
		@return			TRUE			正常終了<br>
						それ以外		エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetVertexBuffer(LPVertexBuffer pBuff){
	m_pVertexBuffer = pBuff;
	return TRUE;
}
/*************************************************************************//*!
		@brief			インデックスバッファ設定
		@param[in]		pBuff			設定バッファ
				
		@return			TRUE			正常終了<br>
						それ以外		エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetIndexBuffer(LPIndexBuffer pBuff){
	m_pIndexBuffer = pBuff;
	return TRUE;
}
/*************************************************************************//*!
		@brief			マテリアル設定
		@param[in]		pMat			設定マテリアル
				
		@return			TRUE			正常終了<br>
						それ以外		エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetMaterial(LPMaterial pMat){
	m_pMaterial = pMat;
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CGeometryBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			変換行列取得
		@param			None

		@return			変換行列の取得
*//**************************************************************************/
FORCE_INLINE CMatrix44& CGeometryBase::GetMatrix(void){
	return m_Matrix;
}
/*************************************************************************//*!
		@brief			頂点バッファ取得
		@param			None

		@return			頂点バッファ
*//**************************************************************************/
FORCE_INLINE LPVertexBuffer CGeometryBase::GetVertexBuffer(void){
	return m_pVertexBuffer;
}
/*************************************************************************//*!
		@brief			頂点バッファ取得
		@param[in,out]	pOut			頂点バッファ配列<br>
										出力用のポインタがNULLなら格納されない。
		@param[in,out]	cnt				頂点バッファの数<br>
										実行時にはpOutの格納最大数を指定する。

		@return			TRUE			正常終了<br>
						それ以外		エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::GetVertexBuffer(LPVertexBuffer* pOut, MofU32& cnt){
	if (!pOut)
	{
		cnt = 1;
	}
	else
	{
		if (cnt > 0){ pOut[0] = m_pVertexBuffer; }
		cnt = 1;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			頂点バッファフラグ取得
		@param			None

		@return			頂点バッファフラグ
*//**************************************************************************/
FORCE_INLINE VertexFlag CGeometryBase::GetVertexFlag(void){
	return m_pVertexBuffer->GetVertexFlag();
}
/*************************************************************************//*!
		@brief			インデックスバッファ取得
		@param			None

		@return			インデックスバッファ
*//**************************************************************************/
FORCE_INLINE LPIndexBuffer CGeometryBase::GetIndexBuffer(void){
	return m_pIndexBuffer;
}
/*************************************************************************//*!
		@brief			マテリアル取得
		@param			None

		@return			マテリアル
*//**************************************************************************/
FORCE_INLINE LPMaterial CGeometryBase::GetMaterial(void){
	return m_pMaterial;
}
/*************************************************************************//*!
		@brief			モーフィング取得
		@param			None

		@return			モーフィング
*//**************************************************************************/
FORCE_INLINE LPGeometryMorphingArray CGeometryBase::GetMorphing(void) {
	return m_pMorphing;
}
/*************************************************************************//*!
		@brief			対応ボーン名リスト取得
		@param			None

		@return			対応ボーン名リスト
*//**************************************************************************/
FORCE_INLINE LPStringArray CGeometryBase::GetBoneNameArray(void){
	return m_pBoneName;
}

//[EOF]