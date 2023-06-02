/*************************************************************************//*!
					
					@file	PolyLine.inl
					@brief	�|�����C���W�I���g���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�擪���W�擾
		@param			None

		@return			�擪���W
*//**************************************************************************/
FORCE_INLINE CVector3& CPolyLine::GetFirstPosition(void){
	return m_pPointArray->GetData(0).Position;
}
/*************************************************************************//*!
		@brief			�I�[���W�擾
		@param			None

		@return			�I�[���W
*//**************************************************************************/
FORCE_INLINE CVector3& CPolyLine::GetLastPosition(void){
	return m_pPointArray->GetData(m_pPointArray->GetArrayCount() - 1).Position;
}

//[EOF]