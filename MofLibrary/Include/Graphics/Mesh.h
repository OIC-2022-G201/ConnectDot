/*************************************************************************//*!
					
					@file	Mesh.h
					@brief	メッシュ基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESH__H__

#define		__MESH__H__

//INCLUDE
#include	"Geometry.h"
#include	"MeshBlock.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュインターフェイス

			メッシュインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMesh : public IMofNamedObject , public IMofCopyObject< IMesh > {
	private:
	public:
		/*************************************************************************//*!
				@brief			バッファの作成
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CreateBuffer(void) = 0;
		
		/*************************************************************************//*!
				@brief			最大・最小計算
				@param[out]		minv			出力用最小
				@param[out]		maxv			出力用最大
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateMinMax(Vector3& minv,Vector3& maxv) = 0;
		/*************************************************************************//*!
				@brief			AABB計算
				@param[out]		aabb			出力用ボックス
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateAABB(BoxAABB& aabb) = 0;
		/*************************************************************************//*!
				@brief			境界球計算
				@param[out]		sph				出力用球
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateSphere(Sphere& sph) = 0;
		
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
								それ以外			解放エラー、エラーコードを返す。
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


		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ジオメトリリスト取得
				@param			None

				@return			ジオメトリリスト
		*//**************************************************************************/
		virtual LPGeometryArray GetGeometry(void) = 0;
		/*************************************************************************//*!
				@brief			ブロックリスト取得
				@param			None

				@return			ブロックリスト
		*//**************************************************************************/
		virtual LPBlockContainer GetBlockContainer(void) = 0;
		/*************************************************************************//*!
				@brief			ジオメトリ登録数取得
				@param			None

				@return			ジオメトリ登録数
		*//**************************************************************************/
		virtual MofU32 GetGeometryCount(void) const = 0;
		/*************************************************************************//*!
				@brief			ジオメトリ取得
				@param[in]		pName			探すジオメトリ名

				@return			ジオメトリ
								見つからなかった場合NULLを返す
		*//**************************************************************************/
		virtual LPGeometry GetGeometryByName(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			ジオメトリ取得
				@param[in]		No				ジオメトリ番号

				@return			ジオメトリ
								見つからなかった場合NULLを返す
		*//**************************************************************************/
		virtual LPGeometry GetGeometry(MofU32 No) = 0;
	};
	
	//ポインタ置き換え
	typedef IMesh*				LPMesh;
	typedef CDynamicArray< LPMesh >		CMeshArray,*LPMeshArray;
}

#endif	//__MESH__H__

//[EOF]