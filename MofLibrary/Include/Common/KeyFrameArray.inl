/*************************************************************************//*!
					
					@file	KeyFrameArray.inl
					@brief	�L�[�t���[���z��N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�������
		@param[in]		Data1		�O�̃L�[�̒l
		@param[in]		Data2		���̃L�[�̒l
		@param[in]		t			��Ԏ���
		@param[out]		Out			�o��

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
template < > struct CKeyFrameArrayImpl::InterpolationImpl< MofFloat > {
	static MofBool GetInterpolationValue(const MofFloat& Data1,const MofFloat& Data2, const MofFloat t,MofFloat& Out)
	{
		Out = Data1 + (MofFloat)((Data2 - Data1) * t);
		return TRUE;
	}
	static MofBool GetInterpolateBezierValue(const MofFloat& Data1, const MofFloat& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, MofFloat& Out)
	{
		float fCurrentPos = (nt - pt) * t + pt;
		float fCurrentCalc = 0.5f;
		float fCalcRange = 0.5f;

		float fTemp1;
		float fTemp2;
		float fTemp3;

		float fCurrentX;

		for (int iLoop = 0; iLoop < 8; iLoop++)
		{
			fTemp1 = 1.0f - fCurrentCalc;
			fTemp2 = fTemp1 * fTemp1;
			fTemp3 = fTemp2 * fTemp1;
			fCurrentX = (fTemp3 * pt) +
				(3 * fTemp2 * fCurrentCalc * (y1 + pt)) +
				(3 * fTemp1 * fCurrentCalc * fCurrentCalc * (y2 + nt)) +
				(fCurrentCalc * fCurrentCalc * fCurrentCalc * nt);

			fCalcRange /= 2.0f;
			if (fCurrentX > fCurrentPos)
			{
				fCurrentCalc -= fCalcRange;
			}
			else
			{
				fCurrentCalc += fCalcRange;
			}
		}
		fTemp1 = 1.0f - fCurrentCalc;
		fTemp2 = fTemp1 * fTemp1;
		fTemp3 = fTemp2 * fTemp1;
		Out = (Data1 * fTemp3) + (3 * fTemp2 * fCurrentCalc * (x1 + Data1)) + (3 * fTemp1 * fCurrentCalc * fCurrentCalc * (x2 + Data2)) + (fCurrentCalc * fCurrentCalc * fCurrentCalc * Data2);
		return TRUE;
	}
	static MofBool GetVector3TimeInterpolationValue(const MofFloat& Data1, const MofFloat& Data2, const Vector3& t, MofFloat& Out)
	{
		Out = Data1 + (MofFloat)((Data2 - Data1) * t.x);
		return TRUE;
	}
	static MofBool GetVector4TimeInterpolationValue(const MofFloat& Data1, const MofFloat& Data2, const Vector4& t, MofFloat& Out)
	{
		Out = Data1 + (MofFloat)((Data2 - Data1) * t.x);
		return TRUE;
	}
};
/*************************************************************************//*!
		@brief			�������(�N�H�[�^�j�I�����ʐ��`���)
		@param[in]		Data1		�O�̃L�[�̒l
		@param[in]		Data2		���̃L�[�̒l
		@param[in]		t			��Ԏ���
		@param[out]		Out			�o��

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
template < > struct CKeyFrameArrayImpl::InterpolationImpl< Quaternion > {
	static MofBool GetInterpolationValue(const Quaternion& Data1,const Quaternion& Data2,MofFloat t,Quaternion& Out)
	{
		CQuaternionUtilities::Slerp(Data1,Data2,t,Out);
		return TRUE;
	}
	static MofBool GetInterpolateBezierValue(const Quaternion& Data1, const Quaternion& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, Quaternion& Out)
	{
		MofFloat vt = CKeyFrameArray<Quaternion>::GetInterpolateBezierTime(x1, x2, y1, y2, pt, nt, t);
		return GetInterpolationValue(Data1, Data2, vt, Out);
	}
	static MofBool GetVector3TimeInterpolationValue(const Quaternion& Data1, const Quaternion& Data2, Vector3& t, Quaternion& Out)
	{
		CQuaternionUtilities::Slerp(Data1, Data2, t.x, Out);
		return TRUE;
	}
	static MofBool GetVector4TimeInterpolationValue(const Quaternion& Data1, const Quaternion& Data2, Vector4& t, Quaternion& Out)
	{
		CQuaternionUtilities::Slerp(Data1, Data2, t.x, Out);
		return TRUE;
	}
};
/*************************************************************************//*!
		@brief			�������(Vector3���`���)
		@param[in]		Data1		�O�̃L�[�̒l
		@param[in]		Data2		���̃L�[�̒l
		@param[in]		t			��Ԏ���
		@param[out]		Out			�o��

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
template < > struct CKeyFrameArrayImpl::InterpolationImpl< Vector3 > {
	static MofBool GetInterpolationValue(const Vector3& Data1, const Vector3& Data2, const MofFloat t, Vector3& Out)
	{
		Out = Data1 + ((Data2 - Data1) * t);
		return TRUE;
	}
	static MofBool GetInterpolateBezierValue(const Vector3& Data1, const Vector3& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, Vector3& Out)
	{
		MofFloat vt = CKeyFrameArray<Vector3>::GetInterpolateBezierTime(x1, x2, y1, y2, pt, nt, t);
		return GetInterpolationValue(Data1, Data2, vt, Out);
	}
	static MofBool GetVector3TimeInterpolationValue(const Vector3& Data1, const Vector3& Data2, const Vector3& t, Vector3& Out)
	{
		Out = Data1 + ((Data2 - Data1) * t);
		return TRUE;
	}
	static MofBool GetVector4TimeInterpolationValue(const Vector3& Data1, const Vector3& Data2, const Vector4& t, Vector3& Out)
	{
		Out = Data1 + ((Data2 - Data1) * Vector3(t.x,t.y,t.z));
		return TRUE;
	}
};
/*************************************************************************//*!
		@brief			�������(Vector4���`���)
		@param[in]		Data1		�O�̃L�[�̒l
		@param[in]		Data2		���̃L�[�̒l
		@param[in]		t			��Ԏ���
		@param[out]		Out			�o��

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
template < > struct CKeyFrameArrayImpl::InterpolationImpl< Vector4 > {
	static MofBool GetInterpolationValue(const Vector4& Data1, const Vector4& Data2, const MofFloat t, Vector4& Out)
	{
		Out = Data1 + ((Data2 - Data1) * t);
		return TRUE;
	}
	static MofBool GetInterpolateBezierValue(const Vector4& Data1, const Vector4& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, Vector4& Out)
	{
		MofFloat vt = CKeyFrameArray<Vector4>::GetInterpolateBezierTime(x1, x2, y1, y2, pt, nt, t);
		return GetInterpolationValue(Data1, Data2, vt, Out);
	}
	static MofBool GetVector3TimeInterpolationValue(const Vector4& Data1, const Vector4& Data2, const Vector3& t, Vector4& Out)
	{
		Out = Data1 + ((Data2 - Data1) * Vector4(t.x,t.y,t.z,1.0f));
		return TRUE;
	}
	static MofBool GetVector4TimeInterpolationValue(const Vector4& Data1, const Vector4& Data2, const Vector4& t, Vector4& Out)
	{
		Out = Data1 + ((Data2 - Data1) * t);
		return TRUE;
	}
};
/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrameArray< T >::CKeyFrameArray() :
CDynamicArray< CKeyFrame< T >* >() {
}
/*************************************************************************//*!
		@brief			�R�s�[�R���X�g���N�^
		@param[in]		pObj		�R�s�[�z��

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrameArray< T >::CKeyFrameArray(const CKeyFrameArray< T >& pObj) :
CDynamicArray< CKeyFrame< T >* >(pObj) {
}
/*************************************************************************//*!
		@brief			�f�X�g���N�^
		@param			None

		@return			None
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrameArray< T >::~CKeyFrameArray(){
	this->Release();
}
/*************************************************************************//*!
		@brief			�f�[�^�̃\�[�g�����s�����r�֐�
		@param[in]		A			�t���[���`
		@param[in]		B			�t���[���a

		@return			<0			A���O
						>0			B���O
						0			����
*//**************************************************************************/
template < typename T > FORCE_INLINE int CKeyFrameArray< T >::KeySortCompare(const void* A,const void* B){
	//�L�[�t���[�����o��
	CKeyFrame< T >* DataA = *((CKeyFrame< T >**)A);
	CKeyFrame< T >* DataB = *((CKeyFrame< T >**)B);
	//��r
	if(DataA->m_Time < DataB->m_Time)
	{
		return -1;
	}
	if(DataA->m_Time > DataB->m_Time)
	{
		return 1;
	}
	return 0;
}
/*************************************************************************//*!
		@brief			�L�[�t���[���̒ǉ�
		@param[in]		Time		�ǉ��L�[�t���[������
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::AddKeyFrame(MofFloat Time){
	if(GetKeyFrame(Time))
	{
		return FALSE;
	}
	T Data;
	GetTimeState(Time,Data);
	CKeyFrame< T >* pNow = GetNowKeyFrame(Time);
	if(pNow)
	{
		CKeyFrame< T >* pAdd = new CKeyFrame< T >(Data,Time,pNow->m_Flag,pNow->m_InterpolationType,NULL);
		if(!AddLast(&pAdd))
		{
			return FALSE;
		}
	}
	else
	{
		CKeyFrame< T >* pAdd = new CKeyFrame< T >(Data,Time,0,KEYINTERPOLATION_NONE,NULL);
		if(!AddLast(&pAdd))
		{
			return FALSE;
		}
	}
	return Sort();
}
/*************************************************************************//*!
		@brief			�L�[�t���[���̒ǉ�
		@param[in]		Data		�ǉ��L�[�t���[�����e
		@param[in]		Time		�ǉ��L�[�t���[������
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::AddKeyFrame(const T& Data,MofFloat Time){
	if(GetKeyFrame(Time))
	{
		return FALSE;
	}
	CKeyFrame< T >* pNow = GetNowKeyFrame(Time);
	if(pNow)
	{
		CKeyFrame< T >* pAdd = new CKeyFrame< T >(Data,Time,pNow->m_Flag,pNow->m_InterpolationType,NULL);
		if(!this->AddLast(&pAdd))
		{
			return FALSE;
		}
	}
	else
	{
		CKeyFrame< T >* pAdd = new CKeyFrame< T >(Data,Time,0,KEYINTERPOLATION_NONE,NULL);
		if(!this->AddLast(&pAdd))
		{
			return FALSE;
		}
	}
	return Sort();
}
/*************************************************************************//*!
		@brief			�L�[�t���[���̍폜
		@param[in]		Time		�폜�L�[�t���[������
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::DeleteKeyFrame(MofFloat Time){
	CKeyFrame< T >* pDel = GetKeyFrame(Time);
	if(!pDel)
	{
		return FALSE;
	}
	return Delete(&pDel);
}
/*************************************************************************//*!
		@brief			�z��̃\�[�g�����s����
		@param[in]		pFunc			��r�֐�
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::Sort(int (*pFunc)(const void *, const void *)){
	return CDynamicArray< CKeyFrame< T >* >::Sort(pFunc);
}
/*************************************************************************//*!
		@brief			���[�v�t���O�����邩�𔻒肷��
		@param			None
				
		@return			TRUE			���[�v����<br>
						FALSE			���[�v���Ȃ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::IsLoop(void){
	return ((this->m_Flag & KEYFRAMEARRAY_LOOPFLAG) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			���[�v�t���O�̐ݒ�
		@param[in]		Loop		���[�v�t���O<br>
									���[�v��L���ɂ���ꍇ��KEYFRAMEARRAY_LOOPALLFRAME��KEYFRAMEARRAY_LOOPSTARTFRAME���w��<br>
									���[�v�𖳌��ɂ���ꍇ��0���w�肷��B
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::SetLoop(MofU32 Loop){
	if(Loop)
	{
		if(!(this->m_Flag & KEYFRAMEARRAY_LOOPFLAG))
		{
			this->m_Flag |= (Loop & KEYFRAMEARRAY_LOOPFLAG);
		}
	}
	else if(this->m_Flag & KEYFRAMEARRAY_LOOPFLAG)
	{
		this->m_Flag &= ~KEYFRAMEARRAY_LOOPFLAG;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			�ŏ��̃L�[�t���[���̎��Ԏ擾
		@param			None

		@return			�ŏ��̃L�[�t���[���̎���
*//**************************************************************************/
template < typename T > FORCE_INLINE MofFloat CKeyFrameArray< T >::GetStartKeyTime(void) const {
	if(this->m_Count <= 0)
	{
		return 0.0f;
	}
	return this->m_pArray[0]->m_Time;
}
/*************************************************************************//*!
		@brief			�ŏI�̃L�[�t���[���̎��Ԏ擾
		@param			None

		@return			�ŏI�̃L�[�t���[���̎���
*//**************************************************************************/
template < typename T > FORCE_INLINE MofFloat CKeyFrameArray< T >::GetLastKeyTime(void) const {
	if(this->m_Count <= 0)
	{
		return 0.0f;
	}
	return this->m_pArray[this->m_Count - 1]->m_Time;
}
/*************************************************************************//*!
		@brief			���̎��Ԃ̃��[�v�̏I�����Ԏ擾
		@param[in]		t			����

		@return			���̎��Ԃ̃��[�v�̏I������
*//**************************************************************************/
template < typename T > FORCE_INLINE MofFloat CKeyFrameArray< T >::GetLoopLastTime(MofFloat t) const {
	//�L�[�t���[����0�Ȃ��b�f�[�^��Ԃ�
	if(this->m_Count <= 0)
	{
		return 0;
	}
	//�I���t���[���̎��Ԃ���Ȃ�
	if(t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//�I�����Ԃ���Ȃ�I�����Ԉȓ��Ɏ��߂�悤�Ɍv�Z������
		if(this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			return this->m_pArray[this->m_Count - 1]->m_Time + (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * ((int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time)) + 1);
		}
		else if(this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			return this->m_pArray[this->m_Count - 1]->m_Time * ((int)(t / this->m_pArray[this->m_Count - 1]->m_Time) + 1);
		}
	}
	//���ʂɏI������
	return GetLastKeyTime();
}
/*************************************************************************//*!
		@brief			�w�莞�Ԃ̃L�[���擾
		@param[in]		t			����

		@return			NULL		�L�[��������Ȃ�<br>
						����ȊO	�������L�[�t���[��
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >* CKeyFrameArray< T >::GetKeyFrame(MofFloat t) const {
	//�S���t���[������w�莞�Ԃ̂��̂�T��
	for(MofU32 i = 0;i < this->m_Count;i++)
	{
		if(this->m_pArray[i]->m_Time + 0.006f >= t && this->m_pArray[i]->m_Time - 0.006f <= t)
		{
			return this->m_pArray[i];
		}
	}
	//�w�莞�Ԃ̃L�[��������Ȃ�
	return NULL;
}
/*************************************************************************//*!
		@brief			�w�莞�Ԃ̃L�[�ԍ����擾
		@param[in]		t			����

		@return			�z��v�f�ԍ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CKeyFrameArray< T >::GetKeyFrameNo(MofFloat t) const {
	//�S���t���[������w�莞�Ԃ̂��̂�T��
	for (MofU32 i = 0; i < this->m_Count; i++)
	{
		if (this->m_pArray[i]->m_Time + 0.006f >= t && this->m_pArray[i]->m_Time - 0.006f <= t)
		{
			return i;
		}
	}
	//�w�莞�Ԃ̃L�[��������Ȃ�
	return MOF_U32_MAX;
}
/*************************************************************************//*!
		@brief			�w�莞�Ԃ̃L�[���擾
		@param[in]		t			����

		@return			NULL		�L�[��������Ȃ�<br>
						����ȊO	�������L�[�t���[��
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >* CKeyFrameArray< T >::GetNowKeyFrame(MofFloat t) const {
	//�L�[���Ȃ�
	if(this->m_Count <= 0)
	{
		return NULL;
	}
	//�I���t���[���̎��Ԃ���Ȃ�
	if(t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//�I�����Ԃ���Ȃ�I�����Ԉȓ��Ɏ��߂�悤�Ɍv�Z������
		if(this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time;
			t -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			t += this->m_pArray[0]->m_Time;
		}
		else if(this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(t / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			return this->m_pArray[this->m_Count - 1];
		}
	}
	//�����t���[���̎��Ԃ��O�Ȃ猻�݂̃t���[���͂Ȃ�
	if(t <= this->m_pArray[0]->m_Time)
	{
		return NULL;
	}
	//�S�L�[�t���[������
	for(MofU32 i = 1;i < this->m_Count;i++)
	{
		//�L�[�t���[���̎��Ԃ҂�����Ȃ�
		if(t == this->m_pArray[i]->m_Time)
		{
			return this->m_pArray[i];
		}
		//�L�[�t���[���̎��ԈȑO�Ȃ�
		else if(t < this->m_pArray[i]->m_Time)
		{
			return this->m_pArray[i - 1];
		}
	}
	//�����܂ŗ��Ă�Ƃ������Ƃ͐������L�[���������Ă��Ȃ�
	return NULL;
}
/*************************************************************************//*!
		@brief			�w�莞�Ԃ̃L�[�ԍ����擾
		@param[in]		t			����

		@return			�z��v�f�ԍ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CKeyFrameArray< T >::GetNowKeyFrameNo(MofFloat t) const {
	//�L�[���Ȃ�
	if (this->m_Count <= 0)
	{
		return MOF_U32_MAX;
	}
	//�I���t���[���̎��Ԃ���Ȃ�
	if (t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//�I�����Ԃ���Ȃ�I�����Ԉȓ��Ɏ��߂�悤�Ɍv�Z������
		if (this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time;
			t -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			t += this->m_pArray[0]->m_Time;
		}
		else if (this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(t / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			return this->m_Count - 1;
		}
	}
	//�����t���[���̎��Ԃ��O�Ȃ猻�݂̃t���[���͂Ȃ�
	if (t <= this->m_pArray[0]->m_Time)
	{
		return MOF_U32_MAX;
	}
	//�S�L�[�t���[������
	for (MofU32 i = 1; i < this->m_Count; i++)
	{
		//�L�[�t���[���̎��Ԃ҂�����Ȃ�
		if (t == this->m_pArray[i]->m_Time)
		{
			return i;
		}
		//�L�[�t���[���̎��ԈȑO�Ȃ�
		else if (t < this->m_pArray[i]->m_Time)
		{
			return i - 1;
		}
	}
	//�����܂ŗ��Ă�Ƃ������Ƃ͐������L�[���������Ă��Ȃ�
	return MOF_U32_MAX;
}
/*************************************************************************//*!
		@brief			�w�莞�Ԃ̎��̃L�[���擾
		@param[in]		t			����

		@return			NULL		�L�[��������Ȃ�<br>
						����ȊO	�������L�[�t���[��
*//**************************************************************************/
template < typename T > FORCE_INLINE CKeyFrame< T >* CKeyFrameArray< T >::GetNextKeyFrame(MofFloat t) const {
	//�L�[���Ȃ�
	if(this->m_Count <= 0)
	{
		return NULL;
	}
	//�I���t���[���̎��Ԃ���Ȃ�
	if(t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//�I�����Ԃ���Ȃ�I�����Ԉȓ��Ɏ��߂�悤�Ɍv�Z������
		if(this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time;
			t -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			t += this->m_pArray[0]->m_Time;
		}
		else if(this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(t / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			return NULL;
		}
	}
	//�����t���[���̎��Ԃ��O�Ȃ珉���t���[����Ԃ�
	if(t <= this->m_pArray[0]->m_Time)
	{
		return this->m_pArray[0];
	}
	//�S�L�[�t���[������
	for(MofU32 i = 1;i < this->m_Count;i++)
	{
		//�L�[�t���[���̎��Ԃ҂�����Ȃ�
		if(t == this->m_pArray[i]->m_Time)
		{
			return this->m_pArray[i + 1];
		}
		//�L�[�t���[���̎��ԈȑO�Ȃ�
		else if(t < this->m_pArray[i]->m_Time)
		{
			return this->m_pArray[i];
		}
	}
	//�����܂ŗ��Ă�Ƃ������Ƃ͐������L�[���������Ă��Ȃ�
	return NULL;
}
/*************************************************************************//*!
		@brief			�w�莞�Ԃ̃L�[�ԍ����擾
		@param[in]		t			����

		@return			�z��v�f�ԍ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofU32 CKeyFrameArray< T >::GetNextKeyFrameNo(MofFloat t) const {
	//�L�[���Ȃ�
	if (this->m_Count <= 0)
	{
		return MOF_U32_MAX;
	}
	//�I���t���[���̎��Ԃ���Ȃ�
	if (t > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//�I�����Ԃ���Ȃ�I�����Ԉȓ��Ɏ��߂�悤�Ɍv�Z������
		if (this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time;
			t -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(t / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			t += this->m_pArray[0]->m_Time;
		}
		else if (this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			t -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(t / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			return MOF_U32_MAX;
		}
	}
	//�����t���[���̎��Ԃ��O�Ȃ珉���t���[����Ԃ�
	if (t <= this->m_pArray[0]->m_Time)
	{
		return 0;
	}
	//�S�L�[�t���[������
	for (MofU32 i = 1; i < this->m_Count; i++)
	{
		//�L�[�t���[���̎��Ԃ҂�����Ȃ�
		if (t == this->m_pArray[i]->m_Time)
		{
			return i + 1;
		}
		//�L�[�t���[���̎��ԈȑO�Ȃ�
		else if (t < this->m_pArray[i]->m_Time)
		{
			return i;
		}
	}
	//�����܂ŗ��Ă�Ƃ������Ƃ͐������L�[���������Ă��Ȃ�
	return MOF_U32_MAX;
}
/*************************************************************************//*!
		@brief			�w�莞�Ԃ̃L�[��Ԃ��擾
		@param[in]		Time		����
		@param[out]		Out			�o��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
template < typename T > FORCE_INLINE MofBool CKeyFrameArray< T >::GetTimeState(MofFloat Time,T& Out) const {
	//�L�[���Ȃ�
	if(this->m_Count <= 0)
	{
		return FALSE;
	}
	//�L�[�t���[������Ȃ炻�̏�Ԃ�Ԃ�
	if(this->m_Count == 1)
	{
		Out = this->m_pArray[0]->m_Value;
		return TRUE;
	}
	//�I���t���[���̎��Ԃ���Ȃ�
	if(Time > this->m_pArray[this->m_Count - 1]->m_Time)
	{
		//�I�����Ԃ���Ȃ�I�����Ԉȓ��Ɏ��߂�悤�Ɍv�Z������
		if(this->m_Flag & KEYFRAMEARRAY_LOOPSTARTFRAME)
		{
			Time -= this->m_pArray[this->m_Count - 1]->m_Time;
			Time -= (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time) * (int)(Time / (this->m_pArray[this->m_Count - 1]->m_Time - this->m_pArray[0]->m_Time));
			Time += this->m_pArray[0]->m_Time;
		}
		else if(this->m_Flag & KEYFRAMEARRAY_LOOPALLFRAME)
		{
			Time -= this->m_pArray[this->m_Count - 1]->m_Time * (int)(Time / this->m_pArray[this->m_Count - 1]->m_Time);
		}
		else
		{
			Out = this->m_pArray[this->m_Count - 1]->m_Value;
			return TRUE;
		}
	}
	//�����t���[���̎��Ԃ��O�Ȃ珉���t���[����Ԃ�
	if(Time <= this->m_pArray[0]->m_Time)
	{
		Out = this->m_pArray[0]->m_Value;
		return TRUE;
	}
	//�S�L�[�t���[������
	for(MofU32 i = 1;i < this->m_Count;i++)
	{
		//�L�[�t���[���̎��Ԃ҂�����Ȃ�
		if(Time == this->m_pArray[i]->m_Time)
		{
			Out = this->m_pArray[i]->m_Value;
			return TRUE;
		}
		//�L�[�t���[���̎��ԈȑO�Ȃ�
		else if(Time < this->m_pArray[i]->m_Time)
		{
			//�O�ƍ��̃|�C���^���o��
			CKeyFrame< T >* prev = this->m_pArray[i - 1];
			if(prev->m_InterpolationType == KEYINTERPOLATION_NONE)
			{
				Out = prev->m_Value;
				return TRUE;
			}
			CKeyFrame< T >* next = this->m_pArray[i];
			//�����쎞�Ԃ����߂�
			MofFloat t = (Time - prev->m_Time) / (MofFloat)(next->m_Time - prev->m_Time);
			switch(prev->m_InterpolationType)
			{
				case KEYINTERPOLATION_EASE:
					t = (1 - prev->m_InterpolationValue[0]) * t + prev->m_InterpolationValue[0] * t * t;
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);

				case KEYINTERPOLATION_HERMITE:
					t = GetInterpolateHermiteTime(prev->m_InterpolationValue[0], prev->m_InterpolationValue[1], t);
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);

				case KEYINTERPOLATION_BEZIER1:
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);
					//return InterpolationImpl< T >::GetInterpolateBezierValue(prev->m_Value, next->m_Value, prev->m_InterpolationValue[0], prev->m_InterpolationValue[1], prev->m_InterpolationValue[2], prev->m_InterpolationValue[3], prev->m_Time, next->m_Time, t, Out);

				case KEYINTERPOLATION_BEZIER2:
					t = GetInterpolateBezierTime(prev->m_InterpolationValue[0],prev->m_InterpolationValue[1],prev->m_InterpolationValue[2],prev->m_InterpolationValue[3],t);
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);

				case KEYINTERPOLATION_BEZIER2_VECTOR3:
				{
					Vector3 vt(
						GetInterpolateBezierTime(prev->m_InterpolationValue[0], prev->m_InterpolationValue[1], prev->m_InterpolationValue[2], prev->m_InterpolationValue[3], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[4], prev->m_InterpolationValue[5], prev->m_InterpolationValue[6], prev->m_InterpolationValue[7], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[8], prev->m_InterpolationValue[9], prev->m_InterpolationValue[10], prev->m_InterpolationValue[11], t)
						);
					return InterpolationImpl< T >::GetVector3TimeInterpolationValue(prev->m_Value, next->m_Value, vt, Out);
				}

				case KEYINTERPOLATION_BEZIER2_VECTOR4:
				{
					Vector4 vt(
						GetInterpolateBezierTime(prev->m_InterpolationValue[0], prev->m_InterpolationValue[1], prev->m_InterpolationValue[2], prev->m_InterpolationValue[3], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[4], prev->m_InterpolationValue[5], prev->m_InterpolationValue[6], prev->m_InterpolationValue[7], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[8], prev->m_InterpolationValue[9], prev->m_InterpolationValue[10], prev->m_InterpolationValue[11], t),
						GetInterpolateBezierTime(prev->m_InterpolationValue[12], prev->m_InterpolationValue[13], prev->m_InterpolationValue[14], prev->m_InterpolationValue[15], t)
						);
					return InterpolationImpl< T >::GetVector4TimeInterpolationValue(prev->m_Value, next->m_Value, vt, Out);
				}

				default:
					return InterpolationImpl< T >::GetInterpolationValue(prev->m_Value, next->m_Value, t, Out);
			}
		}
	}
	//�����܂ŗ��Ă�Ƃ������Ƃ͐������L�[���������Ă��Ȃ�
	return FALSE;
}
/*************************************************************************//*!
		@brief			�G���~�[�g��ԂŌ��݂̎��Ԃ����߂�
		@param[in]		x1			X�R���g���[���|�C���g
		@param[in]		x2			X�R���g���[���|�C���g
		@param[in]		x			���݈ʒu
				
		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CKeyFrameArrayImpl::GetInterpolateHermiteTime(const MofFloat x1, const MofFloat x2, const MofFloat t){
	float start = 0.0f;
	float end = 1.0f;
	float t2 = t * t;
	float t3 = t2 * t;
	return (2 * t3 - 3 * t2 + 1) * start + (-2 * t3 + 3 * t2) * end + (t3 - 2 * t2 + t) * (x1 - start) + (t3 - t2) * (x2 - end);
}
/*************************************************************************//*!
		@brief			�R���x�W�F��ԂŌ��݂̎��Ԃ����߂�
		@param[in]		x1			X�R���g���[���|�C���g
		@param[in]		x2			X�R���g���[���|�C���g
		@param[in]		y1			Y�R���g���[���|�C���g
		@param[in]		y2			Y�R���g���[���|�C���g
		@param[in]		pt			�O�̃L�[�̎���
		@param[in]		nt			���̃L�[�̎���
		@param[in]		t			���݈ʒu
				
		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CKeyFrameArrayImpl::GetInterpolateBezierTime(const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t){
	float start = 0.0f;
	float end = 1.0f;
	float fCurrentPos = (nt - pt) * t + pt;
	float fCurrentCalc = 0.5f;
	float fCalcRange = 0.5f;

	float fTemp1;
	float fTemp2;
	float fTemp3;

	float fCurrentX;

	for (int iLoop = 0; iLoop < 8; iLoop++)
	{
		fTemp1 = 1.0f - fCurrentCalc;
		fTemp2 = fTemp1 * fTemp1;
		fTemp3 = fTemp2 * fTemp1;
		fCurrentX = (fTemp3 * pt) +
			(3 * fTemp2 * fCurrentCalc * (y1 + pt)) +
			(3 * fTemp1 * fCurrentCalc * fCurrentCalc * (y2 + nt)) +
			(fCurrentCalc * fCurrentCalc * fCurrentCalc * nt);

		fCalcRange /= 2.0f;
		if (fCurrentX > fCurrentPos)
		{
			fCurrentCalc -= fCalcRange;
		}
		else
		{
			fCurrentCalc += fCalcRange;
		}
	}
	fTemp1 = 1.0f - fCurrentCalc;
	fTemp2 = fTemp1 * fTemp1;
	fTemp3 = fTemp2 * fTemp1;
	return (start * fTemp3) + (3 * fTemp2 * fCurrentCalc * (x1 + start)) + (3 * fTemp1 * fCurrentCalc * fCurrentCalc * (x2 + end)) + (fCurrentCalc * fCurrentCalc * fCurrentCalc * end);
}
/*************************************************************************//*!
		@brief			�R���x�W�F��ԂŌ��݂̎��Ԃ����߂�
		@param[in]		x1			X�R���g���[���|�C���g
		@param[in]		x2			X�R���g���[���|�C���g
		@param[in]		y1			Y�R���g���[���|�C���g
		@param[in]		y2			Y�R���g���[���|�C���g
		@param[in]		x			���݈ʒu
				
		@return			����
*//**************************************************************************/
FORCE_INLINE MofFloat CKeyFrameArrayImpl::GetInterpolateBezierTime(const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat x){
	if (MOF_ABS(x1 - x2) < 0.0001f && MOF_ABS(y1 - y2) < 0.0001f)
	{
		return x;
	}
	int l;
	float NT, InvT;
	for (l = 0, NT = x, InvT = 1.0f - NT; l < 32; l++)
	{
		float TempX = 3.0f * InvT * InvT * NT * x1 + 3.0f * InvT * NT * NT * x2 + NT * NT * NT - x;
		if (TempX < 0.0001f && TempX > -0.0001f)
		{
			break;
		}
		NT -= TempX * 0.5f;
		InvT = 1.0f - NT;
	}
	return 3.0f * InvT * InvT * NT * y1 + 3.0f * InvT * NT * NT * y2 + NT * NT * NT;
	/*
	RateH = InvT * InvT * T * Y1 + InvT * T * T * Y2 + T * T * T;
	MofFloat t = 0.5f;
	MofFloat s = 0.5f;
	for(MofU32 i = 0; i < MOF_KEYINTERPOLATIONBEZIER2COUNT;i++)
	{
		MofFloat ft = (3.0f * s * s * t * x1) + (3.0f * s * t * t * x2) + (t * t * t) - x;
		if(MOF_ABS(ft) < 0.00001f)
		{
			break;
		}
		if(ft > 0.0f)
		{
			t -= 1 / (4 << i);
		}
		else
		{
			t += 1 / (4 << i);
		}
		s = 1.0f - t;
	}
	return (3.0f * s * s * t * y1) + (3.0f * s * t * t * y2) + (t * t * t);*/
}

//[EOF]