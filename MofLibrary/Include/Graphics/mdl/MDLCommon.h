/*************************************************************************//*!
					
					@file	MDL基本定義.h
					@brief	MDLファイルの基本定義。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MDLCOMMON__H__

#define		__MDLCOMMON__H__

//----------------------------------
////識別子
//----------------------------------
#define		MBSMODEL_FILE_HEADER				"MBS MODEL VER 0.01 FILE"
#define		MBSMODEL_FILE_HEADERLEN				strlen(MBSMODEL_FILE_HEADER)

//----------------------------------
////頂点フラグ
//----------------------------------
#define		MBSMODEL_VERTEXFLAG_POSITION		0x00000001						//!<頂点座標
#define		MBSMODEL_VERTEXFLAG_NORMAL			0x00000002						//!<頂点法線
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS1	0x00000004						//!<頂点UV
#define		MBSMODEL_VERTEXFLAG_COLOR1			0x00000008						//!<頂点カラー
#define		MBSMODEL_VERTEXFLAG_WAIT			0x00000010						//!<頂点ウェイト
#define		MBSMODEL_VERTEXFLAG_TANGENT			0x00000020						//!<頂点接線
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS2	0x00000040						//!<頂点UV
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS3	0x00000080						//!<頂点UV
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS4	0x00000100						//!<頂点UV
#define		MBSMODEL_VERTEXFLAG_BINORMAL		0x00000200						//!<頂点従法線
#define		MBSMODEL_VERTEXFLAG_COLOR2			0x00000400						//!<頂点カラー
#define		MBSMODEL_VERTEXFLAG_COLOR3			0x00000800						//!<頂点カラー
#define		MBSMODEL_VERTEXFLAG_COLOR4			0x00001000						//!<頂点カラー
#define		MBSMODEL_VERTEXFLAG_POINTSIZE		0x00002000						//!<頂点ポイントサイズ
#define		MBSMODEL_VERTEXFLAG_BLENDINDICES	0x00004000						//!<頂点ウェイト
#define		MBSMODEL_VERTEXFLAG_COLOR			0x00001c08						//!<頂点カラー
#define		MBSMODEL_VERTEXFLAG_TEXTURECOORDS	0x000001c4						//!<頂点UV

//----------------------------------
////頂点カラー最大数
//----------------------------------
#define		MBSMODEL_VERTEX_COLORS				4								//!<頂点カラー最大数

//----------------------------------
////頂点UV最大数
//----------------------------------
#define		MBSMODEL_VERTEX_TEXTURECOORDS		4								//!<UVマップ最大数

//----------------------------------
////頂点ブレンド最大数
//----------------------------------
#define		MBSMODEL_VERTEX_BLENDMAX			4								//!<ブレンド最大数

//----------------------------------
////インデックスタイプ
//----------------------------------
#define		MBSMODEL_INDEXFORMAT16				101								//!<16ビットフォーマット
#define		MBSMODEL_INDEXFORMAT32				102								//!<32ビットフォーマット

//----------------------------------
////アニメーションフラグ
//----------------------------------
#define		MBSMODEL_ANIMATION_ROTATION			0x00000000						//回転
#define		MBSMODEL_ANIMATION_SCALING			0x00000001						//拡大
#define		MBSMODEL_ANIMATION_TRANSLATION		0x00000002						//移動

namespace Mof {

	//ENUM

	//----------------------------------
	////モデルチャンクの列挙
	//----------------------------------
	enum tag_MBSMODEL_TEMPLATE {
		MBSMODEL_TEMP_MESH,															//!<メッシュ
		MBSMODEL_TEMP_VERTEX,														//!<頂点情報
		MBSMODEL_TEMP_INDEX,														//!<インデックス情報
		MBSMODEL_TEMP_MATERIALLIST,													//!<マテリアル情報
		MBSMODEL_TEMP_MATERIAL,														//!<マテリアル情報
		MBSMODEL_TEMP_TEXTURE,														//!<テクスチャ情報
		MBSMODEL_TEMP_SHADER,														//!<シェーダー情報
		MBSMODEL_TEMP_BONE,															//!<ボーン情報
		MBSMODEL_TEMP_BONEGROUP,													//!<ボーングループ情報
		MBSMODEL_TEMP_ANIMATIONSET,													//!<アニメーション情報
		MBSMODEL_TEMP_ANIMATION,													//!<アニメーション情報
		MBSMODEL_TEMP_BLOCK,														//!<ブロック情報
		MBSMODEL_TEMP_LODMODEL,														//!<距離減衰モデル情報
		MBSMODEL_TEMP_IK,															//!<IK情報
		MBSMODEL_TEMP_IKJOINT,														//!<IK接続情報
		MBSMODEL_TEMP_RIGID,														//!<剛体情報
		MBSMODEL_TEMP_RIGIDJOINT,													//!<剛体接続情報

		MBSMODEL_TEMP_MAX,															//!<チャンク最大数

		MBSMODEL_TEMP_END					=		0xffffffff,						//!<チャンク終了
	};
	//TYPEDEF STRUCT

	//----------------------------------
	////モデル頂点
	//----------------------------------
	typedef MOF_ALIGNED16_STRUCT tag_MBSMODELVERTEX {
		Vector3							Pos;										//!<座標
		Vector3							Normal;										//!<法線
		Vector2							UV[MBSMODEL_VERTEX_TEXTURECOORDS];			//!<ＵＶ
		Vector4							Color[MBSMODEL_VERTEX_COLORS];				//!<色
		Vector3							Tangent;									//!<接線
		Vector3							BiNormal;									//!<従法線
		MofU8							BlendIndicesCount;							//!<ブレンドボーン数
		MofU8							BlendIndices[MBSMODEL_VERTEX_BLENDMAX];		//!<ブレンドインデックス
		MofFloat						BlendWait[MBSMODEL_VERTEX_BLENDMAX];		//!<ブレンドウェイト
		MofFloat						PointSize;									//!<ポイントサイズ

		MOF_ALIGNED_NEW_OPERATOR(tag_MBSMODELVERTEX);
	}MBSMODELVERTEX,*LPMBSMODELVERTEX;
	//リスト置き換え
	typedef CDynamicArray< MBSMODELVERTEX > MBSVERTEXLIST,*LPMBSVERTEXLIST;
	typedef	CDynamicArray< MofU32 > MBSINDEXLIST,*LPMBSINDEXLIST;

	//----------------------------------
	////モデル頂点リスト
	//----------------------------------
	typedef struct tag_MBSMODELVERTEXLIST {
		MBSVERTEXLIST					VertexList;									//!<頂点リスト
		MofU32							Flag;										//!<頂点フラグ
		MofU32							Size;										//!<頂点サイズ
		MofU32							Usage;										//!<頂点仕様フラグ
	
		//----------------------
		////コンストラクタ
		//----------------------
		tag_MBSMODELVERTEXLIST() : 
		VertexList() ,
		Flag(0) ,
		Size(0) ,
		Usage(0) {
		}
		tag_MBSMODELVERTEXLIST(const tag_MBSMODELVERTEXLIST& Obj) : 
		VertexList(Obj.VertexList) ,
		Flag(Obj.Flag) ,
		Size(Obj.Size) ,
		Usage(Obj.Usage) {
		}
		//----------------------
		////デストラクタ
		//----------------------
		virtual ~tag_MBSMODELVERTEXLIST(){
			VertexList.Release();
		}
	}MBSMODELVERTEXLIST,*LPMBSMODELVERTEXLIST;

	//----------------------------------
	////モデルインデックスオフセット
	//----------------------------------
	typedef struct tag_MBSMODELINDEXOFFSET {
		MofU32							Offset;										//!<オフセット
		MofU32							RenderFaceCount;							//!<描画面数
		LPMofU32						pRenderIndex;								//!<描画インデックス
		MofU32							RenderIndexCount;							//!<描画インデックス数
		
		//----------------------
		////デストラクタ
		//----------------------
		virtual ~tag_MBSMODELINDEXOFFSET(){
			MOF_SAFE_FREE(pRenderIndex,"Index");
		}
	}MBSMODELINDEXOFFSET,*LPMBSMODELINDEXOFFSET;
	//リスト置き換え
	typedef CDynamicArray< LPMBSMODELINDEXOFFSET > MBSMODELINDEXOFFSETLIST,*LPMBSMODELINDEXOFFSETLIST;

	//----------------------------------
	////モデルインデックスリスト
	//----------------------------------
	typedef struct tag_MBSMODELINDEXLIST {
		MBSINDEXLIST					IndexList;									//!<インデックスリスト
		MBSMODELINDEXOFFSETLIST			OffsetList;									//!<オフセットリスト
		MofU32							Usage;										//!<インデックス仕様フラグ
		MofU32							Format;										//!<インデックスフォーマット
	
		//----------------------
		////コンストラクタ
		//----------------------
		tag_MBSMODELINDEXLIST() : 
		IndexList() ,
		OffsetList() ,
		Usage(0) ,
		Format(MBSMODEL_INDEXFORMAT16) {
		}
		tag_MBSMODELINDEXLIST(const tag_MBSMODELINDEXLIST& Obj) : 
		IndexList(Obj.IndexList) ,
		OffsetList(Obj.OffsetList) ,
		Usage(Obj.Usage) ,
		Format(Obj.Format) {
		}
		//----------------------
		////デストラクタ
		//----------------------
		virtual ~tag_MBSMODELINDEXLIST(){
			IndexList.Release();
			OffsetList.Release();
		}
	}MBSMODELINDEXLIST,*LPMBSMODELINDEXLIST;
	
	//----------------------------------
	////モデルマテリアル
	//----------------------------------
	typedef MOF_ALIGNED16_STRUCT tag_MBSMATERIAL {
		CString							Name;										//!<名前
		MofS32							Blend;										//!<ブレンディング
		MofS32							RenderProcess;								//!<レンダリングプロセス
		MofS32							RenderTarget;								//!<レンダリングターゲット
		Vector4							Diffuse;									//!<ディフューズ
		Vector4							Ambient;									//!<アンビエント
		Vector4							Specular;									//!<スペキュラー
		Vector4							Emissive;									//!<エミッシブ
		MofFloat						Power;										//!<パワー
		CStringArray					TexNameArray;								//!<テクスチャ名

		MOF_ALIGNED_NEW_OPERATOR(tag_MBSMODELVERTEX);
	}MBSMATERIAL,*LPMBSMATERIAL;
	//リスト置き換え
	typedef CDynamicArray< LPMBSMATERIAL > MBSMATERIALLIST,*LPMBSMATERIALLIST;
	
	//----------------------------------
	////モデルメッシュ
	//----------------------------------
	typedef struct tag_MBSMESH {
		MofU32							No;											//!<配列内番号
		CString							Name;										//!<名前
		MBSMODELVERTEXLIST				VList;										//!<頂点
		MBSMODELINDEXLIST				IList;										//!<インデックス
		MBSMATERIALLIST					MList;										//!<マテリアルリスト
	}MBSMESH,*LPMBSMESH;
	typedef CDynamicArray< LPMBSMESH > MBSMESHLIST,*LPMBSMESHLIST;
	
	//----------------------------------
	////ボーンウェイト
	//----------------------------------
	typedef struct tag_MBSBONEWEIGHT {
		MofU16							MeshID;										//!<メッシュID
		MofU16							ObjectID;									//!<内部ID
		MofU32							VertexIndex;								//!<頂点インデックス
		MofFloat						Weight;										//!<ウェイト
	}MBSBONEWEIGHT,*LPMBSBONEWEIGHT;
	//リスト置き換え
	typedef CDynamicArray< MBSBONEWEIGHT > MBSBONEWEIGHTLIST,*LPMBSBONEWEIGHTLIST;

//!書き出し用サイズ情報
#define		MBS_MODELBONESTATUS_WRITESIZE		(sizeof(MofBool) + sizeof(MofFloat) + sizeof(MofFloat))
#define		MBS_MODELBONEWEIGHTOLD_WRITESIZE	(sizeof(MofU32) + sizeof(MofFloat) + sizeof(MofU16))
#define		MBS_MODELBONEWEIGHT_WRITESIZE		(sizeof(MofU32) + sizeof(MofFloat) + sizeof(MofU16) + sizeof(MofU16))

}

#endif		//__ANALYSMDL__H__

//[EOF]