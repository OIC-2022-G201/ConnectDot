/*************************************************************************//*!
					
					@file	GraphicsUtilities.h
					@brief	描画関連の汎用処理をまとめたスタティッククラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GRAPHICSUTILITIES__H__

#define		__GRAPHICSUTILITIES__H__

//INCLUDE
#include	"../Graphics/Graphics.h"

#include	"../Graphics/Geometry.h"
#include	"../Graphics/GeometryInstancedBase.h"

#include	"../Graphics/CameraBase.h"
#include	"../Graphics/DirectionalLight.h"

#include	"../Graphics/Shader.h"
#include	"../Graphics/ShaderBindBase.h"
#include	"../Graphics/ShaderEffect.h"

#include	"../Graphics/Font.h"
#include	"../Graphics/Sprite2DContainer.h"
#include	"../Graphics/Sprite3D.h"
#include	"../Graphics/SpriteMotionController.h"

#include	"../Graphics/RenderCommandProxy.h"

namespace Mof {

	/*******************************//*!
	@brief	描画関連の汎用処理をまとめたスタティッククラス

			描画関連の汎用処理をまとめたスタティッククラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGraphicsUtilities {
	private:
		/*******************//*!
		描画用グラフィックス
		*//********************/
		static LPGraphics			m_pGraphics;
		/*******************//*!
		マルチスレッド用プロキシ
		*//********************/
		static LPRenderCommandProxy m_pCommandProxy;
		/*******************//*!
		描画用カメラ
		*//********************/
		static LPCamera				m_pCamera;
		/*******************//*!
		描画用基本ライト
		*//********************/
		static LPDirectionalLight	m_pDirectionalLight;
	public:
		/*************************************************************************//*!
				@brief			描画用基礎データを作成する<br>
								IGraphicsクラスを継承したグラフィックスクラスの初期化時に実行される。<br>
								この関数の実行前にクラス内の関数を実行しないこと。
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool CreateUtilities(void);
		/*************************************************************************//*!
				@brief			描画用基礎データを破棄する
								IGraphicsクラスを継承したグラフィックスクラスの解放時に実行される。<br>
								この関数の実行後にクラス内の関数を実行しないこと。
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool ReleaseUtilities(void);

		//----------------------------------------------------------------------------
		////プリミティブの生成
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			プリミティブを作成する<br>
								基本の頂点配列の指定のみで頂点バッファの生成をおこない、
								インデックスバッファはトライアングルリストで自動生成する。
				@param[in]		pv			頂点配列
				@param[in]		vcnt		頂点配列の数
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateGeometry(DefaultGeometryVertex* pv, MofU32 vcnt, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			プリミティブを作成する<br>
								基本の頂点配列とインデックス配列でバッファの生成をおこなう。
				@param[in]		pv			頂点配列
				@param[in]		vf			頂点要素フラグ(VertexFlag列挙体の組み合わせで指定)
				@param[in]		vcnt		頂点配列の数
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateGeometry(LPCMofVoid pv, MofU32 vf, MofU32 vcnt, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			プリミティブを作成する<br>
								基本の頂点配列とインデックス配列でバッファの生成をおこなう。
				@param[in]		pv			頂点配列
				@param[in]		vcnt		頂点配列の数
				@param[in]		pi			インデックス配列
				@param[in]		icnt		インデックス配列の数
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateGeometry(DefaultGeometryVertex* pv, MofU32 vcnt, MofU16* pi, MofU32 icnt, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			プリミティブを作成する<br>
								基本の頂点配列とインデックス配列でバッファの生成をおこなう。
				@param[in]		pv			頂点配列
				@param[in]		vf			頂点要素フラグ(VertexFlag列挙体の組み合わせで指定)
				@param[in]		vcnt		頂点配列の数
				@param[in]		pi			インデックス配列
				@param[in]		icnt		インデックス配列の数
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateGeometry(LPCMofVoid pv, MofU32 vf, MofU32 vcnt, MofU16* pi, MofU32 icnt, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);

		/*************************************************************************//*!
				@brief			線プリミティブを作成する
				@param[in]		c			分割数
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateLineGeometry(MofU32 c = 1, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			線プリミティブを作成する
				@param[in]		c			分割数
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateLine3DGeometry(MofU32 c = 1, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			線矩形プリミティブを作成する
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateLineRectGeometry(BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			矩形プリミティブを作成する
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateRectGeometry(BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			線円形プリミティブを作成する
				@param[in]		c			分割数
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateLineCircleGeometry(MofU32 c = 36, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			円形プリミティブを作成する
				@param[in]		c			分割数
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateCircleGeometry(MofU32 c = 36, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			三角形プリミティブを作成する
				@param[in]		w			幅
				@param[in]		d			奥行
				@param[in]		sw			横分割
				@param[in]		sd			奥分割
				@param[in]		bRev		両面フラグ
				@param[in]		cp			中心座標
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateTriangleGeometry(BufferAccess VUsage, BufferAccess IUsage);
		/*************************************************************************//*!
				@brief			平面プリミティブを作成する
				@param[in]		w			幅
				@param[in]		d			奥行
				@param[in]		sw			横分割
				@param[in]		sd			奥分割
				@param[in]		bRev		両面フラグ
				@param[in]		cp			中心座標
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreatePlaneGeometry(MofFloat w, MofFloat d, MofU32 sw, MofU32 sd, MofBool bRev, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			箱プリミティブを作成する
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		d			奥行
				@param[in]		sw			横分割
				@param[in]		sh			縦分割
				@param[in]		sd			奥分割
				@param[in]		cp			中心座標
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateBoxGeometry(MofFloat w, MofFloat h, MofFloat d, MofU32 sw, MofU32 sh, MofU32 sd, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			箱プリミティブを作成する
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		d			奥行
				@param[in]		sw			横分割
				@param[in]		sh			縦分割
				@param[in]		sd			奥分割
				@param[in]		cp			中心座標
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateLineBoxGeometry(MofFloat w, MofFloat h, MofFloat d, MofU32 sw, MofU32 sh, MofU32 sd, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			球プリミティブを作成する
				@param[in]		r			半径
				@param[in]		s			分割
				@param[in]		cp			中心座標
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateSphereGeometry(MofFloat r, MofU32 s, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			球プリミティブを作成する
				@param[in]		r			半径
				@param[in]		s			分割
				@param[in]		cp			中心座標
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateLineSphereGeometry(MofFloat r, MofU32 s, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			円柱プリミティブを作成する
				@param[in]		r			半径
				@param[in]		h			高さ
				@param[in]		s			分割
				@param[in]		sh			縦分割
				@param[in]		cp			中心座標
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateCylinderGeometry(MofFloat r, MofFloat h, MofU32 s, MofU32 sh, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			カプセルプリミティブを作成する
				@param[in]		r			半径
				@param[in]		h			高さ
				@param[in]		s			分割
				@param[in]		sh			縦分割
				@param[in]		cp			中心座標
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateCapsuleGeometry(MofFloat r, MofFloat h, MofU32 s, MofU32 sh, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			コーンプリミティブを作成する
				@param[in]		r			半径
				@param[in]		h			高さ
				@param[in]		s			分割
				@param[in]		sh			縦分割
				@param[in]		cp			中心座標
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry CreateConeGeometry(MofFloat r, MofFloat h, MofU32 s, MofU32 sh, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		
		/*************************************************************************//*!
				@brief			スプライトプリミティブを作成する
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry Create2DSpriteGeometry(BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			スプライトプリミティブを作成する
				@param[in]		VUsage		頂点管理方法
				@param[in]		IUsage		インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometry Create3DSpriteGeometry(BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		
		/*************************************************************************//*!
				@brief			スプライトプリミティブを作成する
				@param[in]		InstanceCount	インスタンス最大数
				@param[in]		VUsage			頂点管理方法
				@param[in]		IUsage			インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometryInstanced Create2DSpriteGeometryInstanced(MofU32 InstanceCount, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			スプライトプリミティブを作成する
				@param[in]		InstanceFlag	インスタンスフラグ
				@param[in]		InstanceCount	インスタンス最大数
				@param[in]		VUsage			頂点管理方法
				@param[in]		IUsage			インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometryInstanced Create2DSpriteGeometryInstanced(VertexFlag InstanceFlag, MofU32 InstanceCount, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			スプライトプリミティブを作成する
				@param[in]		InstanceCount	インスタンス最大数
				@param[in]		VUsage			頂点管理方法
				@param[in]		IUsage			インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometryInstanced Create3DSpriteGeometryInstanced(MofU32 InstanceCount, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			スプライトプリミティブを作成する
				@param[in]		InstanceFlag	インスタンスフラグ
				@param[in]		InstanceCount	インスタンス最大数
				@param[in]		VUsage			頂点管理方法
				@param[in]		IUsage			インデックス管理方法

				@return			生成したジオメトリ<br>
								失敗した場合NULL
		*//**************************************************************************/
		static LPGeometryInstanced Create3DSpriteGeometryInstanced(VertexFlag InstanceFlag, MofU32 InstanceCount, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);

		//----------------------------------------------------------------------------
		////描画
		//----------------------------------------------------------------------------
				
		//----------------------------------------------------------------------------
		////プリミティブの描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			プリミティブの描画
				@param[in]		prp			描画パラメーター
				@param[in]		pShader		シェーダー
				@param[in]		pBind		バインダ
				@param[in]		pGeom		ジオメトリ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderPrimitive(PrimitiveRenderParameter& prp, LPShader pShader, LPShaderBind pBind, LPGeometry pGeom);

		//----------------------------------------------------------------------------
		////線の描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			線の描画
				@param[in]		sv			開始位置
				@param[in]		ev			終了位置
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLine(const Vector2& sv,const Vector2& ev,MofU32 col);
		/*************************************************************************//*!
				@brief			線の描画
				@param[in]		sv			開始位置
				@param[in]		ev			終了位置
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLine(const Vector3& sv,const Vector3& ev,MofU32 col);
		/*************************************************************************//*!
				@brief			線の描画
				@param[in]		sx			開始位置X
				@param[in]		sy			開始位置Y
				@param[in]		ex			終了位置X
				@param[in]		ey			終了位置Y
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLine(MofFloat sx,MofFloat sy,MofFloat ex,MofFloat ey,MofU32 col);
		/*************************************************************************//*!
				@brief			線の描画
				@param[in]		sx			開始位置X
				@param[in]		sy			開始位置Y
				@param[in]		sz			開始位置Z
				@param[in]		ex			終了位置X
				@param[in]		ey			終了位置Y
				@param[in]		ez			終了位置Z
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLine(MofFloat sx, MofFloat sy, MofFloat sz, MofFloat ex, MofFloat ey, MofFloat ez, MofU32 col);
		
		/*************************************************************************//*!
				@brief			グリッドの描画
				@param[in]		bet			間隔
				@param[in]		s			サイズ
				@param[in]		col			描画色
				@param[in]		plane		表示平面
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGrid(MofFloat bet, MofFloat s, MofU32 col, PlaneAxis plane);
		/*************************************************************************//*!
				@brief			グリッドの描画
				@param[in]		cp			中心
				@param[in]		bet			間隔
				@param[in]		s			サイズ
				@param[in]		col			描画色
				@param[in]		plane		表示平面
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGrid(const Vector3& cp, MofFloat bet, MofFloat s, MofU32 col, PlaneAxis plane);

		//----------------------------------------------------------------------------
		////矩形の描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			矩形の描画
				@param[in]		rec			矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRect(const Rectangle& rec,MofU32 col);
		/*************************************************************************//*!
				@brief			矩形の描画
				@param[in]		l			左
				@param[in]		t			上
				@param[in]		r			右
				@param[in]		b			下
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b,MofU32 col);
				
		/*************************************************************************//*!
				@brief			塗りつぶし矩形の描画
				@param[in]		rec			矩形
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillRect(const Rectangle& rec,MofU32 col);
		/*************************************************************************//*!
				@brief			塗りつぶし矩形の描画
				@param[in]		rec			矩形
				@param[in]		ltc			左上描画色
				@param[in]		lbc			左下描画色
				@param[in]		rtc			右上描画色
				@param[in]		rbc			右下描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillRect(const Rectangle& rec,MofU32 ltc,MofU32 lbc,MofU32 rtc,MofU32 rbc);
		/*************************************************************************//*!
				@brief			塗りつぶし矩形の描画
				@param[in]		l			左
				@param[in]		t			上
				@param[in]		r			右
				@param[in]		b			下
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b,MofU32 col);
		/*************************************************************************//*!
				@brief			塗りつぶし矩形の描画
				@param[in]		l			左
				@param[in]		t			上
				@param[in]		r			右
				@param[in]		b			下
				@param[in]		ltc			左上描画色
				@param[in]		lbc			左下描画色
				@param[in]		rtc			右上描画色
				@param[in]		rbc			右下描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b,MofU32 ltc,MofU32 lbc,MofU32 rtc,MofU32 rbc);

		//----------------------------------------------------------------------------
		////円の描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			円の描画
				@param[in]		c			描画円
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderCircle(const Circle& c,MofU32 col);
		/*************************************************************************//*!
				@brief			円の描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		r			描画半径
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderCircle(MofFloat px,MofFloat py,MofFloat r,MofU32 col);
		
		/*************************************************************************//*!
				@brief			塗りつぶし円の描画
				@param[in]		c			描画円
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillCircle(const Circle& c,MofU32 col);
		/*************************************************************************//*!
				@brief			塗りつぶし円の描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		r			描画半径
				@param[in]		col			描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillCircle(MofFloat px,MofFloat py,MofFloat r,MofU32 col);
		/*************************************************************************//*!
				@brief			塗りつぶし円の描画
				@param[in]		c			描画円
				@param[in]		Ccol		中心描画色
				@param[in]		Ocol		外周描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillCircle(const Circle& c,MofU32 Ccol,MofU32 Ocol);
		/*************************************************************************//*!
				@brief			塗りつぶし円の描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		r			描画半径
				@param[in]		Ccol		中心描画色
				@param[in]		Ocol		外周描画色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillCircle(MofFloat px,MofFloat py,MofFloat r,MofU32 Ccol,MofU32 Ocol);

		/*************************************************************************//*!
				@brief			塗りつぶし円弧の描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		r			描画半径
				@param[in]		sang		描画開始角度
				@param[in]		eang		描画終了角度
				@param[in]		Ccol		中心描画色
				@param[in]		Ocol		外周描画色

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillArc(MofFloat px, MofFloat py, MofFloat r, MofFloat sang, MofFloat eang, MofU32 Ccol, MofU32 Ocol);

		//----------------------------------------------------------------------------
		////三角形の描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			塗りつぶし三角形の描画
				@param[in]		t			三角形の上の点
				@param[in]		rb			三角形の右下の点
				@param[in]		lb			三角形の左下の点
				@param[in]		tc			三角形の上の点の色
				@param[in]		rbc			三角形の右下の点の色
				@param[in]		lbc			三角形の左下の点の色

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillTriangle(Vector2& t, Vector2& rb, Vector2& lb, MofU32 tc, MofU32 rbc, MofU32 lbc);

		//----------------------------------------------------------------------------
		////四角形の描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			塗りつぶし四角形の描画
				@param[in]		lt			四角形の左上の点
				@param[in]		lb			四角形の左下の点
				@param[in]		rt			四角形の右上の点
				@param[in]		rb			四角形の右下の点
				@param[in]		ltc			四角形の左上の点の色
				@param[in]		lbc			四角形の左下の点の色
				@param[in]		rtc			四角形の右上の点の色
				@param[in]		rbc			四角形の右下の点の色

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderFillQuad(Vector2& lt, Vector2& lb, Vector2& rt, Vector2& rb, MofU32 ltc, MofU32 lbc, MofU32 rtc, MofU32 rbc);

		//----------------------------------------------------------------------------
		////平面の描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D平面の描画
				@param[in]		wMat		変換行列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderPlane(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D平面の描画
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderPlane(const Matrix44& wMat, const Vector4& col);
		
		//----------------------------------------------------------------------------
		////箱の描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D箱の描画<br>
								箱を構成する辺の線のみ描画をおこなう。
				@param[in]		b			AABB
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLineBox(const BoxAABB& b);
		/*************************************************************************//*!
				@brief			3D箱の描画<br>
								箱を構成する辺の線のみ描画をおこなう。
				@param[in]		b			OBB
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLineBox(const BoxOBB& b);
		/*************************************************************************//*!
				@brief			3D箱の描画<br>
								箱を構成する辺の線のみ描画をおこなう。
				@param[in]		wMat		変換行列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLineBox(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D箱の描画<br>
								箱を構成する辺の線のみ描画をおこなう。
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLineBox(const Matrix44& wMat, const Vector4& col);

		/*************************************************************************//*!
				@brief			3D箱の描画
				@param[in]		b			AABB
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderBox(const BoxAABB& b);
		/*************************************************************************//*!
				@brief			3D箱の描画
				@param[in]		b			AABB
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderBox(const BoxAABB& b, const Vector4& col);
		/*************************************************************************//*!
				@brief			3D箱の描画
				@param[in]		b			OBB
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderBox(const BoxOBB& b);
		/*************************************************************************//*!
				@brief			3D箱の描画
				@param[in]		b			OBB
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderBox(const BoxOBB& b, const Vector4& col);
		/*************************************************************************//*!
				@brief			3D箱の描画
				@param[in]		wMat		変換行列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderBox(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D箱の描画
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderBox(const Matrix44& wMat, const Vector4& col);

		//----------------------------------------------------------------------------
		////球の描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D球の描画<br>
								球のX,Y,Z軸の線のみ描画をおこなう。
				@param[in]		s			球体
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLineSphere(const Sphere& s);
		/*************************************************************************//*!
				@brief			3D球の描画<br>
								球のX,Y,Z軸の線のみ描画をおこなう。
				@param[in]		s			球体
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLineSphere(const Sphere& s, const Vector4& col);
		/*************************************************************************//*!
				@brief			3D球の描画<br>
								球のX,Y,Z軸の線のみ描画をおこなう。
				@param[in]		wMat		変換行列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLineSphere(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D球の描画<br>
								球のX,Y,Z軸の線のみ描画をおこなう。
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderLineSphere(const Matrix44& wMat, const Vector4& col);

		/*************************************************************************//*!
				@brief			3D球の描画
				@param[in]		s			球体
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderSphere(const Sphere& s);
		/*************************************************************************//*!
				@brief			3D球の描画
				@param[in]		s			球体
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderSphere(const Sphere& s,const Vector4& col);
		/*************************************************************************//*!
				@brief			3D球の描画
				@param[in]		wMat		変換行列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderSphere(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D球の描画
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderSphere(const Matrix44& wMat, const Vector4& col);

		//----------------------------------------------------------------------------
		////円柱の描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D円柱の描画
				@param[in]		wMat		変換行列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderCylinder(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D円柱の描画
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderCylinder(const Matrix44& wMat, const Vector4& col);

		//----------------------------------------------------------------------------
		////カプセルの描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3Dカプセルの描画
				@param[in]		wMat		変換行列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderCapsule(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3Dカプセルの描画
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderCapsule(const Matrix44& wMat, const Vector4& col);

		//----------------------------------------------------------------------------
		////コーンの描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3Dコーンの描画
				@param[in]		wMat		変換行列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderCone(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3Dコーンの描画
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderCone(const Matrix44& wMat, const Vector4& col);
		
		//----------------------------------------------------------------------------
		////ジオメトリの描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ジオメトリの描画
				@param[in]		wMat		変換行列
				@param[in]		pGeom		ジオメトリ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGeometry(const Matrix44& wMat,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			ジオメトリの描画
				@param[in]		wMat		変換行列
				@param[in]		pGeom		ジオメトリ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGeometry(const Matrix44& wMat, LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			ジオメトリの描画
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				@param[in]		uv			UV補正
				@param[in]		pGeom		ジオメトリ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGeometry(const Matrix44& wMat,const Vector4& col,const Vector2& uv,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			ジオメトリの描画
				@param[in]		wMat		変換行列
				@param[in]		col			色補正
				@param[in]		uv			UV補正
				@param[in]		pGeom		ジオメトリ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGeometry(const Matrix44& wMat, const Vector4& col, const Vector2& uv, LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			ジオメトリの描画
				@param[in]		pMotion		モーションコントローラ
				@param[in]		pGeom		ジオメトリ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGeometry(LPMeshMotionController pMotion,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			ジオメトリの描画
				@param[in]		pMotion		モーションコントローラ
				@param[in]		pGeom		ジオメトリ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGeometry(LPMeshMotionController pMotion, LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			ジオメトリの描画
				@param[in]		pMotion		モーションコントローラ
				@param[in]		col			色補正
				@param[in]		uv			UV補正
				@param[in]		pGeom		ジオメトリ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGeometry(LPMeshMotionController pMotion,const Vector4& col,const Vector2& uv,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			ジオメトリの描画
				@param[in]		pMotion		モーションコントローラ
				@param[in]		col			色補正
				@param[in]		uv			UV補正
				@param[in]		pGeom		ジオメトリ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGeometry(LPMeshMotionController pMotion, const Vector4& col, const Vector2& uv, LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			ジオメトリの描画
				@param[in]		pGeom		ジオメトリ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderGeometry(LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);

		//----------------------------------------------------------------------------
		////テクスチャの描画
		////座標指定での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);



		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
				
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pTex		テクスチャ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px, MofFloat py, const Rectangle& srec, MofU32 col, TextureAlignment Alignment, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px				描画X座標
				@param[in]		py				描画Y座標
				@param[in]		pTex			テクスチャ
				@param[in]		pShaderEffect	シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,LPTexture pTex,LPShaderEffect pShaderEffect);

		//----------------------------------------------------------------------------
		////テクスチャの描画
		////出力矩形への描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		alpha		描画不透明度
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,MofFloat alpha,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		pTex		テクスチャ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,MofU32 col,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);


		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		srec		画像表示矩形
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		srec		画像表示矩形
				@param[in]		pTex		テクスチャ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec, const Rectangle& srec, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		drec		描画矩形
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec, const Rectangle& srec, MofU32 col, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind);

		//----------------------------------------------------------------------------
		////テクスチャの描画
		////拡大倍率指定での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,MofU32 col,TextureAlignment Alignment,LPTexture pTex);


		
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,TextureAlignment Alignment,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);
				


		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);



		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				@param[in]		pShader		シェーダー
				@param[in]		pShaderBind	シェーダーバインド

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px, MofFloat py, MofFloat sx, MofFloat sy, const Rectangle& srec, MofU32 col, TextureAlignment Alignment, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind);
				
		//----------------------------------------------------------------------------
		////テクスチャの描画
		////回転角度指定での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,TextureAlignment Alignment,LPTexture pTex);


				
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);

		//----------------------------------------------------------------------------
		////テクスチャの描画
		////拡大倍率、回転角度指定での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,TextureAlignment Alignment,LPTexture pTex);



		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		s			拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pz			描画Z座標
				@param[in]		sx			Ｘ拡大倍率
				@param[in]		sy			Ｙ拡大倍率
				@param[in]		ang			回転角度
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat pz,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
				
		//----------------------------------------------------------------------------
		////テクスチャの描画
		////2D空間での行列での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Pivot		アライメント位置
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec,MofU32 col,const Vector3& Pivot,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		Pivot		アライメント位置
				@param[in]		Size		サイズ
				@param[in]		uvp			UV移動
				@param[in]		uvs			UV拡大
				@param[in]		uva			UV回転
				@param[in]		vpos		頂点移動
				@param[in]		vcol		頂点カラー
				@param[in]		vcolr		頂点カラーレート
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec, const Vector4& col,const Vector3& Pivot, const Vector3& Size, const Vector2& uvp, const Vector2& uvs,const MofFloat uva,LPVector2 vpos, LPVector4 vcol, MofFloat vcolr,LPTexture pTex);

		//----------------------------------------------------------------------------
		////テクスチャの描画
		////3D空間での行列での描画
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		col			描画色
				@param[in]		bRatio		比率維持フラグ
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,MofU32 col,MofBool bRatio,LPTexture pTex);
		
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		wMat		変換行列
				@param[in]		srec		画像表示矩形
				@param[in]		col			描画色
				@param[in]		bRatio		比率維持フラグ
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec,MofU32 col,MofBool bRatio,LPTexture pTex);
		
		/*************************************************************************//*!
				@brief			テクスチャの描画
				@param[in]		trp			描画パラメーター
				@param[in]		pShader		シェーダー
				@param[in]		pBind		バインダ
				@param[in]		pGeom		ジオメトリ
				@param[in]		pTex		テクスチャ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderTexture(TextureRenderParameter& trp, LPShader pShader, LPShaderBind pBind, LPGeometry pGeom, LPTexture pTex);

		//----------------------------------------------------------------------------
		////フォントの描画
		////内部で生成したデフォルトのフォントで描画を行う
		////デフォルトフォントはMSゴシックの24ptで作成される
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderString(MofFloat px, MofFloat py, LPCMofChar pText, ...);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderString(MofFloat px, MofFloat py, MofU32 col, LPCMofChar pText, ...);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderString(Rectangle& drec, LPCMofChar pText, ...);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		col			描画色
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool RenderString(Rectangle& drec, MofU32 col, LPCMofChar pText, ...);

		/*************************************************************************//*!
				@brief			文字描画矩形の計算
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pText		描画文字列
				@param[out]		Out			出力矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		static MofBool CalculateStringRect(MofFloat px,MofFloat py,LPCMofChar pText,Rectangle& Out);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			描画用グラフィックスを設定する
				@param[in]		pg				グラフィックス

				@return			None
		*//**************************************************************************/
		static void SetGraphics(LPGraphics pg);
		/*************************************************************************//*!
				@brief			描画用グラフィックスコマンドプロキシを設定する
				@param[in]		pg				グラフィックスコマンドプロキシ

				@return			None
		*//**************************************************************************/
		static void SetCommandProxy(LPRenderCommandProxy pg);
		/*************************************************************************//*!
				@brief			描画用画面サイズを設定する
				@param[in]		sw				幅
				@param[in]		sh				高さ

				@return			None
		*//**************************************************************************/
		static MofBool SetScreenSize(MofS32 sw,MofS32 sh);
		/*************************************************************************//*!
				@brief			描画用画面サイズを設定する
				@param[in]		sw				幅
				@param[in]		sh				高さ
				@param[in]		pBind			バインド

				@return			None
		*//**************************************************************************/
		static MofBool SetScreenSize(MofS32 sw,MofS32 sh,LPShaderBind pBind);
		/*************************************************************************//*!
				@brief			描画用カメラを設定する
				@param[in]		pc				カメラ

				@return			None
		*//**************************************************************************/
		static void SetCamera(LPCamera pc);
		/*************************************************************************//*!
				@brief			描画用基本ライトを設定する
				@param[in]		pl				ライト

				@return			None
		*//**************************************************************************/
		static void SetDirectionalLight(LPDirectionalLight pl);
		/*************************************************************************//*!
				@brief			基本フォントの基本色設定
				@param[in]		c				色
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		static MofBool SetDefaultFontColor(MofU32 c);
		/*************************************************************************//*!
				@brief			3Dプリミティブ描画用シェーダーの設定
				@param[in]		p3DPrimitiveShader		3Dプリミティブ描画用シェーダー
				@param[in]		p3DPrimitiveBind		3Dプリミティブ描画用バインド
				
				@return			None
		*//**************************************************************************/
		static MofBool Set3DPrimitiveShader(LPShader p3DPrimitiveShader, LPShaderBind p3DPrimitiveBind);
		/*************************************************************************//*!
				@brief			3Dスキニング描画用シェーダーの設定
				@param[in]		pSkinGeometryShader		3Dスキニング描画用シェーダー
				@param[in]		pSkinGeometryBind		3Dスキニング描画用バインド
				
				@return			None
		*//**************************************************************************/
		static MofBool SetSkinGeometryShader(LPShader pSkinGeometryShader, LPShaderBind pSkinGeometryBind);
		/*************************************************************************//*!
				@brief			3Dプリミティブ描画用シェーダーの設定
				@param[in]		p3DPrimitiveShader		3Dプリミティブ描画用シェーダー
				@param[in]		p3DPrimitiveBind		3Dプリミティブ描画用バインド
				
				@return			None
		*//**************************************************************************/
		static MofBool Set3DPrimitiveShaderImpl(LPShader p3DPrimitiveShader, LPShaderBind p3DPrimitiveBind);
		/*************************************************************************//*!
				@brief			3Dスキニング描画用シェーダーの設定
				@param[in]		pSkinGeometryShader		3Dスキニング描画用シェーダー
				@param[in]		pSkinGeometryBind		3Dスキニング描画用バインド
				
				@return			None
		*//**************************************************************************/
		static MofBool SetSkinGeometryShaderImpl(LPShader pSkinGeometryShader, LPShaderBind pSkinGeometryBind);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			描画用グラフィックスを取得する
				@param			None

				@return			描画用グラフィックス
		*//**************************************************************************/
		static LPGraphics GetGraphics(void);
		/*************************************************************************//*!
				@brief			描画用グラフィックスコマンドプロキシを取得する
				@param			None

				@return			描画用グラフィックスコマンドプロキシ
		*//**************************************************************************/
		static LPRenderCommandProxy GetCommandProxy(void);
		/*************************************************************************//*!
				@brief			描画用カメラを取得する
				@param			None

				@return			描画用カメラ
		*//**************************************************************************/
		static LPCamera GetCamera(void);
		/*************************************************************************//*!
				@brief			描画用基本ライトを取得する
				@param			None

				@return			描画用基本ライト
		*//**************************************************************************/
		static LPDirectionalLight GetDirectionalLight(void);
		/*************************************************************************//*!
				@brief			デフォルトテクスチャを取得する
				@param			None

				@return			描画用カメラ
		*//**************************************************************************/
		static LPTexture GetDefaultTexture(void);
		/*************************************************************************//*!
				@brief			2Dプリミティブ描画用シェーダーを取得する
				@param			None

				@return			2Dプリミティブ描画用シェーダー
		*//**************************************************************************/
		static LPShader Get2DPrimitiveShader(void);
		/*************************************************************************//*!
				@brief			2Dプリミティブ描画用シェーダーを取得する
				@param			None

				@return			2Dプリミティブ描画用シェーダー
		*//**************************************************************************/
		static LPShaderBind Get2DPrimitiveBind(void);
		/*************************************************************************//*!
				@brief			2Dスプライト描画用シェーダーを取得する
				@param			None

				@return			2Dスプライト描画用シェーダー
		*//**************************************************************************/
		static LPShader Get2DSpriteShader(void);
		/*************************************************************************//*!
				@brief			2Dスプライト描画用シェーダーを取得する
				@param			None

				@return			2Dスプライト描画用シェーダー
		*//**************************************************************************/
		static LPShaderBind Get2DSpriteBind(void);
		/*************************************************************************//*!
				@brief			3Dプリミティブ描画用シェーダーを取得する
				@param			None

				@return			3Dプリミティブ描画用シェーダー
		*//**************************************************************************/
		static LPShader Get3DPrimitiveShader(void);
		/*************************************************************************//*!
				@brief			3Dプリミティブ描画用シェーダーを取得する
				@param			None

				@return			3Dプリミティブ描画用シェーダー
		*//**************************************************************************/
		static LPShaderBind Get3DPrimitiveBind(void);
		/*************************************************************************//*!
				@brief			3Dスプライト描画用シェーダーを取得する
				@param			None

				@return			3Dスプライト描画用シェーダー
		*//**************************************************************************/
		static LPShader Get3DSpriteShader(void);
		/*************************************************************************//*!
				@brief			3Dスプライト描画用シェーダーを取得する
				@param			None

				@return			3Dスプライト描画用シェーダー
		*//**************************************************************************/
		static LPShaderBind Get3DSpriteBind(void);
		/*************************************************************************//*!
				@brief			3Dスキニング描画用シェーダーを取得する
				@param			None

				@return			3Dスキニング描画用シェーダー
		*//**************************************************************************/
		static LPShader GetSkinGeometryShader(void);
		/*************************************************************************//*!
				@brief			3Dスキニング描画用シェーダーを取得する
				@param			None

				@return			3Dスキニング描画用シェーダー
		*//**************************************************************************/
		static LPShaderBind GetSkinGeometryBind(void);

	private:
		//作成を禁止する
		CGraphicsUtilities(){};
		CGraphicsUtilities(const CGraphicsUtilities& pObj){};
	};
					
	#include	"GraphicsUtilities.inl"
}

#endif

//[EOF]