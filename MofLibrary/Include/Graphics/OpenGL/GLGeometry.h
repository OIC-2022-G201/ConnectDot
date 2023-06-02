/*************************************************************************//*!
					
					@file	GLGeometry.h
					@brief	OpenGLジオメトリクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLGEOMETRY__H__

#define		__GLGEOMETRY__H__

//INCLUDE
#include	"../GeometryBase.h"
#include	"GLVertexBuffer.h"
#include	"GLIndexBuffer.h"
#include	"GLMaterial.h"

namespace Mof {
	
	/*******************************//*!
	@brief	OpenGLジオメトリクラス

			OpenGLジオメトリクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLGeometry : public CGeometryBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLGeometry();
		/*************************************************************************//*!
				@brief			バッファ指定コンストラクタ
				@param[in]		pName		名前
				@param[in]		Topology	描画方式
				@param[in]		pVBuff		頂点バッファ
				@param[in]		pIBuff		インデックスバッファ
				@param[in]		pMaterial	マテリアル

				@return			None
		*//**************************************************************************/
		CGLGeometry(LPCMofChar pName,PrimitiveTopology Topology,LPVertexBuffer pVBuff,LPIndexBuffer pIBuff,LPMaterial pMaterial);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param			pObj		コピージオメトリ

				@return			None
		*//**************************************************************************/
		CGLGeometry(const CGLGeometry& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLGeometry();
		
		/*************************************************************************//*!
				@brief			メッシュのコピー生成
				@param			None
				
				@return			作成されたコピーメッシュ<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual IGeometry* CreateCopyObject(void) const;
		
		/*************************************************************************//*!
				@brief			基本描画<br>
								バッファの設定と、描画のコールのみを行う。<br>
								マテリアルの設定など、シェーダーの設定は呼び出し前に行っておくこと。
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(void);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CGLGeometry,MOF_GLGEOMETRYCLASS_ID);
	};

	#include	"GLGeometry.inl"
	
	//置き換え
	typedef CGLGeometry		CGeometry;
}

#endif

//[EOF]
