/*************************************************************************//*!
					
					@file	NetworkCommon.h
					@brief	ライブラリのネットワーク系基本定義を行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__NETWORKCOMMON__H__

#define		__NETWORKCOMMON__H__

//INCLUDE
#include	"../Math/MathCommon.h"
#include	"../Common/Allocator.h"

//!無効なソケット
#define		MOF_INVALID_SOCKET				-1
//!ポート最大値
#define		MOF_MAXPORT						0xFFFF


#ifdef	MOFLIB_WINDOWS

#include	<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

typedef SOCKET						MOFSOCKET;
typedef sockaddr_in					MOFSOCKETADDR;

#endif	// MOFLIB_WINDOWS

#ifdef	MOFLIB_ANDROID

#include	<sys/socket.h>

typedef int							MOFSOCKET;
typedef struct sockaddr_in			MOFSOCKETADDR;

#endif	// MOFLIB_ANDROID


#endif