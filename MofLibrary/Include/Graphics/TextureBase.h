/*************************************************************************//*!
					
					@file	TextureBase.h
					@brief	�e�N�X�`�����N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__TEXTUREBASE__H__

#define		__TEXTUREBASE__H__

//INCLUDE
#include	"Texture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�e�N�X�`�����N���X

			���Ɉˑ����Ȃ���{�I�ȃe�N�X�`���̏������s�����N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CTextureBase : public ITexture {
	protected:
		/*******************//*!
		���O
		*//********************/
		CString						m_Name;
		/*******************//*!
		��
		*//********************/
		MofU32						m_Width;
		/*******************//*!
		����
		*//********************/
		MofU32						m_Height;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CTextureBase();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�e�N�X�`��

				@return			None
		*//**************************************************************************/
		CTextureBase(const CTextureBase& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CTextureBase();
		
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
		virtual MofBool Render(MofFloat px,MofFloat py);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,TextureAlignment Alignment);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment);



		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool Render(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);
		
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
		virtual MofBool Render(const Rectangle& drec);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,MofU32 col);



		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,const Rectangle& srec);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Rectangle& drec,const Rectangle& srec,MofU32 col);

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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,MofU32 col);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,TextureAlignment Alignment);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,MofU32 col,TextureAlignment Alignment);


		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,TextureAlignment Alignment);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,TextureAlignment Alignment);
				


		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);



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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderScale(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);



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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,MofU32 col);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,TextureAlignment Alignment);
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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,TextureAlignment Alignment);


				
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec);
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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderRotate(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);

		

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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,TextureAlignment Alignment);



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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment);
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
		virtual MofBool RenderScaleRotate(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment);
		
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
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col,const Vector3& Pivot);
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
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec, const Vector4& col,const Vector3& Pivot, const Vector3& Size, const Vector2& uvp, const Vector2& uvs, const MofFloat uva, LPVector2 vpos, LPVector4 vcol, MofFloat vcolr);

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
		virtual MofBool Render(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,MofU32 col);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�`��F
				@param[in]		bRatio		�䗦�ێ��t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,MofU32 col,MofBool bRatio);
		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		bRatio		�䗦�ێ��t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Rectangle& srec,MofU32 col,MofBool bRatio);



		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
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
				@brief			���擾
				@param			None

				@return			�摜�̕�
		*//**************************************************************************/
		virtual MofU32 GetWidth(void) const;
		/*************************************************************************//*!
				@brief			�����擾
				@param			None

				@return			�摜�̍���
		*//**************************************************************************/
		virtual MofU32 GetHeight(void) const;
	};

	#include	"TextureBase.inl"
}

#endif

//[EOF]