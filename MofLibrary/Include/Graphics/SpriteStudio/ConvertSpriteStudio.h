/*************************************************************************//*!
					
					@file	ConvertSpriteStudio.h
					@brief	スプライトスタジオのssaeファイルの変換を行うためのクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTSPRITESTUDIOFILE__H__

#define		__CONVERTSPRITESTUDIOFILE__H__

//INCLUDE
#include	"../MosCommon.h"
#include	"../Texture.h"

#ifdef		MOFLIB_CONVERTSS

#if defined(DEBUG) || defined(_DEBUG)

#if _MSC_VER >= 1910

#pragma comment (lib,"ssloader2017_md32_d.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"ssloader2015_md32_d.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"ssloader2013_md32_d.lib")

#else

#pragma comment (lib,"ssloader_md32_d.lib")

#endif // _MSC_VER == 1800

#else

#if _MSC_VER >= 1910

#pragma comment (lib,"ssloader2017_md32.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"ssloader2015_md32.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"ssloader2013_md32.lib")

#else

#pragma comment (lib,"ssloader_md32.lib")

#endif // _MSC_VER == 1800

#endif

namespace Mof {
	
	/*******************************//*!
	@brief	スプライトスタジオファイル変換クラス

			スプライトスタジオのssaeファイルの変換を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertSpriteStudio : public CWriteChunkFile {
	private:
		/*******************//*!
		変換ベースパス
		*//********************/
		CString				m_Directory;
		/*******************//*!
		設定
		*//********************/
		SsAnimationSettings	m_Settings;
		/*******************//*!
		セルマップの数
		*//********************/
		MofU32				m_CellMapCount;
		/*******************//*!
		セルマップの数
		*//********************/
		MofU32				m_CellMapNum;
		/*******************//*!
		セルマップ
		*//********************/
		SsCellMap**			m_ppCellMap;
		
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pInName		入力ファイル名
				@param[out]		pOutName	出力ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertSSAE(LPCMofChar pInName,LPCMofChar pOutName);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pInName		入力ファイル名
				@param[out]		pOutName	出力ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertSSEE(LPCMofChar pInName,LPCMofChar pOutName);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pAnim		ssaeアニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(SsAnimePack* pAnim);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pAnim		sseeアニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pSprite		スプライト
				@param[in]		pModel		スプライト格納モデル
				@param[in]		pAnim		sseeアニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(SsPart* pSprite, SsAnimePack* pModel, SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pName		セルマップ名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertCellMap(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pSprite		スプライト
				@param[in]		pModel		スプライト格納モデル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertSprite(SsPart* pSprite,SsAnimePack* pModel);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pAnim		ssaeアニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertAnimation(SsAnimation* pAnim);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pEffect		エフェクト
				@param[in]		pAnim		sseeアニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertEffect(SsEffectNode* pEffect, SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pSprite		スプライト
				@param[in]		pModel		スプライト格納モデル
				@param[in]		pEffect		エフェクト
				@param[in]		pAnim		sseeアニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertEffect(SsPart* pSprite, SsAnimePack* pModel, SsEffectNode* pEffect, SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pEffect		エフェクト
				@param[in]		pAnim		sseeアニメーション
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertEffectParameter(SsEffectNode* pEffect, SsEffectFile* pAnim);
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pAnim		ssaeアニメーション
				@param[in]		mt			最大時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertPartAnimation(SsPartAnime* pAnim, int mt);
		/*************************************************************************//*!
				@brief			キーに変換する
				@param[in]		attr		属性テーブル
				@param[in]		mt			最大時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConverFloatKey(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			キーに変換する
				@param[in]		attr		属性テーブル
				@param[in]		mt			最大時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConverBoolKey(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			キーに変換する
				@param[in]		attr		属性テーブル
				@param[in]		mt			最大時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConverS32Key(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			文字列からベクトル2データを取り出す
				@param[in]		str			文字
				@param[in]		point		ベクトル２
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertStringToVector2(const std::string& str, Vector2& point);
		/*************************************************************************//*!
				@brief			文字列からベクトル4データを取り出す
				@param[in]		str			文字
				@param[in]		color		ベクトル４
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertStringToColor(const std::string& str, Vector4& color);
		/*************************************************************************//*!
				@brief			文字列からブレンドターゲットを取り出す
				@param[in]		str			文字
				@param[in]		out			出力
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertStringToBlendTarget(const std::string& str, SsColorBlendTarget::_enum& out);
		/*************************************************************************//*!
				@brief			文字列からブレンドターゲットを取り出す
				@param[in]		str			文字
				@param[in]		out			出力
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertStringToBlendType(const std::string& str, SsBlendType::_enum& out);
		/*************************************************************************//*!
				@brief			キーに変換する
				@param[in]		attr		属性テーブル
				@param[in]		n			番号
				@param[in]		mt			最大時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConverVertexKey(SsAttribute* attr, MofU32 n, int mt);
		/*************************************************************************//*!
				@brief			キーに変換する
				@param[in]		attr		属性テーブル
				@param[in]		n			番号
				@param[in]		mt			最大時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConverColorKey(SsAttribute* attr, MofU32 n, int mt);
		/*************************************************************************//*!
				@brief			キーに変換する
				@param[in]		attr		属性テーブル
				@param[in]		mt			最大時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConverColorRateKey(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			キーに変換する
				@param[in]		attr		属性テーブル
				@param[in]		mt			最大時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConverEffectKey(SsAttribute* attr, int mt);
		/*************************************************************************//*!
				@brief			スプライトタイプを独自形式に変換する
				@param[in]		t			SpriteStudioのスプライトタイプ
				
				@return			独自形式でのスプライトタイプ
		*//**************************************************************************/
		MofU32 ConvertSpriteType(SsPartType::_enum t);
		/*************************************************************************//*!
				@brief			エフェクトタイプを独自形式に変換する
				@param[in]		t			SpriteStudioのエフェクトタイプ
				
				@return			独自形式でのスプライトタイプ
		*//**************************************************************************/
		MofU32 ConvertEffectType(SsEffectNodeType::_enum t);
		/*************************************************************************//*!
				@brief			ブレンディング方法を独自形式に変換する
				@param[in]		t			SpriteStudioのブレンディングタイプ
				
				@return			独自形式でのブレンディング方法
		*//**************************************************************************/
		MofU32 ConvertBlendingType(SsBlendType::_enum t);
		/*************************************************************************//*!
				@brief			ブレンディング方法を独自形式に変換する
				@param[in]		t			SpriteStudioのブレンディングタイプ
				
				@return			独自形式でのブレンディング方法
		*//**************************************************************************/
		MofU32 ConvertBlendingType(SsRenderBlendType::_enum t);
		/*************************************************************************//*!
				@brief			キータイプを独自形式に変換する
				@param[in]		t			SpriteStudioのキータイプ
				
				@return			独自形式でのキータイプ
		*//**************************************************************************/
		MofU32 ConvertKeyType(SsAttributeKind::_enum t);
		/*************************************************************************//*!
				@brief			キー補間タイプを独自形式に変換する
				@param[in]		t			SpriteStudioのキー補間タイプ
				
				@return			独自形式でのキータイプ
		*//**************************************************************************/
		MofU32 ConvertKeyInterpolationType(SsInterpolationType::_enum t);
		/*************************************************************************//*!
				@brief			補間情報に変換する
				@param[in]		pKey		キー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertKeyInterpolation(SsKeyframe* pKey);
		
		/*************************************************************************//*!
				@brief			対象パーツの最初のセルマップ名を取得
				@param[in]		pSprite		スプライト
				@param[in]		pModel		スプライト格納モデル
				@param[out]		pString		セルマップ画像名
				
				@return			セルマップ<br>
								見つからない場合ＮＵＬＬを返す
		*//**************************************************************************/
		SsCell* GetFirstCellName(SsPart* pSprite,SsAnimePack* pModel,CString& pString);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertSpriteStudio();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertSpriteStudio();
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
		MOF_LIBRARYCLASS_NOTCOPY(CConvertSpriteStudio,MOF_CONVERTSPRITESTUDIOCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertSpriteStudio.inl"

}

#endif

#endif	//__CONVERTSPRITESTUDIOFILE__H__

//[EOF]