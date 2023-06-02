/*************************************************************************//*!
					
					@file	GeometryInstancedBase.h
					@brief	ジオメトリインスタンス基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GEOMETRYINSTANCEDBASE__H__

#define		__GEOMETRYINSTANCEDBASE__H__

//INCLUDE
#include	"GeometryBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ジオメトリ基底クラス

			ジオメトリ基底となるクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGeometryInstancedBase : public CGeometryBase {
	protected:
		/*******************//*!
		描画インスタンスの数
		*//********************/
		MofU32						m_RenderInstanceCount;
		/*******************//*!
		頂点バッファ
		*//********************/
		LPVertexBuffer				m_pInstancedBuffer;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase();
		/*************************************************************************//*!
				@brief			バッファ指定コンストラクタ
				@param[in]		pName			名前
				@param[in]		Topology		描画方式
				@param[in]		pVBuff			頂点バッファ
				@param[in]		pIBuff			インデックスバッファ
				@param[in]		pMaterial		マテリアル
				@param[in]		InstanceCount	インスタンス最大数

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, MofU32 InstanceCount);
		/*************************************************************************//*!
				@brief			バッファ指定コンストラクタ
				@param[in]		pName			名前
				@param[in]		Topology		描画方式
				@param[in]		pVBuff			頂点バッファ
				@param[in]		pIBuff			インデックスバッファ
				@param[in]		pMaterial		マテリアル
				@param[in]		pInstanceBuff	インスタンスバッファ

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピージオメトリ
				@param[in]		InstanceCount	インスタンス最大数

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase(const CGeometryBase& pObj,MofU32 InstanceCount);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピージオメトリ
				@param[in]		pInstanceBuff	インスタンスバッファ

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase(const CGeometryBase& pObj, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピージオメトリ

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase(const CGeometryInstancedBase& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGeometryInstancedBase();
		
		/*************************************************************************//*!
				@brief			バッファの作成
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CreateBuffer(void);
		
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			インスタンス用バッファ設定
				@param[in]		pBuff			設定バッファ
				
				@return			TRUE			正常終了<br>
								それ以外		エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetInstancedBuffer(LPVertexBuffer pBuff);
		/*************************************************************************//*!
				@brief			インスタンス用バッファ設定
				@param[in]		mat				行列
				@param[in]		cnt				行列数
				
				@return			TRUE			正常終了<br>
								それ以外		エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetInstancedMatrix(Matrix44* mat,MofU32 cnt);
		/*************************************************************************//*!
				@brief			インスタンス用バッファ設定
				@param[in]		pBuff			設定バッファ
				@param[in]		Size			設定サイズ
				
				@return			TRUE			正常終了<br>
								それ以外		エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetInstancedBuffer(LPMofVoid pBuff, MofU32 Size);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			頂点バッファ取得
				@param			None

				@return			頂点バッファ
		*//**************************************************************************/
		virtual LPVertexBuffer GetVertexBuffer(void);
		/*************************************************************************//*!
				@brief			頂点バッファ取得
				@param[in,out]	pOut			頂点バッファ配列<br>
												出力用のポインタがNULLなら格納されない。
				@param[in,out]	cnt				頂点バッファの数<br>
												実行時にはpOutの格納最大数を指定する。

				@return			TRUE			正常終了<br>
								それ以外		エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool GetVertexBuffer(LPVertexBuffer* pOut,MofU32& cnt);
		/*************************************************************************//*!
				@brief			頂点バッファフラグ取得
				@param			None

				@return			頂点バッファフラグ
		*//**************************************************************************/
		virtual VertexFlag GetVertexFlag(void);
		/*************************************************************************//*!
				@brief			インスタンス用バッファ取得
				@param			None

				@return			インスタンス用バッファ
		*//**************************************************************************/
		virtual LPVertexBuffer GetInstancedBuffer(void);
	};

	#include	"GeometryInstancedBase.inl"

	//ポインタ置き換え
	typedef CGeometryInstancedBase*		LPGeometryInstanced;
}

#endif

//[EOF]