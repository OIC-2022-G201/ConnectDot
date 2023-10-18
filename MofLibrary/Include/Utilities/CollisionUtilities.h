/*************************************************************************//*!
					
					@file	CollisionUtilities.h
					@brief	あたり判定関連の汎用処理をまとめたスタティッククラス。

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
	@brief	あたり判定関連の汎用処理をまとめたスタティッククラス

			あたり判定関連の汎用処理をまとめたスタティッククラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CCollisionUtilities {
	private:
	public:
	private:
		//作成を禁止する
		CCollisionUtilities(){};
		CCollisionUtilities(const CCollisionUtilities& pObj){};
	};

	#include	"CollisionUtilities.inl"
}

#endif

//[EOF]