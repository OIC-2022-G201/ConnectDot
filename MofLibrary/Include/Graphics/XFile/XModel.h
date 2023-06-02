/*************************************************************************//*!
					
					@file	XModel.h
					@brief	Xファイルモデルクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__XMODEL__H__

#define		__XMODEL__H__

//INCLUDE
#include	"../../Common/KeyFrameArray.h"
#include	"../GraphicsCommon.h"

//DEFINE

//!Xファイルのヘッダーの大きさ
#define		MOF_XFILE_HEADER_SIZE				16

//!関連最大数
#define		MOF_XFILE_MAX_RELATION				8

//!キー定義
#define		MOF_XFILE_ANIMATION_TRANSLATION		0x01
#define		MOF_XFILE_ANIMATION_SCALING			0x02
#define		MOF_XFILE_ANIMATION_ROTATION		0x04
#define		MOF_XFILE_ANIMATION_MATRIX			0x80

namespace Mof {
	
	/*******************************//*!
	@brief	Xファイルテンプレート列挙

			Xファイルを読み込むためのテンプレートタイプの列挙。

	@author	CDW
	*//********************************/
	enum tag_MOFXFILEANALYS_TEMPLATE {
		MOF_XFILE_TEMP_MESH,										//!<メッシュ
		MOF_XFILE_TEMP_MESHTEXTURECOORDS,							//!<メッシュテクスチャ座標
		MOF_XFILE_TEMP_MESHNORMALS,									//!<メッシュの法線
		MOF_XFILE_TEMP_VERTEXCOLOR,									//!<頂点カラー
		MOF_XFILE_TEMP_MESHMATERIALLIST,							//!<メッシュマテリアルリスト
		MOF_XFILE_TEMP_MATERIAL,									//!<マテリアル
		MOF_XFILE_TEMP_TEXTUREFILENAME,								//!<テクスチャ
		MOF_XFILE_TEMP_FRAME,										//!<フレーム
		MOF_XFILE_TEMP_FRAMETRANSFORMMATRIX,						//!<フレームのローカルトランスフォーム
		MOF_XFILE_TEMP_ANIMATIONTICKS,								//!<アニメーション進行速度
		MOF_XFILE_TEMP_ANIMATION,									//!<アニメーション
		MOF_XFILE_TEMP_ANIMATIONSET,								//!<アニメーションセット
		MOF_XFILE_TEMP_ANIMATIONKEY,								//!<アニメーションキー
		MOF_XFILE_TEMP_XSKINHEADER,									//!<スキンメッシュのヘッダー
		MOF_XFILE_TEMP_SKINWEIGHTS,									//!<スキンメッシュのウエイト
		MOF_XFILE_TEMP_RELATION,									//!<間接参照

		MOF_XFILE_TEMP_NUM,											//!<テンプレートの総数
	};
	
	/*******************************//*!
	@brief	Xファイルフレーム構造体

			Xファイルのフレーム情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMESHFRAME {
		CString						Name;							//!<名前
		Matrix44*					pTransformMat;					//!<フレームに関連付けされたトランスフォームマトリクス
		Matrix44					Mat;							//!<このフレームのマトリクス
		Matrix44					OffsetMat;						//!<オフセット行列
		Matrix44					ConvMat;						//!<最終行列
		MofU8						nChild;							//!<子供の数
		MofU16						ID;								//!<識別用配列番号
		struct tag_MOFXMESHFRAME**	pChild;							//!<子供のフレーム
		struct tag_MOFXMESHFRAME*	pParent;						//!<親のフレーム
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMESHFRAME() :
		Name() ,
		pTransformMat(NULL) ,
		Mat() ,
		OffsetMat() ,
		ConvMat() ,
		nChild(0) ,
		ID(0) ,
		pChild(NULL) ,
		pParent(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMESHFRAME(){
			MOF_SAFE_FREE(pChild,"CXModel Release");
		}
	}MOFXMESHFRAME,*LPMOFXMESHFRAME;

	/*******************************//*!
	@brief	XファイルFLOATキー構造体

			XファイルFLOATキー情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXFLOATKEYS {
		MofU32						nFloat;							//!<数
		MofFloat*					Fdata;							//!<float
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXFLOATKEYS() :
		nFloat(0) ,
		Fdata(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXFLOATKEYS(){
			MOF_SAFE_FREE(Fdata,"CXModel Release");
		}
	}MOFXFLOATKEYS,*LPMOFXFLOATKEYS;
	
	/*******************************//*!
	@brief	XファイルFLOATタイムキー構造体

			XファイルFLOATキーとその時間情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXTIMEFLOATKEYS {
		MofU32						Time;							//!<時間
		MOFXFLOATKEYS				TFkeys;							//!<float配列
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXTIMEFLOATKEYS() :
		Time(0) ,
		TFkeys() {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXTIMEFLOATKEYS(){
		}
	}MOFXTIMEFLOATKEYS,*LPMOFXTIMEFLOATKEYS;

	/*******************************//*!
	@brief	XファイルUV情報構造体

			XファイルUV情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXTEXTURECOORDS {
		MofU32						nCoords;						//!<UVの数
		TextureCoords*				Coords;							//!<UV
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXTEXTURECOORDS() :
		nCoords(0) ,
		Coords(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXTEXTURECOORDS(){
			MOF_SAFE_FREE(Coords,"CXModel Release");
		}
	}MOFXTEXTURECOORDS,*LPMOFXTEXTURECOORDS;
	
	/*******************************//*!
	@brief	Xファイルの面情報構造体

			Xファイル面情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMESHFACE {
		MofU32						nFaceIndices;					//!<面のインデックスの数
		MofU32						FaceIndices[4];					//!<面のインデックス
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMESHFACE() :
		nFaceIndices(0) {
			memset(FaceIndices, 0, sizeof(MofU32) * 4);
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMESHFACE(){
		}
	}MOFXMESHFACE,*LPMOFXMESHFACE;
	
	/*******************************//*!
	@brief	Xファイルの法線情報構造体

			Xファイル法線情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMESHNORMAL {
		MofU32						nNormal;						//!<法線ベクトルの数
		Vector3*					Normal;							//!<法線ベクトル
		MofU32						nFaceNormal;					//!<法線のフェイスの数
		LPMOFXMESHFACE				FaceNormal;						//!<法線のフェイス
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMESHNORMAL() :
		nNormal(0) ,
		Normal(NULL) ,
		nFaceNormal(0) ,
		FaceNormal(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMESHNORMAL(){
			MOF_SAFE_FREE(Normal,"CXModel Release");
			MOF_SAFE_FREE(FaceNormal,"CXModel Release");
		}
	}MOFXMESHNORMAL,*LPMOFXMESHNORMAL;
	
	/*******************************//*!
	@brief	Xファイルの頂点カラー情報構造体

			Xファイル頂点カラー情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXVERTEXCOLORKEY {
		MofU32						No;								//!<対応番号
		Vector4						Color;							//!<色
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXVERTEXCOLORKEY() :
		No(0) ,
		Color() {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXVERTEXCOLORKEY(){
		}
	}MOFXVERTEXCOLORKEY,*LPMOFXVERTEXCOLORKEY;
	
	/*******************************//*!
	@brief	Xファイルの頂点カラー情報構造体

			Xファイル頂点カラー情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXVERTEXCOLORS {
		MofU32						nVertex;						//!<頂点数
		LPMOFXVERTEXCOLORKEY		Colors;							//!<頂点カラー
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXVERTEXCOLORS() :
		nVertex(0) ,
		Colors(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXVERTEXCOLORS(){
			MOF_SAFE_FREE(Colors,"CXModel Release");
		}
	}MOFXVERTEXCOLORS,*LPMOFXVERTEXCOLORS;
	
	/*******************************//*!
	@brief	Xファイルのマテリアル情報構造体

			Xファイルマテリアル情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFXMATERIAL {
		CString						Name;							//!<名前
		Vector4						Diffuse;						//!<ディフューズ
		Vector4						Ambient;						//!<アンビエント
		Vector4						Emissive;						//!<エミッシブ
		Vector4						Speculer;						//!<スペキュラー
		MofFloat					Power;							//!<スペキュラーパワー
		MofU8						TextureCount;					//!<テクスチャ数
		LPString*					pTextureName;					//!<テクスチャ名
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMATERIAL() :
		Name() ,
		Diffuse() ,
		Ambient() ,
		Emissive() ,
		Speculer() ,
		Power(0.0f) ,
		TextureCount(0) ,
		pTextureName(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMATERIAL(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(pTextureName,"CXModel Release");
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFXMATERIAL);
	}MOFXMATERIAL,*LPMOFXMATERIAL;
	
	/*******************************//*!
	@brief	Xファイルのマテリアルレンダリングオフセット情報構造体

			Xファイルマテリアルレンダリングオフセット情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMATERIALOFFSET {
		MofU32						Offset;							//!<オフセット
		MofU32						RenderFace;						//!<描画フェイス
		LPMofU32					pRenderIndex;					//!<描画インデックス
		MofU32						RenderIndexCount;				//!<描画インデックス数
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMATERIALOFFSET() :
		Offset(0) ,
		RenderFace(0) ,
		pRenderIndex(NULL) ,
		RenderIndexCount(0) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMATERIALOFFSET(){
			MOF_SAFE_FREE(pRenderIndex,"Index");
		}
	}MOFXMATERIALOFFSET,*LPMOFXMATERIALOFFSET;
	
	/*******************************//*!
	@brief	Xファイルのマテリアルリスト情報構造体

			Xファイルマテリアルリスト情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMATERIALLIST {
		MofU32						nMaterial;						//!<マテリアルの数
		MofU32						nFace;							//!<面の数
		MofU32*						Face;							//!<面
		LPMOFXMATERIALOFFSET		Offset;							//!<オフセット
		LPMOFXMATERIAL*				Material;						//!<関連付けたマテリアル
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMATERIALLIST() :
		nMaterial(0) ,
		nFace(0) ,
		Face(NULL) ,
		Offset(NULL) ,
		Material(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMATERIALLIST(){
			MOF_SAFE_FREE(Face,"CXModel Release");
			MOF_SAFE_FREE(Material,"CXModel Release");
			MOF_SAFE_DELETE_ARRAY(Offset);
		}
	}MOFXMATERIALLIST,*LPMOFXMATERIALLIST;
	
	/*******************************//*!
	@brief	Xファイルのアニメーションキー情報構造体

			Xファイルアニメーションキー情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXANIMETIONKEY {
		MofU32						KeyType;						//!<キーの種類
		MofU32						nKey;							//!<キーの数
		LPMOFXTIMEFLOATKEYS*		pKey;							//!<キー
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXANIMETIONKEY() :
		KeyType(0) ,
		nKey(0) ,
		pKey(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXANIMETIONKEY(){
			if(pKey)
			{
				for(MofU32 i = 0;i < nKey;i++)
				{
					MOF_SAFE_DELETE(pKey[i]);
				}
				MOF_SAFE_FREE(pKey,"CXModel Release");
			}
		}
	}MOFXANIMATIONKEY,*LPMOFXANIMATIONKEY;
	
	/*******************************//*!
	@brief	Xファイルのアニメーション情報構造体

			Xファイルアニメーション情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXANIMETION {
		MofU8						nAnimationKey;					//!<アニメーションキー数
		LPMOFXANIMATIONKEY*			pAnimKey;						//!<関連するアニメーションキー
		LPMOFXMESHFRAME				pFrame;							//!<対応するフレーム
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXANIMETION() :
		nAnimationKey(0) ,
		pAnimKey(NULL) ,
		pFrame(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXANIMETION(){
			MOF_SAFE_FREE(pAnimKey,"CXModel Release");
		}
	}MOFXANIMATION,*LPMOFXANIMATION;
	
	/*******************************//*!
	@brief	Xファイルのアニメーションセット情報構造体

			Xファイルアニメーションセット情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXANIMETIONSET {
		CString						Name;							//!<アニメーション名
		MofU32						MaxCount;						//!<最大アニメーションカウント値
		MofU32						nAnimation;						//!<アニメーション数
		MofU32						ID;								//!<ID
		LPMOFXANIMATION*			pAnimation;						//!<対応するアニメーション

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXANIMETIONSET() :
		Name() ,
		MaxCount(0) ,
		nAnimation(0) ,
		ID(0) ,
		pAnimation(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXANIMETIONSET(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(pAnimation,"CXModel Release");
		}
	}MOFXANIMATIONSET,*LPMOFXANIMATIONSET;

	/*******************************//*!
	@brief	Xファイルのスキニング用ヘッダー情報構造体

			Xファイルスキニング用ヘッダー情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXSKINHEADER {
		MofU16						nSkinWeightsVertex;				//!<影響を受ける頂点
		MofU16						nSkinWeightsFace;				//!<影響を受ける面
		MofU16						nBones;							//!<ボーンの数

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXSKINHEADER() :
		nSkinWeightsVertex(0) ,
		nSkinWeightsFace(0) ,
		nBones(0) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXSKINHEADER(){
		}
	}MOFXSKINHEADER,*LPMOFXSKINHEADER;
	
	/*******************************//*!
	@brief	Xファイルのスキニング用ウエイト情報構造体

			Xファイルスキニング用ウエイト情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXSKINWEIGHT {
		MofU32						Index;							//!<頂点のインデックス
		MofFloat					Weight;							//!<ウエイト
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXSKINWEIGHT() :
		Index(0) ,
		Weight(0.0f) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXSKINWEIGHT(){
		}
	}MOFXSKINWEIGHT,*LPMOFXSKINWEIGHT;
	
	/*******************************//*!
	@brief	Xファイルのスキニング用ウエイト情報構造体

			Xファイルスキニング用ウエイト情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXSKINWEIGHTS {
		CString						Name;							//!<ボーンの名前
		MofU32						nWeights;						//!<ウエイトの数
		LPMOFXSKINWEIGHT			Weights;						//!<ウエイト
		CMatrix44					MatrixOffset;					//!<マトリクス
		LPMofVoid					pMesh;							//!<対応するメッシュ
		LPMOFXMESHFRAME				pFrame;							//!<対応するフレーム
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXSKINWEIGHTS() :
		Name() ,
		nWeights(0) ,
		Weights(NULL) ,
		MatrixOffset() ,
		pMesh(NULL) ,
		pFrame(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXSKINWEIGHTS(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(Weights,"CXModel Release");
		}
	}MOFXSKINWEIGHTS,*LPMOFXSKINWEIGHTS;
	
	/*******************************//*!
	@brief	Xファイルのメッシュ情報構造体

			Xファイルメッシュ情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_MOFXMESH {
		CString						Name;							//!<名前
		MofU32						nVertices;						//!<頂点の数
		Vector3*					Vertices;						//!<頂点
		MofU32						nFace;							//!<面の数
		LPMOFXMESHFACE				Face;							//!<面

		LPMOFXTEXTURECOORDS			TCoords[MOF_XFILE_MAX_RELATION];//!<テクスチャ座標
		LPMOFXMESHNORMAL			Normal;							//!<法線
		LPMOFXVERTEXCOLORS			VColors[MOF_XFILE_MAX_RELATION];//!<頂点カラー
		LPMOFXMATERIALLIST			MaterialList;					//!<マテリアルリスト
		LPMOFXMESHFRAME				Frame;							//!<フレーム

		LPMOFXSKINHEADER			SHerder;						//!<スキンメッシュのヘッダー
		LPMOFXSKINWEIGHTS*			SWeights;						//!<スキンメッシュのウエイト

		MofU32						nIndex;							//!<インデックスの数
		MofU32*						Index;							//!<インデックス
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXMESH() :
		Name() ,
		nVertices(0) ,
		Vertices() ,
		nFace(0) ,
		Face(NULL) ,
		Normal(NULL) ,
		MaterialList(NULL) ,
		Frame(NULL) ,
		SHerder(NULL) ,
		SWeights(NULL) ,
		nIndex(0) ,
		Index(NULL) {
			memset(TCoords,0,sizeof(LPMOFXTEXTURECOORDS) * MOF_XFILE_MAX_RELATION);
			memset(VColors,0,sizeof(LPMOFXVERTEXCOLORS) * MOF_XFILE_MAX_RELATION);
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFXMESH(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(Vertices,"CXModel Release");
			MOF_SAFE_FREE(Face,"CXModel Release");
			MOF_SAFE_FREE(Index,"CXModel Release");
			MOF_SAFE_FREE(SWeights,"CXModel Release");
		}
	}MOFXMESH,*LPMOFXMESH;

	/*******************************//*!
	@brief	Xファイルのオブジェクト情報構造体

			Xファイルオブジェクト情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFXFILEOBJECT {
		MofU8						Type;							//!<種類
		CString						Name;							//!<名前
		LPMofVoid					pData;							//!<データ
		MofS32						nChild;							//!<子の数
		MofS32						nRelation;						//!<関連の数

		struct tag_MOFXFILEOBJECT*	pParents;						//!<親
		struct tag_MOFXFILEOBJECT*	pChildFast;						//!<先頭の子供
		struct tag_MOFXFILEOBJECT*	pChildLast;						//!<最後の子供
		struct tag_MOFXFILEOBJECT*	pSibling;						//!<兄弟
		struct tag_MOFXFILEOBJECT*	pRelation[MOF_XFILE_MAX_RELATION];//!<関連付け
		struct tag_MOFXFILEOBJECT*	pNext;							//!<次
		
		/*******************************//*!
		@brief	Xファイルのオブジェクト削除用基底

				Xファイルオブジェクトを削除するための削除用基底クラス。

		@author	CDW
		*//********************************/
		class DeleterBase {
		public:
			virtual ~DeleterBase() {}
			virtual LPMofVoid GetData() = 0;
		};
		/*******************************//*!
		@brief	Xファイルのオブジェクト削除用テンプレート

				Xファイルオブジェクトを削除するための削除用テンプレートクラス。

		@author	CDW
		*//********************************/
		template< class T > class Deleter : public DeleterBase {
		public:
			T* pObj;
			Deleter(){ pObj = new T(); }
			virtual ~Deleter(){	MOF_SAFE_DELETE(pObj); }
			virtual LPMofVoid GetData(){ return pObj; }
		};

		DeleterBase*				pDataDelete;					//!<データ削除用

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFXFILEOBJECT() :
		Type(0) ,
		Name() ,
		pData(NULL) ,
		nChild(0) ,
		nRelation(0) ,
		pParents(NULL) ,
		pChildFast(NULL) ,
		pChildLast(NULL) ,
		pSibling(NULL) ,
		pNext(NULL) {
			memset(pRelation,0,sizeof(tag_MOFXFILEOBJECT*) * MOF_XFILE_MAX_RELATION);
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_MOFXFILEOBJECT(){
			Name.SetString(NULL);
			if(pData)
			{
				MOF_SAFE_DELETE(pDataDelete);
				pData = NULL;
			}
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFXFILEOBJECT);
	}MOFXFILEOBJECT,*LPMOFXFILEOBJECT;
	
	/*******************************//*!
	@brief	Xファイルモデルクラス

			Xファイルから変換するために情報を保存するためのクラス。
			Xファイルから直接でのレンダリング機能などは提供しない。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CXModel : public IMofNamedObject {
	private:
		/*******************//*!
		ファイル名
		*//********************/
		CString						m_Name;
		/*******************//*!
		解析オブジェクト先頭
		*//********************/
		LPMOFXFILEOBJECT			m_pFastObj;
		/*******************//*!
		解析オブジェクト最後尾
		*//********************/
		LPMOFXFILEOBJECT			m_pLastObj;
		/*******************//*!
		////オブジェクトの数
		*//********************/
		MofU32						m_ObjCount;
		/*******************//*!
		////アニメーションがあるかどうか
		*//********************/
		MofBool						m_AnimationFlag;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CXModel();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CXModel();
		/*************************************************************************//*!
				@brief			オブジェクトの追加
				@param[in]		Type		追加オブジェクトタイプ
				@param[in]		Name		オブジェクト名
				@param[in]		pParents	オブジェクトの親

				@return			追加したオブジェクトを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT AddObject(MofS32 Type,LPCMofChar pName,LPMOFXFILEOBJECT pParents);
		
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
		/*************************************************************************//*!
				@brief			アニメーションフラグ設定
				@param[in]		Flag		フラグ（アニメーションを含むモデルの場合TRUE,含まない場合FALSE）
				
				@return			None
		*//**************************************************************************/
		void SetAnimationFlag(MofBool Flag);

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
				@brief			先頭オブジェクト取得
				@param			None

				@return			先頭オブジェクト
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetFastObject(void);
		/*************************************************************************//*!
				@brief			オブジェクト数取得
				@param			None

				@return			オブジェクト数
		*//**************************************************************************/
		MofU32 GetObjectCount(void);
		/*************************************************************************//*!
				@brief			指定タイプのオブジェクト取得
								Typeに指定したタイプのオブジェクトを取得する。
								検索は先頭オブジェクトから順番に行われ、最初に見つけたオブジェクトを返す
				@param[in]		Type		検索するタイプ

				@return			発見したオブジェクト<br>
								見つからなかった場合はNULLを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetFastTypeObject(MofS32 Type);
		/*************************************************************************//*!
				@brief			親オブジェクトから指定タイプのオブジェクト取得
								Typeに指定したタイプのオブジェクトを取得する。
								検索はObjの親へ順番に検索され、最初に見つけたオブジェクトを返す
				@param[in]		Type		検索するタイプ
				@param[in]		Obj			検索ルートオブジェクト

				@return			発見したオブジェクト<br>
								見つからなかった場合はNULLを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetParentsObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			子オブジェクトから指定タイプのオブジェクト取得
								Typeに指定したタイプのオブジェクトを取得する。
								検索はObjの子へ順番に検索され、最初に見つけたオブジェクトを返す
				@param[in]		Type		検索するタイプ
				@param[in]		Obj			検索ルートオブジェクト

				@return			発見したオブジェクト<br>
								見つからなかった場合はNULLを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetChildObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			同一階層オブジェクトから指定タイプのオブジェクト取得
								Typeに指定したタイプのオブジェクトを取得する。
								検索はObjの同一階層を順番に検索され、最初に見つけたオブジェクトを返す
				@param[in]		Type		検索するタイプ
				@param[in]		Obj			検索ルートオブジェクト

				@return			発見したオブジェクト<br>
								見つからなかった場合はNULLを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetSiblingObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			リンクオブジェクトから指定タイプのオブジェクト取得
								Typeに指定したタイプのオブジェクトを取得する。
								検索はObjのリンクを順番に検索され、最初に見つけたオブジェクトを返す
				@param[in]		Type		検索するタイプ
				@param[in]		Obj			検索ルートオブジェクト

				@return			発見したオブジェクト<br>
								見つからなかった場合はNULLを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetRelationObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			親オブジェクトと関連オブジェクトから指定タイプのオブジェクト取得
								Typeに指定したタイプのオブジェクトを取得する。
								検索はObjの親へ順番に検索され見つからなかった場合
								Objのリンクを順番に検索する。最初に見つけたオブジェクトを返す
				@param[in]		Type		検索するタイプ
				@param[in]		Obj			検索ルートオブジェクト

				@return			発見したオブジェクト<br>
								見つからなかった場合はNULLを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetParentsAndRelationObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			子オブジェクトと関連オブジェクトから指定タイプのオブジェクト取得
								Typeに指定したタイプのオブジェクトを取得する。
								検索はObjの子へ順番に検索され見つからなかった場合
								Objのリンクを順番に検索する。最初に見つけたオブジェクトを返す
				@param[in]		Type		検索するタイプ
				@param[in]		Obj			検索ルートオブジェクト

				@return			発見したオブジェクト<br>
								見つからなかった場合はNULLを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetChileAndRelationObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			同一階層オブジェクトと関連オブジェクトから指定タイプのオブジェクト取得
								Typeに指定したタイプのオブジェクトを取得する。
								検索はObjの同一階層を順番に検索され見つからなかった場合
								Objのリンクを順番に検索する。最初に見つけたオブジェクトを返す
				@param[in]		Type		検索するタイプ
				@param[in]		Obj			検索ルートオブジェクト

				@return			発見したオブジェクト<br>
								見つからなかった場合はNULLを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetSiblingAndRelationObject(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			子オブジェクトと関連オブジェクトから指定タイプのオブジェクト列挙
								Typeに指定したタイプのオブジェクトを列挙する。
								検索はObjの子、Objのリンクの順番で検索する。Addresに列挙結果を格納する
				@param[in]		Type		検索するタイプ
				@param[in,out]	Addres		事前に列挙の格納に必要なメモリを確保しておくこと
				@param[in]		Obj			検索ルートオブジェクト

				@return			None
		*//**************************************************************************/
		void EnumChildAndRelationObject(MofS32 Type,void** Addres,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			全てのオブジェクトから指定タイプのオブジェクト列挙
								Typeに指定したタイプのオブジェクトを列挙する。Addresに列挙結果を格納する
				@param[in]		Type		検索するタイプ
				@param[in,out]	Addres		事前に列挙の格納に必要なメモリを確保しておくこと

				@return			None
		*//**************************************************************************/
		void EnumTypeObject(MofS32 Type,void** Addres);
		/*************************************************************************//*!
				@brief			全てのオブジェクトから指定タイプで指定名のオブジェクト取得
				@param[in]		Type		検索するタイプ
				@param[in]		Name		検索する名前

				@return			発見したオブジェクト<br>
								見つからなかった場合はNULLを返す
		*//**************************************************************************/
		LPMOFXFILEOBJECT GetMatchNameObject(MofS32 Type,LPMofChar Name);
		/*************************************************************************//*!
				@brief			関連オブジェクトから指定タイプのオブジェクトの数取得
				@param[in]		Type		検索するタイプ
				@param[in]		Obj			検索ルートオブジェクト

				@return			関連オブジェクト内の指定タイプオブジェクトの数
		*//**************************************************************************/
		MofU32 GetRelationObjectCount(MofS32 Type,LPMOFXFILEOBJECT Obj);
		/*************************************************************************//*!
				@brief			全てのオブジェクトから指定タイプのオブジェクトの数取得
				@param[in]		Type		検索するタイプ

				@return			指定タイプオブジェクトの数
		*//**************************************************************************/
		MofU32 GetTypeObjectCount(MofS32 Type);
		/*************************************************************************//*!
				@brief			全てのオブジェクトから親のいないオブジェクトの数取得
				@param			None

				@return			親のいないオブジェクトの数
		*//**************************************************************************/
		MofU32 GetNoParentFrameObjectCount(void);
		/*************************************************************************//*!
				@brief			全てのオブジェクトから親のいないオブジェクト列挙
								親のいないオブジェクトを列挙する。Addresに列挙結果を格納する
				@param[in,out]	Addres		事前に列挙の格納に必要なメモリを確保しておくこと

				@return			None
		*//**************************************************************************/
		void EnumNoParentFrameObject(void** Addres);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CXModel,MOF_XMODELCLASS_ID);
	};

	//TYPEDEF
	typedef CXModel* LPXModel;

	//INLINE INCLUDE
	#include	"XModel.inl"

}

#endif	//__XMODEL_H_

//[EOF]