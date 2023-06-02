/*************************************************************************//*!
					
					@file	SoundCommon.h
					@brief	サウンド関連の基本定義を行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SOUNDCOMMON__H__

#define		__SOUNDCOMMON__H__

//INCLUDE
#include	"../Common/ReadFile.h"
#include	"../Common/WriteFile.h"
#include	"../Common/DynamicArray.h"

//プラットフォームごとのインクルードと置き換え
#if defined(MOFLIB_DIRECTX12) || defined(MOFLIB_DIRECTX11)

#if defined(DEBUG) || defined(_DEBUG)

#if _MSC_VER >= 1910

#pragma comment (lib,"libogg2017_md32_d.lib")
#pragma comment (lib,"libvorbis2017_md32_d.lib")
#pragma comment (lib,"libvorbisfile2017_md32_d.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"libogg2015_md32_d.lib")
#pragma comment (lib,"libvorbis2015_md32_d.lib")
#pragma comment (lib,"libvorbisfile2015_md32_d.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"libogg2013_md32_d.lib")
#pragma comment (lib,"libvorbis2013_md32_d.lib")
#pragma comment (lib,"libvorbisfile2013_md32_d.lib")

#else

#pragma comment (lib,"libogg_md32_d.lib")
#pragma comment (lib,"libvorbis_md32_d.lib")
#pragma comment (lib,"libvorbisfile_md32_d.lib")

#endif // _MSC_VER == 1800

#else

#if _MSC_VER >= 1910

#pragma comment (lib,"libogg2017_md32.lib")
#pragma comment (lib,"libvorbis2017_md32.lib")
#pragma comment (lib,"libvorbisfile2017_md32.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"libogg2015_md32.lib")
#pragma comment (lib,"libvorbis2015_md32.lib")
#pragma comment (lib,"libvorbisfile2015_md32.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"libogg2013_md32.lib")
#pragma comment (lib,"libvorbis2013_md32.lib")
#pragma comment (lib,"libvorbisfile2013_md32.lib")

#else

#pragma comment (lib,"libogg_md32.lib")
#pragma comment (lib,"libvorbis_md32.lib")
#pragma comment (lib,"libvorbisfile_md32.lib")

#endif // _MSC_VER == 1800

#endif

#ifdef		MOFLIB_WINDOWS_DESKTOP
#pragma comment(lib,"XAudio2.lib")
#pragma comment(lib,"msacm32.lib")
#include	<mmreg.h>
#include	<msacm.h>
#include	<xaudio2.h>
#else
#pragma comment(lib,"XAudio2.lib")
#pragma comment(lib,"windowscodecs.lib")
#pragma comment(lib,"mfcore.lib")
#pragma comment(lib,"mfplat.lib")
#pragma comment(lib,"mfreadwrite.lib")
#pragma comment(lib,"mfuuid.lib")
#include	<XAudio2.h>
#include	<mfidl.h>
#include	<mfapi.h>
#include	<mfreadwrite.h>
#endif

#include	"OGG/vorbisfile.h"

typedef		IXAudio2*							MofSoundDevice;
typedef		IXAudio2MasteringVoice*				MofSoundMaster;
typedef		IXAudio2SourceVoice*				MofSoundBuffer;

#ifdef		MOFLIB_WINDOWS_DESKTOP
#include	"MP3/MP3File.h"
#else
#include	"UWPStream/UWPStream.h"
#endif

#endif

#ifdef		MOFLIB_DIRECTX9
//LIBRARY
#pragma comment(lib,"dsound.lib")
#pragma comment(lib,"msacm32.lib")
#if defined(DEBUG) || defined(_DEBUG)

#if _MSC_VER >= 1910

#pragma comment (lib,"libogg2017_md32_d.lib")
#pragma comment (lib,"libvorbis2017_md32_d.lib")
#pragma comment (lib,"libvorbisfile2017_md32_d.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"libogg2015_md32_d.lib")
#pragma comment (lib,"libvorbis2015_md32_d.lib")
#pragma comment (lib,"libvorbisfile2015_md32_d.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"libogg2013_md32_d.lib")
#pragma comment (lib,"libvorbis2013_md32_d.lib")
#pragma comment (lib,"libvorbisfile2013_md32_d.lib")

#else

#pragma comment (lib,"libogg_md32_d.lib")
#pragma comment (lib,"libvorbis_md32_d.lib")
#pragma comment (lib,"libvorbisfile_md32_d.lib")

#endif // _MSC_VER == 1800

#else

#if _MSC_VER == 1900

#pragma comment (lib,"libogg2015_md32.lib")
#pragma comment (lib,"libvorbis2015_md32.lib")
#pragma comment (lib,"libvorbisfile2015_md32.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"libogg2013_md32.lib")
#pragma comment (lib,"libvorbis2013_md32.lib")
#pragma comment (lib,"libvorbisfile2013_md32.lib")

#else

#pragma comment (lib,"libogg_md32.lib")
#pragma comment (lib,"libvorbis_md32.lib")
#pragma comment (lib,"libvorbisfile_md32.lib")

#endif // _MSC_VER == 1800

#endif
//INCLUDE
#include	<dsound.h>
#include	<mmreg.h>
#include	<msacm.h>
#include	"OGG/vorbisfile.h"
	typedef		LPDIRECTSOUND8						MofSoundDevice;
	typedef		LPDIRECTSOUNDBUFFER					MofSoundMaster;
	typedef		LPDIRECTSOUNDBUFFER8				MofSoundBuffer;
#endif
#ifdef		MOFLIB_OPENGL

#ifdef		MOFLIB_ANDROID

#include	<SLES/OpenSLES.h>
#include	<SLES/OpenSLES_Android.h>
	typedef		SLEngineItf							MofSoundDevice;
	typedef		SLObjectItf							MofSoundMaster;
	typedef		SLObjectItf							MofSoundBuffer;

#else

#include	<AL/al.h>
#include	<AL/alc.h>
	typedef		ALCdevice*							MofSoundDevice;
	typedef		ALCcontext*							MofSoundMaster;
	typedef		ALuint								MofSoundBuffer;

#endif

#endif
	
namespace Mof {
}

#endif

//[EOF]