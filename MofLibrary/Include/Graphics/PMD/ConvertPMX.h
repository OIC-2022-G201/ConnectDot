/*****************************************************************************
					
					［ファイル名］	ConvertPMX.h
					［処理概要］	PMXメッシュ変換クラス
					
															@author	CDW
															Since  2009.04.01
*****************************************************************************/

//ONCE
#ifndef		__CONVERTPMXMESH__H__

#define		__CONVERTPMXMESH__H__

//INCLUDE
#include	"ConvertVMD.h"

namespace Mof {

	//TYPEDEF STRUCT

	/*******************************//*!
	@brief	ＰＭＸファイルヘッダー構造体

			ＰＭＸファイルヘッダー構造体。

	@author	CDW
	*//********************************/
	typedef MOFLIBRARY_API struct tag_PMXHEADER {
		char							Magic[4];								//!<pmx
		MofFloat						Version;								//!<バージョン
		MofU8							FlagSize;								//!<フラグサイズ
		LPMofU8							Flag;									//!<フラグ
		char*							pModelNameJ;							//!<モデル名
		char*							pModelNameE;							//!<モデル名
		char*							pCommentJ;								//!<モデル名
		char*							pCommentE;								//!<モデル名
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMXHEADER()
		: Version(0.0f)
		, FlagSize(0)
		, Flag(NULL)
		, pModelNameJ(NULL)
		, pModelNameE(NULL)
		, pCommentJ(NULL)
		, pCommentE(NULL) {
			memset(Magic, 0, 4);
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PMXHEADER() {
			Release();
		}
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool Release(LPMofVoid pData = NULL){
			MOF_SAFE_FREE(Flag, "PMXHEADER Release");
			MOF_SAFE_FREE(pModelNameJ, "PMXHEADER Release");
			MOF_SAFE_FREE(pModelNameE, "PMXHEADER Release");
			MOF_SAFE_FREE(pCommentJ, "PMXHEADER Release");
			MOF_SAFE_FREE(pCommentE, "PMXHEADER Release");
			return TRUE;
		}
	}PMXHEADER, *LPPMXHEADER;
	
	/*******************************//*!
	@brief	ＰＭＸファイル頂点構造体

			ＰＭＸファイル頂点構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMXVERTEX {
		Vector3							Pos;										//!<座標
		Vector3							Normal;										//!<法線
		Vector2							UV;											//!<ＵＶ
		Vector4							Color[4];									//!<色
		MofU8							BlendIndicesCount;							//!<ブレンドボーン数
		MofU8							BlendIndices[4];							//!<ブレンドインデックス
		MofFloat						BlendWait[4];								//!<ブレンドウェイト

		MofU32							Index;										//!<インデックス

		MOF_ALIGNED_NEW_OPERATOR(tag_PMXVERTEX);
	}PMXVERTEX, *LPPMXVERTEX;
	//リスト置き換え
	typedef CDynamicArray< PMXVERTEX > PMXVERTEXLIST, *LPPMXVERTEXLIST;
	
	/*******************************//*!
	@brief	ＰＭＸファイル頂点リスト構造体

			ＰＭＸファイル頂点リスト構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMXMESHVERTEX {
		PMXVERTEXLIST					VertexList;									//!<頂点リスト
		MofU32							Flag;										//!<頂点フラグ
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMXMESHVERTEX() :
			VertexList(),
			Flag(0) {
		}
		tag_PMXMESHVERTEX(const tag_PMXMESHVERTEX& Obj) :
			VertexList(Obj.VertexList),
			Flag(Obj.Flag) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PMXMESHVERTEX(){
			VertexList.Release();
		}
	}PMXMESHVERTEX, *LPPMXMESHVERTEX;
	
	/*******************************//*!
	@brief	Xファイルのマテリアルレンダリングオフセット情報構造体

			Xファイルマテリアルレンダリングオフセット情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMXMATERIALOFFSET {
		char						Name[256];						//!<名前
		MofU32						Offset;							//!<オフセット
		MofU32						RenderFace;						//!<描画フェイス
		LPPMXVERTEX					pRenderVertex;					//!<描画頂点
		MofU32						RenderVertexCount;				//!<描画頂点数
		LPMofU32					pRenderIndex;					//!<描画インデックス
		MofU32						RenderIndexCount;				//!<描画インデックス数
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMXMATERIALOFFSET() :
		Offset(0) ,
		RenderFace(0) ,
		pRenderVertex(NULL) ,
		RenderVertexCount(0) ,
		pRenderIndex(NULL) ,
		RenderIndexCount(0) {
			memset(Name, 0, sizeof(Name));
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_PMXMATERIALOFFSET(){
			MOF_SAFE_FREE(pRenderVertex, "pRenderVertex");
			MOF_SAFE_FREE(pRenderIndex, "pRenderIndex");
		}
	}PMXMATERIALOFFSET,*LPPMXMATERIALOFFSET;
	typedef CDynamicArray< LPPMXMATERIALOFFSET > PMXMATERIALOFFSETLIST, *LPPMXMATERIALOFFSETLIST;
	
	/*******************************//*!
	@brief	ＰＭＸファイルＩＫ構造体

			ＰＭＸファイルＩＫ構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMXIKJOINT {
		MofS32							BoneID;
		Vector3							MinRestriction;
		Vector3							MaxRestriction;

		MOF_ALIGNED_NEW_OPERATOR(tag_PMXIKJOINT);
	}PMXIKJOINT,*LPPMXIKJOINT;
	typedef CDynamicArray< PMXIKJOINT > PMXIKJOINTLIST, *LPPMXIKJOINTLIST;

	/*******************************//*!
	@brief	ＰＭＸファイルＩＫ構造体

			ＰＭＸファイルＩＫ構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMXIK {
		MofS32							BoneID;
		MofS32							Iteration;
		MofFloat						Restriction;
		PMXIKJOINTLIST					Joint;
	}PMXIK,*LPPMXIK;

	/*******************************//*!
	@brief	ＰＭＸファイルボーン構造体

			ＰＭＸファイルボーン構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMXBONE {
		char							Name[256];
		Matrix44						GrobalTransform;
		Matrix44						LocalTransform;
		Matrix44						Offset;

		MofS32							BNo;
		MofS32							PNo;
		MofS32							MNo;
		MofU16							Flag;

		LPPMXIK							pIK;
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMXBONE() :
		GrobalTransform() ,
		LocalTransform() ,
		Offset() ,
		BNo(0) ,
		PNo(0) ,
		MNo(0) ,
		Flag(0) ,
		pIK(NULL) {
			memset(Name, 0, sizeof(Name));
		}
	}PMXBONE, *LPPMXBONE;
	//リスト置き換え
	typedef CDynamicArray< PMXBONE > PMXBONELIST, *LPPMXBONELIST;
	
	/*******************************//*!
	@brief	ＰＭＸファイル剛体構造体

			ＰＭＸファイル剛体構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMXRIGID {
		char							Name[256];

		Vector3							Size;
		Vector3							Pos;
		Vector3							Angle;

		MofU32							BNo;
		MofU32							GNo;
		MofU32							GTNo;

		MofU32							Type;
		MofU32							PType;

		MofFloat						Mass;
		MofFloat						LinearDamping;
		MofFloat						AngularDamping;
		MofFloat						Restitution;
		MofFloat						Friction;

		MOF_ALIGNED_NEW_OPERATOR(tag_PMXRIGID);
	}PMXRIGID, *LPPMXRIGID;
	//リスト置き換え
	typedef CDynamicArray< PMXRIGID > PMXRIGIDLIST, *LPPMXRIGIDLIST;

	/*******************************//*!
	@brief	ＰＭＸファイルモーフィング構造体

			ＰＭＸファイルモーフィング構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMXMORPHING {
		char							Name[256];
		MofU32							Count;
		MofU32							Type;
		CU32Array						Index;
		CDynamicArray< Vector3 >		Vertex;
	}PMXMORPHING, *LPPMXMORPHING;
	//リスト置き換え
	typedef CDynamicArray< LPPMXMORPHING > PMXMORPHINGLIST, *LPPMXMORPHINGLIST;
	
	//ENUM
	
	/*******************************//*!
	@brief	ヘッダーフラグ配置

	@author	CDW
	*//********************************/
	enum tag_PMXHEADERFLAG {
		PMX_HEADERFLAG_ENCODING,												//!<エンコード
		PMX_HEADERFLAG_UVCOUNT,													//!<追加UV数
		PMX_HEADERFLAG_VERTEXINDEXSIZE,											//!<頂点インデックスサイズ
		PMX_HEADERFLAG_TEXTUREINDEXSIZE,										//!<テクスチャインデックスサイズ
		PMX_HEADERFLAG_MATERIALINDEXSIZE,										//!<マテリアルインデックスサイズ
		PMX_HEADERFLAG_BONEINDEXSIZE,											//!<ボーンインデックスサイズ
		PMX_HEADERFLAG_MORPHINGINDEXSIZE,										//!<モーフインデックスサイズ
		PMX_HEADERFLAG_RIGIDBODYINDEXSIZE,										//!<剛体インデックスサイズ

		PMX_HEADERFLAG_MAX,														//!<最大数
	};
	
	/*******************************//*!
	@brief	ボーンウェイト方式

	@author	CDW
	*//********************************/
	enum tag_PMXWAITTYPE {
		PMX_WAITTYPE_BDEF1,														//!<BDEF1
		PMX_WAITTYPE_BDEF2,														//!<BDEF2
		PMX_WAITTYPE_BDEF4,														//!<BDEF4
		PMX_WAITTYPE_SDEF,														//!<SDEF
		PMX_WAITTYPE_QDEF,														//!<QDEF

		PMX_WAITTYPE_MAX,														//!<最大数
	};

	/*******************************//*!
	@brief	ボーンフラグ

	@author	CDW
	*//********************************/
	enum tag_PMXBONEFLAG {
		PMX_BONEFLAG_CONNECT							=				0x0001,	//!<接続
		PMX_BONEFLAG_ROTATIONENABLE						=				0x0002,	//!<回転可能
		PMX_BONEFLAG_TRANSLATIONENABLE					=				0x0004,	//!<移動可能
		PMX_BONEFLAG_VISIBLE							=				0x0008,	//!<表示
		PMX_BONEFLAG_ACTIONENABLE						=				0x0010,	//!<操作可
		PMX_BONEFLAG_IKENABLE							=				0x0020,	//!<IK
		PMX_BONEFLAG_ROTATIONEFFECT						=				0x0100,	//!<回転付与
		PMX_BONEFLAG_TRANSLATIONEFFECT					=				0x0200,	//!<移動付与
		PMX_BONEFLAG_AXISFIXED							=				0x0400,	//!<軸固定
		PMX_BONEFLAG_AXISLOCAL							=				0x0800,	//!<ローカル軸
		PMX_BONEFLAG_PHYSICSMORPHING					=				0x1000,	//!<物理後変形
		PMX_BONEFLAG_PARENTMORPHING						=				0x2000,	//!<外部親変形

		PMX_BONEFLAG_MAX								=				0x3FFF,	//!<最大数
	};

	/*******************************//*!
	@brief	モーフィングタイプ

	@author	CDW
	*//********************************/
	enum tag_PMXMORPHINGTYPE {
		PMX_MORPHINGTYPE_GROUP,													//!<グループ
		PMX_MORPHINGTYPE_VERTEX,												//!<頂点
		PMX_MORPHINGTYPE_BONE,													//!<ボーン
		PMX_MORPHINGTYPE_UV,													//!<ＵＶ
		PMX_MORPHINGTYPE_APPENDUV1,												//!<追加ＵＶ
		PMX_MORPHINGTYPE_APPENDUV2,												//!<追加ＵＶ
		PMX_MORPHINGTYPE_APPENDUV3,												//!<追加ＵＶ
		PMX_MORPHINGTYPE_APPENDUV4,												//!<追加ＵＶ
		PMX_MORPHINGTYPE_MATERIAL,												//!<材質
		PMX_MORPHINGTYPE_FLIP,													//!<フリップ
		PMX_MORPHINGTYPE_IMPULSE,												//!<インパルス

		PMX_MORPHINGTYPE_MAX,													//!<最大数
	};

	/*******************************//*!
	@brief	モーフィングタイプ

	@author	CDW
	*//********************************/
	enum tag_PMXVIEWTYPE {
		PMX_VIEWTYPE_BONE,														//!<ボーン
		PMX_VIEWTYPE_MORPHING,													//!<モーフィング

		PMX_VIEWTYPE_MAX,														//!<最大数
	};
	
	/*******************************//*!
	@brief	ＰＭＸファイル剛体形状

			ＰＭＸファイル剛体形状。

	@author	CDW
	*//********************************/
	enum tag_PMXRIGIDBODYSHAPE {
		PMXRIGIDBODYSHAPE_SPHERE,												//!<球
		PMXRIGIDBODYSHAPE_BOX,													//!<箱
		PMXRIGIDBODYSHAPE_CAPSULE,												//!<カプセル
	};
	/*******************************//*!
	@brief	ＰＭＸファイル剛体形状

			ＰＭＸファイル剛体形状。

	@author	CDW
	*//********************************/
	enum tag_PMXRIGIDBODYRELATION {
		PMXRIGIDBODYRELATIONTYPE_RELATION,										//!<参照優先
		PMXRIGIDBODYRELATIONTYPE_RIGID,											//!<物理演算
		PMXRIGIDBODYRELATIONTYPE_RELATIONPOSITION,								//!<参照優先（座標のみ）
	};
	/*******************************//*!
	@brief	ジョイントタイプ

	@author	CDW
	*//********************************/
	enum tag_PMXJOINTTYPE {
		PMX_JOINTTYPE_SPRING6DOF,												//!<6DOF
		PMX_JOINTTYPE_6DOF,														//!<6DOF
		PMX_JOINTTYPE_P2P,														//!<P2P
		PMX_JOINTTYPE_CONETWIST,												//!<コーンツイスト
		PMX_JOINTTYPE_SLIDER,													//!<スライダー
		PMX_JOINTTYPE_HINGE,													//!<ヒンジ

		PMX_JOINTTYPE_MAX,														//!<最大数
	};

	//CLASS
	
	/*******************************//*!
	@brief	ＰＭＸファイル変換

			ＰＭＸファイル変換。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertPMX : public CWriteChunkFile {
	private:
		/*******************//*!
		ファイルヘッダー
		*//********************/
		LPPMXHEADER						m_pHeader;
		/*******************//*!
		読み込みファイル
		*//********************/
		LPReadBinaryFile				m_pFile;
		/*******************//*!
		モーフィング
		*//********************/
		PMXMORPHINGLIST					m_Morphing;
		
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(void);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pVertex		頂点

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertVertex(LPPMXMESHVERTEX pVertex);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pIndex		インデックス

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertFace(LPU32Array pIndex);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pTexture	テクスチャ

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertTexture(LPStringArray pTexture);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pVertex		頂点
				@param[in]		pIndex		インデックス
				@param[in]		pTexture	テクスチャ
				@param[in]		pMO			マテリアルオフセット

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMaterial(LPPMXMESHVERTEX pVertex,LPU32Array pIndex,LPStringArray pTexture, LPPMXMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pVertex				頂点
				@param[in]		Flag				フラグ
				
				@return			TRUE				成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertGeometryVertex(LPPMXVERTEX pVertex, MofU32 Flag);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pMorphing	モーフィング
				@param[in]		pVertex		頂点
				@param[in]		pIndex		インデックス
				@param[in]		pMO			マテリアルオフセット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMorphing(LPPMXMORPHING pMorphing, LPPMXMESHVERTEX pVertex, LPU32Array pIndex, LPPMXMATERIALOFFSET pMO);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pBone		ボーン
				@param[in]		pMO			マテリアルオフセット

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertBone(LPPMXBONELIST pBone, LPPMXMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pBone		ボーン
				@param[in]		pMO			マテリアルオフセット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertWeight(LPPMXBONE pBone, LPPMXMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMorphing(void);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertView(void);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pBone		ボーン
				@param[in]		pRigid		剛体
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertRigidBody(LPPMXBONELIST pBone, LPPMXRIGIDLIST pRigid);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pRigid		剛体
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertJoint(LPPMXRIGIDLIST pRigid);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertSoftBody(void);

		/*************************************************************************//*!
				@brief			ヘッダー読み込み
				@param[in]		pData			読み込みヘッダ－

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool ReadHeader(LPPMXHEADER pData);
		/*************************************************************************//*!
				@brief			インデックス読み込み
				@param[in]		Size			サイズ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofS32 ReadIndex(MofU8 Size);
		/*************************************************************************//*!
				@brief			インデックス読み込み
				@param[in]		Size			サイズ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofU32 ReadIndexU(MofU8 Size);
		/*************************************************************************//*!
				@brief			文字列読み込み
				@param[in]		Enc				エンコード

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		char* ReadStringEncode(MofU8 Enc);
		/*************************************************************************//*!
				@brief			モーフィング読み込み
				@param			None

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool ReadMorphing(void);
		/*************************************************************************//*!
				@brief			文字列読み飛ばし
				@param[in]		Enc				エンコード

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool SkipStringEncode(MofU8 Enc);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertPMX();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertPMX();
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行い、独自形式で出力を行う
				@param[in]		pInName		入力ファイル名
				@param[in]		pOutName	出力ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPCMofChar pOutName);
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CConvertPMX, MOF_CONVERTPMXCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertPMX.inl"

}

#endif	//__CONVERTPMXMESH__H__

//[EOF]