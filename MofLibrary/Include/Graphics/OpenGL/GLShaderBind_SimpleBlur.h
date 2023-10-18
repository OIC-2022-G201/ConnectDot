/*************************************************************************//*!
					
					@file	GLShaderBind_SimpleBlur.h
					@brief	�P���ڂ����V�F�[�_�[�o�C���h�B<br>
							�P���ڂ����V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.10.26
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_SIMPLEBLUR__H__

#define		__GLSHADERBIND_SIMPLEBLUR__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�P���ڂ����V�F�[�_�[�o�C���h�B

			�P���ڂ����V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_SimpleBlur : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	���̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_BLUR = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�ڂ��������̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstBlurParam
		{
			Vector2 BlurStep;
			MofS32 BlurKernelBegin;
			MofS32 BlurKernelEnd;
			MofS32 BlurKernelSize;
		};
		/*******************//*!
		�v���~�e�B�u�`��V�[�����ݒ�
		*//********************/
		ConstBlurParam							m_BlurParam;
	protected:
		/*******************//*!
		�ڂ����T���v�����O�Ԋu���P�[�V����
		*//********************/
		GLuint									m_BlurStepLocation;
		/*******************//*!
		�ڂ����J�n���P�[�V����
		*//********************/
		GLuint									m_BlurKernelBegin;
		/*******************//*!
		�ڂ����I�����P�[�V����
		*//********************/
		GLuint									m_BlurKernelEnd;
		/*******************//*!
		�ڂ����T���v�����O�񐔃��P�[�V����
		*//********************/
		GLuint									m_BlurKernelSize;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_SimpleBlur();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_SimpleBlur(const CGLShaderBind_SimpleBlur& pObj);
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
	
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n);
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pData		�f�[�^
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pTex		�e�N�X�`��

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ݒ�p�����[�^�[�����擾����
				@param			None

				@return			�p�����[�^�[�̐�
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const { return PARAM_MAX; }

		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLShaderBind_SimpleBlur,MOF_GLSHADERBINDSIMPLEBLURCLASS_ID);
	};

	#include	"GLShaderBind_SimpleBlur.inl"
	
	//�u������
	typedef CGLShaderBind_SimpleBlur		CShaderBind_SimpleBlur;
	typedef CShaderBind_SimpleBlur*		LPShaderBind_SimpleBlur;
}

#endif

//[EOF]
