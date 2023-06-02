/*************************************************************************//*!
					
					@file	DX11Geometry.h
					@brief	DirectX11ジオメトリクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11GEOMETRY__H__

#define		__DX11GEOMETRY__H__

//INCLUDE
#include	"../GeometryBase.h"
#include	"DX11VertexBuffer.h"
#include	"DX11IndexBuffer.h"
#include	"DX11Material.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11ジオメトリクラス

			DirectX11ジオメトリクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Geometry : public CGeometryBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Geometry();
		/*************************************************************************//*!
				@brief			バッファ指定コンストラクタ
				@param[in]		pName		名前
				@param[in]		Topology	描画方式
				@param[in]		pVBuff		頂点バッファ
				@param[in]		pIBuff		インデックスバッファ
				@param[in]		pMaterial	マテリアル

				@return			None
		*//**************************************************************************/
		CDX11Geometry(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピージオメトリ

				@return			None
		*//**************************************************************************/
		CDX11Geometry(const CDX11Geometry& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Geometry();
		
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
		MOF_LIBRARYCLASS(CDX11Geometry,MOF_DX11GEOMETRYCLASS_ID);
	};

	#include	"DX11Geometry.inl"
	
	//置き換え
	typedef CDX11Geometry		CGeometry;
}

#endif

//[EOF]