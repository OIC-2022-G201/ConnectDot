/*************************************************************************//*!
					
					@file	GLMesh.h
					@brief	OpenGL���b�V���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLMESH__H__

#define		__GLMESH__H__

//INCLUDE
#include	"../MeshBase.h"
#include	"GLGeometry.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V�����N���X

			���b�V�����N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLMesh : public CMeshBase {
	private:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLMesh();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param			pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CGLMesh(const CGLMesh& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLMesh();
		
		/*************************************************************************//*!
				@brief			���b�V���̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[���b�V��<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual IMesh* CreateCopyObject(void) const;
				
		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLMesh,MOF_GLMESHCLASS_ID);
	};

	#include	"GLMesh.inl"
	
	//�u������
	typedef CGLMesh		CMesh;
}

#endif	//__GLMESH__H__

//[EOF]
