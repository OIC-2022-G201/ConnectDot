/*************************************************************************//*!
					
					@file	ShaderBuffer.h
					@brief	�V�F�[�_�[���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERBUFFER__H__

#define		__SHADERBUFFER__H__

//INCLUDE
#include	"Shader.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�C���^�[�t�F�C�X

			�V�F�[�_�[�ւ̃p�����[�^�[�ݒ�������Ȃ����߂̃o�b�t�@�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShaderBuffer : public IMofNamedObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐���
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pName		�o�b�t�@��
				@param[in]		size		�o�b�t�@�T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader, LPCMofChar pName,const MofU32 size) = 0;
		
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
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		pData		�f�[�^
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(LPMofVoid pData) = 0;
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		pData		�f�[�^
				@param[in]		off			�I�t�Z�b�g
				@param[in]		s			�T�C�Y
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(LPMofVoid pData,MofU32 off,MofU32 s) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�o�b�t�@�T�C�Y�擾
				@param			None

				@return			�o�b�t�@�T�C�Y
		*//**************************************************************************/
		virtual MofU32 GetBufferSize(void) const = 0;
	};

	//�|�C���^�u������
	typedef IShaderBuffer*			LPShaderBuffer;
	typedef CDynamicArray< LPShaderBuffer > CShaderBufferArray, *LPShaderBufferArray;
}

#endif

//[EOF]