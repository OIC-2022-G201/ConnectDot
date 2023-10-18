/*************************************************************************//*!
					
					@file	DX11ShaderBind_HDRBrightPass.h
					@brief	HDR�p���P�x���o�V�F�[�_�[�o�C���h�B<br>
							HDR�p���P�x���o�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.05.18
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_HDRBRIGHTPASS__H__

#define		__DX11SHADERBIND_HDRBRIGHTPASS__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	HDR�p���P�x���o�V�F�[�_�[�o�C���h�B
	
			HDR�p���P�x���o�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_HDRBrightPass : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_HDRBRIGHTPASS = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,

			PARAM_HDRTHRESHOLD,
		};
		/*******************************//*!
		@brief	臒l�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstHDRBrightPassParam
		{
			MofFloat Threshold;
			MofFloat MiddleGray;
			MofFloat BrightPassOffset;
		};
		/*******************//*!
		�v���~�e�B�u�`��V�[�����ݒ�
		*//********************/
		ConstHDRBrightPassParam							m_HDRBrightPassParam;
	protected:
		/*******************//*!
		�X�v���C�g�����̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstHDRBrightPass;
		/*******************//*!
		�P�x�e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pAdaptedLumTex;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_HDRBrightPass();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_HDRBrightPass(const CDX11ShaderBind_HDRBrightPass& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_HDRBrightPass();
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		
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
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n);
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pData		�f�[�^
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pTex		�e�N�X�`��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ݒ�p�����[�^�[�����擾����
				@param			None

				@return			�p�����[�^�[�̐�
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const { return PARAM_MAX; }

		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11ShaderBind_HDRBrightPass,MOF_DX11SHADERBINDHDRBRIGHTPASSCLASS_ID);
	};

	#include	"DX11ShaderBind_HDRBrightPass.inl"
	
	//�u������
	typedef CDX11ShaderBind_HDRBrightPass		CShaderBind_HDRBrightPass;
	typedef CShaderBind_HDRBrightPass*			LPShaderBind_HDRBrightPass;
}

#endif

//[EOF]