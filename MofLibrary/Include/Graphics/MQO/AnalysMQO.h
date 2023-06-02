/*************************************************************************//*!
					
					@file	AnalysMQO.h
					@brief	MQOファイルの解析を行うクラス。

															@author	CDW
															@date	2015.12.14
*//**************************************************************************/

//ONCE
#ifndef		__ANALYSMQOFILE__H__

#define		__ANALYSMQOFILE__H__

//INCLUDE
#include	"../../Common/ReadFile.h"
#include	"MQOModel.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MQOファイル解析クラス

			MQOファイルの解析を行うためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CAnalysMQO : public CReadTextFile {
	protected:
		/*************************************************************************//*!
				@brief			チャンクをスキップする
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool SkipChunk(void);
		/*************************************************************************//*!
				@brief			マテリアルの解析を行う
				@param[out]		pMaterials	マテリアル配列
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysMaterial(LPMOFMQOMATERIALARRAY pMaterials);
		/*************************************************************************//*!
				@brief			オブジェクトの解析を行う
				@param[out]		pObj		オブジェクト
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysObject(LPMOFMQOOBJECT pObj);
		/*************************************************************************//*!
				@brief			頂点の解析を行う
				@param[out]		pVertices	頂点配列を出力するポインタへの参照
				@param[out]		Count		頂点数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysVertex(Vector3*& pVertices,MofU32& Count);
		/*************************************************************************//*!
				@brief			面の解析を行う
				@param[out]		pFaces	面配列を出力するポインタへの参照
				@param[out]		Count		面数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AnalysFaces(LPMOFMQOFACE& pFaces,MofU32& Count);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CAnalysMQO();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAnalysMQO();
		/*************************************************************************//*!
				@brief			ファイルを開いて解析を行う
				@param[in]		pName		ファイル名
				@param[out]		pModel		出力モデル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Analys(const LPMofChar pName,LPMQOModel pModel);
		
		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CAnalysMQO,MOF_ANALYSMQOCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"AnalysMQO.inl"

}

#endif	//__ANALYSMQOFILE__H__

//[EOF]