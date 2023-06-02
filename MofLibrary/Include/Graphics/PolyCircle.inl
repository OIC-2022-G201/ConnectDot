/*************************************************************************//*!
					
					@file	PolyCircle.inl
					@brief	�|���T�[�N���W�I���g���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���͐F�ݒ�
		@param[in]		cn				���ԍ�
		@param[in]		c				�F

		@return			TRUE			����I��<br>
		����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CPolyCircle::SetColor(MofU32 cn, CVector4& c){
	//�ҏW�p�����o��
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	if (cn >= mc)
	{
		return FALSE;
	}
	pPoint[cn].Color = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���͔��a�ݒ�
		@param[in]		cn				���ԍ�
		@param[in]		r				���a

		@return			TRUE			����I��<br>
		����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CPolyCircle::SetRadius(MofU32 cn, MofFloat r){
	//�ҏW�p�����o��
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	if (cn >= mc)
	{
		return FALSE;
	}
	pPoint[cn].Radius = r;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���͔��a�䗦�ێ��ݒ�
		@param[in]		cn				���ԍ�
		@param[in]		r				���a

		@return			TRUE			����I��<br>
		����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CPolyCircle::SetRadiusRatio(MofU32 cn, MofFloat r){
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	if (cn >= mc)
	{
		return FALSE;
	}
	MofFloat ar = GetRadius();
	MofFloat outr = ar - pPoint[cn].Radius;
	MofFloat nor = ar - r;
	for (MofU32 i = 1; i < mc; i++)
	{
		if (i == cn)
		{
			pPoint[i].Radius = r;
		}
		else
		{
			pPoint[i].Radius = nor * (pPoint[i].Radius / outr);
		}
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���v���a�擾
		@param			None

		@return			���v���a
*//**************************************************************************/
FORCE_INLINE MofFloat CPolyCircle::GetRadius(void){
	//�ҏW�p�����o��
	MofFloat re = 0.0f;
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	for (MofU32 i = 1; i < mc; i++)
	{
		re += pPoint[i].Radius;
	}
	return re;
}
/*************************************************************************//*!
		@brief			���a�擾
		@param[in]		cn				���ԍ�

		@return			���a
*//**************************************************************************/
FORCE_INLINE MofFloat CPolyCircle::GetRadius(MofU32 cn){
	MofU32 mc = m_pPointArray->GetArrayCount();
	LPPOLYCIRCLEPOINT pPoint = m_pPointArray->GetArray();
	if (cn >= mc)
	{
		return 0.0f;
	}
	return pPoint[cn].Radius;
}
/*************************************************************************//*!
		@brief			�~���̐��擾
		@param			None

		@return			�~���̐�
*//**************************************************************************/
FORCE_INLINE MofU32 CPolyCircle::GetCircleCount(void){
	return m_pPointArray->GetArrayCount();
}
/*************************************************************************//*!
		@brief			�~���擾
		@param			None

		@return			�~��
*//**************************************************************************/
FORCE_INLINE LPPOLYCIRCLEPOINT CPolyCircle::GetCircleArray(void){
	return m_pPointArray->GetArray();
}

//[EOF]