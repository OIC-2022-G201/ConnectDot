/*************************************************************************//*!
					
					@file	ShaderResourceBase.inl
					@brief	�V�F�[�_�[���\�[�X�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderResourceBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���\�[�X�̐ݒ�
		@param[in]		pTex		�f�[�^
					
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderResourceBase::SetResource(LPTexture pTex) {
	m_pTexture = pTex;
	return TRUE;
}

/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CShaderResourceBase::GetName(void){
	return &m_Name;
}

//[EOF]