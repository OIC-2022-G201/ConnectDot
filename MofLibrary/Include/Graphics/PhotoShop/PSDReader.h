/*************************************************************************//*!
					
					@file	PSDReader.h
					@brief	PSD�ǂݍ��ݗp�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__PSDREADER__H__

#define		__PSDREADER__H__

//INCLUDE
#include	"ImageReader.h"

namespace Mof {
	
	/*******************************//*!
	@brief	PSD�C���[�W�w�b�_�[�\����

			PSD�C���[�W�w�b�_�[�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_IMAGEHEADER {
		MofU16				Channels;				//!<�`�����l����
		MofU32				Row;					//!<�c�s�N�Z����
		MofU32				Column;					//!<���s�N�Z����
		MofU16				Depth;					//!<�r�b�g�k�x
	}PSD_IMAGEHEADER;
	
	/*******************************//*!
	@brief	PSD�w�b�_�[�f�[�^�\����

			PSD�w�b�_�[�f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_HEADER {
		MofU32				Magic;					//!<�}�W�b�N�i���o�[
		MofU16				Version;				//!<�t�@�C���o�[�W����
		MofU8				Reserved[6];			//!<�\���̈�
		MofU16				Channels;				//!<�`�����l����
		MofU32				Row;					//!<�c�s�N�Z����
		MofU32				Column;					//!<���s�N�Z����
		MofU16				Depth;					//!<�r�b�g�k�x
		MofU16				Mode;					//!<�J���[���[�h
	}PSD_HEADER,*LPPSD_HEADER;
	
	/*******************************//*!
	@brief	PSD�J���[���[�h�f�[�^�\����

			PSD�J���[���[�h�f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_COLOR_MODEDATA {
		MofU32				Length;					//!<�f�[�^�T�C�Y
		MofU8*				pData;					//!<�f�[�^�z��
	}PSD_COLOR_MODEDATA;
	
	/*******************************//*!
	@brief	PSD���\�[�X�f�[�^�\����

			PSD���\�[�X�f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_IMAGE_RESOURCE {
		MofU32				Length;					//!<�f�[�^�T�C�Y
		MofU32				Type;					//!<�f�[�^�^�C�v
		MofU16				ID;						//!<�f�[�^�ԍ�
		MofU8*				pName;					//!<�f�[�^��
		MofU32				Size;					//!<���\�[�X�T�C�Y
	}PSD_IMAGE_RESOURCE;

	/*******************************//*!
	@brief	PSD�𑜓x�f�[�^�\����

			PSD�𑜓x�f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_RESOLUTION_INFO {
		MofS16				HorzRes;				//!<���𑜓x
		MofS32				HorzResUnit;			//!<�f�B�X�v���C�𑜓x���[�h
		MofS16				WidthUnit;				//!<���𑜓x���[�h
		MofS16				VertRes;				//!<�c�𑜓x
		MofS32				VertResUnit;			//!<�f�B�X�v���C�𑜓x���[�h
		MofS16				HeightUnit;				//!<�c�𑜓x���[�h
	}PSD_RESOLUTION_INFO;
	
	/*******************************//*!
	@brief	PSD�𑜓x�f�[�^(Version2)�\����

			PSD�𑜓x�f�[�^(Version2)�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_RESOLUTION_INFO_V2 {
		MofS16				Channels;				//!<�`�����l����
		MofS16				Row;					//!<�c��
		MofS16				Column;					//!<����
		MofS16				Depth;					//!<�r�b�g�k�x
		MofS16				Mode;					//!<�J���[���[�h
	}PSD_RESOLUTION_INFO_V2;

	/*******************************//*!
	@brief	PSD�f�B�X�v���C�f�[�^�\����

			PSD�f�B�X�v���C�f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_DISPLAY_INFO {
		MofS16				ColorSpace;				//!<�F�Ԋu
		MofS16				Color[4];				//!<�F�f�[�^
		MofS16				Opacity;				//!<�s�����x
		MofBool				Kind;					//!<���
		MofU8				Padding;				//!<�l�ߕ�
	}PSD_DISPLAY_INFO;
	
	/*******************************//*!
	@brief	PSD�T���l�C���f�[�^�\����

			PSD�T���l�C���f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_THUMBNAIL_INFO {
		MofS32				Format;					//!<�t�H�[�}�b�g
		MofS32				Width;					//!<��
		MofS32				Height;					//!<����
		MofS32				WidthBytes;				//!<���o�C�g��
		MofS32				Size;					//!<�T�C�Y
		MofS32				CompressSize;			//!<���k��T�C�Y
		MofS16				BitPerPixel;			//!<1�r�b�g�̃s�N�Z����
		MofS16				Planes;					//!<�v���[���̐�
		MofU8*				pData;					//!<�f�[�^
	}PSD_THUMBNAIL_INFO;
	
	/*******************************//*!
	@brief	PSD�`�����l���f�[�^�\����

			PSD�`�����l���f�[�^�B
			ChannelID�̒l
				0			: ��
				1			: ��
				2			: ��
				-1(65535)	: �A���t�@

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_CHANNEL_LENGTH_INFO {
		MofU16				ChannelID;				//!<�`�����l���ԍ�
		MofS32				Length;					//!<����
	}PSD_CHANNEL_LENGTH_INFO,PSD_CLI;
	typedef CDynamicArray< PSD_CLI > PSDCLILIST,*LPPSDCLILIST;

	/*******************************//*!
	@brief	PSD�`�����l���͈͍\����

			PSD�`�����l���͈́B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_CHANNEL_SOURCE_DEST_RANGE {
		MofU8				Src[4];					//!<���͈�
		MofU8				Dest[4];				//!<�o�͔͈�
	}PSD_CHANNEL_SOURCE_DEST_RANGE,PSD_CSDR;
	typedef CDynamicArray< PSD_CSDR > PSDCSDRLIST,*LPPSDCSDRLIST;

	/*******************************//*!
	@brief	PSD�u�����f�B���O�͈̓f�[�^�\����

			PSD�u�����f�B���O�͈̓f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_BLENDING_RANGE {
		MofS32				Top;					//!<�͈͏�
		MofS32				Left;					//!<�͈͍�
		MofS32				Bottom;					//!<�͈͉�
		MofS32				Right;					//!<�͈͉E
		MofU8				Default;				//!<�f�t�H���g�F
		MofU8				Flags;					//!<�t���O
		MofU16				Padding;				//!<�l�ߕ�
	}PSD_BLENDING_RANGE;

	/*******************************//*!
	@brief	PSD�u�����f�B���O�f�[�^�\����

			PSD�u�����f�B���O�f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_BLENDING_INFO {
		MofU8				GraySrc[4];				//!<���͈�
		MofU8				GrayDest[4];			//!<�o�͔͈�
		LPPSDCSDRLIST		pSrcRange;				//!<���͈�
		CString				LayerName;				//!<���C���[��
	}PSD_BLENDING_INFO;
	
	/*******************************//*!
	@brief	PSD���C���[���f�[�^�\����

			PSD���C���[���f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_LAYER_INFO {
		MofS32				Left;					//!<�o�E���f�B���O�{�b�N�X�̍�
		MofS32				Top;					//!<�o�E���f�B���O�{�b�N�X�̏�
		MofS32				Right;					//!<�o�E���f�B���O�{�b�N�X�̉E
		MofS32				Bottom;					//!<�o�E���f�B���O�{�b�N�X�̉�
		MofU16				Channels;				//!<�`�����l����
		LPPSDCLILIST		pChannelInfo;			//!<�`�����l���f�[�^
		MofU8*				pLayerData;				//!<���C���[�f�[�^
		MofU32				LayerSize;				//!<���C���[�f�[�^�T�C�Y
		MofU32				BlendKey;				//!<�u�����f�B���O�L�[
		MofU8				Opacity;				//!<�s�����x
		MofU8				Clipping;				//!<�N���b�s���O
		MofU8				Flags;					//!<�t���O
		MofU8				Padding;				//!<�l�ߕ�
		PSD_BLENDING_RANGE	BlendRange;				//!<�A���t�@�u�����h�͈�
		PSD_BLENDING_INFO	BlendInfo;				//!<�u�����f�B���O�f�[�^
		LPMOFIMAGEDATA		pImage;					//!<�C���[�W�f�[�^
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PSD_LAYER_INFO() :
		Left(0) ,
		Top(0) ,
		Right(0) ,
		Bottom(0) ,
		Channels(0) ,
		pChannelInfo(NULL) ,
		pLayerData(NULL) ,
		LayerSize(0) ,
		BlendKey(0) ,
		Opacity(0) ,
		Clipping(0) ,
		Flags(0) ,
		Padding(0) ,
		BlendRange() ,
		BlendInfo() ,
		pImage(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PSD_LAYER_INFO(){
			BlendInfo.LayerName.SetString(NULL);
			MOF_SAFE_DELETE(BlendInfo.pSrcRange);
			MOF_SAFE_DELETE(pChannelInfo);
			MOF_SAFE_FREE(pLayerData,"CPSDReader Release");
		}
	}PSD_LAYER_INFO,*LPPSDLAYERINFO;
	typedef CDynamicArray< LPPSDLAYERINFO > CPSDLayerInfoArray,*LPPSDLayerInfoArray;

	/*******************************//*!
	@brief	PSD�}�X�N���f�[�^�\����

			PSD�}�X�N���f�[�^�B

	@author	CDW
	*//********************************/
	typedef struct tag_PSD_MASK_INFO {
		MofU16				Overlay;				//!<OverlayColorSpace
		MofU8				Color[8];				//!<ColorComponents
		MofU16				Opacity;				//!<0=���� 1=�s����
		MofU8				Kind;					//!<��� 0=Inverted 1=Protected 128=UseStoredValue
		MofU8				Padding;				//!<�l�ߕ�
	}PSD_MASK_INFO;

	//ENUM
	
	/*******************************//*!
	@brief	PSD�J���[���[�h��

			PSD�J���[���[�h�B

	@author	CDW
	*//********************************/
	enum tag_PSD_COLORMODE {
		PSD_COLORMODE_BITMAP		= 0,
		PSD_COLORMODE_GRAYSCALE		= 1,
		PSD_COLORMODE_INDEXED		= 2,
		PSD_COLORMODE_RGB			= 3,
		PSD_COLORMODE_CMYK			= 4,
		PSD_COLORMODE_MULTICANNEL	= 7,
		PSD_COLORMODE_DUOTONE		= 8,
		PSD_COLORMODE_LAB			= 9,
	};
	
	/*******************************//*!
	@brief	PSD���\�[�X��

			PSD���\�[�X�B

	@author	CDW
	*//********************************/
	enum tag_PSD_RESOURCE{
		PSDRES_RESOLUTIONINFOV2		= 1000,
		PSDRES_RESOLUTIONINFO		= 1005,
		PSDRES_DISPLAYINFO			= 1007,
		PSDRES_THUMBNAILINFOBGR		= 1033,
		PSDRES_THUMBNAILINFORGB		= 1036,
		PSDRES_COPYRIGHT			= 1034,
		PSDRES_GLOBALANGLE			= 1037,
		PSDRES_COLORCOUNT			= 1046,
		PSDRES_TRANSPARENTINDEX		= 1047,
	};
	
	/*******************************//*!
	@brief	PSD���k������

			PSD���k�����B

	@author	CDW
	*//********************************/
	enum tag_PSD_COMPRESSION{
		PSDCOMP_RAW					= 0,
		PSDCOMP_RLE					= 1,
		PSDCOMP_ZIPO				= 2,
		PSDCOMP_ZIP					= 3,
	};
	
	/*******************************//*!
	@brief	PSD���C���[�t���O��

			PSD���C���[�t���O�B

	@author	CDW
	*//********************************/
	enum tag_PSD_LAYERFLAGS {
		PSD_LAYERFLAG_VISIBLE		= 0x00000002,
		PSD_LAYERFLAG_GROUP			= 0x00000010,

		PSD_LAYERFLAG_ALL			= 0x00000012,
	};

	//CLASS
	
	/*******************************//*!
	@brief	PSD�t�@�C���ǂݍ��݃N���X

			PSD�t�@�C���ǂݍ��݃N���X�B

	@author	CDW
	*//********************************/
	class CPSDReader : public CImageReader {
	protected:
		/*******************//*!
		PSD�t�@�C��
		*//********************/
		FILE*					m_pFile;
		/*******************//*!
		�G���f�B�A���ϊ��t���O
		*//********************/
		MofBool					m_SwapEndian;
		/*******************//*!
		PSD�t�@�C���w�b�_�[
		*//********************/
		PSD_HEADER				m_Header;
		/*******************//*!
		�J���[���[�h�f�[�^
		*//********************/
		PSD_COLOR_MODEDATA		m_ColorMode;
		/*******************//*!
		�C���[�W���\�[�X
		*//********************/
		PSD_IMAGE_RESOURCE		m_ImageResource;
		/*******************//*!
		�s�N�Z���o�C�g
		*//********************/
		MofS32					m_BytesPerPixelPerChannels;
		/*******************//*!
		�𑜓x�f�[�^
		*//********************/
		PSD_RESOLUTION_INFO		m_ResInfo;
		/*******************//*!
		�𑜓x�f�[�^�ǂݍ��݃t���O
		*//********************/
		MofBool					m_ResInfoFilled;
		/*******************//*!
		�𑜓x�f�[�^Version2
		*//********************/
		PSD_RESOLUTION_INFO_V2	m_ResInfoV2;
		/*******************//*!
		�𑜓x�f�[�^�ǂݍ��݃t���OVersion2
		*//********************/
		MofBool					m_ResInfoV2Filled;
		/*******************//*!
		�f�B�X�v���C�f�[�^
		*//********************/
		PSD_DISPLAY_INFO		m_DisplayInfo;
		/*******************//*!
		�𑜓x�f�[�^�ǂݍ��݃t���O
		*//********************/
		MofBool					m_DisplayInfoFilled;
		/*******************//*!
		�f�B�X�v���C�f�[�^
		*//********************/
		PSD_THUMBNAIL_INFO		m_ThumbnailInfo;
		/*******************//*!
		�𑜓x�f�[�^�ǂݍ��݃t���O
		*//********************/
		MofBool					m_ThumbnailInfoFilled;
		/*******************//*!
		�R�s�[���C�g�ǂݍ��݃t���O
		*//********************/
		MofBool					m_Copyright;
		/*******************//*!
		�S�̊p�x
		*//********************/
		MofS32					m_GlobalAngle;
		/*******************//*!
		�F��
		*//********************/
		MofS16					m_ColorCount;
		/*******************//*!
		����
		*//********************/
		MofS16					m_TransparentIndex;
		/*******************//*!
		���k�t���O
		*//********************/
		MofS16					m_Compress;
		/*******************//*!
		���C���[�T�C�Y�Ƀt�B�b�g�����C���[�W�̐���
		*//********************/
		MofBool					m_LoadFit;
		/*******************//*!
		���C���[�f�[�^
		*//********************/
		CPSDLayerInfoArray		m_LayerInfo;

		/*************************************************************************//*!
				@brief			PSD�t�@�C������4Byte�̃f�[�^��ǂݍ���
				@param[in]		bSwap		�G���f�B�A���ύX�t���O

				@return			�����Ȃ���4Byte�f�[�^
		*//**************************************************************************/
		MofU32 GetLong(MofBool bSwap);
		/*************************************************************************//*!
				@brief			PSD�t�@�C������2Byte�̃f�[�^��ǂݍ���
				@param[in]		bSwap		�G���f�B�A���ύX�t���O

				@return			�����Ȃ���2Byte�f�[�^
		*//**************************************************************************/
		MofU16 GetShort(MofBool bSwap);
		/*************************************************************************//*!
				@brief			�w�b�_�[�̓ǂݍ���
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ReadHeader(void);
		/*************************************************************************//*!
				@brief			�J���[���[�h�f�[�^�̓ǂݍ���
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ReadColorModeData(void);
		/*************************************************************************//*!
				@brief			���\�[�X�̓ǂݍ���
				@param[in,out]	pResource	�o�̓��\�[�X
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ReadImageResource(PSD_IMAGE_RESOURCE* pResource);
		/*************************************************************************//*!
				@brief			���C���[���}�X�N�f�[�^�̓ǂݍ���
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ReadLayerAndMaskInfoSection(void);
		/*************************************************************************//*!
				@brief			�𑜓x�f�[�^�̓ǂݍ���
				@param			None
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadResolutionInfo(void);
		/*************************************************************************//*!
				@brief			�𑜓x�f�[�^Version2�̓ǂݍ���
				@param			None
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadResolutionInfoV2(void);
		/*************************************************************************//*!
				@brief			�f�B�X�v���C�f�[�^�̓ǂݍ���
				@param			None
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadDisplayInfo(void);
		/*************************************************************************//*!
				@brief			�T���l�C���f�[�^�ǂݍ���
				@param			None
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadThumbnailInfo(MofS32 ID,MofS32 Size);
		/*************************************************************************//*!
				@brief			���C���[�f�[�^�ǂݍ���
				@param[in,out]	pInfo		�o�̓��C���[���
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadLayerInfo(PSD_LAYER_INFO* pInfo);
		/*************************************************************************//*!
				@brief			���C���[�`�����l���ʃf�[�^�ǂݍ���
				@param[in,out]	pData		�o�̓f�[�^
				@param[in]		Pixels		�ǂݍ��݃s�N�Z����
				@param[in]		Skip		���C���[�I�t�Z�b�g�X�L�b�v
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadLayerChannels(MofU8* pData,MofS32 Pixels,MofS32 Skip);
		/*************************************************************************//*!
				@brief			�摜�f�[�^�ǂݍ���
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ReadImageData(void);
		/*************************************************************************//*!
				@brief			RAW�����k�`���摜�f�[�^�ǂݍ���
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ReadRAWImageData(void);
		/*************************************************************************//*!
				@brief			RLE���k�`���摜�f�[�^�ǂݍ���
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ReadRLEImageData(void);
		/*************************************************************************//*!
				@brief			���̑��̓ǂݍ���
				@param[in]		Size		�ǂݍ��݃f�[�^�T�C�Y
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadOtherData(MofS32 Size);
		/*************************************************************************//*!
				@brief			�R�s�[���C�g�ǂݍ���
				@param			None
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadCopyright(void);
		/*************************************************************************//*!
				@brief			�O���[�o���A���O���ǂݍ���
				@param			None
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadGlobalAngle(void);
		/*************************************************************************//*!
				@brief			�F���ǂݍ���
				@param			None
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadColorCount(void);
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�ǂݍ���
				@param			None
				
				@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofS32 ReadTransparentIndex(void);
		/*************************************************************************//*!
				@brief			���k�摜�ǂݍ��ݓW�J
				@param[in,out]	pData		�o�̓f�[�^
				@param[in]		Pixels		�ǂݍ��݃s�N�Z����
				@param[in]		ReadSize	�ǂݍ��݃f�[�^�T�C�Y
				
				@return			�f�[�^�T�C�Y��Ԃ�
		*//**************************************************************************/
		MofU32 UnCompressImageData(MofU8* pData,MofU32 Pixels,MofU32 ReadSize);
		/*************************************************************************//*!
				@brief			�`�����l�����s�N�Z���P�ʂŐ���
				@param[in]		pSrc		���f�[�^
				@param[in]		Pixels		�ǂݍ��݃s�N�Z����
				@param[in]		Channels	�W�J�`�����l��
				@param[in]		lSize		�ݒ�摜�T�C�Y
				
				@return			�\�[�g��̃s�N�Z������Ԃ�
		*//**************************************************************************/
		MofU8* SortPixelData(const MofU8* pSrc,MofS32 Pixels,MofS32 Channels,MofS32 lSize);
		/*************************************************************************//*!
				@brief			�ǂݍ��݃��\�[�X��������������
				@param[in,out]	pResource	�o�̓��\�[�X
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ResourceReset(PSD_IMAGE_RESOURCE* pResource);
		
		/*************************************************************************//*!
				@brief			�C���[�W�f�[�^��BMP�t�@�C���ō쐬����
				@param[in]		pName		���O
				@param[in]		pData		�f�[�^
				@param[in]		ImageWidth	��
				@param[in]		ImageHeight	����
				@param[in]		Channels	�`�����l����
				
				@return			���������C���[�W�f�[�^
		*//**************************************************************************/
		LPMOFIMAGEDATA CreateBitmap(LPCMofChar pName,const MofU8* pData,MofU32 ImageWidth,MofU32 ImageHeight,MofS32 Channels);
		/*************************************************************************//*!
				@brief			�C���[�W�f�[�^��DDS�t�@�C���ō쐬����
				@param[in]		pName		���O
				@param[in]		pData		�f�[�^
				@param[in]		ImageWidth	��
				@param[in]		ImageHeight	����
				@param[in]		Channels	�`�����l����
				
				@return			���������C���[�W�f�[�^
		*//**************************************************************************/
		LPMOFIMAGEDATA CreateDDS(LPCMofChar pName,const MofU8* pData,MofU32 ImageWidth,MofU32 ImageHeight,MofS32 Channels);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CPSDReader();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�C���[�W

				@return			None
		*//**************************************************************************/
		CPSDReader(const CPSDReader& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CPSDReader();

		/*************************************************************************//*!
				@brief			�t�@�C���̓ǂݍ���
				@param[in]		pName		�t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			PSD�w�b�_�[�擾
				@param			None

				@return			PSD�w�b�_�[
		*//**************************************************************************/
		LPPSD_HEADER GetHeader(void);
		/*************************************************************************//*!
				@brief			PSD���C���[���擾
				@param			None

				@return			PSD���C���[���
		*//**************************************************************************/
		LPPSDLayerInfoArray GetPSDLayerInfoList(void);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS(CPSDReader,MOF_PSDREADERCLASS_ID);
	};

	//TYPEDEF
	typedef CPSDReader* LPPSDReader;

	//INLINE INCLUDE
	#include	"PSDReader.inl"

}

#endif		//__PSDREADER__H__

//[EOF]