/*************************************************************************//*!
					
					@file	DX11ShaderBind_SpriteInstancedColor.h
					@brief	基本スプライトシェーダーバインド。<br>
							標準的なスプライト描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_SPRITEINSTANCEDCOLOR__H__

#define		__DX11SHADERBIND_SPRITEINSTANCEDCOLOR__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteInstancedBase.h"

namespace Mof {

	/*******************************//*!
	@brief	シェーダーバインド基底インターフェイス

			シェーダーのためのバッファの設定を行うインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_SpriteInstancedColor : public CDX11ShaderBind_SpriteInstancedBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力頂点バッファ列挙

		@author	CDW
		*//********************************/
		enum VertexAttribute
		{
			ATTRIBUTE_POSITION,
			ATTRIBUTE_TEXCOORDS,

			ATTRIBUTE_COLOR,
			ATTRIBUTE_MATRIX,

			ATTRIBUTE_COUNT,
		};
	protected:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SpriteInstancedColor();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SpriteInstancedColor(const CDX11ShaderBind_SpriteInstancedColor& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_SpriteInstancedColor();
		
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pvb			頂点バッファ配列
				@param[in]		Cnt			頂点バッファ配列数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateVertexLayout(LPVertexBuffer* pvb, MofU32 Cnt = 0);

		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11ShaderBind_SpriteInstancedColor,MOF_DX11SHADERBINDSPRITEINSTANCEDBASECLASS_ID);
	};

	#include	"DX11ShaderBind_SpriteInstancedColor.inl"
	
	//置き換え
	typedef CDX11ShaderBind_SpriteInstancedColor		CShaderBind_SpriteInstancedColor;
	typedef CShaderBind_SpriteInstancedColor*			LPShaderBind_SpriteInstancedColor;
}

#endif

//[EOF]