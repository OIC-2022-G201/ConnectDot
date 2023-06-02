/*************************************************************************//*!
					
					@file	Font.h
					@brief	�t�H���g���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__FONT__H__

#define		__FONT__H__

//INCLUDE
#include	"Shader.h"

namespace Mof {

	/*******************************//*!
	@brief	�t�H���g�N���X�����Ńe�N�X�`���ւ̕����I�t�Z�b�g���L�^����\����

			�t�H���g�N���X�����Ńe�N�X�`���ւ̕����I�t�Z�b�g���L�^����\���́B<br>
			��{�I�ɓ����Ŋm�ہE�Ǘ����s���B

	@author	CDW
	*//********************************/
	typedef struct tag_MOFCHARINPUT {
		MofU32						x;								//X�ʒu
		MofU32						y;								//Y�ʒu
		MofU32						Width;							//��
		MofU32						Height;							//����
		CString						String;							//�o�^������

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MOFCHARINPUT() :
			x(0),
			y(0),
			Width(0),
			Height(0),
			String() {
		}
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pStr		�o�^������

				@return			None
		*//**************************************************************************/
		tag_MOFCHARINPUT(LPCMofChar pStr) :
			x(0),
			y(0),
			Width(0),
			Height(0),
			String(pStr) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFCHARINPUT() {
			String.SetString(NULL);
		}
	}MOFCHARINPUT, *LPMOFCHARINPUT;
	typedef CDynamicArray< LPMOFCHARINPUT > CFontCharaInputArray, *LPFontCharaInputArray;

	/*******************************//*!
	@brief	�t�H���g�C���^�[�t�F�C�X

			�t�H���g�̓ǂݍ��݁A�ݒ���s�����߂̃C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IFont : public IMofNamedObject {
	public:
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(void) = 0;
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofFont hFont) = 0;
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param[in]		s			�����T�C�Y
				@param[in]		pFace		�����^�C�v
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,LPCMofChar pFace) = 0;
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param[in]		s			�����T�C�Y
				@param[in]		bold		����
				@param[in]		bi			�Α�
				@param[in]		pFace		�����^�C�v
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(const MofS32 s,const MofS32 bold,const MofBool bi,LPCMofChar pFace) = 0;
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
		virtual MofBool Create(const MofS32 s,const MofS32 bold,const MofBool bi,const MofBool bu,const MofBool bs,LPCMofChar pFace) = 0;
		/*************************************************************************//*!
				@brief			�`�敶���̐���
				@param[in]		pText		������

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateString(LPCMofChar pText) = 0;
		
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderFormatString(MofFloat px,MofFloat py,LPCMofChar pText,...) = 0;
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderFormatString(MofFloat px,MofFloat py,MofU32 col,LPCMofChar pText,...) = 0;
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		drec		�`���`
				@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderFormatString(Rectangle& drec,LPCMofChar pText,...) = 0;
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		drec		�`���`
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderFormatString(Rectangle& drec,MofU32 col,LPCMofChar pText,...) = 0;

		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderString(MofFloat px,MofFloat py,LPCMofChar pText) = 0;
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderString(MofFloat px,MofFloat py,MofU32 col,LPCMofChar pText) = 0;
		
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		drec		�`���`
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderString(Rectangle& drec,LPCMofChar pText) = 0;
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		drec		�`���`
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderString(Rectangle& drec,MofU32 col,LPCMofChar pText) = 0;
		
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		scl			�`��X�P�[��
				@param[in]		pText		�`�敶����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat scl, LPCMofChar pText) = 0;
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
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat scl, MofU32 col,LPCMofChar pText) = 0;
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
		virtual MofBool RenderStringScale(MofFloat px,MofFloat py, MofFloat lh, MofFloat scl, MofU32 col,LPCMofChar pText) = 0;

		/*************************************************************************//*!
				@brief			�����`���`�̌v�Z
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pText		�`�敶����
				@param[out]		Out			�o�͋�`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CalculateStringRect(MofFloat px,MofFloat py,LPCMofChar pText,Rectangle& Out) = 0;
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�T�C�Y�ݒ�
				@param[in]		s				�T�C�Y
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetSize(MofS32 s) = 0;
		/*************************************************************************//*!
				@brief			�����ݒ�
				@param[in]		s				����
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetBold(MofS32 s) = 0;
		/*************************************************************************//*!
				@brief			�Α̐ݒ�
				@param[in]		bi				�Α�
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetItalic(MofBool bi) = 0;
		/*************************************************************************//*!
				@brief			�����ݒ�
				@param[in]		bi				����
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetUnderline(MofBool bi) = 0;
		/*************************************************************************//*!
				@brief			�ŏ������ݒ�
				@param[in]		bi				�ŏ�����
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetStrikeOut(MofBool bi) = 0;
		/*************************************************************************//*!
				@brief			��{�F�ݒ�
				@param[in]		c				�F
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetDefaultColor(MofU32 c) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�t�H���g�T�C�Y�擾
				@param			None

				@return			�t�H���g�T�C�Y
		*//**************************************************************************/
		virtual MofS32 GetSize(void) = 0;
		/*************************************************************************//*!
				@brief			�t�H���g�����擾
				@param			None

				@return			�t�H���g����
		*//**************************************************************************/
		virtual MofS32 GetBold(void) = 0;
		/*************************************************************************//*!
				@brief			�t�H���g�Α̎擾
				@param			None

				@return			�t�H���g�Α�
		*//**************************************************************************/
		virtual MofBool GetItalic(void) = 0;
		/*************************************************************************//*!
				@brief			�t�H���g�^�C�v���擾
				@param			None

				@return			�t�H���g�^�C�v��
		*//**************************************************************************/
		virtual LPString GetFontFace(void) = 0;
		/*************************************************************************//*!
				@brief			�w�蕶����̓o�^�����擾
				@param[in]		pText		������

				@return			�w�蕶����̓o�^���<br>
								�o�^����Ă��Ȃ��ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual LPMOFCHARINPUT GetInputChar(LPCMofChar pText) = 0;
		/*************************************************************************//*!
				@brief			�o�^�e�N�X�`�����擾
				@param			None

				@return			�o�^�e�N�X�`��
		*//**************************************************************************/
		virtual LPTexture GetTexture(void) = 0;
	};
	
	//�|�C���^�u������
	typedef IFont*			LPFont;
	typedef CDynamicArray< LPFont >		CFontArray,*LPFontArray;
}

//[EOF]

#endif