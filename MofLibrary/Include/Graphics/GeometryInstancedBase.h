/*************************************************************************//*!
					
					@file	GeometryInstancedBase.h
					@brief	�W�I���g���C���X�^���X���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GEOMETRYINSTANCEDBASE__H__

#define		__GEOMETRYINSTANCEDBASE__H__

//INCLUDE
#include	"GeometryBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�W�I���g�����N���X

			�W�I���g�����ƂȂ�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGeometryInstancedBase : public CGeometryBase {
	protected:
		/*******************//*!
		�`��C���X�^���X�̐�
		*//********************/
		MofU32						m_RenderInstanceCount;
		/*******************//*!
		���_�o�b�t�@
		*//********************/
		LPVertexBuffer				m_pInstancedBuffer;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase();
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
		CGeometryInstancedBase(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, MofU32 InstanceCount);
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
		CGeometryInstancedBase(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�W�I���g��
				@param[in]		InstanceCount	�C���X�^���X�ő吔

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase(const CGeometryBase& pObj,MofU32 InstanceCount);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�W�I���g��
				@param[in]		pInstanceBuff	�C���X�^���X�o�b�t�@

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase(const CGeometryBase& pObj, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CGeometryInstancedBase(const CGeometryInstancedBase& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGeometryInstancedBase();
		
		/*************************************************************************//*!
				@brief			�o�b�t�@�̍쐬
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CreateBuffer(void);
		
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�C���X�^���X�p�o�b�t�@�ݒ�
				@param[in]		pBuff			�ݒ�o�b�t�@
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetInstancedBuffer(LPVertexBuffer pBuff);
		/*************************************************************************//*!
				@brief			�C���X�^���X�p�o�b�t�@�ݒ�
				@param[in]		mat				�s��
				@param[in]		cnt				�s��
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetInstancedMatrix(Matrix44* mat,MofU32 cnt);
		/*************************************************************************//*!
				@brief			�C���X�^���X�p�o�b�t�@�ݒ�
				@param[in]		pBuff			�ݒ�o�b�t�@
				@param[in]		Size			�ݒ�T�C�Y
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetInstancedBuffer(LPMofVoid pBuff, MofU32 Size);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�擾
				@param			None

				@return			���_�o�b�t�@
		*//**************************************************************************/
		virtual LPVertexBuffer GetVertexBuffer(void);
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�擾
				@param[in,out]	pOut			���_�o�b�t�@�z��<br>
												�o�͗p�̃|�C���^��NULL�Ȃ�i�[����Ȃ��B
				@param[in,out]	cnt				���_�o�b�t�@�̐�<br>
												���s���ɂ�pOut�̊i�[�ő吔���w�肷��B

				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool GetVertexBuffer(LPVertexBuffer* pOut,MofU32& cnt);
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�t���O�擾
				@param			None

				@return			���_�o�b�t�@�t���O
		*//**************************************************************************/
		virtual VertexFlag GetVertexFlag(void);
		/*************************************************************************//*!
				@brief			�C���X�^���X�p�o�b�t�@�擾
				@param			None

				@return			�C���X�^���X�p�o�b�t�@
		*//**************************************************************************/
		virtual LPVertexBuffer GetInstancedBuffer(void);
	};

	#include	"GeometryInstancedBase.inl"

	//�|�C���^�u������
	typedef CGeometryInstancedBase*		LPGeometryInstanced;
}

#endif

//[EOF]