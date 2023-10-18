/*************************************************************************//*!
					
					@file	SpriteAnimation.h
					@brief	�X�v���C�g�A�j���[�V�����N���X�B<br>
							�X�v���C�g�̋�`�ω��ł̃A�j���[�V�������s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPRITEANIMATION__H__

#define		__SPRITEANIMATION__H__

//INCLUDE
#include	"../Common/KeyFrameArray.h"
#include	"../Utilities/Utilities.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�X�v���C�g�A�j���[�V�����ȈՍ쐬�p�p�^�[���\����

			�X�v���C�g�A�j���[�V�������I�t�Z�b�g�ƕ��A�����ō쐬����ۂ�1�p�^�[���̓��e�B

	@author	CDW
	*//********************************/
	typedef struct tag_SPRITEANIMATIONCREATEPATTERN {
		MofFloat							Wait;						//!<�t���[���E�F�C�g
		MofS32								No;							//!<�p�^�[���ԍ�
		MofS32								Step;						//!<�p�^�[���i
	}SpriteAnimationCreatePattern,*LPSpriteAnimationCreatePattern;

	/*******************************//*!
	@brief	�X�v���C�g�A�j���[�V�����ȈՍ쐬�p�\����

			�X�v���C�g�A�j���[�V�������I�t�Z�b�g�ƕ��A�����ō쐬���邽�߂̍\���́B

	@author	CDW
	*//********************************/
	template < int N > struct SpriteAnimationCreateFrame {
		CString								Name;						//!<�A�j���[�V������
		MofFloat							OffsetX;					//!<X�I�t�Z�b�g�ʒu
		MofFloat							OffsetY;					//!<Y�I�t�Z�b�g�ʒu
		MofFloat							Width;						//!<��
		MofFloat							Height;						//!<����
		MofBool								bLoop;						//!<���[�v�t���O(TRUE�Ȃ烋�[�v�AFALSE�Ȃ�ŏI�t���[���Œ�~)
		SpriteAnimationCreatePattern		Pattern[N];					//!<�p�^�[��
	};
	typedef SpriteAnimationCreateFrame< 30 > SpriteAnimationCreate,*LPSpriteAnimationCreate;

	/*******************************//*!
	@brief	�X�v���C�g�A�j���[�V�����N���X

			�X�v���C�g�A�j���[�V�����N���X�B<br>
			�X�v���C�g�̋�`�ω��ł̃A�j���[�V�������s���B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSpriteAnimation : public IMofNamedObject {
	protected:
		/*******************//*!
		�A�j���[�V������
		*//********************/
		CString						m_Name;
		/*******************//*!
		��`���X�g
		*//********************/
		CRectangleKeyFrameArray		m_RectKeyFrame;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CSpriteAnimation();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		frm				�t���[��

				@return			None
		*//**************************************************************************/
		template < int N > CSpriteAnimation(SpriteAnimationCreateFrame< N >& frm);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�I�u�W�F�N�g

				@return			None
		*//**************************************************************************/
		CSpriteAnimation(const CSpriteAnimation& pObj);

		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSpriteAnimation();
				
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Is
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���݂̃��[�V���������[�v���邩�𔻒肷��B
				@param			None
				
				@return			TRUE			���[�v����<br>
								FALE			���[�v���Ȃ�
		*//**************************************************************************/
		virtual MofBool IsLoop(void);
		
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
				@brief			�w�莞�Ԃł̋�`�擾
				@param[in]		t				����
				@param[out]		oRec			�o�͋�`
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool GetTimeRect(const MofFloat t,Rectangle& oRec);
		/*************************************************************************//*!
				@brief			�w�莞�Ԃł̃t���[���ԍ��擾
				@param[in]		t				����

				@return			�t���[���ԍ�
		*//**************************************************************************/
		virtual MofU32 GetTimeFrameNo(const MofFloat t);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����̏I�����Ԏ擾<br>
								���[�v������ꍇ�ł��ŏI�̃t���[���̎��Ԃ�Ԃ�
				@param			None
				
				@return			�A�j���[�V�����̏I������
		*//**************************************************************************/
		virtual MofFloat GetEndTime(void);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS(CSpriteAnimation,MOF_SPRITEANIMATIONCLASS_ID);
	};

	#include	"SpriteAnimation.inl"

	//�u������
	typedef CSpriteAnimation						*LPSpriteAnimation;
	typedef CDynamicArray< LPSpriteAnimation >		CSpriteAnimationArray,*LPSpriteAnimationArray;
}

#endif

//[EOF]