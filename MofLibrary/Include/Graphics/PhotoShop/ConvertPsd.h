/*************************************************************************//*!
					
					@file	ConvertPsd.h
					@brief	PhotoShopのpsdファイルの変換を行うためのクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTPSD__H__

#define		__CONVERTPSD__H__

//INCLUDE
#include	"../MosCommon.h"
#include	"../Texture.h"
#include	"PSDReader.h"

namespace Mof {
	
	/*******************************//*!
	@brief	PSDファイル変換クラス

			PhotoShopのpsdファイルの変換を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertPsd : public CWriteChunkFile {
	private:
		/*******************//*!
		PSDファイル
		*//********************/
		CPSDReader					m_Psd;
		
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(void);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pLayer		変換レイヤー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertSprite(LPPSDLAYERINFO pLayer);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pLayer		変換レイヤー
				@param[in,out]	Offset		現在オフセット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertSprite(LPPSDLAYERINFO pLayer,MofU32& Offset);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertPsd();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertPsd();
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pInName		入力ファイル名
				@param[out]		pOutName	出力ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPCMofChar pOutName);
		
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CConvertPsd,MOF_CONVERTPSDCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertPsd.inl"

}

#endif	//__CONVERTPSD__H__

//[EOF]