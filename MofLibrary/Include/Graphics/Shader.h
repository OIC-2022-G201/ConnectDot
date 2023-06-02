/*************************************************************************//*!
					
					@file	Shader.h
					@brief	�V�F�[�_�[���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADER__H__

#define		__SHADER__H__

//INCLUDE
#include	"ShaderTechnique.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�C���^�[�t�F�C�X

			�V�F�[�_�[�̓ǂݍ��݁A�ݒ���s�����߂̃C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShader : public IMofNamedObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̓ǂݍ���<br>
								���p����O���t�B�N�X���C�u�����ɂ���ēǂݍ��݂̑Ή����Ⴄ���߁A<br>
								�Ή��󋵂͊e�h����̃V�F�[�_�[�N���X���Q�Ƃ��邱�ƁB
				@param[in]		pName		�t�@�C����
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName, MofU32 Flags = SHADERCOMPILE_DEFAULTFLAG) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̓ǂݍ���<br>
								���p����O���t�B�N�X���C�u�����ɂ���ēǂݍ��݂̑Ή����Ⴄ���߁A<br>
								�Ή��󋵂͊e�h����̃V�F�[�_�[�N���X���Q�Ƃ��邱�ƁB
				@param[in]		pS			�V�F�[�_�[
				@param[in]		SSize		�V�F�[�_�[�T�C�Y
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPMofVoid pS, MofU32 SSize, MofU32 Flags = SHADERCOMPILE_DEFAULTFLAG) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̓ǂݍ���<br>
								���_�V�F�[�_�[�A�s�N�Z���V�F�[�_�[�ʓǂݍ���<br>
								���p����O���t�B�N�X���C�u�����ɂ���ēǂݍ��݂̑Ή����Ⴄ���߁A<br>
								�Ή��󋵂͊e�h����̃V�F�[�_�[�N���X���Q�Ƃ��邱�ƁB
				@param[in]		pVName		���_�V�F�[�_�[�t�@�C����
				@param[in]		pPName		�s�N�Z���V�F�[�_�[�t�@�C����
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pVName, LPCMofChar pPName, MofU32 Flags = SHADERCOMPILE_DEFAULTFLAG) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̓ǂݍ���<br>
								���p����O���t�B�N�X���C�u�����ɂ���ēǂݍ��݂̑Ή����Ⴄ���߁A<br>
								�Ή��󋵂͊e�h����̃V�F�[�_�[�N���X���Q�Ƃ��邱�ƁB
				@param[in]		pVS			���_�V�F�[�_�[
				@param[in]		VSSize		���_�V�F�[�_�[�T�C�Y
				@param[in]		pPS			�s�N�Z���V�F�[�_�[
				@param[in]		PSSize		�s�N�Z���V�F�[�_�[�T�C�Y
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPMofVoid pVS, MofU32 VSSize, LPMofVoid pPS, MofU32 PSSize, MofU32 Flags = SHADERCOMPILE_DEFAULTFLAG) = 0;
		
		/*************************************************************************//*!
				@brief			�R���p�C���ς݃V�F�[�_�[�̐���<br>
								Microsoft�񋟂�Effects11���C�u�������g�p�B<br>
								�e�N�j�b�N�̎w��ɑΉ��B
				@param[in]		pName		�t�@�C����
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPCMofChar pName, MofU32 Flags = 0) = 0;
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
		virtual MofBool Create(LPMofVoid pS, MofU32 SSize, MofU32 Flags = 0) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̐���<br>
								���_�V�F�[�_�[�A�s�N�Z���V�F�[�_�[�ʓǂݍ���<br>
								���p����O���t�B�N�X���C�u�����ɂ���ēǂݍ��݂̑Ή����Ⴄ���߁A<br>
								�Ή��󋵂͊e�h����̃V�F�[�_�[�N���X���Q�Ƃ��邱�ƁB
				@param[in]		pVName		���_�V�F�[�_�[�t�@�C����
				@param[in]		pPName		�s�N�Z���V�F�[�_�[�t�@�C����
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPCMofChar pVName, LPCMofChar pPName, MofU32 Flags = 0) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̐���<br>
								���p����O���t�B�N�X���C�u�����ɂ���ēǂݍ��݂̑Ή����Ⴄ���߁A<br>
								�Ή��󋵂͊e�h����̃V�F�[�_�[�N���X���Q�Ƃ��邱�ƁB
				@param[in]		pVS			���_�V�F�[�_�[
				@param[in]		VSSize		���_�V�F�[�_�[�T�C�Y
				@param[in]		pPS			�s�N�Z���V�F�[�_�[
				@param[in]		PSSize		�s�N�Z���V�F�[�_�[�T�C�Y
				@param[in]		Flags		�ǂݍ��݃t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPMofVoid pVS, MofU32 VSSize, LPMofVoid pPS, MofU32 PSSize, MofU32 Flags = 0) = 0;
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�j�b�N�ݒ�
				@param[in]		tn			�e�N�j�b�N�ԍ�
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTechnique(MofU32 tn) = 0;
		/*************************************************************************//*!
				@brief			�e�N�j�b�N�ݒ�
				@param[in]		pName		�e�N�j�b�N��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTechniqueByName(LPCMofChar pName) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̎擾
				@param			None

				@return			�V�F�[�_�[
		*//**************************************************************************/
		virtual MofShaderEffect GetShader(void) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̎擾
				@param			None

				@return			�V�F�[�_�[
		*//**************************************************************************/
		virtual MofVertexShader GetVertexShader(void) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�̎擾
				@param			None

				@return			�V�F�[�_�[
		*//**************************************************************************/
		virtual MofPixelShader GetPixelShader(void) = 0;
		/*************************************************************************//*!
				@brief			�ݒ�o�b�t�@�̐��擾
				@param			None

				@return			�ݒ�o�b�t�@
		*//**************************************************************************/
		virtual MofU32 GetBufferCount(void) const = 0;
		/*************************************************************************//*!
				@brief			�ݒ�o�b�t�@�̐��擾
				@param			None

				@return			�ݒ�o�b�t�@
		*//**************************************************************************/
		virtual MofU32 GetGlobalVariableCount(void) const = 0;
		/*************************************************************************//*!
				@brief			�ݒ�o�b�t�@�̐��擾
				@param			None

				@return			�ݒ�o�b�t�@
		*//**************************************************************************/
		virtual MofU32 GetInterfaceCount(void) const = 0;
		/*************************************************************************//*!
				@brief			�e�N�j�b�N�̐��擾
				@param			None

				@return			�e�N�j�b�N�̐�
		*//**************************************************************************/
		virtual MofU32 GetTechniqueCount(void) const = 0;
		/*************************************************************************//*!
				@brief			�e�N�j�b�N�擾
				@param			None

				@return			�e�N�j�b�N<br>
								���݂��Ȃ��ꍇNULL
		*//**************************************************************************/
		virtual LPShaderTechnique GetTechnique(void) = 0;
		/*************************************************************************//*!
				@brief			�e�N�j�b�N�擾
				@param[in]		n			�e�N�j�b�N

				@return			�e�N�j�b�N<br>
								���݂��Ȃ��ꍇNULL
		*//**************************************************************************/
		virtual LPShaderTechnique GetTechnique(MofU32 n) = 0;
		/*************************************************************************//*!
				@brief			�e�N�j�b�N�擾
				@param[in]		pName		�e�N�j�b�N��

				@return			�e�N�j�b�N<br>
								���݂��Ȃ��ꍇNULL
		*//**************************************************************************/
		virtual LPShaderTechnique GetTechniqueByName(LPCMofChar pName) = 0;
	};

	//�|�C���^�u������
	typedef IShader*			LPShader;
	typedef CDynamicArray< LPShader >		CShaderArray, *LPShaderArray;
}

#endif

//[EOF]