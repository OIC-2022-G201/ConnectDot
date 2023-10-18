/*************************************************************************//*!
					
					@file	InputCommon.h
					@brief	入力関連の基本定義を行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__INPUTCOMMON__H__

#define		__INPUTCOMMON__H__

//INCLUDE
#include	"../Framework/Window/Window.h"
	
//!キーボードキー数
#define		MOFINPUT_KEYBOARDKEYMAX					256
//!マウスボタン数
#define		MOFINPUT_MOUSEBUTTONMAX					8
//!ゲームパッドボタン数
#define		MOFINPUT_GAMEPADBUTTONMAX				128
	
//環境ごとの対応
//Windows
#ifdef		MOFLIB_WINDOWS

//!タッチダウン
#define		MOF_TOUCHEVENTDOWN						(0)
//!タッチアップ
#define		MOF_TOUCHEVENTUP						(1)
//!タッチムーブ
#define		MOF_TOUCHEVENTMOVE						(2)
//!タッチ認識最大数
#define		MOF_TOUCHMAX							(10)

//DirectInput利用
#if defined(MOFLIB_DIRECTX12) || defined(MOFLIB_DIRECTX11) || defined(MOFLIB_DIRECTX9)
	
//LIBRARY
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"XInput9_1_0")
//#pragma comment(lib,"XInput.lib")
	
//DEFINE
//!DirectInputバージョン
#define		DIRECTINPUT_VERSION						0x0800
//INCLUDE
#include	<dinput.h>
#include	<XInput.h>

#ifdef		MOFLIB_WINDOWS_DESKTOP
typedef		LPDIRECTINPUT8							MofInputDevice;
typedef		LPDIRECTINPUTDEVICE8					MofGamePad;
typedef		DIJOYSTATE2								MofGamePadState;

//キーコード定義
#define		MOFKEY_ESCAPE							DIK_ESCAPE
#define		MOFKEY_1								DIK_1
#define		MOFKEY_2								DIK_2
#define		MOFKEY_3								DIK_3
#define		MOFKEY_4								DIK_4
#define		MOFKEY_5								DIK_5
#define		MOFKEY_6								DIK_6								
#define		MOFKEY_7								DIK_7								
#define		MOFKEY_8								DIK_8								
#define		MOFKEY_9								DIK_9								
#define		MOFKEY_0								DIK_0								
#define		MOFKEY_MINUS							DIK_MINUS							
#define		MOFKEY_EQUALS							DIK_EQUALS							
#define		MOFKEY_BACK								DIK_BACK	
#define		MOFKEY_TAB								DIK_TAB	
#define		MOFKEY_Q								DIK_Q
#define		MOFKEY_W								DIK_W
#define		MOFKEY_E								DIK_E
#define		MOFKEY_R								DIK_R
#define		MOFKEY_T								DIK_T
#define		MOFKEY_Y								DIK_Y
#define		MOFKEY_U								DIK_U
#define		MOFKEY_I								DIK_I
#define		MOFKEY_O								DIK_O	
#define		MOFKEY_P								DIK_P	
#define		MOFKEY_LBRACKET							DIK_LBRACKET
#define		MOFKEY_RBRACKET							DIK_RBRACKET
#define		MOFKEY_RETURN							DIK_RETURN	
#define		MOFKEY_LCONTROL							DIK_LCONTROL
#define		MOFKEY_A								DIK_A
#define		MOFKEY_S								DIK_S
#define		MOFKEY_D								DIK_D
#define		MOFKEY_F								DIK_F
#define		MOFKEY_G								DIK_G
#define		MOFKEY_H								DIK_H
#define		MOFKEY_J								DIK_J
#define		MOFKEY_K								DIK_K
#define		MOFKEY_L								DIK_L
#define		MOFKEY_SEMICOLON						DIK_SEMICOLON						
#define		MOFKEY_APOSTROPHE						DIK_APOSTROPHE						
#define		MOFKEY_GRAVE							DIK_GRAVE							
#define		MOFKEY_LSHIFT							DIK_LSHIFT							
#define		MOFKEY_BACKSLASH						DIK_BACKSLASH						
#define		MOFKEY_Z								DIK_Z								
#define		MOFKEY_X								DIK_X								
#define		MOFKEY_C								DIK_C								
#define		MOFKEY_V								DIK_V								
#define		MOFKEY_B								DIK_B								
#define		MOFKEY_N								DIK_N								
#define		MOFKEY_M								DIK_M								
#define		MOFKEY_COMMA							DIK_COMMA							
#define		MOFKEY_PERIOD							DIK_PERIOD							
#define		MOFKEY_SLASH							DIK_SLASH							
#define		MOFKEY_RSHIFT							DIK_RSHIFT							
#define		MOFKEY_MULTIPLY							DIK_MULTIPLY							
#define		MOFKEY_LMENU							DIK_LMENU							
#define		MOFKEY_SPACE							DIK_SPACE							
#define		MOFKEY_CAPITAL							DIK_CAPITAL							
#define		MOFKEY_F1								DIK_F1								
#define		MOFKEY_F2								DIK_F2								
#define		MOFKEY_F3								DIK_F3								
#define		MOFKEY_F4								DIK_F4								
#define		MOFKEY_F5								DIK_F5								
#define		MOFKEY_F6								DIK_F6								
#define		MOFKEY_F7								DIK_F7								
#define		MOFKEY_F8								DIK_F8								
#define		MOFKEY_F9								DIK_F9								
#define		MOFKEY_F10								DIK_F10								
#define		MOFKEY_NUMLOCK							DIK_NUMLOCK							
#define		MOFKEY_SCROLL							DIK_SCROLL							
#define		MOFKEY_NUMPAD7							DIK_NUMPAD7							
#define		MOFKEY_NUMPAD8							DIK_NUMPAD8							
#define		MOFKEY_NUMPAD9							DIK_NUMPAD9							
#define		MOFKEY_SUBTRACT							DIK_SUBTRACT							
#define		MOFKEY_NUMPAD4							DIK_NUMPAD4							
#define		MOFKEY_NUMPAD5							DIK_NUMPAD5							
#define		MOFKEY_NUMPAD6							DIK_NUMPAD6							
#define		MOFKEY_ADD								DIK_ADD								
#define		MOFKEY_NUMPAD1							DIK_NUMPAD1							
#define		MOFKEY_NUMPAD2							DIK_NUMPAD2							
#define		MOFKEY_NUMPAD3							DIK_NUMPAD3							
#define		MOFKEY_NUMPAD0							DIK_NUMPAD0							
#define		MOFKEY_DECIMAL							DIK_DECIMAL							
#define		MOFKEY_OEM_102							DIK_OEM_102							
#define		MOFKEY_F11								DIK_F11								
#define		MOFKEY_F12								DIK_F12								
#define		MOFKEY_F13								DIK_F13								
#define		MOFKEY_F14								DIK_F14								
#define		MOFKEY_F15								DIK_F15								
#define		MOFKEY_KANA								DIK_KANA								
#define		MOFKEY_ABNT_C1							DIK_ABNT_C1							
#define		MOFKEY_CONVERT							DIK_CONVERT							
#define		MOFKEY_NOCONVERT						DIK_NOCONVERT						
#define		MOFKEY_YEN								DIK_YEN								
#define		MOFKEY_ABNT_C2							DIK_ABNT_C2							
#define		MOFKEY_NUMPADEQUALS						DIK_NUMPADEQUALS						
#define		MOFKEY_PREVTRACK						DIK_PREVTRACK						
#define		MOFKEY_AT								DIK_AT								
#define		MOFKEY_COLON							DIK_COLON							
#define		MOFKEY_UNDERLINE						DIK_UNDERLINE						
#define		MOFKEY_KANJI							DIK_KANJI							
#define		MOFKEY_STOP								DIK_STOP								
#define		MOFKEY_AX								DIK_AX								
#define		MOFKEY_UNLABELED						DIK_UNLABELED						
#define		MOFKEY_NEXTTRACK						DIK_NEXTTRACK						
#define		MOFKEY_NUMPADENTER						DIK_NUMPADENTER						
#define		MOFKEY_RCONTROL							DIK_RCONTROL							
#define		MOFKEY_MUTE								DIK_MUTE								
#define		MOFKEY_CALCULATOR						DIK_CALCULATOR						
#define		MOFKEY_PLAYPAUSE						DIK_PLAYPAUSE						
#define		MOFKEY_MEDIASTOP						DIK_MEDIASTOP						
#define		MOFKEY_VOLUMEDOWN						DIK_VOLUMEDOWN						
#define		MOFKEY_VOLUMEUP							DIK_VOLUMEUP							
#define		MOFKEY_WEBHOME							DIK_WEBHOME							
#define		MOFKEY_NUMPADCOMMA						DIK_NUMPADCOMMA						
#define		MOFKEY_DIVIDE							DIK_DIVIDE							
#define		MOFKEY_SYSRQ							DIK_SYSRQ							
#define		MOFKEY_RMENU							DIK_RMENU							
#define		MOFKEY_PAUSE							DIK_PAUSE							
#define		MOFKEY_HOME								DIK_HOME								
#define		MOFKEY_UP								DIK_UP								
#define		MOFKEY_PRIOR							DIK_PRIOR							
#define		MOFKEY_LEFT								DIK_LEFT								
#define		MOFKEY_RIGHT							DIK_RIGHT							
#define		MOFKEY_END								DIK_END								
#define		MOFKEY_DOWN								DIK_DOWN								
#define		MOFKEY_NEXT								DIK_NEXT								
#define		MOFKEY_INSERT							DIK_INSERT							
#define		MOFKEY_DELETE							DIK_DELETE							
#define		MOFKEY_LWIN								DIK_LWIN								
#define		MOFKEY_RWIN								DIK_RWIN								
#define		MOFKEY_APPS								DIK_APPS								
#define		MOFKEY_POWER							DIK_POWER							
#define		MOFKEY_SLEEP							DIK_SLEEP							
#define		MOFKEY_WAKE								DIK_WAKE								
#define		MOFKEY_WEBSEARCH						DIK_WEBSEARCH
#define		MOFKEY_WEBFAVORITES						DIK_WEBFAVORITES						
#define		MOFKEY_WEBREFRESH						DIK_WEBREFRESH						
#define		MOFKEY_WEBSTOP							DIK_WEBSTOP							
#define		MOFKEY_WEBFORWARD						DIK_WEBFORWARD						
#define		MOFKEY_WEBBACK							DIK_WEBBACK
#define		MOFKEY_MYCOMPUTER						DIK_MYCOMPUTER
#define		MOFKEY_MAIL								DIK_MAIL
#define		MOFKEY_MEDIASELECT						DIK_MEDIASELECT
#define		MOFKEY_BACKSPACE      					MOFKEY_BACK         
#define		MOFKEY_NUMPADSTAR     					MOFKEY_MULTIPLY     
#define		MOFKEY_LALT           					MOFKEY_LMENU        
#define		MOFKEY_CAPSLOCK       					MOFKEY_CAPITAL      
#define		MOFKEY_NUMPADMINUS    					MOFKEY_SUBTRACT
#define		MOFKEY_NUMPADPLUS     					MOFKEY_ADD
#define		MOFKEY_NUMPADPERIOD   					MOFKEY_DECIMAL
#define		MOFKEY_NUMPADSLASH    					MOFKEY_DIVIDE
#define		MOFKEY_RALT           					MOFKEY_RMENU
#define		MOFKEY_UPARROW        					MOFKEY_UP
#define		MOFKEY_PGUP           					MOFKEY_PRIOR
#define		MOFKEY_LEFTARROW      					MOFKEY_LEFT         
#define		MOFKEY_RIGHTARROW     					MOFKEY_RIGHT        
#define		MOFKEY_DOWNARROW      					MOFKEY_DOWN         
#define		MOFKEY_PGDN           					MOFKEY_NEXT
#define		MOFKEY_CIRCUMFLEX						MOFKEY_PREVTRACK

#else
typedef		void*									MofInputDevice;
typedef		Windows::Gaming::Input::Gamepad^		MofGamePad;
typedef		Windows::Gaming::Input::GamepadReading	MofGamePadState;

//キーコード定義
#define		MOFKEY_ESCAPE							(MofU8)Windows::System::VirtualKey::Escape
#define		MOFKEY_1								(MofU8)Windows::System::VirtualKey::Number1
#define		MOFKEY_2								(MofU8)Windows::System::VirtualKey::Number2
#define		MOFKEY_3								(MofU8)Windows::System::VirtualKey::Number3
#define		MOFKEY_4								(MofU8)Windows::System::VirtualKey::Number4
#define		MOFKEY_5								(MofU8)Windows::System::VirtualKey::Number5
#define		MOFKEY_6								(MofU8)Windows::System::VirtualKey::Number6					
#define		MOFKEY_7								(MofU8)Windows::System::VirtualKey::Number7					
#define		MOFKEY_8								(MofU8)Windows::System::VirtualKey::Number8					
#define		MOFKEY_9								(MofU8)Windows::System::VirtualKey::Number9					
#define		MOFKEY_0								(MofU8)Windows::System::VirtualKey::Number0						
#define		MOFKEY_MINUS							(MofU8)0
#define		MOFKEY_EQUALS							(MofU8)0
#define		MOFKEY_BACK								(MofU8)Windows::System::VirtualKey::Back
#define		MOFKEY_TAB								(MofU8)Windows::System::VirtualKey::Tab
#define		MOFKEY_Q								(MofU8)Windows::System::VirtualKey::Q
#define		MOFKEY_W								(MofU8)Windows::System::VirtualKey::W
#define		MOFKEY_E								(MofU8)Windows::System::VirtualKey::E
#define		MOFKEY_R								(MofU8)Windows::System::VirtualKey::R
#define		MOFKEY_T								(MofU8)Windows::System::VirtualKey::T
#define		MOFKEY_Y								(MofU8)Windows::System::VirtualKey::Y
#define		MOFKEY_U								(MofU8)Windows::System::VirtualKey::U
#define		MOFKEY_I								(MofU8)Windows::System::VirtualKey::I
#define		MOFKEY_O								(MofU8)Windows::System::VirtualKey::O	
#define		MOFKEY_P								(MofU8)Windows::System::VirtualKey::P	
#define		MOFKEY_LBRACKET							(MofU8)0
#define		MOFKEY_RBRACKET							(MofU8)0
#define		MOFKEY_RETURN							(MofU8)Windows::System::VirtualKey::Enter
#define		MOFKEY_LCONTROL							(MofU8)Windows::System::VirtualKey::LeftControl
#define		MOFKEY_A								(MofU8)Windows::System::VirtualKey::A
#define		MOFKEY_S								(MofU8)Windows::System::VirtualKey::S
#define		MOFKEY_D								(MofU8)Windows::System::VirtualKey::D
#define		MOFKEY_F								(MofU8)Windows::System::VirtualKey::F
#define		MOFKEY_G								(MofU8)Windows::System::VirtualKey::G
#define		MOFKEY_H								(MofU8)Windows::System::VirtualKey::H
#define		MOFKEY_J								(MofU8)Windows::System::VirtualKey::J
#define		MOFKEY_K								(MofU8)Windows::System::VirtualKey::K
#define		MOFKEY_L								(MofU8)Windows::System::VirtualKey::L
#define		MOFKEY_SEMICOLON						(MofU8)0
#define		MOFKEY_APOSTROPHE						(MofU8)0						
#define		MOFKEY_GRAVE							(MofU8)0							
#define		MOFKEY_LSHIFT							(MofU8)Windows::System::VirtualKey::LeftShift							
#define		MOFKEY_BACKSLASH						(MofU8)0						
#define		MOFKEY_Z								(MofU8)Windows::System::VirtualKey::Z								
#define		MOFKEY_X								(MofU8)Windows::System::VirtualKey::X								
#define		MOFKEY_C								(MofU8)Windows::System::VirtualKey::C								
#define		MOFKEY_V								(MofU8)Windows::System::VirtualKey::V								
#define		MOFKEY_B								(MofU8)Windows::System::VirtualKey::B								
#define		MOFKEY_N								(MofU8)Windows::System::VirtualKey::N								
#define		MOFKEY_M								(MofU8)Windows::System::VirtualKey::M								
#define		MOFKEY_COMMA							(MofU8)0
#define		MOFKEY_PERIOD							(MofU8)0	
#define		MOFKEY_SLASH							(MofU8)0							
#define		MOFKEY_RSHIFT							(MofU8)Windows::System::VirtualKey::RightShift							
#define		MOFKEY_MULTIPLY							(MofU8)Windows::System::VirtualKey::Multiply							
#define		MOFKEY_LMENU							(MofU8)Windows::System::VirtualKey::LeftMenu							
#define		MOFKEY_SPACE							(MofU8)Windows::System::VirtualKey::Space							
#define		MOFKEY_CAPITAL							(MofU8)0							
#define		MOFKEY_F1								(MofU8)Windows::System::VirtualKey::F1								
#define		MOFKEY_F2								(MofU8)Windows::System::VirtualKey::F2								
#define		MOFKEY_F3								(MofU8)Windows::System::VirtualKey::F3								
#define		MOFKEY_F4								(MofU8)Windows::System::VirtualKey::F4								
#define		MOFKEY_F5								(MofU8)Windows::System::VirtualKey::F5								
#define		MOFKEY_F6								(MofU8)Windows::System::VirtualKey::F6								
#define		MOFKEY_F7								(MofU8)Windows::System::VirtualKey::F7								
#define		MOFKEY_F8								(MofU8)Windows::System::VirtualKey::F8								
#define		MOFKEY_F9								(MofU8)Windows::System::VirtualKey::F9								
#define		MOFKEY_F10								(MofU8)Windows::System::VirtualKey::F10								
#define		MOFKEY_NUMLOCK							(MofU8)Windows::System::VirtualKey::NumberKeyLock
#define		MOFKEY_SCROLL							(MofU8)Windows::System::VirtualKey::Scroll							
#define		MOFKEY_NUMPAD7							(MofU8)Windows::System::VirtualKey::NumberPad7							
#define		MOFKEY_NUMPAD8							(MofU8)Windows::System::VirtualKey::NumberPad8							
#define		MOFKEY_NUMPAD9							(MofU8)Windows::System::VirtualKey::NumberPad9
#define		MOFKEY_SUBTRACT							(MofU8)Windows::System::VirtualKey::Subtract							
#define		MOFKEY_NUMPAD4							(MofU8)Windows::System::VirtualKey::NumberPad4
#define		MOFKEY_NUMPAD5							(MofU8)Windows::System::VirtualKey::NumberPad5
#define		MOFKEY_NUMPAD6							(MofU8)Windows::System::VirtualKey::NumberPad6
#define		MOFKEY_ADD								(MofU8)Windows::System::VirtualKey::Add								
#define		MOFKEY_NUMPAD1							(MofU8)Windows::System::VirtualKey::NumberPad1
#define		MOFKEY_NUMPAD2							(MofU8)Windows::System::VirtualKey::NumberPad2
#define		MOFKEY_NUMPAD3							(MofU8)Windows::System::VirtualKey::NumberPad3
#define		MOFKEY_NUMPAD0							(MofU8)Windows::System::VirtualKey::NumberPad0
#define		MOFKEY_DECIMAL							(MofU8)Windows::System::VirtualKey::Decimal							
#define		MOFKEY_OEM_102							(MofU8)0							
#define		MOFKEY_F11								(MofU8)Windows::System::VirtualKey::F11								
#define		MOFKEY_F12								(MofU8)Windows::System::VirtualKey::F12								
#define		MOFKEY_F13								(MofU8)Windows::System::VirtualKey::F13								
#define		MOFKEY_F14								(MofU8)Windows::System::VirtualKey::F14								
#define		MOFKEY_F15								(MofU8)Windows::System::VirtualKey::F15								
#define		MOFKEY_KANA								(MofU8)Windows::System::VirtualKey::Kana								
#define		MOFKEY_ABNT_C1							(MofU8)0							
#define		MOFKEY_CONVERT							(MofU8)Windows::System::VirtualKey::Convert							
#define		MOFKEY_NOCONVERT						(MofU8)Windows::System::VirtualKey::NonConvert
#define		MOFKEY_YEN								(MofU8)0
#define		MOFKEY_ABNT_C2							(MofU8)0							
#define		MOFKEY_NUMPADEQUALS						(MofU8)0						
#define		MOFKEY_PREVTRACK						(MofU8)0						
#define		MOFKEY_AT								(MofU8)0								
#define		MOFKEY_COLON							(MofU8)0							
#define		MOFKEY_UNDERLINE						(MofU8)0						
#define		MOFKEY_KANJI							(MofU8)Windows::System::VirtualKey::Kanji							
#define		MOFKEY_STOP								(MofU8)Windows::System::VirtualKey::Stop								
#define		MOFKEY_AX								(MofU8)0	
#define		MOFKEY_UNLABELED						(MofU8)0						
#define		MOFKEY_NEXTTRACK						(MofU8)0						
#define		MOFKEY_NUMPADENTER						(MofU8)0						
#define		MOFKEY_RCONTROL							(MofU8)Windows::System::VirtualKey::RightControl							
#define		MOFKEY_MUTE								(MofU8)0								
#define		MOFKEY_CALCULATOR						(MofU8)0						
#define		MOFKEY_PLAYPAUSE						(MofU8)0						
#define		MOFKEY_MEDIASTOP						(MofU8)0						
#define		MOFKEY_VOLUMEDOWN						(MofU8)0						
#define		MOFKEY_VOLUMEUP							(MofU8)0							
#define		MOFKEY_WEBHOME							(MofU8)0							
#define		MOFKEY_NUMPADCOMMA						(MofU8)0						
#define		MOFKEY_DIVIDE							(MofU8)Windows::System::VirtualKey::Divide							
#define		MOFKEY_SYSRQ							(MofU8)0							
#define		MOFKEY_RMENU							(MofU8)Windows::System::VirtualKey::RightMenu							
#define		MOFKEY_PAUSE							(MofU8)Windows::System::VirtualKey::Pause		
#define		MOFKEY_HOME								(MofU8)Windows::System::VirtualKey::Home
#define		MOFKEY_UP								(MofU8)Windows::System::VirtualKey::Up								
#define		MOFKEY_PRIOR							(MofU8)0							
#define		MOFKEY_LEFT								(MofU8)Windows::System::VirtualKey::Left	
#define		MOFKEY_RIGHT							(MofU8)Windows::System::VirtualKey::Right							
#define		MOFKEY_END								(MofU8)Windows::System::VirtualKey::End								
#define		MOFKEY_DOWN								(MofU8)Windows::System::VirtualKey::Down								
#define		MOFKEY_NEXT								(MofU8)0								
#define		MOFKEY_INSERT							(MofU8)Windows::System::VirtualKey::Insert							
#define		MOFKEY_DELETE							(MofU8)Windows::System::VirtualKey::Delete
#define		MOFKEY_LWIN								(MofU8)Windows::System::VirtualKey::LeftWindows	
#define		MOFKEY_RWIN								(MofU8)Windows::System::VirtualKey::RightWindows
#define		MOFKEY_APPS								(MofU8)Windows::System::VirtualKey::Application
#define		MOFKEY_POWER							(MofU8)0
#define		MOFKEY_SLEEP							(MofU8)Windows::System::VirtualKey::Sleep							
#define		MOFKEY_WAKE								(MofU8)0								
#define		MOFKEY_WEBSEARCH						(MofU8)0
#define		MOFKEY_WEBFAVORITES						(MofU8)0						
#define		MOFKEY_WEBREFRESH						(MofU8)0						
#define		MOFKEY_WEBSTOP							(MofU8)0							
#define		MOFKEY_WEBFORWARD						(MofU8)0						
#define		MOFKEY_WEBBACK							(MofU8)0
#define		MOFKEY_MYCOMPUTER						(MofU8)0
#define		MOFKEY_MAIL								(MofU8)0
#define		MOFKEY_MEDIASELECT						(MofU8)0
#define		MOFKEY_BACKSPACE      					MOFKEY_BACK         
#define		MOFKEY_NUMPADSTAR     					MOFKEY_MULTIPLY     
#define		MOFKEY_LALT           					MOFKEY_LMENU        
#define		MOFKEY_CAPSLOCK       					MOFKEY_CAPITAL      
#define		MOFKEY_NUMPADMINUS    					MOFKEY_SUBTRACT
#define		MOFKEY_NUMPADPLUS     					MOFKEY_ADD
#define		MOFKEY_NUMPADPERIOD   					MOFKEY_DECIMAL
#define		MOFKEY_NUMPADSLASH    					MOFKEY_DIVIDE
#define		MOFKEY_RALT           					MOFKEY_RMENU
#define		MOFKEY_UPARROW        					MOFKEY_UP
#define		MOFKEY_PGUP           					MOFKEY_PRIOR
#define		MOFKEY_LEFTARROW      					MOFKEY_LEFT         
#define		MOFKEY_RIGHTARROW     					MOFKEY_RIGHT        
#define		MOFKEY_DOWNARROW      					MOFKEY_DOWN         
#define		MOFKEY_PGDN           					MOFKEY_NEXT
#define		MOFKEY_CIRCUMFLEX						MOFKEY_PREVTRACK

#endif

//マウスキー定義
#define		MOFMOUSE_LBUTTON						0
#define		MOFMOUSE_RBUTTON						1

#else

typedef		LPMofVoid								MofInputDevice;
typedef		LPMofVoid								MofGamePad;
typedef		LPMofVoid								MofGamePadState;

//マウスキー定義
#define		MOFMOUSE_LBUTTON						0x01
#define		MOFMOUSE_RBUTTON						0x02

//キーコード定義
#define		MOFKEY_1								'1'
#define		MOFKEY_2								'2'
#define		MOFKEY_3								'3'
#define		MOFKEY_4								'4'
#define		MOFKEY_5								'5'
#define		MOFKEY_6								'6'								
#define		MOFKEY_7								'7'								
#define		MOFKEY_8								'8'								
#define		MOFKEY_9								'9'								
#define		MOFKEY_0								'0'								
#define		MOFKEY_MINUS							VK_OEM_MINUS							
#define		MOFKEY_EQUALS							NULL							
#define		MOFKEY_BACK								VK_BACK								
#define		MOFKEY_TAB								VK_TAB								
#define		MOFKEY_Q								'Q'
#define		MOFKEY_W								'W'
#define		MOFKEY_E								'E'
#define		MOFKEY_R								'R'
#define		MOFKEY_T								'T'
#define		MOFKEY_Y								'Y'
#define		MOFKEY_U								'U'
#define		MOFKEY_I								'I'
#define		MOFKEY_O								'O'
#define		MOFKEY_P								'P'
#define		MOFKEY_LBRACKET							VK_OEM_4
#define		MOFKEY_RBRACKET							VK_OEM_6
#define		MOFKEY_RETURN							VK_RETURN							
#define		MOFKEY_LCONTROL							VK_LCONTROL							
#define		MOFKEY_A								'A'
#define		MOFKEY_S								'S'
#define		MOFKEY_D								'D'
#define		MOFKEY_F								'F'
#define		MOFKEY_G								'G'
#define		MOFKEY_H								'H'
#define		MOFKEY_J								'J'
#define		MOFKEY_K								'K'
#define		MOFKEY_L								'L'
#define		MOFKEY_SEMICOLON						VK_OEM_PLUS						
#define		MOFKEY_APOSTROPHE						NULL						
#define		MOFKEY_GRAVE							NULL							
#define		MOFKEY_LSHIFT							VK_LSHIFT							
#define		MOFKEY_BACKSLASH						NULL						
#define		MOFKEY_Z								'Z'
#define		MOFKEY_X								'X'
#define		MOFKEY_C								'C'
#define		MOFKEY_V								'V'
#define		MOFKEY_B								'B'
#define		MOFKEY_N								'N'
#define		MOFKEY_M								'M'
#define		MOFKEY_COMMA							VK_OEM_COMMA							
#define		MOFKEY_PERIOD							VK_PERIOD							
#define		MOFKEY_SLASH							VK_OEM_2
#define		MOFKEY_RSHIFT							VK_RSHIFT							
#define		MOFKEY_MULTIPLY							VK_MULTIPLY							
#define		MOFKEY_LMENU							VK_LMENU							
#define		MOFKEY_SPACE							VK_SPACE							
#define		MOFKEY_CAPITAL							VK_CAPITAL							
#define		MOFKEY_F1								VK_F1								
#define		MOFKEY_F2								VK_F2								
#define		MOFKEY_F3								VK_F3								
#define		MOFKEY_F4								VK_F4								
#define		MOFKEY_F5								VK_F5								
#define		MOFKEY_F6								VK_F6								
#define		MOFKEY_F7								VK_F7								
#define		MOFKEY_F8								VK_F8								
#define		MOFKEY_F9								VK_F9								
#define		MOFKEY_F10								VK_F10								
#define		MOFKEY_NUMLOCK							VK_NUMLOCK							
#define		MOFKEY_SCROLL							VK_SCROLL							
#define		MOFKEY_NUMPAD7							VK_NUMPAD7							
#define		MOFKEY_NUMPAD8							VK_NUMPAD8							
#define		MOFKEY_NUMPAD9							VK_NUMPAD9							
#define		MOFKEY_SUBTRACT							VK_SUBTRACT							
#define		MOFKEY_NUMPAD4							VK_NUMPAD4
#define		MOFKEY_NUMPAD5							VK_NUMPAD5							
#define		MOFKEY_NUMPAD6							VK_NUMPAD6							
#define		MOFKEY_ADD								VK_ADD								
#define		MOFKEY_NUMPAD1							VK_NUMPAD1							
#define		MOFKEY_NUMPAD2							VK_NUMPAD2							
#define		MOFKEY_NUMPAD3							VK_NUMPAD3							
#define		MOFKEY_NUMPAD0							VK_NUMPAD0							
#define		MOFKEY_DECIMAL							VK_DECIMAL							
#define		MOFKEY_OEM_102							VK_OEM_102							
#define		MOFKEY_F11								VK_F11								
#define		MOFKEY_F12								VK_F12								
#define		MOFKEY_F13								VK_F13								
#define		MOFKEY_F14								VK_F14								
#define		MOFKEY_F15								VK_F15								
#define		MOFKEY_KANA								VK_KANA								
#define		MOFKEY_ABNT_C1							NULL							
#define		MOFKEY_CONVERT							VK_CONVERT							
#define		MOFKEY_NOCONVERT						VK_NONCONVERT
#define		MOFKEY_YEN								VK_OEM_5
#define		MOFKEY_ABNT_C2							NULL							
#define		MOFKEY_NUMPADEQUALS						NULL						
#define		MOFKEY_PREVTRACK						VK_MEDIA_PREV_TRACK						
#define		MOFKEY_AT								VK_OEM_3
#define		MOFKEY_COLON							VK_OEM_1							
#define		MOFKEY_UNDERLINE						NULL						
#define		MOFKEY_KANJI							VK_KANJI							
#define		MOFKEY_STOP								NULL								
#define		MOFKEY_AX								VK_OEM_AX
#define		MOFKEY_UNLABELED						NULL						
#define		MOFKEY_NEXTTRACK						VK_MEDIA_NEXT_TRACK						
#define		MOFKEY_NUMPADENTER						VK_RETURN						
#define		MOFKEY_RCONTROL							VK_RCONTROL							
#define		MOFKEY_MUTE								VK_VOLUME_MUTE								
#define		MOFKEY_CALCULATOR						NULL						
#define		MOFKEY_PLAYPAUSE						VK_MEDIA_PLAY_PAUSE						
#define		MOFKEY_MEDIASTOP						VK_MEDIA_STOP						
#define		MOFKEY_VOLUMEDOWN						VK_VOLUME_DOWN						
#define		MOFKEY_VOLUMEUP							VK_VOLUME_UP							
#define		MOFKEY_WEBHOME							VK_BROWSER_HOME							
#define		MOFKEY_NUMPADCOMMA						NULL						
#define		MOFKEY_DIVIDE							VK_DIVIDE							
#define		MOFKEY_SYSRQ							NULL							
#define		MOFKEY_RMENU							VK_RMENU							
#define		MOFKEY_PAUSE							VK_PAUSE							
#define		MOFKEY_HOME								VK_HOME								
#define		MOFKEY_UP								VK_UP								
#define		MOFKEY_PRIOR							VK_PRIOR							
#define		MOFKEY_LEFT								VK_LEFT								
#define		MOFKEY_RIGHT							VK_RIGHT							
#define		MOFKEY_END								VK_END								
#define		MOFKEY_DOWN								VK_DOWN								
#define		MOFKEY_NEXT								VK_NEXT								
#define		MOFKEY_INSERT							VK_INSERT							
#define		MOFKEY_DELETE							VK_DELETE							
#define		MOFKEY_LWIN								VK_LWIN								
#define		MOFKEY_RWIN								VK_RWIN								
#define		MOFKEY_APPS								VK_APPS								
#define		MOFKEY_POWER							NULL							
#define		MOFKEY_SLEEP							VK_SLEEP
#define		MOFKEY_WAKE								NULL
#define		MOFKEY_WEBSEARCH						VK_BROWSER_SEARCH
#define		MOFKEY_WEBFAVORITES						VK_BROWSER_FAVORITES						
#define		MOFKEY_WEBREFRESH						VK_BROWSER_REFRESH						
#define		MOFKEY_WEBSTOP							VK_BROWSER_STOP							
#define		MOFKEY_WEBFORWARD						VK_BROWSER_FORWARD						
#define		MOFKEY_WEBBACK							VK_BROWSER_BACK
#define		MOFKEY_MYCOMPUTER						NULL
#define		MOFKEY_MAIL								VK_LAUNCH_MAIL
#define		MOFKEY_MEDIASELECT						VK_LAUNCH_MEDIA_SELECT
#define		MOFKEY_BACKSPACE      					MOFKEY_BACK         
#define		MOFKEY_NUMPADSTAR     					MOFKEY_MULTIPLY     
#define		MOFKEY_LALT           					MOFKEY_LMENU        
#define		MOFKEY_CAPSLOCK       					MOFKEY_CAPITAL      
#define		MOFKEY_NUMPADMINUS    					MOFKEY_SUBTRACT
#define		MOFKEY_NUMPADPLUS     					MOFKEY_ADD
#define		MOFKEY_NUMPADPERIOD   					MOFKEY_DECIMAL
#define		MOFKEY_NUMPADSLASH    					MOFKEY_DIVIDE
#define		MOFKEY_RALT           					MOFKEY_RMENU
#define		MOFKEY_UPARROW        					MOFKEY_UP
#define		MOFKEY_PGUP           					MOFKEY_PRIOR
#define		MOFKEY_LEFTARROW      					MOFKEY_LEFT         
#define		MOFKEY_RIGHTARROW     					MOFKEY_RIGHT
#define		MOFKEY_DOWNARROW      					MOFKEY_DOWN         
#define		MOFKEY_PGDN           					MOFKEY_NEXT

#endif

#endif

//Android
#ifdef		MOFLIB_ANDROID

typedef		LPMofVoid								MofInputDevice;
typedef		LPMofVoid								MofGamePad;
typedef		LPMofVoid								MofGamePadState;

//!タッチダウン
#define		MOF_TOUCHEVENTDOWN						(0)
//!タッチアップ
#define		MOF_TOUCHEVENTUP						(1)
//!タッチムーブ
#define		MOF_TOUCHEVENTMOVE						(2)
//!タッチダウン
#define		MOF_TOUCHEVENTPOINTERDOWN				(5)
//!タッチアップ
#define		MOF_TOUCHEVENTPOINTERUP					(6)
//!タッチ認識最大数
#define		MOF_TOUCHMAX							(10)

//マウスキー定義
#define		MOFMOUSE_LBUTTON						0
#define		MOFMOUSE_RBUTTON						0

//キーコード定義
#define		MOFKEY_ESCAPE							NULL
#define		MOFKEY_1								8
#define		MOFKEY_2								9
#define		MOFKEY_3								10
#define		MOFKEY_4								11
#define		MOFKEY_5								12
#define		MOFKEY_6								13
#define		MOFKEY_7								14
#define		MOFKEY_8								15
#define		MOFKEY_9								16
#define		MOFKEY_0								7
#define		MOFKEY_MINUS							69
#define		MOFKEY_EQUALS							70
#define		MOFKEY_BACK								4
#define		MOFKEY_TAB								51
#define		MOFKEY_Q								45
#define		MOFKEY_W								51
#define		MOFKEY_E								33
#define		MOFKEY_R								46
#define		MOFKEY_T								48
#define		MOFKEY_Y								53
#define		MOFKEY_U								49
#define		MOFKEY_I								37
#define		MOFKEY_O								43
#define		MOFKEY_P								44
#define		MOFKEY_LBRACKET							71
#define		MOFKEY_RBRACKET							72
#define		MOFKEY_RETURN							66
#define		MOFKEY_LCONTROL							NULL
#define		MOFKEY_A								29
#define		MOFKEY_S								47
#define		MOFKEY_D								32
#define		MOFKEY_F								34
#define		MOFKEY_G								35
#define		MOFKEY_H								36
#define		MOFKEY_J								38
#define		MOFKEY_K								39
#define		MOFKEY_L								40
#define		MOFKEY_SEMICOLON						74
#define		MOFKEY_APOSTROPHE						75
#define		MOFKEY_GRAVE							68
#define		MOFKEY_LSHIFT							59
#define		MOFKEY_BACKSLASH						73
#define		MOFKEY_Z								54
#define		MOFKEY_X								52
#define		MOFKEY_C								31
#define		MOFKEY_V								50
#define		MOFKEY_B								30
#define		MOFKEY_N								42
#define		MOFKEY_M								41
#define		MOFKEY_COMMA							55
#define		MOFKEY_PERIOD							56
#define		MOFKEY_SLASH							76
#define		MOFKEY_RSHIFT							60
#define		MOFKEY_MULTIPLY							NULL
#define		MOFKEY_LMENU							57
#define		MOFKEY_SPACE							62
#define		MOFKEY_CAPITAL							NULL
#define		MOFKEY_F1								NULL
#define		MOFKEY_F2								NULL
#define		MOFKEY_F3								NULL
#define		MOFKEY_F4								NULL
#define		MOFKEY_F5								NULL
#define		MOFKEY_F6								NULL
#define		MOFKEY_F7								NULL
#define		MOFKEY_F8								NULL
#define		MOFKEY_F9								NULL
#define		MOFKEY_F10								NULL
#define		MOFKEY_NUMLOCK							NULL
#define		MOFKEY_SCROLL							NULL
#define		MOFKEY_NUMPAD7							NULL
#define		MOFKEY_NUMPAD8							NULL
#define		MOFKEY_NUMPAD9							NULL
#define		MOFKEY_SUBTRACT							NULL
#define		MOFKEY_NUMPAD4							NULL
#define		MOFKEY_NUMPAD5							NULL
#define		MOFKEY_NUMPAD6							NULL
#define		MOFKEY_ADD								NULL
#define		MOFKEY_NUMPAD1							NULL
#define		MOFKEY_NUMPAD2							NULL
#define		MOFKEY_NUMPAD3							NULL
#define		MOFKEY_NUMPAD0							NULL
#define		MOFKEY_DECIMAL							NULL
#define		MOFKEY_OEM_102							NULL
#define		MOFKEY_F11								NULL
#define		MOFKEY_F12								NULL
#define		MOFKEY_F13								NULL
#define		MOFKEY_F14								NULL
#define		MOFKEY_F15								NULL
#define		MOFKEY_KANA								NULL
#define		MOFKEY_ABNT_C1							NULL
#define		MOFKEY_CONVERT							NULL
#define		MOFKEY_NOCONVERT						NULL
#define		MOFKEY_YEN								NULL
#define		MOFKEY_ABNT_C2							NULL
#define		MOFKEY_NUMPADEQUALS						NULL
#define		MOFKEY_PREVTRACK						NULL
#define		MOFKEY_AT								77
#define		MOFKEY_COLON							NULL
#define		MOFKEY_UNDERLINE						NULL
#define		MOFKEY_KANJI							NULL
#define		MOFKEY_STOP								NULL
#define		MOFKEY_AX								NULL
#define		MOFKEY_UNLABELED						NULL
#define		MOFKEY_NEXTTRACK						NULL
#define		MOFKEY_NUMPADENTER						NULL
#define		MOFKEY_RCONTROL							NULL
#define		MOFKEY_MUTE								91
#define		MOFKEY_CALCULATOR						NULL
#define		MOFKEY_PLAYPAUSE						NULL
#define		MOFKEY_MEDIASTOP						86
#define		MOFKEY_VOLUMEDOWN						25
#define		MOFKEY_VOLUMEUP							24
#define		MOFKEY_WEBHOME							NULL
#define		MOFKEY_NUMPADCOMMA						NULL
#define		MOFKEY_DIVIDE							NULL
#define		MOFKEY_SYSRQ							NULL
#define		MOFKEY_RMENU							58
#define		MOFKEY_PAUSE							NULL
#define		MOFKEY_HOME								3
#define		MOFKEY_UP								NULL
#define		MOFKEY_PRIOR							19
#define		MOFKEY_LEFT								21
#define		MOFKEY_RIGHT							22
#define		MOFKEY_END								NULL
#define		MOFKEY_DOWN								20
#define		MOFKEY_NEXT								NULL
#define		MOFKEY_INSERT							NULL
#define		MOFKEY_DELETE							67
#define		MOFKEY_LWIN								NULL
#define		MOFKEY_RWIN								NULL
#define		MOFKEY_APPS								NULL
#define		MOFKEY_POWER							26
#define		MOFKEY_SLEEP							NULL
#define		MOFKEY_WAKE								NULL
#define		MOFKEY_WEBSEARCH						NULL
#define		MOFKEY_WEBFAVORITES						NULL
#define		MOFKEY_WEBREFRESH						NULL
#define		MOFKEY_WEBSTOP							NULL
#define		MOFKEY_WEBFORWARD						NULL
#define		MOFKEY_WEBBACK							NULL
#define		MOFKEY_MYCOMPUTER						NULL
#define		MOFKEY_MAIL								NULL
#define		MOFKEY_MEDIASELECT						NULL
#define		MOFKEY_BACKSPACE      					NULL
#define		MOFKEY_NUMPADSTAR     					NULL
#define		MOFKEY_LALT           					NULL
#define		MOFKEY_CAPSLOCK       					NULL
#define		MOFKEY_NUMPADMINUS    					NULL
#define		MOFKEY_NUMPADPLUS     					NULL
#define		MOFKEY_NUMPADPERIOD   					NULL
#define		MOFKEY_NUMPADSLASH    					NULL
#define		MOFKEY_RALT           					NULL
#define		MOFKEY_UPARROW        					NULL
#define		MOFKEY_PGUP           					NULL
#define		MOFKEY_LEFTARROW      					NULL
#define		MOFKEY_RIGHTARROW     					NULL
#define		MOFKEY_DOWNARROW      					NULL
#define		MOFKEY_PGDN           					NULL
#define		MOFKEY_CIRCUMFLEX						NULL

#endif

namespace Mof {

}

#endif

//[EOF]