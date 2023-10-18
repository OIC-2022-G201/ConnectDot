/*****************************************************************************
					
					�m�t�@�C�����n	ConvertPMD.h
					�m�����T�v�n	PMD���b�V���ϊ��N���X

															Author �_�c�@��
															Since  2009.04.01
*****************************************************************************/

//ONCE
#ifndef		__CONVERTPMDMESH__H__

#define		__CONVERTPMDMESH__H__

//INCLUDE
#include	"ConvertVMD.h"

namespace Mof {

	//TYPEDEF STRUCT

	/*******************************//*!
	@brief	�o�l�c�t�@�C���w�b�_�[�\����

			�o�l�c�t�@�C���w�b�_�[�\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMDHEADER {
		char							Magic[3];								//!<pmd
		MofFloat						Version;								//!<�o�[�W����
		char							Name[21];								//!<���O
		char							Comment[257];							//!<�R�����g
		char							EName[21];								//!<���O(�p��)
		char							EComment[257];							//!<�R�����g(�R�����g)
		MofU32							ExpressionCount;						//!<�\�
		MofU32							BoneFrameCount;							//!<�{�[���g��
	}PMDHEADER,*LPPMDHEADER;
	
	/*******************************//*!
	@brief	�o�l�c�t�@�C�����_�\����

			�o�l�c�t�@�C�����_�\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMDVERTEX {
		Vector3							Pos;										//!<���W
		Vector3							Normal;										//!<�@��
		Vector2							UV;											//!<�t�u
		Vector4							Color[4];									//!<�F
		MofU8							BlendIndicesCount;							//!<�u�����h�{�[����
		MofU8							BlendIndices[2];							//!<�u�����h�C���f�b�N�X
		MofFloat						BlendWait[2];								//!<�u�����h�E�F�C�g

		MofU32							Index;										//!<���ԍ�

		MOF_ALIGNED_NEW_OPERATOR(tag_PMDVERTEX);
	}PMDVERTEX, *LPPMDVERTEX;
	//���X�g�u������
	typedef CDynamicArray< PMDVERTEX > PMDVERTEXLIST, *LPPMDVERTEXLIST;
	
	/*******************************//*!
	@brief	�o�l�c�t�@�C�����_���X�g�\����

			�o�l�c�t�@�C�����_���X�g�\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMDMESHVERTEX {
		PMDVERTEXLIST					VertexList;									//!<���_���X�g
		MofU32							Flag;										//!<���_�t���O
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMDMESHVERTEX() :
			VertexList(),
			Flag(0) {
		}
		tag_PMDMESHVERTEX(const tag_PMDMESHVERTEX& Obj) :
			VertexList(Obj.VertexList),
			Flag(Obj.Flag) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PMDMESHVERTEX(){
			VertexList.Release();
		}
	}PMDMESHVERTEX, *LPPMDMESHVERTEX;
	
	/*******************************//*!
	@brief	X�t�@�C���̃}�e���A�������_�����O�I�t�Z�b�g���\����

			X�t�@�C���}�e���A�������_�����O�I�t�Z�b�g����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMDMATERIALOFFSET {
		char						Name[256];						//!<���O
		MofU32						Offset;							//!<�I�t�Z�b�g
		MofU32						RenderFace;						//!<�`��t�F�C�X
		LPPMDVERTEX					pRenderVertex;					//!<�`�撸�_
		MofU32						RenderVertexCount;				//!<�`�撸�_��
		LPMofU32					pRenderIndex;					//!<�`��C���f�b�N�X
		MofU32						RenderIndexCount;				//!<�`��C���f�b�N�X��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMDMATERIALOFFSET() :
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
		~tag_PMDMATERIALOFFSET(){
			MOF_SAFE_FREE(pRenderVertex, "pRenderVertex");
			MOF_SAFE_FREE(pRenderIndex, "pRenderIndex");
		}
	}PMDMATERIALOFFSET,*LPPMDMATERIALOFFSET;
	typedef CDynamicArray< LPPMDMATERIALOFFSET > PMDMATERIALOFFSETLIST, *LPPMDMATERIALOFFSETLIST;
	
	/*******************************//*!
	@brief	�o�l�c�t�@�C���{�[���\����

			�o�l�c�t�@�C���{�[���\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMDBONE {
		char							Name[24];
		Matrix44						GrobalTransform;
		Matrix44						LocalTransform;
		Matrix44						Offset;

		MofS32							BNo;
		MofS32							PNo;
		MofU16							TNo;
		MofU8							Type;
		MofU16							IKNo;
	}PMDBONE, *LPPMDBONE;
	//���X�g�u������
	typedef CDynamicArray< PMDBONE > PMDBONELIST, *LPPMDBONELIST;
	
	/*******************************//*!
	@brief	�o�l�c�t�@�C�����̍\����

			�o�l�c�t�@�C�����̍\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMDRIGID {
		char							Name[24];

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

		MOF_ALIGNED_NEW_OPERATOR(tag_PMDRIGID);
	}PMDRIGID, *LPPMDRIGID;
	//���X�g�u������
	typedef CDynamicArray< PMDRIGID > PMDRIGIDLIST, *LPPMDRIGIDLIST;
	
	/*******************************//*!
	@brief	�o�l�c�t�@�C�����[�t�B���O�\����

			�o�l�c�t�@�C�����[�t�B���O�\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_PMDMORPHING {
		char							Name[24];
		MofU32							Count;
		MofU32							Type;
		CU32Array						Index;
		CDynamicArray< Vector3 >		Vertex;
	}PMDMORPHING, *LPPMDMORPHING;
	//���X�g�u������
	typedef CDynamicArray< LPPMDMORPHING > PMDMORPHINGLIST, *LPPMDMORPHINGLIST;

	/*******************************//*!
	@brief	�o�l�c�t�@�C�����̌`��

			�o�l�c�t�@�C�����̌`��B

	@author	CDW
	*//********************************/
	enum tag_PMDRIGIDBODYSHAPE {
		PMDRIGIDBODYSHAPE_SPHERE,												//!<��
		PMDRIGIDBODYSHAPE_BOX,													//!<��
		PMDRIGIDBODYSHAPE_CAPSULE,												//!<�J�v�Z��
	};
	/*******************************//*!
	@brief	�o�l�c�t�@�C�����̌`��

			�o�l�c�t�@�C�����̌`��B

	@author	CDW
	*//********************************/
	enum tag_PMDRIGIDBODYRELATION {
		PMDRIGIDBODYRELATIONTYPE_RELATION,										//!<�Q�ƗD��
		PMDRIGIDBODYRELATIONTYPE_RIGID,											//!<�������Z
		PMDRIGIDBODYRELATIONTYPE_RELATIONPOSITION,								//!<�Q�ƗD��i���W�̂݁j
	};

