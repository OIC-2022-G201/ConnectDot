/*************************************************************************//*!
					
					@file	MomCommon.h
					@brief	独自形式モデルファイル関連の基本定義を行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MOMCOMMON__H__

#define		__MOMCOMMON__H__

//INCLUDE
#include	"GraphicsCommon.h"
#include	"../Common/PackFile.h"
#include	"../Common/WriteChunkFile.h"
#include	"../Common/KeyFrameArray.h"

//DEFINE

//!独自ファイルヘッダー
#define		MOFMODEL_FILE_HEADER				"MOF MODEL VER 0.01 FILE"

//!独自ファイルヘッダー長
#define		MOFMODEL_FILE_HEADERLEN				strlen(MOFMODEL_FILE_HEADER)

//!独自ファイルフッター
#define		MOFMODEL_FILE_FOOTER				"EOF"

//!独自ファイルフッター長
#define		MOFMODEL_FILE_FOOTERLEN				strlen(MOFMODEL_FILE_FOOTER)

namespace Mof {
	
	/*******************************//*!
	@brief	モデルファイルテンプレート列挙

			MOMファイル内に定義されるチャンクの情報タイプを列挙

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_TEMPLATE {
		MOFMODEL_TEMP_MESH					=		0x00001000,						//!<メッシュ
		MOFMODEL_TEMP_GEOMETRY,														//!<ジオメトリ
		MOFMODEL_TEMP_VERTEX,														//!<頂点情報
		MOFMODEL_TEMP_INDEX,														//!<インデックス情報
		MOFMODEL_TEMP_MATERIAL,														//!<マテリアル情報
		MOFMODEL_TEMP_TEXTURE,														//!<テクスチャ情報
		MOFMODEL_TEMP_SHADER,														//!<シェーダー情報
		MOFMODEL_TEMP_MATRIX,														//!<変換行列情報
		MOFMODEL_TEMP_GEOMETRYMORPHING,												//!<モーフィング情報

		MOFMODEL_TEMP_BONE					=		0x00002000,						//!<ボーン情報
		MOFMODEL_TEMP_BONEPARAMETER,												//!<ボーンパラメーター情報
		MOFMODEL_TEMP_BONEWEIGHT,													//!<ボーンウェイト情報
		MOFMODEL_TEMP_BONEGROUP,													//!<ボーングループ情報

		MOFMODEL_TEMP_ANIMATIONSET			=		0x00003000,						//!<アニメーション情報
		MOFMODEL_TEMP_ANIMATION,													//!<アニメーション情報
		MOFMODEL_TEMP_ANIMATIONKEY,													//!<アニメーション情報
		MOFMODEL_TEMP_MORPHING,														//!<アニメーション情報

		MOFMODEL_TEMP_ANIMATION2,													//!<アニメーション情報(Ver2)

		MOFMODEL_TEMP_BLOCK					=		0x00004000,						//!<ブロック情報

		MOFMODEL_TEMP_LODMODEL				=		0x00005000,						//!<距離減衰モデル情報

		MOFMODEL_TEMP_IK					=		0x00006000,						//!<IK情報
		MOFMODEL_TEMP_IKJOINT,														//!<IK接続情報

		MOFMODEL_TEMP_RIGID					=		0x00007000,						//!<剛体情報
		MOFMODEL_TEMP_RIGIDJOINT,													//!<剛体接続情報

		MOFMODEL_TEMP_SCENE					=		0x00010000,						//!<シーン
		MOFMODEL_TEMP_CAMERA,														//!<カメラ
		MOFMODEL_TEMP_CAMERAANIMATION,												//!<アニメーション情報
		MOFMODEL_TEMP_LIGHT,														//!<ライト

		MOFMODEL_TEMP_MAX,															//!<チャンク最大数
	};
	
	/*******************************//*!
	@brief	モデルファイルキータイプ列挙

			MOMファイル内に定義されるアニメーションのキータイプを列挙

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_ANIMATIONKEYTYPE {
		MOFMODEL_ANIMATIONKEY_TRANSLATION,
		MOFMODEL_ANIMATIONKEY_SCALING,
		MOFMODEL_ANIMATIONKEY_ROTATION,
		MOFMODEL_ANIMATIONKEY_FLOTPARAMETER,
		MOFMODEL_ANIMATIONKEY_TARGET,
		MOFMODEL_ANIMATIONKEY_UPVECTOR,
		MOFMODEL_ANIMATIONKEY_CAMERAFOV,
	};

	
	/*******************************//*!
	@brief	モデルファイルキーフラグ列挙

			MOMファイル内に定義されるアニメーションのキーフラグを列挙

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_ANIMATIONKEYFLAG {
		MOFMODEL_ANIMATIONKEYFLAG_RELATIVE	=		0x80000000,
	};

	/*******************************//*!
	@brief	モデルファイルアニメーションフラグ列挙

			MOMファイル内に定義されるアニメーションのフラグを列挙

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_ANIMATIONFLAG {
		MOFMODEL_ANIMATIONFLAG_GROBAL		=		0x00000001,
	};

	/*******************************//*!
	@brief	モデルファイル解析エラー列挙

			モデルファイル解析時に発生するエラーを列挙

	@author	CDW
	*//********************************/
	enum tag_MOFMODEL_RESULT {
		MOFMODEL_RESULTERROR_UNKNOWN		=		0,								//!<よくわからないエラー

		MOFMODEL_RESULT_SUCCEEDED			=		TRUE,							//!<正常終了

		MOFMODEL_RESULTERROR_OPENERROR,												//!<ファイルを開けなかった
		MOFMODEL_RESULTERROR_NOTMOMFILE,											//!<ファイルがMOM形式じゃない

		MOFMODEL_RESULTERROR_CHUNKSIZE,												//!<チャンクサイズがおかしい
		MOFMODEL_RESULTERROR_UNKNOWNCHUNK,											//!<チャンクが変な位置に存在する
		MOFMODEL_RESULTERROR_CHUNKENDFAULT,											//!<チャンク終了が見つからない
		MOFMODEL_RESULTERROR_UNKNOWNCHUNKEND,										//!<チャンク終了が変な位置に存在する

		MOFMODEL_RESULTERROR_NOTFOOTER,												//!<フッターでなく最大サイズを超える
		MOFMODEL_RESULTERROR_UNKNOWNFOOTER,											//!<フッターが変な位置に存在する
		
		MOFMODEL_RESULTERROR_VERTEXBUFFERCREATE,									//!<バッファの生成失敗
		MOFMODEL_RESULTERROR_INDEXBUFFERCREATE,										//!<バッファの生成失敗
		MOFMODEL_RESULTERROR_TEXTURELOAD,											//!<テクスチャの読み込み失敗

		MOFMODEL_RESULTERROR_BONENOTFOUND,											//!<対応するボーンの検索に失敗
		MOFMODEL_RESULTERROR_NOTMORPHINGTYPE,										//!<対応するモーフィングタイプがない
	};

	/*******************************//*!
	@brief	モデルファイルヘッダー構造体

			モデルファイルの基本情報を格納したヘッダー構造体

	@author	CDW
	*//********************************/
	typedef struct tag_MOFMODELHEADER {
		MofBool						bStringCode;									//!<文字コード(UNICODE形式ならTRUE,マルチバイトならFALSE)
		MofU32						Alignment;										//!<アライメント
		MofU32						BlockSize;										//!<ブロックサイズ
		MofU32						Flag;											//!<ファイル情報追加フラグ
	}MOFMODELHEADER,*LPMOFMODELHEADER;
	
	/*******************************//*!
	@brief	ジオメトリモーフィング列挙

			ジオメトリモーフィング列挙

	@author	CDW
	*//********************************/
	typedef enum tag_MOMGEOMETRYMORPHINGTYPE {
		MOMGEOMETRYMORPHINGTYPE_VERTEXPOSITION,										//!<頂点座標
	}GeometryMorphingType;
	
	/*******************************//*!
	@brief	ジオメトリモーフィング頂点座標

			ジオメトリモーフィング頂点座標

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOMGEOMETRYMORPHINGPOSITION {
		MofU32						Index;											//!<インデックス
		Vector3						Position;										//!<頂点座標

		MOF_ALIGNED_NEW_OPERATOR(tag_MOMGEOMETRYMORPHINGPOSITION);
	}MOMGEOMETRYMORPHINGPOSITION;
	typedef CDynamicArray< MOMGEOMETRYMORPHINGPOSITION >		CGeometryMorphingPositionArray, *LPGeometryMorphingPositionArray;
	
	/*******************************//*!
	@brief	プロジェクション情報構造体

			プロジェクション行列の設定に必要な情報を格納する構造体

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOMCAMERAINFO {
		CVector3					Position;			//!<座標
		CVector3					Target;				//!<注視点
		CVector3					Up;					//!<上方ベクトル
		MofFloat					Fov;				//!<視野角
		MofFloat					Aspect;				//!<アスペクト比
		MofFloat					Width;				//!<幅
		MofFloat					Height;				//!<高さ
		MofFloat					Near;				//!<近平面
		MofFloat					Far;				//!<遠平面

		MOF_ALIGNED_NEW_OPERATOR(tag_MOMCAMERAINFO);
	}MOMCAMERAINFO,*LPMOMCAMERAINFO;

	/*******************************//*!
	@brief	剛体ジオメトリ列挙

			剛体ジオメトリ列挙

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSGEOMETRYTYPE {
		MOMPHYSICSGEOMETRYTYPE_SPHERE,												//!<球
		MOMPHYSICSGEOMETRYTYPE_BOX,													//!<箱
		MOMPHYSICSGEOMETRYTYPE_CAPSULE,												//!<カプセル
	}PhysicsGeometryType;

	/*******************************//*!
	@brief	剛体ジョイント列挙

			剛体ジョイント列挙

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSJOINTTYPE {
		MOMPHYSICSJOINTTYPE_6DOF,													//!<6DOF
	}PhysicsJointType;

	/*******************************//*!
	@brief	剛体状態フラグ列挙

			剛体動作状態フラグ列挙

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSBONEFLAG {
		MOMPHYSICSBONEFLAG_FIXED,													//!<ボーン状態での固定
		MOMPHYSICSBONEFLAG_FIXEDPOSITION,											//!<ボーン状態での固定(座標のみ)
		MOMPHYSICSBONEFLAG_ACTOR,													//!<アクター状態優先
		MOMPHYSICSBONEFLAG_INTERPOLATION,											//!<補間中
	}PhysicsBoneFlag;

	/*******************************//*!
	@brief	ジョイント動作フラグ列挙

			ジョイント動作フラグ列挙

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSJOINTAXIS {
		MOMPHYSICSJOINTAXIS_X,														//!<X
		MOMPHYSICSJOINTAXIS_Y,														//!<Y
		MOMPHYSICSJOINTAXIS_Z,														//!<Z
		MOMPHYSICSJOINTAXIS_TWIST,													//!<X
		MOMPHYSICSJOINTAXIS_SWING1,													//!<Y
		MOMPHYSICSJOINTAXIS_SWING2,													//!<Z
		MOMPHYSICSJOINTAXIS_COUNT,													//!<数
	}PhysicsJointAxis;

	/*******************************//*!
	@brief	ジョイント動作フラグ列挙

			ジョイント動作フラグ列挙

	@author	CDW
	*//********************************/
	typedef enum tag_MOMPHYSICSJOINTMOTION {
		MOMPHYSICSJOINTMOTION_LOCKED,												//!<ロック
		MOMPHYSICSJOINTMOTION_LIMITED,												//!<限界設定
		MOMPHYSICSJOINTMOTION_FREE,													//!<フリー
	}PhysicsJointMotion;
	
	/*******************************//*!
	@brief	Physicsバネ情報構造体

			Physicsのバネに必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MOMPHYSICSSPRING {
		CVector3								Stiffness;							//!<剛性
		CVector3								Damping;							//!<減衰

		tag_MOMPHYSICSSPRING() :
		Stiffness() ,
		Damping(1.0f, 1.0f, 1.0f) {
		}
	}MOMPHYSICSSPRING,*LPMOMPHYSICSSPRING;
	
	/*******************************//*!
	@brief	Physics線形限界情報構造体

			Physicsの線形限界に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MOMPHYSICSLINEARLIMIT : public MOMPHYSICSSPRING {
		CVector3								Upper;
		CVector3								Lower;

		tag_MOMPHYSICSLINEARLIMIT() :
		tag_MOMPHYSICSSPRING() ,
		Upper() ,
		Lower() {
		}
	}MOMPHYSICSLINEARLIMIT,*LPMOMPHYSICSLINEARLIMIT;
	
	/*******************************//*!
	@brief	Physicsコーン限界情報構造体

			Physicsのコーン限界に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MOMPHYSICSANGULARLIMIT : public MOMPHYSICSSPRING {
		CVector3								Upper;
		CVector3								Lower;

		tag_MOMPHYSICSANGULARLIMIT() :
		tag_MOMPHYSICSSPRING() ,
		Upper(),
		Lower() {
		}
	}MOMPHYSICSANGULARLIMIT,*LPMOMPHYSICSANGULARLIMIT;
	
	/*******************************//*!
	@brief	メッシュモーションボーン情報管理構造体

			メッシュモーションボーン情報管理構造体。<br>
			アニメーション中の各ボーンの状態や補間を管理するための構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOMPHYSICSJOINTINFO {
		/*******************//*!
		ジョイント名
		*//********************/
		CString						JointName;
		/*******************//*!
		ジョイントタイプ
		*//********************/
		PhysicsJointType			Type;
		/*******************//*!
		対応ボーン名
		*//********************/
		CString						BoneAName;
		/*******************//*!
		対応オフセット
		*//********************/
		CVector3					BoneAOffset;
		/*******************//*!
		対応オフセット
		*//********************/
		CQuaternion					BoneAOrientation;
		/*******************//*!
		対応ボーン名
		*//********************/
		CString						BoneBName;
		/*******************//*!
		対応オフセット
		*//********************/
		CVector3					BoneBOffset;
		/*******************//*!
		対応オフセット
		*//********************/
		CQuaternion					BoneBOrientation;
		/*******************//*!
		モーション
		*//********************/
		PhysicsJointMotion			Motion[MOMPHYSICSJOINTAXIS_COUNT];
		/*******************//*!
		線形限界
		*//********************/
		MOMPHYSICSLINEARLIMIT		LinearLimit;
		/*******************//*!
		コーン限界
		*//********************/
		MOMPHYSICSANGULARLIMIT		AngularLimit;
		
		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOMPHYSICSJOINTINFO() :
		JointName() ,
		Type(MOMPHYSICSJOINTTYPE_6DOF) ,
		BoneAName() ,
		BoneAOffset() ,
		BoneAOrientation(0, 0, 0, 1) ,
		BoneBName() ,
		BoneBOffset() ,
		BoneBOrientation(0, 0, 0, 1) ,
		LinearLimit() ,
		AngularLimit() {
			Motion[MOMPHYSICSJOINTAXIS_X] = MOMPHYSICSJOINTMOTION_LOCKED;
			Motion[MOMPHYSICSJOINTAXIS_Y] = MOMPHYSICSJOINTMOTION_LOCKED;
			Motion[MOMPHYSICSJOINTAXIS_Z] = MOMPHYSICSJOINTMOTION_LOCKED;
			Motion[MOMPHYSICSJOINTAXIS_TWIST] = MOMPHYSICSJOINTMOTION_FREE;
			Motion[MOMPHYSICSJOINTAXIS_SWING1] = MOMPHYSICSJOINTMOTION_FREE;
			Motion[MOMPHYSICSJOINTAXIS_SWING2] = MOMPHYSICSJOINTMOTION_FREE;
		}
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピー元

				@return			None
		*//**************************************************************************/
		tag_MOMPHYSICSJOINTINFO(const tag_MOMPHYSICSJOINTINFO& pObj) :
		JointName(pObj.JointName) ,
		Type(pObj.Type) ,
		BoneAName(pObj.BoneAName) ,
		BoneAOffset(pObj.BoneAOffset) ,
		BoneAOrientation(pObj.BoneAOrientation) ,
		BoneBName(pObj.BoneBName) ,
		BoneBOffset(pObj.BoneBOffset) ,
		BoneBOrientation(pObj.BoneBOrientation),
		LinearLimit(pObj.LinearLimit) ,
		AngularLimit(pObj.AngularLimit) {
			memcpy(Motion, pObj.Motion, sizeof(Motion));
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOMPHYSICSJOINTINFO);
	}MOMPHYSICSJOINTINFO,*LPMOMPHYSICSJOINTINFO;
	typedef CDynamicArray< LPMOMPHYSICSJOINTINFO >		CPhysicsJointInfoArray,*LPPhysicsJointInfoArray;

	/*******************************//*!
	@brief	メッシュモーションボーン情報管理構造体

			メッシュモーションボーン情報管理構造体。<br>
			アニメーション中の各ボーンの状態や補間を管理するための構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_MOMPHYSICSRIGIDINFO {
		/*******************//*!
		剛体名
		*//********************/
		CString						RigidName;
		/*******************//*!
		自動剛体サイズ
		*//********************/
		MofBool						bAutoSize;
		/*******************//*!
		剛体サイズ
		*//********************/
		CVector3					RigidSize;
		/*******************//*!
		対応ボーン名
		*//********************/
		CString						BoneName;
		/*******************//*!
		対応オフセット
		*//********************/
		CVector3					BoneOffset;
		/*******************//*!
		対応オフセット
		*//********************/
		CQuaternion					BoneOrientation;
		/*******************//*!
		グループ
		*//********************/
		MofU32						Group;
		/*******************//*!
		グループ
		*//********************/
		MofU32						TargetGroup;
		/*******************//*!
		摩擦
		*//********************/
		MofFloat					Mass;
		/*******************//*!
		摩擦
		*//********************/
		MofFloat					LinearDamping;
		/*******************//*!
		摩擦
		*//********************/
		MofFloat					AngularDamping;
		/*******************//*!
		摩擦
		*//********************/
		MofFloat					StaticFriction;
		/*******************//*!
		摩擦
		*//********************/
		MofFloat					DynamicFriction;
		/*******************//*!
		反発
		*//********************/
		MofFloat					Restitution;
		/*******************//*!
		対応オフセット
		*//********************/
		MofFloat					Density;
		/*******************//*!
		ルート対応
		*//********************/
		MofBool						bRoot;
		/*******************//*!
		状態
		*//********************/
		PhysicsBoneFlag				InitState;
		/*******************//*!
		状態固定
		*//********************/
		MofBool						bStateLock;
		/*******************//*!
		親参照
		*//********************/
		MofBool						bParentRelation;
		/*******************//*!
		剛体のタイプ
		*//********************/
		PhysicsGeometryType			GeometryType;
		/*******************//*!
		自動子剛体生成
		*//********************/
		MofBool						bAutoChild;
		
		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOMPHYSICSRIGIDINFO() :
		RigidName() ,
		bAutoSize(TRUE) ,
		RigidSize(1, 1, 1) ,
		BoneName() ,
		BoneOffset() ,
		BoneOrientation(0,0,0,1) ,
		Group(0) ,
		TargetGroup(0) , 
		Mass(-1.0f) ,
		LinearDamping(0.0f) ,
		AngularDamping(0.05f) ,
		StaticFriction(0.5f) ,
		DynamicFriction(0.5f) ,
		Restitution(0.5f) ,
		Density(1.0f) ,
		bRoot(FALSE) ,
		InitState(MOMPHYSICSBONEFLAG_FIXED) ,
		bStateLock(FALSE) ,
		bParentRelation(TRUE) ,
		GeometryType(MOMPHYSICSGEOMETRYTYPE_SPHERE) ,
		bAutoChild(FALSE) {
		}
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピー元

				@return			None
		*//**************************************************************************/
		tag_MOMPHYSICSRIGIDINFO(const tag_MOMPHYSICSRIGIDINFO& pObj) :
		RigidName(pObj.RigidName) ,
		bAutoSize(pObj.bAutoSize) ,
		RigidSize(pObj.RigidSize) ,
		BoneName(pObj.BoneName) ,
		BoneOffset(pObj.BoneOffset) ,
		BoneOrientation(pObj.BoneOrientation) ,
		Group(pObj.Group) ,
		TargetGroup(pObj.TargetGroup) ,
		Mass(pObj.Mass) ,
		LinearDamping(pObj.LinearDamping) ,
		AngularDamping(pObj.AngularDamping) ,
		StaticFriction(pObj.StaticFriction) ,
		DynamicFriction(pObj.DynamicFriction) ,
		Restitution(pObj.Restitution) ,
		Density(pObj.Density) ,
		bRoot(pObj.bRoot) ,
		InitState(pObj.InitState) ,
		bStateLock(pObj.bStateLock) ,
		bParentRelation(pObj.bParentRelation) ,
		GeometryType(pObj.GeometryType),
		bAutoChild(pObj.bAutoChild) {
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_MOMPHYSICSRIGIDINFO);
	}MOMPHYSICSRIGIDINFO,*LPMOMPHYSICSRIGIDINFO;
	typedef CDynamicArray< LPMOMPHYSICSRIGIDINFO >		CPhysicsActorInfoArray,*LPPhysicsActorInfoArray;
	
}

#endif

//[EOF]