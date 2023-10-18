/*************************************************************************//*!
					
					@file	ResourceReferenceDebugger.inl
					@brief	���\�[�X����Ď��N���X

															@author	CDW
															@date	2015.10.05
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���J���̃��\�[�X�����擾
		@param			None

		@return			���J���̃��\�[�X��
*//**************************************************************************/
FORCE_INLINE MofU32 CResourceReferenceDebugger::GetResourceCount(){
	return s_ResourceList.GetArrayCount();
}
/*************************************************************************//*!
		@brief			���\�[�X�����擾
		@param[in]		index			�C���f�b�N�X

		@return			���\�[�X��
*//**************************************************************************/
FORCE_INLINE const CString& CResourceReferenceDebugger::GetResouceName(MofU32 index){
	return s_ResourceList.GetData(index)->Name;
}

//[EOF]