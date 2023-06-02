/*************************************************************************//*!
					
					@file	ShaderPass.h
					@brief	シェーダーパス基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERPASS__H__

#define		__SHADERPASS__H__

//INCLUDE
#include	"Texture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	シェーダーパスインターフェイス

			シェーダーのパス設定を行うためのインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShaderPass : public IMofNamedObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			シェーダーパスの開始
				@param[in]		Flag		適用フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Begin(MofU32 Flag) = 0;
		/*************************************************************************//*!
				@brief			シェーダーパスの終了
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool End(void) = 0;
	};

	//ポインタ置き換え
	typedef IShaderPass*		LPShaderPass;
	typedef CDynamicArray< LPShaderPass > CShaderPassArray,*LPShaderPassArray;
}

#endif

//[EOF]