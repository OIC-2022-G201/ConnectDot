/*************************************************************************//*!
					
					@file	SoundPlatform.h
					@brief	サウンド関連のプラットフォームごとのインクルードを行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SOUNDPLATFORM__H__

#define		__SOUNDPLATFORM__H__

#include	"SoundCommon.h"

#if defined(MOFLIB_DIRECTX12) || defined(MOFLIB_DIRECTX11)

#include	"XAudio/XAudioSound.h"
#include	"XAudio/XAudioSoundBuffer.h"
#include	"XAudio/XAudioStreamingSoundBuffer.h"

#endif

#ifdef		MOFLIB_DIRECTX9
#endif

#ifdef		MOFLIB_OPENGL

#ifdef		MOFLIB_ANDROID

#include	"Sound/OpenSL/SLSoundBuffer.h"
#include	"Sound/OpenSL/SLStreamingSoundBuffer.h"

#else

#endif

#endif

#endif

//[EOF]
