/*************************************************************************//*!
					
					@file	ShaderEffect_DeferredLighting.h
					@brief	�x�����C�e�B���O�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.04.27
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_DEFERREDLIGHTING__H__

#define		__SHADEREFFECT_DEFERREDLIGHTING__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	2x2�k���V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_DeferredLighting : public CShaderEffect_2DBase {
	protected:
	public:
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();


		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_DeferredLighting,MOF_SHADEREFFECTDEFERREDLIGHTINGCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_DeferredLighting*			LPShaderEffect_DeferredLighting;

#include	"ShaderEffect_DeferredLighting.inl"

}

#endif

//[EOF]