/*************************************************************************//*!
					
					@file	Window.h
					@brief	�E�C���h�E�̏������s�����C���^�[�t�F�C�X�B<br>
							�E�C���h�E��_�C�A���O�͂��ׂĂ��̃C���^�[�t�F�C�X���p������B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINDOW__H__

#define		__WINDOW__H__

//INCLUDE
#include	"../../Common/ReadFile.h"
#include	"../../Common/WriteFile.h"
#include	"../../Common/DynamicArray.h"

#ifdef		MOFLIB_WINDOWS_DESKTOP
#include	"WindowProc.h"
#endif

//DEFINE

//!�E�C���h�E�ʒu�̕W��
#define		MOFWINDOWPOS_DEFAULT				MOF_S32_MIN

//!�W���X�^�C��
#define		MOFWINDOWSTYLE_DEFAULT				MOF_U32_MAX

namespace Mof {

#ifdef		MOFLIB_WINDOWS_DESKTOP
	/*******************************//*!
	@brief	�E�C���h�E�������\����

			�E�C���h�E�̐����ɕK�v�ȏ����܂Ƃ߂��\����

	@author	CDW
	*//********************************/
	typedef struct tag_WINDOWCREATEINFO {
		MofInstanceHandle		hInst;			//!<�C���X�^���X�n���h��
		CString					Title;			//!<�E�C���h�E�̃^�C�g��
		MofS32					px;				//!<�E�C���h�E��X���W
		MofS32					py;				//!<�E�C���h�E��Y���W
		MofS32					Width;			//!<�E�C���h�E�̕�
		MofS32					Height;			//!<�E�C���h�E�̍���
		MofU32					WCStyle;		//!<�X�^�C���iWNDCLASSEX��style�����o�j
		MofU32					Style;			//!<�X�^�C��
		MofIconHandle			hIcon;			//!<�A�C�R���n���h��
		MofCursorHandle			hCursor;		//!<�J�[�\���n���h��
		MofWindowHandle			hParent;		//!<�e�E�C���h�E�n���h��
		IWindowProc*			pProc;			//!<�v���V�[�W���[
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�E�C���h�E�̃^�C�g���A���W�A�T�C�Y�A�X�^�C���W���l�ɂȂ�B<br>
								�E�C���h�E�Y�̏ꍇ<br>
								�^�C�g���FMofWindow<br>
								���W�F��ʒ���<br>
								�T�C�Y�F1024�~768<br>
								�A�C�R���FIDI_APPLICATION<br>
								�J�[�\���FIDC_ARROW<br>
								WNDCLASSEX�X�^�C���FCS_HREDRAW | CS_VREDRAW<br>
								�X�^�C���FWS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
				@param			None

				@return			None
		*//**************************************************************************/
		tag_WINDOWCREATEINFO() :
		hInst(NULL),
		Title(MOFSTR("MofWindow")),
		px(MOFWINDOWPOS_DEFAULT),
		py(MOFWINDOWPOS_DEFAULT),
		Width(1024),
		Height(768),
		WCStyle(MOFWINDOWSTYLE_DEFAULT) ,
		Style(MOFWINDOWSTYLE_DEFAULT),
		hIcon(NULL),
		hCursor(NULL),
		hParent(NULL),
		pProc(NULL)
		{
		}
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pTitle		�E�C���h�E�̃^�C�g��
				@param[in]		x			�E�C���h�E��X���W
				@param[in]		y			�E�C���h�E��Y���W
				@param[in]		w			�E�C���h�E�̕�
				@param[in]		h			�E�C���h�E�̍���
				@param[in]		stl			�E�C���h�E�̃X�^�C��
				
				@return			None
		*//**************************************************************************/
		tag_WINDOWCREATEINFO(LPCMofChar pTitle,MofS32 x,MofS32 y,MofS32 w,MofS32 h,MofU32 stl) :
		hInst(NULL),
		Title(pTitle),
		px(x),
		py(y),
		Width(w),
		Height(h),
		Style(stl),
		hIcon(NULL),
		hCursor(NULL),
		hParent(NULL),
		pProc(NULL)
		{
		}
	}WINDOWCREATEINFO,*LPWINDOWCREATEINFO;
#else
	
	/*******************************//*!
	@brief	�E�C���h�E�������\����

			�E�C���h�E�̐����ɕK�v�ȏ����܂Ƃ߂��\����

	@author	CDW
	*//********************************/
	typedef struct tag_WINDOWCREATEINFO {
		MofS32					Width;			//!<�E�C���h�E�̕�
		MofS32					Height;			//!<�E�C���h�E�̍���
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�E�C���h�E�̃^�C�g���A���W�A�T�C�Y�A�X�^�C���W���l�ɂȂ�B<br>
								�E�C���h�E�Y�̏ꍇ<br>
								�^�C�g���FMofWindow<br>
								���W�F��ʒ���<br>
								�T�C�Y�F1024�~768<br>
								�A�C�R���FIDI_APPLICATION<br>
								�J�[�\���FIDC_ARROW<br>
								WNDCLASSEX�X�^�C���FCS_HREDRAW | CS_VREDRAW<br>
								�X�^�C���FWS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
				@param			None

				@return			None
		*//**************************************************************************/
		tag_WINDOWCREATEINFO() :
		Width(1024),
		Height(768)
		{
		}
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pTitle		�E�C���h�E�̃^�C�g��
				@param[in]		x			�E�C���h�E��X���W
				@param[in]		y			�E�C���h�E��Y���W
				@param[in]		w			�E�C���h�E�̕�
				@param[in]		h			�E�C���h�E�̍���
				@param[in]		stl			�E�C���h�E�̃X�^�C��
				
				@return			None
		*//**************************************************************************/
		tag_WINDOWCREATEINFO(LPCMofChar pTitle,MofS32 x,MofS32 y,MofS32 w,MofS32 h,MofU32 stl) :
		Width(w),
		Height(h)
		{
		}
	}WINDOWCREATEINFO,*LPWINDOWCREATEINFO;
#endif

	/*******************************//*!
	@brief	�E�C���h�E���C���^�[�t�F�C�X

			�E�C���h�E�̑S�Ă̊��ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IWindow : public IMofNamedObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�E�C���h�E�̐���
				@param[in]		pInfo		�E�C���h�E�̐������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPWINDOWCREATEINFO pInfo) = 0;
		/*************************************************************************//*!
				@brief			�E�C���h�E�̐���<br>
								������WINDOWCREATEINFO�𐶐����āA�E�C���h�E���쐬����B<br>
								�����ɑ��݂��Ȃ��p�����[�^�[�͊��̊�{�l���K�p�����B
				@param[in]		pTitle		�E�C���h�E�̃^�C�g��
				@param[in]		w			�E�C���h�E�̕�
				@param[in]		h			�E�C���h�E�̍���
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPCMofChar pTitle,MofS32 w,MofS32 h) = 0;
	
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			��ʃT�C�Y��ݒ肷��
				@param[in]		sw				��
				@param[in]		sh				����
				@param[in]		bSet			�E�C���h�E�̃T�C�Y�����ۂɕύX���邩�ۂ�<br>
												TRUE�̏ꍇWindow�T�C�Y��ύX����API�����s����B<br>
												FALSE�̏ꍇ�����o��Width,Height�̕ύX�݂̂�API�ɂ��T�C�Y�̕ύX�͍s��Ȃ��B
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetScreenSize(MofS32 sw,MofS32 sh, MofBool bSet = TRUE) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�C���X�^���X�n���h���擾
				@param			None

				@return			�C���X�^���X�n���h��
		*//**************************************************************************/
		virtual MofInstanceHandle GetInstanceHandle(void) = 0;
		/*************************************************************************//*!
				@brief			�E�C���h�E�n���h���擾
				@param			None

				@return			�E�C���h�E�n���h��
		*//**************************************************************************/
		virtual MofWindowHandle GetWindowHandle(void) = 0;
		/*************************************************************************//*!
				@brief			�E�C���h�E�^�C�g���擾
				@param			None

				@return			�E�C���h�E�^�C�g��
		*//**************************************************************************/
		virtual LPString GetTitle(void) = 0;
		/*************************************************************************//*!
				@brief			�E�C���h�E���擾
				@param			None

				@return			�E�C���h�E��
		*//**************************************************************************/
		virtual MofS32 GetWidth(void) const = 0;
		/*************************************************************************//*!
				@brief			�E�C���h�E�����擾
				@param			None

				@return			�E�C���h�E����
		*//**************************************************************************/
		virtual MofS32 GetHeight(void) const = 0;
	};

	//�|�C���^�u������
	typedef IWindow*			LPWindow;
}

#endif

//[EOF]