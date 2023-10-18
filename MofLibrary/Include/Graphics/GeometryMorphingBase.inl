/*************************************************************************//*!
					
					@file	GeometryMorphingBase.inl
					@brief	ジオメトリモーフィング基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryMorphing::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			頂点座標モーフィング設定<br>
						古いデータがある場合解放される
		@param[in]		pArray			設定するキー
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryMorphing::SetMorphingPosition(LPGeometryMorphingPositionArray pArray){
	MOF_SAFE_DELETE(m_pPosition);
	m_pPosition = pArray;
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CGeometryMorphing::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			頂点座標モーフィング取得
		@param			None

		@return			頂点座標モーフィング
*//**************************************************************************/
FORCE_INLINE LPGeometryMorphingPositionArray CGeometryMorphing::GetMorphingPosition(void){
	return m_pPosition;
}

//[EOF]