/*************************************************************************//*!
					
					@file	MeshContainer.h
					@brief	メッシュコンテナ基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHCONTAINER__H__

#define		__MESHCONTAINER__H__

//INCLUDE
#include	"Mesh.h"
#include	"MeshCameraBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュコンテナインターフェイス

			メッシュコンテナインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshContainer : public IMofNamedObject , public IMofCopyObject< IMeshContainer > {
	private:
	public:
		/*************************************************************************//*!
				@brief			メッシュの読み込み
				@param[in]		pName		ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			メッシュの読み込み<br>
								メッシュ内部で利用するテクスチャを引数のテクスチャ配列「pTex」から検索をおこなう。<br>
								存在しない場合新規読み込みをおこない、テクスチャ配列に追加する。<br>
								別メッシュで同一テクスチャを複数使用する場合のメモリ節約に活用する。
				@param[in]		pName		ファイル名
				@param[in]		pTex		テクスチャ検索用配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPTextureArray pTex) = 0;
		/*************************************************************************//*!
				@brief			メモリからメッシュの読み込み
				@param[in]		pName		名前
				@param[in]		pData		メモリアドレス
				@param[in]		Size		サイズ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size) = 0;
		/*************************************************************************//*!
				@brief			メモリからメッシュの読み込み<br>
								メッシュ内部で利用するテクスチャを引数のテクスチャ配列「pTex」から検索をおこなう。<br>
								存在しない場合新規読み込みをおこない、テクスチャ配列に追加する。<br>
								別メッシュで同一テクスチャを複数使用する場合のメモリ節約に活用する。
				@param[in]		pName		名前
				@param[in]		pData		メモリアドレス
				@param[in]		Size		サイズ
				@param[in]		pTex		テクスチャ検索用配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size,LPTextureArray pTex) = 0;
		
		/*************************************************************************//*!
				@brief			メッシュの保存
				@param[in]		pName		ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Save(const LPMofChar pName) = 0;

		/*************************************************************************//*!
				@brief			モーションコントローラーの作成<br>
								内部にボーン情報やアニメーション情報がない場合失敗する
				@param			None
				
				@return			作成したモーションコントローラー<br>
								NULLの場合作成失敗
		*//**************************************************************************/
		virtual LPMeshMotionController CreateMotionController(void) = 0;
		
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		pos				座標
				@param[in]		scl				スケール
				@param[in]		rot				回転
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Vector3& pos, const Vector3& scl, const Vector3& rot) = 0;
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat) = 0;
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col) = 0;
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col,const Vector2& uv) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col,const Vector2& uv) = 0;
		
		
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind) = 0;
		
		
		/*************************************************************************//*!
				@brief			カメラ状態の計算
				@param[in]		pCam		適用カメラ
				@param[in]		t			アニメーション時間
				@param[in]		bLoop		ループ
				@param[in]		pAnim		アニメーション名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CalculateCamera(LPCamera pCam, MofFloat t, MofBool bLoop, LPCMofChar pAnim) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			メッシュリスト取得
				@param			None

				@return			メッシュリスト
		*//**************************************************************************/
		virtual LPMeshArray GetMesh(void) = 0;
		/*************************************************************************//*!
				@brief			メッシュ登録数取得
				@param			None

				@return			メッシュ登録数
		*//**************************************************************************/
		virtual MofU32 GetMeshCount(void) const = 0;
		/*************************************************************************//*!
				@brief			メッシュ取得
				@param[in]		No				メッシュ番号

				@return			メッシュ
								見つからなかった場合NULLを返す
		*//**************************************************************************/
		virtual LPMesh GetMesh(MofU32 No) = 0;
		/*************************************************************************//*!
				@brief			メッシュ取得
				@param[in]		pName			探すメッシュ名

				@return			メッシュ
								見つからなかった場合NULLを返す
		*//**************************************************************************/
		virtual LPMesh GetMesh(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			ジオメトリ登録数取得
				@param			None

				@return			ジオメトリ登録数
		*//**************************************************************************/
		virtual MofU32 GetGeometryCount(void) const = 0;
		/*************************************************************************//*!
				@brief			ジオメトリ取得
				@param[in]		No				ジオメトリ番号

				@return			ジオメトリ
								見つからなかった場合NULLを返す
		*//**************************************************************************/
		virtual LPGeometry GetGeometry(MofU32 No) = 0;
		/*************************************************************************//*!
				@brief			ジオメトリ取得
				@param[in]		pName			探すジオメトリ名

				@return			ジオメトリ
								見つからなかった場合NULLを返す
		*//**************************************************************************/
		virtual LPGeometry GetGeometryByName(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			ボーンリスト取得
				@param			None

				@return			ボーンリスト
		*//**************************************************************************/
		virtual LPBoneArray GetBone(void) = 0;
		/*************************************************************************//*!
				@brief			メッシュアニメーションリスト取得
				@param			None

				@return			メッシュアニメーションリスト
		*//**************************************************************************/
		virtual LPMeshAnimationArray GetAnimation(void) = 0;
		/*************************************************************************//*!
				@brief			剛体情報リスト取得
				@param			None

				@return			剛体情報リスト
		*//**************************************************************************/
		virtual LPPhysicsActorInfoArray GetRigidInfo(void) = 0;
		/*************************************************************************//*!
				@brief			ジョイント情報リスト取得
				@param			None

				@return			ジョイント情報リスト
		*//**************************************************************************/
		virtual LPPhysicsJointInfoArray GetJointInfo(void) = 0;
		/*************************************************************************//*!
				@brief			カメラリスト取得
				@param			None

				@return			カメラリスト
		*//**************************************************************************/
		virtual LPMeshCameraArray GetCamera(void) = 0;
		/*************************************************************************//*!
				@brief			カメラ取得
				@param[in]		pName			探すカメラ名

				@return			カメラ
								見つからなかった場合NULLを返す
		*//**************************************************************************/
		virtual LPMeshCamera GetCamera(LPCMofChar pName) = 0;
	};
	
	//ポインタ置き換え
	typedef IMeshContainer*			LPMeshContainer;
	typedef CDynamicArray< LPMeshContainer >		CMeshContainerArray,*LPMeshContainerArray;
}

#endif	//__MESHCONTAINER__H__

//[EOF]