/*************************************************************************//*!
					
					@file	GLFont.h
					@brief	OpenGLフォントクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLFONT__H__

#define		__GLFONT__H__

//INCLUDE
#include	"../FontBase.h"
#include	"GLTexture.h"

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
		x(0) ,
		y(0) ,
		Width(0) ,
		Height(0) ,
		String() {
		}
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pStr		登録文字列

				@return			None
		*//**************************************************************************/
		tag_MOFCHARINPUT(LPCMofChar pStr) :
		x(0) ,
		y(0) ,
		Width(0) ,
		Height(0) ,
		String(pStr) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFCHARINPUT(){
			String.SetString(NULL);
		}
	}MOFCHARINPUT,*LPMOFCHARINPUT;
	typedef CDynamicArray< LPMOFCHARINPUT > CFontCharaInputArray,*LPFontCharaInputArray;

	/*******************************//*!
	@brief	OpenGLフォントクラス

			OpenGLフォントの読み込み、設定を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLFont : public CFontBase {
	protected:
		/*******************//*!
		テクスチャ
		*//********************/
		LPTexture				m_pTexture;
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
		
		/*************************************************************************//*!
				@brief			描画文字の生成
				@param[in]		pText		文字列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateString(LPCMofChar pText);
		/*************************************************************************//*!
				@brief			指定文字列の登録情報を取得
				@param[in]		pText		文字列

				@return			指定文字列の登録情報<br>
								登録されていない場合NULLを返す
		*//**************************************************************************/
		LPMOFCHARINPUT GetInputChar(LPCMofChar pText);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLFont();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLFont();
		
		/*************************************************************************//*!
				@brief			フォントの生成
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(void);
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
				@brief			文字描画矩形の計算
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pText		描画文字列
				@param[out]		rec			出力矩形
				
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

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CGLFont,MOF_GLFONTCLASS_ID);
	};

	#include	"GLFont.inl"
	
	//置き換え
	typedef CGLFont	CFont;
}

#endif

//[EOF]
