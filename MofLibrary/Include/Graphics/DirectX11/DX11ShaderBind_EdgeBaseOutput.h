/*************************************************************************//*!
					
					@file	DX11ShaderBind_EdgeBaseOutput.h
					@brief	�G�b�W���o�V�F�[�_�[�����V�F�[�_�[�o�C���h�B<br>
							�G�b�W���o�V�F�[�_�[�����V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.06.01
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_EDGEBASEOUTPUT__H__

#define		__DX11SHADERBIND_EDGEBASEOUTPUT__H__

//INCLUDE
#include	"DX11ShaderBind_DepthOutput.h"

namespace Mof {

	/*******************************//*!
	@brief	�G�b�W���o�V�F�[�_�[�����V�F�[�_�[�o�C���h�B

			�G�b�W���o�V�F�[�_�[�����V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_EdgeBaseOutput : public CShaderBind_DepthOutput {
	public:
		/*******************************//*!
		@brief	���̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_MASK = CShaderBind_DepthOutput::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�}�X�N�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstMaskParam
		{
			MofFloat Mask;
		};
		/*******************//*!
		�}�X�N���ݒ�
		*//********************/
		ConstMaskParam							m_MaskParam;
	protected:
		/*******************//*!
		�}�X�N�����̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstMask;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_EdgeBaseOutput();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_EdgeBaseOutput(const CDX11ShaderBind_EdgeBaseOutput& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_EdgeBaseOutput();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_EdgeBaseOutput,MOF_DX11SHADERBINDEDGEBASEOUTPUTCLASS_ID);
	};

	#include	"DX11ShaderBind_EdgeBaseOutput.inl"
	
	//�u������
	typedef CDX11ShaderBind_EdgeBaseOutput		CShaderBind_EdgeBaseOutput;
	typedef CShaderBind_EdgeBaseOutput*			LPShaderBind_EdgeBaseOutput;
}

#endif

//[EOF]