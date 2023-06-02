/*************************************************************************//*!
					
					@file	ShaderEffect_DownScale.h
					@brief	汎用縮小シェーダークラス。

															@author	CDW
															@date	2015.05.18
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_DOWNSCALE__H__

#define		__SHADEREFFECT_DOWNSCALE__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	汎用縮小シェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_DownScale : public CShaderEffect_2DBase {
	public:
		/*******************************//*!
		@brief	縮小時のサンプリングタイプの列挙

		@author	CDW
		*//********************************/
		enum SampleType{
			SAMPLE_2X2,
			SAMPLE_3X3LUM,

			SAMPLE_MAX,
		};
		SampleType m_SampleType;
	protected:
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create2x2();
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create3x3Lum();
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		SampleType		サンプリングタイプ

				@return			None
		*//**************************************************************************/
		CShaderEffect_DownScale(SampleType eSampleType);
		
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_DownScale,MOF_SHADEREFFECTDOWNSCALECLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_DownScale*			LPShaderEffect_DownScale;

#include	"ShaderEffect_DownScale.inl"

}

#endif

//[EOF]