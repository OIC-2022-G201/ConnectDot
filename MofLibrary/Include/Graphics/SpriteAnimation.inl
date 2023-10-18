/*************************************************************************//*!
					
					@file	SpriteAnimation.inl
					@brief	�X�v���C�g�A�j���[�V�����N���X�B<br>
							�X�v���C�g�̋�`�ω��ł̃A�j���[�V�������s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�R���X�g���N�^
		@param[in]		frm				�t���[��

		@return			None
*//**************************************************************************/
template < int N > FORCE_INLINE CSpriteAnimation::CSpriteAnimation(SpriteAnimationCreateFrame< N >& frm) : 
m_Name(frm.Name) {
	MofS32 nc;
	for(nc = 0;nc < N && frm.Pattern[nc].Wait > 0;nc++);
	m_RectKeyFrame.ReSize(nc + 1);
	m_RectKeyFrame.SetFlag(((frm.bLoop) ? KEYFRAMEARRAY_ARRAYMEMBERDELETE | KEYFRAMEARRAY_LOOPALLFRAME | KEYFRAMEARRAY_ARRAYMEMBERCOPY : KEYFRAMEARRAY_ARRAYMEMBERDELETE | KEYFRAMEARRAY_ARRAYMEMBERCOPY));
	MofFloat wt = 0.0f;
	MofFloat ft = ((CUtilities::GetRestrictFPS() <= 0) ? 1.0f : 1.0f / CUtilities::GetRestrictFPS());
	for(int i = 0;i <= nc;i++)
	{
		if(i == nc)
		{
			MofFloat ox = frm.OffsetX + frm.Width * frm.Pattern[i - 1].No;
			MofFloat oy = frm.OffsetY + frm.Height * frm.Pattern[i - 1].Step;
			Rectangle r(ox,oy,ox + frm.Width,oy + frm.Height);
			LPRectangleKeyFrame pKey = new CRectangleKeyFrame(r,wt,0,KEYINTERPOLATION_NONE,NULL);
			m_RectKeyFrame.SetData(pKey,i);
		}
		else
		{
			MofFloat ox = frm.OffsetX + frm.Width * frm.Pattern[i].No;
			MofFloat oy = frm.OffsetY + frm.Height * frm.Pattern[i].Step;
			Rectangle r(ox,oy,ox + frm.Width,oy + frm.Height);
			LPRectangleKeyFrame pKey = new CRectangleKeyFrame(r,wt,0,KEYINTERPOLATION_NONE,NULL);
			m_RectKeyFrame.SetData(pKey,i);
			wt += frm.Pattern[i].Wait * ft;
		}
	}
}
/*************************************************************************//*!
		@brief			���݂̃��[�V���������[�v���邩�𔻒肷��B
		@param			None
				
		@return			TRUE			���[�v����<br>
						FALE			���[�v���Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteAnimation::IsLoop(void){
	return ((m_RectKeyFrame.GetFlag() & KEYFRAMEARRAY_LOOPFLAG) ? TRUE  : FALSE);
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���[�V�����̃��[�v�t���O�̐ݒ�
		@param[in]		bLoop			���[�v�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteAnimation::SetLoop(MofBool bLoop){
	return m_RectKeyFrame.SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CSpriteAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�w�莞�Ԃł̋�`�擾
		@param[in]		t				����
		@param[out]		oRec			�o�͋�`
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteAnimation::GetTimeRect(const MofFloat t,Rectangle& oRec){
	return m_RectKeyFrame.GetTimeState(t,oRec);
}
/*************************************************************************//*!
		@brief			�w�莞�Ԃł̃t���[���ԍ��擾
		@param[in]		t				����

		@return			�t���[���ԍ�
*//**************************************************************************/
FORCE_INLINE MofU32 CSpriteAnimation::GetTimeFrameNo(const MofFloat t) {
	return m_RectKeyFrame.GetNowKeyFrameNo(t);
}
/*************************************************************************//*!
		@brief			�A�j���[�V�����̏I�����Ԏ擾<br>
						���[�v������ꍇ�ł��ŏI�̃t���[���̎��Ԃ�Ԃ�
		@param			None
				
		@return			�A�j���[�V�����̏I������
*//**************************************************************************/
FORCE_INLINE MofFloat CSpriteAnimation::GetEndTime(void){
	return m_RectKeyFrame.GetLastKeyTime();
}

//[EOF]