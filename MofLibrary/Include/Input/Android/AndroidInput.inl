/*************************************************************************//*!
					
					@file	AndroidInput.inl
					@brief	AndroidInput�ł̊e����͂̏������s���N���X�B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�L�[��Ԑݒ�
		@param[in]		n				�L�[�ԍ�
		@param[in]		bState			�L�[���
				
		@return			TRUE			�ݒ萬��<br>
						FALSE			�ݒ莸�s
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::SetKeyState(const MofU8 n,const MofBool bState){
	if(n >= MOFINPUT_KEYBOARDKEYMAX)
	{
		return FALSE;
	}
	m_bKeyState[n] = bState;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�^�b�`���ݒ�<br>
						�^�b�`���͂��L���ȏꍇ�̂ݏ��������s�B
		@param[in]		act				�^�b�`����t���O
		@param[in]		Id				�^�b�`ID
		@param[in]		x				�^�b�`X���W
		@param[in]		y				�^�b�`Y���W

		@return			�C���v�b�g�f�o�C�X
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::SetTouchState(MofS32 act,MofS32 Id,MofFloat x,MofFloat y){
	LPMOFTOUCHSTATE pTouch = NULL;
	//ID����v����^�b�`������
	for(MofU32 i = 0;i < MOF_TOUCHMAX;i++)
	{
		if(m_Touch[i].bTouch && m_Touch[i].Id == Id)
		{
			pTouch = &m_Touch[i];
			break;
		}
	}
	//�^�b�`�G�ꂽ�Ƃ�
	if(act == MOF_TOUCHEVENTDOWN || act == MOF_TOUCHEVENTPOINTERDOWN)
	{
		//�󂫂�����
		for(MofU32 i = 0;i < MOF_TOUCHMAX && !pTouch;i++)
		{
			if(!m_Touch[i].bTouch)
			{
				pTouch = &m_Touch[i];
			}
		}
		if(pTouch)
		{
			pTouch->Pos.x = x;
			pTouch->Pos.y = y;
			pTouch->Id = Id;
			pTouch->bTouch = TRUE;
		}
		return TRUE;
	}
	//�^�b�`�ړ�
	else if(act == MOF_TOUCHEVENTMOVE && pTouch)
	{
		pTouch->Pos.x = x;
		pTouch->Pos.y = y;
		return TRUE;
	}
	//�^�b�`�������Ƃ�
	else if((act == MOF_TOUCHEVENTUP || act == MOF_TOUCHEVENTPOINTERUP) && pTouch)
	{
		pTouch->bTouch = FALSE;
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�C���v�b�g�f�o�C�X�擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�C���v�b�g�f�o�C�X
*//**************************************************************************/
FORCE_INLINE MofInputDevice CAndroidInput::GetDevice(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			�L�[�{�[�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsKeyPush(const MofU8 n){
	return (((m_bKeyState[n]) && !(m_bPrevKeyState[n])) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�L�[�{�[�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsKeyHold(const MofU8 n){
	return m_bKeyState[n];
}
/*************************************************************************//*!
		@brief			�L�[�{�[�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsKeyPull(const MofU8 n){
	return ((!(m_bKeyState[n]) && (m_bPrevKeyState[n])) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�}�E�X�{�^�����͏�Ԕ���<br>
						�{�^���ԍ��̃{�^����Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		n				�{�^���ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsMouseKeyPush(const MofU8 n){
	if(n >= MOF_TOUCHMAX)
	{
		return FALSE;
	}
	return ((m_Touch[n].bTouch && !m_PrevTouch[n].bTouch) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�}�E�X�{�^�����͏�Ԕ���<br>
						�{�^���ԍ��̃{�^����Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�{�^���ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsMouseKeyHold(const MofU8 n){
	if(n >= MOF_TOUCHMAX)
	{
		return FALSE;
	}
	return m_Touch[n].bTouch;
}
/*************************************************************************//*!
		@brief			�}�E�X�{�^�����͏�Ԕ���<br>
						�{�^���ԍ��̃{�^����Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�{�^���ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsMouseKeyPull(const MofU8 n){
	if(n >= MOF_TOUCHMAX)
	{
		return FALSE;
	}
	return ((!m_Touch[n].bTouch && m_PrevTouch[n].bTouch) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`�ԍ��̃^�b�`��Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		n				�^�b�`�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsTouchPush(MofU32 n){
	return (GetTouchState(n) && !GetPrevTouchStateById(GetTouchState(n)->Id)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`ID�̃^�b�`��Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		Id				�^�b�`ID

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsTouchPushById(MofS32 Id){
	return (GetTouchStateById(Id) && !GetPrevTouchStateById(Id)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`�ԍ��̃^�b�`��Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�^�b�`�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsTouchHold(MofU32 n){
	return GetTouchState(n) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`ID�̃^�b�`��Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		Id				�^�b�`ID

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsTouchHoldById(MofS32 Id){
	return GetTouchStateById(Id) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`�ԍ��̃^�b�`��Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�^�b�`�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsTouchPull(MofU32 n){
	return (!GetTouchState(n) && GetPrevTouchState(n)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`ID�̃^�b�`��Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		Id				�^�b�`ID

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::IsTouchPullById(MofS32 Id){
	return (!GetTouchStateById(Id) && GetPrevTouchStateById(Id)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�}�E�X���W����float�^�̃f�[�^�Ƃ��Ď擾����
		@param[out]		px			�}�E�X�w���W
		@param[out]		py			�}�E�X�x���W
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::GetMousePos(MofFloat& px,MofFloat& py){
	for(MofU32 i = 0;i < MOF_TOUCHMAX;i++)
	{
		if(m_Touch[i].bTouch)
		{
			px = m_Touch[i].Pos.x;
			py = m_Touch[i].Pos.y;
			return TRUE;
		}
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�}�E�X���W��Vector2�^�̃f�[�^�Ƃ��Ď擾����
		@param[out]		v			Vector2
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�擾�G���[
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::GetMousePos(Vector2& v){
	for(MofU32 i = 0;i < MOF_TOUCHMAX;i++)
	{
		if(m_Touch[i].bTouch)
		{
			v = m_Touch[i].Pos;
			return TRUE;
		}
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�}�E�X�̃z�C�[���ړ����擾����
		@param			None
				
		@return			�z�C�[���ړ���
*//**************************************************************************/
FORCE_INLINE MofFloat CAndroidInput::GetMouseWheelMove(void){
	return 0.0f;
}
/*************************************************************************//*!
		@brief			�}�E�X�ړ�����float�^�̃f�[�^�Ƃ��Ď擾����
		@param[out]		px			�}�E�X�w�ړ���
		@param[out]		py			�}�E�X�x�ړ���
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::GetMouseMove(MofFloat& px,MofFloat& py){
	for(MofU32 i = 0;i < MOF_TOUCHMAX;i++)
	{
		if(m_Touch[i].bTouch && m_PrevTouch[i].bTouch)
		{
			px = m_Touch[i].Pos.x - m_PrevTouch[i].Pos.x;
			py = m_Touch[i].Pos.y - m_PrevTouch[i].Pos.y;
			return TRUE;
		}
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			�}�E�X�ړ���Vector3�^�̃f�[�^�Ƃ��Ď擾����<br>
						x,y�ɂ̓J�[�\���̈ړ��ʂ�z�ɂ̓z�C�[���̈ړ��ʂ�����
		@param[out]		v			Vector3
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::GetMouseMove(Vector3& v){
	GetMouseMove(v.x,v.y);
	v.z = 0.0f;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�Q�[���p�b�h�ڑ����擾
		@param			None

		@return			�Q�[���p�b�h�ڑ���
*//**************************************************************************/
FORCE_INLINE MofU32 CAndroidInput::GetGamePadCount(void){
	return 0;
}
/*************************************************************************//*!
		@brief			�Q�[���p�b�h�擾<br>
						�ԍ��ɐڑ�����Ă���p�b�h���擾����B<br>
						���݂̐ڑ����ȏ�̒l���w�肵���ꍇNULL��Ԃ�
		@param[in]		n			�p�b�h�ԍ�

		@return			�Q�[���p�b�h
*//**************************************************************************/
FORCE_INLINE LPGamePad CAndroidInput::GetGamePad(MofU32 n){
	return NULL;
}
/*************************************************************************//*!
		@brief			�^�b�`�F���ő吔�擾
		@param			None

		@return			�^�b�`�F���ő吔
*//**************************************************************************/
FORCE_INLINE MofU32 CAndroidInput::GetTouchMax(){
	return MOF_TOUCHMAX;
}
/*************************************************************************//*!
		@brief			�^�b�`��Ԏ擾
						�^�b�`����ĂȂ����NULL��Ԃ�
		@param[in]		n			�^�b�`�C���f�b�N�X

		@return			�^�b�`���
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CAndroidInput::GetTouchState(MofU32 n){
	if(n >= MOF_TOUCHMAX || !m_Touch[n].bTouch)
	{
		return NULL;
	}
	return &m_Touch[n];
}
/*************************************************************************//*!
		@brief			ID���g���ă^�b�`��Ԏ擾
						�^�b�`����ĂȂ����NULL��Ԃ�
		@param[in]		n			�^�b�`ID

		@return			�^�b�`���
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CAndroidInput::GetTouchStateById(MofS32 Id){
	for(MofU32 i = 0;i < MOF_TOUCHMAX;i++)
	{
		if(m_Touch[i].bTouch && m_Touch[i].Id == Id)
		{
			return &m_Touch[i];
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			���O�̃^�b�`��Ԏ擾
						�^�b�`����ĂȂ����NULL��Ԃ�
		@param[in]		n			�^�b�`�ԍ�

		@return			���O�̃^�b�`���
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CAndroidInput::GetPrevTouchState(MofU32 n){
	if(n >= MOF_TOUCHMAX || !m_PrevTouch[n].bTouch)
	{
		return NULL;
	}
	return &m_PrevTouch[n];
}
/*************************************************************************//*!
		@brief			ID���g���Ē��O�̃^�b�`��Ԏ擾
						�^�b�`����ĂȂ����NULL��Ԃ�
		@param[in]		n			�^�b�`ID

		@return			���O�̃^�b�`���
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CAndroidInput::GetPrevTouchStateById(MofS32 Id){
	for(MofU32 i = 0;i < MOF_TOUCHMAX;i++)
	{
		if(m_PrevTouch[i].bTouch && m_PrevTouch[i].Id == Id)
		{
			return &m_PrevTouch[i];
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			�^�b�`�ړ�����float�^�̃f�[�^�Ƃ��Ď擾����
		@param[in]		n			�^�b�`�ԍ�
		@param[out]		px			�^�b�`�w�ړ���
		@param[out]		py			�^�b�`�x�ړ���

		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::GetTouchMove(MofU32 n,MofFloat& px,MofFloat& py){
	LPCMOFTOUCHSTATE pTouch = GetTouchState(n);
	LPCMOFTOUCHSTATE pPrev = pTouch ? GetPrevTouchStateById(pTouch->Id) : NULL;
	if(pTouch && pPrev)
	{
		px = pTouch->Pos.x - pPrev->Pos.x;
		py = pTouch->Pos.y - pPrev->Pos.y;
	}
	else
	{
		px = py = 0;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			�^�b�`�ړ�����float�^�̃f�[�^�Ƃ��Ď擾����
		@param[in]		Id			�^�b�`ID
		@param[out]		px			�^�b�`�w�ړ���
		@param[out]		py			�^�b�`�x�ړ���

		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CAndroidInput::GetTouchMoveById(MofS32 Id,MofFloat& px,MofFloat& py){
	LPCMOFTOUCHSTATE pTouch = GetTouchStateById(Id);
	LPCMOFTOUCHSTATE pPrev = GetPrevTouchStateById(Id);
	if(pTouch && pPrev)
	{
		px = pTouch->Pos.x - pPrev->Pos.x;
		py = pTouch->Pos.y - pPrev->Pos.y;
	}
	else
	{
		px = py = 0;
	}
	return TRUE;
}

//[EOF]
