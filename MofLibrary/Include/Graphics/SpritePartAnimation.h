/*************************************************************************//*!
					
					@file	SpritePartAnimation.h
					@brief	スプライトパーツアニメーション基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPRITEPARTANIMATION__H__

#define		__SPRITEPARTANIMATION__H__

//INCLUDE
#include	"SpriteAnimation.h"
#include	"Sprite2DPart.h"
#include	"MosCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	スプライトアニメーションキー保存構造体

			スプライトアニメーションキー保存構造体。<br>
			キーのタイプとキーフレーム配列を管理する。<br>
			キー配列はunionで各タイプのポインタを保持するため、必要に応じて使用するタイプのキーを取り出すこと

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_SPRITEANIMATIONKEY : public IMofCopyObject< tag_SPRITEANIMATIONKEY > {
		/*******************//*!
		タイプ
		*//********************/
		SpriteAnimationKeyType		Type;
		/*******************//*!
		キー配列
		*//********************/
		union {
			LPMofVoid					pPointer;
			LPFloatKeyFrameArray		pFloatKey;
			LPBoolKeyFrameArray			pBoolKey;
			LPS32KeyFrameArray			pS32Key;
			LPU32KeyFrameArray			pU32Key;
			LPRectangleKeyFrameArray	pRectKey;
			LPVector2KeyFrameArray		pVector2Key;
			LPVector3KeyFrameArray		pVector3Key;
			LPVector4KeyFrameArray		pVector4Key;
			LPQuaternionKeyFrameArray	pQuaternionKey;
		};
		
		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param[in]		t				タイプ

				@return			None
		*//**************************************************************************/
		tag_SPRITEANIMATIONKEY(SpriteAnimationKeyType t) :
		Type(t) ,
		pPointer(NULL) {
			switch(t)
			{
				case MOFSPRITE_ANIMATIONKEY_TRANSLATION:
				case MOFSPRITE_ANIMATIONKEY_SCALING:
				case MOFSPRITE_ANIMATIONKEY_ROTATION:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENT:
				case MOFSPRITE_ANIMATIONKEY_ANCHOR:
				case MOFSPRITE_ANIMATIONKEY_SIZE:
					pVector3Key = new CVector3KeyFrameArray();
					break;

				case MOFSPRITE_ANIMATIONKEY_COLOR:
					pVector4Key = new CVector4KeyFrameArray();
					break;

				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION4:
					pVector2Key = new CVector2KeyFrameArray();
					break;

				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR4:
					pVector4Key = new CVector4KeyFrameArray();
					break;

				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ:
				case MOFSPRITE_ANIMATIONKEY_SCALINGX:
				case MOFSPRITE_ANIMATIONKEY_SCALINGY:									
				case MOFSPRITE_ANIMATIONKEY_SCALINGZ:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONX:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONY:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONZ:
				case MOFSPRITE_ANIMATIONKEY_COLORR:
				case MOFSPRITE_ANIMATIONKEY_COLORG:
				case MOFSPRITE_ANIMATIONKEY_COLORB:
				case MOFSPRITE_ANIMATIONKEY_COLORA:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTX:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTY:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTZ:
				case MOFSPRITE_ANIMATIONKEY_ANCHORX:
				case MOFSPRITE_ANIMATIONKEY_ANCHORY:
				case MOFSPRITE_ANIMATIONKEY_ANCHORZ:
				case MOFSPRITE_ANIMATIONKEY_SIZEX:
				case MOFSPRITE_ANIMATIONKEY_SIZEY:
				case MOFSPRITE_ANIMATIONKEY_SIZEZ:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_UVROTATION:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEX:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEY:
				case MOFSPRITE_ANIMATIONKEY_EFFECTTIME:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR5:
					pFloatKey = new CFloatKeyFrameArray();
					break;

				case MOFSPRITE_ANIMATIONKEY_PRIORITY:
					pS32Key = new CS32KeyFrameArray();
					break;
					
				case MOFSPRITE_ANIMATIONKEY_SHOW:
				case MOFSPRITE_ANIMATIONKEY_XREVERSE:
				case MOFSPRITE_ANIMATIONKEY_YREVERSE:
					pBoolKey = new CBoolKeyFrameArray();
					break;
			}
		}
		
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピーキー

				@return			None
		*//**************************************************************************/
		tag_SPRITEANIMATIONKEY(const tag_SPRITEANIMATIONKEY& pObj) :
		Type(pObj.Type) ,
		pPointer(NULL) {
			switch(Type)
			{
				case MOFSPRITE_ANIMATIONKEY_TRANSLATION:
				case MOFSPRITE_ANIMATIONKEY_SCALING:
				case MOFSPRITE_ANIMATIONKEY_ROTATION:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENT:
				case MOFSPRITE_ANIMATIONKEY_ANCHOR:
				case MOFSPRITE_ANIMATIONKEY_SIZE:
					pVector3Key = new CVector3KeyFrameArray(*pObj.pVector3Key);
					break;

				case MOFSPRITE_ANIMATIONKEY_COLOR:
					pVector4Key = new CVector4KeyFrameArray(*pObj.pVector4Key);
					break;

				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION4:
					pVector2Key = new CVector2KeyFrameArray(*pObj.pVector2Key);
					break;

				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR4:
					pVector4Key = new CVector4KeyFrameArray(*pObj.pVector4Key);
					break;

				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ:
				case MOFSPRITE_ANIMATIONKEY_SCALINGX:
				case MOFSPRITE_ANIMATIONKEY_SCALINGY:									
				case MOFSPRITE_ANIMATIONKEY_SCALINGZ:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONX:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONY:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONZ:
				case MOFSPRITE_ANIMATIONKEY_COLORR:
				case MOFSPRITE_ANIMATIONKEY_COLORG:
				case MOFSPRITE_ANIMATIONKEY_COLORB:
				case MOFSPRITE_ANIMATIONKEY_COLORA:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTX:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTY:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTZ:
				case MOFSPRITE_ANIMATIONKEY_ANCHORX:
				case MOFSPRITE_ANIMATIONKEY_ANCHORY:
				case MOFSPRITE_ANIMATIONKEY_ANCHORZ:
				case MOFSPRITE_ANIMATIONKEY_SIZEX:
				case MOFSPRITE_ANIMATIONKEY_SIZEY:
				case MOFSPRITE_ANIMATIONKEY_SIZEZ:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_UVROTATION:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEX:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEY:
				case MOFSPRITE_ANIMATIONKEY_EFFECTTIME:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR5:
					pFloatKey = new CFloatKeyFrameArray(*pObj.pFloatKey);
					break;

				case MOFSPRITE_ANIMATIONKEY_PRIORITY:
					pS32Key = new CS32KeyFrameArray(*pObj.pS32Key);
					break;
					
				case MOFSPRITE_ANIMATIONKEY_SHOW:
				case MOFSPRITE_ANIMATIONKEY_XREVERSE:
				case MOFSPRITE_ANIMATIONKEY_YREVERSE:
					pBoolKey = new CBoolKeyFrameArray(*pObj.pBoolKey);
					break;
			}
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_SPRITEANIMATIONKEY(){
			switch(Type)
			{
				case MOFSPRITE_ANIMATIONKEY_TRANSLATION:
				case MOFSPRITE_ANIMATIONKEY_SCALING:
				case MOFSPRITE_ANIMATIONKEY_ROTATION:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENT:
				case MOFSPRITE_ANIMATIONKEY_ANCHOR:
				case MOFSPRITE_ANIMATIONKEY_SIZE:
					MOF_SAFE_DELETE(pVector3Key);
					break;

				case MOFSPRITE_ANIMATIONKEY_COLOR:
					MOF_SAFE_DELETE(pVector4Key);
					break;
					
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION4:
					MOF_SAFE_DELETE(pVector2Key);
					break;

				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR4:
					MOF_SAFE_DELETE(pVector4Key);
					break;

				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ:
				case MOFSPRITE_ANIMATIONKEY_SCALINGX:
				case MOFSPRITE_ANIMATIONKEY_SCALINGY:									
				case MOFSPRITE_ANIMATIONKEY_SCALINGZ:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONX:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONY:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONZ:
				case MOFSPRITE_ANIMATIONKEY_COLORR:
				case MOFSPRITE_ANIMATIONKEY_COLORG:
				case MOFSPRITE_ANIMATIONKEY_COLORB:
				case MOFSPRITE_ANIMATIONKEY_COLORA:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTX:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTY:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTZ:
				case MOFSPRITE_ANIMATIONKEY_ANCHORX:
				case MOFSPRITE_ANIMATIONKEY_ANCHORY:
				case MOFSPRITE_ANIMATIONKEY_ANCHORZ:
				case MOFSPRITE_ANIMATIONKEY_SIZEX:
				case MOFSPRITE_ANIMATIONKEY_SIZEY:
				case MOFSPRITE_ANIMATIONKEY_SIZEZ:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_UVROTATION:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEX:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEY:
				case MOFSPRITE_ANIMATIONKEY_EFFECTTIME:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR5:
					MOF_SAFE_DELETE(pFloatKey);
					break;
					
				case MOFSPRITE_ANIMATIONKEY_PRIORITY:
					MOF_SAFE_DELETE(pS32Key);
					break;
				case MOFSPRITE_ANIMATIONKEY_SHOW:
				case MOFSPRITE_ANIMATIONKEY_XREVERSE:
				case MOFSPRITE_ANIMATIONKEY_YREVERSE:
					MOF_SAFE_DELETE(pBoolKey);
					break;
			}
		}
		
		/*************************************************************************//*!
				@brief			コピーバッファの作成
				@param			None

				@return			作成されたコピーバッファ<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual tag_SPRITEANIMATIONKEY* CreateCopyObject(void) const{
			return new tag_SPRITEANIMATIONKEY(*this);
		}
		
		/*************************************************************************//*!
				@brief			ループフラグがあるかを判定する
				@param			None
				
				@return			TRUE			ループする<br>
								FALSE			ループしない
		*//**************************************************************************/
		virtual MofBool IsLoop(void){
			switch(Type)
			{
				case MOFSPRITE_ANIMATIONKEY_TRANSLATION:
				case MOFSPRITE_ANIMATIONKEY_SCALING:
				case MOFSPRITE_ANIMATIONKEY_ROTATION:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENT:
				case MOFSPRITE_ANIMATIONKEY_ANCHOR:
				case MOFSPRITE_ANIMATIONKEY_SIZE:
					return pVector3Key->IsLoop();

				case MOFSPRITE_ANIMATIONKEY_COLOR:
					return pVector4Key->IsLoop();
					
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION4:
					return pVector2Key->IsLoop();
					break;

				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR4:
					return pVector4Key->IsLoop();
					break;

				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ:
				case MOFSPRITE_ANIMATIONKEY_SCALINGX:
				case MOFSPRITE_ANIMATIONKEY_SCALINGY:									
				case MOFSPRITE_ANIMATIONKEY_SCALINGZ:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONX:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONY:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONZ:
				case MOFSPRITE_ANIMATIONKEY_COLORR:
				case MOFSPRITE_ANIMATIONKEY_COLORG:
				case MOFSPRITE_ANIMATIONKEY_COLORB:
				case MOFSPRITE_ANIMATIONKEY_COLORA:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTX:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTY:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTZ:
				case MOFSPRITE_ANIMATIONKEY_ANCHORX:
				case MOFSPRITE_ANIMATIONKEY_ANCHORY:
				case MOFSPRITE_ANIMATIONKEY_ANCHORZ:
				case MOFSPRITE_ANIMATIONKEY_SIZEX:
				case MOFSPRITE_ANIMATIONKEY_SIZEY:
				case MOFSPRITE_ANIMATIONKEY_SIZEZ:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_UVROTATION:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEX:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEY:
				case MOFSPRITE_ANIMATIONKEY_EFFECTTIME:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR5:
					return pFloatKey->IsLoop();
					
				case MOFSPRITE_ANIMATIONKEY_PRIORITY:
					return pS32Key->IsLoop();

				case MOFSPRITE_ANIMATIONKEY_SHOW:
				case MOFSPRITE_ANIMATIONKEY_XREVERSE:
				case MOFSPRITE_ANIMATIONKEY_YREVERSE:
					return pBoolKey->IsLoop();
			}
			return FALSE;
		}
		/*************************************************************************//*!
				@brief			ループフラグの設定
				@param[in]		bLoop		ループフラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetLoop(MofBool bLoop) {
			switch(Type)
			{
				case MOFSPRITE_ANIMATIONKEY_TRANSLATION:
				case MOFSPRITE_ANIMATIONKEY_SCALING:
				case MOFSPRITE_ANIMATIONKEY_ROTATION:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENT:
				case MOFSPRITE_ANIMATIONKEY_ANCHOR:
				case MOFSPRITE_ANIMATIONKEY_SIZE:
					return pVector3Key->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));

				case MOFSPRITE_ANIMATIONKEY_COLOR:
					return pVector4Key->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
					
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION4:
					return pVector2Key->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
					break;

				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR4:
					return pVector4Key->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
					break;

				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ:
				case MOFSPRITE_ANIMATIONKEY_SCALINGX:
				case MOFSPRITE_ANIMATIONKEY_SCALINGY:									
				case MOFSPRITE_ANIMATIONKEY_SCALINGZ:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONX:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONY:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONZ:
				case MOFSPRITE_ANIMATIONKEY_COLORR:
				case MOFSPRITE_ANIMATIONKEY_COLORG:
				case MOFSPRITE_ANIMATIONKEY_COLORB:
				case MOFSPRITE_ANIMATIONKEY_COLORA:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTX:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTY:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTZ:
				case MOFSPRITE_ANIMATIONKEY_ANCHORX:
				case MOFSPRITE_ANIMATIONKEY_ANCHORY:
				case MOFSPRITE_ANIMATIONKEY_ANCHORZ:
				case MOFSPRITE_ANIMATIONKEY_SIZEX:
				case MOFSPRITE_ANIMATIONKEY_SIZEY:
				case MOFSPRITE_ANIMATIONKEY_SIZEZ:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_UVROTATION:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEX:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEY:
				case MOFSPRITE_ANIMATIONKEY_EFFECTTIME:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR5:
					return pFloatKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
					
				case MOFSPRITE_ANIMATIONKEY_PRIORITY:
					return pS32Key->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));

				case MOFSPRITE_ANIMATIONKEY_SHOW:
				case MOFSPRITE_ANIMATIONKEY_XREVERSE:
				case MOFSPRITE_ANIMATIONKEY_YREVERSE:
					return pBoolKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
			}
			return FALSE;
		}
		/*************************************************************************//*!
				@brief			最終キーの時間取得
				@param			None
				
				@return			最終時間
		*//**************************************************************************/
		virtual MofBool GetLastKeyTime(void) {
			switch(Type)
			{
				case MOFSPRITE_ANIMATIONKEY_TRANSLATION:
				case MOFSPRITE_ANIMATIONKEY_SCALING:
				case MOFSPRITE_ANIMATIONKEY_ROTATION:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENT:
				case MOFSPRITE_ANIMATIONKEY_ANCHOR:
				case MOFSPRITE_ANIMATIONKEY_SIZE:
					return pVector3Key->GetLastKeyTime();

				case MOFSPRITE_ANIMATIONKEY_COLOR:
					return pVector4Key->GetLastKeyTime();
					
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION4:
					return pVector2Key->GetLastKeyTime();
					break;

				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR2:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR3:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR4:
					return pVector4Key->GetLastKeyTime();
					break;

				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ:
				case MOFSPRITE_ANIMATIONKEY_SCALINGX:
				case MOFSPRITE_ANIMATIONKEY_SCALINGY:									
				case MOFSPRITE_ANIMATIONKEY_SCALINGZ:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONX:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONY:
				case MOFSPRITE_ANIMATIONKEY_ROTATIONZ:
				case MOFSPRITE_ANIMATIONKEY_COLORR:
				case MOFSPRITE_ANIMATIONKEY_COLORG:
				case MOFSPRITE_ANIMATIONKEY_COLORB:
				case MOFSPRITE_ANIMATIONKEY_COLORA:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTX:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTY:
				case MOFSPRITE_ANIMATIONKEY_ALIGNMENTZ:
				case MOFSPRITE_ANIMATIONKEY_ANCHORX:
				case MOFSPRITE_ANIMATIONKEY_ANCHORY:
				case MOFSPRITE_ANIMATIONKEY_ANCHORZ:
				case MOFSPRITE_ANIMATIONKEY_SIZEX:
				case MOFSPRITE_ANIMATIONKEY_SIZEY:
				case MOFSPRITE_ANIMATIONKEY_SIZEZ:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX:
				case MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY:
				case MOFSPRITE_ANIMATIONKEY_UVROTATION:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEX:
				case MOFSPRITE_ANIMATIONKEY_UVSIZEY:
				case MOFSPRITE_ANIMATIONKEY_EFFECTTIME:
				case MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR5:
					return pFloatKey->GetLastKeyTime();
					
				case MOFSPRITE_ANIMATIONKEY_PRIORITY:
					return pS32Key->GetLastKeyTime();

				case MOFSPRITE_ANIMATIONKEY_SHOW:
				case MOFSPRITE_ANIMATIONKEY_XREVERSE:
				case MOFSPRITE_ANIMATIONKEY_YREVERSE:
					return pBoolKey->GetLastKeyTime();
			}
			return 0.0f;
		}
	}SPRITEANIMATIONKEY,*LPSPRITEANIMATIONKEY;
	typedef CDynamicArray< LPSPRITEANIMATIONKEY >		CSpriteAnimationKeyArray,*LPSpriteAnimationKeyArray;

	/*******************************//*!
	@brief	スプライトパーツアニメーションクラス

			スプライトパーツアニメーションクラス。<br>
			任意のキーでのパーツごとのアニメーションを管理する。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSpritePartAnimation : public IMofNamedObject , public IMofCopyObject< CSpritePartAnimation > {
	protected:
		/*******************//*!
		アニメーション名
		*//********************/
		CString						m_Name;
		/*******************//*!
		アニメーションキー
		*//********************/
		LPSpriteAnimationKeyArray	m_pAnimationKey;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CSpritePartAnimation();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーオブジェクト

				@return			None
		*//**************************************************************************/
		CSpritePartAnimation(const CSpritePartAnimation& pObj);

		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSpritePartAnimation();
		
		/*************************************************************************//*!
				@brief			スプライトアニメーションのコピー生成
				@param			None
				
				@return			作成されたCSpritePartAnimation<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual CSpritePartAnimation* CreateCopyObject(void) const;

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
				
		
		//----------------------------------------------------------------------------
		////Is
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ループフラグがあるかを判定する
				@param			None
				
				@return			TRUE			ループする<br>
								FALSE			ループしない
		*//**************************************************************************/
		virtual MofBool IsLoop(void);

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
				@brief			キー取得
				@param			None

				@return			キーの取得
		*//**************************************************************************/
		virtual LPSpriteAnimationKeyArray GetAnimationKey(void);
		/*************************************************************************//*!
				@brief			キー取得
				@param[in]		t				キータイプ

				@return			キーの取得
		*//**************************************************************************/
		LPFloatKeyFrameArray GetAnimationFloatKey(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			キー取得
				@param[in]		t				キータイプ

				@return			キーの取得
		*//**************************************************************************/
		LPBoolKeyFrameArray GetAnimationBoolKey(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			キー取得
				@param[in]		t				キータイプ

				@return			キーの取得
		*//**************************************************************************/
		LPS32KeyFrameArray GetAnimationS32Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			キー取得
				@param[in]		t				キータイプ

				@return			キーの取得
		*//**************************************************************************/
		LPU32KeyFrameArray GetAnimationU32Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			キー取得
				@param[in]		t				キータイプ

				@return			キーの取得
		*//**************************************************************************/
		LPRectangleKeyFrameArray GetAnimationRectKey(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			キー取得
				@param[in]		t				キータイプ

				@return			キーの取得
		*//**************************************************************************/
		LPVector2KeyFrameArray GetAnimationVector2Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			キー取得
				@param[in]		t				キータイプ

				@return			キーの取得
		*//**************************************************************************/
		LPVector3KeyFrameArray GetAnimationVector3Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			キー取得
				@param[in]		t				キータイプ

				@return			キーの取得
		*//**************************************************************************/
		LPVector4KeyFrameArray GetAnimationVector4Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			キー取得
				@param[in]		t				キータイプ

				@return			キーの取得
		*//**************************************************************************/
		LPQuaternionKeyFrameArray GetAnimationQuaternionKey(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			アニメーションの終了時間取得<br>
								ループをする場合でも最終のフレームの時間を返す
				@param			None
				
				@return			アニメーションの終了時間
		*//**************************************************************************/
		virtual MofFloat GetEndTime(void);
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CSpritePartAnimation,MOF_SPRITEPARTANIMATIONCLASS_ID);
	};

	#include	"SpritePartAnimation.inl"

	//置き換え
	typedef CSpritePartAnimation					*LPSpritePartAnimation;
	typedef CDynamicArray< LPSpritePartAnimation >	CSpritePartAnimationArray,*LPSpritePartAnimationArray;
}

#endif

//[EOF]