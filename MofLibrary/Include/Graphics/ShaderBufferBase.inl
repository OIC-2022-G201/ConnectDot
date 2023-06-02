/*************************************************************************//*!
					
					@file	ShaderBufferBase.inl
					@brief	�V�F�[�_�[�o�b�t�@�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderBufferBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}

/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CShaderBufferBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�o�b�t�@�T�C�Y�擾
		@param			None

		@return			�o�b�t�@�T�C�Y
*//**************************************************************************/
FORCE_INLINE MofU32 CShaderBufferBase::GetBufferSize(void) const{
	return m_Size;
}

//[EOF]