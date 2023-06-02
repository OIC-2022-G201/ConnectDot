/*************************************************************************//*!
					
					@file	GLShaderTechnique.h
					@brief	OpenGLシェーダーテクニッククラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERTECHNIQUE__H__

#define		__GLSHADERTECHNIQUE__H__

//INCLUDE
#include	"../ShaderTechniqueBase.h"
#include	"GLShaderPass.h"

namespace Mof {
	
	/*******************************//*!
	@brief	OpenGLシェーダーテクニッククラス

			OpenGLでのシェーダーのテクニック設定を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderTechnique : public CShaderTechniqueBase {
	protected:
		/*******************//*!
		シェーダーテクニック
		*//********************/
		ID3GLEffectTechnique*	m_pTechnique;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderTechnique();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pTec		テクニック

				@return			None
		*//**************************************************************************/
		CGLShaderTechnique(ID3GLEffectTechnique* pTec);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param			pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderTechnique(const CGLShaderTechnique& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderTechnique();
		
		/*************************************************************************//*!
				@brief			シェーダーテクニックの開始
				@param[in]		Flag		適用フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Begin(MofU32 Flag);
		/*************************************************************************//*!
				@brief			シェーダーパスの開始
				@param[in]		nPass		パス番号
				@param[in]		Flag		適用フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool BeginPass(MofU32 nPass,MofU32 Flag);
		/*************************************************************************//*!
				@brief			シェーダーテクニックの終了
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool End(void);
		/*************************************************************************//*!
				@brief			シェーダーパスの終了
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool EndPass(void);

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//クラス基本定義
		MOF_LIBRARYCLASS(CGLShaderTechnique,MOF_GLSHADERTECHNIQUECLASS_ID);
	};

	#include	"GLShaderTechnique.inl"
}

#endif

//[EOF]