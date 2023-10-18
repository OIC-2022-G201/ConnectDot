/*************************************************************************//*!
					
					@file	DefWindowProc.h
					@brief	�E�C���h�E�Y�ŕW���I�ȃE�C���h�E�̃��b�Z�[�W�������s���B<br>
							��{�v���V�[�W���N���X

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DEFWINDOWPROC__H__

#define		__DEFWINDOWPROC__H__

//INCLUDE
#include	"WindowBase.h"

namespace Mof {
	/*******************************//*!
	@brief	�E�C���h�E�v���V�[�W����{���b�Z�[�W�����N���X

			�E�C���h�E�̃��b�Z�[�W�������s����{���b�Z�[�W�����N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDefWindowProc : public IWindowProc {
	protected:
		/*******************//*!
		�E�C���h�E�C���^�[�t�F�C�X
		*//********************/
		LPWindow			m_pWindow;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDefWindowProc();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pWnd		�E�C���h�E

				@return			None
		*//**************************************************************************/
		CDefWindowProc(LPWindow pWnd);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDefWindowProc();
		/*************************************************************************//*!
				@brief			�R�[�������v���V�[�W��
				@param[in]		hWnd		�E�C���h�E�n���h��
				@param[in]		msg			���b�Z�[�W
				@param[in]		wpar		�p�����[�^�[�P
				@param[in]		lpar		�p�����[�^�[�Q
				
				@return			�����Ń��b�Z�[�W�������s�����ꍇ���̌��ʂ��A<br>
								����ȊO��DefWindowProc�֐����Q�ƁB
		*//**************************************************************************/
		virtual MofProcResult WindowProc(MofWindowHandle hWnd,MofUInt msg,MofProcParamW wpar,MofProcParamL lpar);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CDefWindowProc,MOF_DEFWINDOWPROCCLASS_ID);
	};

}

#endif

//[EOF]