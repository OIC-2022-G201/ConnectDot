/*************************************************************************//*!
					
					@file	ShaderEffect_DepthOutput.h
					@brief	�}���`�����_�����O�ɂ��[�x�e�N�X�`���`��V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.01
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_DEPTHOUTPUT__H__

#define		__SHADEREFFECT_DEPTHOUTPUT__H__

//INCLUDE
#include	"ShaderEffect_3DBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�}���`�����_�����O�ɂ��[�x�e�N�X�`���`��V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_DepthOutput : public CShaderEffect_3DBase {
	protected:
		/*******************//*!
		�[�x�e�N�X�`��
		*//********************/
		LPTexture m_pDepthTex;
		/*******************//*!
		�}���`�����_�����O�t���O
		*//********************/
		MofBool m_MultiRender;
		/*******************//*!
		�[�x�e�N�X�`���`��p�[�x�o�b�t�@
		*//********************/
		LPDepthTarget m_pDepthTarget;

		LPRenderTarget m_pOrigRenderTarget;	//<!�ޔ�
		LPDepthTarget m_pOrigDepthTarget;	//<!�ޔ�
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_DepthOutput();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_DepthOutput();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		TexFormat		�[�x�e�N�X�`���̃t�H�[�}�b�g
				@param[in]		DepthFormat		�[�x�e�N�X�`���`��p�̐[�x�o�b�t�@�t�H�[�}�b�g
				@param[in]		MultiRender		�}���`�����_�����O�t���O

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(PixelFormat TexFormat,PixelFormat DepthFormat,MofBool MultiRender);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			�J�n
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Begin();
		/*************************************************************************//*!
				@brief			�I��
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool End();

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̎擾
				@param[in]		n			�ԍ�
					
				@return			�e�N�X�`��
		*//**************************************************************************/
		virtual LPTexture GetTexture(MofU32 n);
		/*************************************************************************//*!
				@brief			�[�x�e�N�X�`���̎擾
				@param			None
				
				@return			�[�x�e�N�X�`��
		*//**************************************************************************/
		virtual LPTexture GetDepthTexture();

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_DepthOutput,MOF_SHADEREFFECTDEPTHOUTPUTCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_DepthOutput*			LPShaderEffect_DepthOutput;

#include	"ShaderEffect_DepthOutput.inl"

}

#endif

//[EOF]