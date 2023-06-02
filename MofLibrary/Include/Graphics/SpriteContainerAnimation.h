/*************************************************************************//*!
					
					@file	SpriteContainerAnimation.h
					@brief	スプライトコンテナアニメーション基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPRITECONTAINERANIMATION__H__

#define		__SPRITECONTAINERANIMATION__H__

//INCLUDE
#include	"SpritePartAnimation.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュアニメーション基底クラス

			メッシュアニメーション基底となるクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSpriteContainerAnimation : public IMofNamedObject , public IMofCopyObject< CSpriteContainerAnimation > {
	protected:
		/*******************//*!
		名前
		*//********************/
		CString						m_Name;
		/*******************//*!
		パーツアニメーション
		*//********************/
		LPSpritePartAnimationArray	m_pPartAnimation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CSpriteContainerAnimation();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーメッシュアニメーション

				@return			None
		*//**************************************************************************/
		CSpriteContainerAnimation(const CSpriteContainerAnimation& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSpriteContainerAnimation();
		
		/*************************************************************************//*!
				@brief			スプライトアニメーションのコピー生成
				@param			None
				
				@return			作成されたCSpriteContainerAnimation<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual CSpriteContainerAnimation* CreateCopyObject(void) const;

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
		/*************************************************************************//*!
				@brief			モーションのループフラグの設定
				@param[in]		bLoop			ループフラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetLoop(MofBool bLoop);

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
				@brief			アニメーションでの動作パーツ情報取得
				@param			None

				@return			アニメーションでの動作パーツ情報配列
		*//**************************************************************************/
		virtual LPSpritePartAnimationArray GetPartAnimation(void);

		//クラス基本定義
		MOF_LIBRARYCLASS(CSpriteContainerAnimation,MOF_SPRITECONTAINERANIMATIONCLASS_ID);
	};

	#include	"SpriteContainerAnimation.inl"
	
	//置き換え
	typedef CSpriteContainerAnimation					*LPSpriteContainerAnimation;
	typedef CDynamicArray< LPSpriteContainerAnimation >	CSpriteContainerAnimationArray,*LPSpriteContainerAnimationArray;
}

#endif

//[EOF]