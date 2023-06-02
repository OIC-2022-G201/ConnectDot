/*************************************************************************//*!
					
					@file	Framework.h
					@brief	�A�v���P�[�V�����t���[�����[�N�̊�ꏈ����񋟂���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__FRAMEWORK__H__

#define		__FRAMEWORK__H__

//INCLUDE
#include	"Window/Window.h"
#include	"../Common/Application.h"

namespace Mof {

	/*******************************//*!
	@brief	�t���[�����[�N�������\����

			�t���[�����[�N�̐����ɕK�v�ȏ����܂Ƃ߂��\����<br>
			�쐬����t���[�����[�N�̎�ނɂ���Ă��̍\���̂��p�������\���̂��쐬����B

	@author	CDW
	*//********************************/
	typedef struct tag_FRAMEWORKINITIALIZEINFO {
		MofU32					Size;			//!<�\���̃T�C�Y
		MofU32					Flag;			//!<�t���[�����[�N�������t���O
		LPApplication			pApplication;	//!<�A�v���P�[�V��������C���^�[�t�F�C�X

		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_FRAMEWORKINITIALIZEINFO() : 
		Size(sizeof(tag_FRAMEWORKINITIALIZEINFO)) ,
		Flag(0) ,
		pApplication() {
		}
	}FRAMEWORKINITIALIZEINFO,*LPFRAMEWORKINITIALIZEINFO;

	/*******************************//*!
	@brief	�A�v���P�[�V�����t���[�����[�N���C���^�[�t�F�C�X

			�A�v���P�[�V�����t���[�����[�N�̑S�Ă̊��ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IFramework : public IMofObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�t���[�����[�N�̏�����
				@param[in]		pInfo		�t���[�����[�N�̏��������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Initialize(LPFRAMEWORKINITIALIZEINFO pInfo) = 0;
		/*************************************************************************//*!
				@brief			�A�v���P�[�V�����̎��s
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Run(void) = 0;
		/*************************************************************************//*!
				@brief			�t���[�����[�N�n���h���擾
				@param			None
				
				@return			�n���h��
		*//**************************************************************************/
		virtual MofInstanceHandle GetHandle(void) = 0;
		/*************************************************************************//*!
				@brief			�t���[�����[�N�E�C���h�E�擾
				@param			None
				
				@return			�E�C���h�E
		*//**************************************************************************/
		virtual LPWindow GetWindow(void) = 0;
	};
	
	//�|�C���^�u������
	typedef IFramework*			LPFramework;

}

#endif

//[EOF]