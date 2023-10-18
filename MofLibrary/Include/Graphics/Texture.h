/*************************************************************************//*!
					
					@file	Texture.h
					@brief	�e�N�X�`�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__TEXTURE__H__

#define		__TEXTURE__H__

//INCLUDE
#include	"GraphicsCommon.h"
#include	"RenderTarget.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�e�N�X�`�����]��

			�e�N�X�`���̔��]���̗�

	@author	CDW
	*//********************************/
	typedef enum TextureReverse {
		TEXTUREREVERSE_NONE				=	0x00,	//!<���]�Ȃ�
		TEXTUREREVERSE_HORIZON			=	0x01,	//!<�����]
		TEXTUREREVERSE_VERTICAL			=	0x02,	//!<�c���]

		//-------------------------------------------------
		//�Z�k���̒�`
		//-------------------------------------------------
		TEXREV_NONE						=	0x00,	//!<���]�Ȃ�
		TEXREV_HORIZON					=	0x01,	//!<�����]
		TEXREV_VERTICAL					=	0x02,	//!<�c���]
	}TextureReverse;

	/*******************************//*!
	@brief	�e�N�X�`���A���C�����g��

			�e�N�X�`���̈ʒu�A�g��A��]�̊�ƂȂ�A�A���C�����g�̗�

	@author	CDW
	*//********************************/
	typedef enum TextureAlignment {
		TEXTUREALIGNMENT_TOP			=	0x10,	//!<��
		TEXTUREALIGNMENT_VCENTER		=	0x20,	//!<��
		TEXTUREALIGNMENT_BOTTOM			=	0x40,	//!<��
		TEXTUREALIGNMENT_LEFT			=	0x01,	//!<��
		TEXTUREALIGNMENT_HCENTER		=	0x02,	//!<��
		TEXTUREALIGNMENT_RIGHT			=	0x04,	//!<�E

		TEXTUREALIGNMENT_TOPLEFT		=	0x11,	//!<����
		TEXTUREALIGNMENT_TOPCENTER		=	0x12,	//!<����
		TEXTUREALIGNMENT_TOPRIGHT		=	0x14,	//!<�E��
		TEXTUREALIGNMENT_CENTERLEFT		=	0x21,	//!<����
		TEXTUREALIGNMENT_CENTERCENTER	=	0x22,	//!<����
		TEXTUREALIGNMENT_CENTERRIGHT	=	0x24,	//!<�E��
		TEXTUREALIGNMENT_BOTTOMLEFT		=	0x41,	//!<����
		TEXTUREALIGNMENT_BOTTOMCENTER	=	0x42,	//!<����
		TEXTUREALIGNMENT_BOTTOMRIGHT	=	0x44,	//!<�E��

		TEXTUREALIGNMENT_VERTICAL		=	0x70,	//!<�c
		TEXTUREALIGNMENT_HORIZON		=	0x07,	//!<��
		TEXTUREALIGNMENT_MAX			=	0x77,	//!<�ő吔

		TEXTUREALIGNMENT_USER			=	0x100,	//!<���[�U�[�w����W

		//-------------------------------------------------
		//�Z�k���̒�`
		//-------------------------------------------------
		TEXALIGN_TOP					=	0x10,	//!<��
		TEXALIGN_VCENTER				=	0x20,	//!<��
		TEXALIGN_BOTTOM					=	0x40,	//!<��
		TEXALIGN_LEFT					=	0x01,	//!<��
		TEXALIGN_HCENTER				=	0x02,	//!<��
		TEXALIGN_RIGHT					=	0x04,	//!<�E

		TEXALIGN_TOPLEFT				=	0x11,	//!<����
		TEXALIGN_TOPCENTER				=	0x12,	//!<����
		TEXALIGN_TOPRIGHT				=	0x14,	//!<�E��
		TEXALIGN_CENTERLEFT				=	0x21,	//!<����
		TEXALIGN_CENTERCENTER			=	0x22,	//!<����
		TEXALIGN_CENTERRIGHT			=	0x24,	//!<�E��
		TEXALIGN_BOTTOMLEFT				=	0x41,	//!<����
		TEXALIGN_BOTTOMCENTER			=	0x42,	//!<����
		TEXALIGN_BOTTOMRIGHT			=	0x44,	//!<�E��

		TEXALIGN_VERTICAL				=	0x70,	//!<�c
		TEXALIGN_HORIZON				=	0x07,	//!<��
		TEXALIGN_MAX					=	0x77,	//!<�ő吔

		TEXALIGN_USER					=	0x100,	//!<���[�U�[�w����W
	}TextureAlignment;
	
	/*******************************//*!
	@brief	�X�v���C�g�`��X�v���C�g�����̓R���X�^���g�o�b�t�@

	@author	CDW
	*//********************************/
	typedef struct tag_TextureRenderParameter {
		Vector4					vOffset;
		Vector4					vSize;
		Vector4					tOffset;
		Vector4					tSize;
		Vector4					Color;
		Matrix44				World;

		tag_TextureRenderParameter() :
		vOffset(), 
		vSize(1.0f, 1.0f, 1.0f, 1.0f),
		tOffset() ,
		tSize(1.0f,1.0f,1.0f,1.0f) ,
		Color(1.0f,1.0f,1.0f,1.0f),
		World() {
		}
	}TextureRenderParameter,*LPTextureRenderParameter;

	/*******************************//*!
	@brief	�e�N�X�`�����C���^�[�t�F�C�X

			�e�N�X�`�����ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API ITexture : public IMofNamedObject , public IMofCopyObject< ITexture > {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�e�N�X�`���̓ǂݍ���
				@param[in]		pName		�t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			����������̃e�N�X�`���̓ǂݍ���
				@param[in]		pName		���O
				@param[in]		pData		�������A�h���X
				@param[in]		Size		�T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size) = 0;
		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕ۑ�
				@param[in]		pName		�t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Save(LPCMofChar pName) = 0;

		/*************************************************************************//*!
				@brief			�e�N�X�`���̐���
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Format		�t�H�[�}�b�g
				@param[in]		Usage		�Ǘ����@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(const MofU32 w, const MofU32 h, const PixelFormat Format, const BufferAccess Usage) = 0;
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g�p�e�N�X�`���̐���
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Format		�t�H�[�}�b�g
				@param[in]		Usage		�Ǘ����@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateTarget(const MofU32 w, const MofU32 h, const PixelFormat Format, const BufferAccess Usage) = 0;
				
		/*************************************************************************//*!
				@brief			�o�b�t�@�̃}�b�v<br>
								�e�N�X�`���̃����������b�N���āA�擪�̃A�h���X��Ԃ��B
				@param[in]		mt				�}�b�v�^�C�v
				@param[out]		pRowPitch		���̃o�C�g��
				
				@return			�}�b�v���ꂽ�������A�h���X��Ԃ��B<br>
								���s�̏ꍇNULL�ɂȂ�B
		*//**************************************************************************/
		virtual LPMofVoid Map(MofU32 mt, LPMofU32 pRowPitch = NULL) = 0;
		/*************************************************************************//*!
				@brief			�o�b�t�@�̃A���}�b�v<br>
								�e�N�X�`���̃������̃��b�N����������B<br>
								�e�N�X�`���������ւ̏������݂�CPU�ւ̃}�b�v�A���b�N���s�v�Ȋ��ł͌Ăяo���K�v�͂Ȃ��B
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool UnMap(void) = 0;

		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////���W�w��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment) = 0;



		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;
					
		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////�o�͋�`�ւ̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,MofU32 col) = 0;



		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,const Rectangle& srec,MofU32 col) = 0;

		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////�g��{���w��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,MofU32 col,TextureAlignment Alignment) = 0;


		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,TextureAlignment Alignment) = 0;
				


		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;



		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;



		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////��]�p�x�w��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,TextureAlignment Alignment) = 0;


				
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;


			  
		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////�g��{���A��]�p�x�w��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,TextureAlignment Alignment) = 0;



		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment) = 0;
		
		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////2D��Ԃł̍s��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Pivot		�A���C�����g�ʒu
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col,const Vector3& Pivot) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Pivot		�A���C�����g�ʒu
				@param[in]		Size		�T�C�Y
				@param[in]		uvp			UV�ړ�
				@param[in]		uvs			UV�g��
				@param[in]		uva			UV��]
				@param[in]		vpos		���_�ړ�
				@param[in]		vcol		���_�J���[
				@param[in]		vcolr		���_�J���[���[�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Rectangle& srec, const Vector4& col, const Vector3& Pivot, const Vector3& Size, const Vector2& uvp, const Vector2& uvs, const MofFloat uva, LPVector2 vpos, LPVector4 vcol, MofFloat vcolr) = 0;
		
		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////3D��Ԃł̍s��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�`��F
				@param[in]		bRatio		�䗦�ێ��t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,MofU32 col,MofBool bRatio) = 0;
		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		bRatio		�䗦�ێ��t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col,MofBool bRatio) = 0;



		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���擾
				@param			None

				@return			�e�N�X�`��
		*//**************************************************************************/
		virtual MofTexture GetTexture(void) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���擾
				@param			None

				@return			�e�N�X�`��
		*//**************************************************************************/
		virtual MofTextureHandle GetTextureHandle(void) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���֕`�悷�邽�߂̕`��^�[�Q�b�g���擾
				@param			None
				
				@return			�`��^�[�Q�b�g��Ԃ��B
								���s�̏ꍇNULL�ɂȂ�B
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTarget(void) = 0;
		/*************************************************************************//*!
				@brief			���擾
				@param			None

				@return			�摜�̕�
		*//**************************************************************************/
		virtual MofU32 GetWidth(void) const = 0;
		/*************************************************************************//*!
				@brief			�����擾
				@param			None

				@return			�摜�̍���
		*//**************************************************************************/
		virtual MofU32 GetHeight(void) const = 0;
	};

	//�|�C���^�u������
	typedef ITexture*			LPTexture;
	typedef CDynamicArray< LPTexture >		CTextureArray,*LPTextureArray;
}

#endif

//[EOF]