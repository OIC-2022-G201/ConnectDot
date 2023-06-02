/*************************************************************************//*!
					
					@file	GLShaderBind_DepthOutputSkinned.h
					@brief	深度出力シェーダーバインド。<br>
							深度出力シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.30
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_DEPTHOUTPUTSKINNED__H__

#define		__GLSHADERBIND_DEPTHOUTPUTSKINNED__H__

//INCLUDE
#include	"GLShaderBind_SkinGeometryBase.h"

namespace Mof {

	/*******************************//*!
	@brief	深度出力シェーダーバインド。

			深度出力シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_DepthOutputSkinned : public CShaderBind_SkinGeometryBase {
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
		MOF_LIBRARYCLASS(CGLShaderBind_DepthOutputSkinned,MOF_GLSHADERBINDDEPTHOUTPUTSKINNEDCLASS_ID);
	};
	
	#include	"GLShaderBind_DepthOutputSkinned.inl"

	//置き換え
	typedef CGLShaderBind_DepthOutputSkinned		CShaderBind_DepthOutputSkinned;
	typedef CShaderBind_DepthOutputSkinned*		LPShaderBind_DepthOutputSkinned;
}

#endif

//[EOF]
