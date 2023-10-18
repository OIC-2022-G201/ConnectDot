/*************************************************************************//*!
					
					@file	MaterialBase.inl
					@brief	�}�e���A�����N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetName(LPCMofChar pName){
	return Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetDiffuse(const Vector4& c){
	Diffuse = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetDiffuse(const MofU32 c){
	Diffuse.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetAmbient(const Vector4& c){
	Ambient = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetAmbient(const MofU32 c){
	Ambient.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetSpeculer(const Vector4& c){
	Speculer = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetSpeculer(const MofU32 c){
	Speculer.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�G�~�b�V�u�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetEmissive(const Vector4& c){
	Emissive = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�G�~�b�V�u�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetEmissive(const MofU32 c){
	Emissive.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�X�y�L�������x�擾
		@param			pow			���x
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetPower(MofFloat pow){
	Power = pow;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�u�����f�B���O�擾
		@param			bld			�u�����f�B���O
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetBlending(Blending bld){
	Blend = bld;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�e�N�X�`���ݒ�
		@param			pTex		�e�N�X�`��
		@param			n			�ԍ�
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMaterialBase::SetTexture(LPTexture pTex, MofU32 n) {
	pTextureArray->SetData(pTex, n);
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMaterialBase::GetName(void){
	return &Name;
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�擾
		@param			None

		@return			�f�B�t���[�Y�F
*//**************************************************************************/
FORCE_INLINE CVector4& CMaterialBase::GetDiffuse(void){
	return Diffuse;
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�擾
		@param			None

		@return			�f�B�t���[�Y�F
*//**************************************************************************/
FORCE_INLINE const CVector4& CMaterialBase::GetDiffuse(void) const {
	return Diffuse;
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�擾
		@param			None

		@return			�f�B�t���[�Y�F
*//**************************************************************************/
FORCE_INLINE MofU32 CMaterialBase::GetDiffuseU32(void) const{
	return Diffuse.ToU32Color();
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�擾
		@param			None

		@return			�A���r�G���g�F
*//**************************************************************************/
FORCE_INLINE CVector4& CMaterialBase::GetAmbient(void){
	return Ambient;
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�擾
		@param			None

		@return			�A���r�G���g�F
*//**************************************************************************/
FORCE_INLINE const CVector4& CMaterialBase::GetAmbient(void) const {
	return Ambient;
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�擾
		@param			None

		@return			�A���r�G���g�F
*//**************************************************************************/
FORCE_INLINE MofU32 CMaterialBase::GetAmbientU32(void) const{
	return Ambient.ToU32Color();
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�擾
		@param			None

		@return			�X�y�L�����F
*//**************************************************************************/
FORCE_INLINE CVector4& CMaterialBase::GetSpeculer(void){
	return Speculer;
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�擾
		@param			None

		@return			�X�y�L�����F
*//**************************************************************************/
FORCE_INLINE const CVector4& CMaterialBase::GetSpeculer(void) const {
	return Speculer;
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�擾
		@param			None

		@return			�X�y�L�����F
*//**************************************************************************/
FORCE_INLINE MofU32 CMaterialBase::GetSpeculerU32(void) const{
	return Speculer.ToU32Color();
}
/*************************************************************************//*!
		@brief			�G�~�b�V�u�F�擾
		@param			None

		@return			�G�~�b�V�u�F
*//**************************************************************************/
FORCE_INLINE CVector4& CMaterialBase::GetEmissive(void){
	return Emissive;
}
/*************************************************************************//*!
		@brief			�G�~�b�V�u�F�擾
		@param			None

		@return			�G�~�b�V�u�F
*//**************************************************************************/
FORCE_INLINE const CVector4& CMaterialBase::GetEmissive(void) const {
	return Emissive;
}
/*************************************************************************//*!
		@brief			�G�~�b�V�u�F�擾
		@param			None

		@return			�G�~�b�V�u�F
*//**************************************************************************/
FORCE_INLINE MofU32 CMaterialBase::GetEmissiveU32(void) const{
	return Emissive.ToU32Color();
}
/*************************************************************************//*!
		@brief			�X�y�L�������x�擾
		@param			None

		@return			�X�y�L�������x
*//**************************************************************************/
FORCE_INLINE MofFloat CMaterialBase::GetPower(void) const{
	return Power;
}
/*************************************************************************//*!
		@brief			�u�����f�B���O�擾
		@param			None

		@return			�u�����f�B���O
*//**************************************************************************/
FORCE_INLINE Blending CMaterialBase::GetBlending(void) const{
	return Blend;
}
/*************************************************************************//*!
		@brief			�e�N�X�`���z��擾
		@param			None

		@return			�e�N�X�`���z��
*//**************************************************************************/
FORCE_INLINE LPTextureArray CMaterialBase::GetTextureArray(void){
	return pTextureArray;
}
/*************************************************************************//*!
		@brief			�e�N�X�`���擾
		@param			n			�ԍ�
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE LPTexture CMaterialBase::GetTexture(MofU32 n) {
	if (n >= pTextureArray->GetArrayCount())
	{
		return NULL;
	}
	return pTextureArray->GetData(n);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���擾
		@param			n			�ԍ�

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE const LPTexture CMaterialBase::GetTexture(MofU32 n) const {
	if (n >= pTextureArray->GetArrayCount())
	{
		return NULL;
	}
	return pTextureArray->GetData(n);
}

//[EOF]