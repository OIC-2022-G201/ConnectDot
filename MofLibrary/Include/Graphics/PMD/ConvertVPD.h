/*****************************************************************************
					
					�m�t�@�C�����n	ConvertVPD.h
					�m�����T�v�n	VPD�A�j���[�V�����ϊ��N���X
					
															@author	CDW
															Since  2009.04.01
*****************************************************************************/

//ONCE
#ifndef		__CONVERTVPDANIMATION__H__

#define		__CONVERTVPDANIMATION__H__

//INCLUDE
#include	"../MeshContainer.h"
#include	"../BoneBase.h"
#include	"../MeshAnimationBase.h"
#include	"../MomCommon.h"

namespace Mof {

	//DEFINE
#define		VPDHEADERSTRING				"Vocaloid Pose Data file"
#define		VPDHEADERLENGTH				(24)

	//TYPEDEF STRUCT

	/*******************************//*!
	@brief	�u�o�c�t�@�C���w�b�_�[�\����

			�u�o�c�t�@�C���w�b�_�[�\���́B

	@author	CDW
	*//********************************/
	typedef MOFLIBRARY_API struct tag_VPDHEADER {
		char							Header[VPDHEADERLENGTH];				//!<Vocaloid Pose Data file
		char							MName[256];								//!<���f����
	}VPDHEADER, *LPVPDHEADER;

	//CLASS
	
	/*******************************//*!
	@brief	�u�o�c�t�@�C���ϊ��N���X

			�u�o�c�t�@�C���̕ϊ����s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertVPD : public CReadTextFile {
	private:
		/*******************//*!
		�A�j���[�V�������i�[���f��
		*//********************/
		LPMeshContainer					m_pMesh;
		/*******************//*!
		�A�j���[�V������
		*//********************/
		LPMeshAnimation					m_pAnimation;

		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(void);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertAnimation(void);

		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[out]		pData		�w�b�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ReadHeader(LPVPDHEADER pData);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertVPD();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertVPD();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A���b�V���A�j���[�V�����Ƃ��ĕԂ�
				@param[in]		pInName		���̓t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A���b�V���A�j���[�V�����Ƃ��ĕԂ�
				@param[in]		pInName		���̓t�@�C����
				@param[in]		pMesh		���̓��b�V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPMeshContainer pMesh);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			�A�j���[�V�����擾
				@param			None

				@return			�A�j���[�V�����̎擾
		*//**************************************************************************/
		virtual LPMeshAnimation GetAnimation(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CConvertVPD, MOF_CONVERTVPDCLASS_ID);
	};

		//INLINE INCLUDE
	#include	"ConvertVPD.inl"

}

#endif	//__CONVERTVPDANIMATION__H__

//[EOF]