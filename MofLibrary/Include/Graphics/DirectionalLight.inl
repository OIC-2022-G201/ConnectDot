/*************************************************************************//*!
					
					@file	DirectionalLight.inl
					@brief	���������N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���C�g�����ݒ�
		@param[in]		v			����
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectionalLight::SetDirection(const Vector3& v){
	CVector3Utilities::Normal(v,m_Direction);
	return TRUE;
}
/*************************************************************************//*!
		@brief			���C�g�^�C�v�擾
		@param			None

		@return			���C�g�^�C�v
*//**************************************************************************/
FORCE_INLINE LightType CDirectionalLight::GetType(void) const{
	return LIGHTTYPE_DIRECTION;
}
/*************************************************************************//*!
		@brief			���C�g�����擾
		@param			None

		@return			���C�g����
*//**************************************************************************/
FORCE_INLINE CVector3& CDirectionalLight::GetDirection(void){
	return m_Direction;
}
/*************************************************************************//*!
		@brief			���C�g�����擾
		@param			None

		@return			���C�g����
*//**************************************************************************/
FORCE_INLINE const CVector3& CDirectionalLight::GetDirection(void) const {
	return m_Direction;
}

//[EOF]