/*************************************************************************//*!
					
					@file	ShaderEffect_DepthOfField.h
					@brief	��ʊE�[�x�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.04.29
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_DEPTHOFFIELD__H__

#define		__SHADEREFFECT_DEPTHOFFIELD__H__

//INCLUDE
#include	"ShaderEffect_GaussianBlur.h"

namespace Mof {
	
	/*******************************//*!
	@brief	��ʊE�[�x�V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_DepthOfField : public CShaderEffect_2DBase {
	protected:
		/*******************//*!
		�ڂ����̃T���v�����O�Ԋu
		*//********************/
		MofFloat m_BlurStep;
		/*******************//*!
		�������ڂ����`���e�N�X�`��
		*//********************/
		LPTexture m_pXBlurTex;
		/*******************//*!
		�c�����ڂ����`���e�N�X�`��
		*//********************/
		LPTexture m_pYBlurTex;
		/*******************//*!
		�K�E�X�ڂ����V�F�[�_�[
		*//********************/
		LPShaderEffect_GaussianBlur m_pGBlur;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_DepthOfField();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_DepthOfField();
		
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex);
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
		@param[in]		pTex		�e�N�X�`��
		@param[in]		pDepthTex	�[�x�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex,LPTexture pDepthTex);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
		@brief			��ʊE�[�x�̃p�����[�^�ݒ�
		@param[in]		FocalDistance		�œ_����
		@param[in]		FocalRange			�ڂ��Ȃ��͈�
		@param[in]		FocalAttenuation	�ڂ��n�߂Ă���ő�܂łڂ���܂ł̋���
		@param[in]		Far			�ŉ���
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDoFParam(MofFloat FocalDistance,MofFloat FocalRange,MofFloat FocalAttenuation,MofFloat BlurStep,MofFloat Far);
		/*************************************************************************//*!
		@brief			�[�x�e�N�X�`���̐ݒ�
		@param[in]		pTex		�[�x�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthTexture(LPTexture pTex);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_DepthOfField,MOF_SHADEREFFECTDEPTHOFFIELDCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_DepthOfField*			LPShaderEffect_DepthOfField;

#include	"ShaderEffect_DepthOfField.inl"

}

#endif

//[EOF]