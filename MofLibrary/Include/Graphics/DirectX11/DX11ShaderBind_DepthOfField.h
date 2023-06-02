/*************************************************************************//*!
					
					@file	DX11ShaderBind_DepthOfField.h
					@brief	��ʊE�[�x�V�F�[�_�[�o�C���h�B<br>
							��ʊE�[�x�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.04.27
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_DEPTHOFFIELD__H__

#define		__DX11SHADERBIND_DEPTHOFFIELD__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�x�����C�e�B���O�V�F�[�_�[�o�C���h�B

			�x�����C�e�B���O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_DepthOfField : public CDX11ShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_DEPTHOFFIELD = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�v���~�e�B�u�`�惉�C�g�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstDoFParam
		{
			MofFloat	FocalDistance;
			MofFloat	FocalRange;
			MofFloat	FocalAttenuation;
			MofFloat	Far;
		};
		/*******************//*!
		�v���~�e�B�u�`�惉�C�g���ݒ�
		*//********************/
		ConstDoFParam							m_DoFParam;
	protected:
		/*******************//*!
		���C�g�����̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstDoF;
		/*******************//*!
		�ڂ����e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pBlurTex;
		/*******************//*!
		�[�x�e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pDepthTex;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_DepthOfField();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_DepthOfField(const CDX11ShaderBind_DepthOfField& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_DepthOfField();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_DepthOfField,MOF_DX11SHADERBINDDEPTHOFFIELDCLASS_ID);
	};

	#include	"DX11ShaderBind_DepthOfField.inl"
	
	//�u������
	typedef CDX11ShaderBind_DepthOfField		CShaderBind_DepthOfField;
	typedef CShaderBind_DepthOfField*			LPShaderBind_DepthOfField;
}

#endif

//[EOF]