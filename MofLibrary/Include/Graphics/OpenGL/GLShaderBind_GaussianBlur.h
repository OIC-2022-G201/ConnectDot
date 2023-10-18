/*************************************************************************//*!
					
					@file	GLShaderBind_GaussianBlur.h
					@brief	��{�X�v���C�g�V�F�[�_�[�o�C���h�B<br>
							�W���I�ȃX�v���C�g�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.10.19
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_GAUSSIANBLUR__H__

#define		__GLSHADERBIND_GAUSSIANBLUR__H__

//INCLUDE
#include	"../ShaderBind_GaussianBlurBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�V�F�[�_�[�o�C���h���C���^�[�t�F�C�X

			�V�F�[�_�[�̂��߂̃o�b�t�@�̐ݒ���s���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_GaussianBlur : public CShaderBind_GaussianBlurBase {
	public:
	protected:
		/*******************//*!
		�V�F�[�_�[ID
		*//********************/
		GLuint									m_ShaderID;
		/*******************//*!
		���_���P�[�V����
		*//********************/
		GLuint									m_Attribute[CShaderBind_GaussianBlurBase::ATTRIBUTE_COUNT];
		/*******************//*!
		�e�N�X�`�����P�[�V����
		*//********************/
		GLuint									m_TexLocation;
		/*******************//*!
		�v���~�e�B�u�p�����[�^���P�[�V����
		*//********************/
		GLuint									m_OffsetLocation;
		/*******************//*!
		�v���~�e�B�u�p�����[�^���P�[�V����
		*//********************/
		GLuint									m_SizeLocation;
		/*******************//*!
		�v���~�e�B�u�p�����[�^���P�[�V����
		*//********************/
		GLuint									m_TOffsetLocation;
		/*******************//*!
		�v���~�e�B�u�p�����[�^���P�[�V����
		*//********************/
		GLuint									m_TSizeLocation;
		/*******************//*!
		�v���~�e�B�u�p�����[�^���P�[�V����
		*//********************/
		GLuint									m_ColorLocation;
		/*******************//*!
		���[���h�}�g���N�X���P�[�V����
		*//********************/
		GLuint									m_WorldLocation;
		/*******************//*!
		�r���[�}�g���N�X���P�[�V����
		*//********************/
		GLuint									m_ViewLocation;
		/*******************//*!
		�v���W�F�N�V�����}�g���N�X���P�[�V����
		*//********************/
		GLuint									m_ProjectionLocation;
		/*******************//*!
		�ڂ����p�I�t�Z�b�g���P�[�V����
		*//********************/
		GLuint									m_BlurTexOffsets;
		/*******************//*!
		�ڂ����p�t�I�t�Z�b�g���P�[�V����
		*//********************/
		GLuint									m_BlurReverseOffset;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_GaussianBlur();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param			pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_GaussianBlur(const CGLShaderBind_GaussianBlur& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderBind_GaussianBlur();
		
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
		virtual MofBool CreateVertexLayout(LPVertexBuffer* pvb, MofU32 Cnt = 0);

		/*************************************************************************//*!
				@brief			�o�C���h�̎��s
				@param[in]		pGeom		�W�I���g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Bind(LPGeometry pGeom = NULL);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
	
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
				@brief			�T���v���̐ݒ�<br>
								OpenGL�Ŏ��s���̂ݗL��<br>
								DirectX9�̏ꍇ�̓V�F�[�_�[�ł̎w�肪�AOpenGL�n�̏ꍇ�̓e�N�X�`���ł̎w�肪�L���ɂȂ�B
				@param[in]		n			�ԍ�
				@param[in]		pSamp		�T���v��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetSamplerState(MofU32 n,MofSamplerState pSamp);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pTex		�e�N�X�`��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLShaderBind_GaussianBlur,MOF_GLSHADERBINDGAUSSIANBLURCLASS_ID);
	};

	#include	"GLShaderBind_GaussianBlur.inl"

	//�u������
	typedef CGLShaderBind_GaussianBlur		CShaderBind_GaussianBlur;
	typedef CShaderBind_GaussianBlur*		LPShaderBind_GaussianBlur;
}

#endif

//[EOF]
