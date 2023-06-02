/*************************************************************************//*!
					
					@file	DX11ShaderBind_DownScale.h
					@brief	�k���V�F�[�_�[�o�C���h�B<br>
							�k���V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.11.05
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_DOWNSCALE__H__

#define		__DX11SHADERBIND_DOWNSCALE__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�k���V�F�[�_�[�o�C���h�B

			�k���V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_DownScale : public CShaderBind_SpriteBase {
	public:
		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11ShaderBind_DownScale,MOF_DX11SHADERBINDDOWNSCALECLASS_ID);
	};
	
	#include	"DX11ShaderBind_DownScale.inl"

	//�u������
	typedef CDX11ShaderBind_DownScale		CShaderBind_DownScale;
	typedef CShaderBind_DownScale*		LPShaderBind_DownScale;
}

#endif

//[EOF]