/*************************************************************************//*!
					
					@file	GeometryMorphing.h
					@brief	ジオメトリモーフィング基底インターフェイス。

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
	@brief	メッシュアニメーションインターフェイス

			メッシュアニメーションインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IGeometryMorphing : public IMofNamedObject , public IMofCopyObject< IGeometryMorphing > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			頂点座標モーフィング設定<br>
								古いデータがある場合解放される
				@param[in]		pArray			設定するキー
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetMorphingPosition(LPGeometryMorphingPositionArray pArray) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			頂点座標モーフィング取得
				@param			None

				@return			頂点座標モーフィング
		*//**************************************************************************/
		virtual LPGeometryMorphingPositionArray GetMorphingPosition(void) = 0;
	};
	
	//ポインタ置き換え
	typedef IGeometryMorphing*				LPGeometryMorphing;
	typedef CDynamicArray< LPGeometryMorphing >		CGeometryMorphingArray,*LPGeometryMorphingArray;
}

#endif	//__GEOMETRYMORPHINGANIMATION__H__

//[EOF]