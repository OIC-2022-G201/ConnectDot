/*************************************************************************//*!
					
					@file	DX11Font.h
					@brief	DirectX11フォントクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11FONT__H__

#define		__DX11FONT__H__

//INCLUDE
#include	"../FontBase.h"
#include	"DX11Texture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11フォントクラス

			DirectX11フォントの読み込み、設定を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Font : public CFontBase {
	protected:
		/*******************//*!
		テクスチャ
		*//********************/
		LPTexture				m_pTexture;
		/*******************//*!
		フォントハンドル
		*//********************/
		MofFont					m_hFont;
		/*******************//*!
		文字挿入X位置
		*//********************/
		MofU32					m_InsertX;
		/*******************//*!
		文字挿入Y位置
		*//********************/
		MofU32					m_InsertY;
		/*******************//*!
		文字挿入ライン高さ
		*//********************/
		MofU32					m_InsertHeight;
		/*******************//*!
		内部管理文字列
		*//********************/
		LPFontCharaInputArray	m_pInputArray;
		/*******************//*!
		テクスチャ内部バッファ
		*//********************/
		LPMofU8					m_pFontBuffer;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Font();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Font();
		
		/*************************************************************************//*!
				@brief			フォントの生成
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(void);
		/*************************************************************************//*!
				@brief			フォントの生成
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(MofFont hFont);
		/*************************************************************************//*!
				@brief			フォントの生成
				@param[in]		s			文字サイズ
				@param[in]		pFace		文字タイプ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,LPCMofChar pFace);
		/*************************************************************************//*!
				@brief			フォントの生成
				@param[in]		s			文字サイズ
				@param[in]		bold		太さ
				@param[in]		bi			斜体
				@param[in]		pFace		文字タイプ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,const MofS32 bold,const MofBool bi,LPCMofChar pFace);
		/*************************************************************************//*!
				@brief			フォントの生成
				@param[in]		s			文字サイズ
				@param[in]		bold		太さ
				@param[in]		bi			斜体
				@param[in]		bu			下線
				@param[in]		bs			打消し線
				@param[in]		pFace		文字タイプ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,const MofS32 bold,const MofBool bi,const MofBool bu,const MofBool bs,LPCMofChar pFace);
		/*************************************************************************//*!
				@brief			描画文字の生成
				@param[in]		pText		文字列

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateString(LPCMofChar pText);
		
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderString(MofFloat px,MofFloat py,LPCMofChar pText);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderString(MofFloat px,MofFloat py,MofU32 col,LPCMofChar pText);
		
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderString(Rectangle& drec,LPCMofChar pText);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		col			描画色
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderString(Rectangle& drec,MofU32 col,LPCMofChar pText);
		
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		scl			描画スケール
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat scl, LPCMofChar pText);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		scl			描画スケール
				@param[in]		col			描画色
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat scl, MofU32 col,LPCMofChar pText);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		lh			行間
				@param[in]		scl			描画スケール
				@param[in]		col			描画色
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat lh, MofFloat scl, MofU32 col,LPCMofChar pText);

		/*************************************************************************//*!
				@brief			文字描画矩形の計算
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pText		描画文字列
				@param[out]		Out			出力矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CalculateStringRect(MofFloat px,MofFloat py,LPCMofChar pText,Rectangle& Out);

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		/*************************************************************************//*!
				@brief			登録テクスチャを取得
				@param			None

				@return			登録テクスチャ
		*//**************************************************************************/
		virtual LPTexture GetTexture(void);
		/*************************************************************************//*!
				@brief			指定文字列の登録情報を取得
				@param[in]		pText		文字列

				@return			指定文字列の登録情報<br>
								登録されていない場合NULLを返す
		*//**************************************************************************/
		virtual LPMOFCHARINPUT GetInputChar(LPCMofChar pText);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CDX11Font,MOF_DX11FONTCLASS_ID);
	};

	#include	"DX11Font.inl"
	
	//置き換え
	typedef CDX11Font	CFont;
}

#endif

//[EOF]