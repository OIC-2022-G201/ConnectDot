/*************************************************************************//*!
					
					@file	DecryptFile.h
					@brief	�t�@�C������������舵�����C���^�[�t�F�C�X

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DECRYPTFILE__H__

#define		__DECRYPTFILE__H__

//INCLUDE
#include	"String.h"

namespace Mof {

	/*******************************//*!
	@brief	�t�@�C�����������C���^�[�t�F�C�X

			�t�@�C������������舵�����C���^�[�t�F�C�X

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IDecryptFile : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			������
				@param[in]		pData		�t�@�C���f�[�^
				@param[in]		Size		�t�@�C���T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Decrypt(LPMofU8* pData, MofU32& Size) = 0;
	};
	typedef IDecryptFile* LPDecryptFile;
	
	/*******************************//*!
	@brief	XOR�t�@�C��������

			�t�@�C������������舵���N���X

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CXORKeyDecryptFile : public IDecryptFile {
	protected:
		/*******************//*!
		�������p�L�[
		*//********************/
		MofU8					m_Key;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		key			�L�[

				@return			None
		*//**************************************************************************/
		CXORKeyDecryptFile(MofU8 key);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CXORKeyDecryptFile();

		/*************************************************************************//*!
				@brief			������
				@param[in]		pData		�t�@�C���f�[�^
				@param[in]		Size		�t�@�C���T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Decrypt(LPMofU8* pData, MofU32& Size);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CXORKeyDecryptFile, MOF_DECRYPTFILECLASS_ID);
	};

}

#endif

//[EOF]