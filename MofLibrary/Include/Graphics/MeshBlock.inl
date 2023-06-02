/*************************************************************************//*!
					
					@file	MeshBlock.inl
					@brief	���b�V�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�R�s�[����
		@param			None
				
		@return			�쐬���ꂽ�R�s�[<br>
						�쐬�Ɏ��s�����ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE IGeometryBlock* CGeometryBlock::CreateCopyObject(void) const{
	return new CGeometryBlock(*this);
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBlock::SetName(LPCMofChar pName){
	return FALSE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CGeometryBlock::GetName(void){
	return m_pGeometry->GetName();
}
/*************************************************************************//*!
		@brief			�C���f�b�N�X�o�b�t�@�擾
		@param			None

		@return			�C���f�b�N�X�o�b�t�@�̎擾
*//**************************************************************************/
FORCE_INLINE LPIndexBuffer CGeometryBlock::GetIndexBuffer(void){
	return m_pIndexBuffer;
}

/*************************************************************************//*!
		@brief			�R�s�[����
		@param			None
				
		@return			�쐬���ꂽ�R�s�[<br>
						�쐬�Ɏ��s�����ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE IMeshBlock* CMeshBlock::CreateCopyObject(void) const{
	return new CMeshBlock(*this);
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBlock::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMeshBlock::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�u���b�N�z��擾
		@param			None

		@return			�u���b�N�z��̎擾
*//**************************************************************************/
FORCE_INLINE LPGeometryBlockArray CMeshBlock::GetBlockArray(void){
	return m_pGeometryArray;
}

/*************************************************************************//*!
		@brief			�R�s�[����
		@param			None
				
		@return			�쐬���ꂽ�R�s�[<br>
						�쐬�Ɏ��s�����ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE IBlockContainer* CBlockContainer::CreateCopyObject(void) const{
	return new CBlockContainer(*this);
}
/*************************************************************************//*!
		@brief			�p�����[�^�[�擾
		@param			None

		@return			�p�����[�^�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPBLOCKPARAMETER CBlockContainer::GetParameter(void){
	return &m_Parameter;
}
/*************************************************************************//*!
		@brief			�u���b�N�z��擾
		@param			None

		@return			�u���b�N�z��̎擾
*//**************************************************************************/
FORCE_INLINE LPMeshBlockArray CBlockContainer::GetBlockArray(void){
	return m_pMeshBlock;
}
/*************************************************************************//*!
		@brief			�u���b�N�ԍ��擾
		@param[in]		v				�u���b�N���W
		@param[out]		ox				�u���b�N�w�ԍ�
		@param[out]		oy				�u���b�N�x�ԍ�
		@param[out]		oy				�u���b�N�y�ԍ�
				
		@return			TRUE			����I��<br>
						����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CBlockContainer::GetBlockPos(Vector3& v, MofU16* ox, MofU16* oy, MofU16* oz){
	MofFloat ps = ((v.x - m_Parameter.ModelBox.Position.x + m_Parameter.ModelBox.Size.x) * m_Parameter.InverseSize.x);
	*ox = ((ps < 0) ? 0 : (MofU16)ps);
	*ox = MOF_MIN(*ox, m_Parameter.XCount - 1);
	ps = ((v.y - m_Parameter.ModelBox.Position.y + m_Parameter.ModelBox.Size.y) * m_Parameter.InverseSize.y);
	*oy = ((ps < 0) ? 0 : (MofU16)ps);
	*oy = MOF_MIN(*oy, m_Parameter.YCount - 1);
	ps = ((v.z - m_Parameter.ModelBox.Position.z + m_Parameter.ModelBox.Size.z) * m_Parameter.InverseSize.z);
	*oz = ((ps < 0) ? 0 : (MofU16)ps);
	*oz = MOF_MIN(*oz, m_Parameter.ZCount - 1);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�u���b�N�ԍ��擾
		@param[in]		x				�u���b�N�w�ԍ�
		@param[in]		y				�u���b�N�x�ԍ�
		@param[in]		y				�u���b�N�y�ԍ�
				
		@return			���W�̃u���b�N�ԍ�
*//**************************************************************************/
FORCE_INLINE MofU32 CBlockContainer::GetBlockNo(MofU16 x, MofU16 y, MofU16 z){
	return (x * m_Parameter.YCount + y) * m_Parameter.ZCount + z;
}
/*************************************************************************//*!
		@brief			�u���b�N�ԍ��擾
		@param[in]		v				�u���b�N���W
				
		@return			���W�̃u���b�N�ԍ�
*//**************************************************************************/
FORCE_INLINE MofU32 CBlockContainer::GetBlockNo(Vector3& v){
	return GetBlockNo((MofU16)((v.x - m_Parameter.ModelBox.Position.x + m_Parameter.ModelBox.Size.x) * m_Parameter.InverseSize.x),
		(MofU16)((v.y - m_Parameter.ModelBox.Position.y + m_Parameter.ModelBox.Size.y) * m_Parameter.InverseSize.y),
		(MofU16)((v.z - m_Parameter.ModelBox.Position.z + m_Parameter.ModelBox.Size.z) * m_Parameter.InverseSize.z));
}
/*************************************************************************//*!
		@brief			�u���b�N�擾
		@param[in]		No				�u���b�N�ԍ�
				
		@return			�u���b�N
*//**************************************************************************/
FORCE_INLINE LPMeshBlock CBlockContainer::GetBlock(MofU32 No){
	if (!m_pMeshBlock)
	{
		return NULL;
	}
	if (No >= m_pMeshBlock->GetArrayCount())
	{
		return NULL;
	}
	return m_pMeshBlock->GetData(No);
}
/*************************************************************************//*!
		@brief			�u���b�N�擾
		@param[in]		x				�u���b�N�w�ԍ�
		@param[in]		y				�u���b�N�x�ԍ�
		@param[in]		y				�u���b�N�y�ԍ�
				
		@return			���W�̃u���b�N
*//**************************************************************************/
FORCE_INLINE LPMeshBlock CBlockContainer::GetBlock(MofU16 x, MofU16 y, MofU16 z){
	return GetBlock(GetBlockNo(x, y, z));
}
/*************************************************************************//*!
		@brief			�u���b�N�擾
		@param[in]		v				�u���b�N���W
				
		@return			���W�̃u���b�N
*//**************************************************************************/
FORCE_INLINE LPMeshBlock CBlockContainer::GetBlock(Vector3& v){
	return GetBlock(GetBlockNo(v));
}

//[EOF]