/*************************************************************************//*!
					
					@file	GLShaderBind_BumpMappingSkinned.h
					@brief	�o���v�}�b�s���O�V�F�[�_�[�o�C���h�B<br>
							�o���v�}�b�s���O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.10.23
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_BUMPMAPPINGSKINNED__H__

#define		__GLSHADERBIND_BUMPMAPPINGSKINNED__H__

//INCLUDE
#include	"GLShaderBind_SkinGeometryBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�o���v�}�b�s���O�V�F�[�_�[�o�C���h�B

			�o���v�}�b�s���O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_BumpMappingSkinned : public CShaderBind_SkinGeometryBase {
	public:
	protected:
		/*******************//*!
		�e�N�X�`��
		*//********************/
		GLuint									m_NormalMapLocation;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_BumpMappingSkinned();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_BumpMappingSkinned(const CGLShaderBind_BumpMappingSkinned& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderBind_BumpMappingSkinned();
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pvb			���_�o�b�t�@�z��
				@param[in]		Cnt			���_�o�b�t�@�z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool CreateVertexLayout(LPVertexBuffer* pvb,MofU32 Cnt);
	
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
		MOF_LIBRARYCLASS(CGLShaderBind_BumpMappingSkinned,MOF_GLSHADERBINDBUMPMAPPINGSKINNEDCLASS_ID);
	};
	
	#include	"GLShaderBind_BumpMappingSkinned.inl"

	//�u������
	typedef CGLShaderBind_BumpMappingSkinned		CShaderBind_BumpMappingSkinned;
	typedef CShaderBind_BumpMappingSkinned*		LPShaderBind_BumpMappingSkinned;
}

#endif

//[EOF]
