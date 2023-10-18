/*************************************************************************//*!
					
					@file	AnalysMesh.h
					@brief	MOMファイルの解析を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ANALYSMESH__H__

#define		__ANALYSMESH__H__

//INCLUDE
#include	"MeshContainer.h"
#include	"BoneBase.h"
#include	"MeshAnimationBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MOMファイル解析クラス

			MOMファイルの解析を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CAnalysMesh : public CReadBinaryFile {
	private:
		/*******************//*!
		ファイルヘッダー
		*//********************/
		MOFMODELHEADER				m_Header;
		/*******************//*!
		検索用テクスチャリスト
		*//********************/
		LPTextureArray				m_pTextureArray;
		
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pModel		メッシュファイル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Analys(LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pModel		メッシュファイル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysMesh(LPMesh pModel);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pModel		メッシュファイル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysMeshBlock(LPMesh pModel);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pGeometry	ジオメトリ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysGeometry(LPGeometry pGeometry);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pVert		頂点
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysVertex(LPVertexBuffer pVert);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pInd		インデックス
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysIndex(LPIndexBuffer pInd);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pMat		マテリアル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysMaterial(LPMaterial pMat);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pMorphing	マテリアル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysMorphing(LPGeometryMorphing pMorphing);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pMorphing	マテリアル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysMorphingPosition(LPGeometryMorphing pMorphing);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pMat		マテリアル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysTexture(LPMaterial pMat);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pBone		ボーン
				@param[in]		pModel		メッシュファイル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysBone(LPBone pBone,LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pBone		ボーン
				@param[in]		pModel		メッシュファイル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysBoneWeight(LPBone pBone,LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pBone		ボーン
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysIK(LPBone pBone);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pAnim		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimation(LPMeshAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pAnim		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimation(LPMeshBoneAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pAnim		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimation2(LPMeshBoneAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pAnim		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimation(LPMeshMorphingAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pAnim		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimationKey(LPMeshBoneAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pAnim		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimationKey(LPMeshMorphingAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		kit			補間タイプ
				@param[out]		inval		補間数値
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysKeyInterpolation(MofU32 kit,LPMofFloat inval);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pRigid		剛体情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysRigid(LPMOMPHYSICSRIGIDINFO pRigid);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pJoint		ジョイント情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysRigidJoint(LPMOMPHYSICSJOINTINFO pJoint);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pCamera		カメラ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysCamera(LPMeshCamera pCamera);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pCamera		カメラ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysCameraAnimation(LPMeshCameraAnimation pCamera);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		pCamera		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysCameraAnimationKey(LPMeshCameraAnimation pCamera);
		/*************************************************************************//*!
				@brief			読み込みブロックの移動
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool MoveBlockOffset(void);
		/*************************************************************************//*!
				@brief			MOMファイルかを判定する<br>
								ファイルの先頭がMOFMODEL_FILE_HEADERから始まればMOMファイル
				@param			None
				
				@return			TRUE		MOMファイル<br>
								それ以外	MOMファイルではない
		*//**************************************************************************/
		MofBool IsMOMFile(void);
		/*************************************************************************//*!
				@brief			MOMファイルフッターまで解析したかを判定する<br>
								現在位置からMOFMODEL_FILE_FOOTERのデータになっていればフッター
				@param			None
				
				@return			TRUE							フッター<br>
								FALSE							まだフッターではない<br>
								MOFMODEL_RESULTERROR_NOTFOOTER	フッターじゃないのにファイルが終了している
		*//**************************************************************************/
		MofBool IsMOMFooter(void);
		/*************************************************************************//*!
				@brief			MOMファイルからアニメーション部だけを読み込む
				@param[out]		pModel		出力モデル
				@param[out]		pAnim		アタッチするアニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AttachAnimation(LPMeshContainer pModel, LPMeshAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOMファイルからアニメーション部だけを読み込む
				@param[out]		pModel		出力モデル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			MOMファイルからアニメーション部だけを読み込む
				@param[in]		pAnimations	出力アニメーション配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPMeshAnimationArray pAnimations);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CAnalysMesh();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAnalysMesh();
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行う
				@param[in]		pName		ファイル名
				@param[out]		pModel		出力モデル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Analys(LPCMofChar pName,LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			メモリから解析を行う
				@param[in]		pName		名前
				@param[in]		pBuffer		バッファ
				@param[in]		Size		サイズ
				@param[out]		pModel		出力モデル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Analys(LPCMofChar pName,LPCMofVoid pBuffer,const MofU32 Size,LPMeshContainer pModel);
		
		/*************************************************************************//*!
				@brief			ファイルを開いてアニメーション部のみ解析を行う
				@param[in]		pName		ファイル名
				@param[out]		pModel		出力モデル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPCMofChar pName, LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			メモリからアニメーション部のみ解析を行う
				@param[in]		pName		名前
				@param[in]		pBuffer		バッファ
				@param[in]		Size		サイズ
				@param[out]		pModel		出力モデル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPCMofChar pName, LPCMofVoid pBuffer, const MofU32 Size, LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			ファイルを開いてアニメーション部のみ解析を行う
				@param[in]		pName		ファイル名
				@param[out]		pAnimations		出力アニメーション配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPCMofChar pName,LPMeshAnimationArray pAnimations);
		/*************************************************************************//*!
				@brief			メモリからアニメーション部のみ解析を行う
				@param[in]		pName		名前
				@param[in]		pBuffer		バッファ
				@param[in]		Size		サイズ
				@param[out]		pAnimations		出力アニメーション配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPCMofChar pName,LPCMofVoid pBuffer,const MofU32 Size,LPMeshAnimationArray pAnimations);
		
		
		/*************************************************************************//*!
				@brief			テクスチャ検索配列設定
				@param[in]		pTex		テクスチャ検索配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool SetTextureArray(LPTextureArray pTex);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CAnalysMesh,MOF_ANALYSMESHCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"AnalysMesh.inl"

}

#endif	//__ANALYSMESH__H__

//[EOF]