/*************************************************************************//*!
					
					@file	ShaderEffect_BumpMapping.h
					@brief	�o���v�}�b�s���O�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.06.19
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_BUMPMAPPING__H__

#define		__SHADEREFFECT_BUMPMAPPING__H__

//INCLUDE
#include	"ShaderEffect_3DBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�o���v�}�b�s���O�V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_BumpMapping : public CShaderEffect_3DBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_BumpMapping();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_BumpMapping();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			�J�n
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Begin();
		/*************************************************************************//*!
				@brief			�I��
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool End();

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_BumpMapping,MOF_SHADEREFFECTBUMPMAPPINGCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_BumpMapping*			LPShaderEffect_BumpMapping;

#include	"ShaderEffect_BumpMapping.inl"

}

#endif

//[EOF]