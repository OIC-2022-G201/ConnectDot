/*************************************************************************//*!
					
					@file	Mesh.h
					@brief	���b�V�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESH__H__

#define		__MESH__H__

//INCLUDE
#include	"Geometry.h"
#include	"MeshBlock.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���C���^�[�t�F�C�X

			���b�V���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMesh : public IMofNamedObject , public IMofCopyObject< IMesh > {
	private:
	public:
		/*************************************************************************//*!
				@brief			�o�b�t�@�̍쐬
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CreateBuffer(void) = 0;
		
		/*************************************************************************//*!
				@brief			�ő�E�ŏ��v�Z
				@param[out]		minv			�o�͗p�ŏ�
				@param[out]		maxv			�o�͗p�ő�
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateMinMax(Vector3& minv,Vector3& maxv) = 0;
		/*************************************************************************//*!
				@brief			AABB�v�Z
				@param[out]		aabb			�o�͗p�{�b�N�X
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateAABB(BoxAABB& aabb) = 0;
		/*************************************************************************//*!
				@brief			���E���v�Z
				@param[out]		sph				�o�͗p��
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CalculateSphere(Sphere& sph) = 0;
		
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
								����ȊO			����G���[�A�G���[�R�[�h��Ԃ��B
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
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�W�I���g�����X�g�擾
				@param			None

				@return			�W�I���g�����X�g
		*//**************************************************************************/
		virtual LPGeometryArray GetGeometry(void) = 0;
		/*************************************************************************//*!
				@brief			�u���b�N���X�g�擾
				@param			None

				@return			�u���b�N���X�g
		*//**************************************************************************/
		virtual LPBlockContainer GetBlockContainer(void) = 0;
		/*************************************************************************//*!
				@brief			�W�I���g���o�^���擾
				@param			None

				@return			�W�I���g���o�^��
		*//**************************************************************************/
		virtual MofU32 GetGeometryCount(void) const = 0;
		/*************************************************************************//*!
				@brief			�W�I���g���擾
				@param[in]		pName			�T���W�I���g����

				@return			�W�I���g��
								������Ȃ������ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual LPGeometry GetGeometryByName(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			�W�I���g���擾
				@param[in]		No				�W�I���g���ԍ�

				@return			�W�I���g��
								������Ȃ������ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual LPGeometry GetGeometry(MofU32 No) = 0;
	};
	
	//�|�C���^�u������
	typedef IMesh*				LPMesh;
	typedef CDynamicArray< LPMesh >		CMeshArray,*LPMeshArray;
}

#endif	//__MESH__H__

//[EOF]