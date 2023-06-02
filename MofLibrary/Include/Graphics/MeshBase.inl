/*************************************************************************//*!
					
					@file	MeshBase.inl
					@brief	メッシュ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CMeshBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			ジオメトリリスト取得
		@param			None

		@return			ジオメトリリスト
*//**************************************************************************/
FORCE_INLINE LPGeometryArray CMeshBase::GetGeometry(void){
	return m_pGeometry;
}
/*************************************************************************//*!
		@brief			ブロックリスト取得
		@param			None

		@return			ブロックリスト
*//**************************************************************************/
FORCE_INLINE LPBlockContainer CMeshBase::GetBlockContainer(void){
	if (!m_pBlockContainer)
	{
		m_pBlockContainer = new CBlockContainer();
	}
	return m_pBlockContainer;
}
/*************************************************************************//*!
		@brief			ジオメトリ登録数取得
		@param			None

		@return			ジオメトリ登録数
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshBase::GetGeometryCount(void) const {
	return m_pGeometry->GetArrayCount();
}
/*************************************************************************//*!
		@brief			ジオメトリ取得
		@param[in]		pName			探すジオメトリ名

		@return			ジオメトリ
						見つからなかった場合NULLを返す
*//**************************************************************************/
FORCE_INLINE LPGeometry CMeshBase::GetGeometryByName(LPCMofChar pName){
	LPGeometry* re = m_pGeometry->Find(pName);
	if(!re)
	{
		return NULL;
	}
	return *re;
}
/*************************************************************************//*!
		@brief			ジオメトリ取得
		@param[in]		No				ジオメトリ番号

		@return			ジオメトリ
						見つからなかった場合NULLを返す
*//**************************************************************************/
FORCE_INLINE LPGeometry CMeshBase::GetGeometry(MofU32 No){
	if (No >= m_pGeometry->GetArrayCount())
	{
		return NULL;
	}
	return m_pGeometry->GetData(No);
}

//[EOF]