/*************************************************************************//*!
					
					@file	Mof.h
					@brief	MOFライブラリ一括インクルードヘッダー<br>
							ライブラリに必要な関連ヘッダーの一括インクルードを行う。<br>
							ライブラリの標準機能を利用する場合このヘッダーをインクルードすること。

															@author	CDW
															@date	2014.05.14

	\mainpage

	\section 初めに
	このドキュメントはOIC学内でゲーム開発に使用している<br>
	Mofライブラリのリファレンスです。<br>

	\section ライブラリの構成
	本ライブラリは下記のフォルダ構成で各機能を提供します。<br>
	- Collision<br>
						当たり判定に利用する形状用の構造体やクラス群<br>
	- Common<br>
						文字列・動的配列・スレッドなど共通の汎用処理を支援するためのクラス群<br>
	- Framework<br>
						アプリケーションの規定の流れやウインドウの生成・管理をおこなうためのクラス群<br>
	- Graphics<br>
						描画関連の処理をおこなうためのクラス群<br>
						クロスプラットフォームでの開発用に下記の2種類の実装を含む<br>
						+ Windows環境用：DirectX11<br>
						+ Android環境用：OpenGL<br>
	- Input<br>
						キーボード・マウス・タッチパネル・ゲームパッドの入力処理をおこなうためのクラス群<br>
	- Math<br>
						VectorやMatrixなど算術関連の構造体やクラス群<br>
	- Movie<br>
						動画処理をおこなうためのクラス群<br>
	- Network<br>
						ネットワークゲーム作成用の通信支援用クラス群<br>
	- Sound<br>
						サウンド関連の処理をおこなうためのクラス群<br>
						クロスプラットフォームでの開発用に下記の2種類の実装を含む<br>
						+ Windows環境用：XAudio2<br>
						+ Android環境用：OpenSL<br>
	- Utilities<br>
						Graphics等の各処理の関数をstaticで扱えるようにした汎用アクセスクラス群<br>
*//**************************************************************************/

//ONCE
#ifndef		__MOF__H__

#define		__MOF__H__

//DEFINE
//------------------------------------------------------------
//!ライブラリのバージョン
//		・2014/10		ライブラリのみ基本機能とサンプル作成
//						0x00000001
//		・2015/01		2D教科書用の各種対応追加
//						0x00000002
//		・2016/01		3D教科書用の各種対応追加
//						0x00000003
//		・2017/08/29	和田先生によるバージョン挿入リクエスト
//						0x00000004
//		・2017/11/01	SpriteStudioでのエフェクト（SSE）に対応
//						その他細かなバグ修正
//						0x00000005
//		・2018/05/06	細かなバグ修正
//						0x00000006
//		・2018/08/23	FBX読み込み仕様の変更
//						１６本までのウェイト割り付けに対応
//						0x00000007
//		・2019/03/11	VS2017対応追加
//						細かなバグ修正
//						0x00000008
//		・2019/12/11	_ITERATOR_DEBUG_LEVEL=0の指定の追加
//						細かなバグ修正
//						0x00000009
//		・2020/09/30	_ITERATOR_DEBUG_LEVEL=0の指定の取りやめ
//						いくつかのメソッドにconst指定を追加
//						細かなバグ修正
//						0x00000010
//------------------------------------------------------------
#define		MOFLIB_VERSION					0x00000010
#define		MOFLIB_MAJORVERSION				((MOFLIB_VERSION & 0xFFFF0000) >> 16)
#define		MOFLIB_MINORVERSION				((MOFLIB_VERSION & 0xFFFF))

//INCLUDE

//環境ヘッダーのインクルード
//以降のインクルードを環境ごとにする
#include	"Common/Platform.h"

//各種コンバータ利用フラグ変換を利用しないアプリではコメントアウト推奨
#define		MOFLIB_CONVERT

//外部ライブラリが必須のコンバーター
//#define		MOFLIB_CONVERTFBX				//FBX(プロジェクトにFBXのインクルードパス追加が必要)
//#define		MOFLIB_CONVERTSS				//SpriteStudio

//基礎フレームワークのインクルード
#ifdef		MOFLIB_WINDOWS

