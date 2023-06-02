/*************************************************************************//*!
					
					@file	MeshAnimation.h
					@brief	���b�V���A�j���[�V�������C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHANIMATION__H__

#define		__MESHANIMATION__H__

//INCLUDE
#include	"MeshBoneAnimationBase.h"
#include	"MeshMorphingAnimationBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���A�j���[�V�����C���^�[�t�F�C�X

			���b�V���A�j���[�V�����C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshAnimation : public IMofNamedObject , public IMofCopyObject< IMeshAnimation > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
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
				@brief			�A�j���[�V�����ł̓���{�[�����擾
				@param			None

				@return			�A�j���[�V�����ł̓���{�[�����z��
		*//**************************************************************************/
		virtual LPMeshBoneAnimationArray GetBoneAnimation(void) = 0;
		/*************************************************************************//*!
				@brief			�A�j���[�V�����ł̓��샂�[�t�B���O���擾
				@param			None

				@return			�A�j���[�V�����ł̓��샂�[�t�B���O���z��
		*//**************************************************************************/
		virtual LPMeshMorphingAnimationArray GetMorphingAnimation(void) = 0;
		/*************************************************************************//*!
				@brief			�A�j���[�V�����̎��Ԏ擾
				@param			None

				@return			�A�j���[�V�����̎���
		*//**************************************************************************/
		virtual MofFloat GetTime(void) = 0;
	};
	
	//�|�C���^�u������
	typedef IMeshAnimation*				LPMeshAnimation;
	typedef CDynamicArray< LPMeshAnimation >		CMeshAnimationArray,*LPMeshAnimationArray;
}

#endif	//__MESHANIMATION__H__

//[EOF]