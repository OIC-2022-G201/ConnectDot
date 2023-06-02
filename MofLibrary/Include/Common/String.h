/*************************************************************************//*!
					
					@file	String.h
					@brief	������֘A�̏������s���N���X�B<br>
							UNICODE�ƃ}���`�o�C�g�̕����Z�b�g�̒u���������s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__STRING__H__

#define		__STRING__H__

//INCLUDE
#include	"Allocator.h"

namespace Mof {
	
#define		MOF_STRINGIMPL_NAME					CStringA
#define		MOF_STRINGIMPL_TYPE					char

#include	"StringImpl.h"

#undef		MOF_STRINGIMPL_NAME
#undef		MOF_STRINGIMPL_TYPE
	
	
#define		MOF_STRINGIMPL_NAME					CStringW
#define		MOF_STRINGIMPL_TYPE					wchar_t
#define		MOF_STRINGIMPL_UNICODE

#include	"StringImpl.h"

#undef		MOF_STRINGIMPL_NAME
#undef		MOF_STRINGIMPL_TYPE
#undef		MOF_STRINGIMPL_UNICODE

//----------------------------------
////������u������
//----------------------------------
#ifdef		UNICODE

//!������N���X
#define		MOF_STRINGCLASS_ID					MOF_ASTRINGCLASS_ID
typedef		CStringW							CString;
typedef		CString*							LPString;

//!�t�@�C�����J��
#define		MOF_FOPEN							_wfopen
//!�t�@�C�������
#define		MOF_FCLOSE(fp)						if(fp){fclose(fp); fp = NULL;}
//!�t�@�C�������񏑂�����
#define		MOF_FPRINT							fwprintf
//!�ψ��������񏑂�����
#define		MOF_SPRINT							swprintf
//!�ψ��������񏑂�����
#define		MOF_VPRINT							vswprintf
//!�����񒷂�
#define		MOF_StrLength						wcslen
//!������R�s�[
#define		MOF_StrCopy							wcscpy
//!�����񐔒l�ϊ�
#define		MOF_StrToL							wcstol
#define		MOF_StrToUL							wcstoul
#define		MOF_StrToLF							wcstod
//!�e�L�X�g�t�@�C���^�C�v
#define		MOF_FWRITETEXTENCODING				MOFSTR("wt, ccs= UNICODE")
//!2�o�C�g�����̐擪���f(UNICODE�̏ꍇ���FALSE)
#define		MOF_ISDBCLEADBYTE(c)				FALSE
//!�f�B���N�g���쐬
#define		MOF_MAKEDIRECTORY(p,a)				_wmkdir(p)

//!Wide
#define		MOF_TOWIDECHARA(pstr)				pstr
//!Multi
FORCE_INLINE char* MOF_TOMULTICHARA(const wchar_t* pstr)
{
	static char str[1024];
	memset(str, 0, sizeof(str));
	WideCharToMultiByte(CP_ACP, 0, pstr, wcslen(pstr), str, 1024, NULL, NULL);
	return str;
}
//!���`��
FORCE_INLINE LPCMofChar MOF_TOMOFCHARA(const char* pstr)
{
	static wchar_t wstr[1024];
	memset(wstr, 0, sizeof(wstr));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pstr, strlen(pstr), wstr, 1024);
	return wstr;
}
FORCE_INLINE LPCMofChar MOF_TOMOFCHARA(const wchar_t* pstr)
{
	return pstr;
}

#else

//!������N���X
#define		MOF_STRINGCLASS_ID					MOF_WSTRINGCLASS_ID
typedef		CStringA							CString;
typedef		CString*							LPString;

//!�t�@�C�����J��
#define		MOF_FOPEN							fopen
//!�t�@�C�������
#define		MOF_FCLOSE(fp)						if(fp){fclose(fp); fp = NULL;}
//!�t�@�C�������񏑂�����
#define		MOF_FPRINT							fprintf
//!�ψ��������񏑂�����
#define		MOF_SPRINT							sprintf
//!�ψ��������񏑂�����
#define		MOF_VPRINT							vsprintf
//!�����񒷂�
#define		MOF_StrLength						strlen
//!������R�s�[
#define		MOF_StrCopy							strcpy
//!�����񐔒l�ϊ�
#define		MOF_StrToL							strtol
#define		MOF_StrToUL							strtoul
#define		MOF_StrToLF							strtod
//!�e�L�X�g�t�@�C���^�C�v
#define		MOF_FWRITETEXTENCODING				MOFSTR("wt")

#ifdef		MOFLIB_WINDOWS

//!2�o�C�g�����̐擪���f
#define		MOF_ISDBCLEADBYTE(c)				IsDBCSLeadByte(c)
//!�f�B���N�g���쐬
#define		MOF_MAKEDIRECTORY(p,a)				mkdir(p)

//!Wide
FORCE_INLINE wchar_t* MOF_TOWIDECHARA(const char* pstr)
{
	static wchar_t wstr[1024];
	memset(wstr, 0, sizeof(wstr));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pstr, strlen(pstr), wstr, 1024);
	return wstr;
}
//!Multi
#define		MOF_TOMULTICHARA(pstr)				pstr
//!���`��
FORCE_INLINE LPCMofChar MOF_TOMOFCHARA(const char* pstr)
{
	return pstr;
}
FORCE_INLINE LPCMofChar MOF_TOMOFCHARA(const wchar_t* pstr)
{
	static char str[1024];
	memset(str, 0, sizeof(str));
	WideCharToMultiByte(CP_ACP, 0, pstr, wcslen(pstr), str, 1024, NULL, NULL);
	return str;
}

#endif

#ifdef		MOFLIB_ANDROID

//!2�o�C�g�����̐擪���f
#define		MOF_ISDBCLEADBYTE(c)				((c >= 0x81 && c <= 0x9F) ? TRUE : (c >= 0xE0 && c <= 0xFC) ? TRUE : FALSE)
//!�f�B���N�g���쐬
#define		MOF_MAKEDIRECTORY(p,a)				mkdir(p,a)

//!Wide
#define		MOF_TOWIDECHARA(pstr)				pstr
//!Multi
#define		MOF_TOMULTICHARA(pstr)				pstr
//!���`��
#define		MOF_TOMOFCHARA(pstr)				pstr

#endif

#endif

	
	/*******************************//*!
	@brief	���O�������I�u�W�F�N�g�C���^�[�t�F�C�X��������p

			MOF���C�u�������̑S�Ă̖��O�����I�u�W�F�N�g���p�����邩���f���邽�߂̓����N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofNamedObjectImpl {};

	/*******************************//*!
	@brief	���O�������I�u�W�F�N�g�C���^�[�t�F�C�X

			MOF���C�u�������̑S�Ă̖��O�����I�u�W�F�N�g�̊��ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofNamedObject : public IMofObject , public IMofNamedObjectImpl {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~IMofNamedObject(){}
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�ݒ�
				@param[in]		pName			�ݒ肷�閼�O
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void) = 0;
	};

	//TYPEDEF
	typedef IMofNamedObject* LPMofNamedObject;
	typedef const IMofNamedObject* LPCMofNamedObject;
}

#endif

//[EOF]