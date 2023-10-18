/*************************************************************************//*!
					
					@file	DirectInput.inl
					@brief	DirectInput�ł̊e����͂̏������s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�L�[��Ԑݒ�
		@param[in]		n				�L�[�ԍ�
		@param[in]		bState			�L�[���
				
		@return			TRUE			�ݒ萬��<br>
						FALSE			�ݒ莸�s
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::SetKeyState(const MofU8 n,const MofBool bState){
	if(n >= MOFINPUT_KEYBOARDKEYMAX)
	{
		return FALSE;
	}
	if(bState)
	{
		m_bKeyboardState[n] |= 0x80;
	}
	else
	{
		m_bKeyboardState[n] &= ~0x80;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			�L�[��Ԑݒ�
		@param[in]		n				�L�[�ԍ�
		@param[in]		bState			�L�[���
				
		@return			TRUE			�ݒ萬��<br>
						FALSE			�ݒ莸�s
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::SetMouseState(const MofU8 n,const MofBool bState) {
	return FALSE;
}
/*************************************************************************//*!
		@brief			�z�C�[����Ԑݒ�
		@param[in]		w				�z�C�[�����
				
		@return			TRUE			�ݒ萬��<br>
						FALSE			�ݒ莸�s
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::SetMouseWheel(const MofFloat w) {
	return FALSE;
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
FORCE_INLINE MofBool CDirectInput::SetTouchState(MofS32 act, MofS32 Id, MofFloat x, MofFloat y){
	LPMOFTOUCHSTATE pTouch = NULL;
	//ID����v����^�b�`������
	for (MofU32 i = 0; i < MOF_TOUCHMAX; i++)
	{
		if (m_Touch[i].bTouch && m_Touch[i].Id == Id)
		{
			pTouch = &m_Touch[i];
			break;
		}
	}
	//�^�b�`�G�ꂽ�Ƃ�
	if (act == MOF_TOUCHEVENTDOWN)
	{
		//�󂫂�����
		for (MofU32 i = 0; i < MOF_TOUCHMAX && !pTouch; i++)
		{
			if (!m_Touch[i].bTouch)
			{
				pTouch = &m_Touch[i];
			}
		}
		if (pTouch)
		{
			pTouch->Pos.x = x;
			pTouch->Pos.y = y;
			pTouch->Id = Id;
			pTouch->bTouch = TRUE;
		}
		return TRUE;
	}
	//�^�b�`�ړ�
	else if (act == MOF_TOUCHEVENTMOVE && pTouch)
	{
		pTouch->Pos.x = x;
		pTouch->Pos.y = y;
		return TRUE;
	}
	//�^�b�`�������Ƃ�
	else if (act == MOF_TOUCHEVENTUP && pTouch)
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
FORCE_INLINE MofInputDevice CDirectInput::GetDevice(void){
	return m_pInput;
}
/*************************************************************************//*!
		@brief			�L�[�{�[�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsKeyPush(const MofU8 n){
	return (((m_bKeyboardState[n] & 0x80) && !(m_bPrevKeyboardState[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�L�[�{�[�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsKeyHold(const MofU8 n){
	return ((m_bKeyboardState[n] & 0x80) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�L�[�{�[�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsKeyPull(const MofU8 n){
	return ((!(m_bKeyboardState[n] & 0x80) && (m_bPrevKeyboardState[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�}�E�X�{�^�����͏�Ԕ���<br>
						�{�^���ԍ��̃{�^����Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		n				�{�^���ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsMouseKeyPush(const MofU8 n){
	if(n >= MOFINPUT_MOUSEBUTTONMAX)
	{
		return FALSE;
	}
	return (((m_MouseState.rgbButtons[n] & 0x80) && !(m_PrevMouseState.rgbButtons[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�}�E�X�{�^�����͏�Ԕ���<br>
						�{�^���ԍ��̃{�^����Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�{�^���ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsMouseKeyHold(const MofU8 n){
	if(n >= MOFINPUT_MOUSEBUTTONMAX)
	{
		return FALSE;
	}
	return ((m_MouseState.rgbButtons[n] & 0x80) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`�ԍ��̃^�b�`��Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		n				�^�b�`�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchPush(MofU32 n){
	return (GetTouchState(n) && !GetPrevTouchStateById(GetTouchState(n)->Id)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`ID�̃^�b�`��Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		Id				�^�b�`ID

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchPushById(MofS32 Id){
	return (GetTouchStateById(Id) && !GetPrevTouchStateById(Id)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`�ԍ��̃^�b�`��Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�^�b�`�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchHold(MofU32 n){
	return GetTouchState(n) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`ID�̃^�b�`��Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		Id				�^�b�`ID

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchHoldById(MofS32 Id){
	return GetTouchStateById(Id) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`�ԍ��̃^�b�`��Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�^�b�`�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchPull(MofU32 n){
	return (!GetTouchState(n) && GetPrevTouchState(n)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�^�b�`���͏�Ԕ���<br>
						�^�b�`ID�̃^�b�`��Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		Id				�^�b�`ID

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchPullById(MofS32 Id){
	return (!GetTouchStateById(Id) && GetPrevTouchStateById(Id)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			�}�E�X�{�^�����͏�Ԕ���<br>
						�{�^���ԍ��̃{�^����Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�{�^���ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsMouseKeyPull(const MofU8 n){
	if(n >= MOFINPUT_MOUSEBUTTONMAX)
	{
		return FALSE;
	}
	return ((!(m_MouseState.rgbButtons[n] & 0x80) && (m_PrevMouseState.rgbButtons[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�}�E�X���W����float�^�̃f�[�^�Ƃ��Ď擾����
		@param[out]		px			�}�E�X�w���W
		@param[out]		py			�}�E�X�x���W
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetMousePos(MofFloat& px,MofFloat& py){
	px = m_MouseState.lX;
	py = m_MouseState.lY;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�}�E�X���W��Vector2�^�̃f�[�^�Ƃ��Ď擾����
		@param[out]		v			Vector2
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�擾�G���[
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetMousePos(Vector2& v){
	v.x = m_MouseState.lX;
	v.y = m_MouseState.lY;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�}�E�X�̃z�C�[���ړ����擾����
		@param			None
				
		@return			�z�C�[���ړ���
*//**************************************************************************/
FORCE_INLINE MofFloat CDirectInput::GetMouseWheelMove(void){
	return m_MouseState.lZ;
}
/*************************************************************************//*!
		@brief			�}�E�X�ړ�����float�^�̃f�[�^�Ƃ��Ď擾����
		@param[out]		px			�}�E�X�w�ړ���
		@param[out]		py			�}�E�X�x�ړ���
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetMouseMove(MofFloat& px,MofFloat& py){
	px = m_MouseState.lX - m_PrevMouseState.lX;
	py = m_MouseState.lY - m_PrevMouseState.lY;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�}�E�X�ړ���Vector3�^�̃f�[�^�Ƃ��Ď擾����<br>
						x,y�ɂ̓J�[�\���̈ړ��ʂ�z�ɂ̓z�C�[���̈ړ��ʂ�����
		@param[out]		v			Vector3
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetMouseMove(Vector3& v){
	v.x = m_MouseState.lX - m_PrevMouseState.lX;
	v.y = m_MouseState.lY - m_PrevMouseState.lY;
	v.z = m_MouseState.lZ;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�Q�[���p�b�h�ڑ����擾
		@param			None

		@return			�Q�[���p�b�h�ڑ���
*//**************************************************************************/
FORCE_INLINE MofU32 CDirectInput::GetGamePadCount(void){
	return m_pGamePadArray->GetArrayCount();
}
/*************************************************************************//*!
		@brief			�Q�[���p�b�h�擾
		@param			None

		@return			�Q�[���p�b�h
*//**************************************************************************/
FORCE_INLINE LPGamePadArray CDirectInput::GetGamePad(void) {
	return m_pGamePadArray;
}
/*************************************************************************//*!
		@brief			�Q�[���p�b�h�擾<br>
						�ԍ��ɐڑ�����Ă���p�b�h���擾����B<br>
						���݂̐ڑ����ȏ�̒l���w�肵���ꍇNULL��Ԃ�
		@param[in]		n			�p�b�h�ԍ�

		@return			�Q�[���p�b�h
*//**************************************************************************/
FORCE_INLINE LPGamePad CDirectInput::GetGamePad(MofU32 n){
	if(n >= m_pGamePadArray->GetArrayCount())
	{
		return NULL;
	}
	return m_pGamePadArray->GetData(n);
}

