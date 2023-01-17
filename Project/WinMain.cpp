#include "GameApp.h"
#include "GameWindow.h"
#include "resource1.h"

#ifdef UNICODE
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPTSTR lpCmdLine, int nCmdShow)
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPTSTR lpCmdLine, int nCmdShow)
#endif
{
  //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  Mof::LPFramework pFrame = new Mof::CDX11GameFramework();
  Mof::WINDOWSGAMEFRAMEWORKINITIALIZEINFO Info;
  Info.pApplication = new CGameApp();
  Info.WindowCreateInfo.Width = window::kWidth;
  Info.WindowCreateInfo.Height = window::kHeight;
  Info.WindowCreateInfo.Title = "CONNECT DOT";
  auto icon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
  Info.WindowCreateInfo.hIcon = icon;
  ;
  //Info.GraphicsCreateInfo.bWindowed = false;
  pFrame->Initialize(&Info);
  pFrame->Run();
  MOF_SAFE_DELETE(pFrame);
  return 0;
}