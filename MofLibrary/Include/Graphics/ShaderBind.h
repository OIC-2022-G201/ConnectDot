/*************************************************************************//*!
					
					@file	ShaderBind.h
					@brief	シェーダーバインド基底インターフェイス。<br>
							各設定バッファや入力レイアウトを定義し各利用シェーダー毎にパイプラインに設定する。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERBIND__H__

#define		__SHADERBIND__H__

//INCLUDE
#include	"Material.h"
#include	"MeshMotionController.h"
#include	"CameraBase.h"
#include	"DirectionalLight.h"
#include	"ShaderBufferBase.h"
#include	"ShaderResourceBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	シェーダーバインド用レイアウトオブジェクト

			シェーダーのための頂点レイアウト設定を行うレイアウトオブジェクト。

	@author	CDW
	*//********************************/
	typedef struct tag_SHADERBINDLAYOUT {
		VertexFlag							Flag;
		MofVertexLayout						pLayout;

		tag_SHADERBINDLAYOUT() :
		Flag(VERTEXFLAG_UNKOWN) ,
		pLayout(NULL) {
		}

		tag_SHADERBINDLAYOUT(const tag_SHADERBINDLAYOUT& pObj) :
			Flag(pObj.Flag),
			pLayout(pObj.pLayout) {
#ifdef		MOFLIB_DIRECTX11
			if (pLayout)
			{
				pLayout->AddRef();
			}
#endif
#ifdef		MOFLIB_DIRECTX12
			if (pLayout)
			{
				pLayout = new tag_MofVertexLayout(*pObj.pLayout);
			}
#endif
#ifdef		MOFLIB_OPENGL
			if (pLayout)
			{
				pLayout = new CGLLayoutArray(*pLayout);
			}
#endif
		}

		~tag_SHADERBINDLAYOUT(){
#ifdef		MOFLIB_DIRECTX11
			MOF_SAFE_RELEASE(pLayout);
#endif
#ifdef		MOFLIB_DIRECTX12
			MOF_SAFE_DELETE(pLayout);
#endif
#ifdef		MOFLIB_OPENGL
			MOF_SAFE_DELETE(pLayout);
#endif
		}
	}SHADERBINDLAYOUT, *LPSHADERBINDLAYOUT;
	typedef CDynamicArray< LPSHADERBINDLAYOUT > CBindLayout, *LPBindLayout;

	/*******************************//*!
	@brief	シェーダーバインド基底インターフェイス

			シェーダーのためのバッファの設定を行うインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShaderBind : public IMofObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader) = 0;
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pvb			頂点バッファ配列
				@param[in]		Cnt			頂点バッファ配列数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateVertexLayout(LPVertexBuffer* pvb, MofU32 Cnt = 0) = 0;

		/*************************************************************************//*!
				@brief			バインドの実行
				@param[in]		pGeom		ジオメトリ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Bind(LPGeometry pGeom = NULL) = 0;
		/*************************************************************************//*!
				@brief			バインドの実行
				@param[in]		pGeom		ジオメトリ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool BindLayout(LPGeometry pGeom) = 0;
	
		/*************************************************************************//*!
				@brief			バッファの追加
				@param[in]		pName		名前
				@param[in]		size		サイズ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateShaderBuffer(LPCMofChar pName, MofU32 size) = 0;
		/*************************************************************************//*!
				@brief			バッファの追加
				@param[in]		pBuf		バッファ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool AddShaderBuffer(LPShaderBuffer pBuf) = 0;
		/*************************************************************************//*!
				@brief			リソースの追加
				@param[in]		pName		名前
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateShaderResource(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			リソースの追加
				@param[in]		pRes		リソース
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool AddShaderResource(LPShaderResource pRes) = 0;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			バッファの設定
				@param[in]		n			番号
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n) = 0;
		/*************************************************************************//*!
				@brief			バッファの設定
				@param[in]		n			番号
				@param[in]		pData		データ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData) = 0;
		/*************************************************************************//*!
				@brief			サンプラの設定<br>
								DirectX11で実行時のみ有効<br>
								DirectX9の場合はシェーダーでの指定が、OpenGL系の場合はテクスチャでの指定が有効になる。
				@param[in]		n			番号
				@param[in]		st			サンプラタイプ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetSamplerType(MofU32 n,MofU32 st) = 0;
		/*************************************************************************//*!
				@brief			サンプラの設定<br>
								DirectX11で実行時のみ有効<br>
								DirectX9の場合はシェーダーでの指定が、OpenGL系の場合はテクスチャでの指定が有効になる。
				@param[in]		n			番号
				@param[in]		pSamp		サンプラ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetSamplerState(MofU32 n,MofSamplerState pSamp) = 0;
		/*************************************************************************//*!
				@brief			テクスチャの設定
				@param[in]		n			番号
				@param[in]		pTex		テクスチャ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex) = 0;
		
		/*************************************************************************//*!
				@brief			描画用行列を設定する
				@param[in]		wMat			行列

				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(const Matrix44& wMat) = 0;
		/*************************************************************************//*!
				@brief			描画用行列を設定する
				@param[in]		pMotion		モーションコントローラ
				@param[in]		pGeom		ジオメトリ
				
				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(LPMeshMotionController pMotion,LPGeometry pGeom) = 0;
		/*************************************************************************//*!
				@brief			描画用プリミティブパラメーターを設定する
				@param[in]		pPar			テクスチャパラメーター

				@return			None
		*//**************************************************************************/
		virtual void SetPrimitiveParameter(LPPrimitiveRenderParameter pPar) = 0;
		/*************************************************************************//*!
				@brief			描画用テクスチャパラメーターを設定する
				@param[in]		pPar			テクスチャパラメーター

				@return			None
		*//**************************************************************************/
		virtual void SetTextureParameter(LPTextureRenderParameter pPar) = 0;
		/*************************************************************************//*!
				@brief			描画用マテリアルを設定する
				@param[in]		pMat			マテリアル

				@return			None
		*//**************************************************************************/
		virtual void SetMaterial(LPMaterial pMat) = 0;
		/*************************************************************************//*!
				@brief			描画用カメラを設定する
				@param[in]		pc				カメラ

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(LPCamera pc) = 0;
		/*************************************************************************//*!
				@brief			描画用カメラを設定する
				@param[in]		mv				カメラ
				@param[in]		mp				プロジェクション

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(Matrix44& mv,Matrix44& mp) = 0;
		/*************************************************************************//*!
				@brief			描画用基本ライトを設定する
				@param[in]		pl				ライト

				@return			None
		*//**************************************************************************/
		virtual void SetDirectionalLight(LPDirectionalLight pl) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			設定パラメーター数を取得する
				@param			None

				@return			パラメーターの数
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const = 0;
		/*************************************************************************//*!
				@brief			設定パラメーターを取得する
				@param			None

				@return			パラメーター
		*//**************************************************************************/
		virtual LPShaderBufferArray GetShaderBuffer(void) = 0;
		/*************************************************************************//*!
				@brief			設定パラメーターを取得する
				@param[in]		n				番号

				@return			パラメーター
		*//**************************************************************************/
		virtual LPShaderBuffer GetShaderBuffer(MofU32 n) = 0;
		/*************************************************************************//*!
				@brief			設定パラメーターを取得する
				@param[in]		pName			名前

				@return			パラメーター
		*//**************************************************************************/
		virtual LPShaderBuffer GetShaderBufferByName(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			設定リソースを取得する
				@param			None

				@return			リソース
		*//**************************************************************************/
		virtual LPShaderResourceArray GetShaderResource(void) = 0;
		/*************************************************************************//*!
				@brief			設定リソースを取得する
				@param[in]		n				番号

				@return			リソース
		*//**************************************************************************/
		virtual LPShaderResource GetShaderResource(MofU32 n) = 0;
		/*************************************************************************//*!
				@brief			設定リソースを取得する
				@param[in]		pName			名前

				@return			リソース
		*//**************************************************************************/
		virtual LPShaderResource GetShaderResourceByName(LPCMofChar pName) = 0;
	};
	
	//ポインタ置き換え
	typedef IShaderBind*			LPShaderBind;
}

#endif

//[EOF]
