/*************************************************************************//*!
					
					@file	GLShaderBind_ToonEdge.h
					@brief	�g�D�[���֊s�`��V�F�[�_�[�o�C���h�B<br>
							�g�D�[���֊s�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.05.22
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_TOONEDGE__H__

#define		__GLSHADERBIND_TOONEDGE__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�g�D�[���֊s�`��V�F�[�_�[�o�C���h�B

			�g�D�[���֊s�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ToonEdge : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_TOONEDGE = CShaderBind_SpriteBase::PARAM_MAX,
			PARAM_PIXELOFFSET,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�g�D�[���֊s�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstToonEdgeParam
		{
			Vector4  EdgeColor;
			MofFloat ThresholdD;
			MofFloat ThresholdN;
			MofFloat Atten;
			MofFloat Far;
		};
		/*******************//*!
		�g�D�[���֊s���ݒ�
		*//********************/
		ConstToonEdgeParam							m_ToonEdgeParam;
		/*******************************//*!
		@brief	�g�D�[���֊s�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstPixelOffsetParam
		{
			Vector2  PixelOffset;
		};
		/*******************//*!
		�g�D�[���֊s���ݒ�
		*//********************/
		ConstPixelOffsetParam						m_PixelOffsetParam;
	protected:
		/*******************//*!
		�g�D�[���֊s�F���P�[�V����
		*//********************/
		GLuint									m_EdgeColorLocation;
		/*******************//*!
		�g�D�[���֊s�s�����x���P�[�V����
		*//********************/
		GLuint									m_EdgeAlphaLocation;
		/*******************//*!
		�[�x臒l���P�[�V����
		*//********************/
		GLuint									m_ThresholdDLocation;
		/*******************//*!
		�@��臒l���P�[�V����
		*//********************/
		GLuint									m_ThresholdNLocation;
		/*******************//*!
		�����n���P�[�V����
		*//********************/
		GLuint									m_AttenLocation;
		/*******************//*!
		�ŉ��l���P�[�V����
		*//********************/
		GLuint									m_FarLocation;
		/*******************//*!
		�I�t�Z�b�g���P�[�V����
		*//********************/
		GLuint									m_PixelOffsetLocation;
		/*******************//*!
		�[�x�@���e�N�X�`��
		*//********************/
		GLuint									m_DepthNormalTexLocation;
		/*******************//*!
		�}�X�N�e�N�X�`��
		*//********************/
		GLuint									m_MaskTexLocation;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToonEdge();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToonEdge(const CGLShaderBind_ToonEdge& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_ToonEdge,MOF_GLSHADERBINDTOONEDGECLASS_ID);
	};

	#include	"GLShaderBind_ToonEdge.inl"
	
	//�u������
	typedef CGLShaderBind_ToonEdge		CShaderBind_ToonEdge;
	typedef CShaderBind_ToonEdge*			LPShaderBind_ToonEdge;
}

#endif

//[EOF]
