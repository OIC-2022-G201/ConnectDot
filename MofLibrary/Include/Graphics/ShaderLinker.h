/*************************************************************************//*!
					
					@file	ShaderLinker.h
					@brief	�V�F�[�_�[���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERLINKER__H__

#define		__SHADERLINKER__H__

//INCLUDE
#include	"Shader.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�C���^�[�t�F�C�X

			�V�F�[�_�[�̓ǂݍ��݁A�ݒ���s�����߂̃C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShaderLinker : public IMofNamedObject {
	public:
		/*******************************//*!
		@brief	�����N�^

				�^���B

		@author	�_�c�@��
		*//********************************/
		struct LinkType {
			enum Enum {
				BOOL,
				INT,
				UINT,
				FLOAT,

				FVECTOR2,
				FVECTOR3,
				FVECTOR4,

				IVECTOR2,
				IVECTOR3,
				IVECTOR4,

				MATRIX42,
				MATRIX43,
				MATRIX44,
			};
		};
		/*******************************//*!
		@brief	�����N�^

				�^���B

		@author	�_�c�@��
		*//********************************/
		typedef struct tag_LINKDATA {
			/*******************//*!
			���O
			*//********************/
			CString					Name;
			/*******************//*!
			�^�C�v
			*//********************/
			LinkType::Enum			Type;
			/*******************//*!
			�o�b�t�@
			*//********************/
			LPShaderBuffer			pBuffer;
			/*******************//*!
			�I�t�Z�b�g
			*//********************/
			MofU32					Offset;
			/*******************//*!
			�T�C�Y
			*//********************/
			MofU32					Size;
			/*******************//*!
			���f�[�^
			*//********************/
			union {
				bool				b;
				MofS32				i;
				MofU32				ui;
				MofFloat			f;
				MofS32				iv[4];
				MofFloat			fv[4];
				MofS32				im[4][4];
				MofFloat			m[4][4];
			};
		}LINKDATA,*LPLINKDATA;
		typedef CDynamicArray< LPLINKDATA > LinkArray,*LPLinkArray;
		
		/*******************************//*!
		@brief	�����N�^

				�^���B

		@author	�_�c�@��
		*//********************************/
		typedef struct tag_LINKTEXTURE {
			/*******************//*!
			���O
			*//********************/
			CString					Name;
			/*******************//*!
			�ԍ�
			*//********************/
			MofU32					No;
			/*******************//*!
			�o�b�t�@
			*//********************/
			LPShaderResource		pBuffer;
		}LINKTEXTURE,*LPLINKTEXTURE;
		typedef CDynamicArray< LPLINKTEXTURE > LinkTextureArray,*LPLinkTextureArray;
	protected:
	public:
		/*************************************************************************//*!
				@brief			����
				@param[in]		pShader			��������V�F�[�_�[

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader) = 0;
		/*************************************************************************//*!
				@brief			����
				@param[in]		pShader			��������V�F�[�_�[
				@param[in]		pShaderBind		��������V�F�[�_�[

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader,LPShaderBind pBind) = 0;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ϐ��Ƃ̃����N�̎擾
				@param			None

				@return			�ϐ��Ƃ̃����N
		*//**************************************************************************/
		virtual LPLinkArray GetLink(void) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���Ƃ̃����N�̎擾
				@param			None

				@return			�e�N�X�`���Ƃ̃����N
		*//**************************************************************************/
		virtual LPLinkTextureArray GetTextureLink(void) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̎擾
				@param			None

				@return			�V�F�[�_�[
		*//**************************************************************************/
		virtual LPShader GetShader(void) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�o�C���h�̎擾
				@param			None

				@return			�V�F�[�_�[�o�C���h
		*//**************************************************************************/
		virtual LPShaderBind GetShaderBind(void) = 0;
	};

	//�|�C���^�u������
	typedef IShaderLinker*			LPShaderLinker;
}

#endif

//[EOF]