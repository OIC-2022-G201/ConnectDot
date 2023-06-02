/*************************************************************************//*!
					
					@file	Geometry.h
					@brief	�W�I���g�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GEOMETRY__H__

#define		__GEOMETRY__H__

//INCLUDE
#include	"MomCommon.h"
#include	"VertexBuffer.h"
#include	"IndexBuffer.h"
#include	"Material.h"
#include	"GeometryMorphing.h"
#include	"Shader.h"
#include	"ShaderBindBase.h"
#include	"MeshMotionController.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�W�I���g�����C���^�[�t�F�C�X

			�W�I���g�����ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IGeometry : public IMofNamedObject, public IMofCopyObject< IGeometry >  {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�o�b�t�@�̍쐬<br>
								�W�I���g�������œo�^����Ă���A���_�o�b�t�@��C���f�b�N�X�o�b�t�@�̐����������Ȃ��B<br>
								�W�I���g���̒��_��C���f�b�N�X�̏���ύX�����ꍇ�Ɏ��s����K�v������B
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CreateBuffer(void) = 0;
		
		/*************************************************************************//*!
				@brief			�ő�E�ŏ��v�Z<br>
								�W�I���g���Ɋ܂܂�钸�_�̍ő�ʒu�ƍŏ��ʒu�����߂�B
				@param[out]		minv			�o�͗p�ŏ�
				@param[out]		maxv			�o�͗p�ő�
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateMinMax(Vector3& minv,Vector3& maxv) = 0;
		/*************************************************************************//*!
				@brief			�w��{�[�����ɃE�F�C�g������t���Ă���A�ő�E�ŏ����W�v�Z
				@param[in]		pBName			�{�[����
				@param[out]		minv			�o�͗p�ŏ�
				@param[out]		maxv			�o�͗p�ő�
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateMinMax(LPCMofChar pBName, Vector3& minv, Vector3& maxv) = 0;

		/*************************************************************************//*!
				@brief			AABB�v�Z<br>
								�W�I���g���Ɋ܂܂�钸�_�̋��E�{�b�N�X�����߂�B
				@param[out]		aabb			�o�͗p�{�b�N�X
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateAABB(BoxAABB& aabb) = 0;
		/*************************************************************************//*!
				@brief			�w��{�[�����ɃE�F�C�g������t���Ă���AAABB�v�Z
				@param[in]		pBName			�{�[����
				@param[out]		aabb			�o�͗p�{�b�N�X
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateAABB(LPCMofChar pBName, BoxAABB& aabb) = 0;
		/*************************************************************************//*!
				@brief			���E���v�Z
				@param[out]		sph				�o�͗p��
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateSphere(Sphere& sph) = 0;
		/*************************************************************************//*!
				@brief			�w��{�[�����ɃE�F�C�g������t���Ă���A���E���v�Z
				@param[in]		pBName			�{�[����
				@param[out]		sph				�o�͗p��
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateSphere(LPCMofChar pBName, Sphere& sph) = 0;
		
		/*************************************************************************//*!
				@brief			��{�`��<br>
								�o�b�t�@�̐ݒ�ƁA�`��̃R�[���݂̂��s���B<br>
								�}�e���A���̐ݒ�ȂǁA�V�F�[�_�[�̐ݒ�͌Ăяo���O�ɍs���Ă������ƁB
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO			����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(void) = 0;

		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat) = 0;
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				@param[in]		col				�F�␳
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col) = 0;
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				@param[in]		col				�F�␳
				@param[in]		uv				UV�␳
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat,const Vector4& col,const Vector2& uv) = 0;
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion) = 0;
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				@param[in]		col				�F�␳
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col) = 0;
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				@param[in]		col				�F�␳
				@param[in]		uv				UV�␳
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion,const Vector4& col,const Vector2& uv) = 0;

		
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		wMat			�ϊ��s��
				@param[in]		col				�F�␳
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind) = 0;
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
		virtual MofBool Render(const Matrix44& wMat, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, LPShader pShader, LPShaderBind pShaderBind) = 0;
		/*************************************************************************//*!
				@brief			�A�j���[�V�����`��
				@param[in]		pMotion			���[�V�����R���g���[��
				@param[in]		col				�F�␳
				@param[in]		pShader			�V�F�[�_�[
				@param[in]		pShaderBind		�V�F�[�_�[�o�C���h
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, LPShader pShader, LPShaderBind pShaderBind) = 0;
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
		virtual MofBool Render(LPMeshMotionController pMotion, const Vector4& col, const Vector2& uv, LPShader pShader, LPShaderBind pShaderBind) = 0;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ϊ��s��ݒ�
				@param[in]		mat				�ݒ肷��ϊ��s��
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetMatrix(CMatrix44& mat) = 0;
		/*************************************************************************//*!
				@brief			�`������ݒ�
				@param[in]		Topology		�`�����
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetTopology(PrimitiveTopology Topology) = 0;
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�ݒ�
				@param[in]		pBuff			�ݒ�o�b�t�@
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetVertexBuffer(LPVertexBuffer pBuff) = 0;
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�o�b�t�@�ݒ�
				@param[in]		pBuff			�ݒ�o�b�t�@
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetIndexBuffer(LPIndexBuffer pBuff) = 0;
		/*************************************************************************//*!
				@brief			�}�e���A���ݒ�
				@param[in]		pMat			�ݒ�}�e���A��
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetMaterial(LPMaterial pMat) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ϊ��s��擾
				@param			None

				@return			�ϊ��s��̎擾
		*//**************************************************************************/
		virtual CMatrix44& GetMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�擾
				@param			None

				@return			���_�o�b�t�@
		*//**************************************************************************/
		virtual LPVertexBuffer GetVertexBuffer(void) = 0;
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�擾
				@param[in,out]	pOut			���_�o�b�t�@�z��<br>
												�o�͗p�̃|�C���^��NULL�Ȃ�i�[����Ȃ��B
				@param[in,out]	cnt				���_�o�b�t�@�̐�<br>
												���s���ɂ�pOut�̊i�[�ő吔���w�肷��B

				@return			TRUE			����I��<br>
								����ȊO		�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool GetVertexBuffer(LPVertexBuffer* pOut,MofU32& cnt) = 0;
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�t���O�擾
				@param			None

				@return			���_�o�b�t�@�t���O
		*//**************************************************************************/
		virtual VertexFlag GetVertexFlag(void) = 0;
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�o�b�t�@�擾
				@param			None

				@return			�C���f�b�N�X�o�b�t�@
		*//**************************************************************************/
		virtual LPIndexBuffer GetIndexBuffer(void) = 0;
		/*************************************************************************//*!
				@brief			�}�e���A���擾
				@param			None

				@return			�}�e���A��
		*//**************************************************************************/
		virtual LPMaterial GetMaterial(void) = 0;
		/*************************************************************************//*!
				@brief			���[�t�B���O�擾
				@param			None

				@return			���[�t�B���O
		*//**************************************************************************/
		virtual LPGeometryMorphingArray GetMorphing(void) = 0;
		/*************************************************************************//*!
				@brief			�Ή��{�[�������X�g�擾
				@param			None

				@return			�Ή��{�[�������X�g
		*//**************************************************************************/
		virtual LPStringArray GetBoneNameArray(void) = 0;
		/*************************************************************************//*!
				@brief			�����蔻��p�L���b�V���擾
				@param			None

				@return			�����蔻��p�L���b�V��
		*//**************************************************************************/
		virtual LPGeometryCollisionCache GetCollisionCache(void) = 0;
	};

	//�|�C���^�u������
	typedef IGeometry*		LPGeometry;
	typedef CDynamicArray< LPGeometry >		CGeometryArray,*LPGeometryArray;
}

#endif

//[EOF]