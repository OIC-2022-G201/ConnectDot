/*************************************************************************//*!
					
					@file	GeometryMorphingBase.inl
					@brief	�W�I���g�����[�t�B���O���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryMorphing::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���_���W���[�t�B���O�ݒ�<br>
						�Â��f�[�^������ꍇ��������
		@param[in]		pArray			�ݒ肷��L�[
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryMorphing::SetMorphingPosition(LPGeometryMorphingPositionArray pArray){
	MOF_SAFE_DELETE(m_pPosition);
	m_pPosition = pArray;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CGeometryMorphing::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			���_���W���[�t�B���O�擾
		@param			None

		@return			���_���W���[�t�B���O
*//**************************************************************************/
FORCE_INLINE LPGeometryMorphingPositionArray CGeometryMorphing::GetMorphingPosition(void){
	return m_pPosition;
}

//[EOF]