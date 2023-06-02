/*************************************************************************//*!
					
					@file	GLShaderBind_SkinGeometryBase.h
					@brief	基本プリミティブシェーダーバインド。<br>
							標準的なプリミティブ描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_SKINGEOMETRYBASEBASE__H__

#define		__GLSHADERBIND_SKINGEOMETRYBASEBASE__H__

//INCLUDE
#include	"../ShaderBindBase.h"

namespace Mof {

	/*******************************//*!
	@brief	シェーダーバインド基底インターフェイス

			シェーダーのためのバッファの設定を行うインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_SkinGeometryBase : public CShaderBindBase {
	public:
		/*******************************//*!
		@brief	ジオメトリ描画入力頂点バッファ列挙

		@author	CDW
		*//********************************/
		enum VertexAttribute
		{
			ATTRIBUTE_POSITION,
			ATTRIBUTE_NORMAL,
			ATTRIBUTE_TEXCOORDS,
			ATTRIBUTE_COLOR,
			ATTRIBUTE_BLENDWEIGHT,
			ATTRIBUTE_BLENDINDICES,

			ATTRIBUTE_COUNT,
		};		  
		/*******************************//*!
		@brief	ジオメトリ描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_SCENE,
			PARAM_MESH,
			PARAM_MATERIAL,
			PARAM_LIGHT,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	プリミティブ描画シーン情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstSceneParam
		{
			Vector4		vecViewPos;
			Matrix44	mtxView;
			Matrix44	mtxProj;
		};
		/*******************//*!
		プリミティブ描画シーン情報設定
		*//********************/
		ConstSceneParam							m_SceneParam;
		/*******************************//*!
		@brief	プリミティブ描画プリミティブ情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstMeshParam
		{
			MofFloat	mtxWorld[4 * 3 * 128];
			Vector4		colRevise;
			Vector4		CoordsRevise;
		};
		/*******************//*!
		プリミティブ描画プリミティブ情報設定
		*//********************/
		ConstMeshParam							m_MeshParam;
		/*******************************//*!
		@brief	プリミティブ描画マテリアル情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstMaterialParam
		{
			Vector4		matDiffuse;
			Vector4		matAmbient;
			Vector4		matSpeculer;
			Vector4		matEmissive;
			MofFloat	matPower;
		};
		/*******************//*!
		プリミティブ描画マテリアル情報設定
		*//********************/
		ConstMaterialParam						m_MaterialParam;
		/*******************************//*!
		@brief	プリミティブ描画ライト情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstLightParam
		{
			Vector3		litDirection;
			Vector4		litDiffuse;
			Vector4		litAmbient;
			Vector4		litSpeculer;
		};
		/*******************//*!
		プリミティブ描画ライト情報設定
		*//********************/
		ConstLightParam							m_LightParam;
	protected:
		/*******************//*!
		シェーダーID
		*//********************/
		GLuint									m_ShaderID;
		/*******************//*!
		テクスチャロケーション
		*//********************/
		GLuint									m_TexLocation;
		/*******************//*!
		ビューポジションロケーション
		*//********************/
		GLuint									m_ViewPosLocation;
		/*******************//*!
		ワールドマトリクスロケーション
		*//********************/
		GLuint									m_WorldLocation;
		/*******************//*!
		色ロケーション
		*//********************/
		GLuint									m_ColorReviseLocation;
		/*******************//*!
		UV補正ロケーション
		*//********************/
		GLuint									m_CoordsReviseLocation;
		/*******************//*!
		ビューマトリクスロケーション
		*//********************/
		GLuint									m_ViewLocation;
		/*******************//*!
		プロジェクションマトリクスロケーション
		*//********************/
		GLuint									m_ProjectionLocation;
		/*******************//*!
		ディフューズロケーション
		*//********************/
		GLuint									m_DiffuseLocation;
		/*******************//*!
		アンビエントロケーション
		*//********************/
		GLuint									m_AmbientLocation;
		/*******************//*!
		スペキュラロケーション
		*//********************/
		GLuint									m_SpeculerLocation;
		/*******************//*!
		エミッシブロケーション
		*//********************/
		GLuint									m_EmissiveLocation;
		/*******************//*!
		パワーロケーション
		*//********************/
		GLuint									m_PowerLocation;
		/*******************//*!
		ライト方向ロケーション
		*//********************/
		GLuint									m_LightDirectionLocation;
		/*******************//*!
		ディフューズロケーション
		*//********************/
		GLuint									m_LightDiffuseLocation;
		/*******************//*!
		アンビエントロケーション
		*//********************/
		GLuint									m_LightAmbientLocation;
		/*******************//*!
		スペキュラロケーション
		*//********************/
		GLuint									m_LightSpeculerLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_SkinGeometryBase();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param			pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_SkinGeometryBase(const CGLShaderBind_SkinGeometryBase& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderBind_SkinGeometryBase();
		
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
				@brief			バッファの設定
				@param[in]		n			番号
				@param[in]		pData		データ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData);
		/*************************************************************************//*!
				@brief			サンプラの設定<br>
								OpenGLで実行時のみ有効<br>
								DirectX9の場合はシェーダーでの指定が、OpenGL系の場合はテクスチャでの指定が有効になる。
				@param[in]		n			番号
				@param[in]		st			サンプラタイプ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetSamplerType(MofU32 n,MofU32 st);
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

		/*************************************************************************//*!
				@brief			描画用行列を設定する
				@param[in]		wMat			行列

				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			描画用行列を設定する
				@param[in]		pMotion		モーションコントローラ
				@param[in]		pGeom		ジオメトリ
				
				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(LPMeshMotionController pMotion,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			描画用マテリアルを設定する
				@param[in]		pMat			マテリアル

				@return			None
		*//**************************************************************************/
		virtual void SetMaterial(LPMaterial pMat);
		/*************************************************************************//*!
				@brief			描画用プリミティブパラメーターを設定する
				@param[in]		pPar			テクスチャパラメーター

				@return			None
		*//**************************************************************************/
		virtual void SetPrimitiveParameter(LPPrimitiveRenderParameter pPar);
		/*************************************************************************//*!
				@brief			描画用テクスチャパラメーターを設定する
				@param[in]		pPar			テクスチャパラメーター

				@return			None
		*//**************************************************************************/
		virtual void SetTextureParameter(LPTextureRenderParameter pPar);
		/*************************************************************************//*!
				@brief			描画用カメラを設定する
				@param[in]		pc				カメラ

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(LPCamera pc);
		/*************************************************************************//*!
				@brief			描画用カメラを設定する
				@param[in]		mv				カメラ
				@param[in]		mp				プロジェクション

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(Matrix44& mv,Matrix44& mp);
		/*************************************************************************//*!
				@brief			描画用基本ライトを設定する
				@param[in]		pl				ライト

				@return			None
		*//**************************************************************************/
		virtual void SetDirectionalLight(LPDirectionalLight pl);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			設定パラメーター数を取得する
				@param			None

				@return			パラメーターの数
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const { return PARAM_MAX; }

		//クラス基本定義
		MOF_LIBRARYCLASS(CGLShaderBind_SkinGeometryBase,MOF_GLSHADERBINDSKINGEOMETRYBASEBASECLASS_ID);
	};
	
	#include	"GLShaderBind_SkinGeometryBase.inl"

	//置き換え
	typedef CGLShaderBind_SkinGeometryBase			CShaderBind_SkinGeometryBase;
	typedef CShaderBind_SkinGeometryBase*			LPShaderBind_SkinGeometryBase;

}

#endif

//[EOF]
