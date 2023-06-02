/*************************************************************************//*!
					
					@file	XInputGamePad.h
					@brief	XInput�ł̃Q�[���p�b�h�ł̊e����͂̏������s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__XINPUTGAMEPAD__H__

#define		__XINPUTGAMEPAD__H__

//INCLUDE
#include	"../GamePad.h"
	
//DEFINE
			
//----------------------------------
////�g���K�[�̒l��`
//----------------------------------
#define		MOFXINPUT_TRIGGERMIN					0				//!<������Ԃ��ŏ��ʒu
#define		MOFXINPUT_TRIGGERCENTER					128				//!<������Ԃ����S�ʒu
#define		MOFXINPUT_TRIGGERMAX					255				//!<������Ԃ��ő�ʒu

//----------------------------------
////�X�e�B�b�N�̒l��`
//----------------------------------
#define		MOFXINPUT_STICKMIN						-32768			//!<�}�C�i�X�ő�
#define		MOFXINPUT_STICKMINCENTER				-16384			//!<�}�C�i�X���S
#define		MOFXINPUT_STICKCENTER					0				//!<�|����Ă��Ȃ�
#define		MOFXINPUT_STICKCENTERPERMIT				6000			//!<�덷
#define		MOFXINPUT_STICKMAXCENTER				16383			//!<�v���X���S
#define		MOFXINPUT_STICKMAX						32767			//!<�v���X�ő�

namespace Mof {
	
	/*******************************//*!
	@brief	XInput�{�^����

			XInput�̃{�^�����͔�����s�����̂��

	@author	CDW
	*//********************************/
	typedef enum XInputButton {
		XINPUT_DP_UP,												//!<�����p�b�h��
		XINPUT_DP_DOWN,												//!<�����p�b�h��
		XINPUT_DP_LEFT,												//!<�����p�b�h��
		XINPUT_DP_RIGHT,											//!<�����p�b�h�E
	
		XINPUT_LS_PUSH,												//!<���X�e�B�b�N����
		XINPUT_RS_PUSH,												//!<�E�X�e�B�b�N����
	
		XINPUT_A,													//!<A�{�^��
		XINPUT_B,													//!<B�{�^��
		XINPUT_X,													//!<X�{�^��
		XINPUT_Y,													//!<Y�{�^��

		XINPUT_L_BTN,												//!<L�{�^��
		XINPUT_R_BTN,												//!<R�{�^��

		XINPUT_L_TRIGGER,											//!<L�g���K�[
		XINPUT_R_TRIGGER,											//!<R�g���K�[

		XINPUT_START,												//!<START�{�^��
		XINPUT_BACK,												//!<BACK�{�^��

		XINPUT_MAX													//!<�ő吔
	}XInputButton;

	/*******************************//*!
	@brief	�Q�[���p�b�h�������\����

			�Q�[���p�b�h�̐����ɕK�v�ȏ����܂Ƃ߂��\����

	@author	CDW
	*//********************************/
	typedef struct tag_XGAMEPADCREATEINFO : public tag_GAMEPADCREATEINFO {
		MofU32					No;									//!<�R���g���[���[�ԍ�

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_XGAMEPADCREATEINFO() :
		No(0) ,
		tag_GAMEPADCREATEINFO() {
			Size = sizeof(tag_XGAMEPADCREATEINFO);
		}
	}XGAMEPADCREATEINFO,*LPXGAMEPADCREATEINFO;
	
	/*******************************//*!
	@brief	XInput�Q�[���p�b�h�N���X

			XInput�Q�[���p�b�h�̊Ǘ��A���͏������s���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CXGamePad : public IGamePad {
	protected:
		/*******************//*!
		�Q�[���p�b�h
		*//********************/
		MofU32					m_ControllerNo;
		/*******************//*!
		���͏��
		*//********************/
		XINPUT_STATE			m_PadState;
		/*******************//*!
		���O�̓��͏��
		*//********************/
		XINPUT_STATE			m_PrevPadState;
		/*******************//*!
		�p�b�h�U�����
		*//********************/
		XINPUT_VIBRATION		m_Vibration;
		/*******************//*!
		�L�[���
		*//********************/
		MofBool					m_bButtonState[XINPUT_MAX];
		/*******************//*!
		���O�̃L�[���
		*//********************/
		MofBool					m_bPrevButtonState[XINPUT_MAX];
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CXGamePad();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CXGamePad();
		
		/*************************************************************************//*!
				@brief			�Q�[���p�b�h�I�u�W�F�N�g�̐���
				@param[in]		pInfo		�Q�[���p�b�h�̐������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPGAMEPADCREATEINFO pInfo);

		/*************************************************************************//*!
				@brief			���̓L�[�X�V
				@param			None

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool RefreshKey(void);
		
		/*************************************************************************//*!
				@brief			�U���̊J�n
				@param[in]		LeftSpeed		���U��
				@param[in]		RightSpeed		�E�U��

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool StartVibration(MofU16 LeftSpeed,MofU16 RightSpeed);
		/*************************************************************************//*!
				@brief			�U���̒�~
				@param			None

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool StopVibration(void);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
				
		/*************************************************************************//*!
				@brief			�Q�[���p�b�h�L�[���͏�Ԕ���<br>
								�L�[�ԍ��̃L�[��Push(���̃t���[���œ��͂��ꂽ)������s��
				@param[in]		n				�L�[�ԍ�

				@return			TRUE			���͂���<br>
								FALSE			���͂Ȃ�
		*//**************************************************************************/
		virtual MofBool IsKeyPush(const MofU8 n) const;
		/*************************************************************************//*!
				@brief			�Q�[���p�b�h�L�[���͏�Ԕ���<br>
								�L�[�ԍ��̃L�[��Hold(���̃t���[���œ��͂���Ă���)������s��
				@param[in]		n				�L�[�ԍ�

				@return			TRUE			���͂���<br>
								FALSE			���͂Ȃ�
		*//**************************************************************************/
		virtual MofBool IsKeyHold(const MofU8 n) const;
		/*************************************************************************//*!
				@brief			�Q�[���p�b�h�L�[���͏�Ԕ���<br>
								�L�[�ԍ��̃L�[��Pull(���̃t���[���ŕ����ꂽ)������s��
				@param[in]		n				�L�[�ԍ�

				@return			TRUE			���͂���<br>
								FALSE			���͂Ȃ�
		*//**************************************************************************/
		virtual MofBool IsKeyPull(const MofU8 n) const;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�p�b�h�擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�p�b�h���
		*//**************************************************************************/
		virtual MofGamePad GetPad(void);
		/*************************************************************************//*!
				@brief			�p�b�h��Ԏ擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�p�b�h���
		*//**************************************************************************/
		virtual MofGamePadState* GetPadState(void);
		/*************************************************************************//*!
				@brief			�p�b�h��Ԏ擾<br>
								�X�e�B�b�N�̉��ւ̌X�����擾����B
				@param			None

				@return			�X�e�B�b�N�����͗�(-1.0�`1.0)
		*//**************************************************************************/
		virtual MofFloat GetStickHorizontal(void) const;
		/*************************************************************************//*!
				@brief			�p�b�h��Ԏ擾<br>
								�X�e�B�b�N�̏c�ւ̌X�����擾����B
				@param			None

				@return			�X�e�B�b�N�c���͗�(-1.0�`1.0)
		*//**************************************************************************/
		virtual MofFloat GetStickVertical(void) const;
		/*************************************************************************//*!
				@brief			�p�b�h��Ԏ擾<br>
								�E�X�e�B�b�N�̉��ւ̌X�����擾����B
				@param			None

				@return			�X�e�B�b�N�����͗�(-1.0�`1.0)
		*//**************************************************************************/
		virtual MofFloat GetRightStickHorizontal(void) const;
		/*************************************************************************//*!
				@brief			�p�b�h��Ԏ擾<br>
								�E�X�e�B�b�N�̏c�ւ̌X�����擾����B
				@param			None

				@return			�X�e�B�b�N�c���͗�(-1.0�`1.0)
		*//**************************************************************************/
		virtual MofFloat GetRightStickVertical(void) const;
		

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CXGamePad,MOF_XINPUTGAMEPADCLASS_ID);
	};

	#include	"XInputGamePad.inl"
}

#endif

//[EOF]