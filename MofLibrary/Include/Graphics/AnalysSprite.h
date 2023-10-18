/*************************************************************************//*!
					
					@file	AnalysSprite.h
					@brief	MOS�t�@�C���̉�͂��s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ANALYSSPRITE__H__

#define		__ANALYSSPRITE__H__

//INCLUDE
#include	"MosCommon.h"
#include	"Sprite2DContainer.h"
#include	"Sprite2DEffect.h"
#include	"Sprite3D.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MOS�t�@�C����̓N���X

			MOS�t�@�C���̉�͂��s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CAnalysSprite : public CReadBinaryFile {
	private:
		/*******************//*!
		���ID
		*//********************/
		MofU32						m_ID;
		/*******************//*!
		�t�@�C���w�b�_�[
		*//********************/
		MOFSPRITEHEADER				m_Header;
		/*******************//*!
		�t�@�C�������p�e�N�X�`�����X�g
		*//********************/
		LPTextureArray				m_pTextureArray;
		
		/*************************************************************************//*!
				@brief			MOS�t�@�C����ǂݍ���
				@param[in]		pSprite		�X�v���C�g�t�@�C��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Analys(LPSprite2DContainer pSprite);
		/*************************************************************************//*!
				@brief			MOS�t�@�C����ǂݍ���
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysTexture(void);
		/*************************************************************************//*!
				@brief			MOS�t�@�C����ǂݍ���
				@param[in]		pSprite		�X�v���C�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysSprite(LPSprite2DPart pSprite);
		/*************************************************************************//*!
				@brief			MOS�t�@�C����ǂݍ���
				@param[in]		pEffect		�X�v���C�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysEffect(LPSprite2DEffect pSprite);
		/*************************************************************************//*!
				@brief			MOS�t�@�C����ǂݍ���
				@param[in]		pAnim		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimation(LPSpriteContainerAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOS�t�@�C����ǂݍ���
				@param[in]		pAnim		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimation(LPSpritePartAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOS�t�@�C����ǂݍ���
				@param[in]		pAnim		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimationKey(LPSpritePartAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		kit			��ԃ^�C�v
				@param[out]		inval		��Ԑ��l
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysKeyInterpolation(MofU32 kit,LPMofFloat inval);
		/*************************************************************************//*!
				@brief			�ǂݍ��݃u���b�N�̈ړ�
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool MoveBlockOffset(void);
		/*************************************************************************//*!
				@brief			MOS�t�@�C�����𔻒肷��<br>
								�t�@�C���̐擪��MOFSPRITE_FILE_HEADER����n�܂��MOS�t�@�C��
				@param			None
				
				@return			TRUE		MOS�t�@�C��<br>
								����ȊO	MOS�t�@�C���ł͂Ȃ�
		*//**************************************************************************/
		MofBool IsMOSFile(void);
		/*************************************************************************//*!
				@brief			MOS�t�@�C���t�b�^�[�܂ŉ�͂������𔻒肷��<br>
								���݈ʒu����MOFSPRITE_FILE_FOOTER�̃f�[�^�ɂȂ��Ă���΃t�b�^�[
				@param			None
				
				@return			TRUE							�t�b�^�[<br>
								FALSE							�܂��t�b�^�[�ł͂Ȃ�<br>
								MOFSPRITE_RESULTERROR_NOTFOOTER	�t�b�^�[����Ȃ��̂Ƀt�@�C�����I�����Ă���
		*//**************************************************************************/
		MofBool IsMOSFooter(void);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CAnalysSprite();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAnalysSprite();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s��
				@param[in]		pName		�t�@�C����
				@param[out]		pSprite		�o�̓X�v���C�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Analys(LPCMofChar pName,LPSprite2DContainer pSprite);
		/*************************************************************************//*!
				@brief			�����������͂��s��
				@param[in]		pName		���O
				@param[in]		pBuffer		�o�b�t�@
				@param[in]		Size		�T�C�Y
				@param[out]		pSprite		�o�̓X�v���C�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Analys(LPCMofChar pName,LPCMofVoid pBuffer,const MofU32 Size,LPSprite2DContainer pSprite);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CAnalysSprite,MOF_ANALYSSPRITECLASS_ID);
	};

	//INLINE INCLUDE
	#include	"AnalysSprite.inl"

}

#endif	//__ANALYSSPRITE__H__

//[EOF]