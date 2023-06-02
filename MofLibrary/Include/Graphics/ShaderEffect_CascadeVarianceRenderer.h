/*************************************************************************//*!
					
					@file	ShaderEffect_CascadeVarianceRenderer.h
					@brief	�V���h�E�}�b�v�ɂ��e�`��V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.06.10
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_CASCADEVARIANCERENDERER__H__

#define		__SHADEREFFECT_CASCADEVARIANCERENDERER__H__

//INCLUDE
#include	"ShaderEffect_ShadowTexture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V���h�E�}�b�v�ɂ��e�`��V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_CascadeVarianceRenderer : public CShaderEffect_3DBase {
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
		CShaderEffect_CascadeVarianceRenderer();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_CascadeVarianceRenderer();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		Variance	�o���A���X�V���h�E�t���O

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofBool Variance);
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
				@param[in]		matShadowView				���C�g���_�̃r���[�s��
				@param[in]		matShadowProj				���C�g���_�̎ˉe�s��̔z��
				@param[in]		fCascadePartitionsFrustum	������̕����ʒu
				@param[in]		pShadowMapTextures			�V���h�E�}�b�v�e�N�X�`���̔z��
				@param[in]		fCascadeBlendArea			�J�X�P�[�h���E�̂ڂ����
				@param[in]		fShadowPower				���C�g�u���[�f�B���O��}���邽�߂̒l
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetShadowMap(const CMatrix44& matShadowView,const CMatrix44* matShadowProj,const MofFloat *fCascadePartitionsFrustum,const LPTexture* pShadowMapTextures,MofFloat fCascadeBlendArea,MofFloat fShadowPower);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_CascadeVarianceRenderer,MOF_SHADEREFFECTCASCADEVARIANCERENDERERCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_CascadeVarianceRenderer*			LPShaderEffect_CascadeVarianceRenderer;

#include	"ShaderEffect_CascadeVarianceRenderer.inl"

}

#endif

//[EOF]
