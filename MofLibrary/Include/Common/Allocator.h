/*************************************************************************//*!
					
					@file	Allocator.h
					@brief	�������̊m�ۊ֘A�̏������s���N���X�B

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
	@brief	�������m�ۃN���X

			�������m�ۗp�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CAllocator : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�������m��
				@param[in]		Size		�m�ۃT�C�Y
				@param[in]		Ali			�A���C�����g

				@return			�m�ۂ����������A�h���X
								NULL�̏ꍇ�m�ێ��s
		*//**************************************************************************/
		static LPMofVoid Alloc(size_t Size,MofU32 Ali);
		/*************************************************************************//*!
				@brief			���������
				@param[in]		ptr			����A�h���X
				
				@return			TRUE		����ɉ�����ꂽ<br>
								FALSE		����̎��s�A�����̉���A�h���X��NULL�̏ꍇ�Ȃǂɔ�������
		*//**************************************************************************/
		static MofBool Free(LPMofVoid ptr);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS(CAllocator,MOF_ALLOCATORCLASS_ID);
	};
}

//----------------------------------
////����}�N��
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