/*************************************************************************//*!
					
					@file	WinMultiGameApplication.h
					@brief	Windows��ł̃Q�[���A�v���P�[�V�����̓�������C�u�������p�҂��쐬���邽�߂̊��N���X�B<br>
							�Q�[����Run����Windows�p�̃��b�Z�[�W�����ƃ}���`�X���b�h�ōX�V�ƕ`�悪���s�����B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINMULTIGAMEAPPLICATION__H__

#define		__WINMULTIGAMEAPPLICATION__H__

//INCLUDE
#include	"Application.h"
#include	"../Graphics/RenderCommandProxy.h"

namespace Mof {

	/*******************************//*!
	@brief	Windows��ł̃Q�[���A�v���P�[�V�����̓�������C�u�������p�҂��쐬���邽�߂̊��N���X

			Windows��ł̃Q�[���A�v���P�[�V�����̓�������C�u�������p�҂��쐬���邽�߂̊��N���X�B<br>
			�Q�[����Run����Windows�p�̃��b�Z�[�W�����ƃ}���`�X���b�h�ōX�V�ƕ`�悪���s�����B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CWinMultiGameApplication : public IApplication {
	protected:
		/*******************//*!
		�`��R�}���h�v���L�V
		*//********************/
		CRenderCommandProxy					m_CommandProxy;
		/*******************//*!
		�`��X���b�h
		*//********************/
		CRenderThread						m_RenderThread;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CWinMultiGameApplication();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CWinMultiGameApplication();
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
		MOF_LIBRARYCLASS_NOTCOPY(CWinMultiGameApplication,MOF_WINMULTIGAMEAPPLICATIONCLASS_ID);
	};

	#include	"WinMultiGameApplication.inl"
	
	//�u������
	typedef CWinMultiGameApplication		CMultiGameApplication;
}

#endif

//[EOF]