/*************************************************************************//*!
					
					@file	WinSingleGameApplication.h
					@brief	Windows��ł̃Q�[���A�v���P�[�V�����̓�������C�u�������p�҂��쐬���邽�߂̊��N���X�B<br>
							�Q�[����Run����Windows�p�̃��b�Z�[�W�����ƃV���O���X���b�h�ōX�V�ƕ`�悪���s�����B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINSINGLEGAMEAPPLICATION__H__

#define		__WINSINGLEGAMEAPPLICATION__H__

//INCLUDE
#include	"Application.h"

namespace Mof {

	/*******************************//*!
	@brief	Windows��ł̃Q�[���A�v���P�[�V�����̓�������C�u�������p�҂��쐬���邽�߂̊��N���X

			Windows��ł̃Q�[���A�v���P�[�V�����̓�������C�u�������p�҂��쐬���邽�߂̊��N���X�B<br>
			�Q�[����Run����Windows�p�̃��b�Z�[�W�����ƃV���O���X���b�h�ōX�V�ƕ`�悪���s�����B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CWinSingleGameApplication : public IApplication {
	private:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CWinSingleGameApplication();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CWinSingleGameApplication();
		/*************************************************************************//*!
				@brief			�A�v���P�[�V�����̏�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Initialize(void);
		/*************************************************************************//*!
				@brief			�A�v���P�[�V�����̎��s
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Run(void);
		/*************************************************************************//*!
				@brief			�A�v���P�[�V�����̍X�V
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Update(void);
		/*************************************************************************//*!
				@brief			�A�v���P�[�V�����̕`��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(void);
		/*************************************************************************//*!
				@brief			�A�v���P�[�V�����̉��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Release(void);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CWinSingleGameApplication,MOF_WINSINGLEGAMEAPPLICATIONCLASS_ID);
	};

	#include	"WinSingleGameApplication.inl"
	
	//�u������
	typedef CWinSingleGameApplication		CSingleGameApplication;
}

#endif

//[EOF]