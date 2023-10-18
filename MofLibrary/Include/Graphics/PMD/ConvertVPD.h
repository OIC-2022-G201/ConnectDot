/*****************************************************************************
					
					［ファイル名］	ConvertVPD.h
					［処理概要］	VPDアニメーション変換クラス
					
															@author	CDW
															Since  2009.04.01
*****************************************************************************/

//ONCE
#ifndef		__CONVERTVPDANIMATION__H__

#define		__CONVERTVPDANIMATION__H__

//INCLUDE
#include	"../MeshContainer.h"
#include	"../BoneBase.h"
#include	"../MeshAnimationBase.h"
#include	"../MomCommon.h"

namespace Mof {

	//DEFINE
#define		VPDHEADERSTRING				"Vocaloid Pose Data file"
#define		VPDHEADERLENGTH				(24)

	//TYPEDEF STRUCT

	/*******************************//*!
	@brief	ＶＰＤファイルヘッダー構造体

			ＶＰＤファイルヘッダー構造体。

	@author	CDW
	*//********************************/
	typedef MOFLIBRARY_API struct tag_VPDHEADER {
		char							Header[VPDHEADERLENGTH];				//!<Vocaloid Pose Data file
		char							MName[256];								//!<モデル名
	}VPDHEADER, *LPVPDHEADER;

	//CLASS
	
	/*******************************//*!
	@brief	ＶＰＤファイル変換クラス

			ＶＰＤファイルの変換を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertVPD : public CReadTextFile {
	private:
		/*******************//*!
		アニメーションン格納モデル
		*//********************/
		LPMeshContainer					m_pMesh;
		/*******************//*!
		アニメーションン
		*//********************/
		LPMeshAnimation					m_pAnimation;

		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(void);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertAnimation(void);

		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[out]		pData		ヘッダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ReadHeader(LPVPDHEADER pData);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertVPD();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertVPD();
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、メッシュアニメーションとして返す
				@param[in]		pInName		入力ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、メッシュアニメーションとして返す
				@param[in]		pInName		入力ファイル名
				@param[in]		pMesh		入力メッシュ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPMeshContainer pMesh);
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			アニメーション取得
				@param			None

				@return			アニメーションの取得
		*//**************************************************************************/
		virtual LPMeshAnimation GetAnimation(void);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CConvertVPD, MOF_CONVERTVPDCLASS_ID);
	};

		//INLINE INCLUDE
	#include	"ConvertVPD.inl"

}

#endif	//__CONVERTVPDANIMATION__H__

//[EOF]