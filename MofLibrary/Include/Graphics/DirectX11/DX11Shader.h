/*************************************************************************//*!
					
					@file	DX11Shader.cpp
					@brief	DirectX11�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADER__H__

#define		__DX11SHADER__H__

//INCLUDE
#include	"../ShaderBase.h"
#include	"DX11ShaderTechnique.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11�V�F�[�_�[�N���X

			DirectX11�ł̃V�F�[�_�[�ǂݍ��݁A�ݒ���s���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Shader : public CShaderBase {
	protected:
		/*******************//*!
		�V�F�[�_�[
		*//********************/
		ID3DX11Effect*		    m_pShader;
		/*******************//*!
		�V�F�[�_�[
		*//********************/
		D3DX11_EFFECT_DESC		m_Desc;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Shader();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11Shader(const CDX11Shader& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Shader();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̓ǂݍ���<br>
								Microsoft�񋟂�Effects11���C�u�������g�p�B<br>
								�e�N�j�b�N�̎w��ɑΉ��B
				@param[in]		pName		�t�@�C����
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,MofU32 Flags = D3DCOMPILE_ENABLE_STRICTNESS);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̓ǂݍ���<br>
								Microsoft�񋟂�Effects11���C�u�������g�p�B<br>
								�e�N�j�b�N�̎w��ɑΉ��B
				@param[in]		pS			�V�F�[�_�[
				@param[in]		SSize		�V�F�[�_�[�T�C�Y
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPMofVoid pS,MofU32 SSize,MofU32 Flags = D3DCOMPILE_ENABLE_STRICTNESS);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̓ǂݍ���<br>
								���_�V�F�[�_�[�A�s�N�Z���V�F�[�_�[�ʓǂݍ���
				@param[in]		pVName		���_�V�F�[�_�[�t�@�C����
				@param[in]		pPName		�s�N�Z���V�F�[�_�[�t�@�C����
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pVName,LPCMofChar pPName,MofU32 Flags = D3DCOMPILE_ENABLE_STRICTNESS);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̓ǂݍ���<br>
								���_�V�F�[�_�[�A�s�N�Z���V�F�[�_�[��n�����ƂŐ���
				@param[in]		pVS			���_�V�F�[�_�[
				@param[in]		VSSize		���_�V�F�[�_�[�T�C�Y
				@param[in]		pPS			�s�N�Z���V�F�[�_�[
				@param[in]		PSSize		�s�N�Z���V�F�[�_�[�T�C�Y
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPMofVoid pVS,MofU32 VSSize,LPMofVoid pPS,MofU32 PSSize,MofU32 Flags = D3DCOMPILE_ENABLE_STRICTNESS);
		
		/*************************************************************************//*!
				@brief			�R���p�C���ς݃V�F�[�_�[�̐���<br>
								Microsoft�񋟂�Effects11���C�u�������g�p�B<br>
								�e�N�j�b�N�̎w��ɑΉ��B
				@param[in]		pName		�t�@�C����
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPCMofChar pName,MofU32 Flags = 0);
		/*************************************************************************//*!
				@brief			�R���p�C���ς݃V�F�[�_�[�̐���<br>
								Microsoft�񋟂�Effects11���C�u�������g�p�B<br>
								�e�N�j�b�N�̎w��ɑΉ��B
				@param[in]		pS			�V�F�[�_�[
				@param[in]		SSize		�V�F�[�_�[�T�C�Y
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPMofVoid pS, MofU32 SSize, MofU32 Flags = 0);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̐���<br>
								Microsoft�񋟂�Effects11���C�u�������g�p�B<br>
								�e�N�j�b�N�̎w��ɑΉ��B
				@param[in]		pVName		���_�V�F�[�_�[�t�@�C����
				@param[in]		pPName		�s�N�Z���V�F�[�_�[�t�@�C����
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPCMofChar pVName, LPCMofChar pPName, MofU32 Flags = 0);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̐���<br>
								Microsoft�񋟂�Effects11���C�u�������g�p�B<br>
								�e�N�j�b�N�̎w��ɑΉ��B
				@param[in]		pVS			���_�V�F�[�_�[
				@param[in]		VSSize		���_�V�F�[�_�[�T�C�Y
				@param[in]		pPS			�s�N�Z���V�F�[�_�[
				@param[in]		PSSize		�s�N�Z���V�F�[�_�[�T�C�Y
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPMofVoid pVS, MofU32 VSSize, LPMofVoid pPS, MofU32 PSSize, MofU32 Flags = 0);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̎擾
				@param			None

				@return			�V�F�[�_�[
		*//**************************************************************************/
		virtual MofShaderEffect GetShader(void);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̎擾
				@param			None

				@return			�V�F�[�_�[
		*//**************************************************************************/
		virtual MofVertexShader GetVertexShader(void);
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̎擾
				@param			None

				@return			�V�F�[�_�[
		*//**************************************************************************/
		virtual MofPixelShader GetPixelShader(void);
		/*************************************************************************//*!
				@brief			�ݒ�o�b�t�@�̐��擾
				@param			None

				@return			�ݒ�o�b�t�@
		*//**************************************************************************/
		virtual MofU32 GetBufferCount(void) const;
		/*************************************************************************//*!
				@brief			�ݒ�o�b�t�@�̐��擾
				@param			None

				@return			�ݒ�o�b�t�@
		*//**************************************************************************/
		virtual MofU32 GetGlobalVariableCount(void) const;
		/*************************************************************************//*!
				@brief			�ݒ�o�b�t�@�̐��擾
				@param			None

				@return			�ݒ�o�b�t�@
		*//**************************************************************************/
		virtual MofU32 GetInterfaceCount(void) const;

		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11Shader,MOF_DX11SHADERCLASS_ID);
	};

	#include	"DX11Shader.inl"
	
	//�u������
	typedef CDX11Shader		CShader;
}

#endif

//[EOF]