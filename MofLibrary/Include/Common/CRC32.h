/*************************************************************************//*!
					
					@file	CRC32.h
					@brief	CRC32�n�b�V���������s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CRC32__H__

#define		__CRC32__H__

//INCLUDE
#include	"String.h"

namespace Mof {
	
	/*******************************//*!
	@brief	CRC32�n�b�V���������s���X�^�e�B�b�N�N���X

			CRC32�n�b�V���������s���X�^�e�B�b�N�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CCRC32 {
	private:
	public:
		/*************************************************************************//*!
				@brief			�n�b�V������
				@param[in]		pData			�n�b�V�������f�[�^
				@param[in]		s				�n�b�V�������f�[�^�T�C�Y

				@return			���������n�b�V���R�[�h��Ԃ�
		*//**************************************************************************/
		static MofU32 CreateHash(LPCMofVoid pData,MofU32 s);
		/*************************************************************************//*!
				@brief			�n�b�V������
				@param[in]		pStr			�n�b�V������������

				@return			���������n�b�V���R�[�h��Ԃ�
		*//**************************************************************************/
		static MofU32 CreateHash(LPCMofChar pStr);
		/*************************************************************************//*!
				@brief			�n�b�V������
				@param[in]		pStr			�n�b�V������������

				@return			���������n�b�V���R�[�h��Ԃ�
		*//**************************************************************************/
		static MofU32 CreateHash(const LPString pStr);

	private:
		//�쐬���֎~����
		CCRC32(){};
		CCRC32(const CCRC32& pObj){};
	};
	
	//INLINE INCLUDE
	#include	"CRC32.inl"

}

#endif

//[EOF]