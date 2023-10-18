/*************************************************************************//*!
					
					@file	WindowsGameFramework.h
					@brief	Windows�ł̃Q�[���t���[�����[�N��񋟂���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINDOWSGAMEFRAMEWORK__H__

#define		__WINDOWSGAMEFRAMEWORK__H__

//INCLUDE
#include	"../Window/Windows/WinWindow.h"
#include	"../GameFrameworkBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	Windows�ł̃Q�[���t���[�����[�N�N���X

			Windows�ł̃Q�[���t���[�����[�N�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CWindowsGameFramework : public CGameFrameworkBase {
	protected:
		/*******************//*!
		�C���X�^���X�n���h��
		*//********************/
		MofInstanceHandle	m_Handle;
		/*******************//*!
		�������I���t���O
		*//********************/
		MofBool				m_bInitialize;
		/*******************//*!
		���C���E�C���h�E
		*//********************/
		LPWindow			m_pWindow;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CWindowsGameFramework();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CWindowsGameFramework();
		/*************************************************************************//*!
				@brief			�A�v���P�[�V�����̎��s
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Run(void);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		/*************************************************************************//*!
				@brief			�t���[�����[�N�n���h���擾
				@param			None
				
				@return			�n���h��
		*//**************************************************************************/
		virtual MofInstanceHandle GetHandle(void);
		/*************************************************************************//*!
				@brief			�t���[�����[�N�E�C���h�E�擾
				@param			None
				
				@return			�E�C���h�E
		*//**************************************************************************/
		virtual LPWindow GetWindow(void);
	};

	#include	"WindowsGameFramework.inl"
}

#endif

//[EOF]