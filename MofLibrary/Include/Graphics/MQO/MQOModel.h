/*************************************************************************//*!
					
					@file	MQOModel.h
					@brief	MQO�t�@�C�����f���N���X�B

															@author	CDW
															@date	2015.12.14
*//**************************************************************************/

//ONCE
#ifndef		__MQOMODEL__H__

#define		__MQOMODEL__H__

//INCLUDE
#include	"../../Common/KeyFrameArray.h"
#include	"../GraphicsCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MQO�t�@�C���̃}�e���A���\����

			MQO�t�@�C���̃}�e���A���\����

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFMQOMATERIAL {
		CString		Name;					//<!�ގ���
		MofBool		VCol;					//<!���_�J���[
		Vector4		Color;					//<!�F
		MofFloat	Diffuse;				//<!�g�U��
		Vector3		Ambient;				//<!���͌�
		Vector3		Emissive;				//<!���ȏƖ�
		Vector3		Speculer;				//<!���ˌ�
		MofFloat	Power;					//<!���ˌ��̋���
		CString		Texture;				//<!�͗l�}�b�s���O��
		CString		AlphaTex;				//<!�����}�b�s���O��
		CString		BumpTex;				//<!���ʃ}�b�s���O��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOMATERIAL():
			Name("") ,
			VCol(FALSE) ,
			Color(1,1,1,1) ,
			Diffuse(0.8f) ,
			Ambient(0.6f,0.6f,0.6f) ,
			Emissive(0,0,0) ,
			Speculer(0,0,0) ,
			Power(5) ,
			Texture("") ,
			AlphaTex("") ,
			BumpTex("") {
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFMQOMATERIAL);
	}MOFMQOMATERIAL,*LPMOFMQOMATERIAL;
	typedef CDynamicArray<LPMOFMQOMATERIAL> MOFMQOMATERIALARRAY,*LPMOFMQOMATERIALARRAY;
	
	/*******************************//*!
	@brief	MQO�t�@�C���̖ʒ��_�\����

			MQO�t�@�C���̖ʂ��\�����钸�_�̍\����

	@author	CDW
	*//********************************/
	typedef struct tag_MOFMQOFACEVERTEX {
		MofU32		Index;					//<!���_�C���f�b�N�X
		Vector2		UV;						//<!UV�l
		MofU32		Color;					//<!���_�J���[

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOFACEVERTEX() :
			Index() ,
			UV(0,0) ,
			Color(0xFFFFFFFF) {
		}
	}MOFMQOFACEVERTEX,*LPMOFMQOFACEVERTEX;
	
	/*******************************//*!
	@brief	MQO�t�@�C���̖ʍ\����

			MQO�t�@�C���̖ʍ\����

	@author	CDW
	*//********************************/
	typedef struct tag_MOFMQOFACE {
		MofU32				VertCount;		//<!���_��
		LPMOFMQOFACEVERTEX	pVertices;		//<!���_�z��
		MofU32				Material;		//<!�ގ��C���f�b�N�X

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOFACE() :
			VertCount(0) ,
			pVertices(NULL) ,
			Material(0) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFMQOFACE(){
			MOF_SAFE_DELETE_ARRAY(pVertices);
		}
	}MOFMQOFACE,*LPMOFMQOFACE;
	
	/*******************************//*!
	@brief	MQO�t�@�C���̃I�u�W�F�N�g�\����

			MQO�t�@�C���̃I�u�W�F�N�g�\����

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFMQOOBJECT {
		CString			Name;				//<!�I�u�W�F�N�g��
		MofU32			Depth;				//<!�K�w�̐[��
		Vector3			Scale;				//<!���[�J�����W�̊g�嗦
		Vector3			Rotation;			//<!���[�J�����W�̉�]�p
		Vector3			Translation;		//<!���[�J�����W�̕��s�ړ���
		MofU32			Visible;			//<!�\���E��\��
		MofU32			Shading;			//<!�V�F�[�f�B���O
		MofFloat		Facet;				//<!�X���[�W���O�p�x
		MofU32			Mirror;				//<!���ʂ̃^�C�v
		MofU32			MirrorAxis;			//<!���ʂ̓K�p��
		MofFloat		MirrorDistance;		//<!�ڑ�����
		MofU32			VertCount;			//<!���_��
		Vector3*		pVertices;			//<!���_�z��
		MofU32			FaceCount;			//<!�ʐ�
		LPMOFMQOFACE	pFaces;				//<!�ʔz��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOOBJECT():
			Name("") ,
			Depth(0) ,
			Scale(1,1,1) ,
			Rotation(0,0,0) ,
			Translation(0,0,0) ,
			Visible(15) ,
			Shading(0) ,
			Facet(59.5f) ,
			Mirror(0) ,
			MirrorAxis(0) ,
			MirrorDistance(-1) ,
			VertCount(0) ,
			pVertices(NULL) ,
			FaceCount(0) ,
			pFaces(NULL){
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFMQOOBJECT(){
			MOF_SAFE_DELETE_ARRAY(pVertices);
			MOF_SAFE_DELETE_ARRAY(pFaces);
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFMQOOBJECT);
	}MOFMQOOBJECT,*LPMOFMQOOBJECT;
	typedef CDynamicArray<LPMOFMQOOBJECT> MOFMQOOBJECTARRAY,*LPMOFMQOOBJECTARRAY;
	
	/*******************************//*!
	@brief	MQO�t�@�C���̒��_�ϊ��p���ԃf�[�^�\����

			MQO�t�@�C�����璸�_��ϊ�����ۂ̒��ԃf�[�^�\����

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFMQOTEMPVERTEX {
		Vector3		Pos;					//<!���W
		Vector3		Normal;					//<!�@��
		Vector2		UV;						//<!UV
		MofU32		Color;					//<!���_�J���[

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOTEMPVERTEX():
			Pos(0,0,0) ,
			Normal(0,0,0) ,
			UV(0,0) ,
			Color(0xffffffff) {
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFMQOTEMPVERTEX);
	}MOFMQOTEMPVERTEX,*LPMOFMQOTEMPVERTEX;
	typedef const MOFMQOTEMPVERTEX* LPCMOFMQOTEMPVERTEX;
	typedef CDynamicArray<LPMOFMQOTEMPVERTEX> MOFMQOTEMPVERTEXARRAY,*LPMOFMQOTEMPVERTEXARRAY;

	/*******************************//*!
	@brief	MQO�t�@�C���̖ʕϊ��p���ԃf�[�^�\����

			MQO�t�@�C������ʂ�ϊ�����ۂ̒��ԃf�[�^�\����

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFMQOTEMPFACE {
		MofU32				VertCount;		//<!���_��
		LPMOFMQOTEMPVERTEX	pVertices;		//<!���_�z��
		Vector3				AvgNormal;		//<!���ϖ@��
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOTEMPFACE() :
			VertCount(0) ,
			pVertices(NULL) ,
			AvgNormal(0,0,0) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFMQOTEMPFACE(){
			MOF_SAFE_DELETE_ARRAY(pVertices);
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFMQOTEMPFACE);
	}MOFMQOTEMPFACE,*LPMOFMQOTEMPFACE;
	typedef CDynamicArray<LPMOFMQOTEMPFACE> MOFMQOTEMPGEOMETRY,*LPMOFMQOTEMPGEOMETRY;
	typedef CDynamicArray<LPMOFMQOTEMPGEOMETRY> MOFMQOTEMPGEOMETRYARRAY,*LPMOFMQOTEMPGEOMETRYARRAY;

	/*******************************//*!
	@brief	MQO�t�@�C�����f���N���X

			MQO�t�@�C������ϊ����邽�߂ɏ���ۑ����邽�߂̃N���X�B
			MQO�t�@�C�����璼�ڂł̃����_�����O�@�\�Ȃǂ͒񋟂��Ȃ��B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMQOModel : public IMofNamedObject {
	private:
		/*******************//*!
		�t�@�C����
		*//********************/
		CString						m_Name;
		/*******************//*!
		�}�e���A���z��
		*//********************/
		MOFMQOMATERIALARRAY			m_Materials;
		/*******************//*!
		�I�u�W�F�N�g�z��
		*//********************/
		MOFMQOOBJECTARRAY			m_Objects;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CMQOModel();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CMQOModel();
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CMQOModel::Release(LPMofVoid pData = NULL);
		
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
				@brief			�}�e���A���z��擾
				@param			None

				@return			�}�e���A���z��̎擾
		*//**************************************************************************/
		virtual LPMOFMQOMATERIALARRAY GetMaterials(void);
		/*************************************************************************//*!
				@brief			�I�u�W�F�N�g�z��擾
				@param			None

				@return			�I�u�W�F�N�g�z��̎擾
		*//**************************************************************************/
		virtual LPMOFMQOOBJECTARRAY GetObjects(void);
		/*************************************************************************//*!
				@brief			�I�u�W�F�N�g���Ŏg���Ă�}�e���A���̃C���f�b�N�X�ꗗ�擾
				@param[in]		index		�ΏۃI�u�W�F�N�g�̃C���f�b�N�X
				@param[out]		out			�C���f�b�N�X�̏o�͔z��

				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool GetObjectMaterialList(MofU32 index,CDynamicArray<MofU32>& out);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CMQOModel,MOF_MQOMODELCLASS_ID);
	};
	
	//TYPEDEF
	typedef CMQOModel* LPMQOModel;

	//INLINE INCLUDE
	#include	"MQOModel.inl"
}

#endif	//__MQOMODEL__H__

//[EOF]
