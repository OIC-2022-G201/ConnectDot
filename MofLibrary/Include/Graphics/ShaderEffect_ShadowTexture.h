/*************************************************************************//*!
					
					@file	ShaderEffect_ShadowTexture.h
					@brief	�V���h�E�}�b�v�p�[�x�e�N�X�`���`��V�F�[�_�[�B

															@author	CDW
															@date	2015.05.13
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_SHADOWTEXTURE__H__

#define		__SHADEREFFECT_SHADOWTEXTURE__H__

//INCLUDE
#include	"ShaderEffect_3DBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V���h�E�}�b�v�p�[�x�e�N�X�`���`��V�F�[�_�[�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_ShadowTexture : public CShaderEffect_3DBase {
	public:
		/*******************************//*!
		@brief	�V���h�E�}�b�v�`����

		@author	CDW
		*//********************************/
		enum ShadowType{
			SHADOW_NONE,
			SHADOW_NORMAL,
			SHADOW_VARIANCE,
		};
	protected:
		/*******************//*!
		���C�g���_�̃J����
		*//********************/
		CCamera m_LightCam;
		/*******************//*!
		�V���h�E�}�b�v�p�[�x�e�N�X�`��
		*//********************/
		LPTexture m_pShadowMapTex;
		/*******************//*!
		�[�x�e�N�X�`���`��p�[�x�o�b�t�@
		*//********************/
		LPDepthTarget m_pDepthTarget;

		LPCamera m_pOrigCamera;				//<!�ޔ�
		LPRenderTarget m_pOrigRenderTarget;	//<!�ޔ�
		LPDepthTarget m_pOrigDepthTarget;	//<!�ޔ�
		
		MofFloat m_LightMapRange;	//<!�V���h�E�}�b�v�ɕ`�悷��͈�
		MofFloat m_LightMapNear;	//<!�V���h�E�}�b�v�ɕ`�悷��ŏ�����
		MofFloat m_LightMapFar;		//<!�V���h�E�}�b�v�ɕ`�悷��ő勗��
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_ShadowTexture();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_ShadowTexture();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		TexSize �V���h�E�}�b�v�p�e�N�X�`���T�C�Y

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TexSize);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		TexSize		�V���h�E�}�b�v�p�e�N�X�`���T�C�Y
				@param[in]		Type		�V���h�E�}�b�v�̌`��
				@param[in]		TexFormat	�V���h�E�}�b�v�p�e�N�X�`���t�H�[�}�b�g
				@param[in]		DepthFormat	�V���h�E�}�b�v�`��p�̐[�x�o�b�t�@�t�H�[�}�b�g

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TexSize,ShadowType Type,PixelFormat TexFormat,PixelFormat DepthFormat);
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
				@brief			�J�n
				@param[in]		ShadowView	�V���h�E�}�b�v�`��p�̃r���[�s��
				@param[in]		ShadowProj	�V���h�E�}�b�v�`��p�̎ˉe�s��
		
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Begin(const Matrix44& ShadowView,const Matrix44& ShadowProj);
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
		/*************************************************************************//*!
				@brief			�V���h�E�}�b�v�͈̔͂�ݒ�
				@param[in]		Range		�V���h�E�}�b�v�ɕ`�悷��͈�
				@param[in]		Near		�V���h�E�}�b�v�ɕ`�悷��ŏ�����
				@param[in]		Far			�V���h�E�}�b�v�ɕ`�悷��ő勗��
					
				@return			None
		*//**************************************************************************/
		virtual void SetShadowMapParam(MofFloat Range,MofFloat Near,MofFloat Far);
		/*************************************************************************//*!
				@brief			���C�g���王�_�̃r���[�s��Ǝˉe�s��̐ݒ�
				@param[in]		LightView	�r���[�s��
				@param[in]		LightProj	�ˉe�s��
					
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetLightViewProjection(const Matrix44& LightView,const Matrix44& LightProj);

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
		virtual LPTexture GetShadowMapTexture();
		/*************************************************************************//*!
				@brief			���C�g���_�̃J����
				@param			None

				@return			���C�g���_�̃J����
		*//**************************************************************************/
		virtual LPCamera GetCamera(void);
		/*************************************************************************//*!
				@brief			���C�g���_�̃r���[�v���W�F�N�V�����s��擾
				@param			None

				@return			���C�g���_�̃r���[�v���W�F�N�V�����s��
		*//**************************************************************************/
		virtual CMatrix44& GetLightViewProjectionMatrix(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_ShadowTexture,MOF_SHADEREFFECTSHADOWTEXTURECLASS_ID);
	};

	// �u������
	typedef CShaderEffect_ShadowTexture*			LPShaderEffect_ShadowTexture;

#include	"ShaderEffect_ShadowTexture.inl"

}

#endif

//[EOF]