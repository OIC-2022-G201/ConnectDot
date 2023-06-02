/*************************************************************************//*!
					
					@file	Sprite2DEffect.h
					@brief	�X�v���C�g�R���e�i�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPRITE2DEFFECT__H__

#define		__SPRITE2DEFFECT__H__

//INCLUDE
#include	"Sprite2DPart.h"
#include	"SpritePartMotionController.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�X�v���C�g�R���e�i�N���X

			�X�v���C�g�R���e�i�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSprite2DEffect : public CSprite2DPart {
		//----------------------------------------------------------------------------
		////�O���C�u�����Ƃ̑Ή��̂��߂ɂ���ʃp�����[�^�[��public�Ή��ɂ��Ă���
		//----------------------------------------------------------------------------
	public:
		/*******************//*!
		�G�t�F�N�g�p�����[�^�[
		*//********************/
		MOFSPRITEEFFECTPARAMETER			m_EffectParameter;
		/*******************//*!
		�G�~�b�^�[�̐�����
		*//********************/
		MofS32								m_CreateCount;
		
		/*******************************//*!
		@brief	�p�[�e�B�N���̕`��p�̏��\����

				�p�[�e�B�N���̕`��p�̏��\����

		@author	CDW
		*//********************************/
		typedef struct tag_PARTICLEDRAWDATA
		{
			Vector2 position;
			float	rot;
			float	direc;

			Vector4 color;
			Vector2 scale;
		}PARTICLEDRAWDATA, *LPPARTICLEDRAWDATA;
		/*******************************//*!
		@brief	�p�[�e�B�N���̐������̏��\����

				�p�[�e�B�N���̐������̏��\����

		@author	CDW
		*//********************************/
		typedef struct tag_PARTICLEDATA
		{
			MofFloat						StartTime;
			MofFloat						LifeTime;
			MofU32							Seed;
		}ParticleData, *LPParticleData;
		/*******************//*!
		���������p�[�e�B�N�����
		*//********************/
		CDynamicArray< LPParticleData >		m_ParticleData;
		/*******************//*!
		�����e�[�u��
		*//********************/
		CDynamicArray< MofU32 >				m_SeedTable;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CSprite2DEffect();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�e�N�X�`��

				@return			None
		*//**************************************************************************/
		CSprite2DEffect(const CSprite2DEffect& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSprite2DEffect();
		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[�e�N�X�`��<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual ISprite* CreateCopyObject(void) const;
		
		/*************************************************************************//*!
				@brief			�X�v���C�g�̍X�V
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Update(void);
		/*************************************************************************//*!
				@brief			�p�[�e�B�N���̍X�V<br>
								�w��̎��Ԃɂ�����p�[�e�B�N���̏����v�Z����
				@param[in]		t			����
				@param[in]		pt			�o�͂���p�[�e�B�N���̐������
				@param[in,out]	p			�o�͂���p�[�e�B�N�����
				@param[in]		rec			�Čv�Z�t���O

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool UpdateParticle(MofFloat t, LPParticleData pt, PARTICLEDRAWDATA& p, MofBool rec = FALSE);

		/*************************************************************************//*!
				@brief			�G�~�b�^�[�̃��Z�b�g
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ResetEmitter(void);
		/*************************************************************************//*!
				@brief			�G�~�b�^�[������̎��Ԃ̏�Ԃɐݒ肷��
				@param[in]		nt			����

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RefreshEmitter(MofFloat nt);
		
		/*************************************************************************//*!
				@brief			�X�v���C�g�̕`��
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(void);
		/*************************************************************************//*!
				@brief			�X�v���C�g�̕`��
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderPart(void);
		
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			���݂̃��[�V�������I�����Ă��邩�𔻒肷��B<br>
								���[�V���������[�v����ꍇ��TRUE�ɂȂ邱�Ƃ͂Ȃ�
				@param			None
				
				@return			TRUE			�I���ς�<br>
								FALE			�܂��I�����Ă��Ȃ�
		*//**************************************************************************/
		MofBool IsEndMotion(void);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------

		//�N���X��{��`
		MOF_LIBRARYCLASS(CSprite2DEffect,MOF_SPRITE2DEFFECTCLASS_ID);
	};

	#include	"Sprite2DEffect.inl"

	//�|�C���^�u������
	typedef CSprite2DEffect*			LPSprite2DEffect;
}

#endif

//[EOF]