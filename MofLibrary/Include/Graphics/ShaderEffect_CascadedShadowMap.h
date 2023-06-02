/*************************************************************************//*!
					
					@file	ShaderEffect_CascadedShadowMap.h
					@brief	�J�X�P�[�h�V���h�E�}�b�v�V�F�[�_�[�B

															@author	CDW
															@date	2015.06.03
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_CASCADEDSHADOWMAP__H__

#define		__SHADEREFFECT_CASCADEDSHADOWMAP__H__

//INCLUDE
#include	"ShaderEffect_ShadowTexture.h"
#include	"ShaderEffect_CascadeVarianceRenderer.h"
#include	"ShaderEffect_BlurBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�J�X�P�[�h�V���h�E�}�b�v�V�F�[�_�[�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_CascadedShadowMap : public IShaderEffect {
	public:
		/*******************//*!
		�J�X�P�[�h�ő吔
		*//********************/
		static const MofU32 MAX_CASCADES = 3;
	protected:
		/*******************//*!
		�V���h�E�}�b�v�p�[�x�e�N�X�`���`��V�F�[�_�[
		*//********************/
		LPShaderEffect_ShadowTexture m_pShadowTextures[MAX_CASCADES];
		/*******************//*!
		�V���h�E�}�b�v�ɂ��e�`��V�F�[�_�[
		*//********************/
		LPShaderEffect_CascadeVarianceRenderer m_pShadowRenderer;
		/*******************//*!
		�e�̂ڂ����V�F�[�_�[
		*//********************/
		LPShaderEffect_BlurBase m_pBlurShader;
		/*******************//*!
		�ڂ��������̒��ԕ`���
		*//********************/
		LPTexture m_pShadowMapTempBlur;

		/*******************//*!
		�J�X�P�[�h�̕����ʒu
		*//********************/
		MofFloat m_CascadePartitions[MAX_CASCADES];
		/*******************//*!
		���C�g���_�̎ˉe�s��̔z��
		*//********************/
		CMatrix44 m_matShadowProj[MAX_CASCADES];
		/*******************//*!
		���C�g���_�̃r���[�s��
		*//********************/
		CMatrix44 m_matShadowView;
		/*******************//*!
		�e�̂ڂ����
		*//********************/
		MofFloat m_BlurStep;
		/*******************//*!
		�J�X�P�[�h�̋��E�̂ڂ����
		*//********************/
		MofFloat m_CascadeBlendArea;
		/*******************//*!
		���C�g�u���[�f�B���O��}���邽�߂̒l
		*//********************/
		MofFloat m_ShadowPower;
		/*******************//*!
		�V���h�E�}�b�v��Near
		*//********************/
		MofFloat m_ShadowNear;
		/*******************//*!
		�V���h�E�}�b�v��Far;
		*//********************/
		MofFloat m_ShadowFar;

		static void CreateFrustumPointsFromCascadeInterval(MofFloat fCascadeIntervalBegin,MofFloat fCascadeIntervalEnd,const Matrix44& vProjection,Vector4* pvCornerPointsWorld);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_CascadedShadowMap();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_CascadedShadowMap();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		TexSize		�V���h�E�}�b�v�p�e�N�X�`���T�C�Y

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TexSize);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param[in]		Variance	�o���A���X�t���O
				@param[in]		TexSize		�V���h�E�}�b�v�p�e�N�X�`���T�C�Y
				@param[in]		TexFormat	�V���h�E�}�b�v�p�e�N�X�`���t�H�[�}�b�g
				@param[in]		DepthFormat	�V���h�E�}�b�v�p�e�N�X�`���t�H�[�}�b�g

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TexSize,MofBool Variance,PixelFormat TexFormat,PixelFormat DepthFormat);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			�[�x�e�N�X�`���쐬�J�n
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool BeginCascades();
		/*************************************************************************//*!
				@brief			�[�x�e�N�X�`���쐬�J�n
				@param[in]		n				�[�x�e�N�X�`���ԍ�
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool BeginTexture(MofU32 n);
		/*************************************************************************//*!
				@brief			�[�x�e�N�X�`���쐬�I��
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool EndCascades();
		/*************************************************************************//*!
				@brief			�e��K�p������ʕ`��J�n
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool BeginRenderer();
		/*************************************************************************//*!
				@brief			�e��K�p������ʕ`��I��
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool EndRenderer();

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�J�X�P�[�h�����ʒu�̐ݒ�
				@param[in]		Index			�J�X�P�[�h�ԍ�
				@param[in]		PartitionDepth	�����ʒu
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetCascadePartition(MofU32 Index,MofFloat PartitionDepth);
		/*************************************************************************//*!
				@brief			�e�̂ڂ������̐ݒ�
				@param[in]		BlurStep		�e�̂ڂ�����
				
				@return			None
		*//**************************************************************************/
		virtual void SetBlurStep(MofFloat BlurStep);
		/*************************************************************************//*!
				@brief			�J�X�P�[�h���E�̂ڂ�����̐ݒ�
				@param[in]		CascadeBlendArea	�J�X�P�[�h���E�̂ڂ����
				
				@return			None
		*//**************************************************************************/
		virtual void SetCascadeBlendArea(MofFloat CascadeBlendArea);
		/*************************************************************************//*!
				@brief			���C�g�u���[�f�B���O��}���邽�߂̒l��ݒ�
				@param[in]		ShadowPower		���C�g�u���[�f�B���O��}���邽�߂̒l
				
				@return			None
		*//**************************************************************************/
		virtual void SetShadowPower(MofFloat ShadowPower);
		/*************************************************************************//*!
				@brief			�V���h�E�}�b�v��Near�ݒ�
				@param[in]		ShadowNear		�V���h�E�}�b�v��Near
				
				@return			None
		*//**************************************************************************/
		virtual void SetShadowNear(MofFloat ShadowNear);
		/*************************************************************************//*!
				@brief			�V���h�E�}�b�v��Far�ݒ�
				@param[in]		ShadowFar	�V���h�E�}�b�v��Far
				
				@return			None
		*//**************************************************************************/
		virtual void SetShadowFar(MofFloat ShadowFar);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̎擾
				@param			None
				
				@return			�V�F�[�_�[��Ԃ��B
								���s�̏ꍇNULL�ɂȂ�B
		*//**************************************************************************/
		virtual LPShader GetShader(void);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�o�C���h�̎擾
				@param			None
				
				@return			�V�F�[�_�[�o�C���h��Ԃ��B
								���s�̏ꍇNULL�ɂȂ�B
		*//**************************************************************************/
		virtual LPShaderBind GetShaderBind(void);
		/*************************************************************************//*!
				@brief			�[�x�e�N�X�`���̎擾
				@param[in]		n				�G�t�F�N�g�ԍ�
				
				@return			�[�x�e�N�X�`��
		*//**************************************************************************/
		virtual LPShaderEffect_ShadowTexture GetShadowMap(MofU32 n);
		/*************************************************************************//*!
				@brief			�[�x�e�N�X�`���̎擾
				@param[in]		n				�G�t�F�N�g�ԍ�
				
				@return			�[�x�e�N�X�`��
		*//**************************************************************************/
		virtual LPTexture GetShadowMapTexture(MofU32 n);
		/*************************************************************************//*!
				@brief			�J�X�P�[�h�V���h�E�}�b�v�̒i�K���擾
				@param			None
				
				@return			�J�X�P�[�h�V���h�E�}�b�v�̒i�K��
		*//**************************************************************************/
		virtual MofU32 GetCascadeLevels(void);
		/*************************************************************************//*!
				@brief			���C�g���_�̃r���[�s��擾
				@param			None

				@return			���C�g���_�̃r���[�s��
		*//**************************************************************************/
		virtual CMatrix44& GetLightViewMatrix(void);
		/*************************************************************************//*!
				@brief			�J�X�P�[�h�v���W�F�N�V�����s��̎擾
				@param[in]		n				�G�t�F�N�g�ԍ�
				
				@return			�J�X�P�[�h�v���W�F�N�V�����s��
		*//**************************************************************************/
		virtual CMatrix44& GetCascadeProjectionMatrix(MofU32 n);
		/*************************************************************************//*!
				@brief			�e�̂ڂ������̎擾
				@param			None
				
				@return			�e�̂ڂ�����
		*//**************************************************************************/
		virtual MofFloat GetBlurStep(void);
		/*************************************************************************//*!
				@brief			�J�X�P�[�h���E�̂ڂ�����̎擾
				@param			None
				
				@return			�J�X�P�[�h���E�̂ڂ����
		*//**************************************************************************/
		virtual MofFloat GetCascadeBlendArea(void);
		/*************************************************************************//*!
				@brief			���C�g�u���[�f�B���O��}���邽�߂̒l���擾
				@param			None
				
				@return			���C�g�u���[�f�B���O��}���邽�߂̒l
		*//**************************************************************************/
		virtual MofFloat GetShadowPower(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_CascadedShadowMap,MOF_SHADEREFFECTCASCADEDSHADOWMAPCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_CascadedShadowMap*			LPShaderEffect_CascadedShadowMap;

#include	"ShaderEffect_CascadedShadowMap.inl"

}

#endif

//[EOF]
