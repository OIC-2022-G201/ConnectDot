/*************************************************************************//*!
					
					@file	MomCommon.h
					@brief	�Ǝ��`�����f���t�@�C���֘A�̊�{��`���s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MOMCOMMON__H__

#define		__MOMCOMMON__H__

//INCLUDE
#include	"GraphicsCommon.h"
#include	"../Common/PackFile.h"
#include	"../Common/WriteChunkFile.h"
#include	"../Common/KeyFrameArray.h"

//DEFINE

//!�Ǝ��t�@�C���w�b�_�[
#define		MOFMODEL_FILE_HEADER				"MOF MODEL VER 0.01 FILE"

//!�Ǝ��t�@�C���w�b�_�[��
#define		MOFMODEL_FILE_HEADERLEN				strlen(MOFMODEL_FILE_HEADER)

//!�Ǝ��t�@�C���t�b�^�[
#define		MOFMODEL_FILE_FOOTER				"EOF"

//!�Ǝ��t�@�C���t�b�^�[��
#define		MOFMODEL_FILE_FOOTERLEN				strlen(MOFMODEL_FILE_FOOTER)

namespace Mof {
	
	/*******************************//*!
	@brief	���f���t�@�C���e���v���[�g��

			MOM�t�@�C�����ɒ�`�����`�����N�̏��^�C�v���

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_TEMPLATE {
		MOFMODEL_TEMP_MESH					=		0x00001000,						//!<���b�V��
		MOFMODEL_TEMP_GEOMETRY,														//!<�W�I���g��
		MOFMODEL_TEMP_VERTEX,														//!<���_���
		MOFMODEL_TEMP_INDEX,														//!<�C���f�b�N�X���
		MOFMODEL_TEMP_MATERIAL,														//!<�}�e���A�����
		MOFMODEL_TEMP_TEXTURE,														//!<�e�N�X�`�����
		MOFMODEL_TEMP_SHADER,														//!<�V�F�[�_�[���
		MOFMODEL_TEMP_MATRIX,														//!<�ϊ��s����
		MOFMODEL_TEMP_GEOMETRYMORPHING,												//!<���[�t�B���O���

		MOFMODEL_TEMP_BONE					=		0x00002000,						//!<�{�[�����
		MOFMODEL_TEMP_BONEPARAMETER,												//!<�{�[���p�����[�^�[���
		MOFMODEL_TEMP_BONEWEIGHT,													//!<�{�[���E�F�C�g���
		MOFMODEL_TEMP_BONEGROUP,													//!<�{�[���O���[�v���

		MOFMODEL_TEMP_ANIMATIONSET			=		0x00003000,						//!<�A�j���[�V�������
		MOFMODEL_TEMP_ANIMATION,													//!<�A�j���[�V�������
		MOFMODEL_TEMP_ANIMATIONKEY,													//!<�A�j���[�V�������
		MOFMODEL_TEMP_MORPHING,														//!<�A�j���[�V�������

		MOFMODEL_TEMP_ANIMATION2,													//!<�A�j���[�V�������(Ver2)

		MOFMODEL_TEMP_BLOCK					=		0x00004000,						//!<�u���b�N���

		MOFMODEL_TEMP_LODMODEL				=		0x00005000,						//!<�����������f�����

		MOFMODEL_TEMP_IK					=		0x00006000,						//!<IK���
		MOFMODEL_TEMP_IKJOINT,														//!<IK�ڑ����

		MOFMODEL_TEMP_RIGID					=		0x00007000,						//!<���̏��
		MOFMODEL_TEMP_RIGIDJOINT,													//!<���̐ڑ����

		MOFMODEL_TEMP_SCENE					=		0x00010000,						//!<�V�[��
		MOFMODEL_TEMP_CAMERA,														//!<�J����
		MOFMODEL_TEMP_CAMERAANIMATION,												//!<�A�j���[�V�������
		MOFMODEL_TEMP_LIGHT,														//!<���C�g

		MOFMODEL_TEMP_MAX,															//!<�`�����N�ő吔
	};
	
	/*******************************//*!
	@brief	���f���t�@�C���L�[�^�C�v��

			MOM�t�@�C�����ɒ�`�����A�j���[�V�����̃L�[�^�C�v���

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_ANIMATIONKEYTYPE {
		MOFMODEL_ANIMATIONKEY_TRANSLATION,
		MOFMODEL_ANIMATIONKEY_SCALING,
		MOFMODEL_ANIMATIONKEY_ROTATION,
		MOFMODEL_ANIMATIONKEY_FLOTPARAMETER,
		MOFMODEL_ANIMATIONKEY_TARGET,
		MOFMODEL_ANIMATIONKEY_UPVECTOR,
		MOFMODEL_ANIMATIONKEY_CAMERAFOV,
	};

	
	/*******************************//*!
	@brief	���f���t�@�C���L�[�t���O��

			MOM�t�@�C�����ɒ�`�����A�j���[�V�����̃L�[�t���O���

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_ANIMATIONKEYFLAG {
		MOFMODEL_ANIMATIONKEYFLAG_RELATIVE	=		0x80000000,
	};

	/*******************************//*!
	@brief	���f���t�@�C���A�j���[�V�����t���O��

			MOM�t�@�C�����ɒ�`�����A�j���[�V�����̃t���O���

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_ANIMATIONFLAG {
		MOFMODEL_ANIMATIONFLAG_GROBAL		=		0x00000001,
	};

	/*******************************//*!
	@brief	���f���t�@�C����̓G���[��

			���f���t�@�C����͎��ɔ�������G���[���

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_RESULT {
		MOFMODEL_RESULTERROR_UNKNOWN		=		0,								//!<�悭�킩��Ȃ��G���[

		MOFMODEL_RESULT_SUCCEEDED			=		TRUE,							//!<����I��

		MOFMODEL_RESULTERROR_OPENERROR,												//!<�t�@�C�����J���Ȃ�����
		MOFMODEL_RESULTERROR_NOTMOMFILE,											//!<�t�@�C����MOM�`������Ȃ�

		MOFMODEL_RESULTERROR_CHUNKSIZE,												//!<�`�����N�T�C�Y����������
		MOFMODEL_RESULTERROR_UNKNOWNCHUNK,											//!<�`�����N���ςȈʒu�ɑ��݂���
		MOFMODEL_RESULTERROR_CHUNKENDFAULT,											//!<�`�����N�I����������Ȃ�
		MOFMODEL_RESULTERROR_UNKNOWNCHUNKEND,										//!<�`�����N�I�����ςȈʒu�ɑ��݂���

		MOFMODEL_RESULTERROR_NOTFOOTER,												//!<�t�b�^�[�łȂ��ő�T�C�Y�𒴂���
		MOFMODEL_RESULTERROR_UNKNOWNFOOTER,											//!<�t�b�^�[���ςȈʒu�ɑ��݂���
		
		MOFMODEL_RESULTERROR_VERTEXBUFFERCREATE,									//!<�o�b�t�@�̐������s
		MOFMODEL_RESULTERROR_INDEXBUFFERCREATE,										//!<�o�b�t�@�̐������s
		MOFMODEL_RESULTERROR_TEXTURELOAD,											//!<�e�N�X�`���̓ǂݍ��ݎ��s

		MOFMODEL_RESULTERROR_BONENOTFOUND,											//!<�Ή�����{�[���̌����Ɏ��s
		MOFMODEL_RESULTERROR_NOTMORPHINGTYPE,										//!<�Ή����郂�[�t�B���O�^�C�v���Ȃ�
	};

	/*******************************//*!
	@brief	���f���t�@�C���w�b�_�[�\����

			���f���t�@�C���̊�{�����i�[�����w�b�_�[�\����

	@author	CDW
	*//********************************/
	typedef struct tag_MOFMODELHEADER {
		MofBool						bStringCode;									//!<�����R�[�h(UNICODE�`���Ȃ�TRUE,�}���`�o�C�g�Ȃ�FALSE)
		MofU32						Alignment;										//!<�A���C�����g
		MofU32						BlockSize;										//!<�u���b�N�T�C�Y
		MofU32						Flag;											//!<�t�@�C�����ǉ��t���O
	}MOFMODELHEADER,*LPMOFMODELHEADER;
	
	/*******************************//*!
	@brief	�W�I���g�����[�t�B���O��

			�W�I���g�����[�t�B���O��

	@author	CDW
	*//********************************/
	typedef enum tag_MOMGEOMETRYMORPHINGTYPE {
		MOMGEOMETRYMORPHINGTYPE_VERTEXPOSITION,										//!<���_���W
	}GeometryMorphingType;
	
	/*******************************//*!
	@brief	�W�I���g�����[�t�B���O���_���W

			�W�I���g�����[�t�B���O���_���W

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOMGEOMETRYMORPHINGPOSITION {
		MofU32						Index;											//!<�C���f�b�N�X
		Vector3						Position;										//!<���_���W

		MOF_ALIGNED_NEW_OPERATOR(tag_MOMGEOMETRYMORPHINGPOSITION);
	}MOMGEOMETRYMORPHINGPOSITION;
	typedef CDynamicArray< MOMGEOMETRYMORPHINGPOSITION >		CGeometryMorphingPositionArray, *LPGeometryMorphingPositionArray;
	
	/*******************************//*!
	@brief	�v���W�F�N�V�������\����

			�v���W�F�N�V�����s��̐ݒ�ɕK�v�ȏ����i�[����\����

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOMCAMERAINFO {
		CVector3					Position;			//!<���W
		CVector3					Target;				//!<�����_
		CVector3					Up;					//!<����x�N�g��
		MofFloat					Fov;				//!<����p
		MofFloat					Aspect;				//!<�A�X�y�N�g��
		MofFloat					Width;				//!<��
		MofFloat					Height;				//!<����
		MofFloat					Near;				//!<�ߕ���
		MofFloat					Far;				//!<������

		MOF_ALIGNED_NEW_OPERATOR(tag_MOMCAMERAINFO);
	}MOMCAMERAINFO,*LPMOMCAMERAINFO;

	/*******************************//*!
	@brief	���̃W�I���g����

			���̃W�I���g����

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSGEOMETRYTYPE {
		MOMPHYSICSGEOMETRYTYPE_SPHERE,												//!<��
		MOMPHYSICSGEOMETRYTYPE_BOX,													//!<��
		MOMPHYSICSGEOMETRYTYPE_CAPSULE,												//!<�J�v�Z��
	}PhysicsGeometryType;

	/*******************************//*!
	@brief	���̃W���C���g��

			���̃W���C���g��

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSJOINTTYPE {
		MOMPHYSICSJOINTTYPE_6DOF,													//!<6DOF
	}PhysicsJointType;

	/*******************************//*!
	@brief	���̏�ԃt���O��

			���̓����ԃt���O��

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSBONEFLAG {
		MOMPHYSICSBONEFLAG_FIXED,													//!<�{�[����Ԃł̌Œ�
		MOMPHYSICSBONEFLAG_FIXEDPOSITION,											//!<�{�[����Ԃł̌Œ�(���W�̂�)
		MOMPHYSICSBONEFLAG_ACTOR,													//!<�A�N�^�[��ԗD��
		MOMPHYSICSBONEFLAG_INTERPOLATION,											//!<��Ԓ�
	}PhysicsBoneFlag;

	/*******************************//*!
	@brief	�W���C���g����t���O��

			�W���C���g����t���O��

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSJOINTAXIS {
		MOMPHYSICSJOINTAXIS_X,														//!<X
		MOMPHYSICSJOINTAXIS_Y,														//!<Y
		MOMPHYSICSJOINTAXIS_Z,														//!<Z
		MOMPHYSICSJOINTAXIS_TWIST,													//!<X
		MOMPHYSICSJOINTAXIS_SWING1,													//!<Y
		MOMPHYSICSJOINTAXIS_SWING2,													//!<Z
		MOMPHYSICSJOINTAXIS_COUNT,													//!<��
	}PhysicsJointAxis;

	/*******************************//*!
	@brief	�W���C���g����t���O��

			�W���C���g����t���O��

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSJOINTMOTION {
		MOMPHYSICSJOINTMOTION_LOCKED,												//!<���b�N
		MOMPHYSICSJOINTMOTION_LIMITED,												//!<���E�ݒ�
		MOMPHYSICSJOINTMOTION_FREE,													//!<�t���[
	}PhysicsJointMotion;
	
	/*******************************//*!
	@brief	Physics�o�l���\����

			Physics�̃o�l�ɕK�v�ȏ����܂Ƃ߂��\����

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MOMPHYSICSSPRING {
		CVector3								Stiffness;							//!<����
		CVector3								Damping;							//!<����

		tag_MOMPHYSICSSPRING() :
		Stiffness() ,
		Damping(1.0f, 1.0f, 1.0f) {
		}
	}MOMPHYSICSSPRING,*LPMOMPHYSICSSPRING;
	
	/*******************************//*!
	@brief	Physics���`���E���\����

			Physics�̐��`���E�ɕK�v�ȏ����܂Ƃ߂��\����

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MOMPHYSICSLINEARLIMIT : public MOMPHYSICSSPRING {
		CVector3								Upper;
		CVector3								Lower;

		tag_MOMPHYSICSLINEARLIMIT() :
		tag_MOMPHYSICSSPRING() ,
		Upper() ,
		Lower() {
		}
	}MOMPHYSICSLINEARLIMIT,*LPMOMPHYSICSLINEARLIMIT;
	
	/*******************************//*!
	@brief	Physics�R�[�����E���\����

			Physics�̃R�[�����E�ɕK�v�ȏ����܂Ƃ߂��\����

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MOMPHYSICSANGULARLIMIT : public MOMPHYSICSSPRING {
		CVector3								Upper;
		CVector3								Lower;

		tag_MOMPHYSICSANGULARLIMIT() :
		tag_MOMPHYSICSSPRING() ,
		Upper(),
		Lower() {
		}
	}MOMPHYSICSANGULARLIMIT,*LPMOMPHYSICSANGULARLIMIT;
	
	/*******************************//*!
	@brief	���b�V�����[�V�����{�[�����Ǘ��\����

			���b�V�����[�V�����{�[�����Ǘ��\���́B<br>
			�A�j���[�V�������̊e�{�[���̏�Ԃ��Ԃ��Ǘ����邽�߂̍\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOMPHYSICSJOINTINFO {
		/*******************//*!
		�W���C���g��
		*//********************/
		CString						JointName;
		/*******************//*!
		�W���C���g�^�C�v
		*//********************/
		PhysicsJointType			Type;
		/*******************//*!
		�Ή��{�[����
		*//********************/
		CString						BoneAName;
		/*******************//*!
		�Ή��I�t�Z�b�g
		*//********************/
		CVector3					BoneAOffset;
		/*******************//*!
		�Ή��I�t�Z�b�g
		*//********************/
		CQuaternion					BoneAOrientation;
		/*******************//*!
		�Ή��{�[����
		*//********************/
		CString						BoneBName;
		/*******************//*!
		�Ή��I�t�Z�b�g
		*//********************/
		CVector3					BoneBOffset;
		/*******************//*!
		�Ή��I�t�Z�b�g
		*//********************/
		CQuaternion					BoneBOrientation;
		/*******************//*!
		���[�V����
		*//********************/
		PhysicsJointMotion			Motion[MOMPHYSICSJOINTAXIS_COUNT];
		/*******************//*!
		���`���E
		*//********************/
		MOMPHYSICSLINEARLIMIT		LinearLimit;
		/*******************//*!
		�R�[�����E
		*//********************/
		MOMPHYSICSANGULARLIMIT		AngularLimit;
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOMPHYSICSJOINTINFO() :
		JointName() ,
		Type(MOMPHYSICSJOINTTYPE_6DOF) ,
		BoneAName() ,
		BoneAOffset() ,
		BoneAOrientation(0, 0, 0, 1) ,
		BoneBName() ,
		BoneBOffset() ,
		BoneBOrientation(0, 0, 0, 1) ,
		LinearLimit() ,
		AngularLimit() {
			Motion[MOMPHYSICSJOINTAXIS_X] = MOMPHYSICSJOINTMOTION_LOCKED;
			Motion[MOMPHYSICSJOINTAXIS_Y] = MOMPHYSICSJOINTMOTION_LOCKED;
			Motion[MOMPHYSICSJOINTAXIS_Z] = MOMPHYSICSJOINTMOTION_LOCKED;
			Motion[MOMPHYSICSJOINTAXIS_TWIST] = MOMPHYSICSJOINTMOTION_FREE;
			Motion[MOMPHYSICSJOINTAXIS_SWING1] = MOMPHYSICSJOINTMOTION_FREE;
			Motion[MOMPHYSICSJOINTAXIS_SWING2] = MOMPHYSICSJOINTMOTION_FREE;
		}
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[��

				@return			None
		*//**************************************************************************/
		tag_MOMPHYSICSJOINTINFO(const tag_MOMPHYSICSJOINTINFO& pObj) :
		JointName(pObj.JointName) ,
		Type(pObj.Type) ,
		BoneAName(pObj.BoneAName) ,
		BoneAOffset(pObj.BoneAOffset) ,
		BoneAOrientation(pObj.BoneAOrientation) ,
		BoneBName(pObj.BoneBName) ,
		BoneBOffset(pObj.BoneBOffset) ,
		BoneBOrientation(pObj.BoneBOrientation),
		LinearLimit(pObj.LinearLimit) ,
		AngularLimit(pObj.AngularLimit) {
			memcpy(Motion, pObj.Motion, sizeof(Motion));
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOMPHYSICSJOINTINFO);
	}MOMPHYSICSJOINTINFO,*LPMOMPHYSICSJOINTINFO;
	typedef CDynamicArray< LPMOMPHYSICSJOINTINFO >		CPhysicsJointInfoArray,*LPPhysicsJointInfoArray;

	/*******************************//*!
	@brief	���b�V�����[�V�����{�[�����Ǘ��\����

			���b�V�����[�V�����{�[�����Ǘ��\���́B<br>
			�A�j���[�V�������̊e�{�[���̏�Ԃ��Ԃ��Ǘ����邽�߂̍\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOMPHYSICSRIGIDINFO {
		/*******************//*!
		���̖�
		*//********************/
		CString						RigidName;
		/*******************//*!
		�������̃T�C�Y
		*//********************/
		MofBool						bAutoSize;
		/*******************//*!
		���̃T�C�Y
		*//********************/
		CVector3					RigidSize;
		/*******************//*!
		�Ή��{�[����
		*//********************/
		CString						BoneName;
		/*******************//*!
		�Ή��I�t�Z�b�g
		*//********************/
		CVector3					BoneOffset;
		/*******************//*!
		�Ή��I�t�Z�b�g
		*//********************/
		CQuaternion					BoneOrientation;
		/*******************//*!
		�O���[�v
		*//********************/
		MofU32						Group;
		/*******************//*!
		�O���[�v
		*//********************/
		MofU32						TargetGroup;
		/*******************//*!
		���C
		*//********************/
		MofFloat					Mass;
		/*******************//*!
		���C
		*//********************/
		MofFloat					LinearDamping;
		/*******************//*!
		���C
		*//********************/
		MofFloat					AngularDamping;
		/*******************//*!
		���C
		*//********************/
		MofFloat					StaticFriction;
		/*******************//*!
		���C
		*//********************/
		MofFloat					DynamicFriction;
		/*******************//*!
		����
		*//********************/
		MofFloat					Restitution;
		/*******************//*!
		�Ή��I�t�Z�b�g
		*//********************/
		MofFloat					Density;
		/*******************//*!
		���[�g�Ή�
		*//********************/
		MofBool						bRoot;
		/*******************//*!
		���
		*//********************/
		PhysicsBoneFlag				InitState;
		/*******************//*!
		��ԌŒ�
		*//********************/
		MofBool						bStateLock;
		/*******************//*!
		�e�Q��
		*//********************/
		MofBool						bParentRelation;
		/*******************//*!
		���̂̃^�C�v
		*//********************/
		PhysicsGeometryType			GeometryType;
		/*******************//*!
		�����q���̐���
		*//********************/
		MofBool						bAutoChild;
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOMPHYSICSRIGIDINFO() :
		RigidName() ,
		bAutoSize(TRUE) ,
		RigidSize(1, 1, 1) ,
		BoneName() ,
		BoneOffset() ,
		BoneOrientation(0,0,0,1) ,
		Group(0) ,
		TargetGroup(0) , 
		Mass(-1.0f) ,
		LinearDamping(0.0f) ,
		AngularDamping(0.05f) ,
		StaticFriction(0.5f) ,
		DynamicFriction(0.5f) ,
		Restitution(0.5f) ,
		Density(1.0f) ,
		bRoot(FALSE) ,
		InitState(MOMPHYSICSBONEFLAG_FIXED) ,
		bStateLock(FALSE) ,
		bParentRelation(TRUE) ,
		GeometryType(MOMPHYSICSGEOMETRYTYPE_SPHERE) ,
		bAutoChild(FALSE) {
		}
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[��

				@return			None
		*//**************************************************************************/
		tag_MOMPHYSICSRIGIDINFO(const tag_MOMPHYSICSRIGIDINFO& pObj) :
		RigidName(pObj.RigidName) ,
		bAutoSize(pObj.bAutoSize) ,
		RigidSize(pObj.RigidSize) ,
		BoneName(pObj.BoneName) ,
		BoneOffset(pObj.BoneOffset) ,
		BoneOrientation(pObj.BoneOrientation) ,
		Group(pObj.Group) ,
		TargetGroup(pObj.TargetGroup) ,
		Mass(pObj.Mass) ,
		LinearDamping(pObj.LinearDamping) ,
		AngularDamping(pObj.AngularDamping) ,
		StaticFriction(pObj.StaticFriction) ,
		DynamicFriction(pObj.DynamicFriction) ,
		Restitution(pObj.Restitution) ,
		Density(pObj.Density) ,
		bRoot(pObj.bRoot) ,
		InitState(pObj.InitState) ,
		bStateLock(pObj.bStateLock) ,
		bParentRelation(pObj.bParentRelation) ,
		GeometryType(pObj.GeometryType),
		bAutoChild(pObj.bAutoChild) {
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOMPHYSICSRIGIDINFO);
	}MOMPHYSICSRIGIDINFO,*LPMOMPHYSICSRIGIDINFO;
	typedef CDynamicArray< LPMOMPHYSICSRIGIDINFO >		CPhysicsActorInfoArray,*LPPhysicsActorInfoArray;
	
}

#endif

//[EOF]