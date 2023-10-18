/*************************************************************************//*!
					
					@file	DX11ShaderTechnique.h
					@brief	DirectX11�V�F�[�_�[�e�N�j�b�N�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERTECHNIQUE__H__

#define		__DX11SHADERTECHNIQUE__H__

//INCLUDE
#include	"../ShaderTechniqueBase.h"
#include	"DX11ShaderPass.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11�V�F�[�_�[�e�N�j�b�N�N���X

			DirectX11�ł̃V�F�[�_�[�̃e�N�j�b�N�ݒ���s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderTechnique : public CShaderTechniqueBase {
	protected:
		/*******************//*!
		�V�F�[�_�[�e�N�j�b�N
		*//********************/
		ID3DX11EffectTechnique*	m_pTechnique;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderTechnique();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pTec		�e�N�j�b�N

				@return			None
		*//**************************************************************************/
		CDX11ShaderTechnique(ID3DX11EffectTechnique* pTec);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderTechnique(const CDX11ShaderTechnique& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderTechnique();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�e�N�j�b�N�̊J�n
				@param[in]		Flag		�K�p�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Begin(MofU32 Flag);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̊J�n
				@param[in]		nPass		�p�X�ԍ�
				@param[in]		Flag		�K�p�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool BeginPass(MofU32 nPass,MofU32 Flag);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�e�N�j�b�N�̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool End(void);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool EndPass(void);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11ShaderTechnique,MOF_DX11SHADERTECHNIQUECLASS_ID);
	};

	#include	"DX11ShaderTechnique.inl"
}

#endif

//[EOF]