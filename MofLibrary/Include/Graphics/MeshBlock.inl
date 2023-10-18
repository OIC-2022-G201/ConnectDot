/*************************************************************************//*!
					
					@file	MeshBlock.inl
					@brief	メッシュ基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			コピー生成
		@param			None
				
		@return			作成されたコピー<br>
						作成に失敗した場合NULLを返す
*//**************************************************************************/
FORCE_INLINE IGeometryBlock* CGeometryBlock::CreateCopyObject(void) const{
	return new CGeometryBlock(*this);
}
/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBlock::SetName(LPCMofChar pName){
	return FALSE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CGeometryBlock::GetName(void){
	return m_pGeometry->GetName();
}
/*************************************************************************//*!
		@brief			インデックスバッファ取得
		@param			None

		@return			インデックスバッファの取得
*//**************************************************************************/
FORCE_INLINE LPIndexBuffer CGeometryBlock::GetIndexBuffer(void){
	return m_pIndexBuffer;
}

/*************************************************************************//*!
		@brief			コピー生成
		@param			None
				
		@return			作成されたコピー<br>
						作成に失敗した場合NULLを返す
*//**************************************************************************/
FORCE_INLINE IMeshBlock* CMeshBlock::CreateCopyObject(void) const{
	return new CMeshBlock(*this);
}
/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBlock::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CMeshBlock::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			ブロック配列取得
		@param			None

		@return			ブロック配列の取得
*//**************************************************************************/
FORCE_INLINE LPGeometryBlockArray CMeshBlock::GetBlockArray(void){
	return m_pGeometryArray;
}

/*************************************************************************//*!
		@brief			コピー生成
		@param			None
				
		@return			作成されたコピー<br>
						作成に失敗した場合NULLを返す
*//**************************************************************************/
FORCE_INLINE IBlockContainer* CBlockContainer::CreateCopyObject(void) const{
	return new CBlockContainer(*this);
}
/*************************************************************************//*!
		@brief			パラメーター取得
		@param			None

		@return			パラメーターの取得
*//**************************************************************************/
FORCE_INLINE LPBLOCKPARAMETER CBlockContainer::GetParameter(void){
	return &m_Parameter;
}
/*************************************************************************//*!
		@brief			ブロック配列取得
		@param			None

		@return			ブロック配列の取得
*//**************************************************************************/
FORCE_INLINE LPMeshBlockArray CBlockContainer::GetBlockArray(void){
	return m_pMeshBlock;
}
/*************************************************************************//*!
		@brief			ブロック番号取得
		@param[in]		v				ブロック座標
		@param[out]		ox				ブロックＸ番号
		@param[out]		oy				ブロックＹ番号
		@param[out]		oy				ブロックＺ番号
				
		@return			TRUE			正常終了<br>
						それ以外		エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CBlockContainer::GetBlockPos(Vector3& v, MofU16* ox, MofU16* oy, MofU16* oz){
	MofFloat ps = ((v.x - m_Parameter.ModelBox.Position.x + m_Parameter.ModelBox.Size.x) * m_Parameter.InverseSize.x);
	*ox = ((ps < 0) ? 0 : (MofU16)ps);
	*ox = MOF_MIN(*ox, m_Parameter.XCount - 1);
	ps = ((v.y - m_Parameter.ModelBox.Position.y + m_Parameter.ModelBox.Size.y) * m_Parameter.InverseSize.y);
	*oy = ((ps < 0) ? 0 : (MofU16)ps);
	*oy = MOF_MIN(*oy, m_Parameter.YCount - 1);
	ps = ((v.z - m_Parameter.ModelBox.Position.z + m_Parameter.ModelBox.Size.z) * m_Parameter.InverseSize.z);
	*oz = ((ps < 0) ? 0 : (MofU16)ps);
	*oz = MOF_MIN(*oz, m_Parameter.ZCount - 1);
	return TRUE;
}
/*************************************************************************//*!
		@brief			ブロック番号取得
		@param[in]		x				ブロックＸ番号
		@param[in]		y				ブロックＹ番号
		@param[in]		y				ブロックＺ番号
				
		@return			座標のブロック番号
*//**************************************************************************/
FORCE_INLINE MofU32 CBlockContainer::GetBlockNo(MofU16 x, MofU16 y, MofU16 z){
	return (x * m_Parameter.YCount + y) * m_Parameter.ZCount + z;
}
/*************************************************************************//*!
		@brief			ブロック番号取得
		@param[in]		v				ブロック座標
				
		@return			座標のブロック番号
*//**************************************************************************/
FORCE_INLINE MofU32 CBlockContainer::GetBlockNo(Vector3& v){
	return GetBlockNo((MofU16)((v.x - m_Parameter.ModelBox.Position.x + m_Parameter.ModelBox.Size.x) * m_Parameter.InverseSize.x),
		(MofU16)((v.y - m_Parameter.ModelBox.Position.y + m_Parameter.ModelBox.Size.y) * m_Parameter.InverseSize.y),
		(MofU16)((v.z - m_Parameter.ModelBox.Position.z + m_Parameter.ModelBox.Size.z) * m_Parameter.InverseSize.z));
}
/*************************************************************************//*!
		@brief			ブロック取得
		@param[in]		No				ブロック番号
				
		@return			ブロック
*//**************************************************************************/
FORCE_INLINE LPMeshBlock CBlockContainer::GetBlock(MofU32 No){
	if (!m_pMeshBlock)
	{
		return NULL;
	}
	if (No >= m_pMeshBlock->GetArrayCount())
	{
		return NULL;
	}
	return m_pMeshBlock->GetData(No);
}
/*************************************************************************//*!
		@brief			ブロック取得
		@param[in]		x				ブロックＸ番号
		@param[in]		y				ブロックＹ番号
		@param[in]		y				ブロックＺ番号
				
		@return			座標のブロック
*//**************************************************************************/
FORCE_INLINE LPMeshBlock CBlockContainer::GetBlock(MofU16 x, MofU16 y, MofU16 z){
	return GetBlock(GetBlockNo(x, y, z));
}
/*************************************************************************//*!
		@brief			ブロック取得
		@param[in]		v				ブロック座標
				
		@return			座標のブロック
*//**************************************************************************/
FORCE_INLINE LPMeshBlock CBlockContainer::GetBlock(Vector3& v){
	return GetBlock(GetBlockNo(v));
}

//[EOF]