/*************************************************************************//*!
					
					@file	ShaderEffect_2DBase.h
					@brief	2D�p�V�F�[�_�[���ʊ��N���X�B

															@author	CDW
															@date	2015.04.22
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_2DBASE__H__

#define		__SHADEREFFECT_2DBASE__H__

//INCLUDE
#include	"ShaderEffect.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	2D�p�V�F�[�_�[���ʊ��N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_2DBase : public IShaderEffect {
	protected:
		/*******************//*!
		�V�F�[�_�[
		*//********************/
		LPShader		m_pShader;
		/*******************//*!
		�V�F�[�_�[�o�C���h
		*//********************/
		LPShaderBind	m_pShaderBind;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_2DBase();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_2DBase();
		
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		col			�`��F
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,LPTexture pTex);
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTarget		�`��^�[�Q�b�g
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(LPRenderTarget pTarget,LPTexture pTex);
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTarget,LPTexture pTex);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̎擾
				@param			None
				
				@return			�V�F�[�_�[��Ԃ��B
								���s�̏ꍇNULL�ɂȂ�B
		*//**************************************************************************/
		virtual LPShader GetShader(void);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�o�C���h�̎擾
				@param			None
				
				@return			�V�F�[�_�[�o�C���h��Ԃ��B
								���s�̏ꍇNULL�ɂȂ�B
		*//**************************************************************************/
		virtual LPShaderBind GetShaderBind(void);

	};

	// �u������
	typedef CShaderEffect_2DBase*			LPShaderEffect_2DBase;

#include	"ShaderEffect_2DBase.inl"

}

#endif

//[EOF]