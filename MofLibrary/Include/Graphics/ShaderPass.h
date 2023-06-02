/*************************************************************************//*!
					
					@file	ShaderPass.h
					@brief	�V�F�[�_�[�p�X���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERPASS__H__

#define		__SHADERPASS__H__

//INCLUDE
#include	"Texture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�p�X�C���^�[�t�F�C�X

			�V�F�[�_�[�̃p�X�ݒ���s�����߂̃C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShaderPass : public IMofNamedObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̊J�n
				@param[in]		Flag		�K�p�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Begin(MofU32 Flag) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool End(void) = 0;
	};

	//�|�C���^�u������
	typedef IShaderPass*		LPShaderPass;
	typedef CDynamicArray< LPShaderPass > CShaderPassArray,*LPShaderPassArray;
}

#endif

//[EOF]