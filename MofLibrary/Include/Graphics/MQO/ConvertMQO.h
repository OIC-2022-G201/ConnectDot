/*************************************************************************//*!
					
					@file	ConvertMQO.h
					@brief	MQOファイルの変換を行うクラス。

															@author	CDW
															@date	2015.12.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTMQOFILE__H__

#define		__CONVERTMQOFILE__H__

//INCLUDE
#include	"AnalysMQO.h"
#include	"../MomCommon.h"
#include	"../MeshContainer.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MQOファイル変換クラス

			MQOファイルの変換を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertMQO : public CWriteChunkFile {
	private:
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pModel		MQOファイル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMesh(LPMQOModel pModel);
		/*************************************************************************//*!
				@brief			頂点を変換する
				@param[in]		TempVertices	頂点の配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertVertex(MOFMQOTEMPVERTEXARRAY& TempVertices);
		/*************************************************************************//*!
				@brief			インデックスを変換する
				@param[in]		Indices		インデックスの配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertIndex(CDynamicArray<MofU32>& Indices);
		/*************************************************************************//*!
				@brief			マテリアルを変換する
				@param[in]		pMQOMat		マテリアル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMaterial(LPMOFMQOMATERIAL pMQOMat);

		/*************************************************************************//*!
				@brief			MQOのオブジェクト情報を中間ジオメトリデータに変換する
				@param[in]		pMQOObj			MQOのオブジェクト情報
				@param[in]		MaterialIndex	対象のマテリアルインデックス
				@param[out]		TempGeo			出力
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool ConvertTempGeometry(LPMOFMQOOBJECT pMQOObj,MofU32 MaterialIndex,MOFMQOTEMPGEOMETRY& TempGeo);
		/*************************************************************************//*!
				@brief			ミラーの作成
				@param[in]		pMQOObj			MQOのオブジェクト情報
				@param[in,out]	TempGeometrys	ミラー処理を行うジオメトリ配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool CreateMirror(LPMOFMQOOBJECT pMQOObj,MOFMQOTEMPGEOMETRYARRAY& TempGeometrys);
		/*************************************************************************//*!
				@brief			指定の辺がフチかどうか判定
				@param[in]		TempGeometrys		ジオメトリ配列
				@param[in]		FirstMirrorFaces	ミラー処理で追加された最初の面
				@param[in]		TargetA				フチかどうかを判定する辺を構成する一つ目の頂点座標
				@param[in]		TargetB				フチかどうかを判定する辺を構成する二つ目の頂点座標
				
				@return			TRUE		フチ<br>
								それ以外	フチではない
		*//**************************************************************************/
		static MofBool IsBoundaryEdge(MOFMQOTEMPGEOMETRYARRAY &TempGeometrys,LPMOFMQOTEMPFACE* FirstMirrorFaces,const Vector3& TargetA,const Vector3& TargetB);
		/*************************************************************************//*!
				@brief			法線の計算
				@param[in]		pMQOObj			MQOのオブジェクト情報
				@param[in,out]	TempGeometrys	法線の計算を行うジオメトリ配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool CalculationNormal(LPMOFMQOOBJECT pMQOObj,MOFMQOTEMPGEOMETRYARRAY &TempGeometrys);
		/*************************************************************************//*!
				@brief			面の集まりを頂点の配列とインデックスの配列に変換
				@param[in]		TempGeo		面の集まり
				@param[out]		Vertices	頂点出力配列
				@param[out]		Indices		インデックス出力配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool CreateTempVertexArray(MOFMQOTEMPGEOMETRY& TempGeo,MOFMQOTEMPVERTEXARRAY& Vertices,CDynamicArray<MofU32>& Indices);
		/*************************************************************************//*!
				@brief			頂点配列から指定した頂点と同一の頂点があるインデックスを取得
				@param[in,out]	Vertices	頂点配列、同一頂点が見つからない場合末尾に追加される
				@param[in]		TmpVert		検索頂点
				
				@return			頂点のインデックス
		*//**************************************************************************/
		static MofU32 GetTempVertexIndex(MOFMQOTEMPVERTEXARRAY& Vertices,const MOFMQOTEMPVERTEX& TmpVert);
		/*************************************************************************//*!
				@brief			頂点配列から指定した頂点と同一の頂点があるインデックスを取得
				@param[in]		Vertices		頂点配列
				@param[in]		TargetVertex	検索頂点
				
				@return			頂点のインデックス<br>
								見つからない場合はMOF_U32_MAXを返す
		*//**************************************************************************/
		static MofU32 FindTempVertex(MOFMQOTEMPVERTEXARRAY& Vertices,const MOFMQOTEMPVERTEX& TargetVertex);

	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertMQO();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertMQO();
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pInName		入力ファイル名
				@param[in]		pOutName	出力ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(const LPMofChar pInName,const LPMofChar pOutName);
		
		/*************************************************************************//*!
				@brief			MQOの面構造体から頂点を取得する
				@param[in]		Face		MQOの面構造体
				@param[in]		Index		頂点のインデックス
				
				@return			面を構成する頂点
		*//**************************************************************************/
		static LPMOFMQOTEMPVERTEX GetFaceVertex(MOFMQOTEMPFACE& Face,MofU32 Index);
		/*************************************************************************//*!
				@brief			MQOの面構造体から三角形を取得する
				@param[in]		Face		MQOの面構造体
				@param[in]		Index		三角形のインデックス
				@param[out]		pOut		三角形の各頂点を格納する長さ3の配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool GetFaceTriangle(MOFMQOTEMPFACE& Face,MofU32 Index,LPMOFMQOTEMPVERTEX* pOut);
		/*************************************************************************//*!
				@brief			MQOの面構造体から辺を取得する
				@param[in]		Face		MQOの面構造体
				@param[in]		Index		辺のインデックス
				@param[out]		pOutVertA	辺を構成する一つ目の頂点
				@param[out]		pOutVertB	辺を構成する二つ目の頂点
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool GetFaceEdge(MOFMQOTEMPFACE& Face,MofU32 Index,LPMOFMQOTEMPVERTEX& pOutVertA,LPMOFMQOTEMPVERTEX& pOutVertB);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CConvertMQO,MOF_CONVERTMQOCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertMQO.inl"

}

#endif	//__CONVERTMQOFILE__H__

//[EOF]