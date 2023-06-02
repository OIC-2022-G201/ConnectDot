/*************************************************************************//*!
					
					@file	GeometryBase.h
					@brief	�W�I���g�����N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GEOMETRYBASE__H__

#define		__GEOMETRYBASE__H__

//INCLUDE
#include	"Geometry.h"
#include	"GeometryMorphingBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�W�I���g�����N���X

			�W�I���g�����ƂȂ�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGeometryBase : public IGeometry {
	protected:
		/*******************//*!
		���O
		*//********************/
		CString						m_Name;
		/*******************//*!
		�s��
		*//********************/
		CMatrix44					m_Matrix;
		/*******************//*!
		�`�����
		*//********************/
		PrimitiveTopology			m_Topology;
		/*******************//*!
		���_�o�b�t�@
		*//********************/
		LPVertexBuffer				m_pVertexBuffer;
		/*******************//*!
		�C���f�b�N�X�o�b�t�@
		*//********************/
		LPIndexBuffer				m_pIndexBuffer;
		/*******************//*!
		�}�e���A��
		*//********************/
		LPMaterial					m_pMaterial;
		/*******************//*!
		���[�t�B���O
		*//********************/
		LPGeometryMorphingArray		m_pMorphing;
		/*******************//*!
		�Ή��{�[����
		*//********************/
		LPStringArray				m_pBoneName;
		/*******************//*!
		�����蔻��p�L���b�V��
		*//********************/
		LPGeometryCollisionCache	m_pCollisionCache;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGeometryBase();
		/*************************************************************************//*!
				@brief			�o�b�t�@�w��R���X�g���N�^
				@param[in]		pName		���O
				@param[in]		Topology	�`�����
				@param[in]		pVBuff		���_�o�b�t�@
				@param[in]		pIBuff		�C���f�b�N�X�o�b�t�@
				@param[in]		pMaterial	�}�e���A��

				@return			None
		*//**************************************************************************/
		CGeometryBase(LPCMofChar pName,PrimitiveTopology Topology,LPVertexBuffer pVBuff,LPIndexBuffer pIBuff,LPMaterial pMaterial);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CGeometryBase(const CGeometryBase& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGeometryBase();
		
		/*************************************************************************//*!
				@brief			�o�b�t�@�̍쐬<br>
								�W�I���g�������œo�^����Ă���A���_�o�b�t�@��C���f�b�N�X�o�b�t�@�̐����������Ȃ��B<br>
								�W�I���g���̒��_��C���f�b�N�X�̏���ύX�����ꍇ�Ɏ��s����K�v������B
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CreateBuffer(void);
		
		/*************************************************************************//*!
				@brief			�ő�E�ŏ��v�Z<br>
								�W�I���g���Ɋ܂܂�钸�_�̍ő�ʒu�ƍŏ��ʒu�����߂�B
				@param[out]		minv			�o�͗p�ŏ�
				@param[out]		maxv			�o�͗p�ő�
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateMinMax(Vector3& minv,Vector3& maxv);
		/*************************************************************************//*!
				@brief			�w��{�[�����ɃE�F�C�g������t���Ă���A�ő�E�ŏ����W�v�Z
				@param[in]		pBName			�{�[����
				@param[out]		minv			�o�͗p�ŏ�
				@param[out]		maxv			�o�͗p�ő�
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateMinMax(LPCMofChar pBName, Vector3& minv, Vector3& maxv);

		/*************************************************************************//*!
				@brief			AABB�v�Z<br>
								�W�I���g���Ɋ܂܂�钸�_�̋��E�{�b�N�X�����߂�B
				@param[out]		aabb			�o�͗p�{�b�N�X
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateAABB(BoxAABB& aabb);
		/*************************************************************************//*!
				@brief			�w��{�[�����ɃE�F�C�g������t���Ă���AAABB�v�Z
				@param[in]		pBName			�{�[����
				@param[out]		aabb			�o�͗p�{�b�N�X
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateAABB(LPCMofChar pBName, BoxAABB& aabb);
		/*************************************************************************//*!
				@brief			���E���v�Z
				@param[out]		sph				�o�͗p��
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateSphere(Sphere& sph);
		/*************************************************************************//*!
				@brief			�w��{�[�����ɃE�F�C�g������t���Ă���A���E���v�Z
				@param[in]		pBName			�{�[����
				@param[out]		sph				�o�͗p��
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateSphere(LPCMofChar pBName, Sphere& sph);

		/*************************************************************************//*!
				@brief			��{�`��<br>
								�o�b�t�@�̐ݒ�ƁA�`��̃R�[���݂̂��s���B<br>
								�}�e���A���̐ݒ�ȂǁA�V�F�[�_�[�̐ݒ�͌Ăяo���O�ɍs���Ă������ƁB
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(void) = 0;
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				@param[in]		col				�F�␳
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col);
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				@param[in]		col				�F�␳
				@param[in]		uv				UV�␳
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col,const Vector2& uv);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				@param[in]		col				�F�␳
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				@param[in]		col				�F�␳
				@param[in]		uv				UV�␳
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col,const Vector2& uv);
		
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				@param[in]		col				�F�␳
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				@param[in]		col				�F�␳
				@param[in]		uv				UV�␳
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				@param[in]		col				�F�␳
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				@param[in]		col				�F�␳
				@param[in]		uv				UV�␳
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind);


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
				@brief			���O�ݒ�
				@param[in]		pName			�ݒ肷�閼�O
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			�ϊ��s��ݒ�
				@param[in]		mat				�ݒ肷��ϊ��s��
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetMatrix(CMatrix44& mat);
		/*************************************************************************//*!
				@brief			�`������ݒ�
				@param[in]		Topology		�`�����
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetTopology(PrimitiveTopology Topology);
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�ݒ�
				@param[in]		pBuff			�ݒ�o�b�t�@
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetVertexBuffer(LPVertexBuffer pBuff);
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�o�b�t�@�ݒ�
				@param[in]		pBuff			�ݒ�o�b�t�@
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetIndexBuffer(LPIndexBuffer pBuff);
		/*************************************************************************//*!
				@brief			�}�e���A���ݒ�
				@param[in]		pMat			�ݒ�}�e���A��
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetMaterial(LPMaterial pMat);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void);
		/*************************************************************************//*!
				@brief			�ϊ��s��擾
				@param			None

				@return			�ϊ��s��̎擾
		*//**************************************************************************/
		virtual CMatrix44& GetMatrix(void);
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
				@brief			�C���f�b�N�X�o�b�t�@�擾
				@param			None

				@return			�C���f�b�N�X�o�b�t�@
		*//**************************************************************************/
		virtual LPIndexBuffer GetIndexBuffer(void);
		/*************************************************************************//*!
				@brief			�}�e���A���擾
				@param			None

				@return			�}�e���A��
		*//**************************************************************************/
		virtual LPMaterial GetMaterial(void);
		/*************************************************************************//*!
				@brief			���[�t�B���O�擾
				@param			None

				@return			���[�t�B���O
		*//**************************************************************************/
		virtual LPGeometryMorphingArray GetMorphing(void);
		/*************************************************************************//*!
				@brief			�Ή��{�[�������X�g�擾
				@param			None

				@return			�Ή��{�[�������X�g
		*//**************************************************************************/
		virtual LPStringArray GetBoneNameArray(void);
		/*************************************************************************//*!
				@brief			�����蔻��p�L���b�V���擾<br>
								�����蔻��p�̃L���b�V�������݂��Ȃ��ꍇ�͐V�K�ɐ����������Ȃ�
				@param			None

				@return			�����蔻��p�L���b�V��
		*//**************************************************************************/
		virtual LPGeometryCollisionCache GetCollisionCache(void);
	};

	#include	"GeometryBase.inl"
}

#endif

//[EOF]