/*************************************************************************//*!
					
					@file	ShaderEffect_DownScale.h
					@brief	�ėp�k���V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.05.18
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_DOWNSCALE__H__

#define		__SHADEREFFECT_DOWNSCALE__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�ėp�k���V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_DownScale : public CShaderEffect_2DBase {
	public:
		/*******************************//*!
		@brief	�k�����̃T���v�����O�^�C�v�̗�

		@author	CDW
		*//********************************/
		enum SampleType{
			SAMPLE_2X2,
			SAMPLE_3X3LUM,

			SAMPLE_MAX,
		};
		SampleType m_SampleType;
	protected:
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create2x2();
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create3x3Lum();
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		SampleType		�T���v�����O�^�C�v

				@return			None
		*//**************************************************************************/
		CShaderEffect_DownScale(SampleType eSampleType);
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_DownScale,MOF_SHADEREFFECTDOWNSCALECLASS_ID);
	};

	// �u������
	typedef CShaderEffect_DownScale*			LPShaderEffect_DownScale;

#include	"ShaderEffect_DownScale.inl"

}

#endif

//[EOF]