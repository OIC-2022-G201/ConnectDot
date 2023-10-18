/*************************************************************************//*!
					
					@file	DX11Font.h
					@brief	DirectX11�t�H���g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11FONT__H__

#define		__DX11FONT__H__

//INCLUDE
#include	"../FontBase.h"
#include	"DX11Texture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11�t�H���g�N���X

			DirectX11�t�H���g�̓ǂݍ��݁A�ݒ���s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Font : public CFontBase {
	protected:
		/*******************//*!
		�e�N�X�`��
		*//********************/
		LPTexture				m_pTexture;
		/*******************//*!
		�t�H���g�n���h��
		*//********************/
		MofFont					m_hFont;
		/*******************//*!
		�����}��X�ʒu
		*//********************/
		MofU32					m_InsertX;
		/*******************//*!
		�����}��Y�ʒu
		*//********************/
		MofU32					m_InsertY;
		/*******************//*!
		�����}�����C������
		*//********************/
		MofU32					m_InsertHeight;
		/*******************//*!
		�����Ǘ�������
		*//********************/
		LPFontCharaInputArray	m_pInputArray;
		/*******************//*!
		�e�N�X�`�������o�b�t�@
		*//********************/
		LPMofU8					m_pFontBuffer;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Font();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Font();
		
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(void);
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofFont hFont);
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param[in]		s			�����T�C�Y
				@param[in]		pFace		�����^�C�v
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,LPCMofChar pFace);
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param[in]		s			�����T�C�Y
				@param[in]		bold		����
				@param[in]		bi			�Α�
				@param[in]		pFace		�����^�C�v
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,const MofS32 bold,const MofBool bi,LPCMofChar pFace);
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param[in]		s			�����T�C�Y
				@param[in]		bold		����
				@param[in]		bi			�Α�
				@param[in]		bu			����
				@param[in]		bs			�ŏ�����
				@param[in]		pFace		�����^�C�v
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,const MofS32 bold,const MofBool bi,const MofBool bu,const MofBool bs,LPCMofChar pFace);
		/*************************************************************************//*!
				@brief			�`�敶���̐���
				@param[in]		pText		������

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateString(LPCMofChar pText);
		
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderString(MofFloat px,MofFloat py,LPCMofChar pText);
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderString(MofFloat px,MofFloat py,MofU32 col,LPCMofChar pText);
		
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		drec		�`���`
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderString(Rectangle& drec,LPCMofChar pText);
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		drec		�`���`
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderString(Rectangle& drec,MofU32 col,LPCMofChar pText);
		
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		scl			�`��X�P�[��
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat scl, LPCMofChar pText);
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		scl			�`��X�P�[��
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat scl, MofU32 col,LPCMofChar pText);
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		lh			�s��
				@param[in]		scl			�`��X�P�[��
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat lh, MofFloat scl, MofU32 col,LPCMofChar pText);

		/*************************************************************************//*!
				@brief			�����`���`�̌v�Z
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pText		�`�敶����
				@param[out]		Out			�o�͋�`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CalculateStringRect(MofFloat px,MofFloat py,LPCMofChar pText,Rectangle& Out);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		/*************************************************************************//*!
				@brief			�o�^�e�N�X�`�����擾
				@param			None

				@return			�o�^�e�N�X�`��
		*//**************************************************************************/
		virtual LPTexture GetTexture(void);
		/*************************************************************************//*!
				@brief			�w�蕶����̓o�^�����擾
				@param[in]		pText		������

				@return			�w�蕶����̓o�^���<br>
								�o�^����Ă��Ȃ��ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual LPMOFCHARINPUT GetInputChar(LPCMofChar pText);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CDX11Font,MOF_DX11FONTCLASS_ID);
	};

	#include	"DX11Font.inl"
	
	//�u������
	typedef CDX11Font	CFont;
}

#endif

//[EOF]