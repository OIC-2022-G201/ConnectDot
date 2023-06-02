/*************************************************************************//*!
					
					@file	Mof.h
					@brief	MOF���C�u�����ꊇ�C���N���[�h�w�b�_�[<br>
							���C�u�����ɕK�v�Ȋ֘A�w�b�_�[�̈ꊇ�C���N���[�h���s���B<br>
							���C�u�����̕W���@�\�𗘗p����ꍇ���̃w�b�_�[���C���N���[�h���邱�ƁB

															@author	CDW
															@date	2014.05.14

	\mainpage

	\section ���߂�
	���̃h�L�������g��OIC�w���ŃQ�[���J���Ɏg�p���Ă���<br>
	Mof���C�u�����̃��t�@�����X�ł��B<br>

	\section ���C�u�����̍\��
	�{���C�u�����͉��L�̃t�H���_�\���Ŋe�@�\��񋟂��܂��B<br>
	- Collision<br>
						�����蔻��ɗ��p����`��p�̍\���̂�N���X�Q<br>
	- Common<br>
						������E���I�z��E�X���b�h�Ȃǋ��ʂ̔ėp�������x�����邽�߂̃N���X�Q<br>
	- Framework<br>
						�A�v���P�[�V�����̋K��̗����E�C���h�E�̐����E�Ǘ��������Ȃ����߂̃N���X�Q<br>
	- Graphics<br>
						�`��֘A�̏����������Ȃ����߂̃N���X�Q<br>
						�N���X�v���b�g�t�H�[���ł̊J���p�ɉ��L��2��ނ̎������܂�<br>
						+ Windows���p�FDirectX11<br>
						+ Android���p�FOpenGL<br>
	- Input<br>
						�L�[�{�[�h�E�}�E�X�E�^�b�`�p�l���E�Q�[���p�b�h�̓��͏����������Ȃ����߂̃N���X�Q<br>
	- Math<br>
						Vector��Matrix�ȂǎZ�p�֘A�̍\���̂�N���X�Q<br>
	- Movie<br>
						���揈���������Ȃ����߂̃N���X�Q<br>
	- Network<br>
						�l�b�g���[�N�Q�[���쐬�p�̒ʐM�x���p�N���X�Q<br>
	- Sound<br>
						�T�E���h�֘A�̏����������Ȃ����߂̃N���X�Q<br>
						�N���X�v���b�g�t�H�[���ł̊J���p�ɉ��L��2��ނ̎������܂�<br>
						+ Windows���p�FXAudio2<br>
						+ Android���p�FOpenSL<br>
	- Utilities<br>
						Graphics���̊e�����̊֐���static�ň�����悤�ɂ����ėp�A�N�Z�X�N���X�Q<br>
*//**************************************************************************/

//ONCE
#ifndef		__MOF__H__

#define		__MOF__H__

//DEFINE
//------------------------------------------------------------
//!���C�u�����̃o�[�W����
//		�E2014/10		���C�u�����̂݊�{�@�\�ƃT���v���쐬
//						0x00000001
//		�E2015/01		2D���ȏ��p�̊e��Ή��ǉ�
//						0x00000002
//		�E2016/01		3D���ȏ��p�̊e��Ή��ǉ�
//						0x00000003
//		�E2017/08/29	�a�c�搶�ɂ��o�[�W�����}�����N�G�X�g
//						0x00000004
//		�E2017/11/01	SpriteStudio�ł̃G�t�F�N�g�iSSE�j�ɑΉ�
//						���̑��ׂ��ȃo�O�C��
//						0x00000005
//		�E2018/05/06	�ׂ��ȃo�O�C��
//						0x00000006
//		�E2018/08/23	FBX�ǂݍ��ݎd�l�̕ύX
//						�P�U�{�܂ł̃E�F�C�g����t���ɑΉ�
//						0x00000007
//		�E2019/03/11	VS2017�Ή��ǉ�
//						�ׂ��ȃo�O�C��
//						0x00000008
//		�E2019/12/11	_ITERATOR_DEBUG_LEVEL=0�̎w��̒ǉ�
//						�ׂ��ȃo�O�C��
//						0x00000009
//		�E2020/09/30	_ITERATOR_DEBUG_LEVEL=0�̎w��̎����
//						�������̃��\�b�h��const�w���ǉ�
//						�ׂ��ȃo�O�C��
//						0x00000010
//------------------------------------------------------------
#define		MOFLIB_VERSION					0x00000010
#define		MOFLIB_MAJORVERSION				((MOFLIB_VERSION & 0xFFFF0000) >> 16)
#define		MOFLIB_MINORVERSION				((MOFLIB_VERSION & 0xFFFF))

//INCLUDE

//���w�b�_�[�̃C���N���[�h
//�ȍ~�̃C���N���[�h�������Ƃɂ���
#include	"Common/Platform.h"

