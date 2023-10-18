/*************************************************************************//*!
					
					@file	GeometryMorphing.h
					@brief	�W�I���g�����[�t�B���O���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GEOMETRYMORPHINGANIMATION__H__

#define		__GEOMETRYMORPHINGANIMATION__H__

//INCLUDE
#include	"VertexBuffer.h"
#include	"MomCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���A�j���[�V�����C���^�[�t�F�C�X

			���b�V���A�j���[�V�����C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IGeometryMorphing : public IMofNamedObject , public IMofCopyObject< IGeometryMorphing > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���_���W���[�t�B���O�ݒ�<br>
								�Â��f�[�^������ꍇ��������
				@param[in]		pArray			�ݒ肷��L�[
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetMorphingPosition(LPGeometryMorphingPositionArray pArray) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���_���W���[�t�B���O�擾
				@param			None

				@return			���_���W���[�t�B���O
		*//**************************************************************************/
		virtual LPGeometryMorphingPositionArray GetMorphingPosition(void) = 0;
	};
	
	//�|�C���^�u������
	typedef IGeometryMorphing*				LPGeometryMorphing;
	typedef CDynamicArray< LPGeometryMorphing >		CGeometryMorphingArray,*LPGeometryMorphingArray;
}

#endif	//__GEOMETRYMORPHINGANIMATION__H__

//[EOF]