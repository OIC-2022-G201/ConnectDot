/*****************************************************************************
					
					�m�t�@�C�����n	CCDJoint.inl
					�m�����T�v�n	CCD�p�֐߃N���X
					
															@author	CDW
															@date	2014.05.14
*****************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetName(LPCMofChar pName){
	return m_Info.Target.SetString(pName);
}
/*************************************************************************//*!
		@brief			�e�ݒ�
		@param[in]		p				�e
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetParent(LPCCDJoint p){
	m_pParent = p;
	return TRUE;
}

/*************************************************************************//*!
		@brief			�s��ݒ�
		@param[in]		m				�s��
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetMatrix(CMatrix44& m){
	m.GetTranslation(m_Position);
	m.GetRotation(m_Orientation);
	m.GetScaling(m_Scaling);
	m_JointMatrix = m;
	return TRUE;
}

/*************************************************************************//*!
		@brief			�ʒu�ݒ�
		@param[in]		p				�ʒu
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetPosition(Vector3& p){
	m_Position = p;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�p���ݒ�
		@param[in]		q				�p��
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CCCDJoint::SetOrientation(Quaternion& q){
	m_Orientation = q;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CCCDJoint::GetName(void){
	return &m_Info.Target;
}
/*************************************************************************//*!
		@brief			�{�[���擾
		@param			None

		@return			�{�[��
*//**************************************************************************/
FORCE_INLINE LPBone CCCDJoint::GetBone(void) {
	return m_pBone;
}
/*************************************************************************//*!
		@brief			�ݒ���擾
		@param			None

		@return			�ݒ���
*//**************************************************************************/
FORCE_INLINE BONEIKJOINT& CCCDJoint::GetInfo(void) {
	return m_Info;
}
/*************************************************************************//*!
		@brief			�e�擾
		@param			None

		@return			�e
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDJoint::GetParent(void){
	return m_pParent;
}
/*************************************************************************//*!
		@brief			�q�擾
		@param			None

		@return			�q
*//**************************************************************************/
FORCE_INLINE LPCCDJointArray CCCDJoint::GetChildren(void){
	return m_pChildren;
}

/*************************************************************************//*!
		@brief			�q�擾
		@param[in]		No			�ԍ�

		@return			�q
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDJoint::GetChild(MofU32 No){
	if(!m_pChildren || No >= m_pChildren->GetArrayCount())
	{
		return NULL;
	}
	return m_pChildren->GetData(No);
}
/*************************************************************************//*!
		@brief			�q�擾
		@param[in]		pName		���O

		@return			�q
*//**************************************************************************/
FORCE_INLINE LPCCDJoint CCCDJoint::GetJoint(LPCMofChar pName){
	if(!pName)
	{
		return NULL;
	}
	if(!CString::Compare(m_Info.Target.GetString(),pName))
	{
		return this;
	}
	if(m_pChildren)
	{
		for(MofU32 i = 0;i < m_pChildren->GetArrayCount();i++)
		{
			LPCCDJoint re = m_pChildren->GetData(i)->GetJoint(pName);
			if(re)
			{
				return re;
			}
		}
	}
	return NULL;
}

/*************************************************************************//*!
		@brief			�s��擾
		@param			None

		@return			�s��
*//**************************************************************************/
FORCE_INLINE CMatrix44& CCCDJoint::GetMatrix(void){
	return m_JointMatrix;
}
/*************************************************************************//*!
		@brief			�ʒu�擾
		@param			None

		@return			�ʒu
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetPosition(void){
	return m_Position;
}
/*************************************************************************//*!
		@brief			�p���擾
		@param			None

		@return			�p��
*//**************************************************************************/
FORCE_INLINE CQuaternion& CCCDJoint::GetOrientation(void){
	return m_Orientation;
}

/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CCCDJoint::GetRestriction(void) {
	return m_Info.Restriction;
}
/*************************************************************************//*!
		@brief			�䗦�擾
		@param			None

		@return			�䗦
*//**************************************************************************/
FORCE_INLINE MofFloat CCCDJoint::GetWeight(void){
	return m_Info.Weight;
}

/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			����
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetMinSingleRestriction(void){
	return m_Info.MinSingleRestriction;
}

/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			����
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetMaxSingleRestriction(void){
	return m_Info.MaxSingleRestriction;
}

/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			����
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetMinRestriction(void){
	return m_Info.MinRestriction;
}

/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			����
*//**************************************************************************/
FORCE_INLINE CVector3& CCCDJoint::GetMaxRestriction(void){
	return m_Info.MaxRestriction;
}

//[EOF]