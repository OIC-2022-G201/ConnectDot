/*************************************************************************//*!
					
					@file	GLShaderBind_DepthOutputSkinned.h
					@brief	�[�x�o�̓V�F�[�_�[�o�C���h�B<br>
							�[�x�o�̓V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.10.30
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_DEPTHOUTPUTSKINNED__H__

#define		__GLSHADERBIND_DEPTHOUTPUTSKINNED__H__

//INCLUDE
#include	"GLShaderBind_SkinGeometryBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�[�x�o�̓V�F�[�_�[�o�C���h�B

			�[�x�o�̓V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_DepthOutputSkinned : public CShaderBind_SkinGeometryBase {
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
		MOF_LIBRARYCLASS(CGLShaderBind_DepthOutputSkinned,MOF_GLSHADERBINDDEPTHOUTPUTSKINNEDCLASS_ID);
	};
	
	#include	"GLShaderBind_DepthOutputSkinned.inl"

	//�u������
	typedef CGLShaderBind_DepthOutputSkinned		CShaderBind_DepthOutputSkinned;
	typedef CShaderBind_DepthOutputSkinned*		LPShaderBind_DepthOutputSkinned;
}

#endif

//[EOF]
