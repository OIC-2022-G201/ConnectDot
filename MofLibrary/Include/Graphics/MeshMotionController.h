/*************************************************************************//*!
					
					@file	MeshMotionController.h
					@brief	���b�V�����[�V�����Ǘ��N���X�B<br>
							���b�V���A�j���[�V�����̎��ԂƏ�Ԃ��Ǘ�����B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHMOTIONCONTROLLER__H__

#define		__MESHMOTIONCONTROLLER__H__

//INCLUDE
#include	"MotionController.h"
#include	"MeshAnimation.h"
#include	"CCDIK.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V�����[�V�����{�[���t���[����ԍ\����

			���b�V�����[�V�����{�[���t���[����ԍ\���́B<br>
			�t���[�����Ƃ̃{�[������ۑ����邽�߂̍\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_BONEFRAMESTATE {
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
		CQuaternion					Angle;
	}BONEFRAMESTATE,*LPBONEFRAMESTATE;

	/*******************************//*!
	@brief	���b�V�����[�V�����{�[����ԊǗ��\����

			���b�V�����[�V�����{�[����ԊǗ��\���́B<br>
			�A�j���[�V�������̊e�{�[���̏�Ԃ��Ԃ��Ǘ����邽�߂̍\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_BONEMOTIONSTATE : public IMofNamedObjectImpl {
		/*******************//*!
		ID(�z����̔ԍ����i�[�����)
		*//********************/
		MofU32						ID;
		/*******************//*!
		�Ή��{�[��
		*//********************/
		LPBone						pBone;
		/*******************//*!
		�Ή��h�j
		*//********************/
		LPCCDJoint					pIKJoint;
		/*******************//*!
		�Ή��A�j���[�V����
		*//********************/
		LPMeshBoneAnimation			pNowAnimation;
		
		/*******************//*!
		�Ή��A�j���[�V�����J�n����
		*//********************/
		MofFloat					AnimationStartTime;
		/*******************//*!
		�Ή��A�j���[�V��������
		*//********************/
		MofFloat					AnimationTime;
		/*******************//*!
		�Ή��A�j���[�V������Ԏ���
		*//********************/
		MofFloat					TransitionTime;
		/*******************//*!
		�Ή��A�j���[�V�����X�V���x
		*//********************/
		MofFloat					AnimationSpeed;
		/*******************//*!
		�Ή��A�j���[�V�������b�N
		*//********************/
		MotionLock					Lock;
		/*******************//*!
		���ݏ��
		*//********************/
		BONEFRAMESTATE				NowState;
		/*******************//*!
		�ۊǏ��
		*//********************/
		BONEFRAMESTATE				TransitionState;
		/*******************//*!
		�Ή��A�j���[�V�����s��
		*//********************/
		CMatrix44					AnimationMatrix;
		/*******************//*!
		�Ή��{�[���s��
		*//********************/
		CMatrix44					BoneMatrix;
		/*******************//*!
		�␳�s��
		*//********************/
		CMatrix44					ReviseMatrix;
		/*******************//*!
		�ŏI�`��s��
		*//********************/
		CMatrix44					RenderMatrix;
		/*******************//*!
		IK�E�F�C�g
		*//********************/
		MofFloat					IKWait;

		/*******************//*!
		�e�{�[��
		*//********************/
		tag_BONEMOTIONSTATE*		pParent;
		/*******************//*!
		�q�{�[��
		*//********************/
		typedef CDynamicArray< tag_BONEMOTIONSTATE* >		CBoneMotionStateChildArray,*LPBoneMotionStateChildArray;
		LPBoneMotionStateChildArray	pChild;

		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_BONEMOTIONSTATE() :
		ID(0) ,
		pBone(NULL) ,
		pIKJoint(NULL) ,
		pNowAnimation(NULL) ,
		AnimationStartTime(0.0f) ,
		AnimationTime(0.0f) ,
		TransitionTime(0.0f) ,
		AnimationSpeed(1.0f) ,
		Lock(MOTIONLOCK_OFF) ,
		AnimationMatrix() ,
		BoneMatrix() ,
		ReviseMatrix() ,
		RenderMatrix() ,
		IKWait(1.0f) ,
		pParent(NULL) ,
		pChild(NULL) {
			pChild = new CBoneMotionStateChildArray();
			pChild->SetFlag(0);
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_BONEMOTIONSTATE(){
			MOF_SAFE_DELETE(pChild);
		}

		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void){
			if(pBone)
			{
				return pBone->GetName();
			}
			return NULL;
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_BONEMOTIONSTATE);
	}BONEMOTIONSTATE,*LPBONEMOTIONSTATE;
	typedef CDynamicArray< LPBONEMOTIONSTATE >		CBoneMotionStateArray,*LPBoneMotionStateArray;
	
	/*******************************//*!
	@brief	���b�V�����[�V�������[�t�B���O�t���[����ԍ\����

			���b�V�����[�V�������[�t�B���O�t���[����ԍ\���́B<br>
			�t���[�����Ƃ̃��[�t�B���O����ۑ����邽�߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MORPHINGFRAMESTATE {
		/*******************//*!
		���
		*//********************/
		MofFloat					FValue;
	}MORPHINGFRAMESTATE,*LPMORPHINGFRAMESTATE;

	/*******************************//*!
	@brief	���b�V�����[�V�����{�[����ԊǗ��\����

			���b�V�����[�V�����{�[����ԊǗ��\���́B<br>
			�A�j���[�V�������̊e�{�[���̏�Ԃ��Ԃ��Ǘ����邽�߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MORPHINGMOTIONSTATE : public IMofNamedObjectImpl {
		/*******************//*!
		ID(�z����̔ԍ����i�[�����)
		*//********************/
		MofU32						ID;
		/*******************//*!
		�W�I���g���̖��O
		*//********************/
		CString						Name;
		
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
		���ݏ��
		*//********************/
		MORPHINGFRAMESTATE			NowState;
		/*******************//*!
		�Ή��A�j���[�V����
		*//********************/
		LPMeshMorphingAnimation		pNowAnimation;

		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MORPHINGMOTIONSTATE() :
		ID(0) ,
		Name() ,
		AnimationStartTime(0.0f) ,
		AnimationTime(0.0f) ,
		AnimationSpeed(1.0f) ,
		NowState() ,
		pNowAnimation(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_MORPHINGMOTIONSTATE(){
			Name.SetString(NULL);
		}

		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void){
			return &Name;
		}
	}MORPHINGMOTIONSTATE,*LPMORPHINGMOTIONSTATE;
	typedef CDynamicArray< LPMORPHINGMOTIONSTATE >		CMorphingMotionStateArray,*LPMorphingMotionStateArray;
	
	/*******************************//*!
	@brief	���b�V�����[�V������ԊǗ��\����

			���b�V�����[�V������ԊǗ��\���́B<br>
			�A�j���[�V�������̊e��Ԃ��Ԃ��Ǘ����邽�߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_GEOMETRYMOTION : public IMofNamedObjectImpl {
		/*******************//*!
		�W�I���g���̖��O
		*//********************/
		CString						Name;
		/*******************//*!
		�W�I���g���̌����_
		*//********************/
		LPMofVoid					pVertex;
		/*******************//*!
		�Ή��{�[���h�c�z��
		*//********************/
		CU32Array					No;

		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param[in]		pName		���O
				@param[in]		Cnt			�{�[���Ή���

				@return			None
		*//**************************************************************************/
		tag_GEOMETRYMOTION(LPCMofChar pName,MofU32 Cnt) :
		Name(pName) ,
		pVertex(NULL) ,
		No(Cnt) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_GEOMETRYMOTION(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(pVertex,"GEOMETRYMOTION");
			No.Release();
		}

		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void){
			return &Name;
		}
	}GEOMETRYMOTION,*LPGEOMETRYMOTION;
	typedef CDynamicArray< LPGEOMETRYMOTION >		CGeometryMotionArray,*LPGeometryMotionArray;

	/*******************************//*!
	@brief	���b�V�����[�V�����Ǘ��N���X

			���b�V�����[�V�����Ǘ��N���X�B<br>
			���b�V���A�j���[�V�����̎��ԂƏ�Ԃ��Ǘ�����B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMeshMotionController : public IMotionController {
	protected:
		/*******************//*!
		���[���h�}�g���N�X
		*//********************/
		CMatrix44					m_WorldMatrix;
		/*******************//*!
		���[�V��������
		*//********************/
		MofFloat					m_MotionTime;
		/*******************//*!
		���[�V�����ԍ�
		*//********************/
		MofS32						m_MotionNo;
		
		/*******************//*!
		�{�[���z��
		*//********************/
		LPBoneArray					m_pBone;
		/*******************//*!
		�A�j���[�V�����z��
		*//********************/
		LPMeshAnimationArray		m_pAnimation;
		/*******************//*!
		�{�[����Ԕz��
		*//********************/
		LPBoneMotionStateArray		m_pBoneState;
		/*******************//*!
		���[�t�B���O��Ԕz��
		*//********************/
		LPMorphingMotionStateArray	m_pMorphingState;
		/*******************//*!
		�h�j�z��
		*//********************/
		LPCCDIKArray				m_pIKs;
		/*******************//*!
		�W�I���g���Ή��z��
		*//********************/
		LPGeometryMotionArray		m_pGeometryMotion;
		
		/*************************************************************************//*!
				@brief			�s���Ԃ��X�V(�����ċA�p�֐�)
				@param[in]		pBS				�X�V�{�[�����
				@param[in]		wMat			���[���h�}�g���N�X
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrix(LPBONEMOTIONSTATE pBS,const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			�s���Ԃ��X�V(�����ċA�p�֐�)
				@param[in]		pJoint			�h�j���

				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RefreshIKBoneMatrix(LPCCDJoint pJoint);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CMeshMotionController();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pBone		�{�[��
				@param[in]		pAnim		�A�j���[�V����

				@return			None
		*//**************************************************************************/
		CMeshMotionController(LPBoneArray pBone,LPMeshAnimationArray pAnim);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�I�u�W�F�N�g

				@return			None
		*//**************************************************************************/
		CMeshMotionController(const CMeshMotionController& pObj);

		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CMeshMotionController();
		
		/*************************************************************************//*!
				@brief			���݂̏�Ԃ��X�V
				@param			None
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Refresh(void);
		/*************************************************************************//*!
				@brief			�{�[���s���Ԃ��X�V
				@param[in]		wMat			���[���h�}�g���N�X
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrix(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			�s���Ԃ��X�V
				@param[in]		wMat			���[���h�}�g���N�X
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrixOnly(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			�`��s��̈ʒu�݂̂��X�V
				@param[in]		wMat			���[���h�}�g���N�X
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrixPosition(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			�`��s��̈ʒu�݂̂��X�V
				@param[in]		pos				�ʒu
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrixPosition(const Vector3& pos);
		/*************************************************************************//*!
				@brief			���[�t�B���O��Ԃ��X�V
				@param[in]		pGeom			�X�V�W�I���g��
	
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RefreshMorphing(LPGeometry pGeom);
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
				@param[in]		n				���[�V�����ԍ�
				@param[in]		spd				���[�V�����Đ����x
				@param[in]		bLoop			���[�v�t���O
				@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeMotion(MofU32 n, MofFloat spd, MofBool bLoop, MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			���݂̃��[�V������ύX
				@param[in]		n				���[�V�����ԍ�
				@param[in]		nt				���[�V��������
				@param[in]		spd				���[�V�����Đ����x
				@param[in]		tTime			���[�V������Ԏ���
				@param[in]		bLoop			���[�v�t���O
				@param[in]		Lock			�ύX���b�N�t���O
				@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeMotion(MofU32 n,MofFloat nt,MofFloat spd,MofFloat tTime,MofBool bLoop,MotionLock Lock,MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			���݂̃��[�V������ύX
				@param[in]		str				���[�V������
				@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeMotionByName(LPCMofChar str,MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			���݂̃��[�V������ύX
				@param[in]		str				���[�V������
				@param[in]		spd				���[�V�����Đ����x
				@param[in]		bLoop			���[�v�t���O
				@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeMotionByName(LPCMofChar str, MofFloat spd, MofBool bLoop, MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			���݂̃��[�V������ύX
				@param[in]		str				���[�V������
				@param[in]		nt				���[�V��������
				@param[in]		spd				���[�V�����Đ����x
				@param[in]		tTime			���[�V������Ԏ���
				@param[in]		bLoop			���[�v�t���O
				@param[in]		Lock			�ύX���b�N�t���O
				@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeMotionByName(LPCMofChar str, MofFloat nt, MofFloat spd, MofFloat tTime, MofBool bLoop, MotionLock Lock, MofBool bSame = TRUE);
				
		/*************************************************************************//*!
				@brief			���[�V�����̕ύX�����b�N����
				@param[in]		Lock			�ύX���b�N�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeLock(MotionLock Lock);
		
		
		/*************************************************************************//*!
				@brief			�{�[���̒ǉ�<br>
								�����̃{�[���̏ꍇ�́A�㏑���t���O��TRUE�Ȃ����u��������B
				@param[in]		pBone			�{�[��
				@param[in]		bOW				�㏑���t���O

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool AddBone(LPBoneArray pBone, MofBool bOW = TRUE);
		/*************************************************************************//*!
				@brief			�{�[���̒ǉ�<br>
								�����̃{�[���̏ꍇ�́A�㏑���t���O��TRUE�Ȃ����u��������B
				@param[in]		pBone			�{�[��
				@param[in]		bOW				�㏑���t���O

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool AddBone(LPBone pBone, MofBool bOW = TRUE);

		/*************************************************************************//*!
				@brief			�A�j���[�V�����̒ǉ�<br>
								�����̃A�j���[�V�����̏ꍇ�́A<br>
								�ǉ��A�j���[�V�����ɂ̂ݑ��݂���{�[��������ꍇ�̂ݏ���ǉ�����B
				@param[in]		pAnim			�A�j���[�V����

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool AddAnimation(LPMeshAnimationArray pAnim);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����̒ǉ�<br>
								�����̃A�j���[�V�����̏ꍇ�́A<br>
								�ǉ��A�j���[�V�����ɂ̂ݑ��݂���{�[��������ꍇ�̂ݏ���ǉ�����B
				@param[in]		pAnim			�A�j���[�V����

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool AddAnimation(LPMeshAnimation pAnim);

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
		/*************************************************************************//*!
				@brief			�o�^����Ă���{�[�����擾
				@param			None

				@return			�o�^����Ă���{�[����
		*//**************************************************************************/
		virtual MofS32 GetBoneCount(void);
		/*************************************************************************//*!
				@brief			�o�^����Ă��郂�[�V�����擾
				@param[in]		n				���[�V�����ԍ�

				@return			�o�^����Ă��郂�[�V����
		*//**************************************************************************/
		virtual LPMeshAnimation GetMotion(MofU32 n);
		/*************************************************************************//*!
				@brief			�o�^����Ă��郂�[�V�����擾
				@param[in]		pName			���[�V������

				@return			�o�^����Ă��郂�[�V����
		*//**************************************************************************/
		virtual LPMeshAnimation GetMotionByName(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			�o�^����Ă��郂�[�V�����擾
				@param[in]		pName			���[�V������

				@return			�o�^����Ă��郂�[�V�����̔ԍ�
								MOF_U32_MAX			�w�薼�̃��[�V�������o�^����Ă��Ȃ�
		*//**************************************************************************/
		virtual MofU32 GetMotionNoByName(LPCMofChar pName) const;
		/*************************************************************************//*!
				@brief			�{�[����Ԏ擾
				@param[in]		n				�{�[���ԍ�

				@return			�{�[�����
		*//**************************************************************************/
		virtual LPBONEMOTIONSTATE GetBoneState(MofU32 n);
		/*************************************************************************//*!
				@brief			�{�[����Ԏ擾
				@param[in]		Name			��������{�[����

				@return			�{�[�����
		*//**************************************************************************/
		virtual LPBONEMOTIONSTATE GetBoneState(LPCMofChar Name);
		/*************************************************************************//*!
				@brief			���[���h�}�g���N�X�擾
				@param[in]		None

				@return			���[���h�}�g���N�X
		*//**************************************************************************/
		virtual CMatrix44& GetWorldMatrix(void);
		/*************************************************************************//*!
				@brief			4�~3�s��Ƃ��ĕ`��s����擾�擾
				@param[out]		pOut			�s��o�͗p�z��(�Ή��{�[���{���~4�~3��葽���z����m�ۂ��Ă����K�v������)
				@param[out]		cnt				�s��o�͗p�z��̐�
	
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool GetRenderMatrix43(LPMofFloat pOut, MofU32 cnt);
		/*************************************************************************//*!
				@brief			4�~3�s��Ƃ��ĕ`��s����擾�擾<br>
								�Ή��{�[�������X�g�ɑΉ�����{�[�����݂̂̔z���ݒ肷��B<br>
								��x�擾���s���Ɠ����ɃW�I���g�����ƑΉ��{�[���̔z�񂪍쐬�����B
				@param[in]		pName			�`��W�I���g����
				@param[in]		pBNArray		�`��Ή��{�[�������X�g
				@param[out]		pOut			�s��o�͗p�z��(�Ή��{�[���{���~4�~3��葽���z����m�ۂ��Ă����K�v������)
				@param[out]		cnt				�s��o�͗p�z��̐�
	
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool GetRenderMatrix43(LPMofChar pName,LPStringArray pBNArray,LPMofFloat pOut, MofU32 cnt);
		/*************************************************************************//*!
				@brief			4�~4�s��Ƃ��ĕ`��s����擾�擾
				@param[out]		pOut			�s��o�͗p�z��(�Ή��{�[���{���~4�~4��葽���z����m�ۂ��Ă����K�v������)
				@param[out]		cnt				�s��o�͗p�z��̐�
	
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool GetRenderMatrix44(LPMofFloat pOut, MofU32 cnt);
		/*************************************************************************//*!
				@brief			4�~4�s��Ƃ��ĕ`��s����擾�擾<br>
								�Ή��{�[�������X�g�ɑΉ�����{�[�����݂̂̔z���ݒ肷��B<br>
								��x�擾���s���Ɠ����ɃW�I���g�����ƑΉ��{�[���̔z�񂪍쐬�����B
				@param[in]		pName			�`��W�I���g����
				@param[in]		pBNArray		�`��Ή��{�[�������X�g
				@param[out]		pOut			�s��o�͗p�z��(�Ή��{�[���{���~4�~4��葽���z����m�ۂ��Ă����K�v������)
				@param[out]		cnt				�s��o�͗p�z��̐�
	
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool GetRenderMatrix44(LPMofChar pName,LPStringArray pBNArray,LPMofFloat pOut, MofU32 cnt);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CMeshMotionController,MOF_MESHMOTIONCONTROLLERCLASS_ID);
	};

	#include	"MeshMotionController.inl"

	typedef CMeshMotionController *LPMeshMotionController;
}

#endif

//[EOF]