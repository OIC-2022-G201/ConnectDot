/*************************************************************************//*!
					
					@file	GLShaderBind_DownScale.h
					@brief	�k���V�F�[�_�[�o�C���h�B<br>
							�k���V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.11.05
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_DOWNSCALE__H__

#define		__GLSHADERBIND_DOWNSCALE__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�k���V�F�[�_�[�o�C���h�B
	
			�k���V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_DownScale : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_PIXELOFFSET = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�e�N�X�`���T�C�Y�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstPixelOffsetParam
		{
			Vector2 PixelOffset;
		};
		/*******************//*!
		�v���~�e�B�u�`��V�[�����ݒ�
		*//********************/
		ConstPixelOffsetParam							m_PixelOffsetParam;
	protected:
		/*******************//*!
		�X�v���C�g�����̓R���X�^���g�o�b�t�@
		*//********************/
		GLuint											m_PixelOffsetLocation;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_DownScale();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_DownScale(const CGLShaderBind_DownScale& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_DownScale,MOF_GLSHADERBINDDOWNSCALECLASS_ID);
	};

	#include	"GLShaderBind_DownScale.inl"
	
	//�u������
	typedef CGLShaderBind_DownScale		CShaderBind_DownScale;
	typedef CShaderBind_DownScale*			LPShaderBind_DownScale;
}

#endif

//[EOF]
