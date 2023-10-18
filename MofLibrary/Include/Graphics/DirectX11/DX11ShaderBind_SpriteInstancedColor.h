/*************************************************************************//*!
					
					@file	DX11ShaderBind_SpriteInstancedColor.h
					@brief	��{�X�v���C�g�V�F�[�_�[�o�C���h�B<br>
							�W���I�ȃX�v���C�g�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_SPRITEINSTANCEDCOLOR__H__

#define		__DX11SHADERBIND_SPRITEINSTANCEDCOLOR__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteInstancedBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�V�F�[�_�[�o�C���h���C���^�[�t�F�C�X

			�V�F�[�_�[�̂��߂̃o�b�t�@�̐ݒ���s���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_SpriteInstancedColor : public CDX11ShaderBind_SpriteInstancedBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����͒��_�o�b�t�@��

		@author	CDW
		*//********************************/
		enum VertexAttribute
		{
			ATTRIBUTE_POSITION,
			ATTRIBUTE_TEXCOORDS,

			ATTRIBUTE_COLOR,
			ATTRIBUTE_MATRIX,

			ATTRIBUTE_COUNT,
		};
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SpriteInstancedColor();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SpriteInstancedColor(const CDX11ShaderBind_SpriteInstancedColor& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_SpriteInstancedColor();
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pvb			���_�o�b�t�@�z��
				@param[in]		Cnt			���_�o�b�t�@�z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateVertexLayout(LPVertexBuffer* pvb, MofU32 Cnt = 0);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11ShaderBind_SpriteInstancedColor,MOF_DX11SHADERBINDSPRITEINSTANCEDBASECLASS_ID);
	};

	#include	"DX11ShaderBind_SpriteInstancedColor.inl"
	
	//�u������
	typedef CDX11ShaderBind_SpriteInstancedColor		CShaderBind_SpriteInstancedColor;
	typedef CShaderBind_SpriteInstancedColor*			LPShaderBind_SpriteInstancedColor;
}

#endif

//[EOF]