/*************************************************************************//*!
					
					@file	GLShaderBind_EdgeBaseOutput.h
					@brief	�G�b�W���o�V�F�[�_�[�����V�F�[�_�[�o�C���h�B<br>
							�G�b�W���o�V�F�[�_�[�����V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.06.01
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_EDGEBASEOUTPUT__H__

#define		__GLSHADERBIND_EDGEBASEOUTPUT__H__

//INCLUDE
#include	"GLShaderBind_DepthOutput.h"

namespace Mof {

	/*******************************//*!
	@brief	�G�b�W���o�V�F�[�_�[�����V�F�[�_�[�o�C���h�B

			�G�b�W���o�V�F�[�_�[�����V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_EdgeBaseOutput : public CGLShaderBind_DepthOutput {
	public:
		/*******************************//*!
		@brief	���̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_MASK = CGLShaderBind_DepthOutput::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�}�X�N�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstMaskParam
		{
			MofFloat Mask;
		};
		/*******************//*!
		�}�X�N���ݒ�
		*//********************/
		ConstMaskParam							m_MaskParam;
	protected:
		/*******************//*!
		�}�X�N�l���P�[�V����
		*//********************/
		GLuint									m_MaskValueLocation;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_EdgeBaseOutput();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_EdgeBaseOutput(const CGLShaderBind_EdgeBaseOutput& pObj);

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
		MOF_LIBRARYCLASS(CGLShaderBind_EdgeBaseOutput,MOF_GLSHADERBINDEDGEBASEOUTPUTCLASS_ID);
	};

	#include	"GLShaderBind_EdgeBaseOutput.inl"
	
	//�u������
	typedef CGLShaderBind_EdgeBaseOutput		CShaderBind_EdgeBaseOutput;
	typedef CShaderBind_EdgeBaseOutput*			LPShaderBind_EdgeBaseOutput;
}

#endif

//[EOF]
