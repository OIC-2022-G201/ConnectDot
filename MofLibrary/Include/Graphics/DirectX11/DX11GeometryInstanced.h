/*************************************************************************//*!
					
					@file	DX11GeometryInstanced.h
					@brief	DirectX11�W�I���g���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11GEOMETRYINSTANCED__H__

#define		__DX11GEOMETRYINSTANCED__H__

//INCLUDE
#include	"../GeometryInstancedBase.h"
#include	"DX11Geometry.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11�W�I���g���N���X

			DirectX11�W�I���g���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11GeometryInstanced : public CGeometryInstancedBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced();
		/*************************************************************************//*!
				@brief			�o�b�t�@�w��R���X�g���N�^
				@param[in]		pName			���O
				@param[in]		Topology		�`�����
				@param[in]		pVBuff			���_�o�b�t�@
				@param[in]		pIBuff			�C���f�b�N�X�o�b�t�@
				@param[in]		pMaterial		�}�e���A��
				@param[in]		InstanceCount	�C���X�^���X�ő吔

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, MofU32 InstanceCount);
		/*************************************************************************//*!
				@brief			�o�b�t�@�w��R���X�g���N�^
				@param[in]		pName			���O
				@param[in]		Topology		�`�����
				@param[in]		pVBuff			���_�o�b�t�@
				@param[in]		pIBuff			�C���f�b�N�X�o�b�t�@
				@param[in]		pMaterial		�}�e���A��
				@param[in]		pInstanceBuff	�C���X�^���X�o�b�t�@

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�W�I���g��
				@param[in]		InstanceCount	�C���X�^���X�ő吔

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(const CDX11Geometry& pObj, MofU32 InstanceCount);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�W�I���g��
				@param[in]		pInstanceBuff	�C���X�^���X�o�b�t�@

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(const CGeometryBase& pObj, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(const CDX11GeometryInstanced& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11GeometryInstanced();
		
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
		MOF_LIBRARYCLASS(CDX11GeometryInstanced, MOF_DX11GEOMETRYINSTANCEDCLASS_ID);
	};

	#include	"DX11GeometryInstanced.inl"
	
	//�u������
	typedef CDX11GeometryInstanced		CGeometryInstanced;
}

#endif

//[EOF]