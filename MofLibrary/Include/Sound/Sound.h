/*************************************************************************//*!
					
					@file	Sound.h
					@brief	�e��T�E���h�̏������s�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SOUND__H__

#define		__SOUND__H__

//INCLUDE
#include	"SoundCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�T�E���h�������\����

			�T�E���h�̐����ɕK�v�ȏ����܂Ƃ߂��\����

	@author	CDW
	*//********************************/
	typedef struct tag_SOUNDCREATEINFO {
		MofU32					Size;						//!<�\���̃T�C�Y
		MofU32					Flags;						//!<�����t���O

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_SOUNDCREATEINFO() :
		Size(sizeof(tag_SOUNDCREATEINFO)),
		Flags(0) {
		}
	}SOUNDCREATEINFO,*LPSOUNDCREATEINFO;

	/*******************************//*!
	@brief	�T�E���h���C���^�[�t�F�C�X

			�T�E���h�̊��ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API ISound : public IMofObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�T�E���h�I�u�W�F�N�g�̐���
				@param[in]		pInfo		�T�E���h�̐������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPSOUNDCREATEINFO pInfo) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�T�E���h�f�o�C�X�擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�T�E���h�f�o�C�X
		*//**************************************************************************/
		virtual MofSoundDevice GetDevice(void) = 0;
	};

	//�|�C���^�u������
	typedef ISound*				LPSound;
}

#endif

//[EOF]