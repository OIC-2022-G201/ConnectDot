/*************************************************************************//*!
					
					@file	GLShaderBind_GaussianBlur.h
					@brief	基本スプライトシェーダーバインド。<br>
							標準的なスプライト描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.19
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_GAUSSIANBLUR__H__

#define		__GLSHADERBIND_GAUSSIANBLUR__H__

//INCLUDE
#include	"../ShaderBind_GaussianBlurBase.h"

namespace Mof {

	/*******************************//*!
	@brief	シェーダーバインド基底インターフェイス

			シェーダーのためのバッファの設定を行うインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_GaussianBlur : public CShaderBind_GaussianBlurBase {
	public:
	protected:
		/*******************//*!
		シェーダーID
		*//********************/
		GLuint									m_ShaderID;
		/*******************//*!
		頂点ロケーション
		*//********************/
		GLuint									m_Attribute[CShaderBind_GaussianBlurBase::ATTRIBUTE_COUNT];
		/*******************//*!
		テクスチャロケーション
		*//********************/
		GLuint									m_TexLocation;
		/*******************//*!
		プリミティブパラメータロケーション
		*//********************/
		GLuint									m_OffsetLocation;
		/*******************//*!
		プリミティブパラメータロケーション
		*//********************/
		GLuint									m_SizeLocation;
		/*******************//*!
		プリミティブパラメータロケーション
		*//********************/
		GLuint									m_TOffsetLocation;
		/*******************//*!
		プリミティブパラメータロケーション
		*//********************/
		GLuint									m_TSizeLocation;
		/*******************//*!
		プリミティブパラメータロケーション
		*//********************/
		GLuint									m_ColorLocation;
		/*******************//*!
		ワールドマトリクスロケーション
		*//********************/
		GLuint									m_WorldLocation;
		/*******************//*!
		ビューマトリクスロケーション
		*//********************/
		GLuint									m_ViewLocation;
		/*******************//*!
		プロジェクションマトリクスロケーション
		*//********************/
		GLuint									m_ProjectionLocation;
		/*******************//*!
		ぼかし用オフセットロケーション
		*//********************/
		GLuint									m_BlurTexOffsets;
		/*******************//*!
		ぼかし用逆オフセットロケーション
		*//********************/
		GLuint									m_BlurReverseOffset;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_GaussianBlur();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param			pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_GaussianBlur(const CGLShaderBind_GaussianBlur& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderBind_GaussianBlur();
		
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pvb			頂点バッファ配列
				@param[in]		Cnt			頂点バッファ配列数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateVertexLayout(LPVertexBuffer* pvb, MofU32 Cnt = 0);

		/*************************************************************************//*!
				@brief			バインドの実行
				@param[in]		pGeom		ジオメトリ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Bind(LPGeometry pGeom = NULL);

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
				@brief			バッファの設定
				@param[in]		n			番号
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n);
		/*************************************************************************//*!
				@brief			サンプラの設定<br>
								OpenGLで実行時のみ有効<br>
								DirectX9の場合はシェーダーでの指定が、OpenGL系の場合はテクスチャでの指定が有効になる。
				@param[in]		n			番号
				@param[in]		pSamp		サンプラ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetSamplerState(MofU32 n,MofSamplerState pSamp);
		/*************************************************************************//*!
				@brief			テクスチャの設定
				@param[in]		n			番号
				@param[in]		pTex		テクスチャ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);

		//クラス基本定義
		MOF_LIBRARYCLASS(CGLShaderBind_GaussianBlur,MOF_GLSHADERBINDGAUSSIANBLURCLASS_ID);
	};

	#include	"GLShaderBind_GaussianBlur.inl"

	//置き換え
	typedef CGLShaderBind_GaussianBlur		CShaderBind_GaussianBlur;
	typedef CShaderBind_GaussianBlur*		LPShaderBind_GaussianBlur;
}

#endif

//[EOF]
