/*************************************************************************//*!
					
					@file	MofBase.h
					@brief	全てのインターフェイス・クラスの基礎、継承メンバの確認などの機能を準備<br>
							ライブラリ内部のクラスは全てIMofBaseを継承する。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MOFBASE__H__

#define		__MOFBASE__H__

//INCLUDE
#include	"MofCommon.h"
#include	"MofID.h"
#include	"../Math/MathCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	基底インターフェイス

			MOFライブラリ内の全てのクラスの基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~IMofBase(){}
		/*************************************************************************//*!
				@brief			クラスIDの取得
				@param			None

				@return			クラスID<br>
								クラスの種類を識別するために使用される。
		*//**************************************************************************/
		virtual const MofU32 GetTypeID(void) const = 0;
		/*************************************************************************//*!
				@brief			クラス名の取得
				@param			None

				@return			クラス名<br>
								クラスの名前からクラスIDを取得するために使用される。
		*//**************************************************************************/
		virtual LPCMofChar GetTypeName(void) const = 0;
	};
	
	/*******************************//*!
	@brief	基底コピーインターフェイス内部判定用

			コピーインターフェイスを継承するか判断するための内部クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofCopyImpl {};

	/*******************************//*!
	@brief	基底コピーインターフェイス

			コピーインターフェイスを継承する。

	@author	CDW
	*//********************************/
	template < typename T >	class MOFLIBRARY_API IMofCopyObject : public IMofCopyImpl {
	public:
		virtual ~IMofCopyObject(){}
		virtual T* CreateCopyObject() const = 0;
	};
	
	/*******************************//*!
	@brief	参照カウンタインターフェイス

			コピーインターフェイスを継承するか判断するための内部クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofRefCounter {
	private:
		LPMofU32			m_pCounter;
	public:
		IMofRefCounter() : m_pCounter(NULL) { m_pCounter = new MofU32(); *m_pCounter = 1; }
		IMofRefCounter(const IMofRefCounter& pObj) : m_pCounter(pObj.m_pCounter) { if(m_pCounter){ (*m_pCounter)++; } }
		virtual ~IMofRefCounter(){ DeclRef(); }
		virtual void AddRef(void){ if (m_pCounter){ (*m_pCounter)++; } else { m_pCounter = new MofU32(); *m_pCounter = 1; } }
		virtual MofBool DeclRef(void){ if (m_pCounter){ (*m_pCounter)--; if ((*m_pCounter) <= 0){ delete m_pCounter; m_pCounter = NULL; return TRUE; } } m_pCounter = NULL; return FALSE; }
		virtual MofBool IsRef(void){ if (m_pCounter){ if ((*m_pCounter) > 0){ return TRUE; } } return FALSE; }
	};

	/*******************************//*!
	@brief	基底インターフェイス継承クラスか判断する

			インターフェイスを継承する場合、valueがtrue違う場合はvalueがfalseになる。

	@author	CDW
	*//********************************/
	template <class T,class Inter> class IsMofInheritance {
	private:
		static char IsType(Inter);
		static char IsType(Inter*);
		static double IsType(...);
		static T* CreateT();
	public:
		static const bool value = sizeof(IsType(CreateT())) == sizeof(char);
	};
	/*******************************//*!
	@brief	基底インターフェイス継承クラスか判断する

			インターフェイスを継承する場合、valueがtrue違う場合はvalueがfalseになる。

	@author	CDW
	*//********************************/
	template <class T,class Inter> class IsMofInheritance< T*, Inter > {
	private:
		static char IsType(Inter);
		static char IsType(Inter*);
		static double IsType(...);
		static T* CreateT();
	public:
		static const bool value = sizeof(IsType(CreateT())) == sizeof(char);
	};

	/*******************************//*!
	@brief	基底オブジェクトインターフェイス

			MOFライブラリ内の全てのオブジェクトの基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofObject : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~IMofObject(){}
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL) = 0;
	};

}

#define		MOF_CLASSID(id)							virtual const MofU32 GetTypeID(void) const { return id; } static const MofU32 GetClassID(void){ return id; }
#define		MOF_CLASSNAME(s)						virtual LPCMofChar GetTypeName(void) const { static MofChar name[] = s;	return name; }
#define		MOF_CLASSCOPYEQUAL(s)					s& operator=(const s& a){ if(this == &a){ return *this; } this->~s(); return PLACEMENT_NEW(*this,a); }

#define		MOF_LIBRARYCLASS(s,id)					MOF_CLASSNAME(MOF_VALUENAME(s)) MOF_CLASSID(id) MOF_CLASSCOPYEQUAL(s) MOF_ALIGNED_NEW_OPERATOR(s)
#define		MOF_LIBRARYCLASS_NOTEQUAL(s,id)			MOF_CLASSNAME(MOF_VALUENAME(s)) MOF_CLASSID(id)
#define		MOF_LIBRARYCLASS_NOTCOPY(s,id)			MOF_CLASSNAME(MOF_VALUENAME(s)) MOF_CLASSID(id) private: s(const s& pObj){};

#endif

//[EOF]