/*************************************************************************//*!
					
					@file	RenderCommandProxy.h
					@brief	描画コマンドクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__RENDERCOMMANDPROXY__H__

#define		__RENDERCOMMANDPROXY__H__

//INCLUDE
#include	"RenderThread.h"
#include	"../Graphics/Shader.h"
#include	"../Graphics/ShaderBindBase.h"

namespace Mof {

	/*******************************//*!
	@brief	描画コマンドクラス

			描画コマンド。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRenderCommandProxy : public IMofBase {
	protected:
		/*******************//*!
		コマンドフラッシュスレッド
		*//********************/
		LPRenderThread						m_pRenderThread;
		/*******************//*!
		コマンド追加リスト
		*//********************/
		LPRenderCommandList					m_pCommandList;
		/*******************//*!
		コマンド実行前のステータス保存
		*//********************/
		GRAPHICSSTATUS						m_ProxyStatus;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CRenderCommandProxy();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pThread		描画スレッド

				@return			None
		*//**************************************************************************/
		CRenderCommandProxy(LPRenderThread pThread);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param[in]		None

				@return			None
		*//**************************************************************************/
		virtual ~CRenderCommandProxy(void);
		
		/*************************************************************************//*!
				@brief			転送用コマンドリストの作成
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateCommandList(void);

		/*************************************************************************//*!
				@brief			コマンドのフラッシュ
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CommandFlush(void);
		
		/*************************************************************************//*!
				@brief			保存状態の設定
				@param[in]		st			設定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetStatus(const GRAPHICSSTATUS& st);
		
		/*************************************************************************//*!
				@brief			現在の描画ターゲット取得
				@param[out]		None
				
				@return			現在の描画ターゲット
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTarget(void);
		/*************************************************************************//*!
				@brief			指定した番号の描画ターゲット取得
				@param[in]		index		
				
				@return			現在の描画ターゲット
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTargetAt(MofU32 index);
		/*************************************************************************//*!
				@brief			現在の描画ターゲット数を取得
				@param			None
				
				@return			現在の描画ターゲット数
		*//**************************************************************************/
		virtual MofU32 GetRenderTargetCount(void);
		/*************************************************************************//*!
				@brief			現在の深度ターゲット取得
				@param[out]		None
				
				@return			現在の深度ターゲット
		*//**************************************************************************/
		virtual LPDepthTarget GetDepthTarget(void);
		/*************************************************************************//*!
				@brief			ブレンドステート取得
				@param[out]		None
				
				@return			現在のブレンドステート
		*//**************************************************************************/
		virtual Blending GetBlending(void);

		//コマンドのインクルード
#define	MOF_RENDERCOMMANDPROXY_INCLUDE
		#include	"RenderCommandProxyImpl.h"
