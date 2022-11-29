/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

// INCLUDE
#include "GameApp.h"

#include <array>
#include <fstream>


#include "TileMap.h"
#include "BinaryArchive.h"
#include "VectorFrozen.h"
#include "StringFrozen.h"
struct Test {
  std::vector<int> b{};
  std::string str{};
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(b, str);
  }
};
struct Test2 {
  std::vector<int> b{};
  std::string str{};
  Test t;
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(b, str,t);
  }
};

struct Test3 {
  std::vector<int> b{};
  std::string str{};
};
  struct Test4 {
  std::vector<int> b{};
  std::string str{};
  Test3 t3;
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(b, str, t3);
  }
};
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void) {
  CUtilities::SetCurrentDirectory("Resource");
  // CGraphicsUtilities::SetCamera(&camera_);
  // g_pGraphics->SetScreenMode(false);
  g_pGraphics->SetCullMode(CULLMODE_NONE);
  game_.Initialize();
  return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Update(void) {
  //�L�[�̍X�V
  g_pInput->RefreshKey();
  game_.Update();
  return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void) {
  //�`��J�n
  g_pGraphics->RenderStart();
  //��ʂ̃N���A
  g_pGraphics->ClearTarget(0.2f, 0.2f, 0.2f, 0.0f, 1.0f, 0);
  game_.Render();
  //�`��̏I��
  g_pGraphics->RenderEnd();
  return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̉��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Release(void) {
  game_.Shutdown();
  return TRUE;
}