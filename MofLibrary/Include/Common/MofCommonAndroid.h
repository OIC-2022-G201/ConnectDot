/*************************************************************************//*!
					
					@file	MofCommonAndroid.h
					@brief	ライブラリの基本定義を行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MOFCOMMONANDROID__H__

#define		__MOFCOMMONANDROID__H__

#include	<ctype.h>
#include	<wchar.h>
#include	<fcntl.h>
#include	<sys/time.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<pthread.h>
#include	<semaphore.h>
#include	<termios.h>
#include	<jni.h>
typedef		unsigned long		MofWindowHandle;
typedef		unsigned long		MofInstanceHandle;
typedef		unsigned long		MofIconHandle;
typedef		unsigned long		MofCursorHandle;
typedef		unsigned long		MofProcResult;
typedef		unsigned long		MofProcParamW;
typedef		unsigned long		MofProcParamL;
typedef		pthread_t			MofThreadID;
typedef		pthread_mutex_t		MofLock;
typedef		sem_t				MofSemaphore;

#define		MOF_ALIGNED16(a)						a __attribute__ ((aligned (16)))
#define		MOF_ALIGNED16_CLASS						MOF_ALIGNED16(class) MOFLIBRARY_API
#define		MOF_ALIGNED16_STRUCT					MOF_ALIGNED16(struct) MOFLIBRARY_API

#if defined(DEBUG) || defined(_DEBUG)

#include	<android/log.h>

template <class T> T& PLACEMENT_NEW(T &p) { new (&p) T(); return p; }
template <class T1, class T2> T1& PLACEMENT_NEW(T1 &p, const T2 &value) { new (&p) T1(value); return p; }
#define		DEBUG_NEW			new
#define		NEW					new
#define		MOF_ALIGNED_NEW_OPERATOR(T)					\
   FORCE_INLINE void* operator new(size_t sizeInBytes)	{ return _mm_malloc(sizeInBytes,__alignof(T)); }\
   FORCE_INLINE void  operator delete(void* ptr)		{ _mm_free(ptr); }								\
   FORCE_INLINE void* operator new(size_t, void* ptr)	{ return ptr; }									\
   FORCE_INLINE void  operator delete(void*, void*)		{ }												\
   FORCE_INLINE void* operator new[](size_t sizeInBytes){ return _mm_malloc(sizeInBytes,__alignof(T)); }\
   FORCE_INLINE void  operator delete[](void* ptr)		{ _mm_free(ptr); }								\
   FORCE_INLINE void* operator new[](size_t, void* ptr)	{ return ptr; }									\
   FORCE_INLINE void  operator delete[](void*, void*)	{ }										

#define		MOF_PRINTLOG(...)	__android_log_print(ANDROID_LOG_DEBUG,"MOF",__VA_ARGS__)

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

#define		MOF_PRINTLOG(fmt, ...)	

#endif


#endif