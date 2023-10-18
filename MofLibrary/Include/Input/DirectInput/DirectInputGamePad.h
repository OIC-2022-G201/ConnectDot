/*************************************************************************//*!
					
					@file	DirectInputGamePad.h
					@brief	DirectInput�ł̃Q�[���p�b�h�ł̊e����͂̏������s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DIRECTINPUTGAMEPAD__H__

#define		__DIRECTINPUTGAMEPAD__H__

//INCLUDE
#include	"../GamePad.h"
				
namespace Mof {
	
	/*******************************//*!
	@brief	�Q�[���p�b�h�������\����

			�Q�[���p�b�h�̐����ɕK�v�ȏ����܂Ƃ߂��\����

	@author	CDW
	*//********************************/
	typedef struct tag_DXGAMEPADCREATEINFO : public tag_GAMEPADCREATEINFO {
		LPWindow				pWindow;					//!<�E�C���h�E
		MofInputDevice			pInput;						//!<����
		LPDIDEVICEINSTANCE		pInstance;					//!<�f�o�C�X�C���X�^���X

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_DXGAMEPADCREATEINFO() :
		pWindow(NULL) ,
		pInput(NULL) ,
		pInstance(NULL) ,
		tag_GAMEPADCREATEINFO() {
			Size = sizeof(tag_DXGAMEPADCREATEINFO);
		}
	}DXGAMEPADCREATEINFO,*LPDXGAMEPADCREATEINFO;
	
	/*******************************//*!
	@brief	DirectInput�Q�[���p�b�h�N���X

			DirectInput�Q�[���p�b�h�̊Ǘ��A���͏������s���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDXGamePad : public IGamePad {
	protected:
		/*******************//*!
		�Q�[���p�b�h
		*//********************/
		LPDIRECTINPUTDEVICE8	m_pGanePad;
		/*******************//*!
		���͏��
		*//********************/
		DIJOYSTATE2				m_PadState;
		/*******************//*!
		���O�̓��͏��
		*//********************/
		DIJOYSTATE2				m_PrevPadState;
		/*******************//*!
		�Q�[���p�b�h���
		*//********************/
		DIDEVICEINSTANCE		m_PadInfo;

		/*************************************************************************//*!
				@brief			�����Q�[���p�b�h����`
				@param[in]		DIDOInst		�f�o�C�X�C���X�^���X���
				@param[in]		ref				LPDIRECTINPUTDEVICE�ւ̎Q��
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool CALLBACK EnumAxesCallback(LPCDIDEVICEOBJECTINSTANCE DIDOInst,LPMofVoid ref);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDXGamePad();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDXGamePad();
		
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
		

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CDXGamePad,MOF_DXINPUTGAMEPADCLASS_ID);
	};

	#include	"DirectInputGamePad.inl"
}

#endif

//[EOF]