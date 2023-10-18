/*************************************************************************//*!
					
					@file	MeshMorphingAnimation.h
					@brief	���b�V���A�j���[�V�������C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHMORPHINGANIMATION__H__

#define		__MESHMORPHINGANIMATION__H__

//INCLUDE
#include	"Bone.h"
#include	"../Common/KeyFrameArray.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���A�j���[�V�����C���^�[�t�F�C�X

			���b�V���A�j���[�V�����C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshMorphingAnimation : public IMofNamedObject , public IMofCopyObject< IMeshMorphingAnimation > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�p�����[�^�[�L�[�ݒ�<br>
								�Â��f�[�^������ꍇ��������
				@param[in]		pKey			�ݒ肷��L�[
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetParameterKey(LPFloatKeyFrameArray pKey) = 0;
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
				@brief			�p�����[�^�[�L�[�擾
				@param			None

				@return			�p�����[�^�[�L�[
		*//**************************************************************************/
		virtual LPFloatKeyFrameArray GetParameterKey(void) = 0;
	};
	
	//�|�C���^�u������
	typedef IMeshMorphingAnimation*				LPMeshMorphingAnimation;
	typedef CDynamicArray< LPMeshMorphingAnimation >		CMeshMorphingAnimationArray,*LPMeshMorphingAnimationArray;
}

#endif	//__MESHMORPHINGANIMATION__H__

//[EOF]