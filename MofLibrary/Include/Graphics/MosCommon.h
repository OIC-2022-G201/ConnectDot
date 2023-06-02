/*************************************************************************//*!
					
					@file	MosCommon.h
					@brief	�Ǝ��`���X�v���C�g�t�@�C���֘A�̊�{��`���s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MOSCOMMON__H__

#define		__MOSCOMMON__H__

//INCLUDE
#include	"GraphicsCommon.h"
#include	"../Common/PackFile.h"
#include	"../Common/WriteChunkFile.h"
#include	"../Common/KeyFrameArray.h"

//DEFINE

//!�Ǝ��t�@�C���w�b�_�[
#define		MOFSPRITE_FILE_HEADER				"MOS SPRITE VER 0.01 FILE"

//!�Ǝ��t�@�C���w�b�_�[��
#define		MOFSPRITE_FILE_HEADERLEN			strlen(MOFSPRITE_FILE_HEADER)

//!�Ǝ��t�@�C���t�b�^�[
#define		MOFSPRITE_FILE_FOOTER				"EOF"

//!�Ǝ��t�@�C���t�b�^�[��
#define		MOFSPRITE_FILE_FOOTERLEN			strlen(MOFSPRITE_FILE_FOOTER)

namespace Mof {
	
	/*******************************//*!
	@brief	�X�v���C�g�p�[�c�^�C�v��

			�X�v���C�g�p�[�c���ǂ����������Ǘ����Ă��邩���w�肷��^�C�v���

	@author	CDW
	*//********************************/
	typedef enum tag_SPRITETYPE {
		SPRITETYPE_NULL,															//!<��X�v���C�g
		SPRITETYPE_NORMAL,															//!<�ʏ�Ǘ��X�v���C�g
		SPRITETYPE_EMITTER,															//!<�G�~�b�^�[
		SPRITETYPE_PARTICLE,														//!<�p�[�e�B�N��
	}SpriteType;

	/*******************************//*!
	@brief	�X�v���C�g�t�@�C���e���v���[�g��

			MOS�t�@�C�����ɒ�`�����`�����N�̏��^�C�v���

	@author	CDW
	*//********************************/
	enum tag_MOFSPRITE_TEMPLATE {
		MOFSPRITE_TEMP_TEXTURE					=		0x00001000,					//!<�e�N�X�`��

		MOFSPRITE_TEMP_SPRITE					=		0x00002000,					//!<�X�v���C�g

		MOFSPRITE_TEMP_SPRITECONTAINER			=		0x00003000,					//!<�X�v���C�g�R���e�i

		MOFSPRITE_TEMP_SPRITEANIMATION			=		0x00004000,					//!<�X�v���C�g�A�j���[�V����
		MOFSPRITE_TEMP_SPRITEPARTANIMATION,											//!<�X�v���C�g�p�[�c�A�j���[�V����
		MOFSPRITE_TEMP_SPRITEPARTANIMATIONKEY,										//!<�X�v���C�g�p�[�c�A�j���[�V�����L�[

		MOFSPRITE_TEMP_EFFECT					=		0x00005000,					//!<�X�v���C�g�G�t�F�N�g

		MOFSPRITE_TEMP_MAX,															//!<�`�����N�ő吔
	};
	
	/*******************************//*!
	@brief	�X�v���C�g�t�@�C���L�[�^�C�v��

			MOS�t�@�C�����ɒ�`�����A�j���[�V�����̃L�[�^�C�v���

	@author	CDW
	*//********************************/
	typedef enum tag_MOFSPRITE_ANIMATIONKEYTYPE {
		MOFSPRITE_ANIMATIONKEY_TRANSLATION,											//!<���s�ړ�
		MOFSPRITE_ANIMATIONKEY_TRANSLATIONX,										//!<���s�ړ�X
		MOFSPRITE_ANIMATIONKEY_TRANSLATIONY,										//!<���s�ړ�Y
		MOFSPRITE_ANIMATIONKEY_TRANSLATIONZ,										//!<���s�ړ�Z

		MOFSPRITE_ANIMATIONKEY_SCALING,												//!<�X�P�[��
		MOFSPRITE_ANIMATIONKEY_SCALINGX,											//!<�X�P�[��X
		MOFSPRITE_ANIMATIONKEY_SCALINGY,											//!<�X�P�[��Y
		MOFSPRITE_ANIMATIONKEY_SCALINGZ,											//!<�X�P�[��Z

		MOFSPRITE_ANIMATIONKEY_ROTATION,											//!<��]
		MOFSPRITE_ANIMATIONKEY_ROTATIONX,											//!<��]X
		MOFSPRITE_ANIMATIONKEY_ROTATIONY,											//!<��]Y
		MOFSPRITE_ANIMATIONKEY_ROTATIONZ,											//!<��]Z
		
		MOFSPRITE_ANIMATIONKEY_COLOR,												//!<�F
		MOFSPRITE_ANIMATIONKEY_COLORR,												//!<�F�q
		MOFSPRITE_ANIMATIONKEY_COLORG,												//!<�F�f
		MOFSPRITE_ANIMATIONKEY_COLORB,												//!<�F�a
		MOFSPRITE_ANIMATIONKEY_COLORA,												//!<�F�`

		MOFSPRITE_ANIMATIONKEY_PRIORITY,											//!<�`��D�揇��
		
		MOFSPRITE_ANIMATIONKEY_ALIGNMENT,											//!<�A���C�����g
		MOFSPRITE_ANIMATIONKEY_ALIGNMENTX,											//!<�A���C�����gX
		MOFSPRITE_ANIMATIONKEY_ALIGNMENTY,											//!<�A���C�����gY
		MOFSPRITE_ANIMATIONKEY_ALIGNMENTZ,											//!<�A���C�����gZ

		MOFSPRITE_ANIMATIONKEY_ANCHOR,												//!<�A���J�[
		MOFSPRITE_ANIMATIONKEY_ANCHORX,												//!<�A���J�[X
		MOFSPRITE_ANIMATIONKEY_ANCHORY,												//!<�A���J�[Y
		MOFSPRITE_ANIMATIONKEY_ANCHORZ,												//!<�A���J�[Z
		
		MOFSPRITE_ANIMATIONKEY_SIZE,												//!<�T�C�Y
		MOFSPRITE_ANIMATIONKEY_SIZEX,												//!<�T�C�YX
		MOFSPRITE_ANIMATIONKEY_SIZEY,												//!<�T�C�YY
		MOFSPRITE_ANIMATIONKEY_SIZEZ,												//!<�T�C�YZ

		MOFSPRITE_ANIMATIONKEY_SHOW,												//!<�\��

		MOFSPRITE_ANIMATIONKEY_XREVERSE,											//!<X���]
		MOFSPRITE_ANIMATIONKEY_YREVERSE,											//!<Y���]

		MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION1,									//!<���_
		MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION2,									//!<���_
		MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION3,									//!<���_
		MOFSPRITE_ANIMATIONKEY_VERTEXTRANSLATION4,									//!<���_

		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR1,										//!<���_
		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR2,										//!<���_
		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR3,										//!<���_
		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR4,										//!<���_
		MOFSPRITE_ANIMATIONKEY_VERTEXCOLOR5,										//!<���_

		MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONX,										//!<UV
		MOFSPRITE_ANIMATIONKEY_UVTRANSLATIONY,										//!<UV
		MOFSPRITE_ANIMATIONKEY_UVROTATION,											//!<UV
		MOFSPRITE_ANIMATIONKEY_UVSIZEX,												//!<UV
		MOFSPRITE_ANIMATIONKEY_UVSIZEY,												//!<UV

		MOFSPRITE_ANIMATIONKEY_EFFECTTIME,											//!<�G�t�F�N�g�^�C��
	}SpriteAnimationKeyType;
	
	/*******************************//*!
	@brief	�X�v���C�g�p�[�e�B�N���A�j���[�V������

			MOS�t�@�C�����ɒ�`�����X�v���C�g�p�[�e�B�N���A�j���[�V�����̃^�C�v���

	@author	CDW
	*//********************************/
	enum tag_MOFSPRITE_EFFECTANIMATION {
		MOFSPRITE_EFFECTANIMATION_BASIC						=		0x00000001,					//!<��{
		MOFSPRITE_EFFECTANIMATION_SEED						=		0x00000002,					//!<�����ύX
		MOFSPRITE_EFFECTANIMATION_DELAY						=		0x00000004,					//!<�x��
		MOFSPRITE_EFFECTANIMATION_GRAVITY					=		0x00000008,					//!<�d��
		MOFSPRITE_EFFECTANIMATION_POSITION					=		0x00000010,					//!<���W
		MOFSPRITE_EFFECTANIMATION_ROTATION					=		0x00000020,					//!<��]
		MOFSPRITE_EFFECTANIMATION_ROTATIONTRANS				=		0x00000040,					//!<��]
		MOFSPRITE_EFFECTANIMATION_SPEEDTRANS				=		0x00000080,					//!<���x
		MOFSPRITE_EFFECTANIMATION_TANGENTIALACCELERATION	=		0x00000100,					//!<���x
		MOFSPRITE_EFFECTANIMATION_INITIALIZECOLOR			=		0x00000200,					//!<�F
		MOFSPRITE_EFFECTANIMATION_COLORTRANS				=		0x00000400,					//!<�F
		MOFSPRITE_EFFECTANIMATION_ALPHA						=		0x00000800,					//!<�F
		MOFSPRITE_EFFECTANIMATION_SIZE						=		0x00001000,					//!<�傫��
		MOFSPRITE_EFFECTANIMATION_SIZETRANS					=		0x00002000,					//!<�傫��
		MOFSPRITE_EFFECTANIMATION_POINTGRAVITY				=		0x00004000,					//!<�傫��
		MOFSPRITE_EFFECTANIMATION_DIRECTION					=		0x00008000,					//!<�傫��
		MOFSPRITE_EFFECTANIMATION_INFINITE					=		0x00010000,					//!<�傫��

		MOFSPRITE_EFFECTANIMATION_MAX,															//!<�`�����N�ő吔
	};

	/*******************************//*!
	@brief	�X�v���C�g�t�@�C����̓G���[��

			�X�v���C�g�t�@�C����͎��ɔ�������G���[���

	@author	CDW
	*//********************************/
	enum tag_MOFSPRITE_RESULT {
		MOFSPRITE_RESULTERROR_UNKNOWN		=		0,								//!<�悭�킩��Ȃ��G���[

		MOFSPRITE_RESULT_SUCCEEDED			=		TRUE,							//!<����I��

		MOFSPRITE_RESULTERROR_OPENERROR,											//!<�t�@�C�����J���Ȃ�����
		MOFSPRITE_RESULTERROR_NOTMOSFILE,											//!<�t�@�C����MOS�`������Ȃ�

		MOFSPRITE_RESULTERROR_CHUNKSIZE,											//!<�`�����N�T�C�Y����������
		MOFSPRITE_RESULTERROR_UNKNOWNCHUNK,											//!<�`�����N���ςȈʒu�ɑ��݂���
		MOFSPRITE_RESULTERROR_CHUNKENDFAULT,										//!<�`�����N�I����������Ȃ�
		MOFSPRITE_RESULTERROR_UNKNOWNCHUNKEND,										//!<�`�����N�I�����ςȈʒu�ɑ��݂���

		MOFSPRITE_RESULTERROR_NOTFOOTER,											//!<�t�b�^�[�łȂ��ő�T�C�Y�𒴂���
		MOFSPRITE_RESULTERROR_UNKNOWNFOOTER,										//!<�t�b�^�[���ςȈʒu�ɑ��݂���
		
		MOFSPRITE_RESULTERROR_TEXTURELOAD,											//!<�e�N�X�`���̓ǂݍ��ݎ��s
	};

	/*******************************//*!
	@brief	�X�v���C�g�t�@�C���w�b�_�[�\����

			�X�v���C�g�t�@�C���̊�{�����i�[�����w�b�_�[�\����

	@author	CDW
	*//********************************/
	typedef struct tag_MOFSPRITEHEADER {
		MofBool						bStringCode;									//!<�����R�[�h(UNICODE�`���Ȃ�TRUE,�}���`�o�C�g�Ȃ�FALSE)
		MofU32						Alignment;										//!<�A���C�����g
		MofU32						BlockSize;										//!<�u���b�N�T�C�Y
		MofU32						Flag;											//!<�t�@�C�����ǉ��t���O
	}MOFSPRITEHEADER,*LPMOFSPRITEHEADER;
	
	/*******************************//*!
	@brief	�X�v���C�g�G�t�F�N�g�̃f�[�^�\����

			�G�t�F�N�g�̂΂���̂��߂̃f�[�^��\���\����

	@author	CDW
	*//********************************/
	template < typename T > struct MOFSPRITEEFFECTVALUE {
		T							Start;											//!<�J�n
		T							Range;											//!<�͈�

		MOFSPRITEEFFECTVALUE(const T& s,const T& r) :
		Start(s) ,
		Range(r) {
		}
		
		MOFSPRITEEFFECTVALUE(const MOFSPRITEEFFECTVALUE& pObj) :
		Start(pObj.Start) ,
		Range(pObj.Range) {
		}
	};
	
	/*******************************//*!
	@brief	�X�v���C�g�G�t�F�N�g�̃f�[�^�\����

			�G�t�F�N�g�̃f�[�^��\���\����

	@author	CDW
	*//********************************/
	typedef struct tag_MOFSPRITEEFFECTPARAMETER {
		MofU32								Flag;									//!<����t���O
		MofFloat							Life;									//!<��������
		MofFloat							Interval;								//!<�����Ԋu
		MofS32								CreateCount;							//!<��x�ɔr�o������
		MofS32								CreateMax;								//!<�ő�r�o��
		MOFSPRITEEFFECTVALUE< MofFloat >	ParticleLife;							//!<���������p�[�e�B�N���̎���

		MOFSPRITEEFFECTVALUE< Vector2 >		Offset;									//!<�I�t�Z�b�g
		MOFSPRITEEFFECTVALUE< Vector2 >		Scale;									//!<�X�P�[��
		MOFSPRITEEFFECTVALUE< MofFloat >	Angle;									//!<����
		Vector4								StartColor;								//!<�J�n�F
		Vector4								EndColor;								//!<�I���F
		MOFSPRITEEFFECTVALUE< MofFloat >	Speed;									//!<���x
		MOFSPRITEEFFECTVALUE< MofFloat >	Acceleration;							//!<���x
		MOFSPRITEEFFECTVALUE< MofFloat >	Rotation;								//!<��]
		MOFSPRITEEFFECTVALUE< MofFloat >	RotationAcceleration;					//!<��]
		Vector2								Gravity;								//!<�d��
		MofFloat							Delay;									//!<�x��
		MofFloat							RotationFactor;							//!<��]
		MofFloat							RotationEndLifeTimePer;					//!<��]
		MOFSPRITEEFFECTVALUE< MofFloat >	TangentialAcceleration;					//!<�ڑ��x
		MOFSPRITEEFFECTVALUE< Vector4 >		CreateColor;							//!<�F
		MOFSPRITEEFFECTVALUE< Vector4 >		ColorChange;							//!<�F
		MOFSPRITEEFFECTVALUE< MofFloat >	Alpha;									//!<�A���t�@
		MOFSPRITEEFFECTVALUE< MofFloat >	ScaleFactor;							//!<���x
		MOFSPRITEEFFECTVALUE< Vector2 >		ScaleChange;							//!<�X�P�[��
		MOFSPRITEEFFECTVALUE< MofFloat >	ScaleChangeFactor;						//!<���x
		Vector2								GravityPosition;						//!<�d��
		MofFloat							GravityPower;							//!<�d��
		MofFloat							Direction;								//!<�d��

		MofS32								Seed;									//!<�����p��
		tag_MOFSPRITEEFFECTPARAMETER() :
		Flag(0) ,
		Life(0) ,
		Interval(0) ,
		CreateCount(0) ,
		CreateMax(0) ,
		ParticleLife(0,0) ,
		Offset(Vector2(0,0), Vector2(0,0)) ,
		Scale(Vector2(1,1), Vector2(0,0)) ,
		Angle(0, 0) ,
		StartColor(1,1,1,1) ,
		EndColor(1,1,1,1) ,
		Speed(0, 0) ,
		Acceleration(0, 0) ,
		Rotation(0, 0) ,
		RotationAcceleration(0, 0) ,
		Gravity(0,0) ,
		Delay(0) ,
		RotationFactor(0) ,
		RotationEndLifeTimePer(0) ,
		TangentialAcceleration(0,0) ,
		CreateColor(Vector4(0,0,0,0), Vector4(0, 0, 0, 0)) ,
		ColorChange(Vector4(0,0,0,0), Vector4(0, 0, 0, 0)) ,
		Alpha(0,0) ,
		ScaleFactor(0,0) ,
		ScaleChange(Vector2(0,0), Vector2(0,0)) ,
		ScaleChangeFactor(0,0) ,
		GravityPosition(0,0) ,
		GravityPower(0) ,
		Direction(0) ,
		Seed(0) 
		{
		}
		tag_MOFSPRITEEFFECTPARAMETER(const tag_MOFSPRITEEFFECTPARAMETER& pObj):
		Flag(pObj.Flag) ,
		Life(pObj.Life) ,
		Interval(pObj.Interval) ,
		CreateCount(pObj.CreateCount) ,
		CreateMax(pObj.CreateMax) ,
		ParticleLife(pObj.ParticleLife) ,
		Offset(pObj.Offset) ,
		Scale(pObj.Scale) ,
		Angle(pObj.Angle) ,
		StartColor(pObj.StartColor) ,
		EndColor(pObj.EndColor),
		Speed(pObj.Speed) ,
		Acceleration(pObj.Acceleration) ,
		Rotation(pObj.Rotation) ,
		RotationAcceleration(pObj.RotationAcceleration) ,
		Gravity(pObj.Gravity) ,
		Delay(pObj.Delay) ,
		RotationFactor(pObj.RotationFactor) ,
		RotationEndLifeTimePer(pObj.RotationEndLifeTimePer) ,
		TangentialAcceleration(pObj.TangentialAcceleration) ,
		CreateColor(pObj.CreateColor) ,
		ColorChange(pObj.ColorChange) ,
		Alpha(pObj.Alpha) ,
		ScaleFactor(pObj.ScaleFactor) ,
		ScaleChange(pObj.ScaleChange) ,
		ScaleChangeFactor(pObj.ScaleChangeFactor) ,
		GravityPosition(pObj.GravityPosition) ,
		GravityPower(pObj.GravityPower) ,
		Direction(pObj.Direction) ,
		Seed(pObj.Seed)
		{
		}
	}MOFSPRITEEFFECTPARAMETER,*LPMOFSPRITEEFFECTPARAMETER;
}

#endif

//[EOF]