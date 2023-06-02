/*************************************************************************//*!
					
					@file	DX11ShaderPass.h
					@brief	DirectX11�V�F�[�_�[�p�X�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERPASS__H__

#define		__DX11SHADERPASS__H__

//INCLUDE
#include	"../ShaderPassBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11�V�F�[�_�[�p�X�N���X

			DirectX11�ł̃V�F�[�_�[�̃p�X�ݒ���s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderPass : public CShaderPassBase {
	protected:
		/*******************//*!
		�V�F�[�_�[�e�N�j�b�N
		*//********************/
		ID3DX11EffectPass*			m_pPass;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderPass();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pPass		�p�X

				@return			None
		*//**************************************************************************/
		CDX11ShaderPass(ID3DX11EffectPass* pPass);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderPass(const CDX11ShaderPass& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderPass();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̊J�n
				@param[in]		Flag		�K�p�t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Begin(MofU32 Flag);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�p�X�̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool End(void);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11ShaderPass,MOF_DX11SHADERPASSCLASS_ID);
	};

#include	"DX11ShaderPass.h"

}

#endif

//[EOF]