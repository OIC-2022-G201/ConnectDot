/*************************************************************************//*!
					
					@file	DX11ShaderBind_SpriteContainer.h
					@brief	��{�X�v���C�g�V�F�[�_�[�o�C���h�B<br>
							�W���I�ȃX�v���C�g�`��V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_SPRITECONTAINER__H__

#define		__DX11SHADERBIND_SPRITECONTAINER__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�V�F�[�_�[�o�C���h���C���^�[�t�F�C�X

			�V�F�[�_�[�̂��߂̃o�b�t�@�̐ݒ���s���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_SpriteContainer : public CDX11ShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_VERTEX = CDX11ShaderBind_SpriteBase::ConstParam::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�X�v���C�g�`��X�v���C�g�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstVertexParam
		{
			Vector2		cbvPosition1;
			Vector2		cbvPosition2;
			Vector2		cbvPosition3;
			Vector2		cbvPosition4;

			Vector4		cbvColor1;
			Vector4		cbvColor2;
			Vector4		cbvColor3;
			Vector4		cbvColor4;
			Vector4		cbvColorRate;
		};
		/*******************//*!
		�v���~�e�B�u�`��v���~�e�B�u���ݒ�
		*//********************/
		ConstVertexParam						m_VertexParam;
	protected:
		/*******************//*!
		�V�[�������̓R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstVertex;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SpriteContainer();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SpriteContainer(const CDX11ShaderBind_SpriteContainer& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_SpriteContainer();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_SpriteContainer,MOF_DX11SHADERBINDSPRITEBASECLASS_ID);
	};

	#include	"DX11ShaderBind_SpriteContainer.inl"
	
	//�u������
	typedef CDX11ShaderBind_SpriteContainer			CShaderBind_SpriteContainer;
	typedef CShaderBind_SpriteContainer*			LPShaderBind_SpriteContainer;
}

#endif

//[EOF]