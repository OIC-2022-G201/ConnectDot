/*************************************************************************//*!
					
					@file	Window.h
					@brief	ウインドウの処理を行う基底インターフェイス。<br>
							ウインドウやダイアログはすべてこのインターフェイスを継承する。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINDOW__H__

#define		__WINDOW__H__

//INCLUDE
#include	"../../Common/ReadFile.h"
#include	"../../Common/WriteFile.h"
#include	"../../Common/DynamicArray.h"

#ifdef		MOFLIB_WINDOWS_DESKTOP
#include	"WindowProc.h"
#endif

//DEFINE

//!ウインドウ位置の標準
#define		MOFWINDOWPOS_DEFAULT				MOF_S32_MIN

//!標準スタイル
#define		MOFWINDOWSTYLE_DEFAULT				MOF_U32_MAX

namespace Mof {

#ifdef		MOFLIB_WINDOWS_DESKTOP
	/*******************************//*!
	@brief	ウインドウ生成情報構造体

			ウインドウの生成に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct tag_WINDOWCREATEINFO {
		MofInstanceHandle		hInst;			//!<インスタンスハンドル
		CString					Title;			//!<ウインドウのタイトル
		MofS32					px;				//!<ウインドウのX座標
		MofS32					py;				//!<ウインドウのY座標
		MofS32					Width;			//!<ウインドウの幅
		MofS32					Height;			//!<ウインドウの高さ
		MofU32					WCStyle;		//!<スタイル（WNDCLASSEXのstyleメンバ）
		MofU32					Style;			//!<スタイル
		MofIconHandle			hIcon;			//!<アイコンハンドル
		MofCursorHandle			hCursor;		//!<カーソルハンドル
		MofWindowHandle			hParent;		//!<親ウインドウハンドル
		IWindowProc*			pProc;			//!<プロシージャー
		
		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								ウインドウのタイトル、座標、サイズ、スタイル標準値になる。<br>
								ウインドウズの場合<br>
								タイトル：MofWindow<br>
								座標：画面中央<br>
								サイズ：1024×768<br>
								アイコン：IDI_APPLICATION<br>
								カーソル：IDC_ARROW<br>
								WNDCLASSEXスタイル：CS_HREDRAW | CS_VREDRAW<br>
								スタイル：WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
				@param			None

				@return			None
		*//**************************************************************************/
		tag_WINDOWCREATEINFO() :
		hInst(NULL),
		Title(MOFSTR("MofWindow")),
		px(MOFWINDOWPOS_DEFAULT),
		py(MOFWINDOWPOS_DEFAULT),
		Width(1024),
		Height(768),
		WCStyle(MOFWINDOWSTYLE_DEFAULT) ,
		Style(MOFWINDOWSTYLE_DEFAULT),
		hIcon(NULL),
		hCursor(NULL),
		hParent(NULL),
		pProc(NULL)
		{
		}
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pTitle		ウインドウのタイトル
				@param[in]		x			ウインドウのX座標
				@param[in]		y			ウインドウのY座標
				@param[in]		w			ウインドウの幅
				@param[in]		h			ウインドウの高さ
				@param[in]		stl			ウインドウのスタイル
				
				@return			None
		*//**************************************************************************/
		tag_WINDOWCREATEINFO(LPCMofChar pTitle,MofS32 x,MofS32 y,MofS32 w,MofS32 h,MofU32 stl) :
		hInst(NULL),
		Title(pTitle),
		px(x),
		py(y),
		Width(w),
		Height(h),
		Style(stl),
		hIcon(NULL),
		hCursor(NULL),
		hParent(NULL),
		pProc(NULL)
		{
		}
	}WINDOWCREATEINFO,*LPWINDOWCREATEINFO;
#else
	
	/*******************************//*!
	@brief	ウインドウ生成情報構造体

			ウインドウの生成に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct tag_WINDOWCREATEINFO {
		MofS32					Width;			//!<ウインドウの幅
		MofS32					Height;			//!<ウインドウの高さ
		
		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								ウインドウのタイトル、座標、サイズ、スタイル標準値になる。<br>
								ウインドウズの場合<br>
								タイトル：MofWindow<br>
								座標：画面中央<br>
								サイズ：1024×768<br>
								アイコン：IDI_APPLICATION<br>
								カーソル：IDC_ARROW<br>
								WNDCLASSEXスタイル：CS_HREDRAW | CS_VREDRAW<br>
								スタイル：WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
				@param			None

				@return			None
		*//**************************************************************************/
		tag_WINDOWCREATEINFO() :
		Width(1024),
		Height(768)
		{
		}
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pTitle		ウインドウのタイトル
				@param[in]		x			ウインドウのX座標
				@param[in]		y			ウインドウのY座標
				@param[in]		w			ウインドウの幅
				@param[in]		h			ウインドウの高さ
				@param[in]		stl			ウインドウのスタイル
				
				@return			None
		*//**************************************************************************/
		tag_WINDOWCREATEINFO(LPCMofChar pTitle,MofS32 x,MofS32 y,MofS32 w,MofS32 h,MofU32 stl) :
		Width(w),
		Height(h)
		{
		}
	}WINDOWCREATEINFO,*LPWINDOWCREATEINFO;
#endif

	/*******************************//*!
	@brief	ウインドウ基底インターフェイス

			ウインドウの全ての基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IWindow : public IMofNamedObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			ウインドウの生成
				@param[in]		pInfo		ウインドウの生成情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPWINDOWCREATEINFO pInfo) = 0;
		/*************************************************************************//*!
				@brief			ウインドウの生成<br>
								内部でWINDOWCREATEINFOを生成して、ウインドウを作成する。<br>
								引数に存在しないパラメーターは環境の基本値が適用される。
				@param[in]		pTitle		ウインドウのタイトル
				@param[in]		w			ウインドウの幅
				@param[in]		h			ウインドウの高さ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPCMofChar pTitle,MofS32 w,MofS32 h) = 0;
	
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			画面サイズを設定する
				@param[in]		sw				幅
				@param[in]		sh				高さ
				@param[in]		bSet			ウインドウのサイズを実際に変更するか否か<br>
												TRUEの場合Windowサイズを変更するAPIを実行する。<br>
												FALSEの場合メンバのWidth,Heightの変更のみでAPIによるサイズの変更は行わない。
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetScreenSize(MofS32 sw,MofS32 sh, MofBool bSet = TRUE) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			インスタンスハンドル取得
				@param			None

				@return			インスタンスハンドル
		*//**************************************************************************/
		virtual MofInstanceHandle GetInstanceHandle(void) = 0;
		/*************************************************************************//*!
				@brief			ウインドウハンドル取得
				@param			None

				@return			ウインドウハンドル
		*//**************************************************************************/
		virtual MofWindowHandle GetWindowHandle(void) = 0;
		/*************************************************************************//*!
				@brief			ウインドウタイトル取得
				@param			None

				@return			ウインドウタイトル
		*//**************************************************************************/
		virtual LPString GetTitle(void) = 0;
		/*************************************************************************//*!
				@brief			ウインドウ幅取得
				@param			None

				@return			ウインドウ幅
		*//**************************************************************************/
		virtual MofS32 GetWidth(void) const = 0;
		/*************************************************************************//*!
				@brief			ウインドウ高さ取得
				@param			None

				@return			ウインドウ高さ
		*//**************************************************************************/
		virtual MofS32 GetHeight(void) const = 0;
	};

	//ポインタ置き換え
	typedef IWindow*			LPWindow;
}

#endif

//[EOF]