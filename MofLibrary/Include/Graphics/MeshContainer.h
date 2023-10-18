/*************************************************************************//*!
					
					@file	MeshContainer.h
					@brief	���b�V���R���e�i���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHCONTAINER__H__

#define		__MESHCONTAINER__H__

//INCLUDE
#include	"Mesh.h"
#include	"MeshCameraBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���R���e�i�C���^�[�t�F�C�X

			���b�V���R���e�i�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshContainer : public IMofNamedObject , public IMofCopyObject< IMeshContainer > {
	private:
	public:
		/*************************************************************************//*!
				@brief			���b�V���̓ǂݍ���
				@param[in]		pName		�t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			���b�V���̓ǂݍ���<br>
								���b�V�������ŗ��p����e�N�X�`���������̃e�N�X�`���z��upTex�v���猟���������Ȃ��B<br>
								���݂��Ȃ��ꍇ�V�K�ǂݍ��݂������Ȃ��A�e�N�X�`���z��ɒǉ�����B<br>
								�ʃ��b�V���œ���e�N�X�`���𕡐��g�p����ꍇ�̃������ߖ�Ɋ��p����B
				@param[in]		pName		�t�@�C����
				@param[in]		pTex		�e�N�X�`�������p�z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPTextureArray pTex) = 0;
		/*************************************************************************//*!
				@brief			���������烁�b�V���̓ǂݍ���
				@param[in]		pName		���O
				@param[in]		pData		�������A�h���X
				@param[in]		Size		�T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size) = 0;
		/*************************************************************************//*!
				@brief			���������烁�b�V���̓ǂݍ���<br>
								���b�V�������ŗ��p����e�N�X�`���������̃e�N�X�`���z��upTex�v���猟���������Ȃ��B<br>
								���݂��Ȃ��ꍇ�V�K�ǂݍ��݂������Ȃ��A�e�N�X�`���z��ɒǉ�����B<br>
								�ʃ��b�V���œ���e�N�X�`���𕡐��g�p����ꍇ�̃������ߖ�Ɋ��p����B
				@param[in]		pName		���O
				@param[in]		pData		�������A�h���X
				@param[in]		Size		�T�C�Y
				@param[in]		pTex		�e�N�X�`�������p�z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size,LPTextureArray pTex) = 0;
		
		/*************************************************************************//*!
				@brief			���b�V���̕ۑ�
				@param[in]		pName		�t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Save(const LPMofChar pName) = 0;

		/*************************************************************************//*!
				@brief			���[�V�����R���g���[���[�̍쐬<br>
								�����Ƀ{�[������A�j���[�V������񂪂Ȃ��ꍇ���s����
				@param			None
				
				@return			�쐬�������[�V�����R���g���[���[<br>
								NULL�̏ꍇ�쐬���s
		*//**************************************************************************/
		virtual LPMeshMotionController CreateMotionController(void) = 0;
		
		/*************************************************************************//*!
				@brief			��{�`��
				@param[in]		pos				���W
				@param[in]		scl				�X�P�[��
				@param[in]		rot				��]
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Render(const Vector3& pos, const Vector3& scl, const Vector3& rot) = 0;
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
		
		
		/*************************************************************************//*!
				@brief			�J������Ԃ̌v�Z
				@param[in]		pCam		�K�p�J����
				@param[in]		t			�A�j���[�V��������
				@param[in]		bLoop		���[�v
				@param[in]		pAnim		�A�j���[�V������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CalculateCamera(LPCamera pCam, MofFloat t, MofBool bLoop, LPCMofChar pAnim) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���b�V�����X�g�擾
				@param			None

				@return			���b�V�����X�g
		*//**************************************************************************/
		virtual LPMeshArray GetMesh(void) = 0;
		/*************************************************************************//*!
				@brief			���b�V���o�^���擾
				@param			None

				@return			���b�V���o�^��
		*//**************************************************************************/
		virtual MofU32 GetMeshCount(void) const = 0;
		/*************************************************************************//*!
				@brief			���b�V���擾
				@param[in]		No				���b�V���ԍ�

				@return			���b�V��
								������Ȃ������ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual LPMesh GetMesh(MofU32 No) = 0;
		/*************************************************************************//*!
				@brief			���b�V���擾
				@param[in]		pName			�T�����b�V����

				@return			���b�V��
								������Ȃ������ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual LPMesh GetMesh(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			�W�I���g���o�^���擾
				@param			None

				@return			�W�I���g���o�^��
		*//**************************************************************************/
		virtual MofU32 GetGeometryCount(void) const = 0;
		/*************************************************************************//*!
				@brief			�W�I���g���擾
				@param[in]		No				�W�I���g���ԍ�

				@return			�W�I���g��
								������Ȃ������ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual LPGeometry GetGeometry(MofU32 No) = 0;
		/*************************************************************************//*!
				@brief			�W�I���g���擾
				@param[in]		pName			�T���W�I���g����

				@return			�W�I���g��
								������Ȃ������ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual LPGeometry GetGeometryByName(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			�{�[�����X�g�擾
				@param			None

				@return			�{�[�����X�g
		*//**************************************************************************/
		virtual LPBoneArray GetBone(void) = 0;
		/*************************************************************************//*!
				@brief			���b�V���A�j���[�V�������X�g�擾
				@param			None

				@return			���b�V���A�j���[�V�������X�g
		*//**************************************************************************/
		virtual LPMeshAnimationArray GetAnimation(void) = 0;
		/*************************************************************************//*!
				@brief			���̏�񃊃X�g�擾
				@param			None

				@return			���̏�񃊃X�g
		*//**************************************************************************/
		virtual LPPhysicsActorInfoArray GetRigidInfo(void) = 0;
		/*************************************************************************//*!
				@brief			�W���C���g��񃊃X�g�擾
				@param			None

				@return			�W���C���g��񃊃X�g
		*//**************************************************************************/
		virtual LPPhysicsJointInfoArray GetJointInfo(void) = 0;
		/*************************************************************************//*!
				@brief			�J�������X�g�擾
				@param			None

				@return			�J�������X�g
		*//**************************************************************************/
		virtual LPMeshCameraArray GetCamera(void) = 0;
		/*************************************************************************//*!
				@brief			�J�����擾
				@param[in]		pName			�T���J������

				@return			�J����
								������Ȃ������ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual LPMeshCamera GetCamera(LPCMofChar pName) = 0;
	};
	
	//�|�C���^�u������
	typedef IMeshContainer*			LPMeshContainer;
	typedef CDynamicArray< LPMeshContainer >		CMeshContainerArray,*LPMeshContainerArray;
}

#endif	//__MESHCONTAINER__H__

//[EOF]