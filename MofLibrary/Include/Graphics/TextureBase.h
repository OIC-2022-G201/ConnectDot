/*************************************************************************//*!
					
					@file	TextureBase.h
					@brief	テクスチャ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__TEXTUREBASE__H__

#define		__TEXTUREBASE__H__

//INCLUDE
#include	"Texture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	テクスチャ基底クラス

			環境に依存しない基本的なテクスチャの処理を行う基底クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CTextureBase : public ITexture {
	protected:
		/*******************//*!
		名前
		*//********************/
		CString						m_Name;
		/*******************//*!
		幅
		*//********************/
		MofU32						m_Width;
		/*******************//*!
		高さ
		*//********************/
		MofU32						m_Height;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CTextureBase();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーテクスチャ

				@return			None
		*//**************************************************************************/
		CTextureBase(const CTextureBase& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CTextureBase();
		
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
		virtual MofBool Render(MofFloat px,MofFloat py);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,TextureAlignment Alignment);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment);



		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);
		
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
		virtual MofBool Render(const Rectangle& drec);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,MofU32 col);



		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,const Rectangle& srec);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,const Rectangle& srec,MofU32 col);

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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,MofU32 col);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,TextureAlignment Alignment);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,MofU32 col,TextureAlignment Alignment);


		
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,TextureAlignment Alignment);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,TextureAlignment Alignment);
				


		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);



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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);



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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,MofU32 col);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,TextureAlignment Alignment);
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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,TextureAlignment Alignment);


				
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec);
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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);

		

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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,TextureAlignment Alignment);



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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);
		
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
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col,const Vector3& Pivot);
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
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec, const Vector4& col,const Vector3& Pivot, const Vector3& Size, const Vector2& uvp, const Vector2& uvs, const MofFloat uva, LPVector2 vpos, LPVector4 vcol, MofFloat vcolr);

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
		virtual MofBool Render(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,MofU32 col);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		col			描画色
				@param[in]		bRatio		比率維持フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,MofU32 col,MofBool bRatio);
		
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		bRatio		比率維持フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col,MofBool bRatio);



		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前設定
				@param[in]		pName			設定する名前
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void);
		/*************************************************************************//*!
				@brief			幅取得
				@param			None

				@return			画像の幅
		*//**************************************************************************/
		virtual MofU32 GetWidth(void) const;
		/*************************************************************************//*!
				@brief			高さ取得
				@param			None

				@return			画像の高さ
		*//**************************************************************************/
		virtual MofU32 GetHeight(void) const;
	};

	#include	"TextureBase.inl"
}

#endif

//[EOF]