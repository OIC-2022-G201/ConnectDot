/*************************************************************************//*!
					
					@file	ResourceReferenceDebugger.inl
					@brief	リソース解放監視クラス

															@author	CDW
															@date	2015.10.05
*//**************************************************************************/

/*************************************************************************//*!
		@brief			未開放のリソース数を取得
		@param			None

		@return			未開放のリソース数
*//**************************************************************************/
FORCE_INLINE MofU32 CResourceReferenceDebugger::GetResourceCount(){
	return s_ResourceList.GetArrayCount();
}
/*************************************************************************//*!
		@brief			リソース名を取得
		@param[in]		index			インデックス

		@return			リソース名
*//**************************************************************************/
FORCE_INLINE const CString& CResourceReferenceDebugger::GetResouceName(MofU32 index){
	return s_ResourceList.GetData(index)->Name;
}

//[EOF]