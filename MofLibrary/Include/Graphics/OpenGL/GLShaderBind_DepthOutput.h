/*************************************************************************//*!
					
					@file	GLShaderBind_DepthOutput.h
					@brief	�[�x�o�̓V�F�[�_�[�o�C���h�B<br>
							�[�x�o�̓V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.10.30
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_DEPTHOUTPUT__H__

#define		__GLSHADERBIND_DEPTHOUTPUT__H__

//INCLUDE
#include	"GLShaderBind_3DPrimitiveBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�[�x�o�̓V�F�[�_�[�o�C���h�B

			�[�x�o�̓V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_DepthOutput : public CShaderBind_3DPrimitiveBase {
	public:
	
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�`��p�J������ݒ肷��
				@param[in]		pc				�J����

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(LPCamera pc);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLShaderBind_DepthOutput,MOF_GLSHADERBINDDEPTHOUTPUTCLASS_ID);
	};
	
	#include	"GLShaderBind_DepthOutput.inl"

	//�u������
	typedef CGLShaderBind_DepthOutput		CShaderBind_DepthOutput;
	typedef CShaderBind_DepthOutput*		LPShaderBind_DepthOutput;
}

#endif

//[EOF]
