/*************************************************************************//*!
					
					@file	MofCommonWindows.h
					@brief	ライブラリの基本定義を行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MOFCOMMONWINDOWS__H__

#define		__MOFCOMMONWINDOWS__H__

#ifdef		MOFLIB_WINDOWS_DESKTOP
#define		WIN32_LEAN_AND_MEAN
#include	<Windows.h>
#include	<mmsystem.h>
#include	<shellapi.h>
#include	<shlwapi.h>
#include	<Commdlg.h>
#include	<process.h>
#include	<tchar.h>
#include	<direct.h>
#pragma comment(lib,"shlwapi.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"Comctl32.lib")
typedef		HWND									MofWindowHandle;
typedef		HINSTANCE								MofInstanceHandle;
typedef		HICON									MofIconHandle;
typedef		HCURSOR									MofCursorHandle;
typedef		LRESULT									MofProcResult;
typedef		WPARAM									MofProcParamW;
typedef		LPARAM									MofProcParamL;
typedef		HANDLE									MofThreadID;
typedef		CRITICAL_SECTION						MofLock;
typedef		HANDLE									MofSemaphore;
#else
#define		WIN32_LEAN_AND_MEAN
#include	<wrl.h>
#include	<wrl/client.h>
#include	<roapi.h>
#include	<Windows.h>
#include	<process.h>
#include	<tchar.h>
#include	<agile.h>
#include	<ppltasks.h>
#include	<Collection.h>
typedef		Windows::UI::Core::CoreWindow^			MofWindowHandle;
typedef		HINSTANCE								MofInstanceHandle;
typedef		HICON									MofIconHandle;
typedef		HCURSOR									MofCursorHandle;
typedef		LRESULT									MofProcResult;
typedef		WPARAM									MofProcParamW;
typedef		LPARAM									MofProcParamL;
typedef		HANDLE									MofThreadID;
typedef		CRITICAL_SECTION						MofLock;
typedef		HANDLE									MofSemaphore;
#endif

#define		MOF_ALIGNED16(a)						__declspec(align(16)) a
#define		MOF_ALIGNED16_CLASS						MOF_ALIGNED16(class) MOFLIBRARY_API
#define		MOF_ALIGNED16_STRUCT					struct MOFLIBRARY_API
//#define		MOF_ALIGNED16_STRUCT					MOF_ALIGNED16(struct) MOFLIBRARY_API

#if defined(DEBUG) || defined(_DEBUG)

#include	<crtdbg.h>
template <class T> T& PLACEMENT_NEW(T &p) { new (&p) T(); return p; }
template <class T1, class T2> T1& PLACEMENT_NEW(T1 &p, const T2 &value) { new (&p) T1(value); return p; }
#define		DEBUG_NEW			new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define		NEW					DEBUG_NEW
#define		ALIGN_NEW(T)		new (_mm_malloc(sizeof(T),__alignof(T))) T
#define		MOF_ALIGNED_NEW_OPERATOR(T)					\
   FORCE_INLINE void* operator new(size_t sizeInBytes)	{ return _mm_malloc(sizeInBytes,__alignof(T)); }\
   FORCE_INLINE void  operator delete(void* ptr)		{ _mm_free(ptr); }								\
   FORCE_INLINE void* operator new(size_t, void* ptr)	{ return ptr; }									\
   FORCE_INLINE void  operator delete(void*, void*)		{ }												\
   FORCE_INLINE void* operator new[](size_t sizeInBytes){ return _mm_malloc(sizeInBytes,__alignof(T)); }\
   FORCE_INLINE void  operator delete[](void* ptr)		{ _mm_free(ptr); }								\
   FORCE_INLINE void* operator new[](size_t, void* ptr)	{ return ptr; }									\
   FORCE_INLINE void  operator delete[](void*, void*)	{ }										

FORCE_INLINE void MOF_PRINTLOG(const _TCHAR* fmt, ...)
{
	_TCHAR buf[512];
	va_list ap;
	va_start(ap, fmt);
	_vsntprintf(buf, 511, fmt, ap);
	OutputDebugString(buf);
}

#else

template <class T> T& PLACEMENT_NEW(T &p) { new (&p) T(); return p; }
template <class T1, class T2> T1& PLACEMENT_NEW(T1 &p, const T2 &value) { new (&p) T1(value); return p; }
#define		DEBUG_NEW			new
#define		NEW					new
#define		ALIGN_NEW(T)		new (_mm_malloc(sizeof(T),__alignof(T))) T
#define		MOF_ALIGNED_NEW_OPERATOR(T)					\
   FORCE_INLINE void* operator new(size_t sizeInBytes)	{ return _mm_malloc(sizeInBytes,__alignof(T)); }\
   FORCE_INLINE void  operator delete(void* ptr)		{ _mm_free(ptr); }								\
   FORCE_INLINE void* operator new(size_t, void* ptr)	{ return ptr; }									\
   FORCE_INLINE void  operator delete(void*, void*)		{ }												\
   FORCE_INLINE void* operator new[](size_t sizeInBytes){ return _mm_malloc(sizeInBytes,__alignof(T)); }\
   FORCE_INLINE void  operator delete[](void* ptr)		{ _mm_free(ptr); }								\
   FORCE_INLINE void* operator new[](size_t, void* ptr)	{ return ptr; }									\
   FORCE_INLINE void  operator delete[](void*, void*)	{ }										

#define		MOF_PRINTLOG(fmt,...)	__noop

#endif

#endif