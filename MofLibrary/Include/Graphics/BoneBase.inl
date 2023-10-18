/*************************************************************************//*!
					
					@file	BoneBase.inl
					@brief	�{�[�����N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			ID�ݒ�
		@param[in]		id				ID
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CBone::SetID(MofU32 id){
	m_ID = id;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�t���O�ݒ�
		@param[in]		flg				�t���O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CBone::SetFlag(MofU32 flg){
	m_Flag = flg;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CBone::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}

/*************************************************************************//*!
		@brief			ID�擾
		@param			None

		@return			ID
*//**************************************************************************/
FORCE_INLINE MofU32 CBone::GetID(void){
	return m_ID;
}
/*************************************************************************//*!
		@brief			�t���O�擾
		@param			None

		@return			�t���O
*//**************************************************************************/
FORCE_INLINE MofU32 CBone::GetFlag(void){
	return m_Flag;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CBone::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�e�̖��O�擾
		@param			None

		@return			�e�̖��O
*//**************************************************************************/
FORCE_INLINE LPString CBone::GetParentName(void){
	return &m_ParentName;
}
/*************************************************************************//*!
		@brief			�ϊ��s��擾
		@param			None

		@return			�ϊ��s��
*//**************************************************************************/
FORCE_INLINE CMatrix44& CBone::GetMatrix(void){
	return m_Matrix;
}
/*************************************************************************//*!
		@brief			�ϊ��s��擾
		@param[out]		pos				���W�ϊ�
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CBone::GetLocalTranslation(Vector3& pos){
	m_Matrix.GetTranslation(pos);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�I�t�Z�b�g�s��擾
		@param			None

		@return			�I�t�Z�b�g�s��
*//**************************************************************************/
FORCE_INLINE CMatrix44& CBone::GetOffsetMatrix(void){
	return m_OffsetMatrix;
}
/*************************************************************************//*!
		@brief			�I�t�Z�b�g�s��擾
		@param			None

		@return			�I�t�Z�b�g�s��
*//**************************************************************************/
FORCE_INLINE CMatrix33& CBone::GetRotationOffsetMatrix(void){
	return m_RotationOffsetMatrix;
}
/*************************************************************************//*!
		@brief			�E�F�C�g�z��擾
		@param			None

		@return			�E�F�C�g�z��
*//**************************************************************************/
FORCE_INLINE LPGeometryBoneWeightArray CBone::GetWeightsArray(void){
	return m_pWeights;
}
/*************************************************************************//*!
		@brief			�h�j�z��擾
		@param			None

		@return			�h�j�z��
*//**************************************************************************/
FORCE_INLINE LPBoneIKInfoArray CBone::GetIKsArray(void) {
	return m_pIKs;
}

//[EOF]