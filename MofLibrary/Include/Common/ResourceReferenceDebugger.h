/*************************************************************************//*!
					
					@file	ResourceReferenceDebugger.h
					@brief	���\�[�X����Ď��N���X

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
	@brief	���\�[�X����Ď��N���X

			���\�[�X����Ď��N���X

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CResourceReferenceDebugger{
	protected:
		/*******************************//*!
		@brief	���\�[�X���ƎQ�ƃJ�E���^�̃y�A

		@author	CDW
		*//********************************/
		struct RESOURCE_INFO{
			CString	Name;
			MofU32	RefCount;
		};
		/*******************************//*!
		@brief	�Q�ƃI�u�W�F�N�g

		@author	CDW
		*//********************************/
		struct REFERENCE_INFO{
			LPCMofNamedObject	pKey;
			RESOURCE_INFO*		pResource;
		};
		/*******************//*!
		���\�[�X�ꗗ
		*//********************/
		static CDynamicArray<RESOURCE_INFO*>	s_ResourceList;
		/*******************//*!
		�Q�ƈꗗ
		*//********************/
		static CDynamicArray<REFERENCE_INFO>	s_RefList;
	public:
		/*************************************************************************//*!
				@brief			�V�������\�[�X��o�^���ĎQ�Ƃ��쐬
				@param[in]		pRefKey			�Q�Ƃւ̃L�[�ƂȂ�I�u�W�F�N�g�̃|�C���^
				@param[in]		pResourceName	���\�[�X�̖��O

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool CreateRef(LPCMofNamedObject pRefKey,LPCMofChar pResourceName);
		/*************************************************************************//*!
				@brief			�Q�Ƃ��R�s�[
				@param[in]		pRefKey			�Q�Ƃւ̃L�[�ƂȂ�I�u�W�F�N�g�̃|�C���^
				@param[in]		pSrcKey			�R�s�[���̎Q�Ƃւ̃L�[�ƂȂ�I�u�W�F�N�g�̃|�C���^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool CopyRef(LPCMofNamedObject pRefKey,LPCMofNamedObject pSrcKey);
		/*************************************************************************//*!
				@brief			�Q�Ƃ��폜
				@param[in]		pRefKey			�Q�Ƃւ̃L�[�ƂȂ�I�u�W�F�N�g�̃|�C���^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool DeleteRef(LPCMofNamedObject pRefKey);
		/*************************************************************************//*!
				@brief			���\�[�X���X�g�ƑS�Ă̎Q�Ƃ��폜
				@param			None

				@return			None
		*//**************************************************************************/
		static void Clear();
		/*************************************************************************//*!
				@brief			�f�o�b�O���O�ɖ��J���̃��\�[�X�ꗗ���o��
				@param			None

				@return			None
		*//**************************************************************************/
		static void PrintResouceList();

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���J���̃��\�[�X�����擾
				@param			None

				@return			���J���̃��\�[�X��
		*//**************************************************************************/
		static MofU32 GetResourceCount();
		/*************************************************************************//*!
				@brief			���\�[�X�����擾
				@param[in]		index			�C���f�b�N�X

				@return			���\�[�X��
		*//**************************************************************************/
		static const CString& GetResouceName(MofU32 index);

	protected:
		/*************************************************************************//*!
				@brief			�L�[�ƂȂ�|�C���^����Q�ƃI�u�W�F�N�g������
				@param			None

				@return			�Q�ƃI�u�W�F�N�g�̃C���f�b�N�X<br>
								������Ȃ����-1��Ԃ��B
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
