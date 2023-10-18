/*************************************************************************//*!
					
					@file	InputUtilities.cpp
					@brief	�C���v�b�g�֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�L�[�{�[�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsKeyPush(const MofU8 n){
	return m_pInput->IsKeyPush(n);
}
/*************************************************************************//*!
		@brief			�L�[�{�[�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsKeyHold(const MofU8 n){
	return m_pInput->IsKeyHold(n);
}
/*************************************************************************//*!
		@brief			�L�[�{�[�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsKeyPull(const MofU8 n){
	return m_pInput->IsKeyPull(n);
}
/*************************************************************************//*!
		@brief			�}�E�X�{�^�����͏�Ԕ���<br>
						�{�^���ԍ��̃{�^����Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		n				�{�^���ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsMouseKeyPush(const MofU8 n){
	return m_pInput->IsMouseKeyPush(n);
}
/*************************************************************************//*!
		@brief			�}�E�X�{�^�����͏�Ԕ���<br>
						�{�^���ԍ��̃{�^����Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�{�^���ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsMouseKeyHold(const MofU8 n){
	return m_pInput->IsMouseKeyHold(n);
}
/*************************************************************************//*!
		@brief			�}�E�X�{�^�����͏�Ԕ���<br>
						�{�^���ԍ��̃{�^����Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�{�^���ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsMouseKeyPull(const MofU8 n){
	return m_pInput->IsMouseKeyPull(n);
}
/*************************************************************************//*!
		@brief			�C���v�b�g�C���^�[�t�F�C�X��ݒ肷��
		@param[in]		pg				�C���v�b�g�C���^�[�t�F�C�X

		@return			None
*//**************************************************************************/
FORCE_INLINE void CInputUtilities::SetInput(LPInput pg){
	m_pInput = pg;
	return;
}
/*************************************************************************//*!
		@brief			�L�[��Ԑݒ�
		@param[in]		n				�L�[�ԍ�
		@param[in]		bState			�L�[���
				
		@return			TRUE			�ݒ萬��<br>
						FALSE			�ݒ莸�s
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::SetKeyState(const MofU8 n,const MofBool bState){
	return m_pInput->SetKeyState(n,bState);
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
FORCE_INLINE MofBool CInputUtilities::SetTouchState(MofS32 act,MofS32 Id,MofFloat x,MofFloat y){
	return m_pInput->SetTouchState(act,Id,x,y);
}
/*************************************************************************//*!
		@brief			�C���v�b�g�C���^�[�t�F�C�X���擾����
		@param			None

		@return			�C���v�b�g�C���^�[�t�F�C�X
*//**************************************************************************/
FORCE_INLINE  LPInput CInputUtilities::GetInput(void){
	return m_pInput;
}
/*************************************************************************//*!
		@brief			�}�E�X���W����float�^�̃f�[�^�Ƃ��Ď擾����
		@param[out]		px			�}�E�X�w���W
		@param[out]		py			�}�E�X�x���W
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::GetMousePos(MofFloat& px,MofFloat& py){
	return m_pInput->GetMousePos(px,py);
}
/*************************************************************************//*!
		@brief			�}�E�X���W��Vector2�^�̃f�[�^�Ƃ��Ď擾����
		@param[out]		v			Vector2
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�擾�G���[
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::GetMousePos(Vector2& v){
	return m_pInput->GetMousePos(v);
}
/*************************************************************************//*!
		@brief			�}�E�X�̃z�C�[���ړ����擾����
		@param			None
				
		@return			�z�C�[���ړ���
*//**************************************************************************/
FORCE_INLINE MofFloat CInputUtilities::GetMouseWheelMove(void){
	return m_pInput->GetMouseWheelMove();
}
/*************************************************************************//*!
		@brief			�}�E�X�ړ�����float�^�̃f�[�^�Ƃ��Ď擾����
		@param[out]		px			�}�E�X�w�ړ���
		@param[out]		py			�}�E�X�x�ړ���
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::GetMouseMove(MofFloat& px,MofFloat& py){
	return m_pInput->GetMouseMove(px,py);
}
/*************************************************************************//*!
		@brief			�}�E�X�ړ���Vector3�^�̃f�[�^�Ƃ��Ď擾����<br>
						x,y�ɂ̓J�[�\���̈ړ��ʂ�z�ɂ̓z�C�[���̈ړ��ʂ�����
		@param[out]		v			Vector3
				
		@return			TRUE		����Ɏ擾���邱�Ƃ��ł���
						FALSE		�ǂݍ��݃G���[
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::GetMouseMove(Vector3& v){
	return m_pInput->GetMouseMove(v);
}

//[EOF]