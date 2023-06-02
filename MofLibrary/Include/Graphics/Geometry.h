/*************************************************************************//*!
					
					@file	Geometry.h
					@brief	ジオメトリ基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GEOMETRY__H__

#define		__GEOMETRY__H__

//INCLUDE
#include	"MomCommon.h"
#include	"VertexBuffer.h"
#include	"IndexBuffer.h"
#include	"Material.h"
#include	"GeometryMorphing.h"
#include	"Shader.h"
#include	"ShaderBindBase.h"
#include	"MeshMotionController.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ジオメトリ基底インターフェイス

			ジオメトリ基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IGeometry : public IMofNamedObject, public IMofCopyObject< IGeometry >  {
	protected:
	public:
		/*************************************************************************//*!
				@brief			バッファの作成<br>
								ジオメトリ内部で登録されている、頂点バッファやインデックスバッファの生成をおこなう。<br>
								ジオメトリの頂点やインデックスの情報を変更した場合に実行する必要がある。
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CreateBuffer(void) = 0;
		
		/*************************************************************************//*!
				@brief			最大・最小計算<br>
								ジオメトリに含まれる頂点の最大位置と最小位置を求める。
				@param[out]		minv			出力用最小
				@param[out]		maxv			出力用最大
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateMinMax(Vector3& minv,Vector3& maxv) = 0;
		/*************************************************************************//*!
				@brief			指定ボーン名にウェイトを割り付けている、最大・最小座標計算
				@param[in]		pBName			ボーン名
				@param[out]		minv			出力用最小
				@param[out]		maxv			出力用最大
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateMinMax(LPCMofChar pBName, Vector3& minv, Vector3& maxv) = 0;

		/*************************************************************************//*!
				@brief			AABB計算<br>
								ジオメトリに含まれる頂点の境界ボックスを求める。
				@param[out]		aabb			出力用ボックス
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateAABB(BoxAABB& aabb) = 0;
		/*************************************************************************//*!
				@brief			指定ボーン名にウェイトを割り付けている、AABB計算
				@param[in]		pBName			ボーン名
				@param[out]		aabb			出力用ボックス
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateAABB(LPCMofChar pBName, BoxAABB& aabb) = 0;
		/*************************************************************************//*!
				@brief			境界球計算
				@param[out]		sph				出力用球
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateSphere(Sphere& sph) = 0;
		/*************************************************************************//*!
				@brief			指定ボーン名にウェイトを割り付けている、境界球計算
				@param[in]		pBName			ボーン名
				@param[out]		sph				出力用球
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateSphere(LPCMofChar pBName, Sphere& sph) = 0;
		
		/*************************************************************************//*!
				@brief			基本描画<br>
								バッファの設定と、描画のコールのみを行う。<br>
								マテリアルの設定など、シェーダーの設定は呼び出し前に行っておくこと。
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外			解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(void) = 0;

		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat) = 0;
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col) = 0;
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col,const Vector2& uv) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col,const Vector2& uv) = 0;

		
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind) = 0;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			変換行列設定
				@param[in]		mat				設定する変換行列
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetMatrix(CMatrix44& mat) = 0;
		/*************************************************************************//*!
				@brief			描画方式設定
				@param[in]		Topology		描画方式
				
				@return			TRUE			正常終了<br>
								それ以外		エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetTopology(PrimitiveTopology Topology) = 0;
		/*************************************************************************//*!
				@brief			頂点バッファ設定
				@param[in]		pBuff			設定バッファ
				
				@return			TRUE			正常終了<br>
								それ以外		エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetVertexBuffer(LPVertexBuffer pBuff) = 0;
		/*************************************************************************//*!
				@brief			インデックスバッファ設定
				@param[in]		pBuff			設定バッファ
				
				@return			TRUE			正常終了<br>
								それ以外		エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetIndexBuffer(LPIndexBuffer pBuff) = 0;
		/*************************************************************************//*!
				@brief			マテリアル設定
				@param[in]		pMat			設定マテリアル
				
				@return			TRUE			正常終了<br>
								それ以外		エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetMaterial(LPMaterial pMat) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			変換行列取得
				@param			None

				@return			変換行列の取得
		*//**************************************************************************/
		virtual CMatrix44& GetMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			頂点バッファ取得
				@param			None

				@return			頂点バッファ
		*//**************************************************************************/
		virtual LPVertexBuffer GetVertexBuffer(void) = 0;
		/*************************************************************************//*!
				@brief			頂点バッファ取得
				@param[in,out]	pOut			頂点バッファ配列<br>
												出力用のポインタがNULLなら格納されない。
				@param[in,out]	cnt				頂点バッファの数<br>
												実行時にはpOutの格納最大数を指定する。

				@return			TRUE			正常終了<br>
								それ以外		エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool GetVertexBuffer(LPVertexBuffer* pOut,MofU32& cnt) = 0;
		/*************************************************************************//*!
				@brief			頂点バッファフラグ取得
				@param			None

				@return			頂点バッファフラグ
		*//**************************************************************************/
		virtual VertexFlag GetVertexFlag(void) = 0;
		/*************************************************************************//*!
				@brief			インデックスバッファ取得
				@param			None

				@return			インデックスバッファ
		*//**************************************************************************/
		virtual LPIndexBuffer GetIndexBuffer(void) = 0;
		/*************************************************************************//*!
				@brief			マテリアル取得
				@param			None

				@return			マテリアル
		*//**************************************************************************/
		virtual LPMaterial GetMaterial(void) = 0;
		/*************************************************************************//*!
				@brief			モーフィング取得
				@param			None

				@return			モーフィング
		*//**************************************************************************/
		virtual LPGeometryMorphingArray GetMorphing(void) = 0;
		/*************************************************************************//*!
				@brief			対応ボーン名リスト取得
				@param			None

				@return			対応ボーン名リスト
		*//**************************************************************************/
		virtual LPStringArray GetBoneNameArray(void) = 0;
		/*************************************************************************//*!
				@brief			当たり判定用キャッシュ取得
				@param			None

				@return			当たり判定用キャッシュ
		*//**************************************************************************/
		virtual LPGeometryCollisionCache GetCollisionCache(void) = 0;
	};

	//ポインタ置き換え
	typedef IGeometry*		LPGeometry;
	typedef CDynamicArray< LPGeometry >		CGeometryArray,*LPGeometryArray;
}

#endif

//[EOF]