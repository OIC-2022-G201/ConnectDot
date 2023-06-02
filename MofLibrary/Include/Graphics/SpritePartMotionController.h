/*************************************************************************//*!
					
					@file	SpritePartMotionController.h
					@brief	�X�v���C�g�p�[�c���[�V�����Ǘ��N���X�B<br>
							�X�v���C�g�p�[�c�A�j���[�V�����̎��ԂƏ�Ԃ��Ǘ�����B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPRITEPARTMOTIONCONTROLLER__H__

#define		__SPRITEPARTMOTIONCONTROLLER__H__

//INCLUDE
#include	"MotionController.h"
#include	"SpriteContainerAnimation.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�X�v���C�g�p�[�c���[�V�����t���[����ԍ\����

			�X�v���C�g�p�[�c���[�V�����t���[����ԍ\���́B<br>
			�t���[�����Ƃ̃p�[�c����ۑ����邽�߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_PARTFRAMESTATE {
		/*******************//*!
		���W
		*//********************/
		CVector3					Pos;
		/*******************//*!
		�X�P�[��
		*//********************/
		CVector3					Scale;
		/*******************//*!
		��]
		*//********************/
		CVector3					Angle;
		/*******************//*!
		�F
		*//********************/
		CVector4					Color;
		/*******************//*!
		�A���C�����g�I�t�Z�b�g
		*//********************/
		CVector3					AlignmentOffset;
		/*******************//*!
		�T�C�Y
		*//********************/
		CVector3					Size;
		/*******************//*!
		�A���J�[
		*//********************/
		CVector3					Anchor;
		/*******************//*!
		���_
		*//********************/
		CVector2					Vertex[4];
		/*******************//*!
		���_
		*//********************/
		CVector4					VertexColor[4];
		/*******************//*!
		���_
		*//********************/
		MofFloat					VertexColorRate;
		/*******************//*!
		UV���W
		*//********************/
		CVector2					UVPos;
		/*******************//*!
		UV�X�P�[��
		*//********************/
		CVector2					UVScale;
		/*******************//*!
		UV��]
		*//********************/
		MofFloat					UVAngle;

		MOF_ALIGNED_NEW_OPERATOR(tag_PARTFRAMESTATE);
	}PARTFRAMESTATE,*LPPARTFRAMESTATE;

	/*******************************//*!
	@brief	�X�v���C�g�p�[�c���[�V�����{�[����ԊǗ��\����

			�X�v���C�g�p�[�c���[�V�����{�[����ԊǗ��\���́B<br>
			�A�j���[�V�������̊e�{�[���̏�Ԃ��Ԃ��Ǘ����邽�߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_PARTMOTIONSTATE : public IMofNamedObjectImpl {
		/*******************//*!
		ID(�z����̔ԍ����i�[�����)
		*//********************/
		MofU32						ID;
		/*******************//*!
		�Ή��{�[��
		*//********************/
		LPSprite2DPart				pSprite;
		/*******************//*!
		�Ή��A�j���[�V����
		*//********************/
		LPSpritePartAnimation		pNowAnimation;
		
		/*******************//*!
		�Ή��A�j���[�V�����J�n����
		*//********************/
		MofFloat					AnimationStartTime;
		/*******************//*!
		�Ή��A�j���[�V��������
		*//********************/
		MofFloat					AnimationTime;
		/*******************//*!
		�Ή��A�j���[�V�����X�V���x
		*//********************/
		MofFloat					AnimationSpeed;
		/*******************//*!
		��{�\��
		*//********************/
		MofBool						bBaseShow;
		/*******************//*!
		���ݏ��
		*//********************/
		PARTFRAMESTATE				NowState;
		/*******************//*!
		�Ή��A�j���[�V�����s��
		*//********************/
		CMatrix44					AnimationMatrix;
		/*******************//*!
		�ŏI�`��s��
		*//********************/
		CMatrix44					RenderMatrix;

		/*******************//*!
		�e�p�[�c
		*//********************/
		tag_PARTMOTIONSTATE*		pParent;
		/*******************//*!
		�q�p�[�c
		*//********************/
		typedef CDynamicArray< tag_PARTMOTIONSTATE* >		CPartMotionStateChildArray,*LPPartMotionStateChildArray;
		LPPartMotionStateChildArray	pChild;

		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PARTMOTIONSTATE() :
		ID(0) ,
		pSprite(NULL) ,
		pNowAnimation(NULL) ,
		AnimationStartTime(0.0f) ,
		AnimationTime(0.0f) ,
		AnimationSpeed(1.0f) ,
		bBaseShow(TRUE) ,
		NowState() ,
		AnimationMatrix() ,
		RenderMatrix() ,
		pParent(NULL) ,
		pChild(NULL) {
			pChild = new CPartMotionStateChildArray();
			pChild->SetFlag(0);
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PARTMOTIONSTATE(){
			MOF_SAFE_DELETE(pChild);
		}

		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void){
			if(pSprite)
			{
				return pSprite->GetName();
			}
			return NULL;
		}
	}PARTMOTIONSTATE,*LPPARTMOTIONSTATE;
	typedef CDynamicArray< LPPARTMOTIONSTATE >		CPartMotionStateArray,*LPPartMotionStateArray;

	/*******************************//*!
	@brief	�X�v���C�g�p�[�c���[�V�����Ǘ��N���X

			�X�v���C�g�p�[�c���[�V�����Ǘ��N���X�B<br>
			�X�v���C�g�p�[�c�A�j���[�V�����̎��ԂƏ�Ԃ��Ǘ�����B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSpritePartMotionController : public IMotionController {
	protected:
		/*******************//*!
		���[���h�}�g���N�X
		*//********************/
		CMatrix44						m_WorldMatrix;
		/*******************//*!
		���[�V��������
		*//********************/
		MofFloat						m_MotionTime;
		/*******************//*!
		���[�V�����ԍ�
		*//********************/
		MofS32							m_MotionNo;
		
		/*******************//*!
		�A�j���[�V�����z��
		*//********************/
		LPSpriteContainerAnimationArray	m_pAnimation;
		/*******************//*!
		�X�v���C�g��Ԕz��
		*//********************/
		LPPartMotionStateArray			m_pPartState;
		
		/*************************************************************************//*!
				@brief			�X�v���C�g��Ԃ��쐬
				@param[in]		pPart
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool CreatePartMotionState(LPSprite2DPart pPart);
		/*************************************************************************//*!
				@brief			�s���Ԃ��X�V(�����ċA�p�֐�)
				@param[in]		pPS				�X�V�X�v���C�g���
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Refresh(LPPARTMOTIONSTATE pPS);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CSpritePartMotionController();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pPart		�X�v���C�g
				@param[in]		pAnim		�A�j���[�V����

				@return			None
		*//**************************************************************************/
		CSpritePartMotionController(LPSprite2DPart pPart,LPSpriteContainerAnimationArray pAnim);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�I�u�W�F�N�g

				@return			None
		*//**************************************************************************/
		CSpritePartMotionController(const CSpritePartMotionController& pObj);

		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSpritePartMotionController();
		
		/*************************************************************************//*!
				@brief			���݂̏�Ԃ��X�V
				@param			None
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Refresh(void);
		/*************************************************************************//*!
				@brief			���݂̃��[�V������Ԃ��X�V
				@param[in]		t				�X�V����
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool AddTimer(MofFloat t);

		/*************************************************************************//*!
				@brief			���݂̃��[�V������ύX
				@param[in]		n				���[�V�����ԍ�
				@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeMotion(MofU32 n,MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			���݂̃��[�V������ύX
				@param[in]		str				���[�V������
				@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeMotionByName(LPCMofChar str,MofBool bSame = TRUE);
				
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
				@brief			���݂̃��[�V�������I�����Ă��邩�𔻒肷��B<br>
								���[�V���������[�v����ꍇ��TRUE�ɂȂ邱�Ƃ͂Ȃ�
				@param			None
				
				@return			TRUE			�I���ς�<br>
								FALE			�܂��I�����Ă��Ȃ�
		*//**************************************************************************/
		virtual MofBool IsEndMotion(void);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���݂̃��[�V�������Ԃ�ݒ�
				@param[in]		t				�ݒ莞��
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTime(MofFloat t);
		/*************************************************************************//*!
				@brief			���[�V�����̃��[�v�t���O�̐ݒ�
				@param[in]		n				���[�V�����ԍ�
				@param[in]		bLoop			���[�v�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetMotionLoop(MofU32 n,MofBool bLoop);
		/*************************************************************************//*!
				@brief			���[�V�����̃��[�v�t���O�̐ݒ�
				@param[in]		str				���[�V������
				@param[in]		bLoop			���[�v�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetMotionLoopByName(LPCMofChar str,MofBool bLoop);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���݂̃��[�V�������Ԏ擾
				@param			None

				@return			���݂̃��[�V��������
		*//**************************************************************************/
		virtual MofFloat GetTime(void) const;
		/*************************************************************************//*!
				@brief			���݂̃��[�V�����ԍ��擾
				@param			None

				@return			���݂̃��[�V�����ԍ�
		*//**************************************************************************/
		virtual MofS32 GetMotionNo(void) const;
		/*************************************************************************//*!
				@brief			�o�^����Ă��郂�[�V�������擾
				@param			None

				@return			�o�^����Ă��郂�[�V������
		*//**************************************************************************/
		virtual MofS32 GetMotionCount(void) const;

		//�N���X��{��`
		MOF_LIBRARYCLASS(CSpritePartMotionController,MOF_SPRITEPARTMOTIONCONTROLLERCLASS_ID);
	};

	#include	"SpritePartMotionController.inl"

	typedef CSpritePartMotionController *LPSpritePartMotionController;
}

#endif

//[EOF]