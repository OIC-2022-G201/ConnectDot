/*************************************************************************//*!
					
					@file	AnalysSprite.h
					@brief	MOSファイルの解析を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ANALYSSPRITE__H__

#define		__ANALYSSPRITE__H__

//INCLUDE
#include	"MosCommon.h"
#include	"Sprite2DContainer.h"
#include	"Sprite2DEffect.h"
#include	"Sprite3D.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MOSファイル解析クラス

			MOSファイルの解析を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CAnalysSprite : public CReadBinaryFile {
	private:
		/*******************//*!
		解析ID
		*//********************/
		MofU32						m_ID;
		/*******************//*!
		ファイルヘッダー
		*//********************/
		MOFSPRITEHEADER				m_Header;
		/*******************//*!
		ファイル検索用テクスチャリスト
		*//********************/
		LPTextureArray				m_pTextureArray;
		
		/*************************************************************************//*!
				@brief			MOSファイルを読み込む
				@param[in]		pSprite		スプライトファイル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Analys(LPSprite2DContainer pSprite);
		/*************************************************************************//*!
				@brief			MOSファイルを読み込む
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysTexture(void);
		/*************************************************************************//*!
				@brief			MOSファイルを読み込む
				@param[in]		pSprite		スプライト
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysSprite(LPSprite2DPart pSprite);
		/*************************************************************************//*!
				@brief			MOSファイルを読み込む
				@param[in]		pEffect		スプライト
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysEffect(LPSprite2DEffect pSprite);
		/*************************************************************************//*!
				@brief			MOSファイルを読み込む
				@param[in]		pAnim		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimation(LPSpriteContainerAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOSファイルを読み込む
				@param[in]		pAnim		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimation(LPSpritePartAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOSファイルを読み込む
				@param[in]		pAnim		アニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysAnimationKey(LPSpritePartAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOMファイルを読み込む
				@param[in]		kit			補間タイプ
				@param[out]		inval		補間数値
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysKeyInterpolation(MofU32 kit,LPMofFloat inval);
		/*************************************************************************//*!
				@brief			読み込みブロックの移動
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool MoveBlockOffset(void);
		/*************************************************************************//*!
				@brief			MOSファイルかを判定する<br>
								ファイルの先頭がMOFSPRITE_FILE_HEADERから始まればMOSファイル
				@param			None
				
				@return			TRUE		MOSファイル<br>
								それ以外	MOSファイルではない
		*//**************************************************************************/
		MofBool IsMOSFile(void);
		/*************************************************************************//*!
				@brief			MOSファイルフッターまで解析したかを判定する<br>
								現在位置からMOFSPRITE_FILE_FOOTERのデータになっていればフッター
				@param			None
				
				@return			TRUE							フッター<br>
								FALSE							まだフッターではない<br>
								MOFSPRITE_RESULTERROR_NOTFOOTER	フッターじゃないのにファイルが終了している
		*//**************************************************************************/
		MofBool IsMOSFooter(void);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CAnalysSprite();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAnalysSprite();
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行う
				@param[in]		pName		ファイル名
				@param[out]		pSprite		出力スプライト
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Analys(LPCMofChar pName,LPSprite2DContainer pSprite);
		/*************************************************************************//*!
				@brief			メモリから解析を行う
				@param[in]		pName		名前
				@param[in]		pBuffer		バッファ
				@param[in]		Size		サイズ
				@param[out]		pSprite		出力スプライト
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Analys(LPCMofChar pName,LPCMofVoid pBuffer,const MofU32 Size,LPSprite2DContainer pSprite);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CAnalysSprite,MOF_ANALYSSPRITECLASS_ID);
	};

	//INLINE INCLUDE
	#include	"AnalysSprite.inl"

}

#endif	//__ANALYSSPRITE__H__

//[EOF]