/*************************************************************************//*!
					
					@file	DX11MeshContainer.h
					@brief	DirectX11メッシュコンテナクラス。

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
	@brief	メッシュ基底クラス

			メッシュ基底クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11MeshContainer : public CMeshContainerBase {
	private:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11MeshContainer();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピージオメトリ

				@return			None
		*//**************************************************************************/
		CDX11MeshContainer(const CDX11MeshContainer& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11MeshContainer();
		
		/*************************************************************************//*!
				@brief			メッシュのコピー生成
				@param			None
				
				@return			作成されたコピーメッシュ<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual IMeshContainer* CreateCopyObject(void) const;
				
		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11MeshContainer,MOF_DX11MESHCONTAINERCLASS_ID);
	};

	#include	"DX11MeshContainer.inl"
	
	//置き換え
	typedef CDX11MeshContainer		CMeshContainer;
}

#endif	//__DX11MESH__H__

//[EOF]