/*************************************************************************//*!
		@brief			�^�b�`�F���ő吔�擾
		@param			None

		@return			�^�b�`�F���ő吔
*//**************************************************************************/
FORCE_INLINE MofU32 CDirectInput::GetTouchMax(){
	return MOF_TOUCHMAX;
}
/*************************************************************************//*!
		@brief			�^�b�`��Ԏ擾
						�^�b�`����ĂȂ����NULL��Ԃ�
		@param[in]		n			�^�b�`�C���f�b�N�X

		@return			�^�b�`���
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CDirectInput::GetTouchState(MofU32 n){
	if(n >= MOF_TOUCHMAX || !m_Touch[n].bTouch)
	{
		return NULL;
	}
	return &m_Touch[n];
}
/*************************************************************************//*!
		@brief			ID���g���ă^�b�`��Ԏ擾
						�^�b�`����ĂȂ����NULL��Ԃ�
		@param[in]		Id			�^�b�`ID

		@return			�^�b�`���
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CDirectInput::GetTouchStateById(MofS32 Id){
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
FORCE_INLINE LPCMOFTOUCHSTATE CDirectInput::GetPrevTouchState(MofU32 n){
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
FORCE_INLINE LPCMOFTOUCHSTATE CDirectInput::GetPrevTouchStateById(MofS32 Id){
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
FORCE_INLINE MofBool CDirectInput::GetTouchMove(MofU32 n,MofFloat& px,MofFloat& py){
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
FORCE_INLINE MofBool CDirectInput::GetTouchMoveById(MofS32 Id,MofFloat& px,MofFloat& py){
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