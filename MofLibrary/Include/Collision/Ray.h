/*************************************************************************//*!
					
					@file	Ray.h
					@brief	レイ演算関連<br>
							レイを使用した当たり判定用のレイ構造体と、各種形状用の接触判定関数を提供する。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__RAY__H__

#define		__RAY__H__

//INCLUDE
#include	"Sphere.h"
#include	"Box.h"

namespace Mof {

	/*******************************//*!
	@brief	3Dレイ構造体

			3Dレイを扱うための構造体。<br>
			レイの始点(Position)と方向(Direction)でレイの情報を表す。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT Ray3D {
		Vector3				Position;					//!<始点
		Vector3				Direction;					//!<方向
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		Ray3D();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pos			座標
				@param[in]		dir			方向

				@return			None
		*//**************************************************************************/
		Ray3D(const Vector3& pos,const Vector3& dir);
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pv			座標

				@return			None
		*//**************************************************************************/
		Ray3D(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーレイ

				@return			None
		*//**************************************************************************/
		Ray3D(const Ray3D& pObj);
		
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			+=演算
		*//**************************************************************************/
		Ray3D& operator += ( const Vector3& v );
		/*************************************************************************//*!
				@brief			+=演算
		*//**************************************************************************/
		Ray3D& operator += ( const Ray3D& v );
		/*************************************************************************//*!
				@brief			-=演算
		*//**************************************************************************/
		Ray3D& operator -= ( const Vector3& v );
		/*************************************************************************//*!
				@brief			-=演算
		*//**************************************************************************/
		Ray3D& operator -= ( const Ray3D& v );
		/*************************************************************************//*!
				@brief			Vector3との+演算
		*//**************************************************************************/
		Ray3D operator + ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Ray3Dとの+演算
		*//**************************************************************************/
		Ray3D operator + ( const Ray3D& v ) const;
		/*************************************************************************//*!
				@brief			Vector3との-演算
		*//**************************************************************************/
		Ray3D operator - ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Ray3Dとの-演算
		*//**************************************************************************/
		Ray3D operator - ( const Ray3D& v ) const;
	}Ray3D;
	
	/*******************************//*!
	@brief	3Dレイ演算クラス

			Ray3D構造体を扱うためのスタティッククラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRay3DUtilities {
	public:
		/*************************************************************************//*!
				@brief			レイのローカル変換<br>
								rayをmatで指定された行列のローカル空間に変換をおこないoutに格納する。
				@param[in]		ray			変換レイ
				@param[in]		mat			変換行列
				@param[out]		out			変換済みレイ

				@return			None
		*//**************************************************************************/
		static void ToLocal(const Ray3D& ray, const Matrix44& mat, Ray3D& out);

		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した平面と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		pos			平面点
				@param[in]		nrm			法線
				@param[in]		ray			判定レイ
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionPlane(const Vector3& pos,const Vector3& nrm,const Ray3D& ray,MofFloat& od);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した平面と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		pos			平面点
				@param[in]		nrm			法線
				@param[in]		rpos		レイの座標
				@param[in]		rdir		レイの方向
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionPlane(const Vector3& pos,const Vector3& nrm, const Vector3& rpos, const Vector3& rdir,MofFloat& od);

		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した球と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		sph			判定球
				@param[in]		ray			判定レイ
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionSphere(const Sphere& sph,const Ray3D& ray,MofFloat& od);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したAABBと交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		aabb		判定AABB
				@param[in]		ray			判定レイ
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionAABB(const BoxAABB& aabb,const Ray3D& ray,MofFloat& od);
		
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した三角形と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		ptc			三角形
				@param[in]		ray			判定レイ
				@param[in,out]	od			判定限界距離/出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionTriangle(LPTRIANGLECOLLISIONCACHE ptc, const Ray3D& ray, MofFloat& od);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した三角形と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		ta			三角形頂点１
				@param[in]		tb			三角形頂点２
				@param[in]		tc			三角形頂点３
				@param[in]		ray			判定レイ
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc,const Ray3D& ray,MofFloat& od);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した三角形と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		ta			三角形頂点１
				@param[in]		tb			三角形頂点２
				@param[in]		tc			三角形頂点３
				@param[in]		ray			判定レイ
				@param[out]		od			出力接触距離
				@param[out]		on			出力三角形法線

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc,const Ray3D& ray,MofFloat& od,Vector3& on);
		
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した三角形と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		ptc			三角形
				@param[in]		pos			レイの座標
				@param[in]		dir			レイの方向
				@param[in,out]	od			判定限界距離/出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionTriangle(LPTRIANGLECOLLISIONCACHE ptc, const Vector3& pos, const Vector3& dir, MofFloat& od);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した三角形と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		ta			三角形頂点１
				@param[in]		tb			三角形頂点２
				@param[in]		tc			三角形頂点３
				@param[in]		pos			レイの座標
				@param[in]		dir			レイの方向
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc, const Vector3& pos, const Vector3& dir,MofFloat& od);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した三角形と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		ta			三角形頂点１
				@param[in]		tb			三角形頂点２
				@param[in]		tc			三角形頂点３
				@param[in]		pos			レイの座標
				@param[in]		dir			レイの方向
				@param[out]		od			出力接触距離
				@param[out]		on			出力三角形法線

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc, const Vector3& pos, const Vector3& dir,MofFloat& od,Vector3& on);

		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したジオメトリと交差するかを判定する。
				@param[in]		pGeom		判定ジオメトリ
				@param[in]		ray			判定レイ

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionGeometry(LPGeometry pGeom, const Ray3D& ray);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したジオメトリと交差するかを判定する。<br>
								交差する場合、接触ポリゴンの情報をoutに格納する
				@param[in]		pGeom		判定ジオメトリ
				@param[in]		ray			判定レイ
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionGeometry(LPGeometry pGeom, const Ray3D& ray, COLLISIONOUTGEOMETRY& out);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したジオメトリと交差するかを判定する。
				@param[in]		pGeom		判定ジオメトリ
				@param[in]		ray			判定レイ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionGeometry(LPGeometry pGeom, const Ray3D& ray, IsTriangleCollision pFunc);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したジオメトリと交差するかを判定する。<br>
								交差する場合、接触ポリゴンの情報をoutに格納する
				@param[in]		pGeom		判定ジオメトリ
				@param[in]		ray			判定レイ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionGeometry(LPGeometry pGeom, const Ray3D& ray, IsTriangleCollision pFunc, COLLISIONOUTGEOMETRY& out);

		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMesh pMesh, const Ray3D& ray);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMesh pMesh, const Ray3D& ray, COLLISIONOUTMESH& out);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMesh pMesh, const Ray3D& ray, IsTriangleCollision pFunc);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMesh pMesh, const Ray3D& ray, IsTriangleCollision pFunc, COLLISIONOUTMESH& out);

		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, COLLISIONOUTGEOMETRY& out);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, COLLISIONOUTMESHCONTAINER& out);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, IsTriangleCollision pFunc);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, IsTriangleCollision pFunc, COLLISIONOUTGEOMETRY& out);
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[in]		ray			判定レイ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, IsTriangleCollision pFunc, COLLISIONOUTMESHCONTAINER& out);
	private:
		//作成を禁止する
		CRay3DUtilities(){};
		CRay3DUtilities(const CRay3DUtilities& pObj){};
	};
	
	/*******************************//*!
	@brief	2Dレイクラス

			2Dレイを扱うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRay3D : public Ray3D , public IMofBase {
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CRay3D();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pos			座標
				@param[in]		dir			方向

				@return			None
		*//**************************************************************************/
		CRay3D(const Vector3& pos,const Vector3& dir);
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pv			座標

				@return			None
		*//**************************************************************************/
		CRay3D(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーレイ

				@return			None
		*//**************************************************************************/
		CRay3D(const Ray3D& pObj);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーレイ

				@return			None
		*//**************************************************************************/
		CRay3D(const CRay3D& pObj);
		
		/*************************************************************************//*!
				@brief			移動<br>
								m移動する。
				@param[in]		m			移動量
				
				@return			None
		*//**************************************************************************/
		void Translation(const Vector3& m);
		/*************************************************************************//*!
				@brief			移動<br>
								posの位置に移動する。
				@param[in]		pos			位置
				
				@return			None
		*//**************************************************************************/
		void SetPosition(const Vector3& pos);

		/*************************************************************************//*!
				@brief			レイのローカル変換<br>
								matで指定された行列のローカル空間に変換をおこなう。
				@param[in]		mat			変換行列

				@return			None
		*//**************************************************************************/
		void ToLocal(Matrix44& mat);
		/*************************************************************************//*!
				@brief			レイのローカル変換<br>
								matで指定された行列のローカル空間に変換をおこないoutに格納する。
				@param[in]		mat			変換行列
				@param[out]		out			変換済みレイ

				@return			None
		*//**************************************************************************/
		void ToLocal(Matrix44& mat, Ray3D& out) const;

		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した平面と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		pos			平面点
				@param[in]		nrm			法線
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionPlane(const Vector3& pos,const Vector3& nrm,MofFloat& od) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した球と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		sph			判定球
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionSphere(const Sphere& sph,MofFloat& od) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したAABBと交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		aabb		判定AABB
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionAABB(const BoxAABB& aabb, MofFloat& od) const;
		
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した三角形と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		ptc			三角形
				@param[in,out]	od			判定限界距離/出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionTriangle(LPTRIANGLECOLLISIONCACHE ptc, MofFloat& od) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した三角形と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		ta			三角形頂点１
				@param[in]		tb			三角形頂点２
				@param[in]		tc			三角形頂点３
				@param[out]		od			出力接触距離

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc,MofFloat& od) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定した三角形と交差するかを判定する。<br>
								交差する場合、接触するまでの距離をodに入れる
				@param[in]		ta			三角形頂点１
				@param[in]		tb			三角形頂点２
				@param[in]		tc			三角形頂点３
				@param[out]		od			出力接触距離
				@param[out]		on			出力三角形法線

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc,MofFloat& od,Vector3& on) const;

		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したジオメトリと交差するかを判定する。
				@param[in]		pGeom		判定ジオメトリ

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したジオメトリと交差するかを判定する。<br>
								交差する場合、接触ポリゴンの情報をoutに格納する
				@param[in]		pGeom		判定ジオメトリ
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom, COLLISIONOUTGEOMETRY& out) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したジオメトリと交差するかを判定する。
				@param[in]		pGeom		判定ジオメトリ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom, IsTriangleCollision pFunc) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したジオメトリと交差するかを判定する。<br>
								交差する場合、接触ポリゴンの情報をoutに格納する
				@param[in]		pGeom		判定ジオメトリ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom, IsTriangleCollision pFunc, COLLISIONOUTGEOMETRY& out) const;

		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。
				@param[in]		pMesh		判定メッシュ

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh, COLLISIONOUTMESH& out) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。
				@param[in]		pMesh		判定メッシュ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh, IsTriangleCollision pFunc) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh, IsTriangleCollision pFunc, COLLISIONOUTMESH& out) const;

		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。
				@param[in]		pMesh		判定メッシュ

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, COLLISIONOUTGEOMETRY& out) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, COLLISIONOUTMESHCONTAINER& out) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。
				@param[in]		pMesh		判定メッシュ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, IsTriangleCollision pFunc) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pMesh		判定メッシュ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, IsTriangleCollision pFunc, COLLISIONOUTGEOMETRY& out) const;
		/*************************************************************************//*!
				@brief			あたり判定<br>
								指定したメッシュと交差するかを判定する。<br>
								交差する場合、接触ジオメトリの情報をoutに格納する
				@param[in]		pGeom		判定メッシュ
				@param[in]		pFunc		判定省略用関数（この関数でTRUEを返したポリゴンとしか判定を実行しない）
				@param[out]		out			出力接触ポリゴン情報

				@return			TRUE		接触あり
								FALSE		接触なし
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, IsTriangleCollision pFunc, COLLISIONOUTMESHCONTAINER& out) const;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------

		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CRay3D& operator = ( const Ray3D& v );

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTEQUAL(CRay3D,MOF_RAY3DCLASS_ID);
	};

	//ポインタ置き換え
	typedef CRay3D*				LPRay3D;

	#include	"Ray.inl"

}

#endif

//[EOF]