/*************************************************************************//*!
					
					@file	ResourceReferenceDebugger.h
					@brief	リソース解放監視クラス

															@author	CDW
															@date	2015.10.02
*//**************************************************************************/

//ONCE
#ifndef		__RESOURCEREFERENCEDEBUGGER__H__

#define		__RESOURCEREFERENCEDEBUGGER__H__

//INCLUDE
#include	"DynamicArray.h"


#if defined(DEBUG) || defined(_DEBUG)

namespace Mof {
	
	/*******************************//*!
	@brief	リソース解放監視クラス

			リソース解放監視クラス

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CResourceReferenceDebugger{
	protected:
		/*******************************//*!
		@brief	リソース名と参照カウンタのペア

		@author	CDW
		*//********************************/
		struct RESOURCE_INFO{
			CString	Name;
			MofU32	RefCount;
		};
		/*******************************//*!
		@brief	参照オブジェクト

		@author	CDW
		*//********************************/
		struct REFERENCE_INFO{
			LPCMofNamedObject	pKey;
			RESOURCE_INFO*		pResource;
		};
		/*******************//*!
		リソース一覧
		*//********************/
		static CDynamicArray<RESOURCE_INFO*>	s_ResourceList;
		/*******************//*!
		参照一覧
		*//********************/
		static CDynamicArray<REFERENCE_INFO>	s_RefList;
	public:
		/*************************************************************************//*!
				@brief			新しいリソースを登録して参照を作成
				@param[in]		pRefKey			参照へのキーとなるオブジェクトのポインタ
				@param[in]		pResourceName	リソースの名前

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		static MofBool CreateRef(LPCMofNamedObject pRefKey,LPCMofChar pResourceName);
		/*************************************************************************//*!
				@brief			参照をコピー
				@param[in]		pRefKey			参照へのキーとなるオブジェクトのポインタ
				@param[in]		pSrcKey			コピー元の参照へのキーとなるオブジェクトのポインタ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		static MofBool CopyRef(LPCMofNamedObject pRefKey,LPCMofNamedObject pSrcKey);
		/*************************************************************************//*!
				@brief			参照を削除
				@param[in]		pRefKey			参照へのキーとなるオブジェクトのポインタ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		static MofBool DeleteRef(LPCMofNamedObject pRefKey);
		/*************************************************************************//*!
				@brief			リソースリストと全ての参照を削除
				@param			None

				@return			None
		*//**************************************************************************/
		static void Clear();
		/*************************************************************************//*!
				@brief			デバッグログに未開放のリソース一覧を出力
				@param			None

				@return			None
		*//**************************************************************************/
		static void PrintResouceList();

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			未開放のリソース数を取得
				@param			None

				@return			未開放のリソース数
		*//**************************************************************************/
		static MofU32 GetResourceCount();
		/*************************************************************************//*!
				@brief			リソース名を取得
				@param[in]		index			インデックス

				@return			リソース名
		*//**************************************************************************/
		static const CString& GetResouceName(MofU32 index);

	protected:
		/*************************************************************************//*!
				@brief			キーとなるポインタから参照オブジェクトを検索
				@param			None

				@return			参照オブジェクトのインデックス<br>
								見つからなければ-1を返す。
		*//**************************************************************************/
		static MofS32 FindRef(LPCMofNamedObject pRefKey);
	};
	
	#include	"ResourceReferenceDebugger.inl"
}

#define MOF_REFMNG_CREATEREF(pRefKey,pResourceName)	(Mof::CResourceReferenceDebugger::CreateRef(pRefKey,pResourceName));
#define MOF_REFMNG_COPYREF(pRefKey,pSrcKey)			(Mof::CResourceReferenceDebugger::CopyRef(pRefKey,pSrcKey));
#define MOF_REFMNG_DELETEREF(pRefKey)				(Mof::CResourceReferenceDebugger::DeleteRef(pRefKey));

#else

#define MOF_REFMNG_CREATEREF(...)
#define MOF_REFMNG_COPYREF(...)
#define MOF_REFMNG_DELETEREF(...)

#endif



#endif	//__REFERENCEMANAGER__H__

//[EOF]
