/*****************************************************************************
					
					�m�t�@�C�����n	ConvertPMX.h
					�m�����T�v�n	PMX���b�V���ϊ��N���X
					
															@author	CDW
															Since  2009.04.01
*****************************************************************************/

//ONCE
#ifndef		__CONVERTPMXMESH__H__

#define		__CONVERTPMXMESH__H__

//INCLUDE
#include	"ConvertVMD.h"

namespace Mof {

	//TYPEDEF STRUCT

	/*******************************//*!
	@brief	�o�l�w�t�@�C���w�b�_�[�\����

			�o�l�w�t�@�C���w�b�_�[�\���́B

	@author	CDW
	*//********************************/
	typedef MOFLIBRARY_API struct tag_PMXHEADER {
		char							Magic[4];								//!<pmx
		MofFloat						Version;								//!<�o�[�W����
		MofU8							FlagSize;								//!<�t���O�T�C�Y
		LPMofU8							Flag;									//!<�t���O
		char*							pModelNameJ;							//!<���f����
		char*							pModelNameE;							//!<���f����
		char*							pCommentJ;								//!<���f����
		char*							pCommentE;								//!<���f����
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMXHEADER()
		: Version(0.0f)
		, FlagSize(0)
		, Flag(NULL)
		, pModelNameJ(NULL)
		, pModelNameE(NULL)
		, pCommentJ(NULL)
		, pCommentE(NULL) {
			memset(Magic, 0, 4);
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PMXHEADER() {
			Release();
		}
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool Release(LPMofVoid pData = NULL){
			MOF_SAFE_FREE(Flag, "PMXHEADER Release");
			MOF_SAFE_FREE(pModelNameJ, "PMXHEADER Release");
			MOF_SAFE_FREE(pModelNameE, "PMXHEADER Release");
			MOF_SAFE_FREE(pCommentJ, "PMXHEADER Release");
			MOF_SAFE_FREE(pCommentE, "PMXHEADER Release");
			return TRUE;
		}
	}PMXHEADER, *LPPMXHEADER;
	
	/*******************************//*!
	@brief	�o�l�w�t�@�C�����_�\����

			�o�l�w�t�@�C�����_�\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMXVERTEX {
		Vector3							Pos;										//!<���W
		Vector3							Normal;										//!<�@��
		Vector2							UV;											//!<�t�u
		Vector4							Color[4];									//!<�F
		MofU8							BlendIndicesCount;							//!<�u�����h�{�[����
		MofU8							BlendIndices[4];							//!<�u�����h�C���f�b�N�X
		MofFloat						BlendWait[4];								//!<�u�����h�E�F�C�g

		MofU32							Index;										//!<�C���f�b�N�X

		MOF_ALIGNED_NEW_OPERATOR(tag_PMXVERTEX);
	}PMXVERTEX, *LPPMXVERTEX;
	//���X�g�u������
	typedef CDynamicArray< PMXVERTEX > PMXVERTEXLIST, *LPPMXVERTEXLIST;
	
	/*******************************//*!
	@brief	�o�l�w�t�@�C�����_���X�g�\����

			�o�l�w�t�@�C�����_���X�g�\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMXMESHVERTEX {
		PMXVERTEXLIST					VertexList;									//!<���_���X�g
		MofU32							Flag;										//!<���_�t���O
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMXMESHVERTEX() :
			VertexList(),
			Flag(0) {
		}
		tag_PMXMESHVERTEX(const tag_PMXMESHVERTEX& Obj) :
			VertexList(Obj.VertexList),
			Flag(Obj.Flag) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PMXMESHVERTEX(){
			VertexList.Release();
		}
	}PMXMESHVERTEX, *LPPMXMESHVERTEX;
	
	/*******************************//*!
	@brief	X�t�@�C���̃}�e���A�������_�����O�I�t�Z�b�g���\����

			X�t�@�C���}�e���A�������_�����O�I�t�Z�b�g����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMXMATERIALOFFSET {
		char						Name[256];						//!<���O
		MofU32						Offset;							//!<�I�t�Z�b�g
		MofU32						RenderFace;						//!<�`��t�F�C�X
		LPPMXVERTEX					pRenderVertex;					//!<�`�撸�_
		MofU32						RenderVertexCount;				//!<�`�撸�_��
		LPMofU32					pRenderIndex;					//!<�`��C���f�b�N�X
		MofU32						RenderIndexCount;				//!<�`��C���f�b�N�X��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMXMATERIALOFFSET() :
		Offset(0) ,
		RenderFace(0) ,
		pRenderVertex(NULL) ,
		RenderVertexCount(0) ,
		pRenderIndex(NULL) ,
		RenderIndexCount(0) {
			memset(Name, 0, sizeof(Name));
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_PMXMATERIALOFFSET(){
			MOF_SAFE_FREE(pRenderVertex, "pRenderVertex");
			MOF_SAFE_FREE(pRenderIndex, "pRenderIndex");
		}
	}PMXMATERIALOFFSET,*LPPMXMATERIALOFFSET;
	typedef CDynamicArray< LPPMXMATERIALOFFSET > PMXMATERIALOFFSETLIST, *LPPMXMATERIALOFFSETLIST;
	
	/*******************************//*!
	@brief	�o�l�w�t�@�C���h�j�\����

			�o�l�w�t�@�C���h�j�\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMXIKJOINT {
		MofS32							BoneID;
		Vector3							MinRestriction;
		Vector3							MaxRestriction;

		MOF_ALIGNED_NEW_OPERATOR(tag_PMXIKJOINT);
	}PMXIKJOINT,*LPPMXIKJOINT;
	typedef CDynamicArray< PMXIKJOINT > PMXIKJOINTLIST, *LPPMXIKJOINTLIST;

	/*******************************//*!
	@brief	�o�l�w�t�@�C���h�j�\����

			�o�l�w�t�@�C���h�j�\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMXIK {
		MofS32							BoneID;
		MofS32							Iteration;
		MofFloat						Restriction;
		PMXIKJOINTLIST					Joint;
	}PMXIK,*LPPMXIK;

	/*******************************//*!
	@brief	�o�l�w�t�@�C���{�[���\����

			�o�l�w�t�@�C���{�[���\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMXBONE {
		char							Name[256];
		Matrix44						GrobalTransform;
		Matrix44						LocalTransform;
		Matrix44						Offset;

		MofS32							BNo;
		MofS32							PNo;
		MofS32							MNo;
		MofU16							Flag;

		LPPMXIK							pIK;
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMXBONE() :
		GrobalTransform() ,
		LocalTransform() ,
		Offset() ,
		BNo(0) ,
		PNo(0) ,
		MNo(0) ,
		Flag(0) ,
		pIK(NULL) {
			memset(Name, 0, sizeof(Name));
		}
	}PMXBONE, *LPPMXBONE;
	//���X�g�u������
	typedef CDynamicArray< PMXBONE > PMXBONELIST, *LPPMXBONELIST;
	
	/*******************************//*!
	@brief	�o�l�w�t�@�C�����̍\����

			�o�l�w�t�@�C�����̍\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMXRIGID {
		char							Name[256];

		Vector3							Size;
		Vector3							Pos;
		Vector3							Angle;

		MofU32							BNo;
		MofU32							GNo;
		MofU32							GTNo;

		MofU32							Type;
		MofU32							PType;

		MofFloat						Mass;
		MofFloat						LinearDamping;
		MofFloat						AngularDamping;
		MofFloat						Restitution;
		MofFloat						Friction;

		MOF_ALIGNED_NEW_OPERATOR(tag_PMXRIGID);
	}PMXRIGID, *LPPMXRIGID;
	//���X�g�u������
	typedef CDynamicArray< PMXRIGID > PMXRIGIDLIST, *LPPMXRIGIDLIST;

	/*******************************//*!
	@brief	�o�l�w�t�@�C�����[�t�B���O�\����

			�o�l�w�t�@�C�����[�t�B���O�\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMXMORPHING {
		char							Name[256];
		MofU32							Count;
		MofU32							Type;
		CU32Array						Index;
		CDynamicArray< Vector3 >		Vertex;
	}PMXMORPHING, *LPPMXMORPHING;
	//���X�g�u������
	typedef CDynamicArray< LPPMXMORPHING > PMXMORPHINGLIST, *LPPMXMORPHINGLIST;
	
	//ENUM
	
	/*******************************//*!
	@brief	�w�b�_�[�t���O�z�u

	@author	CDW
	*//********************************/
	enum tag_PMXHEADERFLAG {
		PMX_HEADERFLAG_ENCODING,												//!<�G���R�[�h
		PMX_HEADERFLAG_UVCOUNT,													//!<�ǉ�UV��
		PMX_HEADERFLAG_VERTEXINDEXSIZE,											//!<���_�C���f�b�N�X�T�C�Y
		PMX_HEADERFLAG_TEXTUREINDEXSIZE,										//!<�e�N�X�`���C���f�b�N�X�T�C�Y
		PMX_HEADERFLAG_MATERIALINDEXSIZE,										//!<�}�e���A���C���f�b�N�X�T�C�Y
		PMX_HEADERFLAG_BONEINDEXSIZE,											//!<�{�[���C���f�b�N�X�T�C�Y
		PMX_HEADERFLAG_MORPHINGINDEXSIZE,										//!<���[�t�C���f�b�N�X�T�C�Y
		PMX_HEADERFLAG_RIGIDBODYINDEXSIZE,										//!<���̃C���f�b�N�X�T�C�Y

		PMX_HEADERFLAG_MAX,														//!<�ő吔
	};
	
	/*******************************//*!
	@brief	�{�[���E�F�C�g����

	@author	CDW
	*//********************************/
	enum tag_PMXWAITTYPE {
		PMX_WAITTYPE_BDEF1,														//!<BDEF1
		PMX_WAITTYPE_BDEF2,														//!<BDEF2
		PMX_WAITTYPE_BDEF4,														//!<BDEF4
		PMX_WAITTYPE_SDEF,														//!<SDEF
		PMX_WAITTYPE_QDEF,														//!<QDEF

		PMX_WAITTYPE_MAX,														//!<�ő吔
	};

	/*******************************//*!
	@brief	�{�[���t���O

	@author	CDW
	*//********************************/
	enum tag_PMXBONEFLAG {
		PMX_BONEFLAG_CONNECT							=				0x0001,	//!<�ڑ�
		PMX_BONEFLAG_ROTATIONENABLE						=				0x0002,	//!<��]�\
		PMX_BONEFLAG_TRANSLATIONENABLE					=				0x0004,	//!<�ړ��\
		PMX_BONEFLAG_VISIBLE							=				0x0008,	//!<�\��
		PMX_BONEFLAG_ACTIONENABLE						=				0x0010,	//!<�����
		PMX_BONEFLAG_IKENABLE							=				0x0020,	//!<IK
		PMX_BONEFLAG_ROTATIONEFFECT						=				0x0100,	//!<��]�t�^
		PMX_BONEFLAG_TRANSLATIONEFFECT					=				0x0200,	//!<�ړ��t�^
		PMX_BONEFLAG_AXISFIXED							=				0x0400,	//!<���Œ�
		PMX_BONEFLAG_AXISLOCAL							=				0x0800,	//!<���[�J����
		PMX_BONEFLAG_PHYSICSMORPHING					=				0x1000,	//!<������ό`
		PMX_BONEFLAG_PARENTMORPHING						=				0x2000,	//!<�O���e�ό`

		PMX_BONEFLAG_MAX								=				0x3FFF,	//!<�ő吔
	};

	/*******************************//*!
	@brief	���[�t�B���O�^�C�v

	@author	CDW
	*//********************************/
	enum tag_PMXMORPHINGTYPE {
		PMX_MORPHINGTYPE_GROUP,													//!<�O���[�v
		PMX_MORPHINGTYPE_VERTEX,												//!<���_
		PMX_MORPHINGTYPE_BONE,													//!<�{�[��
		PMX_MORPHINGTYPE_UV,													//!<�t�u
		PMX_MORPHINGTYPE_APPENDUV1,												//!<�ǉ��t�u
		PMX_MORPHINGTYPE_APPENDUV2,												//!<�ǉ��t�u
		PMX_MORPHINGTYPE_APPENDUV3,												//!<�ǉ��t�u
		PMX_MORPHINGTYPE_APPENDUV4,												//!<�ǉ��t�u
		PMX_MORPHINGTYPE_MATERIAL,												//!<�ގ�
		PMX_MORPHINGTYPE_FLIP,													//!<�t���b�v
		PMX_MORPHINGTYPE_IMPULSE,												//!<�C���p���X

		PMX_MORPHINGTYPE_MAX,													//!<�ő吔
	};

	/*******************************//*!
	@brief	���[�t�B���O�^�C�v

	@author	CDW
	*//********************************/
	enum tag_PMXVIEWTYPE {
		PMX_VIEWTYPE_BONE,														//!<�{�[��
		PMX_VIEWTYPE_MORPHING,													//!<���[�t�B���O

		PMX_VIEWTYPE_MAX,														//!<�ő吔
	};
	
	/*******************************//*!
	@brief	�o�l�w�t�@�C�����̌`��

			�o�l�w�t�@�C�����̌`��B

	@author	CDW
	*//********************************/
	enum tag_PMXRIGIDBODYSHAPE {
		PMXRIGIDBODYSHAPE_SPHERE,												//!<��
		PMXRIGIDBODYSHAPE_BOX,													//!<��
		PMXRIGIDBODYSHAPE_CAPSULE,												//!<�J�v�Z��
	};
	/*******************************//*!
	@brief	�o�l�w�t�@�C�����̌`��

			�o�l�w�t�@�C�����̌`��B

	@author	CDW
	*//********************************/
	enum tag_PMXRIGIDBODYRELATION {
		PMXRIGIDBODYRELATIONTYPE_RELATION,										//!<�Q�ƗD��
		PMXRIGIDBODYRELATIONTYPE_RIGID,											//!<�������Z
		PMXRIGIDBODYRELATIONTYPE_RELATIONPOSITION,								//!<�Q�ƗD��i���W�̂݁j
	};
	/*******************************//*!
	@brief	�W���C���g�^�C�v

	@author	CDW
	*//********************************/
	enum tag_PMXJOINTTYPE {
		PMX_JOINTTYPE_SPRING6DOF,												//!<6DOF
		PMX_JOINTTYPE_6DOF,														//!<6DOF
		PMX_JOINTTYPE_P2P,														//!<P2P
		PMX_JOINTTYPE_CONETWIST,												//!<�R�[���c�C�X�g
		PMX_JOINTTYPE_SLIDER,													//!<�X���C�_�[
		PMX_JOINTTYPE_HINGE,													//!<�q���W

		PMX_JOINTTYPE_MAX,														//!<�ő吔
	};

	//CLASS
	
	/*******************************//*!
	@brief	�o�l�w�t�@�C���ϊ�

			�o�l�w�t�@�C���ϊ��B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertPMX : public CWriteChunkFile {
	private:
		/*******************//*!
		�t�@�C���w�b�_�[
		*//********************/
		LPPMXHEADER						m_pHeader;
		/*******************//*!
		�ǂݍ��݃t�@�C��
		*//********************/
		LPReadBinaryFile				m_pFile;
		/*******************//*!
		���[�t�B���O
		*//********************/
		PMXMORPHINGLIST					m_Morphing;
		
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(void);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pVertex		���_

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertVertex(LPPMXMESHVERTEX pVertex);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pIndex		�C���f�b�N�X

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertFace(LPU32Array pIndex);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pTexture	�e�N�X�`��

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertTexture(LPStringArray pTexture);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pVertex		���_
				@param[in]		pIndex		�C���f�b�N�X
				@param[in]		pTexture	�e�N�X�`��
				@param[in]		pMO			�}�e���A���I�t�Z�b�g

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMaterial(LPPMXMESHVERTEX pVertex,LPU32Array pIndex,LPStringArray pTexture, LPPMXMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pVertex				���_
				@param[in]		Flag				�t���O
				
				@return			TRUE				����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertGeometryVertex(LPPMXVERTEX pVertex, MofU32 Flag);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pMorphing	���[�t�B���O
				@param[in]		pVertex		���_
				@param[in]		pIndex		�C���f�b�N�X
				@param[in]		pMO			�}�e���A���I�t�Z�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMorphing(LPPMXMORPHING pMorphing, LPPMXMESHVERTEX pVertex, LPU32Array pIndex, LPPMXMATERIALOFFSET pMO);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pBone		�{�[��
				@param[in]		pMO			�}�e���A���I�t�Z�b�g

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertBone(LPPMXBONELIST pBone, LPPMXMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pBone		�{�[��
				@param[in]		pMO			�}�e���A���I�t�Z�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertWeight(LPPMXBONE pBone, LPPMXMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMorphing(void);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertView(void);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pBone		�{�[��
				@param[in]		pRigid		����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertRigidBody(LPPMXBONELIST pBone, LPPMXRIGIDLIST pRigid);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pRigid		����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertJoint(LPPMXRIGIDLIST pRigid);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertSoftBody(void);

		/*************************************************************************//*!
				@brief			�w�b�_�[�ǂݍ���
				@param[in]		pData			�ǂݍ��݃w�b�_�|

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool ReadHeader(LPPMXHEADER pData);
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�ǂݍ���
				@param[in]		Size			�T�C�Y

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofS32 ReadIndex(MofU8 Size);
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�ǂݍ���
				@param[in]		Size			�T�C�Y

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofU32 ReadIndexU(MofU8 Size);
		/*************************************************************************//*!
				@brief			������ǂݍ���
				@param[in]		Enc				�G���R�[�h

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		char* ReadStringEncode(MofU8 Enc);
		/*************************************************************************//*!
				@brief			���[�t�B���O�ǂݍ���
				@param			None

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool ReadMorphing(void);
		/*************************************************************************//*!
				@brief			������ǂݔ�΂�
				@param[in]		Enc				�G���R�[�h

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool SkipStringEncode(MofU8 Enc);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertPMX();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertPMX();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pInName		���̓t�@�C����
				@param[in]		pOutName	�o�̓t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPCMofChar pOutName);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CConvertPMX, MOF_CONVERTPMXCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertPMX.inl"

}

#endif	//__CONVERTPMXMESH__H__

//[EOF]