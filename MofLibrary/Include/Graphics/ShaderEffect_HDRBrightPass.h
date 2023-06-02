/*************************************************************************//*!
					
					@file	ShaderEffect_HDRBrightPass.h
					@brief	HDR�p���P�x���o�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.20
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_HDRBRIGHTPASS__H__

#define		__SHADEREFFECT_HDRBRIGHTPASS__H__

//INCLUDE
#include	"ShaderEffect_BrightPass.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	HDR�p���P�x���o�V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_HDRBrightPass : public CShaderEffect_BrightPass {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
		@brief			���P�x�̊�ƂȂ�臒l��ݒ�
		@param[in]		Threshold		臒l
				
		@return			None
		*//**************************************************************************/
		virtual MofBool SetThreshold(MofFloat Threshold);
		/*************************************************************************//*!
		@brief			���P�x�̊�ƂȂ�臒l��ݒ�
		@param[in]		Threshold			臒l
		@param[in]		MiddleGray			���Ԃ̖��邳
		@param[in]		HDRBrightPassOffset	�I�t�Z�b�g
				
		@return			None
		*//**************************************************************************/
		virtual MofBool SetHDRBrightPassParam(MofFloat Threshold,MofFloat MiddleGray,MofFloat HDRBrightPassOffset);
		/*************************************************************************//*!
		@brief			���邳�̊�ƂȂ�e�N�X�`����ݒ�
		@param[in]		pTex		�e�N�X�`��
				
		@return			None
		*//**************************************************************************/
		virtual MofBool SetAdaptedLumTexture(LPTexture pTex);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_HDRBrightPass,MOF_SHADEREFFECTHDRBRIGHTPASSCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_HDRBrightPass*			LPShaderEffect_HDRBrightPass;

#include	"ShaderEffect_HDRBrightPass.inl"

}

#endif

//[EOF]