//ライブラリのリンク、ライブラリコンパイルの場合は無視される
#ifndef		MOFLIB_COMPILE

#if defined(DEBUG) || defined(_DEBUG)

#if _MSC_VER >= 1910

#pragma comment (lib,"MofLibrary2017_d.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"MofLibrary2015_d.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"MofLibrary2013_d.lib")

#else

#pragma comment (lib,"MofLibrary_d.lib")

#endif // _MSC_VER == 1800

#else

#if _MSC_VER >= 1910

#pragma comment (lib,"MofLibrary2017.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"MofLibrary2015.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"MofLibrary2013.lib")

#else

#pragma comment (lib,"MofLibrary.lib")

#endif // _MSC_VER == 1800

#endif

#endif

//各種コンバータ（変換を利用する場合のみインクルード）
#ifdef		MOFLIB_CONVERT

#ifdef		MOFLIB_CONVERTFBX

#include	"Graphics/FBX/fbxsdk.h"
#include	"Graphics/FBX/ConvertFBX.h"

#endif		// MOFLIB_CONVERTFBX

#ifdef		MOFLIB_CONVERTSS

#include	"Graphics/SpriteStudio/ssloader.h"
#include	"Graphics/SpriteStudio/ConvertSpriteStudio.h"

#endif		// MOFLIB_CONVERTSS

#include	"Graphics/MQO/ConvertMQO.h"
#include	"Graphics/PMD/ConvertPMD.h"
#include	"Graphics/PMD/ConvertPMX.h"
#include	"Graphics/PMD/ConvertVMD.h"
#include	"Graphics/XFile/ConvertX.h"
#include	"Graphics/PhotoShop/ConvertPsd.h"
#include	"Graphics/mdl/ConvertMDL.h"

#endif

#include	"Common/WinSingleGameApplication.h"
#include	"Common/WinMultiGameApplication.h"
#include	"Graphics/GraphicsPlatform.h"
#include	"Sound/SoundPlatform.h"

#ifdef		MOFLIB_DIRECTX12

#include	"Framework/Windows/DirectX12/DX12GameFramework.h"
#include	"Input/XInput/XInputGamePad.h"
#include	"Movie/DirectShow/DShowMovie.h"

#endif

#ifdef		MOFLIB_DIRECTX11

#include	"Framework/Windows/DirectX11/DX11GameFramework.h"
#include	"Input/XInput/XInputGamePad.h"
#include	"Movie/DirectShow/DShowMovie.h"

#endif

#ifdef		MOFLIB_DIRECTX9

#endif

#endif

#ifdef		MOFLIB_ANDROID

#include	"Common/AndroidSingleGameApplication.h"
#include	"Graphics/GraphicsPlatform.h"
#include	"Sound/SoundPlatform.h"

#include	"Framework/Android/AndroidJNIGameFramework.h"

#endif

//汎用スタティッククラスのインクルード
#include	"Utilities/Utilities.h"
#include	"Utilities/GraphicsUtilities.h"
#include	"Utilities/InputUtilities.h"
#include	"Utilities/SoundUtilities.h"
#include	"Utilities/CollisionUtilities.h"

//ライブラリ内へのアクセスを簡単に行うためのnamespace引き上げ(学生用簡易アクセスのための処置、推奨はしない)
using namespace Mof;

//学生用の基礎クラス簡易アクセス用(スタティッククラスから取得する)
#define		g_pFramework					CUtilities::GetFramework()				//!<基底フレームワーク取得用マクロ
#define		g_pMainWindow					g_pFramework->GetWindow()				//!<メインウインドウ取得用マクロ
#define		g_pGraphics						CGraphicsUtilities::GetGraphics()		//!<基底グラフィックス取得用マクロ
#define		g_pCommandProxy					CGraphicsUtilities::GetCommandProxy()	//!<マルチスレッド用コマンドバッファ取得用マクロ
#define		g_pInput						CInputUtilities::GetInput()				//!<基底インプット取得用マクロ
#define		g_pSound						CSoundUtilities::GetSound()				//!<基底サウンド取得用マクロ

#endif

//[EOF]