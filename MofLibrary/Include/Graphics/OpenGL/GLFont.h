/*************************************************************************//*!
					
					@file	GLFont.h
					@brief	OpenGL�t�H���g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLFONT__H__

#define		__GLFONT__H__

//INCLUDE
#include	"../FontBase.h"
#include	"GLTexture.h"

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
		x(0) ,
		y(0) ,
		Width(0) ,
		Height(0) ,
		String() {
		}
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pStr		�o�^������

				@return			None
		*//**************************************************************************/
		tag_MOFCHARINPUT(LPCMofChar pStr) :
		x(0) ,
		y(0) ,
		Width(0) ,
		Height(0) ,
		String(pStr) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_MOFCHARINPUT(){
			String.SetString(NULL);
		}
	}MOFCHARINPUT,*LPMOFCHARINPUT;
	typedef CDynamicArray< LPMOFCHARINPUT > CFontCharaInputArray,*LPFontCharaInputArray;

	/*******************************//*!
	@brief	OpenGL�t�H���g�N���X

			OpenGL�t�H���g�̓ǂݍ��݁A�ݒ���s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLFont : public CFontBase {
	protected:
		/*******************//*!
		�e�N�X�`��
		*//********************/
		LPTexture				m_pTexture;
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
		
		/*************************************************************************//*!
				@brief			�`�敶���̐���
				@param[in]		pText		������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateString(LPCMofChar pText);
		/*************************************************************************//*!
				@brief			�w�蕶����̓o�^�����擾
				@param[in]		pText		������

				@return			�w�蕶����̓o�^���<br>
								�o�^����Ă��Ȃ��ꍇNULL��Ԃ�
		*//**************************************************************************/
		LPMOFCHARINPUT GetInputChar(LPCMofChar pText);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLFont();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLFont();
		
		/*************************************************************************//*!
				@brief			�t�H���g�̐���
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(void);
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
				@brief			�����`���`�̌v�Z
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pText		�`�敶����
				@param[out]		rec			�o�͋�`
				
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

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CGLFont,MOF_GLFONTCLASS_ID);
	};

	#include	"GLFont.inl"
	
	//�u������
	typedef CGLFont	CFont;
}

#endif

//[EOF]
