/*************************************************************************//*!
					
					@file	MeshContainerBase.inl
					@brief	���b�V�����N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			��{�`��
		@param[in]		pos				���W
		@param[in]		scl				�X�P�[��
		@param[in]		rot				��]
				
		@return			TRUE			����I��<br>
						����ȊO			����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshContainerBase::Render(const Vector3& pos, const Vector3& scl, const Vector3& rot){
	CMatrix44 mat;
	mat.RotationZXY(rot);
	mat.Scaling(scl, mat);
	mat.SetTranslation(pos);
	return Render(mat);
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshContainerBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMeshContainerBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			���b�V�����X�g�擾
		@param			None

		@return			���b�V�����X�g
*//**************************************************************************/
FORCE_INLINE LPMeshArray CMeshContainerBase::GetMesh(void){
	return m_pMesh;
}
/*************************************************************************//*!
		@brief			���b�V���o�^���擾
		@param			None

		@return			���b�V���o�^��
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshContainerBase::GetMeshCount(void) const {
	return m_pMesh->GetArrayCount();
}
/*************************************************************************//*!
		@brief			���b�V���擾
		@param[in]		pName			���b�V���ԍ�

		@return			���b�V��
						������Ȃ������ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE LPMesh CMeshContainerBase::GetMesh(MofU32 No){
	if (No >= m_pMesh->GetArrayCount())
	{
		return NULL;
	}
	return m_pMesh->GetData(No);
}
/*************************************************************************//*!
		@brief			���b�V���擾
		@param[in]		pName			�T�����b�V����

		@return			���b�V��
						������Ȃ������ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE LPMesh CMeshContainerBase::GetMesh(LPCMofChar pName){
	LPMesh* re = m_pMesh->Find(pName);
	if(!re)
	{
		return NULL;
	}
	return *re;
}
/*************************************************************************//*!
		@brief			�W�I���g���o�^���擾
		@param			None

		@return			�W�I���g���o�^��
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshContainerBase::GetGeometryCount(void) const {
	MofU32 re = 0;
	for (MofU32 i = 0; i < m_pMesh->GetArrayCount(); i++)
	{
		re += m_pMesh->GetData(i)->GetGeometryCount();
	}
	return re;
}
/*************************************************************************//*!
		@brief			�W�I���g���擾
		@param[in]		No				�W�I���g���ԍ�

		@return			�W�I���g��
						������Ȃ������ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE LPGeometry CMeshContainerBase::GetGeometry(MofU32 No){
	MofU32 n = No;
	for (MofU32 i = 0; i < m_pMesh->GetArrayCount(); i++)
	{
		MofU32 cnt = m_pMesh->GetData(i)->GetGeometryCount();
		if (n < cnt)
		{
			return m_pMesh->GetData(i)->GetGeometry(n);
		}
		else
		{
			n -= cnt;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�W�I���g���擾
		@param[in]		pName			�T���W�I���g����

		@return			�W�I���g��
						������Ȃ������ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE LPGeometry CMeshContainerBase::GetGeometryByName(LPCMofChar pName){
	for(MofU32 i = 0;i < m_pMesh->GetArrayCount();i++)
	{
		LPGeometry re = m_pMesh->GetData(i)->GetGeometryByName(pName);
		if(re)
		{
			return re;
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�{�[�����X�g�擾
		@param			None

		@return			�{�[�����X�g
*//**************************************************************************/
FORCE_INLINE LPBoneArray CMeshContainerBase::GetBone(void){
	return m_pBone;
}
/*************************************************************************//*!
		@brief			���b�V���A�j���[�V�������X�g�擾
		@param			None

		@return			���b�V���A�j���[�V�������X�g
*//**************************************************************************/
FORCE_INLINE LPMeshAnimationArray CMeshContainerBase::GetAnimation(void){
	return m_pAnimation;
}
/*************************************************************************//*!
		@brief			���̏�񃊃X�g�擾
		@param			None

		@return			���̏�񃊃X�g
*//**************************************************************************/
FORCE_INLINE LPPhysicsActorInfoArray CMeshContainerBase::GetRigidInfo(void) {
	return m_pRigid;
}
/*************************************************************************//*!
		@brief			�W���C���g��񃊃X�g�擾
		@param			None

		@return			�W���C���g��񃊃X�g
*//**************************************************************************/
FORCE_INLINE LPPhysicsJointInfoArray CMeshContainerBase::GetJointInfo(void) {
	return m_pJoint;
}
/*************************************************************************//*!
		@brief			�J�������X�g�擾
		@param			None

		@return			�J�������X�g
*//**************************************************************************/
FORCE_INLINE LPMeshCameraArray CMeshContainerBase::GetCamera(void) {
	return m_pCamera;
}
/*************************************************************************//*!
		@brief			�J�����擾
		@param[in]		pName			�T���J������

		@return			�J����
						������Ȃ������ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE LPMeshCamera CMeshContainerBase::GetCamera(LPCMofChar pName){
	LPMeshCamera* re = m_pCamera->Find(pName);
	if(!re)
	{
		return NULL;
	}
	return *re;
}

//[EOF]