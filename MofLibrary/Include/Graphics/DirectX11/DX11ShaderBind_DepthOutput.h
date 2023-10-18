/*************************************************************************//*!
					
					@file	DX11ShaderBind_DepthOutput.h
					@brief	深度出力シェーダーバインド。<br>
							深度出力シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.05.25
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_DEPTHOUTPUT__H__

#define		__DX11SHADERBIND_DEPTHOUTPUT__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_3DPrimitiveBase.h"

namespace Mof {

	/*******************************//*!
	@brief	深度出力シェーダーバインド。

			深度出力シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_DepthOutput : public CShaderBind_3DPrimitiveBase {
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_DepthOutput,MOF_DX11SHADERBINDDEPTHOUTPUTCLASS_ID);
	};
	
	#include	"DX11ShaderBind_DepthOutput.inl"

	//置き換え
	typedef CDX11ShaderBind_DepthOutput		CShaderBind_DepthOutput;
	typedef CShaderBind_DepthOutput*		LPShaderBind_DepthOutput;
}

#endif

//[EOF]