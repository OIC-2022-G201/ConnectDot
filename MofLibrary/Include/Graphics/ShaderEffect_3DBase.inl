/*************************************************************************//*!
					
					@file	ShaderEffect_3DBase.h
					@brief	3D�p�V�F�[�_�[���ʊ��N���X�B

															@author	CDW
															@date	2015.05.01
*//**************************************************************************/

/*************************************************************************//*!
		@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�v���~�e�B�u�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_3DBase::GetShader(void){
	return m_p3DPrimitiveShader;
}
/*************************************************************************//*!
		@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�v���~�e�B�u�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_3DBase::GetShaderBind(void){
	return m_p3DPrimitiveBind;
}

/*************************************************************************//*!
		@brief			3D�X�L�j���O�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�X�L�j���O�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_3DBase::Get3DPrimitiveShader(void){
	return GetShader();
}
/*************************************************************************//*!
		@brief			3D�X�L�j���O�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�X�L�j���O�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_3DBase::Get3DPrimitiveBind(void){
	return GetShaderBind();
}

/*************************************************************************//*!
		@brief			3D�X�L�j���O�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�X�L�j���O�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_3DBase::GetSkinGeometryShader(void){
	return m_pSkinGeometryShader;
}
/*************************************************************************//*!
		@brief			3D�X�L�j���O�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�X�L�j���O�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_3DBase::GetSkinGeometryBind(void){
	return m_pSkinGeometryBind;
}

/*************************************************************************//*!
		@brief			�e�N�X�`���̎擾
		@param[in]		n			�ԍ�
			
		@return			�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_3DBase::GetTexture(MofU32 n){
	return NULL;
}

//[EOF]