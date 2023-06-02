/*************************************************************************//*!
					
					@file	Platform.h
					@brief	���C�u�����̓���v���b�g�t�H�[�����Ƃ̒�`���s��<br>
							���s����v���b�g�t�H�[���ɂ��MOFLIB_DIRECTX11�AMOFLIB_DIRECTX9�A<br>
							MOFLIB_OPENGL�AMOFLIB_ANDROID�̂����ꂩ��L���ɂ��邱�ƁB

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__PLATFORM__H__

#define		__PLATFORM__H__

//----------------------------------
//�v���b�g�t�H�[���̐U�蕪��
//OS�͊����̒�`����U�蕪����A
//Windows�̏ꍇ�͂���ɃO���t�B�b�N�X���C�u�����̃^�C�v�𕪂��邱�Ƃ��ł���B
//----------------------------------
#if defined( _WIN64 )

//!WINDOWS
#define		MOFLIB_WINDOWS
#define		MOFLIB_WINDOWS_DESKTOP

//!DIRECTX11
#define		MOFLIB_DIRECTX11

//!DIRECTX9
//#define		MOFLIB_DIRECTX9

//!OPENGL
//#define		MOFLIB_OPENGL

#elif defined( _WIN32 )

//!WINDOWS
#define		MOFLIB_WINDOWS
#define		MOFLIB_WINDOWS_DESKTOP

//!DIRECTX12
//#define		MOFLIB_DIRECTX12

//!DIRECTX11
#define		MOFLIB_DIRECTX11

//!DIRECTX9
//#define		MOFLIB_DIRECTX9

//!OPENGL
//#define		MOFLIB_OPENGL

#else

//!OPENGL
#define		MOFLIB_ANDROID

//!OPENGL
#define		MOFLIB_OPENGL

#endif

//----------------------------------
//�v���b�g�t�H�[���̑g�ݍ��킹�G���[
//----------------------------------
#ifdef		MOFLIB_WINDOWS

#ifdef		MOFLIB_ANDROID
#error		"PlatformError!![Please use windows, android, or either.]"
#endif

#ifdef		MOFLIB_DIRECTX12

#ifdef		MOFLIB_DIRECTX11
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif

#ifdef		MOFLIB_DIRECTX9
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif
#ifdef		MOFLIB_OPENGL
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif
#else

#ifdef		MOFLIB_DIRECTX11

#ifdef		MOFLIB_DIRECTX9
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif

#ifdef		MOFLIB_OPENGL
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif

#else

#ifdef		MOFLIB_OPENGL

#ifdef		MOFLIB_DIRECTX9
#error		Please use any one of DIRECTX12, DIRECTX11, DIRECTX9, OPENGL. 
#endif

#endif

#endif
#endif

#endif

#ifdef		MOFLIB_ANDROID

#ifdef		MOFLIB_DIRECTX12
#error		"PlatformError!![In android, DIRECTX12 cannot be used.]"
#endif

#ifdef		MOFLIB_DIRECTX11
#error		"PlatformError!![In android, DIRECTX11 cannot be used.]"
#endif

#ifdef		MOFLIB_DIRECTX9
#error		"PlatformError!![In android, DIRECTX9 cannot be used.]"
#endif

#ifndef		MOFLIB_OPENGL
#define		MOFLIB_ANDROID
#endif

#endif

//----------------------------------
////VisualStudio�pwarning�΍�
//----------------------------------
#ifdef		MOFLIB_WINDOWS
//���C�u����pdb
#pragma warning (disable : 4099) //C runtime lib ('*' �Ɍ�����܂���B�f�o�b�O��񂪂Ȃ����̂Ƃ��āA�I�u�W�F�N�g�Ƀ����N���܂��B)
//WARNING(2005�ȍ~)
#pragma warning (disable : 4995) //C runtime lib ('*' �����O��������ꂽ#pragma�Ƃ��ċL�q����Ă��܂��B)
#pragma warning (disable : 4996) //C runtime lib ('*' ���Â��`���Ƃ��Đ錾����܂����B)

//WARNING(�W��)
//#define		__MOFTYPEWARNINGOUTPUT__
#ifndef		__MOFTYPEWARNINGOUTPUT__
#pragma warning (disable : 4018) //C runtime lib ('*' : signed �� unsigned �̐��l���r���悤�Ƃ��܂����B)
#pragma warning (disable : 4244) //C runtime lib ('*' : '*' ���� '*' �ւ̕ϊ��ł��B�f�[�^��������\��������܂��B)
#endif		//#ifndef	__MOFTYPEWARNINGOUTPUT__
#endif

#if defined(DEBUG) || defined(_DEBUG)
//#define		_ITERATOR_DEBUG_LEVEL					0
#endif

#endif

//[EOF]