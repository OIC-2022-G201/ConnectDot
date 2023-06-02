/*************************************************************************//*!
					
					@file	DX11ShaderBind_SkinGeometryBase.h
					@brief	��{�v���~�e�B�u�V�F�[�_�[�o�C���h�B<br>
							�W���I�ȃv���~�e�B�u�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_SKINGEOMETRYBASEBASE__H__

#define		__DX11SHADERBIND_SKINGEOMETRYBASEBASE__H__

//INCLUDE
#include	"../ShaderBindBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�V�F�[�_�[�o�C���h���C���^�[�t�F�C�X

			�V�F�[�_�[�̂��߂̃o�b�t�@�̐ݒ���s���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_SkinGeometryBase : public CShaderBindBase { 
	public:
		/*******************************//*!
		@brief	�W�I���g���`����͒��_�o�b�t�@��

		@author	CDW
		*//********************************/
		enum VertexAttribute
		{
			ATTRIBUTE_POSITION,
			ATTRIBUTE_NORMAL,
			ATTRIBUTE_TEXCOORDS,
			ATTRIBUTE_COLOR,
			ATTRIBUTE_BLENDWEIGHT,
			ATTRIBUTE_BLENDINDICES,

			ATTRIBUTE_COUNT,
		};		  
		/*******************************//*!
		@brief	�W�I���g���`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_SCENE,
			PARAM_MESH,
			PARAM_MATERIAL,
			PARAM_LIGHT,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�v���~�e�B�u�`��V�[�������̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstSceneParam
		{
			Vector4		vecViewPos;
			Matrix44	mtxView;
			Matrix44	mtxProj;
		};
		/*******************//*!
		�v���~�e�B�u�`��V�[�����ݒ�
		*//********************/
		ConstSceneParam							m_SceneParam;
		/*******************************//*!
		@brief	�v���~�e�B�u�`��v���~�e�B�u�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstMeshParam
		{
			MofFloat	mtxWorld[4 * 3 * 128];
			Vector4		colRevise;
			Vector4		CoordsRevise;
		};
		/*******************//*!
		�v���~�e�B�u�`��v���~�e�B�u���ݒ�
		*//********************/
		ConstMeshParam							m_MeshParam;
		/*******************************//*!
		@brief	�v���~�e�B�u�`��}�e���A�������̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstMaterialParam
		{
			Vector4		matDiffuse;
			Vector4		matAmbient;
			Vector4		matSpeculer;
			Vector4		matEmissive;
			MofFloat	matPower;
		};
		/*******************//*!
		�v���~�e�B�u�`��}�e���A�����ݒ�
		*//********************/
		ConstMaterialParam						m_MaterialParam;
		/*******************************//*!
		@brief	�v���~�e�B�u�`�惉�C�g�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstLightParam
		{
			Vector3		litDirection;
			MofFloat	Dummy1;
			Vector4		litDiffuse;
			Vector4		litAmbient;
			Vector4		litSpeculer;
		};
		/*******************//*!
		�v���~�e�B�u�`�惉�C�g���ݒ�
		*//********************/
		ConstLightParam							m_LightParam;
	protected:
		/*******************//*!
		�V�[�������̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstScene;
		/*******************//*!
		�v���~�e�B�u�����̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstMesh;
		/*******************//*!
		�}�e���A�������̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstMaterial;
		/*******************//*!
		���C�g�����̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstLight;
		/*******************//*!
		�T���v���[
		*//********************/
		ID3DX11EffectSamplerVariable*			m_pSampler;
		/*******************//*!
		�e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pTexture;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SkinGeometryBase();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SkinGeometryBase(const CDX11ShaderBind_SkinGeometryBase& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_SkinGeometryBase();
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pvb			���_�o�b�t�@�z��
				@param[in]		Cnt			���_�o�b�t�@�z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateVertexLayout(LPVertexBuffer* pvb, MofU32 Cnt = 0);
		
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
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n);
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pData		�f�[�^
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData);
		/*************************************************************************//*!
				@brief			�T���v���̐ݒ�<br>
								DirectX11�Ŏ��s���̂ݗL��<br>
								DirectX9�̏ꍇ�̓V�F�[�_�[�ł̎w�肪�AOpenGL�n�̏ꍇ�̓e�N�X�`���ł̎w�肪�L���ɂȂ�B
				@param[in]		n			�ԍ�
				@param[in]		st			�T���v���^�C�v
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetSamplerType(MofU32 n,MofU32 st);
		/*************************************************************************//*!
				@brief			�T���v���̐ݒ�<br>
								DirectX11�Ŏ��s���̂ݗL��<br>
								DirectX9�̏ꍇ�̓V�F�[�_�[�ł̎w�肪�AOpenGL�n�̏ꍇ�̓e�N�X�`���ł̎w�肪�L���ɂȂ�B
				@param[in]		n			�ԍ�
				@param[in]		pSamp		�T���v��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetSamplerState(MofU32 n,MofSamplerState pSamp);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pTex		�e�N�X�`��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);
		
		/*************************************************************************//*!
				@brief			�`��p�s���ݒ肷��
				@param[in]		wMat			�s��

				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			�`��p�s���ݒ肷��
				@param[in]		pMotion		���[�V�����R���g���[��
				@param[in]		pGeom		�W�I���g��
				
				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(LPMeshMotionController pMotion,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			�`��p�}�e���A����ݒ肷��
				@param[in]		pMat			�}�e���A��

				@return			None
		*//**************************************************************************/
		virtual void SetMaterial(LPMaterial pMat);
		/*************************************************************************//*!
				@brief			�`��p�v���~�e�B�u�p�����[�^�[��ݒ肷��
				@param[in]		pPar			�e�N�X�`���p�����[�^�[

				@return			None
		*//**************************************************************************/
		virtual void SetPrimitiveParameter(LPPrimitiveRenderParameter pPar);
		/*************************************************************************//*!
				@brief			�`��p�e�N�X�`���p�����[�^�[��ݒ肷��
				@param[in]		pPar			�e�N�X�`���p�����[�^�[

				@return			None
		*//**************************************************************************/
		virtual void SetTextureParameter(LPTextureRenderParameter pPar);
		/*************************************************************************//*!
				@brief			�`��p�J������ݒ肷��
				@param[in]		pc				�J����

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(LPCamera pc);
		/*************************************************************************//*!
				@brief			�`��p�J������ݒ肷��
				@param[in]		mv				�J����
				@param[in]		mp				�v���W�F�N�V����

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(Matrix44& mv,Matrix44& mp);
		/*************************************************************************//*!
				@brief			�`��p��{���C�g��ݒ肷��
				@param[in]		pl				���C�g

				@return			None
		*//**************************************************************************/
		virtual void SetDirectionalLight(LPDirectionalLight pl);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ݒ�p�����[�^�[�����擾����
				@param			None

				@return			�p�����[�^�[�̐�
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const { return PARAM_MAX; }

		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11ShaderBind_SkinGeometryBase,MOF_DX11SHADERBINDSKINGEOMETRYBASEBASECLASS_ID);
	};
	
	#include	"DX11ShaderBind_SkinGeometryBase.inl"

	//�u������
	typedef CDX11ShaderBind_SkinGeometryBase		CShaderBind_SkinGeometryBase;
	typedef CShaderBind_SkinGeometryBase*			LPShaderBind_SkinGeometryBase;
}

#endif

//[EOF]