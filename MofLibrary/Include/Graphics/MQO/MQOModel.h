/*************************************************************************//*!
					
					@file	MQOModel.h
					@brief	MQOファイルモデルクラス。

															@author	CDW
															@date	2015.12.14
*//**************************************************************************/

//ONCE
#ifndef		__MQOMODEL__H__

#define		__MQOMODEL__H__

//INCLUDE
#include	"../../Common/KeyFrameArray.h"
#include	"../GraphicsCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MQOファイルのマテリアル構造体

			MQOファイルのマテリアル構造体

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFMQOMATERIAL {
		CString		Name;					//<!材質名
		MofBool		VCol;					//<!頂点カラー
		Vector4		Color;					//<!色
		MofFloat	Diffuse;				//<!拡散光
		Vector3		Ambient;				//<!周囲光
		Vector3		Emissive;				//<!自己照明
		Vector3		Speculer;				//<!反射光
		MofFloat	Power;					//<!反射光の強さ
		CString		Texture;				//<!模様マッピング名
		CString		AlphaTex;				//<!透明マッピング名
		CString		BumpTex;				//<!凹凸マッピング名
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOMATERIAL():
			Name("") ,
			VCol(FALSE) ,
			Color(1,1,1,1) ,
			Diffuse(0.8f) ,
			Ambient(0.6f,0.6f,0.6f) ,
			Emissive(0,0,0) ,
			Speculer(0,0,0) ,
			Power(5) ,
			Texture("") ,
			AlphaTex("") ,
			BumpTex("") {
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFMQOMATERIAL);
	}MOFMQOMATERIAL,*LPMOFMQOMATERIAL;
	typedef CDynamicArray<LPMOFMQOMATERIAL> MOFMQOMATERIALARRAY,*LPMOFMQOMATERIALARRAY;
	
	/*******************************//*!
	@brief	MQOファイルの面頂点構造体

			MQOファイルの面を構成する頂点の構造体

	@author	CDW
	*//********************************/
	typedef struct tag_MOFMQOFACEVERTEX {
		MofU32		Index;					//<!頂点インデックス
		Vector2		UV;						//<!UV値
		MofU32		Color;					//<!頂点カラー

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOFACEVERTEX() :
			Index() ,
			UV(0,0) ,
			Color(0xFFFFFFFF) {
		}
	}MOFMQOFACEVERTEX,*LPMOFMQOFACEVERTEX;
	
	/*******************************//*!
	@brief	MQOファイルの面構造体

			MQOファイルの面構造体

	@author	CDW
	*//********************************/
	typedef struct tag_MOFMQOFACE {
		MofU32				VertCount;		//<!頂点数
		LPMOFMQOFACEVERTEX	pVertices;		//<!頂点配列
		MofU32				Material;		//<!材質インデックス

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOFACE() :
			VertCount(0) ,
			pVertices(NULL) ,
			Material(0) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFMQOFACE(){
			MOF_SAFE_DELETE_ARRAY(pVertices);
		}
	}MOFMQOFACE,*LPMOFMQOFACE;
	
	/*******************************//*!
	@brief	MQOファイルのオブジェクト構造体

			MQOファイルのオブジェクト構造体

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFMQOOBJECT {
		CString			Name;				//<!オブジェクト名
		MofU32			Depth;				//<!階層の深さ
		Vector3			Scale;				//<!ローカル座標の拡大率
		Vector3			Rotation;			//<!ローカル座標の回転角
		Vector3			Translation;		//<!ローカル座標の平行移動量
		MofU32			Visible;			//<!表示・非表示
		MofU32			Shading;			//<!シェーディング
		MofFloat		Facet;				//<!スムージング角度
		MofU32			Mirror;				//<!鏡面のタイプ
		MofU32			MirrorAxis;			//<!鏡面の適用軸
		MofFloat		MirrorDistance;		//<!接続距離
		MofU32			VertCount;			//<!頂点数
		Vector3*		pVertices;			//<!頂点配列
		MofU32			FaceCount;			//<!面数
		LPMOFMQOFACE	pFaces;				//<!面配列
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOOBJECT():
			Name("") ,
			Depth(0) ,
			Scale(1,1,1) ,
			Rotation(0,0,0) ,
			Translation(0,0,0) ,
			Visible(15) ,
			Shading(0) ,
			Facet(59.5f) ,
			Mirror(0) ,
			MirrorAxis(0) ,
			MirrorDistance(-1) ,
			VertCount(0) ,
			pVertices(NULL) ,
			FaceCount(0) ,
			pFaces(NULL){
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFMQOOBJECT(){
			MOF_SAFE_DELETE_ARRAY(pVertices);
			MOF_SAFE_DELETE_ARRAY(pFaces);
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFMQOOBJECT);
	}MOFMQOOBJECT,*LPMOFMQOOBJECT;
	typedef CDynamicArray<LPMOFMQOOBJECT> MOFMQOOBJECTARRAY,*LPMOFMQOOBJECTARRAY;
	
	/*******************************//*!
	@brief	MQOファイルの頂点変換用中間データ構造体

			MQOファイルから頂点を変換する際の中間データ構造体

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFMQOTEMPVERTEX {
		Vector3		Pos;					//<!座標
		Vector3		Normal;					//<!法線
		Vector2		UV;						//<!UV
		MofU32		Color;					//<!頂点カラー

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOTEMPVERTEX():
			Pos(0,0,0) ,
			Normal(0,0,0) ,
			UV(0,0) ,
			Color(0xffffffff) {
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFMQOTEMPVERTEX);
	}MOFMQOTEMPVERTEX,*LPMOFMQOTEMPVERTEX;
	typedef const MOFMQOTEMPVERTEX* LPCMOFMQOTEMPVERTEX;
	typedef CDynamicArray<LPMOFMQOTEMPVERTEX> MOFMQOTEMPVERTEXARRAY,*LPMOFMQOTEMPVERTEXARRAY;

	/*******************************//*!
	@brief	MQOファイルの面変換用中間データ構造体

			MQOファイルから面を変換する際の中間データ構造体

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOFMQOTEMPFACE {
		MofU32				VertCount;		//<!頂点数
		LPMOFMQOTEMPVERTEX	pVertices;		//<!頂点配列
		Vector3				AvgNormal;		//<!平均法線
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFMQOTEMPFACE() :
			VertCount(0) ,
			pVertices(NULL) ,
			AvgNormal(0,0,0) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFMQOTEMPFACE(){
			MOF_SAFE_DELETE_ARRAY(pVertices);
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOFMQOTEMPFACE);
	}MOFMQOTEMPFACE,*LPMOFMQOTEMPFACE;
	typedef CDynamicArray<LPMOFMQOTEMPFACE> MOFMQOTEMPGEOMETRY,*LPMOFMQOTEMPGEOMETRY;
	typedef CDynamicArray<LPMOFMQOTEMPGEOMETRY> MOFMQOTEMPGEOMETRYARRAY,*LPMOFMQOTEMPGEOMETRYARRAY;

	/*******************************//*!
	@brief	MQOファイルモデルクラス

			MQOファイルから変換するために情報を保存するためのクラス。
			MQOファイルから直接でのレンダリング機能などは提供しない。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMQOModel : public IMofNamedObject {
	private:
		/*******************//*!
		ファイル名
		*//********************/
		CString						m_Name;
		/*******************//*!
		マテリアル配列
		*//********************/
		MOFMQOMATERIALARRAY			m_Materials;
		/*******************//*!
		オブジェクト配列
		*//********************/
		MOFMQOOBJECTARRAY			m_Objects;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CMQOModel();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CMQOModel();
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CMQOModel::Release(LPMofVoid pData = NULL);
		
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
				@brief			マテリアル配列取得
				@param			None

				@return			マテリアル配列の取得
		*//**************************************************************************/
		virtual LPMOFMQOMATERIALARRAY GetMaterials(void);
		/*************************************************************************//*!
				@brief			オブジェクト配列取得
				@param			None

				@return			オブジェクト配列の取得
		*//**************************************************************************/
		virtual LPMOFMQOOBJECTARRAY GetObjects(void);
		/*************************************************************************//*!
				@brief			オブジェクト内で使われてるマテリアルのインデックス一覧取得
				@param[in]		index		対象オブジェクトのインデックス
				@param[out]		out			インデックスの出力配列

				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool GetObjectMaterialList(MofU32 index,CDynamicArray<MofU32>& out);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CMQOModel,MOF_MQOMODELCLASS_ID);
	};
	
	//TYPEDEF
	typedef CMQOModel* LPMQOModel;

	//INLINE INCLUDE
	#include	"MQOModel.inl"
}

#endif	//__MQOMODEL__H__

//[EOF]
