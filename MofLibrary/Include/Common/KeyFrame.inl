/*************************************************************************//*!
					
					@file	KeyFrame.inl
					@brief	�L�[�t���[���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >::CKeyFrame() :
m_Value(NULL) ,
m_Time(0.0f) ,
m_Flag(0) ,
m_InterpolationType(KEYINTERPOLATION_LINEAR) {
	memset(m_InterpolationValue,0,sizeof(MofFloat) * MOF_KEYFRAMEINTERPOLATIONCOUNT);
}
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		v			�v�f
		@param[in]		t			����
		@param[in]		f			�t���O
		@param[in]		inter		��ԕ��@
		@param[in]		pinterval	��ԃp�����[�^�[

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >::CKeyFrame(const T& v,MofFloat t,MofU32 f,KeyFrameInterpolationType inter,LPCMofFloat pinterval) :
m_Value(v) ,
m_Time(t) ,
m_Flag(f) ,
m_InterpolationType(inter) {
	memset(m_InterpolationValue,0,sizeof(MofFloat) * MOF_KEYFRAMEINTERPOLATIONCOUNT);
	switch(inter)
	{
		case KEYINTERPOLATION_EASE:
			memcpy(m_InterpolationValue,pinterval,sizeof(MofFloat));
			break;
		case KEYINTERPOLATION_HERMITE:
			memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 2);
			break;
		case KEYINTERPOLATION_BEZIER1:
			memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 4);
			break;
		case KEYINTERPOLATION_BEZIER2:
			memcpy(m_InterpolationValue,pinterval,sizeof(MofFloat) * 4);
			break;
		case KEYINTERPOLATION_BEZIER2_VECTOR3:
			memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 12);
			break;
		case KEYINTERPOLATION_BEZIER2_VECTOR4:
			memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 16);
			break;
		default:
			memset(m_InterpolationValue,0,sizeof(MofFloat) * 16);
			break;
	}
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�t���[��

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >::CKeyFrame(const CKeyFrame< T >& pObj) :
m_Value(pObj.m_Value) ,
m_Time(pObj.m_Time) ,
m_Flag(pObj.m_Flag) ,
m_InterpolationType(pObj.m_InterpolationType) {
	memcpy(m_InterpolationValue,pObj.m_InterpolationValue,sizeof(MofFloat) * MOF_KEYFRAMEINTERPOLATIONCOUNT);
}		
/*************************************************************************//*!
		@brief			�R�s�[�L�[�t���[���̍쐬
		@param			None

		@return			�쐬���ꂽ�R�s�[�L�[�t���[��<br>
						�쐬�Ɏ��s�����ꍇNULL��Ԃ�
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >* CKeyFrame< T >::CreateCopyObject(void) const{
	return new CKeyFrame< T >(*this);
}
/*************************************************************************//*!
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >::~CKeyFrame(){
}
/*************************************************************************//*!
		@brief			�f�[�^�ݒ�
		@param[in]		v			�f�[�^
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrame< T >::SetValue(T& v){
	m_Value = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���Ԑݒ�
		@param[in]		t			�f�[�^
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrame< T >::SetTime(MofFloat v){
	m_Time = v;
	return TRUE;
}
/*************************************************************************//*!
		@brief			��Ԑݒ�
		@param[in]		inter		��ԕ��@
		@param[in]		pinterval	��ԃp�����[�^�[

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrame< T >::SetInterpolation(KeyFrameInterpolationType inter, LPCMofFloat pinterval) {
	m_InterpolationType = inter;
	switch (inter)
	{
	case KEYINTERPOLATION_EASE:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat));
		break;
	case KEYINTERPOLATION_HERMITE:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 2);
		break;
	case KEYINTERPOLATION_BEZIER1:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 4);
		break;
	case KEYINTERPOLATION_BEZIER2:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 4);
		break;
	case KEYINTERPOLATION_BEZIER2_VECTOR3:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 12);
		break;
	case KEYINTERPOLATION_BEZIER2_VECTOR4:
		memcpy(m_InterpolationValue, pinterval, sizeof(MofFloat) * 16);
		break;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���Ԏ擾
		@param			None

		@return			����
*//**************************************************************************/
template < typename T > FORCE_INLINE MofFloat CKeyFrame< T >::GetTime(void) const{
	return m_Time;
}
/*************************************************************************//*!
		@brief			�t���O�擾
		@param			None

		@return			�t���O
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CKeyFrame< T >::GetFlag(void) const{
	return m_Flag;
}
/*************************************************************************//*!
		@brief			��ԕ��@�擾
		@param			None

		@return			��ԕ��@
*//**************************************************************************/
template < typename T > FORCE_INLINE KeyFrameInterpolationType CKeyFrame< T >::GetInterpolationType(void) const{
	return m_InterpolationType;
}
/*************************************************************************//*!
		@brief			��ԏ��擾
		@param			None

		@return			��ԏ��
*//**************************************************************************/
template < typename T > FORCE_INLINE LPCMofFloat CKeyFrame< T >::GetInterpolationValue(void) const{
	return m_InterpolationValue;
}
/*************************************************************************//*!
		@brief			�f�[�^�擾
		@param			None

		@return			�f�[�^
*//**************************************************************************/
template < typename T > FORCE_INLINE T& CKeyFrame< T >::GetValue(void){
	return m_Value;
}
/*************************************************************************//*!
		@brief			�f�[�^�擾
		@param			None

		@return			�f�[�^
*//**************************************************************************/
template < typename T > FORCE_INLINE const T& CKeyFrame< T >::GetValue(void) const{
	return m_Value;
}

//[EOF]