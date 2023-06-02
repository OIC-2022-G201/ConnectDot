/*************************************************************************//*!
					
					@file	GLShaderBind_DepthOutput.h
					@brief	深度出力シェーダーバインド。<br>
							深度出力シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.30
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_DEPTHOUTPUT__H__

#define		__GLSHADERBIND_DEPTHOUTPUT__H__

//INCLUDE
#include	"GLShaderBind_3DPrimitiveBase.h"

namespace Mof {

	/*******************************//*!
	@brief	深度出力シェーダーバインド。

			深度出力シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_DepthOutput : public CShaderBind_3DPrimitiveBase {
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
		MOF_LIBRARYCLASS(CGLShaderBind_DepthOutput,MOF_GLSHADERBINDDEPTHOUTPUTCLASS_ID);
	};
	
	#include	"GLShaderBind_DepthOutput.inl"

	//置き換え
	typedef CGLShaderBind_DepthOutput		CShaderBind_DepthOutput;
	typedef CShaderBind_DepthOutput*		LPShaderBind_DepthOutput;
}

#endif

//[EOF]
