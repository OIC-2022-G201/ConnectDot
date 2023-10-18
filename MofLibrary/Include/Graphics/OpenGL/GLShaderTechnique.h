/*************************************************************************//*!
					
					@file	GLShaderTechnique.h
					@brief	OpenGL�V�F�[�_�[�e�N�j�b�N�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERTECHNIQUE__H__

#define		__GLSHADERTECHNIQUE__H__

//INCLUDE
#include	"../ShaderTechniqueBase.h"
#include	"GLShaderPass.h"

namespace Mof {
	
	/*******************************//*!
	@brief	OpenGL�V�F�[�_�[�e�N�j�b�N�N���X

			OpenGL�ł̃V�F�[�_�[�̃e�N�j�b�N�ݒ���s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderTechnique : public CShaderTechniqueBase {
	protected:
		/*******************//*!
		�V�F�[�_�[�e�N�j�b�N
		*//********************/
		ID3GLEffectTechnique*	m_pTechnique;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderTechnique();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pTec		�e�N�j�b�N

				@return			None
		*//**************************************************************************/
		CGLShaderTechnique(ID3GLEffectTechnique* pTec);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param			pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderTechnique(const CGLShaderTechnique& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderTechnique();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�e�N�j�b�N�̊J�n
				@param[in]		Flag		�K�p�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Begin(MofU32 Flag);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̊J�n
				@param[in]		nPass		�p�X�ԍ�
				@param[in]		Flag		�K�p�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool BeginPass(MofU32 nPass,MofU32 Flag);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�e�N�j�b�N�̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool End(void);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool EndPass(void);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLShaderTechnique,MOF_GLSHADERTECHNIQUECLASS_ID);
	};

	#include	"GLShaderTechnique.inl"
}

#endif

//[EOF]