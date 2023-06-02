/*************************************************************************//*!
					
					@file	DX11Geometry.h
					@brief	DirectX11�W�I���g���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11GEOMETRY__H__

#define		__DX11GEOMETRY__H__

//INCLUDE
#include	"../GeometryBase.h"
#include	"DX11VertexBuffer.h"
#include	"DX11IndexBuffer.h"
#include	"DX11Material.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11�W�I���g���N���X

			DirectX11�W�I���g���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Geometry : public CGeometryBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Geometry();
		/*************************************************************************//*!
				@brief			�o�b�t�@�w��R���X�g���N�^
				@param[in]		pName		���O
				@param[in]		Topology	�`�����
				@param[in]		pVBuff		���_�o�b�t�@
				@param[in]		pIBuff		�C���f�b�N�X�o�b�t�@
				@param[in]		pMaterial	�}�e���A��

				@return			None
		*//**************************************************************************/
		CDX11Geometry(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CDX11Geometry(const CDX11Geometry& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Geometry();
		
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
		MOF_LIBRARYCLASS(CDX11Geometry,MOF_DX11GEOMETRYCLASS_ID);
	};

	#include	"DX11Geometry.inl"
	
	//�u������
	typedef CDX11Geometry		CGeometry;
}

#endif

//[EOF]