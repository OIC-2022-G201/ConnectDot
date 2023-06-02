/*************************************************************************//*!
					
					@file	ShaderEffect_BlurBase.h
					@brief	�ڂ����V�F�[�_�[���N���X�B

															@author	CDW
															@date	2015.06.17
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_BLURBASE__H__

#define		__SHADEREFFECT_BLURBASE__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�K�E�X�ڂ����V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_BlurBase : public CShaderEffect_2DBase {
	protected:
	public:

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ڂ����̃p�����[�^�̐ݒ�
				@param[in]		SampleStepX		�T���v�����O����s�N�Z���̉��Ԋu
				@param[in]		SampleStepY		�T���v�����O����s�N�Z���̏c�Ԋu
				@param[in]		TexWidth		�e�N�X�`���̃T�C�Y
				@param[in]		TexHeight		�e�N�X�`���̃T�C�Y

				@return			None
		*//**************************************************************************/
		virtual void SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY,MofS32 TexWidth,MofS32 TexHeight) = 0;
		/*************************************************************************//*!
				@brief			�ڂ����̃p�����[�^�̐ݒ�
				@param[in]		SampleStepX		�T���v�����O����s�N�Z���̉��Ԋu
				@param[in]		SampleStepY		�T���v�����O����s�N�Z���̏c�Ԋu

				@return			None
		*//**************************************************************************/
		virtual void SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY) = 0;

	};

	// �u������
	typedef CShaderEffect_BlurBase*			LPShaderEffect_BlurBase;
}

#endif

//[EOF]