//�e��R���o�[�^���p�t���O�ϊ��𗘗p���Ȃ��A�v���ł̓R�����g�A�E�g����
#define		MOFLIB_CONVERT

//�O�����C�u�������K�{�̃R���o�[�^�[
//#define		MOFLIB_CONVERTFBX				//FBX(�v���W�F�N�g��FBX�̃C���N���[�h�p�X�ǉ����K�v)
//#define		MOFLIB_CONVERTSS				//SpriteStudio

//��b�t���[�����[�N�̃C���N���[�h
#ifdef		MOFLIB_WINDOWS

//���C�u�����̃����N�A���C�u�����R���p�C���̏ꍇ�͖��������
#ifndef		MOFLIB_COMPILE

#if defined(DEBUG) || defined(_DEBUG)

#if _MSC_VER >= 1910

#pragma comment (lib,"MofLibrary2017_d.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"MofLibrary2015_d.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"MofLibrary2013_d.lib")

#else

#pragma comment (lib,"MofLibrary_d.lib")

#endif // _MSC_VER == 1800

#else

#if _MSC_VER >= 1910

#pragma comment (lib,"MofLibrary2017.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"MofLibrary2015.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"MofLibrary2013.lib")

#else

#pragma comment (lib,"MofLibrary.lib")

#endif // _MSC_VER == 1800

#endif

#endif

//�e��R���o�[�^�i�ϊ��𗘗p����ꍇ�̂݃C���N���[�h�j
#ifdef		MOFLIB_CONVERT

#ifdef		MOFLIB_CONVERTFBX

#include	"Graphics/FBX/fbxsdk.h"
#include	"Graphics/FBX/ConvertFBX.h"

#endif		// MOFLIB_CONVERTFBX

#ifdef		MOFLIB_CONVERTSS

#include	"Graphics/SpriteStudio/ssloader.h"
#include	"Graphics/SpriteStudio/ConvertSpriteStudio.h"

#endif		// MOFLIB_CONVERTSS

#include	"Graphics/MQO/ConvertMQO.h"
#include	"Graphics/PMD/ConvertPMD.h"
#include	"Graphics/PMD/ConvertPMX.h"
#include	"Graphics/PMD/ConvertVMD.h"
#include	"Graphics/XFile/ConvertX.h"
#include	"Graphics/PhotoShop/ConvertPsd.h"
#include	"Graphics/mdl/ConvertMDL.h"

#endif

#include	"Common/WinSingleGameApplication.h"
#include	"Common/WinMultiGameApplication.h"
#include	"Graphics/GraphicsPlatform.h"
#include	"Sound/SoundPlatform.h"

#ifdef		MOFLIB_DIRECTX12

#include	"Framework/Windows/DirectX12/DX12GameFramework.h"
#include	"Input/XInput/XInputGamePad.h"
#include	"Movie/DirectShow/DShowMovie.h"

#endif

#ifdef		MOFLIB_DIRECTX11

#include	"Framework/Windows/DirectX11/DX11GameFramework.h"
#include	"Input/XInput/XInputGamePad.h"
#include	"Movie/DirectShow/DShowMovie.h"

#endif

#ifdef		MOFLIB_DIRECTX9

#endif

#endif

#ifdef		MOFLIB_ANDROID

#include	"Common/AndroidSingleGameApplication.h"
#include	"Graphics/GraphicsPlatform.h"
#include	"Sound/SoundPlatform.h"

#include	"Framework/Android/AndroidJNIGameFramework.h"

#endif

//�ėp�X�^�e�B�b�N�N���X�̃C���N���[�h
#include	"Utilities/Utilities.h"
#include	"Utilities/GraphicsUtilities.h"
#include	"Utilities/InputUtilities.h"
#include	"Utilities/SoundUtilities.h"
#include	"Utilities/CollisionUtilities.h"

//���C�u�������ւ̃A�N�Z�X���ȒP�ɍs�����߂�namespace�����グ(�w���p�ȈՃA�N�Z�X�̂��߂̏��u�A�����͂��Ȃ�)
using namespace Mof;

//�w���p�̊�b�N���X�ȈՃA�N�Z�X�p(�X�^�e�B�b�N�N���X����擾����)
#define		g_pFramework					CUtilities::GetFramework()				//!<���t���[�����[�N�擾�p�}�N��
#define		g_pMainWindow					g_pFramework->GetWindow()				//!<���C���E�C���h�E�擾�p�}�N��
#define		g_pGraphics						CGraphicsUtilities::GetGraphics()		//!<���O���t�B�b�N�X�擾�p�}�N��
#define		g_pCommandProxy					CGraphicsUtilities::GetCommandProxy()	//!<�}���`�X���b�h�p�R�}���h�o�b�t�@�擾�p�}�N��
#define		g_pInput						CInputUtilities::GetInput()				//!<���C���v�b�g�擾�p�}�N��
#define		g_pSound						CSoundUtilities::GetSound()				//!<���T�E���h�擾�p�}�N��

#endif

//[EOF]