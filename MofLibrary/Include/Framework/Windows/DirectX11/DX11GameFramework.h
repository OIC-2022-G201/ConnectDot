/*************************************************************************//*!
					
					@file	DX11GameFramework.h
					@brief	DX11�ł̃Q�[���t���[�����[�N��񋟂���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11GAMEFRAMEWORK__H__

#define		__DX11GAMEFRAMEWORK__H__

//INCLUDE
#include	"../WindowsGameFramework.h"
#include	"../../../Graphics/DirectX11/DX11Graphics.h"
#include	"../../../Input/DirectInput/DirectInput.h"
#include	"../../../Sound/XAudio/XAudioSound.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�Q�[���t���[�����[�N�������\����

			�Q�[���t���[�����[�N�̐����ɕK�v�ȏ����܂Ƃ߂��\����<br>
			�쐬����t���[�����[�N�̎�ނɂ���Ă��̍\���̂��p�������\���̂��쐬����B

	@author	CDW
	*//********************************/
	typedef struct tag_WINDOWSGAMEFRAMEWORKINITIALIZEINFO : public GAMEFRAMEWORKINITIALIZEINFO {
		WINDOWCREATEINFO			WindowCreateInfo;	//!<���C���E�C���h�E�������
		DIRECTGRAPHICSCREATEINFO	GraphicsCreateInfo;	//!<�O���t�B�b�N�X�������
		DIRECTINPUTCREATEINFO		InputCreateInfo;	//!<�C���v�b�g�������
		SOUNDCREATEINFO				SoundCreateInfo;	//!<�T�E���h�������

		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_WINDOWSGAMEFRAMEWORKINITIALIZEINFO() :
		WindowCreateInfo() ,
		GraphicsCreateInfo() ,
		InputCreateInfo() ,
		SoundCreateInfo() ,
		GAMEFRAMEWORKINITIALIZEINFO() {
			Size = sizeof(tag_WINDOWSGAMEFRAMEWORKINITIALIZEINFO);
		}
	}WINDOWSGAMEFRAMEWORKINITIALIZEINFO,*LPWINDOWSGAMEFRAMEWORKINITIALIZEINFO;
	
	/*******************************//*!
	@brief	DX11�ł̃Q�[���t���[�����[�N�N���X

			DX11�ł̃Q�[���t���[�����[�N�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11GameFramework : public CWindowsGameFramework {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11GameFramework();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11GameFramework();
		/*************************************************************************//*!
				@brief			�t���[�����[�N�̏�����<br>
								���L�̏����Ńt���[�����[�N�̏����������s���܂��B<br>
								�E�E�C���h�E�̐���<br>
								�EDirectX11Graphics�̏�����<br>
								�EDirectInput�̏�����<br>
								�EXAudio2�̏�����<br>
								�E�A�v���P�[�V�����̏�����<br>
								�����ŗ��p���Ȃ��@�\�����݂���ꍇ�A������pInfo->Flag�����o�ɂď������t���O��ݒ肵�Ă��������B
				@param[in]		pInfo		�t���[�����[�N�̏��������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Initialize(LPFRAMEWORKINITIALIZEINFO pInfo);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CDX11GameFramework,MOF_DX11GAMEFRAMEWORKCLASS_ID);
	};

}

#endif

//[EOF]