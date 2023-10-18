/*************************************************************************//*!
					
					@file	AndroidJNIGameFramework.h
					@brief	AndroidJNI�ł̃Q�[���t���[�����[�N��񋟂���N���X�B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ANDROIDJNIGAMEFRAMEWORK__H__

#define		__ANDROIDJNIGAMEFRAMEWORK__H__

//INCLUDE
#include	"../GameFrameworkBase.h"
#include	"../../Graphics/OpenGL/GLGraphics.h"
#include	"../../Sound/OpenSL/SLSound.h"
#include	"../../Input/Android/AndroidInput.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�Q�[���t���[�����[�N�������\����

			�Q�[���t���[�����[�N�̐����ɕK�v�ȏ����܂Ƃ߂��\����<br>
			�쐬����t���[�����[�N�̎�ނɂ���Ă��̍\���̂��p�������\���̂��쐬����B

	@author	�_�c�@��
	*//********************************/
	typedef struct tag_ANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO : public GAMEFRAMEWORKINITIALIZEINFO {
		WINDOWCREATEINFO		WindowCreateInfo;	//!<���C���E�C���h�E�������
		GRAPHICSCREATEINFO		GraphicsCreateInfo;	//!<�O���t�B�b�N�X�������
		INPUTCREATEINFO			InputCreateInfo;	//!<�C���v�b�g�������
		SOUNDCREATEINFO			SoundCreateInfo;	//!<�T�E���h�������

		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_ANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO() :
		GAMEFRAMEWORKINITIALIZEINFO() ,
		WindowCreateInfo() ,
		GraphicsCreateInfo() ,
		InputCreateInfo() ,
		SoundCreateInfo() {
			Size = sizeof(tag_ANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO);
			Flag = MOF_FRAMEWORK_SOUNDINITIALIZE | MOF_FRAMEWORK_INPUTINITIALIZE;
		}
	}ANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO,*LPANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO;
	
	/*******************************//*!
	@brief	AndroidJNI�ł̃Q�[���t���[�����[�N�N���X

			AndroidJNI�ł̃Q�[���t���[�����[�N�N���X�B

	@author	�_�c�@��
	*//********************************/
	class MOFLIBRARY_API CAndroidJNIGameFramework : public CGameFrameworkBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CAndroidJNIGameFramework();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAndroidJNIGameFramework();
		/*************************************************************************//*!
				@brief			�t���[�����[�N�̏�����
				@param[in]		pInfo		�t���[�����[�N�̏��������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Initialize(LPFRAMEWORKINITIALIZEINFO pInfo);
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
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CAndroidJNIGameFramework,MOF_ANDROIDJNIGAMEFRAMEWORKCLASS_ID);
	};
	
	#include	"AndroidJNIGameFramework.inl"
}

#endif

//[EOF]
