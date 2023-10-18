/*************************************************************************//*!
					
					@file	LightBase.inl
					@brief	���C�g���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetDiffuse(const Vector4& c){
	m_Diffuse = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetDiffuse(const MofU32 c){
	m_Diffuse.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetAmbient(const Vector4& c){
	m_Ambient = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetAmbient(const MofU32 c){
	m_Ambient.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetSpeculer(const Vector4& c){
	m_Speculer = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�ݒ�
		@param[in]		c			�F
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CLightBase::SetSpeculer(const MofU32 c){
	m_Speculer.SetU32Color(c);
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CLightBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�擾
		@param			None

		@return			�f�B�t���[�Y�F
*//**************************************************************************/
FORCE_INLINE CVector4& CLightBase::GetDiffuse(void){
	return m_Diffuse;
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�擾
		@param			None

		@return			�f�B�t���[�Y�F
*//**************************************************************************/
FORCE_INLINE const CVector4& CLightBase::GetDiffuse(void) const {
	return m_Diffuse;
}
/*************************************************************************//*!
		@brief			�f�B�t���[�Y�F�擾
		@param			None

		@return			�f�B�t���[�Y�F
*//**************************************************************************/
FORCE_INLINE MofU32 CLightBase::GetDiffuseU32(void) const{
	return m_Diffuse.ToU32Color();
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�擾
		@param			None

		@return			�A���r�G���g�F
*//**************************************************************************/
FORCE_INLINE CVector4& CLightBase::GetAmbient(void){
	return m_Ambient;
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�擾
		@param			None

		@return			�A���r�G���g�F
*//**************************************************************************/
FORCE_INLINE const CVector4& CLightBase::GetAmbient(void) const {
	return m_Ambient;
}
/*************************************************************************//*!
		@brief			�A���r�G���g�F�擾
		@param			None

		@return			�A���r�G���g�F
*//**************************************************************************/
FORCE_INLINE MofU32 CLightBase::GetAmbientU32(void) const{
	return m_Ambient.ToU32Color();
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�擾
		@param			None

		@return			�X�y�L�����F
*//**************************************************************************/
FORCE_INLINE CVector4& CLightBase::GetSpeculer(void){
	return m_Speculer;
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�擾
		@param			None

		@return			�X�y�L�����F
*//**************************************************************************/
FORCE_INLINE const CVector4& CLightBase::GetSpeculer(void) const {
	return m_Speculer;
}
/*************************************************************************//*!
		@brief			�X�y�L�����F�擾
		@param			None

		@return			�X�y�L�����F
*//**************************************************************************/
FORCE_INLINE MofU32 CLightBase::GetSpeculerU32(void) const{
	return m_Speculer.ToU32Color();
}

//[EOF]