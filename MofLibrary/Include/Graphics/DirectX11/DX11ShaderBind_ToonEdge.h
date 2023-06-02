/*************************************************************************//*!
					
					@file	DX11ShaderBind_ToonEdge.h
					@brief	�g�D�[���֊s�`��V�F�[�_�[�o�C���h�B<br>
							�g�D�[���֊s�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.05.22
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_TOONEDGE__H__

#define		__DX11SHADERBIND_TOONEDGE__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�g�D�[���֊s�`��V�F�[�_�[�o�C���h�B

			�g�D�[���֊s�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_ToonEdge : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_TOONEDGE = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�g�D�[���֊s�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstToonEdgeParam
		{
			Vector4  EdgeColor;
			MofFloat ThresholdD;
			MofFloat ThresholdN;
			MofFloat Atten;
			MofFloat Far;
		};
		/*******************//*!
		�g�D�[���֊s���ݒ�
		*//********************/
		ConstToonEdgeParam							m_ToonEdgeParam;
	protected:
		/*******************//*!
		�g�D�[���֊s�����̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstToonEdge;
		/*******************//*!
		�[�x�@���e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pDepthNormalTex;
		/*******************//*!
		�}�X�N�e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pMaskTex;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToonEdge();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToonEdge(const CDX11ShaderBind_ToonEdge& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_ToonEdge();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_ToonEdge,MOF_DX11SHADERBINDTOONEDGECLASS_ID);
	};

	#include	"DX11ShaderBind_ToonEdge.inl"
	
	//�u������
	typedef CDX11ShaderBind_ToonEdge		CShaderBind_ToonEdge;
	typedef CShaderBind_ToonEdge*			LPShaderBind_ToonEdge;
}

#endif

//[EOF]