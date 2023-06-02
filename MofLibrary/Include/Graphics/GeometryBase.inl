/*************************************************************************//*!
					
					@file	GeometryBase.inl
					@brief	�W�I���g�����N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			�ϊ��s��ݒ�
		@param[in]		mat				�ݒ肷��ϊ��s��
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetMatrix(CMatrix44& mat){
	m_Matrix = mat;
	MOF_SAFE_DELETE(m_pCollisionCache);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�`������ݒ�
		@param[in]		Topology		�`�����
				
		@return			TRUE			����I��<br>
						����ȊO		�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetTopology(PrimitiveTopology Topology){
	m_Topology = Topology;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���_�o�b�t�@�ݒ�
		@param[in]		pBuff			�ݒ�o�b�t�@
				
		@return			TRUE			����I��<br>
						����ȊO		�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetVertexBuffer(LPVertexBuffer pBuff){
	m_pVertexBuffer = pBuff;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�C���f�b�N�X�o�b�t�@�ݒ�
		@param[in]		pBuff			�ݒ�o�b�t�@
				
		@return			TRUE			����I��<br>
						����ȊO		�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetIndexBuffer(LPIndexBuffer pBuff){
	m_pIndexBuffer = pBuff;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�}�e���A���ݒ�
		@param[in]		pMat			�ݒ�}�e���A��
				
		@return			TRUE			����I��<br>
						����ȊO		�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::SetMaterial(LPMaterial pMat){
	m_pMaterial = pMat;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CGeometryBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�ϊ��s��擾
		@param			None

		@return			�ϊ��s��̎擾
*//**************************************************************************/
FORCE_INLINE CMatrix44& CGeometryBase::GetMatrix(void){
	return m_Matrix;
}
/*************************************************************************//*!
		@brief			���_�o�b�t�@�擾
		@param			None

		@return			���_�o�b�t�@
*//**************************************************************************/
FORCE_INLINE LPVertexBuffer CGeometryBase::GetVertexBuffer(void){
	return m_pVertexBuffer;
}
/*************************************************************************//*!
		@brief			���_�o�b�t�@�擾
		@param[in,out]	pOut			���_�o�b�t�@�z��<br>
										�o�͗p�̃|�C���^��NULL�Ȃ�i�[����Ȃ��B
		@param[in,out]	cnt				���_�o�b�t�@�̐�<br>
										���s���ɂ�pOut�̊i�[�ő吔���w�肷��B

		@return			TRUE			����I��<br>
						����ȊO		�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryBase::GetVertexBuffer(LPVertexBuffer* pOut, MofU32& cnt){
	if (!pOut)
	{
		cnt = 1;
	}
	else
	{
		if (cnt > 0){ pOut[0] = m_pVertexBuffer; }
		cnt = 1;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���_�o�b�t�@�t���O�擾
		@param			None

		@return			���_�o�b�t�@�t���O
*//**************************************************************************/
FORCE_INLINE VertexFlag CGeometryBase::GetVertexFlag(void){
	return m_pVertexBuffer->GetVertexFlag();
}
/*************************************************************************//*!
		@brief			�C���f�b�N�X�o�b�t�@�擾
		@param			None

		@return			�C���f�b�N�X�o�b�t�@
*//**************************************************************************/
FORCE_INLINE LPIndexBuffer CGeometryBase::GetIndexBuffer(void){
	return m_pIndexBuffer;
}
/*************************************************************************//*!
		@brief			�}�e���A���擾
		@param			None

		@return			�}�e���A��
*//**************************************************************************/
FORCE_INLINE LPMaterial CGeometryBase::GetMaterial(void){
	return m_pMaterial;
}
/*************************************************************************//*!
		@brief			���[�t�B���O�擾
		@param			None

		@return			���[�t�B���O
*//**************************************************************************/
FORCE_INLINE LPGeometryMorphingArray CGeometryBase::GetMorphing(void) {
	return m_pMorphing;
}
/*************************************************************************//*!
		@brief			�Ή��{�[�������X�g�擾
		@param			None

		@return			�Ή��{�[�������X�g
*//**************************************************************************/
FORCE_INLINE LPStringArray CGeometryBase::GetBoneNameArray(void){
	return m_pBoneName;
}

//[EOF]