/*************************************************************************//*!
					
					@file	GLShaderBind_DepthOfField.h
					@brief	��ʊE�[�x�V�F�[�_�[�o�C���h�B<br>
							��ʊE�[�x�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.10.30
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_DEPTHOFFIELD__H__

#define		__GLSHADERBIND_DEPTHOFFIELD__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�x�����C�e�B���O�V�F�[�_�[�o�C���h�B

			�x�����C�e�B���O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_DepthOfField : public CGLShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_DEPTHOFFIELD = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�v���~�e�B�u�`�惉�C�g�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstDoFParam
		{
			MofFloat	FocalDistance;
			MofFloat	FocalRange;
			MofFloat	FocalAttenuation;
			MofFloat	Far;
		};
		/*******************//*!
		�v���~�e�B�u�`�惉�C�g���ݒ�
		*//********************/
		ConstDoFParam						m_DoFParam;
	protected:
		/*******************//*!
		�œ_�������P�[�V����
		*//********************/
		GLuint								m_FocalDistanceLocation;
		/*******************//*!
		�œ_�����P�[�V����
		*//********************/
		GLuint								m_FocalRangeLocation;
		/*******************//*!
		�ω��������P�[�V����
		*//********************/
		GLuint								m_FocalAttenuationLocation;
		/*******************//*!
		�ŉ��l���P�[�V����
		*//********************/
		GLuint								m_FarLocation;
		/*******************//*!
		�ڂ����e�N�X�`��
		*//********************/
		GLuint								m_BlurTex;
		/*******************//*!
		�[�x�e�N�X�`��
		*//********************/
		GLuint								m_DepthTex;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_DepthOfField();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_DepthOfField(const CGLShaderBind_DepthOfField& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_DepthOfField,MOF_GLSHADERBINDDEPTHOFFIELDCLASS_ID);
	};

	#include	"GLShaderBind_DepthOfField.inl"
	
	//�u������
	typedef CGLShaderBind_DepthOfField		CShaderBind_DepthOfField;
	typedef CShaderBind_DepthOfField*			LPShaderBind_DepthOfField;
}

#endif

//[EOF]
