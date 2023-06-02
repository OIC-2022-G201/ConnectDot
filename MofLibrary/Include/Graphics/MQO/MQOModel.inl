/*************************************************************************//*!
					
					@file	MQOModel.inl
					@brief	MQO�t�@�C�����f���N���X�B

															@author	CDW
															@date	2015.12.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMQOModel::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMQOModel::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�}�e���A���z��擾
		@param			None

		@return			�}�e���A���z��̎擾
*//**************************************************************************/
FORCE_INLINE LPMOFMQOMATERIALARRAY CMQOModel::GetMaterials(void){
	return &m_Materials;
}
/*************************************************************************//*!
		@brief			�I�u�W�F�N�g�z��擾
		@param			None

		@return			�I�u�W�F�N�g�z��̎擾
*//**************************************************************************/
FORCE_INLINE LPMOFMQOOBJECTARRAY CMQOModel::GetObjects(void){
	return &m_Objects;
}

//[EOF]
