/*************************************************************************//*!
					
					@file	GLGeometry.h
					@brief	OpenGL�W�I���g���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLGEOMETRY__H__

#define		__GLGEOMETRY__H__

//INCLUDE
#include	"../GeometryBase.h"
#include	"GLVertexBuffer.h"
#include	"GLIndexBuffer.h"
#include	"GLMaterial.h"

namespace Mof {
	
	/*******************************//*!
	@brief	OpenGL�W�I���g���N���X

			OpenGL�W�I���g���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLGeometry : public CGeometryBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLGeometry();
		/*************************************************************************//*!
				@brief			�o�b�t�@�w��R���X�g���N�^
				@param[in]		pName		���O
				@param[in]		Topology	�`�����
				@param[in]		pVBuff		���_�o�b�t�@
				@param[in]		pIBuff		�C���f�b�N�X�o�b�t�@
				@param[in]		pMaterial	�}�e���A��

				@return			None
		*//**************************************************************************/
		CGLGeometry(LPCMofChar pName,PrimitiveTopology Topology,LPVertexBuffer pVBuff,LPIndexBuffer pIBuff,LPMaterial pMaterial);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param			pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CGLGeometry(const CGLGeometry& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLGeometry();
		
		/*************************************************************************//*!
				@brief			���b�V���̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[���b�V��<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual IGeometry* CreateCopyObject(void) const;
		
		/*************************************************************************//*!
				@brief			��{�`��<br>
								�o�b�t�@�̐ݒ�ƁA�`��̃R�[���݂̂��s���B<br>
								�}�e���A���̐ݒ�ȂǁA�V�F�[�_�[�̐ݒ�͌Ăяo���O�ɍs���Ă������ƁB
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(void);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		
		
		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLGeometry,MOF_GLGEOMETRYCLASS_ID);
	};

	#include	"GLGeometry.inl"
	
	//�u������
	typedef CGLGeometry		CGeometry;
}

#endif

//[EOF]
