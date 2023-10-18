/*************************************************************************//*!
					
					@file	WinWindow.h
					@brief	�E�C���h�E�Y�p�̃E�C���h�E�̏������s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINWINDOW__H__

#define		__WINWINDOW__H__

//INCLUDE
#include	"DefWindowProc.h"
#include	"ImeProc.h"

namespace Mof {
	/*******************************//*!
	@brief	�E�C���h�E�Y�p�E�C���h�E�N���X

			�E�C���h�E�Y�p�̕W���I�ȃE�C���h�E�̏������s���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CWindow : public CWindowBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CWindow();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CWindow();
		/*************************************************************************//*!
				@brief			�E�C���h�E�̐���
				@param[in]		pInfo		�E�C���h�E�̐������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPWINDOWCREATEINFO pInfo);
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
		virtual MofBool Create(LPCMofChar pTitle,MofS32 w,MofS32 h);
		
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
		virtual MofBool SetScreenSize(MofS32 sw,MofS32 sh, MofBool bSet = TRUE);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CWindow,MOF_WINDOWCLASS_ID);
	};

}

#endif

//[EOF]