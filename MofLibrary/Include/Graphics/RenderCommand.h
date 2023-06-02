/*************************************************************************//*!
					
					@file	RenderCommand.h
					@brief	描画コマンドクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__RENDERCOMMAND__H__

#define		__RENDERCOMMAND__H__

//INCLUDE
#include	"Graphics.h"

//DEFINE
#define		MOFRENDERCOMMAND_DEFAULTSIZE			(1024 * 1024)				//!<コマンドバッファの標準サイズ

namespace Mof {

	/*******************************//*!
	@brief	描画コマンドクラス

			描画コマンド。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IRenderCommand : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			コマンドの実行
				@param			None
				
				@return			None
		*//**************************************************************************/
		virtual MofBool Execute(void) = 0;

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTEQUAL(IRenderCommand, MOF_RENDERCOMMANDCLASS_ID);
	};
	//ポインタ置き換え
	typedef IRenderCommand*				LPRenderCommand;
	
	/*******************************//*!
	@brief	描画コマンドリストクラス

			描画コマンドリスト。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRenderCommandList : public IMofBase {
	protected:
		/*******************//*!
		バッファ
		*//********************/
		LPMofU8					m_pBuffer;
		/*******************//*!
		バッファサイズ
		*//********************/
		MofU32					m_Size;
		/*******************//*!
		バッファオフセット
		*//********************/
		MofU32					m_Offset;
			
		/*************************************************************************//*!
				@brief			コマンド用のメモリ確保
				@param			None

				@return			メモリポインタ
		*//**************************************************************************/
		template< typename T > LPMofVoid AllocateCommandSpace(void);
	public:
		
		/*******************************//*!
		@brief	内部コマンド実行用ポインタ

				内部コマンド実行用ポインタ

		@author	CDW
		*//********************************/
		class MOFLIBRARY_API CCommandPointer {
		private:
			/*******************//*!
			参照位置
			*//********************/
			LPMofU8					m_pPointer;
		public:
			/*************************************************************************//*!
					@brief			コンストラクタ
			*//**************************************************************************/
			CCommandPointer(LPMofU8 pCurrent) : m_pPointer(pCurrent){}
			/*************************************************************************//*!
					@brief			次の位置に移動
			*//**************************************************************************/
			CCommandPointer& operator++(){ size_t size = *reinterpret_cast< MofU32* >(m_pPointer); m_pPointer += sizeof(MofU32) + size; return *this; }
			/*************************************************************************//*!
					@brief			内部コマンドへのアクセス
			*//**************************************************************************/
			LPRenderCommand operator->(){ return reinterpret_cast< LPRenderCommand >(m_pPointer + sizeof(MofU32)); }
			/*************************************************************************//*!
					@brief			内部コマンドへのアクセス
			*//**************************************************************************/
			void operator() (){ reinterpret_cast< LPRenderCommand >(m_pPointer + sizeof(MofU32))->Execute(); }
			/*************************************************************************//*!
					@brief			ポインタ比較
			*//**************************************************************************/
			bool operator!=(LPCMofU8 rcp){ return (m_pPointer != rcp); }
		};

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		bs			バッファサイズ

				@return			None
		*//**************************************************************************/
		CRenderCommandList(MofU32 bs = MOFRENDERCOMMAND_DEFAULTSIZE);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CRenderCommandList();
		
		/*************************************************************************//*!
				@brief			コマンドの追加
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		template < typename T > T* AddCommand(void);
		/*************************************************************************//*!
				@brief			コマンドの追加
				@param[in]		p0			設定パラメーター

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		template < typename T, typename P0 > T* AddCommand(P0& p0);
		/*************************************************************************//*!
				@brief			コマンドの追加
				@param[in]		p0			設定パラメーター
				@param[in]		p1			設定パラメーター

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		template < typename T, typename P0, typename P1 > T* AddCommand(P0& p0, P1& p1);
		/*************************************************************************//*!
				@brief			コマンドの追加
				@param[in]		p0			設定パラメーター
				@param[in]		p1			設定パラメーター
				@param[in]		p2			設定パラメーター

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		template < typename T, typename P0, typename P1, typename P2 > T* AddCommand(P0& p0, P1& p1, P2& p2);
		/*************************************************************************//*!
				@brief			コマンドの追加
				@param[in]		p0			設定パラメーター
				@param[in]		p1			設定パラメーター
				@param[in]		p2			設定パラメーター
				@param[in]		p3			設定パラメーター

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		template < typename T, typename P0, typename P1, typename P2, typename P3 > T* AddCommand(P0& p0, P1& p1, P2& p2, P3& p3);
		/*************************************************************************//*!
				@brief			コマンドの追加
				@param[in]		p0			設定パラメーター
				@param[in]		p1			設定パラメーター
				@param[in]		p2			設定パラメーター
				@param[in]		p3			設定パラメーター
				@param[in]		p4			設定パラメーター

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		template < typename T, typename P0, typename P1, typename P2, typename P3, typename P4 > T* AddCommand(P0& p0, P1& p1, P2& p2, P3& p3, P4& p4);
		/*************************************************************************//*!
				@brief			コマンドの追加
				@param[in]		p0			設定パラメーター
				@param[in]		p1			設定パラメーター
				@param[in]		p2			設定パラメーター
				@param[in]		p3			設定パラメーター
				@param[in]		p4			設定パラメーター
				@param[in]		p5			設定パラメーター

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		template < typename T, typename P0, typename P1, typename P2, typename P3, typename P4, typename P5 > T* AddCommand(P0& p0, P1& p1, P2& p2, P3& p3, P4& p4, P5& p5);

		/*************************************************************************//*!
				@brief			コマンドの実行
				@param			None
				
				@return			None
		*//**************************************************************************/
		virtual MofBool Execute(void);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CRenderCommandList, MOF_RENDERCOMMANDLISTCLASS_ID);
	};
	//ポインタ置き換え
	typedef CRenderCommandList*				LPRenderCommandList;

	#include	"RenderCommand.inl"
}

#endif

//[EOF]