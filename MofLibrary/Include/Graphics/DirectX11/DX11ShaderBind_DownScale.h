/*************************************************************************//*!
					
					@file	DX11ShaderBind_DownScale.h
					@brief	縮小シェーダーバインド。<br>
							縮小シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.11.05
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_DOWNSCALE__H__

#define		__DX11SHADERBIND_DOWNSCALE__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	縮小シェーダーバインド。

			縮小シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_DownScale : public CShaderBind_SpriteBase {
	public:
		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11ShaderBind_DownScale,MOF_DX11SHADERBINDDOWNSCALECLASS_ID);
	};
	
	#include	"DX11ShaderBind_DownScale.inl"

	//置き換え
	typedef CDX11ShaderBind_DownScale		CShaderBind_DownScale;
	typedef CShaderBind_DownScale*		LPShaderBind_DownScale;
}

#endif

//[EOF]