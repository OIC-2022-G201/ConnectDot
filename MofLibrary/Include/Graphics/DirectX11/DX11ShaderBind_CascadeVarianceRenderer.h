/*************************************************************************//*!
					
					@file	DX11ShaderBind_CascadeVarianceRenderer.h
					@brief	�V���h�E�}�b�v�̉e�`��V�F�[�_�[�o�C���h�B<br>
							�V���h�E�}�b�v�̉e�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.06.10
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_CASCADEVARIANCERENDERER__H__

#define		__DX11SHADERBIND_CASCADEVARIANCERENDERER__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_3DPrimitiveBase.h"
#include	"../ShaderEffect_CascadedShadowMap.h"

namespace Mof {

	/*******************************//*!
	@brief	�V���h�E�}�b�v�̉e�`��V�F�[�_�[�o�C���h�B

			�V���h�E�}�b�v�̉e�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_CascadeVarianceRenderer : public CShaderBind_3DPrimitiveBase {
	public:
		/*******************************//*!
		@brief	�V���h�E�}�b�v�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_SHADOWMAP = CShaderBind_3DPrimitiveBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�V���h�E�}�b�v�`������̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstShadowMapParam
		{
			Matrix44	m_Shadow;
			Vector4		m_vCascadeOffset[CShaderEffect_CascadedShadowMap::MAX_CASCADES];
			Vector4		m_vCascadeScale[CShaderEffect_CascadedShadowMap::MAX_CASCADES];

			MofFloat	m_fMinBorderPadding;
			MofFloat	m_fMaxBorderPadding;

			MofFloat	m_fCascadeBlendArea;
			MofFloat	m_fShadowPower;
		};
		/*******************//*!
		�V���h�E�}�b�v�`����ݒ�
		*//********************/
		ConstShadowMapParam						m_ShadowMapParam;
	protected:
		/*******************//*!
		�V���h�E�}�b�v�`������̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstShadowMap;
		/*******************//*!
		�e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pShadowMapTex0;
		/*******************//*!
		�e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pShadowMapTex1;
		/*******************//*!
		�e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pShadowMapTex2;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_CascadeVarianceRenderer();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_CascadeVarianceRenderer(const CDX11ShaderBind_CascadeVarianceRenderer& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_CascadeVarianceRenderer();
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		
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
				@brief			�e�N�X�`���̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pTex		�e�N�X�`��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_CascadeVarianceRenderer,MOF_DX11SHADERBINDCASCADEVARIANCERENDERERCLASS_ID);
	};
	
	#include	"DX11ShaderBind_CascadeVarianceRenderer.inl"

	//�u������
	typedef CDX11ShaderBind_CascadeVarianceRenderer		CShaderBind_CascadeVarianceRenderer;
	typedef CShaderBind_CascadeVarianceRenderer*		LPShaderBind_CascadeVarianceRenderer;
}

#endif

//[EOF]