#undef	MOF_RENDERCOMMANDPROXY_INCLUDE

		class MOFLIBRARY_API CShaderBindTextureCommand : public IRenderCommand {
		protected:
			LPShaderBind								m_pBind;
			LPTexture									m_pTexture;
			MofU32										m_No;
		public:
			CShaderBindTextureCommand(LPShaderBind pBind, LPTexture pTex, MofU32 n) : m_pBind(pBind), m_pTexture(pTex), m_No(n) { }
			virtual MofBool Execute(void){ return m_pBind->SetTexture(m_No, m_pTexture); }
		};
		MofBool SetBindTexture(LPShaderBind pBind, LPTexture pTex, MofU32 n){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindTextureCommand >(pBind, pTex, n)) ? TRUE : FALSE); }

		class MOFLIBRARY_API CShaderBindSamplerTypeCommand : public IRenderCommand {
		protected:
			LPShaderBind								m_pBind;
			MofU32										m_SamplerType;
			MofU32										m_No;
		public:
			CShaderBindSamplerTypeCommand(LPShaderBind pBind, MofU32 type, MofU32 n) : m_pBind(pBind), m_SamplerType(type), m_No(n) { }
			virtual MofBool Execute(void){ return m_pBind->SetSamplerType(m_No, m_SamplerType); }
		};
		MofBool SetBindSampler(LPShaderBind pBind, MofU32 type, MofU32 n){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindSamplerTypeCommand >(pBind, type, n)) ? TRUE : FALSE); }

		class MOFLIBRARY_API CShaderBindSamplerStateCommand : public IRenderCommand {
		protected:
			LPShaderBind								m_pBind;
			MofSamplerState								m_pSampler;
			MofU32										m_No;
		public:
			CShaderBindSamplerStateCommand(LPShaderBind pBind, MofSamplerState ps, MofU32 n) : m_pBind(pBind), m_pSampler(ps), m_No(n) { }
			virtual MofBool Execute(void){ return m_pBind->SetSamplerState(m_No, m_pSampler); }
		};
		MofBool SetBindSampler(LPShaderBind pBind, MofSamplerState ps, MofU32 n){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindSamplerStateCommand >(pBind, ps, n)) ? TRUE : FALSE); }

		template < typename T >
		class MOFLIBRARY_API CShaderBindCommand : public IRenderCommand {
		protected:
			LPShaderBind								m_pBind;
			T											m_Data;
			MofU32										m_No;
		public:
			CShaderBindCommand(LPShaderBind pBind, const T& param, MofU32 n) : m_pBind(pBind), m_Data(param), m_No(n) { }
			virtual MofBool Execute(void){ return m_pBind->SetBuffer(m_No, &m_Data); }
		};
		template < typename T > MofBool SetBindBuffer(LPShaderBind pBind, const T& param, MofU32 n){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindCommand< T > >(pBind, param, n)) ? TRUE : FALSE); }

		template < typename B, typename T, typename F >
		class MOFLIBRARY_API CShaderBindFunctionCommand : public IRenderCommand {
		protected:
			B											m_pBind;
			T											m_Data;
			F											m_Func;
		public:
			CShaderBindFunctionCommand(B pBind, const T& param, F func) : m_pBind(pBind), m_Data(param), m_Func(func) { }
			virtual MofBool Execute(void){ (m_pBind->*m_Func)(m_Data); return TRUE; }
		};
		template < typename B, typename T, typename F > MofBool SetBindFunction(B pBind, const T& param, F func){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindFunctionCommand< B, T, F > >(pBind, param, func)) ? TRUE : FALSE); }

		template < typename B, typename T, typename F >
		class MOFLIBRARY_API CShaderBindPointerFunctionCommand : public IRenderCommand {
		protected:
			B											m_pBind;
			T											m_Data;
			F											m_Func;
		public:
			CShaderBindPointerFunctionCommand(B pBind, const T& param, F func) : m_pBind(pBind), m_Data(param), m_Func(func) { }
			virtual MofBool Execute(void){ (m_pBind->*m_Func)(&m_Data); return TRUE; }
		};
		template < typename B, typename T, typename F > MofBool SetBindPointerFunction(B pBind, const T& param, F func){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindPointerFunctionCommand< B, T, F > >(pBind, param, func)) ? TRUE : FALSE); }

		template < typename T >
		class MOFLIBRARY_API CResourceReleaseCommand : public IRenderCommand {
		protected:
			T											m_Data;
		public:
			CResourceReleaseCommand(T& param) : m_Data(param) { }
			virtual MofBool Execute(void){ MOF_SAFE_RELEASE(m_Data); return TRUE; }
		};
		template < typename T > MofBool ResourceRelease(T& param){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CResourceReleaseCommand< T > >(param)) ? TRUE : FALSE); }

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CRenderCommandProxy, MOF_RENDERCOMMANDPROXYCLASS_ID);
	};

	typedef CRenderCommandProxy* LPRenderCommandProxy;

	#include	"RenderCommandProxy.inl"
}

#endif

//[EOF]