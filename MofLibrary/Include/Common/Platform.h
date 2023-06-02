/*************************************************************************//*!
					
					@file	Platform.h
					@brief	ライブラリの動作プラットフォームごとの定義を行う<br>
							実行するプラットフォームによりMOFLIB_DIRECTX11、MOFLIB_DIRECTX9、<br>
							MOFLIB_OPENGL、MOFLIB_ANDROIDのいずれかを有効にすること。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__PLATFORM__H__

#define		__PLATFORM__H__

//----------------------------------
//プラットフォームの振り分け
//OSは既存の定義から振り分ける、
//Windowsの場合はさらにグラフィックスライブラリのタイプを分けることができる。
//----------------------------------
#if defined( _WIN64 )

//!WINDOWS
#define		MOFLIB_WINDOWS
#define		MOFLIB_WINDOWS_DESKTOP

//!DIRECTX11
#define		MOFLIB_DIRECTX11

//!DIRECTX9
//#define		MOFLIB_DIRECTX9

//!OPENGL
//#define		MOFLIB_OPENGL

#elif defined( _WIN32 )

//!WINDOWS
#define		MOFLIB_WINDOWS
#define		MOFLIB_WINDOWS_DESKTOP

//!DIRECTX12
//#define		MOFLIB_DIRECTX12

//!DIRECTX11
#define		MOFLIB_DIRECTX11

//!DIRECTX9
//#define		MOFLIB_DIRECTX9

//!OPENGL
//#define		MOFLIB_OPENGL

#else

//!OPENGL
#define		MOFLIB_ANDROID

//!OPENGL
#define		MOFLIB_OPENGL

#endif

//----------------------------------
//プラットフォームの組み合わせエラー
//----------------------------------
#ifdef		MOFLIB_WINDOWS

#ifdef		MOFLIB_ANDROID
#error		"PlatformError!![Please use windows, android, or either.]"
#endif

#ifdef		MOFLIB_DIRECTX12

#ifdef		MOFLIB_DIRECTX11
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif

#ifdef		MOFLIB_DIRECTX9
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif
#ifdef		MOFLIB_OPENGL
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif
#else

#ifdef		MOFLIB_DIRECTX11

#ifdef		MOFLIB_DIRECTX9
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif

#ifdef		MOFLIB_OPENGL
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif

#else

#ifdef		MOFLIB_OPENGL

#ifdef		MOFLIB_DIRECTX9
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif

#endif

#endif
#endif

#endif

#ifdef		MOFLIB_ANDROID

#ifdef		MOFLIB_DIRECTX12
#error		"PlatformError!![In android, DIRECTX12 cannot be used.]"
#endif

#ifdef		MOFLIB_DIRECTX11
#error		"PlatformError!![In android, DIRECTX11 cannot be used.]"
#endif

#ifdef		MOFLIB_DIRECTX9
#error		"PlatformError!![In android, DIRECTX9 cannot be used.]"
#endif

#ifndef		MOFLIB_OPENGL
#define		MOFLIB_ANDROID
#endif

#endif

//----------------------------------
////VisualStudio用warning対策
//----------------------------------
#ifdef		MOFLIB_WINDOWS
//ライブラリpdb
#pragma warning (disable : 4099) //C runtime lib ('*' に見つかりません。デバッグ情報がないものとして、オブジェクトにリンクします。)
//WARNING(2005以降)
#pragma warning (disable : 4995) //C runtime lib ('*' が名前が避けられた#pragmaとして記述されています。)
#pragma warning (disable : 4996) //C runtime lib ('*' が古い形式として宣言されました。)

//WARNING(標準)
//#define		__MOFTYPEWARNINGOUTPUT__
#ifndef		__MOFTYPEWARNINGOUTPUT__
#pragma warning (disable : 4018) //C runtime lib ('*' : signed と unsigned の数値を比較しようとしました。)
#pragma warning (disable : 4244) //C runtime lib ('*' : '*' から '*' への変換です。データが失われる可能性があります。)
#endif		//#ifndef	__MOFTYPEWARNINGOUTPUT__
#endif

#if defined(DEBUG) || defined(_DEBUG)
//#define		_ITERATOR_DEBUG_LEVEL					0
#endif

#endif

//[EOF]