/*************************************************************************//*!
					
					@file	GameFrameworkBase.h
					@brief	�Q�[���t���[�����[�N�̊�ꏈ����񋟂���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GAMEFRAMEWORKBASE__H__

#define		__GAMEFRAMEWORKBASE__H__

//INCLUDE
#include	"Framework.h"
#include	"../Graphics/Graphics.h"
#include	"../Input/Input.h"
#include	"../Sound/Sound.h"

namespace Mof {

//!�O���t�B�b�N�X�������t���O
#define		MOF_FRAMEWORK_GRAPHICSINITIALIZE						0x00000001
//!�T�E���h�������t���O
#define		MOF_FRAMEWORK_SOUNDINITIALIZE							0x00000002
//!�C���v�b�g�������t���O
#define		MOF_FRAMEWORK_INPUTINITIALIZE							0x00000004
//!�A�v���P�[�V�����������t���O
#define		MOF_FRAMEWORK_APPLICATIONINITIALIZE						0x00000008
//!��{�������t���O
#define		MOF_FRAMEWORK_DEFAULTINITIALIZE							(MOF_FRAMEWORK_GRAPHICSINITIALIZE | MOF_FRAMEWORK_SOUNDINITIALIZE | MOF_FRAMEWORK_INPUTINITIALIZE | MOF_FRAMEWORK_APPLICATIONINITIALIZE)

	/*******************************//*!
	@brief	�Q�[���t���[�����[�N�������\����

			�Q�[���t���[�����[�N�̐����ɕK�v�ȏ����܂Ƃ߂��\����<br>
			�쐬����t���[�����[�N�̎�ނɂ���Ă��̍\���̂��p�������\���̂��쐬����B

	@author	CDW
	*//********************************/
	typedef struct tag_GAMEFRAMEWORKINITIALIZEINFO : public FRAMEWORKINITIALIZEINFO {
		MofU32					FPS;			//!<FPS

		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GAMEFRAMEWORKINITIALIZEINFO() :
		FRAMEWORKINITIALIZEINFO() ,
		FPS(60) {
			Size = sizeof(tag_GAMEFRAMEWORKINITIALIZEINFO);
			Flag = MOF_FRAMEWORK_DEFAULTINITIALIZE;
		}
	}GAMEFRAMEWORKINITIALIZEINFO,*LPGAMEFRAMEWORKINITIALIZEINFO;
	
	/*******************************//*!
	@brief	�Q�[���t���[�����[�N���N���X

			�Q�[���t���[�����[�N�̑S�Ă̊��ƂȂ�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGameFrameworkBase : public IFramework {
	protected:
		/*******************//*!
		����A�v���P�[�V����
		*//********************/
		LPApplication		m_pApplication;
		/*******************//*!
		�O���t�B�b�N�X
		*//********************/
		LPGraphics			m_pGraphics;
		/*******************//*!
		�C���v�b�g
		*//********************/
		LPInput				m_pInput;
		/*******************//*!
		�T�E���h
		*//********************/
		LPSound				m_pSound;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGameFrameworkBase();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGameFrameworkBase();
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
	private:
		//�R�s�[���֎~����
		CGameFrameworkBase(const CGameFrameworkBase& pObj){};
	};

}

#endif

//[EOF]