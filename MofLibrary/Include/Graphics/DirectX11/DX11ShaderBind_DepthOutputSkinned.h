/*************************************************************************//*!
					
					@file	DX11ShaderBind_DepthOutputSkinned.h
					@brief	深度出力シェーダーバインド。<br>
							深度出力シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.05.25
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_DEPTHOUTPUTSKINNED__H__

#define		__DX11SHADERBIND_DEPTHOUTPUTSKINNED__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_SkinGeometryBase.h"

namespace Mof {

	/*******************************//*!
	@brief	深度出力シェーダーバインド。

			深度出力シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_DepthOutputSkinned : public CShaderBind_SkinGeometryBase {
	public:
	
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			描画用カメラを設定する
				@param[in]		pc				カメラ

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(LPCamera pc);

		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11ShaderBind_DepthOutputSkinned,MOF_DX11SHADERBINDDEPTHOUTPUTSKINNEDCLASS_ID);
	};
	
	#include	"DX11ShaderBind_DepthOutputSkinned.inl"

	//置き換え
	typedef CDX11ShaderBind_DepthOutputSkinned		CShaderBind_DepthOutputSkinned;
	typedef CShaderBind_DepthOutputSkinned*		LPShaderBind_DepthOutputSkinned;
}

#endif

//[EOF]