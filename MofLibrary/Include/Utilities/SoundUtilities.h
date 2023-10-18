/*************************************************************************//*!
					
					@file	SoundUtilities.h
					@brief	サウンド関連の汎用処理をまとめたスタティッククラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SOUNDUTILITIES__H__

#define		__SOUNDUTILITIES__H__

//INCLUDE
#include	"../Sound/Sound.h"

namespace Mof {
	
	/*******************************//*!
	@brief	サウンド関連の汎用処理をまとめたスタティッククラス

			サウンド関連の汎用処理をまとめたスタティッククラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSoundUtilities {
	private:
		/*******************//*!
		サウンド
		*//********************/
		static LPSound				m_pSound;
	public:
#ifdef		MOFLIB_WINDOWS_DESKTOP
		/*************************************************************************//*!
				@brief			WAVEファイルのチャンクを読み込む
				@param[in]		hmmio			ファイルハンドル
				@param[out]		mmdata			MMINFO
				@param[out]		mmriff			MMINFO
				@param[out]		pcwf			WAVEFORMAT
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		static MofBool ReadWaveFormat(HMMIO hmmio,MMCKINFO* mmdata,MMCKINFO* mmriff,WAVEFORMATEX** pcwf);
		/*************************************************************************//*!
				@brief			WAVEファイルのデータを読み込む
				@param[in]		hmmio			ファイルハンドル
				@param[in]		pCkIn			MMINFO
				@param[in]		pRiff			MMINFO
				@param[in]		Size			読み込みサイズ
				@param[out]		pData			読み込みデータ
		
				@return			読み込んだバイト数
		*//**************************************************************************/
		static MofU32 ReadWave(HMMIO hmmio,MMCKINFO* pCkIn,MMCKINFO* pRiff,MofU32 Size,LPMofVoid pData);
		/*************************************************************************//*!
				@brief			WAVEファイルの読み込み位置を初期化する
				@param[in]		hmmio			ファイルハンドル
				@param[in]		mmdata			MMINFO
				@param[in]		mmriff			MMINFO
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		static MofBool ResetWavePosition(HMMIO hmmio,MMCKINFO* mmdata,MMCKINFO* mmriff);
		/*************************************************************************//*!
				@brief			WAVEファイルの読み込み位置を初期化する
				@param[in]		hmmio			ファイルハンドル
				@param[in]		mmdata			MMINFO
				@param[in]		mmriff			MMINFO
				@param[in]		off				オフセット位置

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		static MofBool SetWavePosition(HMMIO hmmio, MMCKINFO* mmdata, MMCKINFO* mmriff, MofU32 off);
#endif

#ifdef		MOFLIB_WINDOWS
		/*************************************************************************//*!
				@brief			OGGファイルを読み込む<br>
								読み込んだファイルのバッファ、サイズ、フォーマットを出力する。
				@param[in]		pFile			読み込みファイル
				@param[out]		pData			出力バッファ
				@param[out]		Size			出力サイズ
				@param[out]		pcwf			出力フォーマット
		
				@return			TRUE			正常終了<br>
								FALSE			エラー
		*//**************************************************************************/
		static MofBool ReadOGG(CReadBinaryFile* pFile,LPMofU8* pData,MofU32* Size,WAVEFORMATEX* pcwf);
		/*************************************************************************//*!
				@brief			開いたファイルからOGGファイルを読み込む<br>
								読み込んだファイル、サイズ、フォーマットを出力する。
				@param[in]		fp				読み込みファイル
				@param[out]		pFile			出力ファイル
				@param[out]		Size			出力サイズ
				@param[out]		pcwf			出力フォーマット
		
				@return			TRUE			正常終了<br>
								FALSE			エラー
		*//**************************************************************************/
		static MofBool ReadOGG(FILE* fp,OggVorbis_File* pFile,MofU32* Size,WAVEFORMATEX* pcwf);
		/*************************************************************************//*!
				@brief			開いたファイルからOGGファイルを読み込む<br>
								読み込んだファイル、サイズ、フォーマットを出力する。
				@param[in]		fp				読み込みファイル
				@param[out]		pFile			出力ファイル
				@param[out]		Size			出力サイズ
				@param[out]		pcwf			出力フォーマット
		
				@return			TRUE			正常終了<br>
								FALSE			エラー
		*//**************************************************************************/
		static MofBool ReadOGG(CReadBinaryFile* fp,OggVorbis_File* pFile,MofU32* Size,WAVEFORMATEX* pcwf);
		/*************************************************************************//*!
				@brief			OGGファイルから指定サイズだけ読み込む<br>
								サイズ読み込み以前にバッファの終端まで到達した場合LoopPosまでオフセットを移動させる。
				@param[out]		pData			出力データ
				@param[in]		pFile			読み込みファイル
				@param[in]		Size			読み込みサイズ
				@param[in]		LoopPos			ループポイント
		
				@return			TRUE			正常終了<br>
								FALSE			エラー
		*//**************************************************************************/
		static MofBool ReadOGG(LPMofU8 pData,OggVorbis_File* pFile,MofU32 Size,MofFloat LoopPos);
#endif
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			サウンドインターフェイスを設定する
				@param[in]		pg				サウンドインターフェイス

				@return			None
		*//**************************************************************************/
		static void SetSound(LPSound pg);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			サウンドインターフェイスを取得する
				@param			None

				@return			サウンドインターフェイス
		*//**************************************************************************/
		static LPSound GetSound(void);

	private:
		//作成を禁止する
		CSoundUtilities(){};
		CSoundUtilities(const CSoundUtilities& pObj){};
	};
					
	#include	"SoundUtilities.inl"
}

#endif

//[EOF]