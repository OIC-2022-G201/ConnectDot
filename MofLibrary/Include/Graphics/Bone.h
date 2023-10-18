/*************************************************************************//*!
					
					@file	Bone.h
					@brief	�{�[�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__BONE__H__

#define		__BONE__H__

//INCLUDE
#include	"MomCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�{�[���t���O��

			�{�[���ɕt���ł��铮��t���O��

	@author	CDW
	*//********************************/
	typedef enum tag_BONEFLAG {
		BONEFLAG_REVISE								=	0x00000001,				//!<�␳�v�Z
	}BoneFlag;

	/*******************************//*!
	@brief	�{�[���E�F�C�g

			�{�[���E�F�C�g�B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_BONEWEIGHT {
		/*******************//*!
		�C���f�b�N�X
		*//********************/
		MofU32					Index;
		/*******************//*!
		�E�F�C�g
		*//********************/
		MofFloat				Weight;
	}BONEWEIGHT,*LPBONEWEIGHT;
	typedef CDynamicArray< BONEWEIGHT >		CBoneWeightArray,*LPBoneWeightArray;

	/*******************************//*!
	@brief	�{�[���E�F�C�g

			�{�[���E�F�C�g�B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_GEOMETRYBONEWEIGHT : public IMofCopyObject< tag_GEOMETRYBONEWEIGHT > {
		/*******************//*!
		���O
		*//********************/
		CString					GeometryName;
		/*******************//*!
		�E�F�C�g
		*//********************/
		CBoneWeightArray		Weights;
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GEOMETRYBONEWEIGHT() :
		GeometryName() ,
		Weights() {
		}
		
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�E�F�C�g

				@return			None
		*//**************************************************************************/
		tag_GEOMETRYBONEWEIGHT(const tag_GEOMETRYBONEWEIGHT& pObj) :
		GeometryName(pObj.GeometryName) ,
		Weights(pObj.Weights) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_GEOMETRYBONEWEIGHT(){
			GeometryName.SetString(NULL);
			Weights.Release();
		}
		
		/*************************************************************************//*!
				@brief			�R�s�[�o�b�t�@�̍쐬
				@param			None

				@return			�쐬���ꂽ�R�s�[�o�b�t�@<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual tag_GEOMETRYBONEWEIGHT* CreateCopyObject(void) const{
			return new tag_GEOMETRYBONEWEIGHT(*this);
		}
	}GEOMETRYBONEWEIGHT,*LPGEOMETRYBONEWEIGHT;
	typedef CDynamicArray< LPGEOMETRYBONEWEIGHT >		CGeometryBoneWeightArray,*LPGeometryBoneWeightArray;
	
	/*******************************//*!
	@brief	�{�[���E�F�C�g

			�{�[���E�F�C�g�B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_BONEIKJOINT {
		/*******************//*!
		�Ή��{�[����
		*//********************/
		CString					Target;
		/*******************//*!
		�������a
		*//********************/
		MofFloat				Restriction;
		/*******************//*!
		�䗦
		*//********************/
		MofFloat				Weight;
		/*******************//*!
		�t���O
		*//********************/
		MofU32					Flag;
		/*******************//*!
		�����p�x
		*//********************/
		CVector3				MinRestriction;
		/*******************//*!
		�����p�x
		*//********************/
		CVector3				MinSingleRestriction;
		/*******************//*!
		�����p�x
		*//********************/
		CVector3				MaxRestriction;
		/*******************//*!
		�����p�x
		*//********************/
		CVector3				MaxSingleRestriction;
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_BONEIKJOINT() :
		Target() ,
		Restriction(MOF_MATH_2PI) ,
		Weight(1.0f) ,
		Flag(0) ,
		MinRestriction(-MOF_MATH_2PI, -MOF_MATH_2PI, -MOF_MATH_2PI) ,
		MinSingleRestriction(-MOF_MATH_2PI, -MOF_MATH_2PI, -MOF_MATH_2PI) ,
		MaxRestriction(MOF_MATH_2PI, MOF_MATH_2PI, MOF_MATH_2PI) ,
		MaxSingleRestriction(MOF_MATH_2PI, MOF_MATH_2PI, MOF_MATH_2PI) {
		}
		
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�E�F�C�g

				@return			None
		*//**************************************************************************/
		tag_BONEIKJOINT(const tag_BONEIKJOINT& pObj) :
		Target(pObj.Target) ,
		Restriction(pObj.Restriction) ,
		Weight(pObj.Weight) ,
		Flag(pObj.Flag) ,
		MinRestriction(pObj.MinRestriction) ,
		MinSingleRestriction(pObj.MinSingleRestriction) ,
		MaxRestriction(pObj.MaxRestriction) ,
		MaxSingleRestriction(pObj.MaxSingleRestriction) {
		}
		
		
		/*************************************************************************//*!
				@brief			���
		*//**************************************************************************/
		tag_BONEIKJOINT& operator = ( const tag_BONEIKJOINT& v ){
			Target = v.Target;
			Restriction = v.Restriction;
			Weight = v.Weight;
			Flag = v.Flag;
			MinRestriction = v.MinRestriction;
			MinSingleRestriction = v.MinSingleRestriction;
			MaxRestriction = v.MaxRestriction;
			MaxSingleRestriction = v.MaxSingleRestriction;
			return *this;
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_BONEIKJOINT);
	}BONEIKJOINT,*LPBONEIKJOINT;
	typedef CDynamicArray< BONEIKJOINT >		CBoneIKJointArray,*LPBoneIKJointArray;

	/*******************************//*!
	@brief	�{�[���h�j

			�{�[���h�j�B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_BONEIKINFO : public IMofCopyObject< tag_BONEIKINFO > {
		/*******************//*!
		�Ή��{�[����
		*//********************/
		CString					Target;
		/*******************//*!
		������
		*//********************/
		MofS32					Iteration;
		/*******************//*!
		�������a
		*//********************/
		MofFloat				Restriction;
		/*******************//*!
		�덷
		*//********************/
		MofFloat				Tolerance;
		/*******************//*!
		�W���C���g
		*//********************/
		CBoneIKJointArray		Joint;

		/*************************************************************************//*!
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param			None

				@return			None
		*//**************************************************************************/
		tag_BONEIKINFO() :
		Target() ,
		Iteration(5) ,
		Restriction(0.0f) ,
		Tolerance(0.01f) ,
		Joint() {
		}
		
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�E�F�C�g

				@return			None
		*//**************************************************************************/
		tag_BONEIKINFO(const tag_BONEIKINFO& pObj) :
		Target(pObj.Target) ,
		Iteration(pObj.Iteration) ,
		Restriction(pObj.Restriction) ,
		Tolerance(pObj.Tolerance) ,
		Joint(pObj.Joint) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_BONEIKINFO(){
			Target.SetString(NULL);
			Joint.Release();
		}
		
		/*************************************************************************//*!
				@brief			���
		*//**************************************************************************/
		tag_BONEIKINFO& operator = ( const tag_BONEIKINFO& v ){
			Target = v.Target;
			Iteration = v.Iteration;
			Restriction = v.Restriction;
			Tolerance = v.Tolerance;
			Joint = v.Joint;
			return *this;
		}

		/*************************************************************************//*!
				@brief			�R�s�[�o�b�t�@�̍쐬
				@param			None

				@return			�쐬���ꂽ�R�s�[�o�b�t�@<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual tag_BONEIKINFO* CreateCopyObject(void) const{
			return new tag_BONEIKINFO(*this);
		}
	}BONEIKINFO,*LPBONEIKINFO;
	typedef CDynamicArray< LPBONEIKINFO >		CBoneIKInfoArray,*LPBoneIKInfoArray;

	/*******************************//*!
	@brief	�{�[���C���^�[�t�F�C�X

			�{�[���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IBone : public IMofNamedObject , public IMofCopyObject< IBone > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ID�ݒ�
				@param[in]		id				ID
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetID(MofU32 id) = 0;
		/*************************************************************************//*!
				@brief			�t���O�ݒ�
				@param[in]		flg				�t���O
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetFlag(MofU32 flg) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ID�擾
				@param			None

				@return			ID
		*//**************************************************************************/
		virtual MofU32 GetID(void) = 0;
		/*************************************************************************//*!
				@brief			�t���O�擾
				@param			None

				@return			�t���O
		*//**************************************************************************/
		virtual MofU32 GetFlag(void) = 0;
		/*************************************************************************//*!
				@brief			�e�̖��O�擾
				@param			None

				@return			�e�̖��O
		*//**************************************************************************/
		virtual LPString GetParentName(void) = 0;
		/*************************************************************************//*!
				@brief			�ϊ��s��擾
				@param			None

				@return			�ϊ��s��
		*//**************************************************************************/
		virtual CMatrix44& GetMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			�ϊ��s��擾
				@param[out]		pos				���W�ϊ�
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool GetLocalTranslation(Vector3& pos) = 0;
		/*************************************************************************//*!
				@brief			�I�t�Z�b�g�s��擾
				@param			None

				@return			�I�t�Z�b�g�s��
		*//**************************************************************************/
		virtual CMatrix44& GetOffsetMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			�I�t�Z�b�g�s��擾
				@param			None

				@return			�I�t�Z�b�g�s��
		*//**************************************************************************/
		virtual CMatrix33& GetRotationOffsetMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			�E�F�C�g�z��擾
				@param			None

				@return			�E�F�C�g�z��
		*//**************************************************************************/
		virtual LPGeometryBoneWeightArray GetWeightsArray(void) = 0;
		/*************************************************************************//*!
				@brief			�h�j�z��擾
				@param			None

				@return			�h�j�z��
		*//**************************************************************************/
		virtual LPBoneIKInfoArray GetIKsArray(void) = 0;
	};
	
	//�|�C���^�u������
	typedef IBone*				LPBone;
	typedef CDynamicArray< LPBone >		CBoneArray,*LPBoneArray;
}

#endif	//__BONE__H__

//[EOF]