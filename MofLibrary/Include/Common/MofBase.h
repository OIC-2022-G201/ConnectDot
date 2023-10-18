/*************************************************************************//*!
					
					@file	MofBase.h
					@brief	�S�ẴC���^�[�t�F�C�X�E�N���X�̊�b�A�p�������o�̊m�F�Ȃǂ̋@�\������<br>
							���C�u���������̃N���X�͑S��IMofBase���p������B

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
	@brief	���C���^�[�t�F�C�X

			MOF���C�u�������̑S�ẴN���X�̊��ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~IMofBase(){}
		/*************************************************************************//*!
				@brief			�N���XID�̎擾
				@param			None

				@return			�N���XID<br>
								�N���X�̎�ނ����ʂ��邽�߂Ɏg�p�����B
		*//**************************************************************************/
		virtual const MofU32 GetTypeID(void) const = 0;
		/*************************************************************************//*!
				@brief			�N���X���̎擾
				@param			None

				@return			�N���X��<br>
								�N���X�̖��O����N���XID���擾���邽�߂Ɏg�p�����B
		*//**************************************************************************/
		virtual LPCMofChar GetTypeName(void) const = 0;
	};
	
	/*******************************//*!
	@brief	���R�s�[�C���^�[�t�F�C�X��������p

			�R�s�[�C���^�[�t�F�C�X���p�����邩���f���邽�߂̓����N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofCopyImpl {};

	/*******************************//*!
	@brief	���R�s�[�C���^�[�t�F�C�X

			�R�s�[�C���^�[�t�F�C�X���p������B

	@author	CDW
	*//********************************/
	template < typename T >	class MOFLIBRARY_API IMofCopyObject : public IMofCopyImpl {
	public:
		virtual ~IMofCopyObject(){}
		virtual T* CreateCopyObject() const = 0;
	};
	
	/*******************************//*!
	@brief	�Q�ƃJ�E���^�C���^�[�t�F�C�X

			�R�s�[�C���^�[�t�F�C�X���p�����邩���f���邽�߂̓����N���X�B

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
	@brief	���C���^�[�t�F�C�X�p���N���X�����f����

			�C���^�[�t�F�C�X���p������ꍇ�Avalue��true�Ⴄ�ꍇ��value��false�ɂȂ�B

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
	@brief	���C���^�[�t�F�C�X�p���N���X�����f����

			�C���^�[�t�F�C�X���p������ꍇ�Avalue��true�Ⴄ�ꍇ��value��false�ɂȂ�B

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
	@brief	���I�u�W�F�N�g�C���^�[�t�F�C�X

			MOF���C�u�������̑S�ẴI�u�W�F�N�g�̊��ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMofObject : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~IMofObject(){}
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
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