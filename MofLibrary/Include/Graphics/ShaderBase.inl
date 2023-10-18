/*************************************************************************//*!
					
					@file	ShaderBase.inl
					@brief	�V�F�[�_�[���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			�e�N�j�b�N�ݒ�
		@param[in]		tn			�e�N�j�b�N�ԍ�
					
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderBase::SetTechnique(MofU32 tn){
	m_NowTechnique = tn;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�e�N�j�b�N�ݒ�
		@param[in]		pName		�e�N�j�b�N��
					
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderBase::SetTechniqueByName(LPCMofChar pName){
	if (!m_pTechniqueArray || !pName)
	{
		return FALSE;
	}
	for (MofU32 i = 0; i < m_pTechniqueArray->GetArrayCount(); i++)
	{
		if (m_pTechniqueArray->GetData(i)->GetName()->Compare(pName) == 0)
		{
			m_NowTechnique = i;
			return TRUE;
		}
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CShaderBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�e�N�j�b�N�̐��擾
		@param			None

		@return			�e�N�j�b�N�̐�
*//**************************************************************************/
FORCE_INLINE MofU32 CShaderBase::GetTechniqueCount(void) const{
	if(!m_pTechniqueArray)
	{
		return 0;
	}
	return m_pTechniqueArray->GetArrayCount();
}
/*************************************************************************//*!
		@brief			�e�N�j�b�N�擾
		@param			None

		@return			�e�N�j�b�N<br>
						���݂��Ȃ��ꍇNULL
*//**************************************************************************/
FORCE_INLINE LPShaderTechnique CShaderBase::GetTechnique(void){
	if (!m_pTechniqueArray)
	{
		return NULL;
	}
	if (m_NowTechnique >= m_pTechniqueArray->GetArrayCount())
	{
		return NULL;
	}
	return m_pTechniqueArray->GetData(m_NowTechnique);
}
/*************************************************************************//*!
		@brief			�e�N�j�b�N�擾
		@param[in]		n			�e�N�j�b�N

		@return			�e�N�j�b�N<br>
						���݂��Ȃ��ꍇNULL
*//**************************************************************************/
FORCE_INLINE LPShaderTechnique CShaderBase::GetTechnique(MofU32 n){
	if(!m_pTechniqueArray)
	{
		return NULL;
	}
	if(n >= m_pTechniqueArray->GetArrayCount())
	{
		return NULL;
	}
	return m_pTechniqueArray->GetData(n);
}
/*************************************************************************//*!
		@brief			�e�N�j�b�N�擾
		@param[in]		pName		�e�N�j�b�N��

		@return			�e�N�j�b�N<br>
						���݂��Ȃ��ꍇNULL
*//**************************************************************************/
FORCE_INLINE LPShaderTechnique CShaderBase::GetTechniqueByName(LPCMofChar pName){
	if(!m_pTechniqueArray || !pName)
	{
		return NULL;
	}
	for(MofU32 i = 0;i < m_pTechniqueArray->GetArrayCount();i++)
	{
		if(m_pTechniqueArray->GetData(i)->GetName()->Compare(pName) == 0)
		{
			return m_pTechniqueArray->GetData(i);
		}
	}
	return NULL;
}

//[EOF]