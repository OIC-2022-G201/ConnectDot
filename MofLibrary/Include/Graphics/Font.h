/*************************************************************************//*!
					
					@file	Font.h
					@brief	フォント基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__FONT__H__

#define		__FONT__H__

//INCLUDE
#include	"Shader.h"

namespace Mof {

	/*******************************//*!
	@brief	フォントクラス内部でテクスチャへの文字オフセットを記録する構造体

			フォントクラス内部でテクスチャへの文字オフセットを記録する構造体。<br>
			基本的に内部で確保・管理を行う。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFCHARINPUT {
		MofU32						x;								//X位置
		MofU32						y;								//Y位置
		MofU32						Width;							//幅
		MofU32						Height;							//高さ
		CString						String;							//登録文字列

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFCHARINPUT() :
			x(0),
			y(0),
			Width(0),
			Height(0),
			String() {
		}
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pStr		登録文字列

				@return			None
		*//**************************************************************************/
		tag_MOFCHARINPUT(LPCMofChar pStr) :
			x(0),
			y(0),
			Width(0),
			Height(0),
			String(pStr) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFCHARINPUT() {
			String.SetString(NULL);
		}
	}MOFCHARINPUT, *LPMOFCHARINPUT;
	typedef CDynamicArray< LPMOFCHARINPUT > CFontCharaInputArray, *LPFontCharaInputArray;

	/*******************************//*!
	@brief	フォントインターフェイス

			フォントの読み込み、設定を行うためのインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IFont : public IMofNamedObject {
	public:
		/*************************************************************************//*!
				@brief			フォントの生成
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(void) = 0;
		/*************************************************************************//*!
				@brief			フォントの生成
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(MofFont hFont) = 0;
		/*************************************************************************//*!
				@brief			フォントの生成
				@param[in]		s			文字サイズ
				@param[in]		pFace		文字タイプ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,LPCMofChar pFace) = 0;
		/*************************************************************************//*!
				@brief			フォントの生成
				@param[in]		s			文字サイズ
				@param[in]		bold		太さ
				@param[in]		bi			斜体
				@param[in]		pFace		文字タイプ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,const MofS32 bold,const MofBool bi,LPCMofChar pFace) = 0;
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
		virtual MofBool Create(const MofS32 s,const MofS32 bold,const MofBool bi,const MofBool bu,const MofBool bs,LPCMofChar pFace) = 0;
		/*************************************************************************//*!
				@brief			描画文字の生成
				@param[in]		pText		文字列

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateString(LPCMofChar pText) = 0;
		
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderFormatString(MofFloat px,MofFloat py,LPCMofChar pText,...) = 0;
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderFormatString(MofFloat px,MofFloat py,MofU32 col,LPCMofChar pText,...) = 0;
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderFormatString(Rectangle& drec,LPCMofChar pText,...) = 0;
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		col			描画色
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderFormatString(Rectangle& drec,MofU32 col,LPCMofChar pText,...) = 0;

		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderString(MofFloat px,MofFloat py,LPCMofChar pText) = 0;
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderString(MofFloat px,MofFloat py,MofU32 col,LPCMofChar pText) = 0;
		
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderString(Rectangle& drec,LPCMofChar pText) = 0;
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		col			描画色
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderString(Rectangle& drec,MofU32 col,LPCMofChar pText) = 0;
		
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		scl			描画スケール
				@param[in]		pText		描画文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat scl, LPCMofChar pText) = 0;
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
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat scl, MofU32 col,LPCMofChar pText) = 0;
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
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat lh, MofFloat scl, MofU32 col,LPCMofChar pText) = 0;

		/*************************************************************************//*!
				@brief			文字描画矩形の計算
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pText		描画文字列
				@param[out]		Out			出力矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CalculateStringRect(MofFloat px,MofFloat py,LPCMofChar pText,Rectangle& Out) = 0;
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			サイズ設定
				@param[in]		s				サイズ
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetSize(MofS32 s) = 0;
		/*************************************************************************//*!
				@brief			太さ設定
				@param[in]		s				太さ
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetBold(MofS32 s) = 0;
		/*************************************************************************//*!
				@brief			斜体設定
				@param[in]		bi				斜体
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetItalic(MofBool bi) = 0;
		/*************************************************************************//*!
				@brief			下線設定
				@param[in]		bi				下線
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetUnderline(MofBool bi) = 0;
		/*************************************************************************//*!
				@brief			打消し線設定
				@param[in]		bi				打消し線
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetStrikeOut(MofBool bi) = 0;
		/*************************************************************************//*!
				@brief			基本色設定
				@param[in]		c				色
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetDefaultColor(MofU32 c) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			フォントサイズ取得
				@param			None

				@return			フォントサイズ
		*//**************************************************************************/
		virtual MofS32 GetSize(void) = 0;
		/*************************************************************************//*!
				@brief			フォント太さ取得
				@param			None

				@return			フォント太さ
		*//**************************************************************************/
		virtual MofS32 GetBold(void) = 0;
		/*************************************************************************//*!
				@brief			フォント斜体取得
				@param			None

				@return			フォント斜体
		*//**************************************************************************/
		virtual MofBool GetItalic(void) = 0;
		/*************************************************************************//*!
				@brief			フォントタイプ名取得
				@param			None

				@return			フォントタイプ名
		*//**************************************************************************/
		virtual LPString GetFontFace(void) = 0;
		/*************************************************************************//*!
				@brief			指定文字列の登録情報を取得
				@param[in]		pText		文字列

				@return			指定文字列の登録情報<br>
								登録されていない場合NULLを返す
		*//**************************************************************************/
		virtual LPMOFCHARINPUT GetInputChar(LPCMofChar pText) = 0;
		/*************************************************************************//*!
				@brief			登録テクスチャを取得
				@param			None

				@return			登録テクスチャ
		*//**************************************************************************/
		virtual LPTexture GetTexture(void) = 0;
	};
	
	//ポインタ置き換え
	typedef IFont*			LPFont;
	typedef CDynamicArray< LPFont >		CFontArray,*LPFontArray;
}

//[EOF]

#endif