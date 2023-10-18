/*************************************************************************//*!
					
					@file	ShaderEffect_CascadedShadowMap.h
					@brief	�J�X�P�[�h�V���h�E�}�b�v�V�F�[�_�[�B

															@author	CDW
															@date	2015.06.03
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_CascadedShadowMap::Create(){
	return Create(512,TRUE,PIXELFORMAT_R32G32_FLOAT,PIXELFORMAT_D24S8_UNORM);
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
		@param[in]		TexSize �V���h�E�}�b�v�p�e�N�X�`���T�C�Y

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_CascadedShadowMap::Create(MofU32 TexSize){
	return Create(TexSize,TRUE,PIXELFORMAT_R32G32_FLOAT,PIXELFORMAT_D24S8_UNORM);
}
/*************************************************************************//*!
		@brief			�J�X�P�[�h�����ʒu�̐ݒ�
		@param[in]		Index			�J�X�P�[�h�ԍ�
		@param[in]		PartitionDepth	�����ʒu
		
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_CascadedShadowMap::SetCascadePartition(MofU32 Index,MofFloat PartitionDepth){
	if(Index < 0 || MAX_CASCADES <= Index)
	{
		return FALSE;
	}
	m_CascadePartitions[Index] = PartitionDepth;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�e�̂ڂ������̐ݒ�
		@param[in]		BlurStep		�e�̂ڂ�����
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetBlurStep(MofFloat BlurStep){
	m_BlurStep = BlurStep;
}
/*************************************************************************//*!
		@brief			�J�X�P�[�h���E�̂ڂ�����̐ݒ�
		@param[in]		CascadeBlendArea	�J�X�P�[�h���E�̂ڂ����
				
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetCascadeBlendArea(MofFloat CascadeBlendArea){
	m_CascadeBlendArea = CascadeBlendArea;
}
/*************************************************************************//*!
		@brief			���C�g�u���[�f�B���O��}���邽�߂̒l��ݒ�
		@param[in]		ShadowPower		���C�g�u���[�f�B���O��}���邽�߂̒l
		
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetShadowPower(MofFloat ShadowPower){
	m_ShadowPower = ShadowPower;
}
/*************************************************************************//*!
		@brief			�V���h�E�}�b�v��Near�ݒ�
		@param[in]		ShadowNear		�V���h�E�}�b�v��Near
		
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetShadowNear(MofFloat ShadowNear){
	m_ShadowNear = ShadowNear;
}
/*************************************************************************//*!
		@brief			�V���h�E�}�b�v��Far�ݒ�
		@param[in]		ShadowFar	�V���h�E�}�b�v��Far
		
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_CascadedShadowMap::SetShadowFar(MofFloat ShadowFar){
	m_ShadowFar = ShadowFar;
}
/*************************************************************************//*!
		@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�v���~�e�B�u�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_CascadedShadowMap::GetShader(void){
	return m_pShadowRenderer->GetShader();
}
/*************************************************************************//*!
		@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
		@param			None

		@return			3D�v���~�e�B�u�`��p�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_CascadedShadowMap::GetShaderBind(void){
	return m_pShadowRenderer->GetShaderBind();
}
/*************************************************************************//*!
		@brief			�[�x�e�N�X�`���̎擾
		@param[in]		n				�G�t�F�N�g�ԍ�
				
		@return			�[�x�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPShaderEffect_ShadowTexture CShaderEffect_CascadedShadowMap::GetShadowMap(MofU32 n){
	return m_pShadowTextures[n];
}
/*************************************************************************//*!
		@brief			�[�x�e�N�X�`���̎擾
		@param[in]		n				�G�t�F�N�g�ԍ�
		
		@return			�[�x�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_CascadedShadowMap::GetShadowMapTexture(MofU32 n){
	return m_pShadowTextures[n]->GetShadowMapTexture();
}
/*************************************************************************//*!
		@brief			�J�X�P�[�h�V���h�E�}�b�v�̒i�K���擾
		@param			None
		
		@return			�J�X�P�[�h�V���h�E�}�b�v�̒i�K��
*//**************************************************************************/
FORCE_INLINE MofU32 CShaderEffect_CascadedShadowMap::GetCascadeLevels(void){
	return MAX_CASCADES;
}
/*************************************************************************//*!
		@brief			���C�g���_�̃r���[�s��擾
		@param			None

		@return			���C�g���_�̃r���[�s��
*//**************************************************************************/
FORCE_INLINE CMatrix44& CShaderEffect_CascadedShadowMap::GetLightViewMatrix(void){
	return m_matShadowView;
}
/*************************************************************************//*!
		@brief			�J�X�P�[�h�v���W�F�N�V�����s��̎擾
		@param[in]		n				�G�t�F�N�g�ԍ�
				
		@return			�J�X�P�[�h�v���W�F�N�V�����s��
*//**************************************************************************/
FORCE_INLINE CMatrix44& CShaderEffect_CascadedShadowMap::GetCascadeProjectionMatrix(MofU32 n){
	return m_matShadowProj[n];
}
/*************************************************************************//*!
		@brief			�e�̂ڂ������̎擾
		@param			None
				
		@return			�e�̂ڂ�����
*//**************************************************************************/
FORCE_INLINE MofFloat CShaderEffect_CascadedShadowMap::GetBlurStep(void){
	return m_BlurStep;
}
/*************************************************************************//*!
		@brief			�J�X�P�[�h���E�̂ڂ�����̎擾
		@param			None
				
		@return			�J�X�P�[�h���E�̂ڂ����
*//**************************************************************************/
FORCE_INLINE MofFloat CShaderEffect_CascadedShadowMap::GetCascadeBlendArea(void){
	return m_CascadeBlendArea;
}
/*************************************************************************//*!
		@brief			���C�g�u���[�f�B���O��}���邽�߂̒l���擾
		@param			None
				
		@return			���C�g�u���[�f�B���O��}���邽�߂̒l
*//**************************************************************************/
FORCE_INLINE MofFloat CShaderEffect_CascadedShadowMap::GetShadowPower(void){
	return m_ShadowPower;
}

//[EOF]
