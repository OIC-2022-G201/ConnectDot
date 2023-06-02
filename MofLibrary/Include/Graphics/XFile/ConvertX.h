/*************************************************************************//*!
					
					@file	ConvertX.h
					@brief	Xファイルの変換を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTXFILE__H__

#define		__CONVERTXFILE__H__

//INCLUDE
#include	"AnalysX.h"
#include	"../MomCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	Ｘファイル変換クラス

			テキスト形式のＸファイルの変換を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertX : public CWriteChunkFile {
	private:
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pModel		Xファイル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMesh(LPXModel pModel);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pMesh		内部メッシュ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMesh(LPMOFXMESH pMesh);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pMesh		内部メッシュ
				@param[in]		pOffset		描画オフセット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertVertex(LPMOFXMESH pMesh,LPMOFXMATERIALOFFSET pOffset);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pMesh		内部メッシュ
				@param[in]		pOffset		描画オフセット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertIndex(LPMOFXMESH pMesh,LPMOFXMATERIALOFFSET pOffset);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pMaterial	描画マテリアル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMaterial(LPMOFXMATERIAL pMaterial);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pFrame		フレーム
				@param[in]		pWeight		ウェイト
				@param[in]		pMesh		メッシュ
				@param[in]		bCount		ボーン数
				@param[in]		mCount		メッシュ数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertBone(LPMOFXMESHFRAME pFrame,LPMOFXSKINWEIGHTS* pWeight,LPMOFXMESH* pMesh,MofU32 bCount,MofU32 mCount);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pWeight		ウェイト
				@param[in]		pMesh		メッシュ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertWeight(LPMOFXSKINWEIGHTS pWeight,LPMOFXMESH pMesh);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pAC			アニメーション
				@param[in]		at			アニメーションフレーム
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertAnimation(LPMOFXANIMATIONSET pAC,MofFloat at);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pAKey		アニメーション
				@param[in]		at			アニメーションフレーム
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertAnimationKey(LPMOFXANIMATIONKEY pAKey,MofFloat at);

	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertX();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertX();
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pInName		入力ファイル名
				@param[out]		pOutName	出力ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPCMofChar pOutName);
		
		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CConvertX,MOF_CONVERTXCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertX.inl"

}

#endif	//__CONVERTXFILE__H__

//[EOF]