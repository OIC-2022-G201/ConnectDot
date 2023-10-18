/*************************************************************************//*!
					
					@file	GLShaderBind_BumpMapping.h
					@brief	�o���v�}�b�s���O�V�F�[�_�[�o�C���h�B<br>
							�o���v�}�b�s���O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.10.22
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_BUMPMAPPING__H__

#define		__GLSHADERBIND_BUMPMAPPING__H__

//INCLUDE
#include	"GLShaderBind_3DPrimitiveBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�o���v�}�b�s���O�V�F�[�_�[�o�C���h�B

			�o���v�}�b�s���O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_BumpMapping : public CShaderBind_3DPrimitiveBase {
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
		CGLShaderBind_BumpMapping();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_BumpMapping(const CGLShaderBind_BumpMapping& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderBind_BumpMapping();
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_BumpMapping,MOF_GLSHADERBINDBUMPMAPPINGCLASS_ID);
	};
	
	#include	"GLShaderBind_BumpMapping.inl"

	//�u������
	typedef CGLShaderBind_BumpMapping		CShaderBind_BumpMapping;
	typedef CShaderBind_BumpMapping*		LPShaderBind_BumpMapping;
}

#endif

//[EOF]
