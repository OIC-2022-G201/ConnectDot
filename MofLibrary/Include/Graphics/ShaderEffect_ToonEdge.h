/*************************************************************************//*!
					
					@file	ShaderEffect_ToonEdge.h
					@brief	�G�b�W�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.22
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_TOONEDGE__H__

#define		__SHADEREFFECT_TOONEDGE__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"
#include	"ShaderEffect_EdgeBaseOutput.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�G�b�W�V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_ToonEdge : public CShaderEffect_2DBase {
	protected:
	public:
		
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
		@param[in]		pEffect		�G�b�W�`�揀���V�F�[�_�[
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex,LPShaderEffect_EdgeBaseOutput pEffect);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
		@brief			�[�x�@���e�N�X�`���̐ݒ�
		@param[in]		pTex		�[�x�@���e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthNormalTexture(LPTexture pTex);
		/*************************************************************************//*!
		@brief			�}�X�N�e�N�X�`���̐ݒ�
		@param[in]		pTex		�}�X�N�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetMaskTexture(LPTexture pTex);
		/*************************************************************************//*!
		@brief			�G�b�W�V�F�[�_�[�̐ݒ�
		@param[in]		EdgeColor	�G�b�W�̐F
		@param[in]		ThresholdD	�[�x�G�b�W�̂������l
		@param[in]		ThresholdN	�@���G�b�W�̂������l
		@param[in]		Atten		�����ɂ��s�����x�̌����l
		@param[in]		Far			�J������Far
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetToonEdgeParam(Vector4& EdgeColor,MofFloat ThresholdD,MofFloat ThresholdN,MofFloat Atten,MofFloat Far);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_ToonEdge,MOF_SHADEREFFECTTOONEDGECLASS_ID);
	};

	// �u������
	typedef CShaderEffect_ToonEdge*			LPShaderEffect_ToonEdge;

#include	"ShaderEffect_ToonEdge.inl"

}

#endif

//[EOF]