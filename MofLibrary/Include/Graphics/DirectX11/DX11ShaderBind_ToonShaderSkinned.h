/*************************************************************************//*!
					
					@file	DX11ShaderBind_ToonShaderSkinned.h
					@brief	�g�D�[�������_�����O�V�F�[�_�[�o�C���h�B<br>
							�g�D�[�������_�����O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.05.27
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_TOONSHADERSKINNED__H__

#define		__DX11SHADERBIND_TOONSHADERSKINNED__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_EdgeBaseOutputSkinned.h"

namespace Mof {

	/*******************************//*!
	@brief	�g�D�[�������_�����O�V�F�[�_�[�o�C���h�B

			�g�D�[�������_�����O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_ToonShaderSkinned : public CShaderBind_EdgeBaseOutputSkinned {
	public:
	protected:
		/*******************//*!
		�e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pToonMap;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToonShaderSkinned();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToonShaderSkinned(const CDX11ShaderBind_ToonShaderSkinned& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_ToonShaderSkinned();
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
	
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pTex		�e�N�X�`��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11ShaderBind_ToonShaderSkinned,MOF_DX11SHADERBINDTOONSHADERSKINNEDCLASS_ID);
	};
	
	#include	"DX11ShaderBind_ToonShaderSkinned.inl"

	//�u������
	typedef CDX11ShaderBind_ToonShaderSkinned		CShaderBind_ToonShaderSkinned;
	typedef CShaderBind_ToonShaderSkinned*		LPShaderBind_ToonShaderSkinned;
}

#endif

//[EOF]