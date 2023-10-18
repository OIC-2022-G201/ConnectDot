/*************************************************************************//*!
					
					@file	DX11Texture.h
					@brief	DirectX11�e�N�X�`�����N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11TEXTURE__H__

#define		__DX11TEXTURE__H__

//INCLUDE
#include	"../TextureBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11�e�N�X�`���N���X

			DirectX11�ł̃e�N�X�`���ǂݍ��݁A�`����s���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Texture : public CTextureBase {
	protected:
		/*******************//*!
		�e�N�X�`��
		*//********************/
		ID3D11Texture2D*			m_pTexture;
		/*******************//*!
		�V�F�[�_�[���\�[�X
		*//********************/
		ID3D11ShaderResourceView*	m_pShaderResourceView;
		/*******************//*!
		�`��^�[�Q�b�g
		*//********************/
		LPRenderTarget				m_pRenderTarget;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Texture();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�e�N�X�`��

				@return			None
		*//**************************************************************************/
		CDX11Texture(const CDX11Texture& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Texture();

		/*************************************************************************//*!
				@brief			�e�N�X�`���̓ǂݍ���
				@param[in]		pName		�t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			����������̃e�N�X�`���̓ǂݍ���
				@param[in]		pName		���O
				@param[in]		pData		�������A�h���X
				@param[in]		Size		�T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size);
		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕ۑ�
				@param[in]		pName		�t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Save(LPCMofChar pName);

		/*************************************************************************//*!
				@brief			�e�N�X�`���̐���
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Format		�t�H�[�}�b�g
				@param[in]		Usage		�Ǘ����@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(const MofU32 w, const MofU32 h, const PixelFormat Format, const BufferAccess Usage);
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g�p�e�N�X�`���̐���<br>
								D3D11_TEXTURE2D_DESC�\���̂�BindFlags��D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE<br>
								CPUAccessFlags��0��ݒ肵�ăe�N�X�`���𐶐�����B<br>
								�e�N�X�`��������A�`��^�[�Q�b�g�̐��������s�����B

				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Format		�t�H�[�}�b�g
				@param[in]		Usage		�Ǘ����@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateTarget(const MofU32 w, const MofU32 h, const PixelFormat Format, const BufferAccess Usage);
		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[�e�N�X�`��<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual ITexture* CreateCopyObject(void) const;
		
		/*************************************************************************//*!
				@brief			�o�b�t�@�̃}�b�v
				@param[in]		mt				�}�b�v�^�C�v
				@param[out]		pRowPitch		���̃o�C�g��
				
				@return			�}�b�v���ꂽ�������A�h���X��Ԃ��B<br>
								���s�̏ꍇNULL�ɂȂ�B
		*//**************************************************************************/
		virtual LPMofVoid Map(MofU32 mt, LPMofU32 pRowPitch = NULL);
		/*************************************************************************//*!
				@brief			�o�b�t�@�̃A���}�b�v
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool UnMap(void);

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
				@brief			�e�N�X�`���擾<br>
								m_pShaderResourceView���擾����B<br>
								�`��^�[�Q�b�g�Ƃ��Ďg�p���Ă���e�N�X�`���̏ꍇ�A<br>
								���̊֐��̎��s��CreateShaderResourceView�����s��m_pShaderResourceView�𐶐�����B
				@param			None

				@return			�e�N�X�`��
		*//**************************************************************************/
		virtual MofTexture GetTexture(void);
		/*************************************************************************//*!
				@brief			�e�N�X�`���擾<br>
								m_pTexture���擾����B
				@param			None

				@return			�e�N�X�`��
		*//**************************************************************************/
		virtual MofTextureHandle GetTextureHandle(void);
		/*************************************************************************//*!
				@brief			�e�N�X�`���֕`�悷�邽�߂̕`��^�[�Q�b�g���擾<br>
								CreateTarget�Ő������ꂽ�e�N�X�`���ɂ̂ݗL���B<br>
								m_pShaderResourceView����������Ă���ꍇ�A���̊֐��̎��s��m_pShaderResourceView�͉�������B
				@param			None
				
				@return			�`��^�[�Q�b�g��Ԃ��B
								���s�̏ꍇNULL�ɂȂ�B
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTarget(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11Texture,MOF_DX11TEXTURECLASS_ID);
	};

	#include	"DX11Texture.inl"
	
	//�u������
	typedef CDX11Texture		CTexture;

}

#endif

//[EOF]