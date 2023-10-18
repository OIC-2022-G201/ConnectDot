/*************************************************************************//*!
					
					@file	RenderThread.h
					@brief	マルチスレッド用描画スレッド

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__RENDERTHREAD__H__

#define		__RENDERTHREAD__H__

//INCLUDE
#include	"../Common/Queue.h"
#include	"../Common/Thread.h"
#include	"RenderCommand.h"

namespace Mof {

	//描画コマンドキュー
	typedef CQueue< LPRenderCommandList > CRenderCommandQueue, *LPRenderCommandQueue;

	/*******************************//*!
	@brief	ロック

			ロック

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRenderThread : public CThread {
	protected:
		/*******************//*!
		スレッド継続フラグ
		*//********************/
		MofBool						m_bRunnable;
		/*******************//*!
		コマンドキュー
		*//********************/
		CRenderCommandQueue			m_CommandQueue;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CRenderThread();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CRenderThread();

		/*************************************************************************//*!
				@brief			スレッドの内部実行処理
				@param			None

				@return			None
		*//**************************************************************************/
		virtual void Run(void);
		/*************************************************************************//*!
				@brief			コマンドをプッシュする
				@param[in]		pCmd			追加コマンド

				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool PushCommand(LPRenderCommandList pCmd);

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			コマンド登録判定
				@param			コマンド登録がある

				@return			TRUE			登録有<br>
								それ以外		登録なし。
		*//**************************************************************************/
		virtual MofBool IsCommand(void);
		/*************************************************************************//*!
				@brief			コマンド処理待機

				@return			TRUE			待機正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool WaitCommandFlush(void);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CRenderThread, MOF_RENDERTHREADCLASS_ID);
	};

	//置き換え
	typedef CRenderThread*		LPRenderThread;

	#include	"RenderThread.inl"
}

#endif

//[EOF]