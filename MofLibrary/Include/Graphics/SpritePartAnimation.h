/*************************************************************************//*!
					
					@file	SpritePartAnimation.h
					@brief	�X�v���C�g�p�[�c�A�j���[�V�������N���X�B

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
	@brief	�X�v���C�g�A�j���[�V�����L�[�ۑ��\����

			�X�v���C�g�A�j���[�V�����L�[�ۑ��\���́B<br>
			�L�[�̃^�C�v�ƃL�[�t���[���z����Ǘ�����B<br>
			�L�[�z���union�Ŋe�^�C�v�̃|�C���^��ێ����邽�߁A�K�v�ɉ����Ďg�p����^�C�v�̃L�[�����o������

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_SPRITEANIMATIONKEY : public IMofCopyObject< tag_SPRITEANIMATIONKEY > {
		/*******************//*!
		�^�C�v
		*//********************/
		SpriteAnimationKeyType		Type;
		/*******************//*!
		�L�[�z��
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
				@brief			�R���X�g���N�^<br>
								�S�Ẵp�����[�^�[���f�t�H���g�ō쐬����B
				@param[in]		t				�^�C�v

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
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�L�[

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
				@brief			�f�X�g���N�^
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
				@brief			�R�s�[�o�b�t�@�̍쐬
				@param			None

				@return			�쐬���ꂽ�R�s�[�o�b�t�@<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual tag_SPRITEANIMATIONKEY* CreateCopyObject(void) const{
			return new tag_SPRITEANIMATIONKEY(*this);
		}
		
		/*************************************************************************//*!
				@brief			���[�v�t���O�����邩�𔻒肷��
				@param			None
				
				@return			TRUE			���[�v����<br>
								FALSE			���[�v���Ȃ�
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
				@brief			���[�v�t���O�̐ݒ�
				@param[in]		bLoop		���[�v�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
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
				@brief			�ŏI�L�[�̎��Ԏ擾
				@param			None
				
				@return			�ŏI����
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
	@brief	�X�v���C�g�p�[�c�A�j���[�V�����N���X

			�X�v���C�g�p�[�c�A�j���[�V�����N���X�B<br>
			�C�ӂ̃L�[�ł̃p�[�c���Ƃ̃A�j���[�V�������Ǘ�����B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSpritePartAnimation : public IMofNamedObject , public IMofCopyObject< CSpritePartAnimation > {
	protected:
		/*******************//*!
		�A�j���[�V������
		*//********************/
		CString						m_Name;
		/*******************//*!
		�A�j���[�V�����L�[
		*//********************/
		LPSpriteAnimationKeyArray	m_pAnimationKey;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CSpritePartAnimation();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�I�u�W�F�N�g

				@return			None
		*//**************************************************************************/
		CSpritePartAnimation(const CSpritePartAnimation& pObj);

		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSpritePartAnimation();
		
		/*************************************************************************//*!
				@brief			�X�v���C�g�A�j���[�V�����̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽCSpritePartAnimation<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual CSpritePartAnimation* CreateCopyObject(void) const;

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
				
		
		//----------------------------------------------------------------------------
		////Is
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���[�v�t���O�����邩�𔻒肷��
				@param			None
				
				@return			TRUE			���[�v����<br>
								FALSE			���[�v���Ȃ�
		*//**************************************************************************/
		virtual MofBool IsLoop(void);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�ݒ�
				@param[in]		pName			�ݒ肷�閼�O
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			���[�V�����̃��[�v�t���O�̐ݒ�
				@param[in]		bLoop			���[�v�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetLoop(MofBool bLoop);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param			None

				@return			�L�[�̎擾
		*//**************************************************************************/
		virtual LPSpriteAnimationKeyArray GetAnimationKey(void);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param[in]		t				�L�[�^�C�v

				@return			�L�[�̎擾
		*//**************************************************************************/
		LPFloatKeyFrameArray GetAnimationFloatKey(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param[in]		t				�L�[�^�C�v

				@return			�L�[�̎擾
		*//**************************************************************************/
		LPBoolKeyFrameArray GetAnimationBoolKey(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param[in]		t				�L�[�^�C�v

				@return			�L�[�̎擾
		*//**************************************************************************/
		LPS32KeyFrameArray GetAnimationS32Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param[in]		t				�L�[�^�C�v

				@return			�L�[�̎擾
		*//**************************************************************************/
		LPU32KeyFrameArray GetAnimationU32Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param[in]		t				�L�[�^�C�v

				@return			�L�[�̎擾
		*//**************************************************************************/
		LPRectangleKeyFrameArray GetAnimationRectKey(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param[in]		t				�L�[�^�C�v

				@return			�L�[�̎擾
		*//**************************************************************************/
		LPVector2KeyFrameArray GetAnimationVector2Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param[in]		t				�L�[�^�C�v

				@return			�L�[�̎擾
		*//**************************************************************************/
		LPVector3KeyFrameArray GetAnimationVector3Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param[in]		t				�L�[�^�C�v

				@return			�L�[�̎擾
		*//**************************************************************************/
		LPVector4KeyFrameArray GetAnimationVector4Key(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			�L�[�擾
				@param[in]		t				�L�[�^�C�v

				@return			�L�[�̎擾
		*//**************************************************************************/
		LPQuaternionKeyFrameArray GetAnimationQuaternionKey(SpriteAnimationKeyType t);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����̏I�����Ԏ擾<br>
								���[�v������ꍇ�ł��ŏI�̃t���[���̎��Ԃ�Ԃ�
				@param			None
				
				@return			�A�j���[�V�����̏I������
		*//**************************************************************************/
		virtual MofFloat GetEndTime(void);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS(CSpritePartAnimation,MOF_SPRITEPARTANIMATIONCLASS_ID);
	};

	#include	"SpritePartAnimation.inl"

	//�u������
	typedef CSpritePartAnimation					*LPSpritePartAnimation;
	typedef CDynamicArray< LPSpritePartAnimation >	CSpritePartAnimationArray,*LPSpritePartAnimationArray;
}

#endif

//[EOF]