/*************************************************************************//*!
					
					@file	GLShaderPass.h
					@brief	OpenGL�V�F�[�_�[�p�X�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERPASS__H__

#define		__GLSHADERPASS__H__

//INCLUDE
#include	"../ShaderPassBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	OpenGL�V�F�[�_�[�p�X�N���X

			OpenGL�ł̃V�F�[�_�[�̃p�X�ݒ���s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderPass : public CShaderPassBase {
	protected:
		/*******************//*!
		�V�F�[�_�[�e�N�j�b�N
		*//********************/
		ID3GLEffectPass*			m_pPass;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderPass();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pPass		�p�X

				@return			None
		*//**************************************************************************/
		CGLShaderPass(ID3GLEffectPass* pPass);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param			pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderPass(const CGLShaderPass& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderPass();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̊J�n
				@param[in]		Flag		�K�p�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Begin(MofU32 Flag);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool End(void);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLShaderPass,MOF_GLSHADERPASSCLASS_ID);
	};

#include	"GLShaderPass.h"

}

#endif

//[EOF]