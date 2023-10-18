/*************************************************************************//*!
					
					@file	ConvertMDL.h
					@brief	MDLファイルの変換を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTMDLFILE__H__

#define		__CONVERTMDLFILE__H__

//INCLUDE
#include	"../MomCommon.h"
#include	"MDLCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ＭＤＬファイル変換クラス

			ＭＤＬファイルの変換を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertMDL : public CWriteChunkFile {
	private:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertMDL();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertMDL();
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pInName		入力ファイル名
				@param[out]		pOutName	出力ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPCMofChar pOutName);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pVL			描画頂点
				@param[in]		pIL			描画インデックス
				@param[in]		pOffset		描画オフセット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertVertex(LPMBSMODELVERTEXLIST pVL,LPMBSMODELINDEXLIST pIL,LPMBSMODELINDEXOFFSET pOffset);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pIL			描画インデックス
				@param[in]		pOffset		描画オフセット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertIndex(LPMBSMODELINDEXLIST pIL,LPMBSMODELINDEXOFFSET pOffset);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pMaterial	描画マテリアル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMaterial(LPMBSMATERIAL pMaterial);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pWeight		ウェイト
				@param[in]		pMesh		メッシュ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertWeight(LPMBSBONEWEIGHTLIST pWeight,LPMBSMESH pMesh);
		
		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CConvertMDL,MOF_CONVERTMDLCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertMDL.inl"

}

#endif	//__CONVERTMDLFILE__H__

//[EOF]