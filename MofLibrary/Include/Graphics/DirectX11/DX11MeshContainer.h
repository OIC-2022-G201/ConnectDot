/*************************************************************************//*!
					
					@file	DX11MeshContainer.h
					@brief	DirectX11���b�V���R���e�i�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11MESHCONTAINER__H__

#define		__DX11MESHCONTAINER__H__

//INCLUDE
#include	"../MeshContainerBase.h"
#include	"DX11Mesh.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V�����N���X

			���b�V�����N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11MeshContainer : public CMeshContainerBase {
	private:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11MeshContainer();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CDX11MeshContainer(const CDX11MeshContainer& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11MeshContainer();
		
		/*************************************************************************//*!
				@brief			���b�V���̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[���b�V��<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual IMeshContainer* CreateCopyObject(void) const;
				
		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11MeshContainer,MOF_DX11MESHCONTAINERCLASS_ID);
	};

	#include	"DX11MeshContainer.inl"
	
	//�u������
	typedef CDX11MeshContainer		CMeshContainer;
}

#endif	//__DX11MESH__H__

//[EOF]
