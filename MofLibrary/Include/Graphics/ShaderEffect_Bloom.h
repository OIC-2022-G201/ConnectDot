/*************************************************************************//*!
					
					@file	ShaderEffect_Bloom.h
					@brief	Bloom�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.11.09
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_BLOOM__H__

#define		__SHADEREFFECT_BLOOM__H__

//INCLUDE
#include	"ShaderEffect_BrightPass.h"
#include	"ShaderEffect_GaussianBlur.h"

namespace Mof {
	
	/*******************************//*!
	@brief	Bloom�V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_Bloom : public CShaderEffect_2DBase {
	protected:
		/*******************//*!
		���P�x���o��e�N�X�`��
		*//********************/
		LPTexture m_pTexBright;
		/*******************//*!
		�������u���[�o�͐�e�N�X�`��
		*//********************/
		LPTexture m_pTexBloomX;
		/*******************//*!
		�c���������u���[�o�͐�e�N�X�`��
		*//********************/
		LPTexture m_pTexBloomY;
		/*******************//*!
		���P�x���o�V�F�[�_�[
		*//********************/
		LPShaderEffect_BrightPass m_pBrightPass;
		/*******************//*!
		�K�E�X�ڂ����V�F�[�_�[
		*//********************/
		LPShaderEffect_GaussianBlur m_pGBlur;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_Bloom();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_Bloom();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		Bloom		�u���[���X�P�[��

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofU32 Bloom);
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
		virtual MofBool Render(LPTexture pTarget,LPTexture pTex,MofU32 BlurRepeat,LPMofFloat pBlurSteps);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�u���[���̖��邳�{���ݒ�
				@param[in]		BloomScale	�u���[���̖��邳�{��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBloomScale(MofFloat BloomScale);
		/*************************************************************************//*!
				@brief			���P�x�����o�̃p�����[�^�ݒ�
				@param[in]		Threshold			臒l
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBrightPassParam(MofFloat Threshold);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_Bloom,MOF_SHADEREFFECTBLOOMCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_Bloom*			LPShaderEffect_Bloom;

#include	"ShaderEffect_Bloom.inl"

}

#endif

//[EOF]