	//CLASS
	/*******************************//*!
	@brief	�o�l�c�t�@�C���ϊ�

			�o�l�c�t�@�C���ϊ��B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertPMD : public CWriteChunkFile {
	private:
		/*******************//*!
		�t�@�C���w�b�_�[
		*//********************/
		LPPMDHEADER						m_pHeader;
		/*******************//*!
		�ǂݍ��݃t�@�C��
		*//********************/
		LPReadBinaryFile				m_pFile;
		/*******************//*!
		�ǂݍ��݃t�@�C��
		*//********************/
		LPReadTextFile					m_pMaterialFile;
		/*******************//*!
		���[�t�B���O
		*//********************/
		PMDMORPHINGLIST					m_Morphing;
		
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
		MofBool ConvertVertex(LPPMDMESHVERTEX pVertex);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pIndex		�C���f�b�N�X

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertFace(LPU32Array pIndex);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pVertex		���_
				@param[in]		pIndex		�C���f�b�N�X
				@param[in]		pMO			�}�e���A���I�t�Z�b�g

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMaterial(LPPMDMESHVERTEX pVertex, LPU32Array pIndex, LPPMDMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pVertex				���_
				@param[in]		Flag				�t���O
				
				@return			TRUE				����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertGeometryVertex(LPPMDVERTEX pVertex, MofU32 Flag);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pMorphing	���[�t�B���O
				@param[in]		pVertex		���_
				@param[in]		pIndex		�C���f�b�N�X
				@param[in]		pMO			�}�e���A���I�t�Z�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMorphing(LPPMDMORPHING pMorphing, LPPMDMESHVERTEX pVertex, LPU32Array pIndex, LPPMDMATERIALOFFSET pMO);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pBone		�{�[��
				@param[in]		pMO			�}�e���A���I�t�Z�b�g

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertBone(LPPMDBONELIST pBone, LPPMDMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pBone		�{�[��
				@param[in]		pMO			�}�e���A���I�t�Z�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertWeight(LPPMDBONE pBone, LPPMDMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pBone		�{�[��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertIK(LPPMDBONELIST pBone);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertExpression(void);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertExpressionViewList(void);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertBoneFrameList(void);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertBoneViewList(void);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pBone		�{�[��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertEnglishName(LPPMDBONELIST pBone);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertToonTexture(void);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pBone		�{�[��
				@param[in]		pRigid		����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertRigidBody(LPPMDBONELIST pBone, LPPMDRIGIDLIST pRigid);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pRigid		����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertJoint(LPPMDRIGIDLIST pRigid);

		/*************************************************************************//*!
				@brief			�w�b�_�[�ǂݍ���
				@param[in]		pData			�ǂݍ��݃w�b�_�|

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool ReadHeader(LPPMDHEADER pData);
		/*************************************************************************//*!
				@brief			���[�t�B���O�ǂݍ���
				@param			None

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool ReadMorphing(void);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertPMD();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertPMD();
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
		MOF_LIBRARYCLASS_NOTCOPY(CConvertPMD, MOF_CONVERTPMDCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertPMD.inl"

}

#endif	//__CONVERTPMDMESH__H__

//[EOF]