/*************************************************************************//*!
					
					@file	MosCommon.h
					@brief	独自形式スプライトファイル関連の基本定義を行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MOSCOMMON__H__

#define		__MOSCOMMON__H__

//INCLUDE
#include	"GraphicsCommon.h"
#include	"../Common/PackFile.h"
#include	"../Common/WriteChunkFile.h"
#include	"../Common/KeyFrameArray.h"

//DEFINE

//!独自ファイルヘッダー
#define		MOFSPRITE_FILE_HEADER				"MOS SPRITE VER 0.01 FILE"

//!独自ファイルヘッダー長
#define		MOFSPRITE_FILE_HEADERLEN			strlen(MOFSPRITE_FILE_HEADER)

//!独自ファイルフッター
#define		MOFSPRITE_FILE_FOOTER				"EOF"

//!独自ファイルフッター長
#define		MOFSPRITE_FILE_FOOTERLEN			strlen(MOFSPRITE_FILE_FOOTER)

namespace Mof {
	
	/*******************************//*!
	@brief	スプライトパーツタイプ列挙

			スプライトパーツがどういう情報を管理しているかを指定するタイプを列挙

	@author	CDW
	*//********************************/
	typedef enum tag_SPRITETYPE {
		SPRITETYPE_NULL,															//!<空スプライト
		SPRITETYPE_NORMAL,															//!<通常管理スプライト
		SPRITETYPE_EMITTER,															//!<エミッター
		SPRITETYPE_PARTICLE,														//!<パーティクル
	}SpriteType;

	/*******************************//*!
	@brief	スプライトファイルテンプレート列挙

			MOSファイル内に定義されるチャンクの情報タイプを列挙

	@author	CDW
	*//********************************/
	enum tag_MOFSPRITE_TEMPLATE {
		MOFSPRITE_TEMP_TEXTURE					=		0x00001000,					//!<テクスチャ

		MOFSPRITE_TEMP_SPRITE					=		0x00002000,					//!<スプライト

		MOFSPRITE_TEMP_SPRITECONTAINER			=		0x00003000,					//!<スプライトコンテナ

		MOFSPRITE_TEMP_SPRITEANIMATION			=		0x00004000,					//!<スプライトアニメーション
		MOFSPRITE_TEMP_SPRITEPARTANIMATION,											//!<スプライトパーツアニメーション
		MOFSPRITE_TEMP_SPRITEPARTANIMATIONKEY,										//!<スプライトパーツアニメーションキー

		MOFSPRITE_TEMP_EFFECT					=		0x00005000,					//!<スプライトエフェクト

		MOFSPRITE_TEMP_MAX,															//!<チャンク最大数
	};
	
	/*******************************//*!
	@brief	スプライトファイルキータイプ列挙

			MOSファイル内に定義されるアニメーションのキータイプを列挙

	@author	CDW
	*//********************************/
	typedef enum tag_MOFSPRITE_ANIMATIONKEYTYPE {
		MOFSPRITE_ANIMATIONKEY_TRANSLATION,											//!<平行移動
		MOFSPRITE_ANIMATIONKEY_TRANSLATIONX,										//!<平行移動X
		MOFSPRITE_ANIMATIONKEY_TRANSLATIONY,										//!<平行移動Y
		MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ,										//!<平行移動Z

		MOFSPRITE_ANIMATIONKEY_SCALING,												//!<スケール
		MOFSPRITE_ANIMATIONKEY_SCALINGX,											//!<スケールX
		MOFSPRITE_ANIMATIONKEY_SCALINGY,											//!<スケールY
		MOFSPRITE_ANIMATIONKEY_SCALINGZ,											//!<スケールZ

		MOFSPRITE_ANIMATIONKEY_ROTATION,											//!<回転
		MOFSPRITE_ANIMATIONKEY_ROTATIONX,											//!<回転X
		MOFSPRITE_ANIMATIONKEY_ROTATIONY,											//!<回転Y
		MOFSPRITE_ANIMATIONKEY_ROTATIONZ,											//!<回転Z
		
		MOFSPRITE_ANIMATIONKEY_COLOR,												//!<色
		MOFSPRITE_ANIMATIONKEY_COLORR,												//!<色Ｒ
		MOFSPRITE_ANIMATIONKEY_COLORG,												//!<色Ｇ
		MOFSPRITE_ANIMATIONKEY_COLORB,												//!<色Ｂ
		MOFSPRITE_ANIMATIONKEY_COLORA,												//!<色Ａ

		MOFSPRITE_ANIMATIONKEY_PRIORITY,											//!<描画優先順位
		
		MOFSPRITE_ANIMATIONKEY_ALIGNMENT,											//!<アライメント
		MOFSPRITE_ANIMATIONKEY_ALIGNMENTX,											//!<アライメントX
		MOFSPRITE_ANIMATIONKEY_ALIGNMENTY,											//!<アライメントY
		MOFSPRITE_ANIMATIONKEY_ALIGNMENTZ,											//!<アライメントZ

		MOFSPRITE_ANIMATIONKEY_ANCHOR,												//!<アンカー
		MOFSPRITE_ANIMATIONKEY_ANCHORX,												//!<アンカーX
		MOFSPRITE_ANIMATIONKEY_ANCHORY,												//!<アンカーY
		MOFSPRITE_ANIMATIONKEY_ANCHORZ,												//!<アンカーZ
		
		MOFSPRITE_ANIMATIONKEY_SIZE,												//!<サイズ
		MOFSPRITE_ANIMATIONKEY_SIZEX,												//!<サイズX
		MOFSPRITE_ANIMATIONKEY_SIZEY,												//!<サイズY
		MOFSPRITE_ANIMATIONKEY_SIZEZ,												//!<サイズZ

		MOFSPRITE_ANIMATIONKEY_SHOW,												//!<表示

		MOFSPRITE_ANIMATIONKEY_XREVERSE,											//!<X反転
		MOFSPRITE_ANIMATIONKEY_YREVERSE,											//!<Y反転

		MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1,									//!<頂点
		MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION2,									//!<頂点
		MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION3,									//!<頂点
		MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION4,									//!<頂点

		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1,										//!<頂点
		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR2,										//!<頂点
		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR3,										//!<頂点
		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR4,										//!<頂点
		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR5,										//!<頂点

		MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX,										//!<UV
		MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY,										//!<UV
		MOFSPRITE_ANIMATIONKEY_UVROTATION,											//!<UV
		MOFSPRITE_ANIMATIONKEY_UVSIZEX,												//!<UV
		MOFSPRITE_ANIMATIONKEY_UVSIZEY,												//!<UV

		MOFSPRITE_ANIMATIONKEY_EFFECTTIME,											//!<エフェクトタイム
	}SpriteAnimationKeyType;
	
	/*******************************//*!
	@brief	スプライトパーティクルアニメーション列挙

			MOSファイル内に定義されるスプライトパーティクルアニメーションのタイプを列挙

	@author	CDW
	*//********************************/
	enum tag_MOFSPRITE_EFFECTANIMATION {
		MOFSPRITE_EFFECTANIMATION_BASIC						=		0x00000001,					//!<基本
		MOFSPRITE_EFFECTANIMATION_SEED						=		0x00000002,					//!<乱数変更
		MOFSPRITE_EFFECTANIMATION_DELAY						=		0x00000004,					//!<遅延
		MOFSPRITE_EFFECTANIMATION_GRAVITY					=		0x00000008,					//!<重力
		MOFSPRITE_EFFECTANIMATION_POSITION					=		0x00000010,					//!<座標
		MOFSPRITE_EFFECTANIMATION_ROTATION					=		0x00000020,					//!<回転
		MOFSPRITE_EFFECTANIMATION_ROTATIONTRANS				=		0x00000040,					//!<回転
		MOFSPRITE_EFFECTANIMATION_SPEEDTRANS				=		0x00000080,					//!<速度
		MOFSPRITE_EFFECTANIMATION_TANGENTIALACCELERATION	=		0x00000100,					//!<速度
		MOFSPRITE_EFFECTANIMATION_INITIALIZECOLOR			=		0x00000200,					//!<色
		MOFSPRITE_EFFECTANIMATION_COLORTRANS				=		0x00000400,					//!<色
		MOFSPRITE_EFFECTANIMATION_ALPHA						=		0x00000800,					//!<色
		MOFSPRITE_EFFECTANIMATION_SIZE						=		0x00001000,					//!<大きさ
		MOFSPRITE_EFFECTANIMATION_SIZETRANS					=		0x00002000,					//!<大きさ
		MOFSPRITE_EFFECTANIMATION_POINTGRAVITY				=		0x00004000,					//!<大きさ
		MOFSPRITE_EFFECTANIMATION_DIRECTION					=		0x00008000,					//!<大きさ
		MOFSPRITE_EFFECTANIMATION_INFINITE					=		0x00010000,					//!<大きさ

		MOFSPRITE_EFFECTANIMATION_MAX,															//!<チャンク最大数
	};

	/*******************************//*!
	@brief	スプライトファイル解析エラー列挙

			スプライトファイル解析時に発生するエラーを列挙

	@author	CDW
	*//********************************/
	enum tag_MOFSPRITE_RESULT {
		MOFSPRITE_RESULTERROR_UNKNOWN		=		0,								//!<よくわからないエラー

		MOFSPRITE_RESULT_SUCCEEDED			=		TRUE,							//!<正常終了

		MOFSPRITE_RESULTERROR_OPENERROR,											//!<ファイルを開けなかった
		MOFSPRITE_RESULTERROR_NOTMOSFILE,											//!<ファイルがMOS形式じゃない

		MOFSPRITE_RESULTERROR_CHUNKSIZE,											//!<チャンクサイズがおかしい
		MOFSPRITE_RESULTERROR_UNKNOWNCHUNK,											//!<チャンクが変な位置に存在する
		MOFSPRITE_RESULTERROR_CHUNKENDFAULT,										//!<チャンク終了が見つからない
		MOFSPRITE_RESULTERROR_UNKNOWNCHUNKEND,										//!<チャンク終了が変な位置に存在する

		MOFSPRITE_RESULTERROR_NOTFOOTER,											//!<フッターでなく最大サイズを超える
		MOFSPRITE_RESULTERROR_UNKNOWNFOOTER,										//!<フッターが変な位置に存在する
		
		MOFSPRITE_RESULTERROR_TEXTURELOAD,											//!<テクスチャの読み込み失敗
	};

	/*******************************//*!
	@brief	スプライトファイルヘッダー構造体

			スプライトファイルの基本情報を格納したヘッダー構造体

	@author	CDW
	*//********************************/
	typedef struct tag_MOFSPRITEHEADER {
		MofBool						bStringCode;									//!<文字コード(UNICODE形式ならTRUE,マルチバイトならFALSE)
		MofU32						Alignment;										//!<アライメント
		MofU32						BlockSize;										//!<ブロックサイズ
		MofU32						Flag;											//!<ファイル情報追加フラグ
	}MOFSPRITEHEADER,*LPMOFSPRITEHEADER;
	
	/*******************************//*!
	@brief	スプライトエフェクトのデータ構造体

			エフェクトのばらつきのためのデータを表す構造体

	@author	CDW
	*//********************************/
	template < typename T > struct MOFSPRITEEFFECTVALUE {
		T							Start;											//!<開始
		T							Range;											//!<範囲

		MOFSPRITEEFFECTVALUE(const T& s,const T& r) :
		Start(s) ,
		Range(r) {
		}
		
		MOFSPRITEEFFECTVALUE(const MOFSPRITEEFFECTVALUE& pObj) :
		Start(pObj.Start) ,
		Range(pObj.Range) {
		}
	};
	
	/*******************************//*!
	@brief	スプライトエフェクトのデータ構造体

			エフェクトのデータを表す構造体

	@author	CDW
	*//********************************/
	typedef struct tag_MOFSPRITEEFFECTPARAMETER {
		MofU32								Flag;									//!<動作フラグ
		MofFloat							Life;									//!<生存時間
		MofFloat							Interval;								//!<生成間隔
		MofS32								CreateCount;							//!<一度に排出される個数
		MofS32								CreateMax;								//!<最大排出数
		MOFSPRITEEFFECTVALUE< MofFloat >	ParticleLife;							//!<生成されるパーティクルの寿命

		MOFSPRITEEFFECTVALUE< Vector2 >		Offset;									//!<オフセット
		MOFSPRITEEFFECTVALUE< Vector2 >		Scale;									//!<スケール
		MOFSPRITEEFFECTVALUE< MofFloat >	Angle;									//!<向き
		Vector4								StartColor;								//!<開始色
		Vector4								EndColor;								//!<終了色
		MOFSPRITEEFFECTVALUE< MofFloat >	Speed;									//!<速度
		MOFSPRITEEFFECTVALUE< MofFloat >	Acceleration;							//!<速度
		MOFSPRITEEFFECTVALUE< MofFloat >	Rotation;								//!<回転
		MOFSPRITEEFFECTVALUE< MofFloat >	RotationAcceleration;					//!<回転
		Vector2								Gravity;								//!<重力
		MofFloat							Delay;									//!<遅延
		MofFloat							RotationFactor;							//!<回転
		MofFloat							RotationEndLifeTimePer;					//!<回転
		MOFSPRITEEFFECTVALUE< MofFloat >	TangentialAcceleration;					//!<接速度
		MOFSPRITEEFFECTVALUE< Vector4 >		CreateColor;							//!<色
		MOFSPRITEEFFECTVALUE< Vector4 >		ColorChange;							//!<色
		MOFSPRITEEFFECTVALUE< MofFloat >	Alpha;									//!<アルファ
		MOFSPRITEEFFECTVALUE< MofFloat >	ScaleFactor;							//!<速度
		MOFSPRITEEFFECTVALUE< Vector2 >		ScaleChange;							//!<スケール
		MOFSPRITEEFFECTVALUE< MofFloat >	ScaleChangeFactor;						//!<速度
		Vector2								GravityPosition;						//!<重力
		MofFloat							GravityPower;							//!<重力
		MofFloat							Direction;								//!<重力

		MofS32								Seed;									//!<乱数用種
		tag_MOFSPRITEEFFECTPARAMETER() :
		Flag(0) ,
		Life(0) ,
		Interval(0) ,
		CreateCount(0) ,
		CreateMax(0) ,
		ParticleLife(0,0) ,
		Offset(Vector2(0,0), Vector2(0,0)) ,
		Scale(Vector2(1,1), Vector2(0,0)) ,
		Angle(0, 0) ,
		StartColor(1,1,1,1) ,
		EndColor(1,1,1,1) ,
		Speed(0, 0) ,
		Acceleration(0, 0) ,
		Rotation(0, 0) ,
		RotationAcceleration(0, 0) ,
		Gravity(0,0) ,
		Delay(0) ,
		RotationFactor(0) ,
		RotationEndLifeTimePer(0) ,
		TangentialAcceleration(0,0) ,
		CreateColor(Vector4(0,0,0,0), Vector4(0, 0, 0, 0)) ,
		ColorChange(Vector4(0,0,0,0), Vector4(0, 0, 0, 0)) ,
		Alpha(0,0) ,
		ScaleFactor(0,0) ,
		ScaleChange(Vector2(0,0), Vector2(0,0)) ,
		ScaleChangeFactor(0,0) ,
		GravityPosition(0,0) ,
		GravityPower(0) ,
		Direction(0) ,
		Seed(0) 
		{
		}
		tag_MOFSPRITEEFFECTPARAMETER(const tag_MOFSPRITEEFFECTPARAMETER& pObj):
		Flag(pObj.Flag) ,
		Life(pObj.Life) ,
		Interval(pObj.Interval) ,
		CreateCount(pObj.CreateCount) ,
		CreateMax(pObj.CreateMax) ,
		ParticleLife(pObj.ParticleLife) ,
		Offset(pObj.Offset) ,
		Scale(pObj.Scale) ,
		Angle(pObj.Angle) ,
		StartColor(pObj.StartColor) ,
		EndColor(pObj.EndColor),
		Speed(pObj.Speed) ,
		Acceleration(pObj.Acceleration) ,
		Rotation(pObj.Rotation) ,
		RotationAcceleration(pObj.RotationAcceleration) ,
		Gravity(pObj.Gravity) ,
		Delay(pObj.Delay) ,
		RotationFactor(pObj.RotationFactor) ,
		RotationEndLifeTimePer(pObj.RotationEndLifeTimePer) ,
		TangentialAcceleration(pObj.TangentialAcceleration) ,
		CreateColor(pObj.CreateColor) ,
		ColorChange(pObj.ColorChange) ,
		Alpha(pObj.Alpha) ,
		ScaleFactor(pObj.ScaleFactor) ,
		ScaleChange(pObj.ScaleChange) ,
		ScaleChangeFactor(pObj.ScaleChangeFactor) ,
		GravityPosition(pObj.GravityPosition) ,
		GravityPower(pObj.GravityPower) ,
		Direction(pObj.Direction) ,
		Seed(pObj.Seed)
		{
		}
	}MOFSPRITEEFFECTPARAMETER,*LPMOFSPRITEEFFECTPARAMETER;
}

#endif

//[EOF]