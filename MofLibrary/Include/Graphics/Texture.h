/*************************************************************************//*!
					
					@file	Texture.h
					@brief	テクスチャ基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__TEXTURE__H__

#define		__TEXTURE__H__

//INCLUDE
#include	"GraphicsCommon.h"
#include	"RenderTarget.h"

namespace Mof {
	
	/*******************************//*!
	@brief	テクスチャ反転列挙

			テクスチャの反転軸の列挙

	@author	CDW
	*//********************************/
	typedef enum TextureReverse {
		TEXTUREREVERSE_NONE				=	0x00,	//!<反転なし
		TEXTUREREVERSE_HORIZON			=	0x01,	//!<横反転
		TEXTUREREVERSE_VERTICAL			=	0x02,	//!<縦反転

		//-------------------------------------------------
		//短縮名の定義
		//-------------------------------------------------
		TEXREV_NONE						=	0x00,	//!<反転なし
		TEXREV_HORIZON					=	0x01,	//!<横反転
		TEXREV_VERTICAL					=	0x02,	//!<縦反転
	}TextureReverse;

	/*******************************//*!
	@brief	テクスチャアライメント列挙

			テクスチャの位置、拡大、回転の基準となる、アライメントの列挙

	@author	CDW
	*//********************************/
	typedef enum TextureAlignment {
		TEXTUREALIGNMENT_TOP			=	0x10,	//!<上
		TEXTUREALIGNMENT_VCENTER		=	0x20,	//!<中
		TEXTUREALIGNMENT_BOTTOM			=	0x40,	//!<下
		TEXTUREALIGNMENT_LEFT			=	0x01,	//!<左
		TEXTUREALIGNMENT_HCENTER		=	0x02,	//!<中
		TEXTUREALIGNMENT_RIGHT			=	0x04,	//!<右

		TEXTUREALIGNMENT_TOPLEFT		=	0x11,	//!<左上
		TEXTUREALIGNMENT_TOPCENTER		=	0x12,	//!<中上
		TEXTUREALIGNMENT_TOPRIGHT		=	0x14,	//!<右上
		TEXTUREALIGNMENT_CENTERLEFT		=	0x21,	//!<左中
		TEXTUREALIGNMENT_CENTERCENTER	=	0x22,	//!<中中
		TEXTUREALIGNMENT_CENTERRIGHT	=	0x24,	//!<右中
		TEXTUREALIGNMENT_BOTTOMLEFT		=	0x41,	//!<左下
		TEXTUREALIGNMENT_BOTTOMCENTER	=	0x42,	//!<中下
		TEXTUREALIGNMENT_BOTTOMRIGHT	=	0x44,	//!<右下

		TEXTUREALIGNMENT_VERTICAL		=	0x70,	//!<縦
		TEXTUREALIGNMENT_HORIZON		=	0x07,	//!<横
		TEXTUREALIGNMENT_MAX			=	0x77,	//!<最大数

		TEXTUREALIGNMENT_USER			=	0x100,	//!<ユーザー指定座標

		//-------------------------------------------------
		//短縮名の定義
		//-------------------------------------------------
		TEXALIGN_TOP					=	0x10,	//!<上
		TEXALIGN_VCENTER				=	0x20,	//!<中
		TEXALIGN_BOTTOM					=	0x40,	//!<下
		TEXALIGN_LEFT					=	0x01,	//!<左
		TEXALIGN_HCENTER				=	0x02,	//!<中
		TEXALIGN_RIGHT					=	0x04,	//!<右

		TEXALIGN_TOPLEFT				=	0x11,	//!<左上
		TEXALIGN_TOPCENTER				=	0x12,	//!<中上
		TEXALIGN_TOPRIGHT				=	0x14,	//!<右上
		TEXALIGN_CENTERLEFT				=	0x21,	//!<左中
		TEXALIGN_CENTERCENTER			=	0x22,	//!<中中
		TEXALIGN_CENTERRIGHT			=	0x24,	//!<右中
		TEXALIGN_BOTTOMLEFT				=	0x41,	//!<左下
		TEXALIGN_BOTTOMCENTER			=	0x42,	//!<中下
		TEXALIGN_BOTTOMRIGHT			=	0x44,	//!<右下

		TEXALIGN_VERTICAL				=	0x70,	//!<縦
		TEXALIGN_HORIZON				=	0x07,	//!<横
		TEXALIGN_MAX					=	0x77,	//!<最大数

		TEXALIGN_USER					=	0x100,	//!<ユーザー指定座標
	}TextureAlignment;
	
	/*******************************//*!
	@brief	スプライト描画スプライト情報入力コンスタントバッファ

	@author	CDW
	*//********************************/
	typedef struct tag_TextureRenderParameter {
		Vector4					vOffset;
		Vector4					vSize;
		Vector4					tOffset;
		Vector4					tSize;
		Vector4					Color;
		Matrix44				World;

		tag_TextureRenderParameter() :
		vOffset(), 
		vSize(1.0f, 1.0f, 1.0f, 1.0f),
		tOffset() ,
		tSize(1.0f,1.0f,1.0f,1.0f) ,
		Color(1.0f,1.0f,1.0f,1.0f),
		World() {
		}
	}TextureRenderParameter,*LPTextureRenderParameter;

	/*******************************//*!
	@brief	テクスチャ基底インターフェイス

			テクスチャ基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API ITexture : public IMofNamedObject , public IMofCopyObject< ITexture > {
	protected:
	public:
		/*************************************************************************//*!
				@brief			テクスチャの読み込み
				@param[in]		pName		ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			メモリからのテクスチャの読み込み
				@param[in]		pName		名前
				@param[in]		pData		メモリアドレス
				@param[in]		Size		サイズ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size) = 0;
		
		/*************************************************************************//*!
				@brief			テクスチャの保存
				@param[in]		pName		ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Save(LPCMofChar pName) = 0;

		/*************************************************************************//*!
				@brief			テクスチャの生成
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Format		フォーマット
				@param[in]		Usage		管理方法
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(const MofU32 w, const MofU32 h, const PixelFormat Format, const BufferAccess Usage) = 0;
		/*************************************************************************//*!
				@brief			描画ターゲット用テクスチャの生成
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Format		フォーマット
				@param[in]		Usage		管理方法
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateTarget(const MofU32 w, const MofU32 h, const PixelFormat Format, const BufferAccess Usage) = 0;
				
		/*************************************************************************//*!
				@brief			バッファのマップ<br>
								テクスチャのメモリをロックして、先頭のアドレスを返す。
				@param[in]		mt				マップタイプ
				@param[out]		pRowPitch		横のバイト数
				
				@return			マップされたメモリアドレスを返す。<br>
								失敗の場合NULLになる。
		*//**************************************************************************/
		virtual LPMofVoid Map(MofU32 mt, LPMofU32 pRowPitch = NULL) = 0;
		/*************************************************************************//*!
				@brief			バッファのアンマップ<br>
								テクスチャのメモリのロックを解除する。<br>
								テクスチャメモリへの書き込みにCPUへのマップ、ロックが不要な環境では呼び出す必要はない。
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool UnMap(void) = 0;

		//----------------------------------------------------------------------------
		////テクスチャの描画
		////座標指定での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment) = 0;



		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;
					
		//----------------------------------------------------------------------------
		////テクスチャの描画
		////出力矩形への描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,MofU32 col) = 0;



		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,const Rectangle& srec,MofU32 col) = 0;

		//----------------------------------------------------------------------------
		////テクスチャの描画
		////拡大倍率指定での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,MofU32 col,TextureAlignment Alignment) = 0;


		
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,TextureAlignment Alignment) = 0;
				


		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;



		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;



		//----------------------------------------------------------------------------
		////テクスチャの描画
		////回転角度指定での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,TextureAlignment Alignment) = 0;


				
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;


			  
		//----------------------------------------------------------------------------
		////テクスチャの描画
		////拡大倍率、回転角度指定での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,TextureAlignment Alignment) = 0;



		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;
		
		//----------------------------------------------------------------------------
		////テクスチャの描画
		////2D空間での行列での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Pivot		アライメント位置
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col,const Vector3& Pivot) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Pivot		アライメント位置
				@param[in]		Size		サイズ
				@param[in]		uvp			UV移動
				@param[in]		uvs			UV拡大
				@param[in]		uva			UV回転
				@param[in]		vpos		頂点移動
				@param[in]		vcol		頂点カラー
				@param[in]		vcolr		頂点カラーレート
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Rectangle& srec, const Vector4& col, const Vector3& Pivot, const Vector3& Size, const Vector2& uvp, const Vector2& uvs, const MofFloat uva, LPVector2 vpos, LPVector4 vcol, MofFloat vcolr) = 0;
		
		//----------------------------------------------------------------------------
		////テクスチャの描画
		////3D空間での行列での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		col			描画色
				@param[in]		bRatio		比率維持フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,MofU32 col,MofBool bRatio) = 0;
		
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		bRatio		比率維持フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col,MofBool bRatio) = 0;



		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャ取得
				@param			None

				@return			テクスチャ
		*//**************************************************************************/
		virtual MofTexture GetTexture(void) = 0;
		/*************************************************************************//*!
				@brief			テクスチャ取得
				@param			None

				@return			テクスチャ
		*//**************************************************************************/
		virtual MofTextureHandle GetTextureHandle(void) = 0;
		/*************************************************************************//*!
				@brief			テクスチャへ描画するための描画ターゲットを取得
				@param			None
				
				@return			描画ターゲットを返す。
								失敗の場合NULLになる。
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTarget(void) = 0;
		/*************************************************************************//*!
				@brief			幅取得
				@param			None

				@return			画像の幅
		*//**************************************************************************/
		virtual MofU32 GetWidth(void) const = 0;
		/*************************************************************************//*!
				@brief			高さ取得
				@param			None

				@return			画像の高さ
		*//**************************************************************************/
		virtual MofU32 GetHeight(void) const = 0;
	};

	//ポインタ置き換え
	typedef ITexture*			LPTexture;
	typedef CDynamicArray< LPTexture >		CTextureArray,*LPTextureArray;
}

#endif

//[EOF]