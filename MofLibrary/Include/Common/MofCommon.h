/*************************************************************************//*!
					
					@file	MofCommon.h
					@brief	���C�u�����̊�{��`���s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MOFCOMMON__H__

#define		__MOFCOMMON__H__

//INCLUDE
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<assert.h>
#include	<new>
#include	<vector>
#include	<list>

#include	"Platform.h"

//----------------------------------
////TRUE,FALSE
//----------------------------------
#ifndef		FALSE
#define		FALSE									0
#endif

#ifndef		TRUE
#define		TRUE									1
#endif

//!�߂�l�������f�}�N��
#define		MOF_RESULTSUCCEEDED(re)					((re == TRUE) ? TRUE : FALSE)
//!�߂�l���s���f�}�N��
#define		MOF_RESULTFAULT(re)						((re != TRUE) ? TRUE : FALSE)

//----------------------------------
////NULL
//----------------------------------
#ifndef		NULL
#ifdef __cplusplus
#define		NULL									0
#else
#define		NULL									((void *)0)
#endif
#endif

//----------------------------------
////�C�����C���֐��p
//----------------------------------
#ifdef		MOFLIBRARY_DLL
#ifdef		MOFLIBRARY_EXPORT
#define		MOFLIBRARY_API							__declspec(dllexport)
#else
#define		MOFLIBRARY_API							__declspec(dllimport)
#endif
#else
#define		MOFLIBRARY_API							
#endif

//----------------------------------
////�C�����C���֐��p
//----------------------------------
#ifndef		FORCE_INLINE
#ifdef		_MSC_VER
  #if		(_MSC_VER >= 1200)
  #define	FORCE_INLINE __forceinline
  #else		//#ifn	(_MSC_VER >= 1200)
  #define	FORCE_INLINE __inline
  #endif	//(_MSC_VER >= 1200)
#else		//#ifndef	_MSC_VER
  #ifdef	__cplusplus
  #define	FORCE_INLINE inline
#else		//#ifn	__cplusplus
  #define	FORCE_INLINE
  #endif	//__cplusplus
#endif		//_MSC_VER
#endif		//FORCE_INLINE

//----------------------------------
////������u������
//----------------------------------
#ifdef _UNICODE
#ifndef UNICODE
#define UNICODE
#endif
#endif

#ifdef UNICODE
#ifndef _UNICODE
#define _UNICODE
#endif
#endif

#ifdef		UNICODE

typedef		wchar_t				MofChar;
typedef		MofChar*			LPMofChar;
typedef		const MofChar*		LPCMofChar;
#define		_MOFSTR(str)		L##str
#define		MOFSTR(str)			_MOFSTR(str)

//!���O�o��
#define		MOF_VALUENAME(s)						L#s
#define		MOF_VALUENAME_IN(s)						MOF_VALUENAME(s)

//!���O�A��
#define		MOF_VALUECONNECT(x,y)					x##y
#define		MOF_VALUECONNECT_IN(v1,v2)				MOF_VALUECONNECT(v1,v2)
#define		MOF_VALUECONNECT2(x,y,z)				x##y##z
#define		MOF_VALUECONNECT2_IN(v1,v2,v3)			MOF_VALUECONNECT(v1,v2,v3)
#define		MOF_VALUECONNECT3(x,y,z,w)				x##y##z##w
#define		MOF_VALUECONNECT3_IN(v1,v2,v3,v4)		MOF_VALUECONNECT(v1,v2,v3,v4)

#else

typedef		char				MofChar;
typedef		MofChar*			LPMofChar;
typedef		const MofChar*		LPCMofChar;
#define		_MOFSTR(str)		str
#define		MOFSTR(str)			str

//!���O�o��
#define		MOF_VALUENAME(s)						#s
#define		MOF_VALUENAME_IN(s)						MOF_VALUENAME(s)

//!���O�A��
#define		MOF_VALUECONNECT(x,y)					x##y
#define		MOF_VALUECONNECT_IN(v1,v2)				MOF_VALUECONNECT(v1,v2)
#define		MOF_VALUECONNECT2(x,y,z)				x##y##z
#define		MOF_VALUECONNECT2_IN(v1,v2,v3)			MOF_VALUECONNECT(v1,v2,v3)
#define		MOF_VALUECONNECT3(x,y,z,w)				x##y##z##w
#define		MOF_VALUECONNECT3_IN(v1,v2,v3,v4)		MOF_VALUECONNECT(v1,v2,v3,v4)

#endif

//----------------------------------
////�e���p��{�ݒ�ƒu������
//----------------------------------
#if defined( MOFLIB_WINDOWS )

#include	"MofCommonWindows.h"

#elif defined( MOFLIB_ANDROID )

#include	"MofCommonAndroid.h"

#endif

#endif

//[EOF]