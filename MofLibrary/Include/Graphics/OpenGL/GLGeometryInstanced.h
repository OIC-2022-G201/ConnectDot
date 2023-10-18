/*************************************************************************//*!
					
					@file	GLGeometryInstanced.h
					@brief	OpenGL�W�I���g���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLGEOMETRYINSTANCED__H__

#define		__GLGEOMETRYINSTANCED__H__

//INCLUDE
#include	"../GeometryInstancedBase.h"
#include	"GLGeometry.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11�W�I���g���N���X

			DirectX11�W�I���g���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLGeometryInstanced : public CGeometryInstancedBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLGeometryInstanced();
		/*************************************************************************//*!
				@brief			�o�b�t�@�w��R���X�g���N�^
				@param[in]		pName		���O
				@param[in]		Topology	�`�����
				@param[in]		pVBuff		���_�o�b�t�@
				@param[in]		pIBuff		�C���f�b�N�X�o�b�t�@
				@param[in]		pMaterial	�}�e���A��
				@param[in]		InstanceCount�C���X�^���X�ő吔

				@return			None
		*//**************************************************************************/
		CGLGeometryInstanced(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, MofU32 InstanceCount);
		/*************************************************************************//*!
				@brief			�o�b�t�@�w��R���X�g���N�^
				@param[in]		pName		���O
				@param[in]		Topology	�`�����
				@param[in]		pVBuff		���_�o�b�t�@
				@param[in]		pIBuff		�C���f�b�N�X�o�b�t�@
				@param[in]		pMaterial	�}�e���A��
				@param[in]		pInstanceBuff�C���X�^���X�o�b�t�@

				@return			None
		*//**************************************************************************/
		CGLGeometryInstanced(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��
				@param[in]		InstanceCount�C���X�^���X�ő吔

				@return			None
		*//**************************************************************************/
		CGLGeometryInstanced(const CGLGeometry& pObj, MofU32 InstanceCount);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��
				@param[in]		pInstanceBuff�C���X�^���X�o�b�t�@

				@return			None
		*//**************************************************************************/
		CGLGeometryInstanced(const CGeometryBase& pObj, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CGLGeometryInstanced(const CGLGeometryInstanced& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLGeometryInstanced();
		
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
		MOF_LIBRARYCLASS(CGLGeometryInstanced, MOF_GLGEOMETRYINSTANCEDCLASS_ID);
	};

	#include	"GLGeometryInstanced.inl"
	
	//�u������
	typedef CGLGeometryInstanced		CGeometryInstanced;
}

#endif

//[EOF]