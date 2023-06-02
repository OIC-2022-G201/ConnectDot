/*************************************************************************//*!
					
					@file	ShaderEffect_HDR.h
					@brief	HDR�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.15
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_HDR__H__

#define		__SHADEREFFECT_HDR__H__

//INCLUDE
#include	"ShaderEffect_SampleLuminance.h"
#include	"ShaderEffect_DownScale.h"
#include	"ShaderEffect_BrightPass.h"
#include	"ShaderEffect_HDRBrightPass.h"
#include	"ShaderEffect_GaussianBlur.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	HDR�V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_HDR : public CShaderEffect_2DBase {
	protected:
		/*******************//*!
		�g�[���}�b�v�t���O
		*//********************/
		MofBool							m_bToneMap;
		/*******************//*!
		�P�x����p�e�N�X�`���̔z��
		*//********************/
		LPTextureArray					m_pTexLuminance;
		/*******************//*!
		�g�[���}�b�v�̊�ƂȂ�P�x�e�N�X�`��
		*//********************/
		LPTexture						m_pTexAdaptedLuminanceCur;
		/*******************//*!
		���P�x���o��e�N�X�`��
		*//********************/
		LPTexture						m_pTexBright;
		/*******************//*!
		�������u���[�o�͐�e�N�X�`��
		*//********************/
		LPTexture						m_pTexBloomX;
		/*******************//*!
		�c���������u���[�o�͐�e�N�X�`��
		*//********************/
		LPTexture						m_pTexBloomY;
		/*******************//*!
		�F�e�N�X�`������P�x�֕ϊ�����V�F�[�_�[
		*//********************/
		LPShaderEffect_SampleLuminance	m_pSampleLuminance;
		/*******************//*!
		�P�x����p�̏k���V�F�[�_�[
		*//********************/
		LPShaderEffect_DownScale		m_pDownScale;
		/*******************//*!
		���P�x���o�V�F�[�_�[
		*//********************/
		LPShaderEffect_BrightPass		m_pBrightPass;
		/*******************//*!
		���P�x���o�V�F�[�_�[
		*//********************/
		LPShaderEffect_HDRBrightPass	m_pToneBrightPass;
		/*******************//*!
		�K�E�X�ڂ����V�F�[�_�[
		*//********************/
		LPShaderEffect_GaussianBlur		m_pGBlur;
		/*******************//*!
		���E�V�~�����[�V�����̕ω����x(0.0f�`1.0f)
		*//********************/
		MofFloat						m_LumTransitionSpeed;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_HDR();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		bTone		�g�[���}�b�v�L���t���O

				@return			None
		*//**************************************************************************/
		CShaderEffect_HDR(MofBool bTone);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_HDR();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		TargetSize	�`���

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TargetSize);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		TargetSize	�`���
				@param[in]		Bloom		�u���[���X�P�[��

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TargetSize, MofU32 Bloom);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		TargetSize		�`���
				@param[in]		Bloom			�u���[���X�P�[��
				@param[in]		LumTexFormat	�P�x�e�N�X�`���̃t�H�[�}�b�g

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TargetSize, MofU32 Bloom, PixelFormat LumTexFormat);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTex);
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex);
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
		@param[in]		pTex		�e�N�X�`��
		@param[in]		BlurRepeat	�ڂ�����
		@param[in]		pBlurSteps	�񐔂��Ƃ̂ڂ������̔z��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex,MofU32 BlurRepeat,LPMofFloat pBlurSteps);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�����V�~�����[�V�����̕ω����x
				@param[in]		MiddleGray	0.0f�`1.0f�̕ω����x
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetLumTransitionSpeed(MofFloat Speed);
		/*************************************************************************//*!
				@brief			���邳�̊�l��ݒ�
				@param[in]		MiddleGray	���邳�̊�l
				@param[in]		BloomScale	�u���[���̖��邳�{��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetToneMapParam(MofFloat MiddleGray,MofFloat BloomScale);
		/*************************************************************************//*!
				@brief			���P�x�����o�̃p�����[�^�ݒ�
				@param[in]		Threshold			臒l
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBrightPassParam(MofFloat Threshold);
		/*************************************************************************//*!
				@brief			���P�x�����o�̃p�����[�^�ݒ�
				@param[in]		Threshold			臒l
				@param[in]		MiddleGray			���邳�̊�l
				@param[in]		BrightPassOffset	�␳
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBrightPassParam(MofFloat Threshold,MofFloat MiddleGray,MofFloat BrightPassOffset);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_HDR,MOF_SHADEREFFECTHDRCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_HDR*			LPShaderEffect_HDR;

#include	"ShaderEffect_HDR.inl"

}

#endif

//[EOF]