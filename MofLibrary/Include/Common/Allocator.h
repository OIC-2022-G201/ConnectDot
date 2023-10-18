/*************************************************************************//*!
					
					@file	Allocator.h
					@brief	メモリの確保関連の処理を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ALLOCATOR__H__

#define		__ALLOCATOR__H__

//INCLUDE
#include	"MofBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メモリ確保クラス

			メモリ確保用クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CAllocator : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			メモリ確保
				@param[in]		Size		確保サイズ
				@param[in]		Ali			アライメント

				@return			確保したメモリアドレス
								NULLの場合確保失敗
		*//**************************************************************************/
		static LPMofVoid Alloc(size_t Size,MofU32 Ali);
		/*************************************************************************//*!
				@brief			メモリ解放
				@param[in]		ptr			解放アドレス
				
				@return			TRUE		正常に解放された<br>
								FALSE		解放の失敗、引数の解放アドレスがNULLの場合などに発生する
		*//**************************************************************************/
		static MofBool Free(LPMofVoid ptr);
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CAllocator,MOF_ALLOCATORCLASS_ID);
	};
}

//----------------------------------
////解放マクロ
//----------------------------------
#ifndef		__MOFDEFAULTRELEASEMACRO__
#define		__MOFDEFAULTRELEASEMACRO__
#define		MOF_ALLOCATOR(Size,Str)					Mof::CAllocator::Alloc(Size,16);
#define		MOF_ALIGND_ALLOCATOR(Size,Ali,Str)		Mof::CAllocator::Alloc(Size,Ali);
#define		MOF_SAFE_RELEASE(x)						if(x){x->Release(); x = NULL;}
#define		MOF_SAFE_DESTROY(x)						if(x){x->Destroy(); x = NULL;}
#define		MOF_SAFE_FREE(ptr,Str)					Mof::CAllocator::Free(ptr); ptr = NULL;
#define		MOF_SAFE_DELETE(x)						if(x){delete (x); (x) = NULL;}
#define		MOF_SAFE_DELETE_ARRAY(x)				if(x){delete[] (x); (x) = NULL;}
#endif		//#ifndef	__MOFDEFAULTRELEASEMACRO__

//INLINE INCLUDE
#include	"Allocator.inl"

#endif

//[EOF]