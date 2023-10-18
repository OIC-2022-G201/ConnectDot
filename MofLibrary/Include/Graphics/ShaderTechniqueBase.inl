/*************************************************************************//*!
					
					@file	ShaderTechniqueBase.inl
					@brief	�V�F�[�_�[�e�N�j�b�N���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderTechniqueBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CShaderTechniqueBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�p�X�̐��擾
		@param			None

		@return			�p�X�̐�
*//**************************************************************************/
FORCE_INLINE MofU32 CShaderTechniqueBase::GetPassCount(void) const{
	if(!m_pPassArray)
	{
		return 0;
	}
	return m_pPassArray->GetArrayCount();
}
/*************************************************************************//*!
		@brief			�p�X�̎擾
		@param[in]		n			�p�X�ԍ�

		@return			�p�X
*//**************************************************************************/
FORCE_INLINE LPShaderPass CShaderTechniqueBase::GetPass(MofU32 n){
	if(!m_pPassArray)
	{
		return NULL;
	}
	if(n >= m_pPassArray->GetArrayCount())
	{
		return NULL;
	}
	return m_pPassArray->GetData(n);
}

//[EOF]