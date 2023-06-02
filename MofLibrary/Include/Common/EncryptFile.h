/*************************************************************************//*!
					
					@file	EncryptFile.h
					@brief	�t�@�C���Í�������舵�����C���^�[�t�F�C�X

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ENCRYPTFILE__H__

#define		__ENCRYPTFILE__H__

//INCLUDE
#include	"String.h"

namespace Mof {

	/*******************************//*!
	@brief	�t�@�C���Í������C���^�[�t�F�C�X

			�t�@�C���Í�������舵�����C���^�[�t�F�C�X

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IEncryptFile : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			������
				@param[in]		pData		�t�@�C���f�[�^
				@param[in]		Size		�t�@�C���T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Encrypt(LPMofU8* pData, MofU32& Size) = 0;
	};
	typedef IEncryptFile* LPEncryptFile;
	
	/*******************************//*!
	@brief	XOR�t�@�C���Í���

			�t�@�C���Í�������舵���N���X

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CXORKeyEncryptFile : public IEncryptFile {
	protected:
		/*******************//*!
		�Í����p�L�[
		*//********************/
		MofU8					m_Key;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		key			�L�[

				@return			None
		*//**************************************************************************/
		CXORKeyEncryptFile(MofU8 key);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CXORKeyEncryptFile();

		/*************************************************************************//*!
				@brief			�Í���
				@param[in]		pData		�t�@�C���f�[�^
				@param[in]		Size		�t�@�C���T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Encrypt(LPMofU8* pData, MofU32& Size);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CXORKeyEncryptFile, MOF_ENCRYPTFILECLASS_ID);
	};

}

#endif

//[EOF]