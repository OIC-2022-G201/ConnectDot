/*************************************************************************//*!
					
					@file	GLShaderBind_Bloom.h
					@brief	�u���[���V�F�[�_�[�o�C���h�B<br>
							�u���[���V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.11.09
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_BLOOM__H__

#define		__GLSHADERBIND_BLOOM__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�u���[���V�F�[�_�[�o�C���h�B
	
			�u���[���V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_Bloom : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_BLOOM = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�g�[���}�b�v�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstBloomParam
		{
			MofFloat BloomScale;
		};
		/*******************//*!
		�g�[���}�b�v���ݒ�
		*//********************/
		ConstBloomParam							m_BloomParam;
	protected:
		/*******************//*!
		�g�[���}�b�v�����̓R���X�^���g�o�b�t�@
		*//********************/
		GLuint									m_BloomScaleLocation;
		/*******************//*!
		�u���[���e�N�X�`��
		*//********************/
		GLuint									m_BloomTexLocation;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_Bloom();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_Bloom(const CGLShaderBind_Bloom& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_Bloom,MOF_GLSHADERBINDBLOOMCLASS_ID);
	};

	#include	"GLShaderBind_Bloom.inl"
	
	//�u������
	typedef CGLShaderBind_Bloom		CShaderBind_Bloom;
	typedef CShaderBind_Bloom*			LPShaderBind_Bloom;
}

#endif

//[EOF]
