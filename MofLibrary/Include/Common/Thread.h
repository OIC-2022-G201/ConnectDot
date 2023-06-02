/*************************************************************************//*!
					
					@file	Thread.h
					@brief	�X���b�h���쐬���s���邽�߂̊��C���^�[�t�F�C�X�ƃN���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__THREAD__H__

#define		__THREAD__H__

//INCLUDE
#include	"DynamicArray.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�X���b�h���C���^�[�t�F�C�X

			�X���b�h���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IThread : public IMofNamedObject {
	private:
	public:
		/*******************************//*!
		@brief	�X���b�h�v���C�I���e�B��

				�X���b�h���s�̗D��x�������v���C�I���e�B�񋓁B

		@author	CDW
		*//********************************/
		typedef enum ThreadPriorities {
			THREADPRIORITIES_LOWEST,				//!<�Œ�
			THREADPRIORITIES_LOW,					//!<��
			THREADPRIORITIES_NORMAL,				//!<����
			THREADPRIORITIES_HIGH,					//!<��
			THREADPRIORITIES_HIGHEST,				//!<�ō�
			THREADPRIORITIES_INHERIT,				//!<�ݒ�Ȃ�
		}ThreadPriorities;
		
		/*************************************************************************//*!
				@brief			�X���b�h�̊J�n
				@param[in]		pName			�X���b�h�̖��O
				@param[in]		priority		�X���b�h�̗D��x
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Start(LPCMofChar pName,ThreadPriorities priority = THREADPRIORITIES_INHERIT) = 0;
		/*************************************************************************//*!
				@brief			�X���b�h�̓������s����<br>
								�����͌p����̊e��X���b�h�N���X�ōs��
				@param			None

				@return			None
		*//**************************************************************************/
		virtual void Run(void) = 0;
		/*************************************************************************//*!
				@brief			�X���b�h�̓���
				@param[in]		w				�ҋ@����(msec)
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Join(MofU32 w = 0) = 0;
	};

	//�X���b�h�u������
	typedef IThread			*LPThread;
	
	/*******************************//*!
	@brief	�X���b�h���N���X

			�X���b�h���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CThread : public IThread {
	private:
		/*******************//*!
		�X���b�h��
		*//********************/
		CString						m_Name;
		/*******************//*!
		�X���b�hID
		*//********************/
		MofThreadID					m_ID;
		
		/*************************************************************************//*!
				@brief			�X���b�h�̌Ăяo���̂��ƂɂȂ�static�R�[���֐�
				@param[in]		pData			�X���b�h�̊J�n���ɗ^����ꂽCThread�N���X�|�C���^

				@return			�e���̃X���b�h�̎����Ɉˑ�
		*//**************************************************************************/
#ifdef		MOFLIB_WINDOWS
		static unsigned int __stdcall ThreadCallback( void* pData );
#else
		static void* ThreadCallback( void* pData );
#endif
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CThread();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CThread();
		
		/*************************************************************************//*!
				@brief			�X���b�h�̊J�n
				@param[in]		pName			�X���b�h�̖��O
				@param[in]		priority		�X���b�h�̗D��x
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Start(LPCMofChar pName,ThreadPriorities priority = THREADPRIORITIES_INHERIT);
		/*************************************************************************//*!
				@brief			�X���b�h�̓���
				@param[in]		w				�ҋ@����(msec)
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Join(MofU32 w = 0);
		
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�ݒ�
				@param[in]		pName			�ݒ肷�閼�O
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CThread,MOF_THREADCLASS_ID);
	};
	
	/*******************************//*!
	@brief	�X���b�h���������������N���X

			�X���b�h���������������N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRunnable : public IMofObject {
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CRunnable();

		/*************************************************************************//*!
				@brief			�X���b�h�̓������s����<br>
								�����͌p����̊e��X���b�h�N���X�ōs��
				@param			None

				@return			None
		*//**************************************************************************/
		virtual void Run(void) = 0;
		
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CRunnable,MOF_RUNNABLECLASS_ID);
	};

	//���������u������
	typedef CRunnable		*LPRunnable;

	/*******************************//*!
	@brief	�X���b�h�N���X

			�X���b�h�N���X�B<br>
			�p�����ꂽ�������������N���X��Run�����s�����X���b�h

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRunnableThread : public CThread {
	protected:
		/*******************//*!
		�����N���X
		*//********************/
		LPRunnable					m_pRunnable;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			pRunnable		�����̏�������

				@return			None
		*//**************************************************************************/
		CRunnableThread(LPRunnable pRunnable);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CRunnableThread();

		/*************************************************************************//*!
				@brief			�X���b�h�̓������s����<br>
								�R���X�g���N�^�ŗ^����ꂽ��CRunnable��Run�����s����B
				@param			None

				@return			None
		*//**************************************************************************/
		virtual void Run(void);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CRunnableThread,MOF_RUNNABLETHREADCLASS_ID);
	};
	
	/*******************************//*!
	@brief	�X���b�h�N���X

			�X���b�h�N���X�B<br>
			�p�����ꂽ�������������N���X��Run�����s�����X���b�h

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CCallbackThread : public CThread {
	protected:
		
		/*************************************************************************//*!
				@brief			�����֐����s�C���^�[�t�F�C�X
		*//**************************************************************************/
		struct ICallbackFuncImpl {
			virtual ~ICallbackFuncImpl(){}
			virtual void operator()() = 0;
		};
		/*************************************************************************//*!
				@brief			�����֐����s
		*//**************************************************************************/
		template < typename Func > struct CallbackFuncImpl : public ICallbackFuncImpl {
			Func						m_Func;
			CallbackFuncImpl(Func f) : m_Func(f){}
			virtual ~CallbackFuncImpl(){}
			virtual void operator()(){m_Func();}
		};
		/*******************//*!
		�����֐�
		*//********************/
		ICallbackFuncImpl*				m_pFunc;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			f				�����̏����R�[���o�b�N

				@return			None
		*//**************************************************************************/
		template < typename Func > CCallbackThread(Func f);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CCallbackThread();

		/*************************************************************************//*!
				@brief			�X���b�h�̓������s����<br>
								�R���X�g���N�^�ŗ^����ꂽ��CRunnable��Run�����s����B
				@param			None

				@return			None
		*//**************************************************************************/
		virtual void Run(void);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CCallbackThread,MOF_CALLBACKTHREADCLASS_ID);
	};

	#include	"Thread.inl"
}

#endif

//[EOF]