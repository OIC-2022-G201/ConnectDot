/*************************************************************************//*!
					
					@file	String.h
					@brief	文字列関連の処理を行うクラス。<br>
							UNICODEとマルチバイトの文字セットの置き換えも行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__STRING__H__

#define		__STRING__H__

//INCLUDE
#include	"Allocator.h"

namespace Mof {
	
#define		MOF_STRINGIMPL_NAME					CStringA
#define		MOF_STRINGIMPL_TYPE					char

#include	"StringImpl.h"

#undef		MOF_STRINGIMPL_NAME
#undef		MOF_STRINGIMPL_TYPE
	
	
#define		MOF_STRINGIMPL_NAME					CStringW
#define		MOF_STRINGIMPL_TYPE					wchar_t
#define		MOF_STRINGIMPL_UNICODE

#include	"StringImpl.h"

#undef		MOF_STRINGIMPL_NAME
#undef		MOF_STRINGIMPL_TYPE
#undef		MOF_STRINGIMPL_UNICODE

//----------------------------------
////文字列置き換え
//----------------------------------
#ifdef		UNICODE

//!文字列クラス
#define		MOF_STRINGCLASS_ID					MOF_ASTRINGCLASS_ID
typedef		CStringW							CString;
typedef		CString*							LPString;

//!ファイルを開く
#define		MOF_FOPEN							_wfopen
//!ファイルを閉じる
#define		MOF_FCLOSE(fp)						if(fp){fclose(fp); fp = NULL;}
//!ファイル文字列書き込み
#define		MOF_FPRINT							fwprintf
//!可変引数文字列書き込み
#define		MOF_SPRINT							swprintf
//!可変引数文字列書き込み
#define		MOF_VPRINT							vswprintf
//!文字列長さ
#define		MOF_StrLength						wcslen
//!文字列コピー
#define		MOF_StrCopy							wcscpy
//!文字列数値変換
#define		MOF_StrToL							wcstol
#define		MOF_StrToUL							wcstoul
#define		MOF_StrToLF							wcstod
//!テキストファイルタイプ
#define		MOF_FWRITETEXTENCODING				MOFSTR("wt, ccs= UNICODE")
//!2バイト文字の先頭判断(UNICODEの場合常にFALSE)
#define		MOF_ISDBCLEADBYTE(c)				FALSE
//!ディレクトリ作成
#define		MOF_MAKEDIRECTORY(p,a)				_wmkdir(p)

//!Wide
#define		MOF_TOWIDECHARA(pstr)				pstr
//!Multi
FORCE_INLINE char* MOF_TOMULTICHARA(const wchar_t* pstr)
{
	static char str[1024];
	memset(str, 0, sizeof(str));
	WideCharToMultiByte(CP_ACP, 0, pstr, wcslen(pstr), str, 1024, NULL, NULL);
	return str;
}
//!現形式
FORCE_INLINE LPCMofChar MOF_TOMOFCHARA(const char* pstr)
{
	static wchar_t wstr[1024];
	memset(wstr, 0, sizeof(wstr));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pstr, strlen(pstr), wstr, 1024);
	return wstr;
}
FORCE_INLINE LPCMofChar MOF_TOMOFCHARA(const wchar_t* pstr)
{
	return pstr;
}

#else

//!文字列クラス
#define		MOF_STRINGCLASS_ID					MOF_WSTRINGCLASS_ID
typedef		CStringA							CString;
typedef		CString*							LPString;

//!ファイルを開く
#define		MOF_FOPEN							fopen
//!ファイルを閉じる
#define		MOF_FCLOSE(fp)						if(fp){fclose(fp); fp = NULL;}
//!ファイル文字列書き込み
#define		MOF_FPRINT							fprintf
//!可変引数文字列書き込み
#define		MOF_SPRINT							sprintf
//!可変引数文字列書き込み
#define		MOF_VPRINT							vsprintf
//!文字列長さ
#define		MOF_StrLength						strlen
//!文字列コピー
#define		MOF_StrCopy							strcpy
//!文字列数値変換
#define		MOF_StrToL							strtol
#define		MOF_StrToUL							strtoul
#define		MOF_StrToLF							strtod
//!テキストファイルタイプ
#define		MOF_FWRITETEXTENCODING				MOFSTR("wt")

#ifdef		MOFLIB_WINDOWS

//!2バイト文字の先頭判断
#define		MOF_ISDBCLEADBYTE(c)				IsDBCSLeadByte(c)
//!ディレクトリ作成
#define		MOF_MAKEDIRECTORY(p,a)				mkdir(p)

//!Wide
FORCE_INLINE wchar_t* MOF_TOWIDECHARA(const char* pstr)
{
	static wchar_t wstr[1024];
	memset(wstr, 0, sizeof(wstr));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pstr, strlen(pstr), wstr, 1024);
	return wstr;
}
//!Multi
#define		MOF_TOMULTICHARA(pstr)				pstr
//!現形式
FORCE_INLINE LPCMofChar MOF_TOMOFCHARA(const char* pstr)
{
	return pstr;
}
FORCE_INLINE LPCMofChar MOF_TOMOFCHARA(const wchar_t* pstr)
{
	static char str[1024];
	memset(str, 0, sizeof(str));
	WideCharToMultiByte(CP_ACP, 0, pstr, wcslen(pstr), str, 1024, NULL, NULL);
	return str;
}

#endif

#ifdef		MOFLIB_ANDROID

//!2バイト文字の先頭判断
#define		MOF_ISDBCLEADBYTE(c)				((c >= 0x81 && c <= 0x9F) ? TRUE : (c >= 0xE0 && c <= 0xFC) ? TRUE : FALSE)
//!ディレクトリ作成
#define		MOF_MAKEDIRECTORY(p,a)				mkdir(p,a)

//!Wide
#define		MOF_TOWIDECHARA(pstr)				pstr
//!Multi
#define		MOF_TOMULTICHARA(pstr)				pstr
//!現形式
#define		MOF_TOMOFCHARA(pstr)				pstr

#endif

#endif

	
	/*******************************//*!
	@brief	名前持ち基底オブジェクトインターフェイス内部判定用

			MOFライブラリ内の全ての名前持ちオブジェクトを継承するか判断するための内部クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofNamedObjectImpl {};

	/*******************************//*!
	@brief	名前持ち基底オブジェクトインターフェイス

			MOFライブラリ内の全ての名前持ちオブジェクトの基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofNamedObject : public IMofObject , public IMofNamedObjectImpl {
	protected:
	public:
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~IMofNamedObject(){}
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前設定
				@param[in]		pName			設定する名前
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void) = 0;
	};

	//TYPEDEF
	typedef IMofNamedObject* LPMofNamedObject;
	typedef const IMofNamedObject* LPCMofNamedObject;
}

#endif

//[EOF]