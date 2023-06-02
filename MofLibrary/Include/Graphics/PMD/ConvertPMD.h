/*****************************************************************************
					
					［ファイル名］	ConvertPMD.h
					［処理概要］	PMDメッシュ変換クラス

															Author 濱田　享
															Since  2009.04.01
*****************************************************************************/

//ONCE
#ifndef		__CONVERTPMDMESH__H__

#define		__CONVERTPMDMESH__H__

//INCLUDE
#include	"ConvertVMD.h"

namespace Mof {

	//TYPEDEF STRUCT

	/*******************************//*!
	@brief	ＰＭＤファイルヘッダー構造体

			ＰＭＤファイルヘッダー構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMDHEADER {
		char							Magic[3];								//!<pmd
		MofFloat						Version;								//!<バージョン
		char							Name[21];								//!<名前
		char							Comment[257];							//!<コメント
		char							EName[21];								//!<名前(英語)
		char							EComment[257];							//!<コメント(コメント)
		MofU32							ExpressionCount;						//!<表情数
		MofU32							BoneFrameCount;							//!<ボーン枠数
	}PMDHEADER,*LPPMDHEADER;
	
	/*******************************//*!
	@brief	ＰＭＤファイル頂点構造体

			ＰＭＤファイル頂点構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMDVERTEX {
		Vector3							Pos;										//!<座標
		Vector3							Normal;										//!<法線
		Vector2							UV;											//!<ＵＶ
		Vector4							Color[4];									//!<色
		MofU8							BlendIndicesCount;							//!<ブレンドボーン数
		MofU8							BlendIndices[2];							//!<ブレンドインデックス
		MofFloat						BlendWait[2];								//!<ブレンドウェイト

		MofU32							Index;										//!<元番号

		MOF_ALIGNED_NEW_OPERATOR(tag_PMDVERTEX);
	}PMDVERTEX, *LPPMDVERTEX;
	//リスト置き換え
	typedef CDynamicArray< PMDVERTEX > PMDVERTEXLIST, *LPPMDVERTEXLIST;
	
	/*******************************//*!
	@brief	ＰＭＤファイル頂点リスト構造体

			ＰＭＤファイル頂点リスト構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMDMESHVERTEX {
		PMDVERTEXLIST					VertexList;									//!<頂点リスト
		MofU32							Flag;										//!<頂点フラグ
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMDMESHVERTEX() :
			VertexList(),
			Flag(0) {
		}
		tag_PMDMESHVERTEX(const tag_PMDMESHVERTEX& Obj) :
			VertexList(Obj.VertexList),
			Flag(Obj.Flag) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PMDMESHVERTEX(){
			VertexList.Release();
		}
	}PMDMESHVERTEX, *LPPMDMESHVERTEX;
	
	/*******************************//*!
	@brief	Xファイルのマテリアルレンダリングオフセット情報構造体

			Xファイルマテリアルレンダリングオフセット情報を読み込むための構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMDMATERIALOFFSET {
		char						Name[256];						//!<名前
		MofU32						Offset;							//!<オフセット
		MofU32						RenderFace;						//!<描画フェイス
		LPPMDVERTEX					pRenderVertex;					//!<描画頂点
		MofU32						RenderVertexCount;				//!<描画頂点数
		LPMofU32					pRenderIndex;					//!<描画インデックス
		MofU32						RenderIndexCount;				//!<描画インデックス数
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PMDMATERIALOFFSET() :
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
		~tag_PMDMATERIALOFFSET(){
			MOF_SAFE_FREE(pRenderVertex, "pRenderVertex");
			MOF_SAFE_FREE(pRenderIndex, "pRenderIndex");
		}
	}PMDMATERIALOFFSET,*LPPMDMATERIALOFFSET;
	typedef CDynamicArray< LPPMDMATERIALOFFSET > PMDMATERIALOFFSETLIST, *LPPMDMATERIALOFFSETLIST;
	
	/*******************************//*!
	@brief	ＰＭＤファイルボーン構造体

			ＰＭＤファイルボーン構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMDBONE {
		char							Name[24];
		Matrix44						GrobalTransform;
		Matrix44						LocalTransform;
		Matrix44						Offset;

		MofS32							BNo;
		MofS32							PNo;
		MofU16							TNo;
		MofU8							Type;
		MofU16							IKNo;
	}PMDBONE, *LPPMDBONE;
	//リスト置き換え
	typedef CDynamicArray< PMDBONE > PMDBONELIST, *LPPMDBONELIST;
	
	/*******************************//*!
	@brief	ＰＭＤファイル剛体構造体

			ＰＭＤファイル剛体構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_PMDRIGID {
		char							Name[24];

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

		MOF_ALIGNED_NEW_OPERATOR(tag_PMDRIGID);
	}PMDRIGID, *LPPMDRIGID;
	//リスト置き換え
	typedef CDynamicArray< PMDRIGID > PMDRIGIDLIST, *LPPMDRIGIDLIST;
	
	/*******************************//*!
	@brief	ＰＭＤファイルモーフィング構造体

			ＰＭＤファイルモーフィング構造体。

	@author	CDW
	*//********************************/
	typedef struct tag_PMDMORPHING {
		char							Name[24];
		MofU32							Count;
		MofU32							Type;
		CU32Array						Index;
		CDynamicArray< Vector3 >		Vertex;
	}PMDMORPHING, *LPPMDMORPHING;
	//リスト置き換え
	typedef CDynamicArray< LPPMDMORPHING > PMDMORPHINGLIST, *LPPMDMORPHINGLIST;

