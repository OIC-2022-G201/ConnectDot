/*************************************************************************//*!
					
					@file	CollisionUtilities.h
					@brief	�����蔻��֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__COLLISIONUTILITIES__H__

#define		__COLLISIONUTILITIES__H__

//INCLUDE
#include	"../Collision/Rectangle.h"
#include	"../Collision/Circle.h"

namespace Mof {

	/*******************************//*!
	@brief	�����蔻��֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X

			�����蔻��֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CCollisionUtilities {
	private:
	public:
	private:
		//�쐬���֎~����
		CCollisionUtilities(){};
		CCollisionUtilities(const CCollisionUtilities& pObj){};
	};

	#include	"CollisionUtilities.inl"
}

#endif

//[EOF]