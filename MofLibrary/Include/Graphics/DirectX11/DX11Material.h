/*************************************************************************//*!
					
					@file	DX11Material.h
					@brief	DirectX11�}�e���A���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11MATERIAL__H__

#define		__DX11MATERIAL__H__

//INCLUDE
#include	"../MaterialBase.h"
#include	"DX11Texture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11�}�e���A���N���X

			DirectX11�}�e���A���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Material : public CMaterialBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Material();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�}�e���A��

				@return			None
		*//**************************************************************************/
		CDX11Material(const CDX11Material& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Material();
		
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
		MOF_LIBRARYCLASS(CDX11Material,MOF_DX11MATERIALCLASS_ID);
	};

	#include	"DX11Material.inl"
	
	//�u������
	typedef CDX11Material		CMaterial;
}

#endif

//[EOF]