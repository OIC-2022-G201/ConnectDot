/*************************************************************************//*!
					
					@file	SpriteContainerAnimation.h
					@brief	�X�v���C�g�R���e�i�A�j���[�V�������N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPRITECONTAINERANIMATION__H__

#define		__SPRITECONTAINERANIMATION__H__

//INCLUDE
#include	"SpritePartAnimation.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���A�j���[�V�������N���X

			���b�V���A�j���[�V�������ƂȂ�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSpriteContainerAnimation : public IMofNamedObject , public IMofCopyObject< CSpriteContainerAnimation > {
	protected:
		/*******************//*!
		���O
		*//********************/
		CString						m_Name;
		/*******************//*!
		�p�[�c�A�j���[�V����
		*//********************/
		LPSpritePartAnimationArray	m_pPartAnimation;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CSpriteContainerAnimation();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[���b�V���A�j���[�V����

				@return			None
		*//**************************************************************************/
		CSpriteContainerAnimation(const CSpriteContainerAnimation& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSpriteContainerAnimation();
		
		/*************************************************************************//*!
				@brief			�X�v���C�g�A�j���[�V�����̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽCSpriteContainerAnimation<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual CSpriteContainerAnimation* CreateCopyObject(void) const;

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�ݒ�
				@param[in]		pName			�ݒ肷�閼�O
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			���[�V�����̃��[�v�t���O�̐ݒ�
				@param[in]		bLoop			���[�v�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetLoop(MofBool bLoop);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����ł̓���p�[�c���擾
				@param			None

				@return			�A�j���[�V�����ł̓���p�[�c���z��
		*//**************************************************************************/
		virtual LPSpritePartAnimationArray GetPartAnimation(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CSpriteContainerAnimation,MOF_SPRITECONTAINERANIMATIONCLASS_ID);
	};

	#include	"SpriteContainerAnimation.inl"
	
	//�u������
	typedef CSpriteContainerAnimation					*LPSpriteContainerAnimation;
	typedef CDynamicArray< LPSpriteContainerAnimation >	CSpriteContainerAnimationArray,*LPSpriteContainerAnimationArray;
}

#endif

//[EOF]