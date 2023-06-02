/*****************************************************************************
					
					�m�t�@�C�����n	CCDIK.inl
					�m�����T�v�n	CCDIK�N���X
					
															@author	CDW
															@date	2014.05.14
*****************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCCDIK::SetName(LPCMofChar pName){
	return m_Info.Target.SetString(pName);
}
/*************************************************************************//*!
		@brief			�ʒu�ݒ�
		@param[in]		p				�ʒu
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCCDIK::SetTargetPosition(Vector3& p){
	m_TargetPos = p;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�ʒu�ݒ�
		@param[in]		p				�ʒu
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCCDIK::SetTargetPosition(Matrix44& p) {
	CMatrix44Utilities::GetTranslation(p, m_TargetPos);
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CCCDIK::GetName(void){
	return &m_Info.Target;
}
/*************************************************************************//*!
		@brief			���[�g�擾
		@param			None

		@return			���[�g
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDIK::GetRoot(void){
	return m_pRoot;
}

/*************************************************************************//*!
		@brief			�G�t�F�N�^�擾
		@param			None

		@return			�G�t�F�N�^
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDIK::GetEffector(void){
	return m_pEffector;
}
/*************************************************************************//*!
		@brief			�^�[�Q�b�g�擾
		@param			None

		@return			�^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDIK::GetTarget(void) {
	return m_pTarget;
}

/*************************************************************************//*!
		@brief			�q�擾
		@param[in]		pName		���O

		@return			�q
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDIK::GetJoint(LPCMofChar pName){
	if(!pName)
	{
		return NULL;
	}
	return m_pRoot->GetJoint(pName);
}

/*************************************************************************//*!
		@brief			�^�[�Q�b�g�ʒu�擾
		@param			None

		@return			�^�[�Q�b�g�ʒu
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDIK::GetTargetPosition(void){
	return m_TargetPos;
}

/*************************************************************************//*!
		@brief			�����񐔎擾
		@param			None

		@return			������
*//**************************************************************************/
FORCE_INLINE MofS32 CCCDIK::GetMaxIteration(void){
	return m_Info.Iteration;
}

/*************************************************************************//*!
		@brief			���e�덷�擾
		@param			None

		@return			���e�덷
*//**************************************************************************/
FORCE_INLINE MofFloat CCCDIK::GetTolerance(void){
	return m_Info.Tolerance;
}
//[EOF]