	/*******************************//*!
	@brief	ＰＭＤファイル剛体形状

			ＰＭＤファイル剛体形状。

	@author	CDW
	*//********************************/
	enum tag_PMDRIGIDBODYSHAPE {
		PMDRIGIDBODYSHAPE_SPHERE,												//!<球
		PMDRIGIDBODYSHAPE_BOX,													//!<箱
		PMDRIGIDBODYSHAPE_CAPSULE,												//!<カプセル
	};
	/*******************************//*!
	@brief	ＰＭＤファイル剛体形状

			ＰＭＤファイル剛体形状。

	@author	CDW
	*//********************************/
	enum tag_PMDRIGIDBODYRELATION {
		PMDRIGIDBODYRELATIONTYPE_RELATION,										//!<参照優先
		PMDRIGIDBODYRELATIONTYPE_RIGID,											//!<物理演算
		PMDRIGIDBODYRELATIONTYPE_RELATIONPOSITION,								//!<参照優先（座標のみ）
	};

	//CLASS
	/*******************************//*!
	@brief	ＰＭＤファイル変換

			ＰＭＤファイル変換。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertPMD : public CWriteChunkFile {
	private:
		/*******************//*!
		ファイルヘッダー
		*//********************/
		LPPMDHEADER						m_pHeader;
		/*******************//*!
		読み込みファイル
		*//********************/
		LPReadBinaryFile				m_pFile;
		/*******************//*!
		読み込みファイル
		*//********************/
		LPReadTextFile					m_pMaterialFile;
		/*******************//*!
		モーフィング
		*//********************/
		PMDMORPHINGLIST					m_Morphing;
		
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
		MofBool ConvertVertex(LPPMDMESHVERTEX pVertex);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pIndex		インデックス

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertFace(LPU32Array pIndex);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pVertex		頂点
				@param[in]		pIndex		インデックス
				@param[in]		pMO			マテリアルオフセット

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMaterial(LPPMDMESHVERTEX pVertex, LPU32Array pIndex, LPPMDMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pVertex				頂点
				@param[in]		Flag				フラグ
				
				@return			TRUE				成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertGeometryVertex(LPPMDVERTEX pVertex, MofU32 Flag);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pMorphing	モーフィング
				@param[in]		pVertex		頂点
				@param[in]		pIndex		インデックス
				@param[in]		pMO			マテリアルオフセット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertMorphing(LPPMDMORPHING pMorphing, LPPMDMESHVERTEX pVertex, LPU32Array pIndex, LPPMDMATERIALOFFSET pMO);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pBone		ボーン
				@param[in]		pMO			マテリアルオフセット

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertBone(LPPMDBONELIST pBone, LPPMDMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pBone		ボーン
				@param[in]		pMO			マテリアルオフセット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertWeight(LPPMDBONE pBone, LPPMDMATERIALOFFSETLIST pMO);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pBone		ボーン
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertIK(LPPMDBONELIST pBone);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertExpression(void);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertExpressionViewList(void);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertBoneFrameList(void);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertBoneViewList(void);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pBone		ボーン
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertEnglishName(LPPMDBONELIST pBone);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertToonTexture(void);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pBone		ボーン
				@param[in]		pRigid		剛体
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertRigidBody(LPPMDBONELIST pBone, LPPMDRIGIDLIST pRigid);
		/*************************************************************************//*!
				@brief			メッシュファイルを変換する
				@param[in]		pRigid		剛体
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool ConvertJoint(LPPMDRIGIDLIST pRigid);

		/*************************************************************************//*!
				@brief			ヘッダー読み込み
				@param[in]		pData			読み込みヘッダ－

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool ReadHeader(LPPMDHEADER pData);
		/*************************************************************************//*!
				@brief			モーフィング読み込み
				@param			None

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool ReadMorphing(void);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertPMD();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertPMD();
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
		MOF_LIBRARYCLASS_NOTCOPY(CConvertPMD, MOF_CONVERTPMDCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertPMD.inl"

}

#endif	//__CONVERTPMDMESH__H__

//[EOF]