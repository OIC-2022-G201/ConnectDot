/*************************************************************************//*!
					
					@file	ShaderEffect_BrightPass.h
					@brief	���P�x���o�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.04.20
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_BRIGHTPASS__H__

#define		__SHADEREFFECT_BRIGHTPASS__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���P�x���o�V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_BrightPass : public CShaderEffect_2DBase {
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

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_BrightPass,MOF_SHADEREFFECTBRIGHTPASSCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_BrightPass*			LPShaderEffect_BrightPass;

#include	"ShaderEffect_BrightPass.inl"

}

#endif

//[EOF]