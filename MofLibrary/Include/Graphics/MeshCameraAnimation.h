/*************************************************************************//*!
					
					@file	MeshCameraAnimation.h
					@brief	���b�V���A�j���[�V�������C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHCAMERAANIMATION__H__

#define		__MESHCAMERAANIMATION__H__

//INCLUDE
#include	"Bone.h"
#include	"../Common/KeyFrameArray.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���A�j���[�V�����C���^�[�t�F�C�X

			���b�V���A�j���[�V�����C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshCameraAnimation : public IMofNamedObject , public IMofCopyObject< IMeshCameraAnimation > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���W�L�[�ݒ�<br>
								�Â��f�[�^������ꍇ��������
				@param[in]		pKey			�ݒ肷��L�[
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetPositionKey(LPVector3KeyFrameArray pKey) = 0;
		/*************************************************************************//*!
				@brief			�^�[�Q�b�g�L�[�ݒ�<br>
								�Â��f�[�^������ꍇ��������
				@param[in]		pKey			�ݒ肷��L�[
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetTargetKey(LPVector3KeyFrameArray pKey) = 0;
		/*************************************************************************//*!
				@brief			����L�[�ݒ�<br>
								�Â��f�[�^������ꍇ��������
				@param[in]		pKey			�ݒ肷��L�[
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetUpKey(LPVector3KeyFrameArray pKey) = 0;
		/*************************************************************************//*!
				@brief			����p�L�[�ݒ�<br>
								�Â��f�[�^������ꍇ��������
				@param[in]		pKey			�ݒ肷��L�[
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetFovKey(LPFloatKeyFrameArray pKey) = 0;
		/*************************************************************************//*!
				@brief			���[�V�����̃��[�v�t���O�̐ݒ�
				@param[in]		bLoop			���[�v�t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetLoop(MofBool bLoop) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�A�j���[�V�����̎��Ԏ擾
				@param			None

				@return			�A�j���[�V�����̎���
		*//**************************************************************************/
		virtual MofFloat GetTime(void) = 0;
		/*************************************************************************//*!
				@brief			���W�L�[�擾
				@param			None

				@return			���W�L�[
		*//**************************************************************************/
		virtual LPVector3KeyFrameArray GetPositionKey(void) = 0;
		/*************************************************************************//*!
				@brief			�^�[�Q�b�g�L�[�擾
				@param			None

				@return			�^�[�Q�b�g�L�[
		*//**************************************************************************/
		virtual LPVector3KeyFrameArray GetTargetKey(void) = 0;
		/*************************************************************************//*!
				@brief			����L�[�擾
				@param			None

				@return			����L�[
		*//**************************************************************************/
		virtual LPVector3KeyFrameArray GetUpKey(void) = 0;
		/*************************************************************************//*!
				@brief			����p�L�[�擾
				@param			None

				@return			����p�L�[
		*//**************************************************************************/
		virtual LPFloatKeyFrameArray GetFovKey(void) = 0;
	};
	
	//�|�C���^�u������
	typedef IMeshCameraAnimation*				LPMeshCameraAnimation;
	typedef CDynamicArray< LPMeshCameraAnimation >		CMeshCameraAnimationArray,*LPMeshCameraAnimationArray;
}

#endif	//__MESHCAMERAANIMATION__H__

//[EOF]