/*************************************************************************//*!
					
					@file	MeshBase.h
					@brief	メッシュ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHBASE__H__

#define		__MESHBASE__H__

//INCLUDE
#include	"Mesh.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュ基底クラス

			メッシュ基底クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMeshBase : public IMesh {
	protected:
		/*******************//*!
		名前
		*//********************/
		CString						m_Name;
		/*******************//*!
		ジオメトリ
		*//********************/
		LPGeometryArray				m_pGeometry;
		/*******************//*!
		ブロックコンテナ
		*//********************/
		LPBlockContainer			m_pBlockContainer;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CMeshBase();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピージオメトリ

				@return			None
		*//**************************************************************************/
		CMeshBase(const CMeshBase& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CMeshBase();
		
		/*************************************************************************//*!
				@brief			バッファの作成
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CreateBuffer(void);
		
		/*************************************************************************//*!
				@brief			最大・最小計算
				@param[out]		minv			出力用最小
				@param[out]		maxv			出力用最大
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateMinMax(Vector3& minv,Vector3& maxv);
		/*************************************************************************//*!
				@brief			AABB計算
				@param[out]		aabb			出力用ボックス
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateAABB(BoxAABB& aabb);
		/*************************************************************************//*!
				@brief			境界球計算
				@param[out]		sph				出力用球
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool CalculateSphere(Sphere& sph);
		
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				
				@return			TRUE			正常終了<br>
								それ以外			解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				
				@return			TRUE			正常終了<br>
								それ以外			解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col);
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				
				@return			TRUE			正常終了<br>
								それ以外			解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col,const Vector2& uv);
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				
				@return			TRUE			正常終了<br>
								それ以外			解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion);
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				
				@return			TRUE			正常終了<br>
								それ以外			解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col);
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				@param[in]		uv				UV補正
				
				@return			TRUE			正常終了<br>
								それ以外			解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col,const Vector2& uv);
		
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			基本描画
				@param[in]		wMat			変換行列
				@param[in]		col				色補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind);
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
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			アニメーション描画
				@param[in]		pMotion			モーションコントローラ
				@param[in]		col				色補正
				@param[in]		pShader			シェーダー
				@param[in]		pShaderBind		シェーダーバインド
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind);
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
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind);

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
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
				@brief			ジオメトリリスト取得
				@param			None

				@return			ジオメトリリスト
		*//**************************************************************************/
		virtual LPGeometryArray GetGeometry(void);
		/*************************************************************************//*!
				@brief			ブロックリスト取得
				@param			None

				@return			ブロックリスト
		*//**************************************************************************/
		virtual LPBlockContainer GetBlockContainer(void);
		/*************************************************************************//*!
				@brief			ジオメトリ登録数取得
				@param			None

				@return			ジオメトリ登録数
		*//**************************************************************************/
		virtual MofU32 GetGeometryCount(void) const;
		/*************************************************************************//*!
				@brief			ジオメトリ取得
				@param[in]		pName			探すジオメトリ名

				@return			ジオメトリ
								見つからなかった場合NULLを返す
		*//**************************************************************************/
		virtual LPGeometry GetGeometryByName(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			ジオメトリ取得
				@param[in]		No				ジオメトリ番号

				@return			ジオメトリ
								見つからなかった場合NULLを返す
		*//**************************************************************************/
		virtual LPGeometry GetGeometry(MofU32 No);
	};
	
	#include	"MeshBase.inl"
}

#endif	//__MESHBASE__H__

//[EOF]
