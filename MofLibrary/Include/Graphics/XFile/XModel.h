/*************************************************************************//*!
					
					@file	XModel.h
					@brief	X�t�@�C�����f���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__XMODEL__H__

#define		__XMODEL__H__

//INCLUDE
#include	"../../Common/KeyFrameArray.h"
#include	"../GraphicsCommon.h"

//DEFINE

//!X�t�@�C���̃w�b�_�[�̑傫��
#define		MOF_XFILE_HEADER_SIZE				16

//!�֘A�ő吔
#define		MOF_XFILE_MAX_RELATION				8

//!�L�[��`
#define		MOF_XFILE_ANIMATION_TRANSLATION		0x01
#define		MOF_XFILE_ANIMATION_SCALING			0x02
#define		MOF_XFILE_ANIMATION_ROTATION		0x04
#define		MOF_XFILE_ANIMATION_MATRIX			0x80

namespace Mof {
	
	/*******************************//*!
	@brief	X�t�@�C���e���v���[�g��

			X�t�@�C����ǂݍ��ނ��߂̃e���v���[�g�^�C�v�̗񋓁B

	@author	CDW
	*//********************************/
	enum tag_MOFXFILEANALYS_TEMPLATE {
		MOF_XFILE_TEMP_MESH,										//!<���b�V��
		MOF_XFILE_TEMP_MESHTEXTURECOORDS,							//!<���b�V���e�N�X�`�����W
		MOF_XFILE_TEMP_MESHNORMALS,									//!<���b�V���̖@��
		MOF_XFILE_TEMP_VERTEXCOLOR,									//!<���_�J���[
		MOF_XFILE_TEMP_MESHMATERIALLIST,							//!<���b�V���}�e���A�����X�g
		MOF_XFILE_TEMP_MATERIAL,									//!<�}�e���A��
		MOF_XFILE_TEMP_TEXTUREFILENAME,								//!<�e�N�X�`��
		MOF_XFILE_TEMP_FRAME,										//!<�t���[��
		MOF_XFILE_TEMP_FRAMETRANSFORMMATRIX,						//!<�t���[���̃��[�J���g�����X�t�H�[��
		MOF_XFILE_TEMP_ANIMATIONTICKS,								//!<�A�j���[�V�����i�s���x
		MOF_XFILE_TEMP_ANIMATION,									//!<�A�j���[�V����
		MOF_XFILE_TEMP_ANIMATIONSET,								//!<�A�j���[�V�����Z�b�g
		MOF_XFILE_TEMP_ANIMATIONKEY,								//!<�A�j���[�V�����L�[
		MOF_XFILE_TEMP_XSKINHEADER,									//!<�X�L�����b�V���̃w�b�_�[
		MOF_XFILE_TEMP_SKINWEIGHTS,									//!<�X�L�����b�V���̃E�G�C�g
		MOF_XFILE_TEMP_RELATION,									//!<�ԐڎQ��

		MOF_XFILE_TEMP_NUM,											//!<�e���v���[�g�̑���
	};
	
	/*******************************//*!
	@brief	X�t�@�C���t���[���\����

			X�t�@�C���̃t���[������ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMESHFRAME {
		CString						Name;							//!<���O
		Matrix44*					pTransformMat;					//!<�t���[���Ɋ֘A�t�����ꂽ�g�����X�t�H�[���}�g���N�X
		Matrix44					Mat;							//!<���̃t���[���̃}�g���N�X
		Matrix44					OffsetMat;						//!<�I�t�Z�b�g�s��
		Matrix44					ConvMat;						//!<�ŏI�s��
		MofU8						nChild;							//!<�q���̐�
		MofU16						ID;								//!<���ʗp�z��ԍ�
		struct tag_MOFXMESHFRAME**	pChild;							//!<�q���̃t���[��
		struct tag_MOFXMESHFRAME*	pParent;						//!<�e�̃t���[��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMESHFRAME() :
		Name() ,
		pTransformMat(NULL) ,
		Mat() ,
		OffsetMat() ,
		ConvMat() ,
		nChild(0) ,
		ID(0) ,
		pChild(NULL) ,
		pParent(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMESHFRAME(){
			MOF_SAFE_FREE(pChild,"CXModel Release");
		}
	}MOFXMESHFRAME,*LPMOFXMESHFRAME;

	/*******************************//*!
	@brief	X�t�@�C��FLOAT�L�[�\����

			X�t�@�C��FLOAT�L�[����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXFLOATKEYS {
		MofU32						nFloat;							//!<��
		MofFloat*					Fdata;							//!<float
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXFLOATKEYS() :
		nFloat(0) ,
		Fdata(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXFLOATKEYS(){
			MOF_SAFE_FREE(Fdata,"CXModel Release");
		}
	}MOFXFLOATKEYS,*LPMOFXFLOATKEYS;
	
	/*******************************//*!
	@brief	X�t�@�C��FLOAT�^�C���L�[�\����

			X�t�@�C��FLOAT�L�[�Ƃ��̎��ԏ���ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXTIMEFLOATKEYS {
		MofU32						Time;							//!<����
		MOFXFLOATKEYS				TFkeys;							//!<float�z��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXTIMEFLOATKEYS() :
		Time(0) ,
		TFkeys() {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXTIMEFLOATKEYS(){
		}
	}MOFXTIMEFLOATKEYS,*LPMOFXTIMEFLOATKEYS;

	/*******************************//*!
	@brief	X�t�@�C��UV���\����

			X�t�@�C��UV����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXTEXTURECOORDS {
		MofU32						nCoords;						//!<UV�̐�
		TextureCoords*				Coords;							//!<UV
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXTEXTURECOORDS() :
		nCoords(0) ,
		Coords(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXTEXTURECOORDS(){
			MOF_SAFE_FREE(Coords,"CXModel Release");
		}
	}MOFXTEXTURECOORDS,*LPMOFXTEXTURECOORDS;
	
	/*******************************//*!
	@brief	X�t�@�C���̖ʏ��\����

			X�t�@�C���ʏ���ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMESHFACE {
		MofU32						nFaceIndices;					//!<�ʂ̃C���f�b�N�X�̐�
		MofU32						FaceIndices[4];					//!<�ʂ̃C���f�b�N�X
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMESHFACE() :
		nFaceIndices(0) {
			memset(FaceIndices, 0, sizeof(MofU32) * 4);
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMESHFACE(){
		}
	}MOFXMESHFACE,*LPMOFXMESHFACE;
	
	/*******************************//*!
	@brief	X�t�@�C���̖@�����\����

			X�t�@�C���@������ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMESHNORMAL {
		MofU32						nNormal;						//!<�@���x�N�g���̐�
		Vector3*					Normal;							//!<�@���x�N�g��
		MofU32						nFaceNormal;					//!<�@���̃t�F�C�X�̐�
		LPMOFXMESHFACE				FaceNormal;						//!<�@���̃t�F�C�X
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMESHNORMAL() :
		nNormal(0) ,
		Normal(NULL) ,
		nFaceNormal(0) ,
		FaceNormal(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMESHNORMAL(){
			MOF_SAFE_FREE(Normal,"CXModel Release");
			MOF_SAFE_FREE(FaceNormal,"CXModel Release");
		}
	}MOFXMESHNORMAL,*LPMOFXMESHNORMAL;
	
	/*******************************//*!
	@brief	X�t�@�C���̒��_�J���[���\����

			X�t�@�C�����_�J���[����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXVERTEXCOLORKEY {
		MofU32						No;								//!<�Ή��ԍ�
		Vector4						Color;							//!<�F
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXVERTEXCOLORKEY() :
		No(0) ,
		Color() {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXVERTEXCOLORKEY(){
		}
	}MOFXVERTEXCOLORKEY,*LPMOFXVERTEXCOLORKEY;
	
	/*******************************//*!
	@brief	X�t�@�C���̒��_�J���[���\����

			X�t�@�C�����_�J���[����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXVERTEXCOLORS {
		MofU32						nVertex;						//!<���_��
		LPMOFXVERTEXCOLORKEY		Colors;							//!<���_�J���[
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXVERTEXCOLORS() :
		nVertex(0) ,
		Colors(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXVERTEXCOLORS(){
			MOF_SAFE_FREE(Colors,"CXModel Release");
		}
	}MOFXVERTEXCOLORS,*LPMOFXVERTEXCOLORS;
	
	/*******************************//*!
	@brief	X�t�@�C���̃}�e���A�����\����

			X�t�@�C���}�e���A������ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFXMATERIAL {
		CString						Name;							//!<���O
		Vector4						Diffuse;						//!<�f�B�t���[�Y
		Vector4						Ambient;						//!<�A���r�G���g
		Vector4						Emissive;						//!<�G�~�b�V�u
		Vector4						Speculer;						//!<�X�y�L�����[
		MofFloat					Power;							//!<�X�y�L�����[�p���[
		MofU8						TextureCount;					//!<�e�N�X�`����
		LPString*					pTextureName;					//!<�e�N�X�`����
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMATERIAL() :
		Name() ,
		Diffuse() ,
		Ambient() ,
		Emissive() ,
		Speculer() ,
		Power(0.0f) ,
		TextureCount(0) ,
		pTextureName(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMATERIAL(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(pTextureName,"CXModel Release");
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFXMATERIAL);
	}MOFXMATERIAL,*LPMOFXMATERIAL;
	
	/*******************************//*!
	@brief	X�t�@�C���̃}�e���A�������_�����O�I�t�Z�b�g���\����

			X�t�@�C���}�e���A�������_�����O�I�t�Z�b�g����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMATERIALOFFSET {
		MofU32						Offset;							//!<�I�t�Z�b�g
		MofU32						RenderFace;						//!<�`��t�F�C�X
		LPMofU32					pRenderIndex;					//!<�`��C���f�b�N�X
		MofU32						RenderIndexCount;				//!<�`��C���f�b�N�X��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMATERIALOFFSET() :
		Offset(0) ,
		RenderFace(0) ,
		pRenderIndex(NULL) ,
		RenderIndexCount(0) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMATERIALOFFSET(){
			MOF_SAFE_FREE(pRenderIndex,"Index");
		}
	}MOFXMATERIALOFFSET,*LPMOFXMATERIALOFFSET;
	
	/*******************************//*!
	@brief	X�t�@�C���̃}�e���A�����X�g���\����

			X�t�@�C���}�e���A�����X�g����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMATERIALLIST {
		MofU32						nMaterial;						//!<�}�e���A���̐�
		MofU32						nFace;							//!<�ʂ̐�
		MofU32*						Face;							//!<��
		LPMOFXMATERIALOFFSET		Offset;							//!<�I�t�Z�b�g
		LPMOFXMATERIAL*				Material;						//!<�֘A�t�����}�e���A��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMATERIALLIST() :
		nMaterial(0) ,
		nFace(0) ,
		Face(NULL) ,
		Offset(NULL) ,
		Material(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMATERIALLIST(){
			MOF_SAFE_FREE(Face,"CXModel Release");
			MOF_SAFE_FREE(Material,"CXModel Release");
			MOF_SAFE_DELETE_ARRAY(Offset);
		}
	}MOFXMATERIALLIST,*LPMOFXMATERIALLIST;
	
	/*******************************//*!
	@brief	X�t�@�C���̃A�j���[�V�����L�[���\����

			X�t�@�C���A�j���[�V�����L�[����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXANIMETIONKEY {
		MofU32						KeyType;						//!<�L�[�̎��
		MofU32						nKey;							//!<�L�[�̐�
		LPMOFXTIMEFLOATKEYS*		pKey;							//!<�L�[
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXANIMETIONKEY() :
		KeyType(0) ,
		nKey(0) ,
		pKey(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXANIMETIONKEY(){
			if(pKey)
			{
				for(MofU32 i = 0;i < nKey;i++)
				{
					MOF_SAFE_DELETE(pKey[i]);
				}
				MOF_SAFE_FREE(pKey,"CXModel Release");
			}
		}
	}MOFXANIMATIONKEY,*LPMOFXANIMATIONKEY;
	
	/*******************************//*!
	@brief	X�t�@�C���̃A�j���[�V�������\����

			X�t�@�C���A�j���[�V��������ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXANIMETION {
		MofU8						nAnimationKey;					//!<�A�j���[�V�����L�[��
		LPMOFXANIMATIONKEY*			pAnimKey;						//!<�֘A����A�j���[�V�����L�[
		LPMOFXMESHFRAME				pFrame;							//!<�Ή�����t���[��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXANIMETION() :
		nAnimationKey(0) ,
		pAnimKey(NULL) ,
		pFrame(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXANIMETION(){
			MOF_SAFE_FREE(pAnimKey,"CXModel Release");
		}
	}MOFXANIMATION,*LPMOFXANIMATION;
	
	/*******************************//*!
	@brief	X�t�@�C���̃A�j���[�V�����Z�b�g���\����

			X�t�@�C���A�j���[�V�����Z�b�g����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXANIMETIONSET {
		CString						Name;							//!<�A�j���[�V������
		MofU32						MaxCount;						//!<�ő�A�j���[�V�����J�E���g�l
		MofU32						nAnimation;						//!<�A�j���[�V������
		MofU32						ID;								//!<ID
		LPMOFXANIMATION*			pAnimation;						//!<�Ή�����A�j���[�V����

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXANIMETIONSET() :
		Name() ,
		MaxCount(0) ,
		nAnimation(0) ,
		ID(0) ,
		pAnimation(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXANIMETIONSET(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(pAnimation,"CXModel Release");
		}
	}MOFXANIMATIONSET,*LPMOFXANIMATIONSET;

	/*******************************//*!
	@brief	X�t�@�C���̃X�L�j���O�p�w�b�_�[���\����

			X�t�@�C���X�L�j���O�p�w�b�_�[����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXSKINHEADER {
		MofU16						nSkinWeightsVertex;				//!<�e�����󂯂钸�_
		MofU16						nSkinWeightsFace;				//!<�e�����󂯂��
		MofU16						nBones;							//!<�{�[���̐�

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXSKINHEADER() :
		nSkinWeightsVertex(0) ,
		nSkinWeightsFace(0) ,
		nBones(0) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXSKINHEADER(){
		}
	}MOFXSKINHEADER,*LPMOFXSKINHEADER;
	
	/*******************************//*!
	@brief	X�t�@�C���̃X�L�j���O�p�E�G�C�g���\����

			X�t�@�C���X�L�j���O�p�E�G�C�g����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXSKINWEIGHT {
		MofU32						Index;							//!<���_�̃C���f�b�N�X
		MofFloat					Weight;							//!<�E�G�C�g
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXSKINWEIGHT() :
		Index(0) ,
		Weight(0.0f) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXSKINWEIGHT(){
		}
	}MOFXSKINWEIGHT,*LPMOFXSKINWEIGHT;
	
	/*******************************//*!
	@brief	X�t�@�C���̃X�L�j���O�p�E�G�C�g���\����

			X�t�@�C���X�L�j���O�p�E�G�C�g����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXSKINWEIGHTS {
		CString						Name;							//!<�{�[���̖��O
		MofU32						nWeights;						//!<�E�G�C�g�̐�
		LPMOFXSKINWEIGHT			Weights;						//!<�E�G�C�g
		CMatrix44					MatrixOffset;					//!<�}�g���N�X
		LPMofVoid					pMesh;							//!<�Ή����郁�b�V��
		LPMOFXMESHFRAME				pFrame;							//!<�Ή�����t���[��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXSKINWEIGHTS() :
		Name() ,
		nWeights(0) ,
		Weights(NULL) ,
		MatrixOffset() ,
		pMesh(NULL) ,
		pFrame(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXSKINWEIGHTS(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(Weights,"CXModel Release");
		}
	}MOFXSKINWEIGHTS,*LPMOFXSKINWEIGHTS;
	
	/*******************************//*!
	@brief	X�t�@�C���̃��b�V�����\����

			X�t�@�C�����b�V������ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMESH {
		CString						Name;							//!<���O
		MofU32						nVertices;						//!<���_�̐�
		Vector3*					Vertices;						//!<���_
		MofU32						nFace;							//!<�ʂ̐�
		LPMOFXMESHFACE				Face;							//!<��

		LPMOFXTEXTURECOORDS			TCoords[MOF_XFILE_MAX_RELATION];//!<�e�N�X�`�����W
		LPMOFXMESHNORMAL			Normal;							//!<�@��
		LPMOFXVERTEXCOLORS			VColors[MOF_XFILE_MAX_RELATION];//!<���_�J���[
		LPMOFXMATERIALLIST			MaterialList;					//!<�}�e���A�����X�g
		LPMOFXMESHFRAME				Frame;							//!<�t���[��

		LPMOFXSKINHEADER			SHerder;						//!<�X�L�����b�V���̃w�b�_�[
		LPMOFXSKINWEIGHTS*			SWeights;						//!<�X�L�����b�V���̃E�G�C�g

		MofU32						nIndex;							//!<�C���f�b�N�X�̐�
		MofU32*						Index;							//!<�C���f�b�N�X
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMESH() :
		Name() ,
		nVertices(0) ,
		Vertices() ,
		nFace(0) ,
		Face(NULL) ,
		Normal(NULL) ,
		MaterialList(NULL) ,
		Frame(NULL) ,
		SHerder(NULL) ,
		SWeights(NULL) ,
		nIndex(0) ,
		Index(NULL) {
			memset(TCoords,0,sizeof(LPMOFXTEXTURECOORDS) * MOF_XFILE_MAX_RELATION);
			memset(VColors,0,sizeof(LPMOFXVERTEXCOLORS) * MOF_XFILE_MAX_RELATION);
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMESH(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(Vertices,"CXModel Release");
			MOF_SAFE_FREE(Face,"CXModel Release");
			MOF_SAFE_FREE(Index,"CXModel Release");
			MOF_SAFE_FREE(SWeights,"CXModel Release");
		}
	}MOFXMESH,*LPMOFXMESH;

	/*******************************//*!
	@brief	X�t�@�C���̃I�u�W�F�N�g���\����

			X�t�@�C���I�u�W�F�N�g����ǂݍ��ނ��߂̍\���́B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFXFILEOBJECT {
		MofU8						Type;							//!<���
		CString						Name;							//!<���O
		LPMofVoid					pData;							//!<�f�[�^
		MofS32						nChild;							//!<�q�̐�
		MofS32						nRelation;						//!<�֘A�̐�

		struct tag_MOFXFILEOBJECT*	pParents;						//!<�e
		struct tag_MOFXFILEOBJECT*	pChildFast;						//!<�擪�̎q��
		struct tag_MOFXFILEOBJECT*	pChildLast;						//!<�Ō�̎q��
		struct tag_MOFXFILEOBJECT*	pSibling;						//!<�Z��
		struct tag_MOFXFILEOBJECT*	pRelation[MOF_XFILE_MAX_RELATION];//!<�֘A�t��
		struct tag_MOFXFILEOBJECT*	pNext;							//!<��
		
		/*******************************//*!
		@brief	X�t�@�C���̃I�u�W�F�N�g�폜�p���

				X�t�@�C���I�u�W�F�N�g���폜���邽�߂̍폜�p���N���X�B

		@author	CDW
		*//********************************/
		class DeleterBase {
		public:
			virtual ~DeleterBase() {}
			virtual LPMofVoid GetData() = 0;
		};
		/*******************************//*!
		@brief	X�t�@�C���̃I�u�W�F�N�g�폜�p�e���v���[�g

				X�t�@�C���I�u�W�F�N�g���폜���邽�߂̍폜�p�e���v���[�g�N���X�B

		@author	CDW
		*//********************************/
		template< class T > class Deleter : public DeleterBase {
		public:
			T* pObj;
			Deleter(){ pObj = new T(); }
			virtual ~Deleter(){	MOF_SAFE_DELETE(pObj); }
			virtual LPMofVoid GetData(){ return pObj; }
		};

		DeleterBase*				pDataDelete;					//!<�f�[�^�폜�p

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXFILEOBJECT() :
		Type(0) ,
		Name() ,
		pData(NULL) ,
		nChild(0) ,
		nRelation(0) ,
		pParents(NULL) ,
		pChildFast(NULL) ,
		pChildLast(NULL) ,
		pSibling(NULL) ,
		pNext(NULL) {
			memset(pRelation,0,sizeof(tag_MOFXFILEOBJECT*) * MOF_XFILE_MAX_RELATION);
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_MOFXFILEOBJECT(){
			Name.SetString(NULL);
			if(pData)
			{
				MOF_SAFE_DELETE(pDataDelete);
				pData = NULL;
			}
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFXFILEOBJECT);
	}MOFXFILEOBJECT,*LPMOFXFILEOBJECT;
	
	/*******************************//*!
	@brief	X�t�@�C�����f���N���X

			X�t�@�C������ϊ����邽�߂ɏ���ۑ����邽�߂̃N���X�B
			X�t�@�C�����璼�ڂł̃����_�����O�@�\�Ȃǂ͒񋟂��Ȃ��B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CXModel : public IMofNamedObject {
	private:
		/*******************//*!
		�t�@�C����
		*//********************/
		CString						m_Name;
		/*******************//*!
		��̓I�u�W�F�N�g�擪
		*//********************/
		LPMOFXFILEOBJECT			m_pFastObj;
		/*******************//*!
		��̓I�u�W�F�N�g�Ō��
		*//********************/
		LPMOFXFILEOBJECT			m_pLastObj;
		/*******************//*!
		////�I�u�W�F�N�g�̐�
		*//********************/
		MofU32						m_ObjCount;
		/*******************//*!
		////�A�j���[�V���������邩�ǂ���
		*//********************/
		MofBool						m_AnimationFlag;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CXModel();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CXModel();
		/*************************************************************************//*!
				@brief			�I�u�W�F�N�g�̒ǉ�
				@param[in]		Type		�ǉ��I�u�W�F�N�g�^�C�v
				@param[in]		Name		�I�u�W�F�N�g��
				@param[in]		pParents	�I�u�W�F�N�g�̐e

				@return			�ǉ������I�u�W�F�N�g��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT AddObject(MofS32 Type,LPCMofChar pName,LPMOFXFILEOBJECT pParents);
		
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
				@brief			�A�j���[�V�����t���O�ݒ�
				@param[in]		Flag		�t���O�i�A�j���[�V�������܂ރ��f���̏ꍇTRUE,�܂܂Ȃ��ꍇFALSE�j
				
				@return			None
		*//**************************************************************************/
		void SetAnimationFlag(MofBool Flag);

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
				@brief			�擪�I�u�W�F�N�g�擾
				@param			None

				@return			�擪�I�u�W�F�N�g
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetFastObject(void);
		/*************************************************************************//*!
				@brief			�I�u�W�F�N�g���擾
				@param			None

				@return			�I�u�W�F�N�g��
		*//**************************************************************************/
		MofU32 GetObjectCount(void);
		/*************************************************************************//*!
				@brief			�w��^�C�v�̃I�u�W�F�N�g�擾
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g���擾����B
								�����͐擪�I�u�W�F�N�g���珇�Ԃɍs���A�ŏ��Ɍ������I�u�W�F�N�g��Ԃ�
				@param[in]		Type		��������^�C�v

				@return			���������I�u�W�F�N�g<br>
								������Ȃ������ꍇ��NULL��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetFastTypeObject(MofS32 Type);
		/*************************************************************************//*!
				@brief			�e�I�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g�擾
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g���擾����B
								������Obj�̐e�֏��ԂɌ�������A�ŏ��Ɍ������I�u�W�F�N�g��Ԃ�
				@param[in]		Type		��������^�C�v
				@param[in]		Obj			�������[�g�I�u�W�F�N�g

				@return			���������I�u�W�F�N�g<br>
								������Ȃ������ꍇ��NULL��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetParentsObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			�q�I�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g�擾
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g���擾����B
								������Obj�̎q�֏��ԂɌ�������A�ŏ��Ɍ������I�u�W�F�N�g��Ԃ�
				@param[in]		Type		��������^�C�v
				@param[in]		Obj			�������[�g�I�u�W�F�N�g

				@return			���������I�u�W�F�N�g<br>
								������Ȃ������ꍇ��NULL��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetChildObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			����K�w�I�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g�擾
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g���擾����B
								������Obj�̓���K�w�����ԂɌ�������A�ŏ��Ɍ������I�u�W�F�N�g��Ԃ�
				@param[in]		Type		��������^�C�v
				@param[in]		Obj			�������[�g�I�u�W�F�N�g

				@return			���������I�u�W�F�N�g<br>
								������Ȃ������ꍇ��NULL��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetSiblingObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			�����N�I�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g�擾
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g���擾����B
								������Obj�̃����N�����ԂɌ�������A�ŏ��Ɍ������I�u�W�F�N�g��Ԃ�
				@param[in]		Type		��������^�C�v
				@param[in]		Obj			�������[�g�I�u�W�F�N�g

				@return			���������I�u�W�F�N�g<br>
								������Ȃ������ꍇ��NULL��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetRelationObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			�e�I�u�W�F�N�g�Ɗ֘A�I�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g�擾
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g���擾����B
								������Obj�̐e�֏��ԂɌ������ꌩ����Ȃ������ꍇ
								Obj�̃����N�����ԂɌ�������B�ŏ��Ɍ������I�u�W�F�N�g��Ԃ�
				@param[in]		Type		��������^�C�v
				@param[in]		Obj			�������[�g�I�u�W�F�N�g

				@return			���������I�u�W�F�N�g<br>
								������Ȃ������ꍇ��NULL��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetParentsAndRelationObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			�q�I�u�W�F�N�g�Ɗ֘A�I�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g�擾
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g���擾����B
								������Obj�̎q�֏��ԂɌ������ꌩ����Ȃ������ꍇ
								Obj�̃����N�����ԂɌ�������B�ŏ��Ɍ������I�u�W�F�N�g��Ԃ�
				@param[in]		Type		��������^�C�v
				@param[in]		Obj			�������[�g�I�u�W�F�N�g

				@return			���������I�u�W�F�N�g<br>
								������Ȃ������ꍇ��NULL��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetChileAndRelationObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			����K�w�I�u�W�F�N�g�Ɗ֘A�I�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g�擾
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g���擾����B
								������Obj�̓���K�w�����ԂɌ������ꌩ����Ȃ������ꍇ
								Obj�̃����N�����ԂɌ�������B�ŏ��Ɍ������I�u�W�F�N�g��Ԃ�
				@param[in]		Type		��������^�C�v
				@param[in]		Obj			�������[�g�I�u�W�F�N�g

				@return			���������I�u�W�F�N�g<br>
								������Ȃ������ꍇ��NULL��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetSiblingAndRelationObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			�q�I�u�W�F�N�g�Ɗ֘A�I�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g��
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g��񋓂���B
								������Obj�̎q�AObj�̃����N�̏��ԂŌ�������BAddres�ɗ񋓌��ʂ��i�[����
				@param[in]		Type		��������^�C�v
				@param[in,out]	Addres		���O�ɗ񋓂̊i�[�ɕK�v�ȃ��������m�ۂ��Ă�������
				@param[in]		Obj			�������[�g�I�u�W�F�N�g

				@return			None
		*//**************************************************************************/
		void EnumChildAndRelationObject(MofS32 Type,void** Addres,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			�S�ẴI�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g��
								Type�Ɏw�肵���^�C�v�̃I�u�W�F�N�g��񋓂���BAddres�ɗ񋓌��ʂ��i�[����
				@param[in]		Type		��������^�C�v
				@param[in,out]	Addres		���O�ɗ񋓂̊i�[�ɕK�v�ȃ��������m�ۂ��Ă�������

				@return			None
		*//**************************************************************************/
		void EnumTypeObject(MofS32 Type,void** Addres);
		/*************************************************************************//*!
				@brief			�S�ẴI�u�W�F�N�g����w��^�C�v�Ŏw�薼�̃I�u�W�F�N�g�擾
				@param[in]		Type		��������^�C�v
				@param[in]		Name		�������閼�O

				@return			���������I�u�W�F�N�g<br>
								������Ȃ������ꍇ��NULL��Ԃ�
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetMatchNameObject(MofS32 Type,LPMofChar Name);
		/*************************************************************************//*!
				@brief			�֘A�I�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g�̐��擾
				@param[in]		Type		��������^�C�v
				@param[in]		Obj			�������[�g�I�u�W�F�N�g

				@return			�֘A�I�u�W�F�N�g���̎w��^�C�v�I�u�W�F�N�g�̐�
		*//**************************************************************************/
		MofU32 GetRelationObjectCount(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			�S�ẴI�u�W�F�N�g����w��^�C�v�̃I�u�W�F�N�g�̐��擾
				@param[in]		Type		��������^�C�v

				@return			�w��^�C�v�I�u�W�F�N�g�̐�
		*//**************************************************************************/
		MofU32 GetTypeObjectCount(MofS32 Type);
		/*************************************************************************//*!
				@brief			�S�ẴI�u�W�F�N�g����e�̂��Ȃ��I�u�W�F�N�g�̐��擾
				@param			None

				@return			�e�̂��Ȃ��I�u�W�F�N�g�̐�
		*//**************************************************************************/
		MofU32 GetNoParentFrameObjectCount(void);
		/*************************************************************************//*!
				@brief			�S�ẴI�u�W�F�N�g����e�̂��Ȃ��I�u�W�F�N�g��
								�e�̂��Ȃ��I�u�W�F�N�g��񋓂���BAddres�ɗ񋓌��ʂ��i�[����
				@param[in,out]	Addres		���O�ɗ񋓂̊i�[�ɕK�v�ȃ��������m�ۂ��Ă�������

				@return			None
		*//**************************************************************************/
		void EnumNoParentFrameObject(void** Addres);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CXModel,MOF_XMODELCLASS_ID);
	};

	//TYPEDEF
	typedef CXModel* LPXModel;

	//INLINE INCLUDE
	#include	"XModel.inl"

}

#endif	//__XMODEL_H_

//[EOF]