/*************************************************************************//*!
					
					@file	AndroidSingleGameApplication.h
					@brief	Android��ł̃Q�[���A�v���P�[�V�����̓�������C�u�������p�҂��쐬���邽�߂̊��N���X�B<br>
							�Q�[����Run����Android�p�̃��b�Z�[�W�����ƃV���O���X���b�h�ōX�V�ƕ`�悪���s�����B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ANDROIDSINGLEGAMEAPPLICATION__H__

#define		__ANDROIDSINGLEGAMEAPPLICATION__H__

//INCLUDE
#include	"Application.h"

namespace Mof {

	/*******************************//*!
	@brief	Android��ł̃Q�[���A�v���P�[�V�����̓�������C�u�������p�҂��쐬���邽�߂̊��N���X

			Android��ł̃Q�[���A�v���P�[�V�����̓�������C�u�������p�҂��쐬���邽�߂̊��N���X�B<br>
			�Q�[����Run����Android�p�̃��b�Z�[�W�����ƃV���O���X���b�h�ōX�V�ƕ`�悪���s�����B

	@author	�_�c�@��
	*//********************************/
	class MOFLIBRARY_API CAndroidSingleGameApplication : public IApplication {
	private:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CAndroidSingleGameApplication();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAndroidSingleGameApplication();
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
		MOF_LIBRARYCLASS_NOTCOPY(CAndroidSingleGameApplication,MOF_ANDROIDSINGLEGAMEAPPLICATIONCLASS_ID);
	};
	
	#include	"AndroidSingleGameApplication.inl"
	
	//�u������
	typedef CAndroidSingleGameApplication		CSingleGameApplication;
}

#endif

//[EOF]