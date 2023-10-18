/*****************************************************************************
					
					�m�t�@�C�����n	XModel.inl
					�m�����T�v�n	X�t�@�C�����f��

															Author CDW
															Since  2009.04.01
*****************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CXModel::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			�A�j���[�V�����t���O�ݒ�
		@param[in]		Flag		�t���O�i�A�j���[�V�������܂ރ��f���̏ꍇTRUE,�܂܂Ȃ��ꍇFALSE�j
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CXModel::SetAnimationFlag(MofBool Flag){
	m_AnimationFlag = Flag;
	return;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CXModel::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�擪�I�u�W�F�N�g�擾
		@param			None

		@return			�擪�I�u�W�F�N�g
*//**************************************************************************/
FORCE_INLINE LPMOFXFILEOBJECT CXModel::GetFastObject(void){
	return m_pFastObj;
}
/*************************************************************************//*!
		@brief			�I�u�W�F�N�g���擾
		@param			None

		@return			�I�u�W�F�N�g��
*//**************************************************************************/
FORCE_INLINE MofU32 CXModel::GetObjectCount(void){
	return m_ObjCount;
}

//[EOF]