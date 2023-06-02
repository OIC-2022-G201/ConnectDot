/*************************************************************************//*!
					
					@file	ShaderResource.h
					@brief	�V�F�[�_�[���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERRESOURCE__H__

#define		__SHADERRESOURCE__H__

//INCLUDE
#include	"Shader.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�C���^�[�t�F�C�X

			�V�F�[�_�[�ւ̃p�����[�^�[�ݒ�������Ȃ����߂̃o�b�t�@�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShaderResource : public IMofNamedObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐���
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pName		���\�[�X��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader, LPCMofChar pName) = 0;
		
		/*************************************************************************//*!
				@brief			�o�C���h�̎��s
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Bind(void) = 0;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���\�[�X�̐ݒ�
				@param[in]		pTex		�f�[�^
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetResource(LPTexture pTex) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
	};

	//�|�C���^�u������
	typedef IShaderResource*			LPShaderResource;
	typedef CDynamicArray< LPShaderResource > CShaderResourceArray, *LPShaderResourceArray;
}

#endif

//[EOF]