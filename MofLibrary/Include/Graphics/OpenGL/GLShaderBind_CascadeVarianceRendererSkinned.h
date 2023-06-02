/*************************************************************************//*!
					
					@file	GLShaderBind_CascadeVarianceRendererSkinned.h
					@brief	�V���h�E�}�b�v�̉e�`��V�F�[�_�[�o�C���h�B<br>
							�V���h�E�}�b�v�̉e�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.11.09
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_CASCADEVARIANCERENDERERSKINNED__H__

#define		__GLSHADERBIND_CASCADEVARIANCERENDERERSKINNED__H__

//INCLUDE
#include	"GLShaderBind_SkinGeometryBase.h"
#include	"../ShaderEffect_CascadedShadowMap.h"

namespace Mof {

	/*******************************//*!
	@brief	�V���h�E�}�b�v�̉e�`��V�F�[�_�[�o�C���h�B

			�V���h�E�}�b�v�̉e�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_CascadeVarianceRendererSkinned : public CShaderBind_SkinGeometryBase {
	public:
		/*******************************//*!
		@brief	�V���h�E�}�b�v�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_SHADOWMAP = CShaderBind_SkinGeometryBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�V���h�E�}�b�v�`������̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstShadowMapParam
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
		ConstShadowMapParam					m_ShadowMapParam;
	protected:
		/*******************//*!
		�e�}�g���N�X���P�[�V����
		*//********************/
		GLuint								m_ShadowMatLocation;
		/*******************//*!
		�J�X�P�[�h�I�t�Z�b�g���P�[�V����
		*//********************/
		GLuint								m_CascadeOffsetLocation;
		/*******************//*!
		�J�X�P�[�h�X�P�[�����P�[�V����
		*//********************/
		GLuint								m_CascadeScaleLocation;
		/*******************//*!
		�ŏ��p�f�B���O���P�[�V����
		*//********************/
		GLuint								m_MinBorderPaddingLocation;
		/*******************//*!
		�ő�p�f�B���O���P�[�V����
		*//********************/
		GLuint								m_MaxBorderPaddingLocation;
		/*******************//*!
		�J�X�P�[�h�u�����h�͈̓��P�[�V����
		*//********************/
		GLuint								m_CascadeBlendAreaLocation;
		/*******************//*!
		�e�̋������P�[�V����
		*//********************/
		GLuint								m_ShadowPowerLocation;
		/*******************//*!
		�e�N�X�`��
		*//********************/
		GLuint								m_ShadowMapTexLocation0;
		/*******************//*!
		�e�N�X�`��
		*//********************/
		GLuint								m_ShadowMapTexLocation1;
		/*******************//*!
		�e�N�X�`��
		*//********************/
		GLuint								m_ShadowMapTexLocation2;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_CascadeVarianceRendererSkinned();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_CascadeVarianceRendererSkinned(const CGLShaderBind_CascadeVarianceRendererSkinned& pObj);
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
	
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
		MOF_LIBRARYCLASS(CGLShaderBind_CascadeVarianceRendererSkinned,MOF_GLSHADERBINDCASCADEVARIANCERENDERERSKINNEDCLASS_ID);
	};
	
	#include	"GLShaderBind_CascadeVarianceRendererSkinned.inl"

	//�u������
	typedef CGLShaderBind_CascadeVarianceRendererSkinned		CShaderBind_CascadeVarianceRendererSkinned;
	typedef CShaderBind_CascadeVarianceRendererSkinned*		LPShaderBind_CascadeVarianceRendererSkinned;
}

#endif

//[EOF]
