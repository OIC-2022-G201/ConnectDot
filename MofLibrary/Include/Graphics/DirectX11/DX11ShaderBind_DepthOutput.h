/*************************************************************************//*!
					
					@file	DX11ShaderBind_DepthOutput.h
					@brief	�[�x�o�̓V�F�[�_�[�o�C���h�B<br>
							�[�x�o�̓V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.05.25
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_DEPTHOUTPUT__H__

#define		__DX11SHADERBIND_DEPTHOUTPUT__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_3DPrimitiveBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�[�x�o�̓V�F�[�_�[�o�C���h�B

			�[�x�o�̓V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_DepthOutput : public CShaderBind_3DPrimitiveBase {
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_DepthOutput,MOF_DX11SHADERBINDDEPTHOUTPUTCLASS_ID);
	};
	
	#include	"DX11ShaderBind_DepthOutput.inl"

	//�u������
	typedef CDX11ShaderBind_DepthOutput		CShaderBind_DepthOutput;
	typedef CShaderBind_DepthOutput*		LPShaderBind_DepthOutput;
}

#endif

//[EOF]