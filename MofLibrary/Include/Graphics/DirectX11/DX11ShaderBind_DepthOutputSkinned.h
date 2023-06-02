/*************************************************************************//*!
					
					@file	DX11ShaderBind_DepthOutputSkinned.h
					@brief	�[�x�o�̓V�F�[�_�[�o�C���h�B<br>
							�[�x�o�̓V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.05.25
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_DEPTHOUTPUTSKINNED__H__

#define		__DX11SHADERBIND_DEPTHOUTPUTSKINNED__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_SkinGeometryBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�[�x�o�̓V�F�[�_�[�o�C���h�B

			�[�x�o�̓V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_DepthOutputSkinned : public CShaderBind_SkinGeometryBase {
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_DepthOutputSkinned,MOF_DX11SHADERBINDDEPTHOUTPUTSKINNEDCLASS_ID);
	};
	
	#include	"DX11ShaderBind_DepthOutputSkinned.inl"

	//�u������
	typedef CDX11ShaderBind_DepthOutputSkinned		CShaderBind_DepthOutputSkinned;
	typedef CShaderBind_DepthOutputSkinned*		LPShaderBind_DepthOutputSkinned;
}

#endif

//[EOF]