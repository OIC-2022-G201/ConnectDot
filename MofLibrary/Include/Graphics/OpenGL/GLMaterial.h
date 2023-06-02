/*************************************************************************//*!
					
					@file	GLMaterial.h
					@brief	OpenGLマテリアルクラス。

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
	@brief	OpenGLマテリアルクラス

			OpenGLマテリアルクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLMaterial : public CMaterialBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLMaterial();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param			pObj		コピーマテリアル

				@return			None
		*//**************************************************************************/
		CGLMaterial(const CGLMaterial& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLMaterial();
		
		/*************************************************************************//*!
				@brief			コピーバッファの作成
				@param			None

				@return			作成されたコピーバッファ<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual IMaterial* CreateCopyObject(void) const;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CGLMaterial,MOF_GLMATERIALCLASS_ID);
	};

	#include	"GLMaterial.inl"
	
	//置き換え
	typedef CGLMaterial		CMaterial;
}

#endif

//[EOF]