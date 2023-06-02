/*************************************************************************//*!
					
					@file	GLShaderBind_ToonShaderSkinned.h
					@brief	�g�D�[�������_�����O�V�F�[�_�[�o�C���h�B<br>
							�g�D�[�������_�����O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.10.26
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_TOONSHADERSKINNED__H__

#define		__GLSHADERBIND_TOONSHADERSKINNED__H__

//INCLUDE
#include	"GLShaderBind_EdgeBaseOutputSkinned.h"

namespace Mof {

	/*******************************//*!
	@brief	�g�D�[�������_�����O�V�F�[�_�[�o�C���h�B

			�g�D�[�������_�����O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ToonShaderSkinned : public CShaderBind_EdgeBaseOutputSkinned {
	public:
	protected:
		/*******************//*!
		�e�N�X�`��
		*//********************/
		GLuint	m_ToonMapLocation;
		/*******************//*!
		�e�N�X�`��
		*//********************/
		LPTexture	m_pToonMap;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToonShaderSkinned();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToonShaderSkinned(const CGLShaderBind_ToonShaderSkinned& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderBind_ToonShaderSkinned();
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		/*************************************************************************//*!
				@brief			�o�C���h�̎��s
				@param[in]		pGeom		�W�I���g��

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Bind(LPGeometry pGeom = NULL);
	
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pTex		�e�N�X�`��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLShaderBind_ToonShaderSkinned,MOF_GLSHADERBINDTOONSHADERSKINNEDCLASS_ID);
	};
	
	#include	"GLShaderBind_ToonShaderSkinned.inl"

	//�u������
	typedef CGLShaderBind_ToonShaderSkinned		CShaderBind_ToonShaderSkinned;
	typedef CShaderBind_ToonShaderSkinned*		LPShaderBind_ToonShaderSkinned;
}

#endif

//[EOF]
