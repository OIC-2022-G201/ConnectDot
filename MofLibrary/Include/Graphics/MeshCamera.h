/*************************************************************************//*!
					
					@file	MeshCamera.h
					@brief	���b�V���J�������C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHCAMERA__H__

#define		__MESHCAMERA__H__

//INCLUDE
#include	"Camera.h"
#include	"MeshCameraAnimationBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���R���e�i�C���^�[�t�F�C�X

			���b�V���R���e�i�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshCamera : public IMofNamedObject , public IMofCopyObject< IMeshCamera > {
	private:
	public:
		/*************************************************************************//*!
				@brief			�J������Ԃ̌v�Z
				@param[in]		pCam		�K�p�J����

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CalculateCamera(LPCamera pCam) = 0;
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
				@brief			�J�������擾
				@param			None

				@return			�J�������
		*//**************************************************************************/
		virtual MOMCAMERAINFO& GetInfo(void) = 0;
		/*************************************************************************//*!
				@brief			�A�j���[�V�����̎擾
				@param			None

				@return			�A�j���[�V�����z��
		*//**************************************************************************/
		virtual LPMeshCameraAnimationArray GetAnimation(void) = 0;
		/*************************************************************************//*!
				@brief			�o�^����Ă��A�j���[�V�����擾
				@param[in]		pName			�A�j���[�V������

				@return			�A�j���[�V����
		*//**************************************************************************/
		virtual LPMeshCameraAnimation GetAnimation(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			�A�j���[�V�����o�^���擾
				@param			None

				@return			�A�j���[�V�����o�^��
		*//**************************************************************************/
		virtual MofU32 GetAnimationCount(void) = 0;
	};
	
	//�|�C���^�u������
	typedef IMeshCamera*			LPMeshCamera;
	typedef CDynamicArray< LPMeshCamera >		CMeshCameraArray,*LPMeshCameraArray;
}

#endif	//__MESHCONTAINER__H__

//[EOF]