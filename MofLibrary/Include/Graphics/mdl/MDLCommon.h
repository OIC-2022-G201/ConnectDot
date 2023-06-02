/*************************************************************************//*!
					
					@file	MDL��{��`.h
					@brief	MDL�t�@�C���̊�{��`�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MDLCOMMON__H__

#define		__MDLCOMMON__H__

//----------------------------------
////���ʎq
//----------------------------------
#define		MBSMODEL_FILE_HEADER				"MBS MODEL VER 0.01 FILE"
#define		MBSMODEL_FILE_HEADERLEN				strlen(MBSMODEL_FILE_HEADER)

//----------------------------------
////���_�t���O
//----------------------------------
#define		MBSMODEL_VERTEXFLAG_POSITION		0x00000001						//!<���_���W
#define		MBSMODEL_VERTEXFLAG_NORMAL			0x00000002						//!<���_�@��
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS1	0x00000004						//!<���_UV
#define		MBSMODEL_VERTEXFLAG_COLOR1			0x00000008						//!<���_�J���[
#define		MBSMODEL_VERTEXFLAG_WAIT			0x00000010						//!<���_�E�F�C�g
#define		MBSMODEL_VERTEXFLAG_TANGENT			0x00000020						//!<���_�ڐ�
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS2	0x00000040						//!<���_UV
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS3	0x00000080						//!<���_UV
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS4	0x00000100						//!<���_UV
#define		MBSMODEL_VERTEXFLAG_BINORMAL		0x00000200						//!<���_�]�@��
#define		MBSMODEL_VERTEXFLAG_COLOR2			0x00000400						//!<���_�J���[
#define		MBSMODEL_VERTEXFLAG_COLOR3			0x00000800						//!<���_�J���[
#define		MBSMODEL_VERTEXFLAG_COLOR4			0x00001000						//!<���_�J���[
#define		MBSMODEL_VERTEXFLAG_POINTSIZE		0x00002000						//!<���_�|�C���g�T�C�Y
#define		MBSMODEL_VERTEXFLAG_BLENDINDICES	0x00004000						//!<���_�E�F�C�g
#define		MBSMODEL_VERTEXFLAG_COLOR			0x00001c08						//!<���_�J���[
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS	0x000001c4						//!<���_UV

//----------------------------------
////���_�J���[�ő吔
//----------------------------------
#define		MBSMODEL_VERTEX_COLORS				4								//!<���_�J���[�ő吔

//----------------------------------
////���_UV�ő吔
//----------------------------------
#define		MBSMODEL_VERTEX_TEXTURECOORDS		4								//!<UV�}�b�v�ő吔

//----------------------------------
////���_�u�����h�ő吔
//----------------------------------
#define		MBSMODEL_VERTEX_BLENDMAX			4								//!<�u�����h�ő吔

//----------------------------------
////�C���f�b�N�X�^�C�v
//----------------------------------
#define		MBSMODEL_INDEXFORMAT16				101								//!<16�r�b�g�t�H�[�}�b�g
#define		MBSMODEL_INDEXFORMAT32				102								//!<32�r�b�g�t�H�[�}�b�g

//----------------------------------
////�A�j���[�V�����t���O
//----------------------------------
#define		MBSMODEL_ANIMATION_ROTATION			0x00000000						//��]
#define		MBSMODEL_ANIMATION_SCALING			0x00000001						//�g��
#define		MBSMODEL_ANIMATION_TRANSLATION		0x00000002						//�ړ�

namespace Mof {

	//ENUM

	//----------------------------------
	////���f���`�����N�̗�
	//----------------------------------
	enum tag_MBSMODEL_TEMPLATE {
		MBSMODEL_TEMP_MESH,															//!<���b�V��
		MBSMODEL_TEMP_VERTEX,														//!<���_���
		MBSMODEL_TEMP_INDEX,														//!<�C���f�b�N�X���
		MBSMODEL_TEMP_MATERIALLIST,													//!<�}�e���A�����
		MBSMODEL_TEMP_MATERIAL,														//!<�}�e���A�����
		MBSMODEL_TEMP_TEXTURE,														//!<�e�N�X�`�����
		MBSMODEL_TEMP_SHADER,														//!<�V�F�[�_�[���
		MBSMODEL_TEMP_BONE,															//!<�{�[�����
		MBSMODEL_TEMP_BONEGROUP,													//!<�{�[���O���[�v���
		MBSMODEL_TEMP_ANIMATIONSET,													//!<�A�j���[�V�������
		MBSMODEL_TEMP_ANIMATION,													//!<�A�j���[�V�������
		MBSMODEL_TEMP_BLOCK,														//!<�u���b�N���
		MBSMODEL_TEMP_LODMODEL,														//!<�����������f�����
		MBSMODEL_TEMP_IK,															//!<IK���
		MBSMODEL_TEMP_IKJOINT,														//!<IK�ڑ����
		MBSMODEL_TEMP_RIGID,														//!<���̏��
		MBSMODEL_TEMP_RIGIDJOINT,													//!<���̐ڑ����

		MBSMODEL_TEMP_MAX,															//!<�`�����N�ő吔

		MBSMODEL_TEMP_END					=		0xffffffff,						//!<�`�����N�I��
	};
	//TYPEDEF STRUCT

	//----------------------------------
	////���f�����_
	//----------------------------------
	typedef MOF_ALIGNED16_STRUCT tag_MBSMODELVERTEX {
		Vector3							Pos;										//!<���W
		Vector3							Normal;										//!<�@��
		Vector2							UV[MBSMODEL_VERTEX_TEXTURECOORDS];			//!<�t�u
		Vector4							Color[MBSMODEL_VERTEX_COLORS];				//!<�F
		Vector3							Tangent;									//!<�ڐ�
		Vector3							BiNormal;									//!<�]�@��
		MofU8							BlendIndicesCount;							//!<�u�����h�{�[����
		MofU8							BlendIndices[MBSMODEL_VERTEX_BLENDMAX];		//!<�u�����h�C���f�b�N�X
		MofFloat						BlendWait[MBSMODEL_VERTEX_BLENDMAX];		//!<�u�����h�E�F�C�g
		MofFloat						PointSize;									//!<�|�C���g�T�C�Y

		MOF_ALIGNED_NEW_OPERATOR(tag_MBSMODELVERTEX);
	}MBSMODELVERTEX,*LPMBSMODELVERTEX;
	//���X�g�u������
	typedef CDynamicArray< MBSMODELVERTEX > MBSVERTEXLIST,*LPMBSVERTEXLIST;
	typedef	CDynamicArray< MofU32 > MBSINDEXLIST,*LPMBSINDEXLIST;

	//----------------------------------
	////���f�����_���X�g
	//----------------------------------
	typedef struct tag_MBSMODELVERTEXLIST {
		MBSVERTEXLIST					VertexList;									//!<���_���X�g
		MofU32							Flag;										//!<���_�t���O
		MofU32							Size;										//!<���_�T�C�Y
		MofU32							Usage;										//!<���_�d�l�t���O
	
		//----------------------
		////�R���X�g���N�^
		//----------------------
		tag_MBSMODELVERTEXLIST() : 
		VertexList() ,
		Flag(0) ,
		Size(0) ,
		Usage(0) {
		}
		tag_MBSMODELVERTEXLIST(const tag_MBSMODELVERTEXLIST& Obj) : 
		VertexList(Obj.VertexList) ,
		Flag(Obj.Flag) ,
		Size(Obj.Size) ,
		Usage(Obj.Usage) {
		}
		//----------------------
		////�f�X�g���N�^
		//----------------------
		virtual ~tag_MBSMODELVERTEXLIST(){
			VertexList.Release();
		}
	}MBSMODELVERTEXLIST,*LPMBSMODELVERTEXLIST;

	//----------------------------------
	////���f���C���f�b�N�X�I�t�Z�b�g
	//----------------------------------
	typedef struct tag_MBSMODELINDEXOFFSET {
		MofU32							Offset;										//!<�I�t�Z�b�g
		MofU32							RenderFaceCount;							//!<�`��ʐ�
		LPMofU32						pRenderIndex;								//!<�`��C���f�b�N�X
		MofU32							RenderIndexCount;							//!<�`��C���f�b�N�X��
		
		//----------------------
		////�f�X�g���N�^
		//----------------------
		virtual ~tag_MBSMODELINDEXOFFSET(){
			MOF_SAFE_FREE(pRenderIndex,"Index");
		}
	}MBSMODELINDEXOFFSET,*LPMBSMODELINDEXOFFSET;
	//���X�g�u������
	typedef CDynamicArray< LPMBSMODELINDEXOFFSET > MBSMODELINDEXOFFSETLIST,*LPMBSMODELINDEXOFFSETLIST;

	//----------------------------------
	////���f���C���f�b�N�X���X�g
	//----------------------------------
	typedef struct tag_MBSMODELINDEXLIST {
		MBSINDEXLIST					IndexList;									//!<�C���f�b�N�X���X�g
		MBSMODELINDEXOFFSETLIST			OffsetList;									//!<�I�t�Z�b�g���X�g
		MofU32							Usage;										//!<�C���f�b�N�X�d�l�t���O
		MofU32							Format;										//!<�C���f�b�N�X�t�H�[�}�b�g
	
		//----------------------
		////�R���X�g���N�^
		//----------------------
		tag_MBSMODELINDEXLIST() : 
		IndexList() ,
		OffsetList() ,
		Usage(0) ,
		Format(MBSMODEL_INDEXFORMAT16) {
		}
		tag_MBSMODELINDEXLIST(const tag_MBSMODELINDEXLIST& Obj) : 
		IndexList(Obj.IndexList) ,
		OffsetList(Obj.OffsetList) ,
		Usage(Obj.Usage) ,
		Format(Obj.Format) {
		}
		//----------------------
		////�f�X�g���N�^
		//----------------------
		virtual ~tag_MBSMODELINDEXLIST(){
			IndexList.Release();
			OffsetList.Release();
		}
	}MBSMODELINDEXLIST,*LPMBSMODELINDEXLIST;
	
	//----------------------------------
	////���f���}�e���A��
	//----------------------------------
	typedef MOF_ALIGNED16_STRUCT tag_MBSMATERIAL {
		CString							Name;										//!<���O
		MofS32							Blend;										//!<�u�����f�B���O
		MofS32							RenderProcess;								//!<�����_�����O�v���Z�X
		MofS32							RenderTarget;								//!<�����_�����O�^�[�Q�b�g
		Vector4							Diffuse;									//!<�f�B�t���[�Y
		Vector4							Ambient;									//!<�A���r�G���g
		Vector4							Specular;									//!<�X�y�L�����[
		Vector4							Emissive;									//!<�G�~�b�V�u
		MofFloat						Power;										//!<�p���[
		CStringArray					TexNameArray;								//!<�e�N�X�`����

		MOF_ALIGNED_NEW_OPERATOR(tag_MBSMODELVERTEX);
	}MBSMATERIAL,*LPMBSMATERIAL;
	//���X�g�u������
	typedef CDynamicArray< LPMBSMATERIAL > MBSMATERIALLIST,*LPMBSMATERIALLIST;
	
	//----------------------------------
	////���f�����b�V��
	//----------------------------------
	typedef struct tag_MBSMESH {
		MofU32							No;											//!<�z����ԍ�
		CString							Name;										//!<���O
		MBSMODELVERTEXLIST				VList;										//!<���_
		MBSMODELINDEXLIST				IList;										//!<�C���f�b�N�X
		MBSMATERIALLIST					MList;										//!<�}�e���A�����X�g
	}MBSMESH,*LPMBSMESH;
	typedef CDynamicArray< LPMBSMESH > MBSMESHLIST,*LPMBSMESHLIST;
	
	//----------------------------------
	////�{�[���E�F�C�g
	//----------------------------------
	typedef struct tag_MBSBONEWEIGHT {
		MofU16							MeshID;										//!<���b�V��ID
		MofU16							ObjectID;									//!<����ID
		MofU32							VertexIndex;								//!<���_�C���f�b�N�X
		MofFloat						Weight;										//!<�E�F�C�g
	}MBSBONEWEIGHT,*LPMBSBONEWEIGHT;
	//���X�g�u������
	typedef CDynamicArray< MBSBONEWEIGHT > MBSBONEWEIGHTLIST,*LPMBSBONEWEIGHTLIST;

//!�����o���p�T�C�Y���
#define		MBS_MODELBONESTATUS_WRITESIZE		(sizeof(MofBool) + sizeof(MofFloat) + sizeof(MofFloat))
#define		MBS_MODELBONEWEIGHTOLD_WRITESIZE	(sizeof(MofU32) + sizeof(MofFloat) + sizeof(MofU16))
#define		MBS_MODELBONEWEIGHT_WRITESIZE		(sizeof(MofU32) + sizeof(MofFloat) + sizeof(MofU16) + sizeof(MofU16))

}

#endif		//__ANALYSMDL__H__

//[EOF]