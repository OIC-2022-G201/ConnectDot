/*************************************************************************//*!
					
					@file	ShaderEffect_DeferredLighting.h
					@brief	遅延ライティングシェーダークラス。

															@author	CDW
															@date	2015.04.27
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_DEFERREDLIGHTING__H__

#define		__SHADEREFFECT_DEFERREDLIGHTING__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	2x2縮小シェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_DeferredLighting : public CShaderEffect_2DBase {
	protected:
	public:
		
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();


		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_DeferredLighting,MOF_SHADEREFFECTDEFERREDLIGHTINGCLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_DeferredLighting*			LPShaderEffect_DeferredLighting;

#include	"ShaderEffect_DeferredLighting.inl"

}

#endif

//[EOF]