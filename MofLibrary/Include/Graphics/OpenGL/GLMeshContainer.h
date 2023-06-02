/*************************************************************************//*!
					
					@file	GLMeshContainer.h
					@brief	OpenGL���b�V���R���e�i�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLMESHCONTAINER__H__

#define		__GLMESHCONTAINER__H__

//INCLUDE
#include	"../MeshContainerBase.h"
#include	"GLMesh.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V�����N���X

			���b�V�����N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLMeshContainer : public CMeshContainerBase {
	private:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLMeshContainer();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param			pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CGLMeshContainer(const CGLMeshContainer& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLMeshContainer();
		
		/*************************************************************************//*!
				@brief			���b�V���̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[���b�V��<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual IMeshContainer* CreateCopyObject(void) const;
				
		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLMeshContainer,MOF_GLMESHCONTAINERCLASS_ID);
	};

	#include	"GLMeshContainer.inl"
	
	//�u������
	typedef CGLMeshContainer		CMeshContainer;
}

#endif	//__GLMESH__H__

//[EOF]
