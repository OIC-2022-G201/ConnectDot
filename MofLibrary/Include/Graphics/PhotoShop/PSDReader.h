/*************************************************************************//*!
					
					@file	PSDReader.h
					@brief	PSD読み込み用クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__PSDREADER__H__

#define		__PSDREADER__H__

//INCLUDE
#include	"ImageReader.h"

namespace Mof {
	
	/*******************************//*!
	@brief	PSDイメージヘッダー構造体

			PSDイメージヘッダー。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_IMAGEHEADER {
		MofU16				Channels;				//!<チャンネル数
		MofU32				Row;					//!<縦ピクセル数
		MofU32				Column;					//!<横ピクセル数
		MofU16				Depth;					//!<ビット震度
	}PSD_IMAGEHEADER;
	
	/*******************************//*!
	@brief	PSDヘッダーデータ構造体

			PSDヘッダーデータ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_HEADER {
		MofU32				Magic;					//!<マジックナンバー
		MofU16				Version;				//!<ファイルバージョン
		MofU8				Reserved[6];			//!<予備領域
		MofU16				Channels;				//!<チャンネル数
		MofU32				Row;					//!<縦ピクセル数
		MofU32				Column;					//!<横ピクセル数
		MofU16				Depth;					//!<ビット震度
		MofU16				Mode;					//!<カラーモード
	}PSD_HEADER,*LPPSD_HEADER;
	
	/*******************************//*!
	@brief	PSDカラーモードデータ構造体

			PSDカラーモードデータ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_COLOR_MODEDATA {
		MofU32				Length;					//!<データサイズ
		MofU8*				pData;					//!<データ配列
	}PSD_COLOR_MODEDATA;
	
	/*******************************//*!
	@brief	PSDリソースデータ構造体

			PSDリソースデータ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_IMAGE_RESOURCE {
		MofU32				Length;					//!<データサイズ
		MofU32				Type;					//!<データタイプ
		MofU16				ID;						//!<データ番号
		MofU8*				pName;					//!<データ名
		MofU32				Size;					//!<リソースサイズ
	}PSD_IMAGE_RESOURCE;

	/*******************************//*!
	@brief	PSD解像度データ構造体

			PSD解像度データ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_RESOLUTION_INFO {
		MofS16				HorzRes;				//!<横解像度
		MofS32				HorzResUnit;			//!<ディスプレイ解像度モード
		MofS16				WidthUnit;				//!<横解像度モード
		MofS16				VertRes;				//!<縦解像度
		MofS32				VertResUnit;			//!<ディスプレイ解像度モード
		MofS16				HeightUnit;				//!<縦解像度モード
	}PSD_RESOLUTION_INFO;
	
	/*******************************//*!
	@brief	PSD解像度データ(Version2)構造体

			PSD解像度データ(Version2)。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_RESOLUTION_INFO_V2 {
		MofS16				Channels;				//!<チャンネル数
		MofS16				Row;					//!<縦幅
		MofS16				Column;					//!<横幅
		MofS16				Depth;					//!<ビット震度
		MofS16				Mode;					//!<カラーモード
	}PSD_RESOLUTION_INFO_V2;

	/*******************************//*!
	@brief	PSDディスプレイデータ構造体

			PSDディスプレイデータ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_DISPLAY_INFO {
		MofS16				ColorSpace;				//!<色間隔
		MofS16				Color[4];				//!<色データ
		MofS16				Opacity;				//!<不透明度
		MofBool				Kind;					//!<種類
		MofU8				Padding;				//!<詰め物
	}PSD_DISPLAY_INFO;
	
	/*******************************//*!
	@brief	PSDサムネイルデータ構造体

			PSDサムネイルデータ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_THUMBNAIL_INFO {
		MofS32				Format;					//!<フォーマット
		MofS32				Width;					//!<幅
		MofS32				Height;					//!<高さ
		MofS32				WidthBytes;				//!<幅バイト数
		MofS32				Size;					//!<サイズ
		MofS32				CompressSize;			//!<圧縮後サイズ
		MofS16				BitPerPixel;			//!<1ビットのピクセル数
		MofS16				Planes;					//!<プレーンの数
		MofU8*				pData;					//!<データ
	}PSD_THUMBNAIL_INFO;
	
	/*******************************//*!
	@brief	PSDチャンネルデータ構造体

			PSDチャンネルデータ。
			ChannelIDの値
				0			: 赤
				1			: 緑
				2			: 青
				-1(65535)	: アルファ

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_CHANNEL_LENGTH_INFO {
		MofU16				ChannelID;				//!<チャンネル番号
		MofS32				Length;					//!<長さ
	}PSD_CHANNEL_LENGTH_INFO,PSD_CLI;
	typedef CDynamicArray< PSD_CLI > PSDCLILIST,*LPPSDCLILIST;

	/*******************************//*!
	@brief	PSDチャンネル範囲構造体

			PSDチャンネル範囲。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_CHANNEL_SOURCE_DEST_RANGE {
		MofU8				Src[4];					//!<元範囲
		MofU8				Dest[4];				//!<出力範囲
	}PSD_CHANNEL_SOURCE_DEST_RANGE,PSD_CSDR;
	typedef CDynamicArray< PSD_CSDR > PSDCSDRLIST,*LPPSDCSDRLIST;

	/*******************************//*!
	@brief	PSDブレンディング範囲データ構造体

			PSDブレンディング範囲データ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_BLENDING_RANGE {
		MofS32				Top;					//!<範囲上
		MofS32				Left;					//!<範囲左
		MofS32				Bottom;					//!<範囲下
		MofS32				Right;					//!<範囲右
		MofU8				Default;				//!<デフォルト色
		MofU8				Flags;					//!<フラグ
		MofU16				Padding;				//!<詰め物
	}PSD_BLENDING_RANGE;

	/*******************************//*!
	@brief	PSDブレンディングデータ構造体

			PSDブレンディングデータ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_BLENDING_INFO {
		MofU8				GraySrc[4];				//!<元範囲
		MofU8				GrayDest[4];			//!<出力範囲
		LPPSDCSDRLIST		pSrcRange;				//!<元範囲
		CString				LayerName;				//!<レイヤー名
	}PSD_BLENDING_INFO;
	
	/*******************************//*!
	@brief	PSDレイヤー情報データ構造体

			PSDレイヤー情報データ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_LAYER_INFO {
		MofS32				Left;					//!<バウンディングボックスの左
		MofS32				Top;					//!<バウンディングボックスの上
		MofS32				Right;					//!<バウンディングボックスの右
		MofS32				Bottom;					//!<バウンディングボックスの下
		MofU16				Channels;				//!<チャンネル数
		LPPSDCLILIST		pChannelInfo;			//!<チャンネルデータ
		MofU8*				pLayerData;				//!<レイヤーデータ
		MofU32				LayerSize;				//!<レイヤーデータサイズ
		MofU32				BlendKey;				//!<ブレンディングキー
		MofU8				Opacity;				//!<不透明度
		MofU8				Clipping;				//!<クリッピング
		MofU8				Flags;					//!<フラグ
		MofU8				Padding;				//!<詰め物
		PSD_BLENDING_RANGE	BlendRange;				//!<アルファブレンド範囲
		PSD_BLENDING_INFO	BlendInfo;				//!<ブレンディングデータ
		LPMOFIMAGEDATA		pImage;					//!<イメージデータ
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PSD_LAYER_INFO() :
		Left(0) ,
		Top(0) ,
		Right(0) ,
		Bottom(0) ,
		Channels(0) ,
		pChannelInfo(NULL) ,
		pLayerData(NULL) ,
		LayerSize(0) ,
		BlendKey(0) ,
		Opacity(0) ,
		Clipping(0) ,
		Flags(0) ,
		Padding(0) ,
		BlendRange() ,
		BlendInfo() ,
		pImage(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PSD_LAYER_INFO(){
			BlendInfo.LayerName.SetString(NULL);
			MOF_SAFE_DELETE(BlendInfo.pSrcRange);
			MOF_SAFE_DELETE(pChannelInfo);
			MOF_SAFE_FREE(pLayerData,"CPSDReader Release");
		}
	}PSD_LAYER_INFO,*LPPSDLAYERINFO;
	typedef CDynamicArray< LPPSDLAYERINFO > CPSDLayerInfoArray,*LPPSDLayerInfoArray;

	/*******************************//*!
	@brief	PSDマスク情報データ構造体

			PSDマスク情報データ。

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_MASK_INFO {
		MofU16				Overlay;				//!<OverlayColorSpace
		MofU8				Color[8];				//!<ColorComponents
		MofU16				Opacity;				//!<0=透明 1=不透明
		MofU8				Kind;					//!<種類 0=Inverted 1=Protected 128=UseStoredValue
		MofU8				Padding;				//!<詰め物
	}PSD_MASK_INFO;

	//ENUM
	
	/*******************************//*!
	@brief	PSDカラーモード列挙

			PSDカラーモード。

	@author	CDW
	*//********************************/
	enum tag_PSD_COLORMODE {
		PSD_COLORMODE_BITMAP		= 0,
		PSD_COLORMODE_GRAYSCALE		= 1,
		PSD_COLORMODE_INDEXED		= 2,
		PSD_COLORMODE_RGB			= 3,
		PSD_COLORMODE_CMYK			= 4,
		PSD_COLORMODE_MULTICANNEL	= 7,
		PSD_COLORMODE_DUOTONE		= 8,
		PSD_COLORMODE_LAB			= 9,
	};
	
	/*******************************//*!
	@brief	PSDリソース列挙

			PSDリソース。

	@author	CDW
	*//********************************/
	enum tag_PSD_RESOURCE{
		PSDRES_RESOLUTIONINFOV2		= 1000,
		PSDRES_RESOLUTIONINFO		= 1005,
		PSDRES_DISPLAYINFO			= 1007,
		PSDRES_THUMBNAILINFOBGR		= 1033,
		PSDRES_THUMBNAILINFORGB		= 1036,
		PSDRES_COPYRIGHT			= 1034,
		PSDRES_GLOBALANGLE			= 1037,
		PSDRES_COLORCOUNT			= 1046,
		PSDRES_TRANSPARENTINDEX		= 1047,
	};
	
	/*******************************//*!
	@brief	PSD圧縮方式列挙

			PSD圧縮方式。

	@author	CDW
	*//********************************/
	enum tag_PSD_COMPRESSION{
		PSDCOMP_RAW					= 0,
		PSDCOMP_RLE					= 1,
		PSDCOMP_ZIPO				= 2,
		PSDCOMP_ZIP					= 3,
	};
	
	/*******************************//*!
	@brief	PSDレイヤーフラグ列挙

			PSDレイヤーフラグ。

	@author	CDW
	*//********************************/
	enum tag_PSD_LAYERFLAGS {
		PSD_LAYERFLAG_VISIBLE		= 0x00000002,
		PSD_LAYERFLAG_GROUP			= 0x00000010,

		PSD_LAYERFLAG_ALL			= 0x00000012,
	};

	//CLASS
	
	/*******************************//*!
	@brief	PSDファイル読み込みクラス

			PSDファイル読み込みクラス。

	@author	CDW
	*//********************************/
	class CPSDReader : public CImageReader {
	protected:
		/*******************//*!
		PSDファイル
		*//********************/
		FILE*					m_pFile;
		/*******************//*!
		エンディアン変換フラグ
		*//********************/
		MofBool					m_SwapEndian;
		/*******************//*!
		PSDファイルヘッダー
		*//********************/
		PSD_HEADER				m_Header;
		/*******************//*!
		カラーモードデータ
		*//********************/
		PSD_COLOR_MODEDATA		m_ColorMode;
		/*******************//*!
		イメージリソース
		*//********************/
		PSD_IMAGE_RESOURCE		m_ImageResource;
		/*******************//*!
		ピクセルバイト
		*//********************/
		MofS32					m_BytesPerPixelPerChannels;
		/*******************//*!
		解像度データ
		*//********************/
		PSD_RESOLUTION_INFO		m_ResInfo;
		/*******************//*!
		解像度データ読み込みフラグ
		*//********************/
		MofBool					m_ResInfoFilled;
		/*******************//*!
		解像度データVersion2
		*//********************/
		PSD_RESOLUTION_INFO_V2	m_ResInfoV2;
		/*******************//*!
		解像度データ読み込みフラグVersion2
		*//********************/
		MofBool					m_ResInfoV2Filled;
		/*******************//*!
		ディスプレイデータ
		*//********************/
		PSD_DISPLAY_INFO		m_DisplayInfo;
		/*******************//*!
		解像度データ読み込みフラグ
		*//********************/
		MofBool					m_DisplayInfoFilled;
		/*******************//*!
		ディスプレイデータ
		*//********************/
		PSD_THUMBNAIL_INFO		m_ThumbnailInfo;
		/*******************//*!
		解像度データ読み込みフラグ
		*//********************/
		MofBool					m_ThumbnailInfoFilled;
		/*******************//*!
		コピーライト読み込みフラグ
		*//********************/
		MofBool					m_Copyright;
		/*******************//*!
		全体角度
		*//********************/
		MofS32					m_GlobalAngle;
		/*******************//*!
		色数
		*//********************/
		MofS16					m_ColorCount;
		/*******************//*!
		透明
		*//********************/
		MofS16					m_TransparentIndex;
		/*******************//*!
		圧縮フラグ
		*//********************/
		MofS16					m_Compress;
		/*******************//*!
		レイヤーサイズにフィットしたイメージの生成
		*//********************/
		MofBool					m_LoadFit;
		/*******************//*!
		レイヤーデータ
		*//********************/
		CPSDLayerInfoArray		m_LayerInfo;

		/*************************************************************************//*!
				@brief			PSDファイルから4Byteのデータを読み込む
				@param[in]		bSwap		エンディアン変更フラグ

				@return			符号なしの4Byteデータ
		*//**************************************************************************/
		MofU32 GetLong(MofBool bSwap);
		/*************************************************************************//*!
				@brief			PSDファイルから2Byteのデータを読み込む
				@param[in]		bSwap		エンディアン変更フラグ

				@return			符号なしの2Byteデータ
		*//**************************************************************************/
		MofU16 GetShort(MofBool bSwap);
		/*************************************************************************//*!
				@brief			ヘッダーの読み込み
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ReadHeader(void);
		/*************************************************************************//*!
				@brief			カラーモードデータの読み込み
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ReadColorModeData(void);
		/*************************************************************************//*!
				@brief			リソースの読み込み
				@param[in,out]	pResource	出力リソース
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ReadImageResource(PSD_IMAGE_RESOURCE* pResource);
		/*************************************************************************//*!
				@brief			レイヤー＆マスクデータの読み込み
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ReadLayerAndMaskInfoSection(void);
		/*************************************************************************//*!
				@brief			解像度データの読み込み
				@param			None
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadResolutionInfo(void);
		/*************************************************************************//*!
				@brief			解像度データVersion2の読み込み
				@param			None
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadResolutionInfoV2(void);
		/*************************************************************************//*!
				@brief			ディスプレイデータの読み込み
				@param			None
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadDisplayInfo(void);
		/*************************************************************************//*!
				@brief			サムネイルデータ読み込み
				@param			None
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadThumbnailInfo(MofS32 ID,MofS32 Size);
		/*************************************************************************//*!
				@brief			レイヤーデータ読み込み
				@param[in,out]	pInfo		出力レイヤー情報
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadLayerInfo(PSD_LAYER_INFO* pInfo);
		/*************************************************************************//*!
				@brief			レイヤーチャンネル別データ読み込み
				@param[in,out]	pData		出力データ
				@param[in]		Pixels		読み込みピクセル数
				@param[in]		Skip		レイヤーオフセットスキップ
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadLayerChannels(MofU8* pData,MofS32 Pixels,MofS32 Skip);
		/*************************************************************************//*!
				@brief			画像データ読み込み
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ReadImageData(void);
		/*************************************************************************//*!
				@brief			RAW無圧縮形式画像データ読み込み
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ReadRAWImageData(void);
		/*************************************************************************//*!
				@brief			RLE圧縮形式画像データ読み込み
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ReadRLEImageData(void);
		/*************************************************************************//*!
				@brief			その他の読み込み
				@param[in]		Size		読み込みデータサイズ
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadOtherData(MofS32 Size);
		/*************************************************************************//*!
				@brief			コピーライト読み込み
				@param			None
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadCopyright(void);
		/*************************************************************************//*!
				@brief			グローバルアングル読み込み
				@param			None
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadGlobalAngle(void);
		/*************************************************************************//*!
				@brief			色数読み込み
				@param			None
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadColorCount(void);
		/*************************************************************************//*!
				@brief			インデックス読み込み
				@param			None
				
				@return			読み込んだデータサイズを返す
		*//**************************************************************************/
		MofS32 ReadTransparentIndex(void);
		/*************************************************************************//*!
				@brief			圧縮画像読み込み展開
				@param[in,out]	pData		出力データ
				@param[in]		Pixels		読み込みピクセル数
				@param[in]		ReadSize	読み込みデータサイズ
				
				@return			データサイズを返す
		*//**************************************************************************/
		MofU32 UnCompressImageData(MofU8* pData,MofU32 Pixels,MofU32 ReadSize);
		/*************************************************************************//*!
				@brief			チャンネルをピクセル単位で整列
				@param[in]		pSrc		元データ
				@param[in]		Pixels		読み込みピクセル数
				@param[in]		Channels	展開チャンネル
				@param[in]		lSize		設定画像サイズ
				
				@return			ソート後のピクセル情報を返す
		*//**************************************************************************/
		MofU8* SortPixelData(const MofU8* pSrc,MofS32 Pixels,MofS32 Channels,MofS32 lSize);
		/*************************************************************************//*!
				@brief			読み込みリソース情報を初期化する
				@param[in,out]	pResource	出力リソース
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ResourceReset(PSD_IMAGE_RESOURCE* pResource);
		
		/*************************************************************************//*!
				@brief			イメージデータをBMPファイルで作成する
				@param[in]		pName		名前
				@param[in]		pData		データ
				@param[in]		ImageWidth	幅
				@param[in]		ImageHeight	高さ
				@param[in]		Channels	チャンネル数
				
				@return			生成したイメージデータ
		*//**************************************************************************/
		LPMOFIMAGEDATA CreateBitmap(LPCMofChar pName,const MofU8* pData,MofU32 ImageWidth,MofU32 ImageHeight,MofS32 Channels);
		/*************************************************************************//*!
				@brief			イメージデータをDDSファイルで作成する
				@param[in]		pName		名前
				@param[in]		pData		データ
				@param[in]		ImageWidth	幅
				@param[in]		ImageHeight	高さ
				@param[in]		Channels	チャンネル数
				
				@return			生成したイメージデータ
		*//**************************************************************************/
		LPMOFIMAGEDATA CreateDDS(LPCMofChar pName,const MofU8* pData,MofU32 ImageWidth,MofU32 ImageHeight,MofS32 Channels);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CPSDReader();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーイメージ

				@return			None
		*//**************************************************************************/
		CPSDReader(const CPSDReader& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CPSDReader();

		/*************************************************************************//*!
				@brief			ファイルの読み込み
				@param[in]		pName		ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName);

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			PSDヘッダー取得
				@param			None

				@return			PSDヘッダー
		*//**************************************************************************/
		LPPSD_HEADER GetHeader(void);
		/*************************************************************************//*!
				@brief			PSDレイヤー情報取得
				@param			None

				@return			PSDレイヤー情報
		*//**************************************************************************/
		LPPSDLayerInfoArray GetPSDLayerInfoList(void);
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CPSDReader,MOF_PSDREADERCLASS_ID);
	};

	//TYPEDEF
	typedef CPSDReader* LPPSDReader;

	//INLINE INCLUDE
	#include	"PSDReader.inl"

}

#endif		//__PSDREADER__H__

//[EOF]