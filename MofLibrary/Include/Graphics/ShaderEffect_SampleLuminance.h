/*************************************************************************//*!
					
					@file	ShaderEffect_SampleLuminance.h
					@brief	輝度変換シェーダークラス。

															@author	CDW
															@date	2015.05.18
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_SAMPLELUMINANCE__H__

#define		__SHADEREFFECT_SAMPLELUMINANCE__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	輝度変換シェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_SampleLuminance : public CShaderEffect_2DBase {
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
		MOF_LIBRARYCLASS(CShaderEffect_SampleLuminance,MOF_SHADEREFFECTSAMPLELUMINANCECLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_SampleLuminance*			LPShaderEffect_SampleLuminance;

#include	"ShaderEffect_SampleLuminance.inl"

}

#endif

//[EOF]