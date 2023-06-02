/*************************************************************************//*!
					
					@file	GeometryInstancedBase.inl
					@brief	�W�I���g���C���X�^���X���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�C���X�^���X�p�o�b�t�@�ݒ�
		@param[in]		pBuff			�ݒ�o�b�t�@
				
		@return			TRUE			����I��<br>
						����ȊO		�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CGeometryInstancedBase::SetInstancedBuffer(LPVertexBuffer pBuff){
	m_pInstancedBuffer = pBuff;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���_�o�b�t�@�擾
		@param			None

		@return			���_�o�b�t�@
*//**************************************************************************/
FORCE_INLINE LPVertexBuffer CGeometryInstancedBase::GetVertexBuffer(void){
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
FORCE_INLINE MofBool CGeometryInstancedBase::GetVertexBuffer(LPVertexBuffer* pOut, MofU32& cnt){
	if (!pOut)
	{
		cnt = 2;
	}
	else
	{
		if (cnt > 0){ pOut[0] = m_pVertexBuffer; }
		if (cnt > 1){ pOut[1] = m_pInstancedBuffer; }
		cnt = 2;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���_�o�b�t�@�t���O�擾
		@param			None

		@return			���_�o�b�t�@�t���O
*//**************************************************************************/
FORCE_INLINE VertexFlag CGeometryInstancedBase::GetVertexFlag(void){
	return (VertexFlag)(m_pVertexBuffer->GetVertexFlag() | m_pInstancedBuffer->GetVertexFlag());
}
/*************************************************************************//*!
		@brief			�C���X�^���X�p�o�b�t�@�擾
		@param			None

		@return			�C���X�^���X�p�o�b�t�@
*//**************************************************************************/
FORCE_INLINE LPVertexBuffer CGeometryInstancedBase::GetInstancedBuffer(void){
	return m_pInstancedBuffer;
}

//[EOF]