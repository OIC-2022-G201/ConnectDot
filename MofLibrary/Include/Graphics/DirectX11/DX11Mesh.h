/*************************************************************************//*!
					
					@file	DX11Mesh.h
					@brief	DirectX11���b�V���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11MESH__H__

#define		__DX11MESH__H__

//INCLUDE
#include	"../MeshBase.h"
#include	"DX11Geometry.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V�����N���X

			���b�V�����N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Mesh : public CMeshBase {
	private:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Mesh();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CDX11Mesh(const CDX11Mesh& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Mesh();
		
		/*************************************************************************//*!
				@brief			���b�V���̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[���b�V��<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual IMesh* CreateCopyObject(void) const;
				
		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11Mesh,MOF_DX11MESHCLASS_ID);
	};

	#include	"DX11Mesh.inl"
	
	//�u������
	typedef CDX11Mesh		CMesh;
}

#endif	//__DX11MESH__H__

//[EOF]
