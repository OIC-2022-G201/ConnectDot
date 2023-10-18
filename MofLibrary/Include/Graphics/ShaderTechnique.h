/*************************************************************************//*!
					
					@file	ShaderTechnique.h
					@brief	�V�F�[�_�[�e�N�j�b�N���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERTECHNIQUE__H__

#define		__SHADERTECHNIQUE__H__

//INCLUDE
#include	"ShaderPass.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�e�N�j�b�N�C���^�[�t�F�C�X

			�V�F�[�_�[�̃e�N�j�b�N�ݒ���s�����߂̃C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShaderTechnique : public IMofNamedObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�e�N�j�b�N�̊J�n
				@param[in]		Flag		�K�p�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Begin(MofU32 Flag) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̊J�n
				@param[in]		nPass		�p�X�ԍ�
				@param[in]		Flag		�K�p�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool BeginPass(MofU32 nPass,MofU32 Flag) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�e�N�j�b�N�̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool End(void) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool EndPass(void) = 0;
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�p�X�̐��擾
				@param			None

				@return			�p�X�̐�
		*//**************************************************************************/
		virtual MofU32 GetPassCount(void) const = 0;
		/*************************************************************************//*!
				@brief			�p�X�̎擾
				@param[in]		n			�p�X�ԍ�

				@return			�p�X
		*//**************************************************************************/
		virtual LPShaderPass GetPass(MofU32 n) = 0;
	};

	//�|�C���^�u������
	typedef IShaderTechnique*		LPShaderTechnique;
	typedef CDynamicArray< LPShaderTechnique > CShaderTechniqueArray,*LPShaderTechniqueArray;
}

#endif

//[EOF]