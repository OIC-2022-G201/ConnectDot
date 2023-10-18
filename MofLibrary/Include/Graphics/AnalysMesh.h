/*************************************************************************//*!
					
					@file	AnalysMesh.h
					@brief	MOM�t�@�C���̉�͂��s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ANALYSMESH__H__

#define		__ANALYSMESH__H__

//INCLUDE
#include	"MeshContainer.h"
#include	"BoneBase.h"
#include	"MeshAnimationBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MOM�t�@�C����̓N���X

			MOM�t�@�C���̉�͂��s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CAnalysMesh : public CReadBinaryFile {
	private:
		/*******************//*!
		�t�@�C���w�b�_�[
		*//********************/
		MOFMODELHEADER				m_Header;
		/*******************//*!
		�����p�e�N�X�`�����X�g
		*//********************/
		LPTextureArray				m_pTextureArray;
		
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pModel		���b�V���t�@�C��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Analys(LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pModel		���b�V���t�@�C��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysMesh(LPMesh pModel);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pModel		���b�V���t�@�C��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysMeshBlock(LPMesh pModel);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pGeometry	�W�I���g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysGeometry(LPGeometry pGeometry);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pVert		���_
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysVertex(LPVertexBuffer pVert);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pInd		�C���f�b�N�X
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysIndex(LPIndexBuffer pInd);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pMat		�}�e���A��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysMaterial(LPMaterial pMat);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pMorphing	�}�e���A��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysMorphing(LPGeometryMorphing pMorphing);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pMorphing	�}�e���A��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysMorphingPosition(LPGeometryMorphing pMorphing);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pMat		�}�e���A��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysTexture(LPMaterial pMat);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pBone		�{�[��
				@param[in]		pModel		���b�V���t�@�C��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysBone(LPBone pBone,LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pBone		�{�[��
				@param[in]		pModel		���b�V���t�@�C��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysBoneWeight(LPBone pBone,LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pBone		�{�[��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysIK(LPBone pBone);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pAnim		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimation(LPMeshAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pAnim		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimation(LPMeshBoneAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pAnim		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimation2(LPMeshBoneAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pAnim		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimation(LPMeshMorphingAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pAnim		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimationKey(LPMeshBoneAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pAnim		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimationKey(LPMeshMorphingAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		kit			��ԃ^�C�v
				@param[out]		inval		��Ԑ��l
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysKeyInterpolation(MofU32 kit,LPMofFloat inval);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pRigid		���̏��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysRigid(LPMOMPHYSICSRIGIDINFO pRigid);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pJoint		�W���C���g���
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysRigidJoint(LPMOMPHYSICSJOINTINFO pJoint);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pCamera		�J����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysCamera(LPMeshCamera pCamera);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pCamera		�J����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysCameraAnimation(LPMeshCameraAnimation pCamera);
		/*************************************************************************//*!
				@brief			MOM�t�@�C����ǂݍ���
				@param[in]		pCamera		�A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysCameraAnimationKey(LPMeshCameraAnimation pCamera);
		/*************************************************************************//*!
				@brief			�ǂݍ��݃u���b�N�̈ړ�
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool MoveBlockOffset(void);
		/*************************************************************************//*!
				@brief			MOM�t�@�C�����𔻒肷��<br>
								�t�@�C���̐擪��MOFMODEL_FILE_HEADER����n�܂��MOM�t�@�C��
				@param			None
				
				@return			TRUE		MOM�t�@�C��<br>
								����ȊO	MOM�t�@�C���ł͂Ȃ�
		*//**************************************************************************/
		MofBool IsMOMFile(void);
		/*************************************************************************//*!
				@brief			MOM�t�@�C���t�b�^�[�܂ŉ�͂������𔻒肷��<br>
								���݈ʒu����MOFMODEL_FILE_FOOTER�̃f�[�^�ɂȂ��Ă���΃t�b�^�[
				@param			None
				
				@return			TRUE							�t�b�^�[<br>
								FALSE							�܂��t�b�^�[�ł͂Ȃ�<br>
								MOFMODEL_RESULTERROR_NOTFOOTER	�t�b�^�[����Ȃ��̂Ƀt�@�C�����I�����Ă���
		*//**************************************************************************/
		MofBool IsMOMFooter(void);
		/*************************************************************************//*!
				@brief			MOM�t�@�C������A�j���[�V������������ǂݍ���
				@param[out]		pModel		�o�̓��f��
				@param[out]		pAnim		�A�^�b�`����A�j���[�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AttachAnimation(LPMeshContainer pModel, LPMeshAnimation pAnim);
		/*************************************************************************//*!
				@brief			MOM�t�@�C������A�j���[�V������������ǂݍ���
				@param[out]		pModel		�o�̓��f��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			MOM�t�@�C������A�j���[�V������������ǂݍ���
				@param[in]		pAnimations	�o�̓A�j���[�V�����z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPMeshAnimationArray pAnimations);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CAnalysMesh();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAnalysMesh();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s��
				@param[in]		pName		�t�@�C����
				@param[out]		pModel		�o�̓��f��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Analys(LPCMofChar pName,LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			�����������͂��s��
				@param[in]		pName		���O
				@param[in]		pBuffer		�o�b�t�@
				@param[in]		Size		�T�C�Y
				@param[out]		pModel		�o�̓��f��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Analys(LPCMofChar pName,LPCMofVoid pBuffer,const MofU32 Size,LPMeshContainer pModel);
		
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ăA�j���[�V�������̂݉�͂��s��
				@param[in]		pName		�t�@�C����
				@param[out]		pModel		�o�̓��f��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPCMofChar pName, LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			����������A�j���[�V�������̂݉�͂��s��
				@param[in]		pName		���O
				@param[in]		pBuffer		�o�b�t�@
				@param[in]		Size		�T�C�Y
				@param[out]		pModel		�o�̓��f��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPCMofChar pName, LPCMofVoid pBuffer, const MofU32 Size, LPMeshContainer pModel);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ăA�j���[�V�������̂݉�͂��s��
				@param[in]		pName		�t�@�C����
				@param[out]		pAnimations		�o�̓A�j���[�V�����z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPCMofChar pName,LPMeshAnimationArray pAnimations);
		/*************************************************************************//*!
				@brief			����������A�j���[�V�������̂݉�͂��s��
				@param[in]		pName		���O
				@param[in]		pBuffer		�o�b�t�@
				@param[in]		Size		�T�C�Y
				@param[out]		pAnimations		�o�̓A�j���[�V�����z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysAnimationOnly(LPCMofChar pName,LPCMofVoid pBuffer,const MofU32 Size,LPMeshAnimationArray pAnimations);
		
		
		/*************************************************************************//*!
				@brief			�e�N�X�`�������z��ݒ�
				@param[in]		pTex		�e�N�X�`�������z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool SetTextureArray(LPTextureArray pTex);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CAnalysMesh,MOF_ANALYSMESHCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"AnalysMesh.inl"

}

#endif	//__ANALYSMESH__H__

//[EOF]