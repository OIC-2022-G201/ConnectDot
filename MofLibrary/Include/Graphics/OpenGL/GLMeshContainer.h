/*************************************************************************//*!
					
					@file	GLMeshContainer.h
					@brief	OpenGLメッシュコンテナクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLMESHCONTAINER__H__

#define		__GLMESHCONTAINER__H__

//INCLUDE
#include	"../MeshContainerBase.h"
#include	"GLMesh.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュ基底クラス

			メッシュ基底クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLMeshContainer : public CMeshContainerBase {
	private:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLMeshContainer();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param			pObj		コピージオメトリ

				@return			None
		*//**************************************************************************/
		CGLMeshContainer(const CGLMeshContainer& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLMeshContainer();
		
		/*************************************************************************//*!
				@brief			メッシュのコピー生成
				@param			None
				
				@return			作成されたコピーメッシュ<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual IMeshContainer* CreateCopyObject(void) const;
				
		//クラス基本定義
		MOF_LIBRARYCLASS(CGLMeshContainer,MOF_GLMESHCONTAINERCLASS_ID);
	};

	#include	"GLMeshContainer.inl"
	
	//置き換え
	typedef CGLMeshContainer		CMeshContainer;
}

#endif	//__GLMESH__H__

//[EOF]
