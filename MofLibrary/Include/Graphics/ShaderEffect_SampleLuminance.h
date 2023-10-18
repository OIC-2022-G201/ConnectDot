/*************************************************************************//*!
					
					@file	ShaderEffect_SampleLuminance.h
					@brief	�P�x�ϊ��V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.18
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_SAMPLELUMINANCE__H__

#define		__SHADEREFFECT_SAMPLELUMINANCE__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�P�x�ϊ��V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_SampleLuminance : public CShaderEffect_2DBase {
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
		MOF_LIBRARYCLASS(CShaderEffect_SampleLuminance,MOF_SHADEREFFECTSAMPLELUMINANCECLASS_ID);
	};

	// �u������
	typedef CShaderEffect_SampleLuminance*			LPShaderEffect_SampleLuminance;

#include	"ShaderEffect_SampleLuminance.inl"

}

#endif

//[EOF]