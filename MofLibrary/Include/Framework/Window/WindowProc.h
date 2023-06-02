/*************************************************************************//*!
					
					@file	WindowProc.h
					@brief	�E�C���h�E�̃��b�Z�[�W�������s�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINDOWPROC__H__

#define		__WINDOWPROC__H__

//INCLUDE
#include	"../../Math/MathCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�E�C���h�E�v���V�[�W�����C���^�[�t�F�C�X

			�E�C���h�E�̃��b�Z�[�W�������s�����C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IWindowProc : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R�[�������v���V�[�W��
				@param[in]		hWnd		�E�C���h�E�n���h��
				@param[in]		msg			���b�Z�[�W
				@param[in]		wpar		�p�����[�^�[�P
				@param[in]		lpar		�p�����[�^�[�Q
				
				@return			�����Ń��b�Z�[�W�������s�����ꍇ���̌��ʂ��A<br>
								����ȊO��DefWindowProc�֐����Q�ƁB
		*//**************************************************************************/
		virtual MofProcResult WindowProc(MofWindowHandle hWnd,MofUInt msg,MofProcParamW wpar,MofProcParamL lpar) = 0;
	};

}

#endif

//[EOF]