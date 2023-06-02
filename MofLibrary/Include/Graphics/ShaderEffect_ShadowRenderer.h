/*************************************************************************//*!
					
					@file	ShaderEffect_ShadowRenderer.h
					@brief	�V���h�E�}�b�v�ɂ��e�`��V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.04
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_SHADOWRENDERER__H__

#define		__SHADEREFFECT_SHADOWRENDERER__H__

//INCLUDE
#include	"ShaderEffect_ShadowTexture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V���h�E�}�b�v�ɂ��e�`��V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_ShadowRenderer : public CShaderEffect_3DBase {
	protected:
		/*******************//*!
		�e�����炷��
		*//********************/
		MofFloat	m_ShadowEpsilon;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_ShadowRenderer();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_ShadowRenderer();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			�J�n
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Begin();
		/*************************************************************************//*!
				@brief			�I��
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool End();

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�V���h�E�}�b�v�̃Z�b�g
				@param[in]		pShadowMap
				
				@return			None
		*//**************************************************************************/
		virtual void SetShadowMap(LPShaderEffect_ShadowTexture pShadowMap);
		/*************************************************************************//*!
				@brief			�C�v�V�����̐ݒ�
				@param[in]		Epsilon			�e�����炷��
				
				@return			None
		*//**************************************************************************/
		virtual void SetEpsilon(MofFloat Epsilon);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_ShadowRenderer,MOF_SHADEREFFECTSHADOWRENDERERCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_ShadowRenderer*			LPShaderEffect_ShadowRenderer;

#include	"ShaderEffect_ShadowRenderer.inl"

}

#endif

//[EOF]