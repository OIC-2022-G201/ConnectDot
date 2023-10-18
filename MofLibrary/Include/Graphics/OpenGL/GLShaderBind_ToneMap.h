/*************************************************************************//*!
					
					@file	GLShaderBind_ToneMap.h
					@brief	�g�[���}�b�v�V�F�[�_�[�o�C���h�B<br>
							�g�[���}�b�v�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.11.06
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_TONEMAP__H__

#define		__GLSHADERBIND_TONEMAP__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�g�[���}�b�v�V�F�[�_�[�o�C���h�B
	
			�g�[���}�b�v�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ToneMap : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_TONEMAP = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�g�[���}�b�v�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstToneMapParam
		{
			MofFloat MiddleGray;
			MofFloat BloomScale;
		};
		/*******************//*!
		�g�[���}�b�v���ݒ�
		*//********************/
		ConstToneMapParam				m_ToneMapParam;
	protected:
		/*******************//*!
		��P�x���P�[�V����
		*//********************/
		GLuint							m_MiddleGrayLocation;
		/*******************//*!
		�u���[���̖��邳���P�[�V����
		*//********************/
		GLuint							m_BloomScaleLocation;
		/*******************//*!
		�P�x�e�N�X�`�����P�[�V����
		*//********************/
		GLuint							m_AdaptedLumTexLocation;
		/*******************//*!
		�u���[���e�N�X�`�����P�[�V����
		*//********************/
		GLuint							m_BloomTexLocation;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToneMap();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToneMap(const CGLShaderBind_ToneMap& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_ToneMap,MOF_GLSHADERBINDTONEMAPCLASS_ID);
	};

	#include	"GLShaderBind_ToneMap.inl"
	
	//�u������
	typedef CGLShaderBind_ToneMap		CShaderBind_ToneMap;
	typedef CShaderBind_ToneMap*			LPShaderBind_ToneMap;
}

#endif

//[EOF]
