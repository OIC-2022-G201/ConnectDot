/*************************************************************************//*!
					
					@file	CollisionCommon.h
					@brief	ライブラリのコリジョン系基本定義を行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__COLLISIONCOMMON__H__

#define		__COLLISIONCOMMON__H__

//INCLUDE
#include	"../Math/Matrix44.h"
#include	"../Common/DynamicArray.h"

namespace Mof {

	//前方定義
	class IGeometry;
	typedef IGeometry*				LPGeometry;
	class IMesh;
	typedef IMesh*					LPMesh;
	class IMeshContainer;
	typedef IMeshContainer*			LPMeshContainer;

	/*******************************//*!
	@brief	三角形の接触判定用キャッシュ

			三角形の接触判定用キャッシュ構造体。<br>
			ジオメトリとの接触判定の初回実行時にジオメトリ内部に保存される。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_TRIANGLECOLLISIONCACHE{
		MofU32					Index[3];					//!<インデックス
		Vector3					Vertex[3];					//!<頂点
		Vector3					Edge[3];					//!<辺
		Vector3					Normal;						//!<法線

		MOF_ALIGNED_NEW_OPERATOR(tag_TRIANGLECOLLISIONCACHE);
	}TRIANGLECOLLISIONCACHE, *LPTRIANGLECOLLISIONCACHE;
	typedef CDynamicArray< LPTRIANGLECOLLISIONCACHE >		CGeometryCollisionCache, *LPGeometryCollisionCache;
	typedef MofBool(*IsTriangleCollision)(LPTRIANGLECOLLISIONCACHE);
	/*******************************//*!
	@brief	ジオメトリとの接触情報出力

			ジオメトリとの接触情報出力構造体。<br>
			CollisionGeometry等の接触判定関数の出力として利用される。<br>
			接触したポリゴンを構成するインデックス情報、ポリゴンの法線ベクトル、接触位置までの距離を持つ。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_COLLISIONOUTGEOMETRY{
		MofU32					Index1;						//!<インデックス１
		MofU32					Index2;						//!<インデックス２
		MofU32					Index3;						//!<インデックス３
		Vector3					Normal;						//!<法線
		MofFloat				d;							//!<距離

		MOF_ALIGNED_NEW_OPERATOR(tag_COLLISIONOUTGEOMETRY);
	}COLLISIONOUTGEOMETRY, *LPCOLLISIONOUTGEOMETRY;

	/*******************************//*!
	@brief	メッシュとの接触情報出力

			メッシュとの接触情報出力構造体。<br>
			ジオメトリの接触情報に加え接触したジオメトリのメッシュ内の要素番号を加える

	@author	CDW
	*//********************************/
	typedef struct tag_COLLISIONOUTMESH {
		MofU32					No;							//!<接触ジオメトリ番号
		COLLISIONOUTGEOMETRY	Geometry;					//!<接触ジオメトリ情報
	}COLLISIONOUTMESH, *LPCOLLISIONOUTMESH;

	/*******************************//*!
	@brief	メッシュコンテナとの接触情報出力

			メッシュコンテナとの接触情報出力構造体。<br>
			メッシュの接触情報に加え接触したメッシュのコンテナ内の要素番号を加える

	@author	CDW
	*//********************************/
	typedef struct tag_COLLISIONOUTMESHCONTAINER {
		MofU32					No;							//!<接触メッシュ番号
		COLLISIONOUTMESH		Mesh;						//!<接触メッシュ情報
	}COLLISIONOUTMESHCONTAINER, *LPCOLLISIONOUTMESHCONTAINER;

}

#endif

//[EOF]