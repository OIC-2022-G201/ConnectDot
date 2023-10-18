/*************************************************************************//*!
					
					@file	GLShaderBind_ShadowRenderer.h
					@brief	�V���h�E�}�b�v�̉e�`��V�F�[�_�[�o�C���h�B<br>
							�V���h�E�}�b�v�̉e�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.10.29
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_SHADOWRENDERER__H__

#define		__GLSHADERBIND_SHADOWRENDERER__H__

//INCLUDE
#include	"GLShaderBind_3DPrimitiveBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�V���h�E�}�b�v�̉e�`��V�F�[�_�[�o�C���h�B

			�V���h�E�}�b�v�̉e�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ShadowRenderer : public CShaderBind_3DPrimitiveBase {
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
		struct ConstShadowMapParam
		{
			Matrix44	mtxLightVP;
			MofFloat	ShadowMapSize;
			MofFloat	ShadowEpsilon;
		};
		/*******************//*!
		�V���h�E�}�b�v�`����ݒ�
		*//********************/
		ConstShadowMapParam						m_ShadowMapParam;
	protected:
		/*******************//*!
		���C�g�}�g���N�X���P�[�V����
		*//********************/
		GLuint									m_LightVPLocation;
		/*******************//*!
		�V���h�E�}�b�v�T�C�Y���P�[�V����
		*//********************/
		GLuint									m_ShadowMapSizeLocation;
		/*******************//*!
		�V���h�E�}�b�v�C�v�V�������P�[�V����
		*//********************/
		GLuint									m_ShadowEpsilonLocation;
		/*******************//*!
		�e�N�X�`�����P�[�V����
		*//********************/
		GLuint									m_ShadowMapTexLocation;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ShadowRenderer();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ShadowRenderer(const CGLShaderBind_ShadowRenderer& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_ShadowRenderer,MOF_GLSHADERBINDSHADOWRENDERERCLASS_ID);
	};
	
	#include	"GLShaderBind_ShadowRenderer.inl"

	//�u������
	typedef CGLShaderBind_ShadowRenderer		CShaderBind_ShadowRenderer;
	typedef CShaderBind_ShadowRenderer*		LPShaderBind_ShadowRenderer;
}

#endif

//[EOF]
