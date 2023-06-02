/*************************************************************************//*!
					
					@file	DX11ShaderBind_BumpMappingSkinned.h
					@brief	�o���v�}�b�s���O�V�F�[�_�[�o�C���h�B<br>
							�o���v�}�b�s���O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.06.22
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_BUMPMAPPINGSKINNED__H__

#define		__DX11SHADERBIND_BUMPMAPPINGSKINNED__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_SkinGeometryBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�o���v�}�b�s���O�V�F�[�_�[�o�C���h�B

			�o���v�}�b�s���O�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_BumpMappingSkinned : public CShaderBind_SkinGeometryBase {
	public:
	protected:
		/*******************//*!
		�e�N�X�`��
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pNormalMap;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_BumpMappingSkinned();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_BumpMappingSkinned(const CDX11ShaderBind_BumpMappingSkinned& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_BumpMappingSkinned();
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pvb			���_�o�b�t�@�z��
				@param[in]		Cnt			���_�o�b�t�@�z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool CreateVertexLayout(LPVertexBuffer* pvb,MofU32 Cnt);
	
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_BumpMappingSkinned,MOF_DX11SHADERBINDBUMPMAPPINGSKINNEDCLASS_ID);
	};
	
	#include	"DX11ShaderBind_BumpMappingSkinned.inl"

	//�u������
	typedef CDX11ShaderBind_BumpMappingSkinned		CShaderBind_BumpMappingSkinned;
	typedef CShaderBind_BumpMappingSkinned*		LPShaderBind_BumpMappingSkinned;
}

#endif

//[EOF]