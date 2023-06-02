/*************************************************************************//*!
					
					@file	GLMaterial.h
					@brief	OpenGL�}�e���A���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLMATERIAL__H__

#define		__GLMATERIAL__H__

//INCLUDE
#include	"../MaterialBase.h"
#include	"GLTexture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	OpenGL�}�e���A���N���X

			OpenGL�}�e���A���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLMaterial : public CMaterialBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLMaterial();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param			pObj		�R�s�[�}�e���A��

				@return			None
		*//**************************************************************************/
		CGLMaterial(const CGLMaterial& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLMaterial();
		
		/*************************************************************************//*!
				@brief			�R�s�[�o�b�t�@�̍쐬
				@param			None

				@return			�쐬���ꂽ�R�s�[�o�b�t�@<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual IMaterial* CreateCopyObject(void) const;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		
		
		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLMaterial,MOF_GLMATERIALCLASS_ID);
	};

	#include	"GLMaterial.inl"
	
	//�u������
	typedef CGLMaterial		CMaterial;
}

#endif

//[EOF]