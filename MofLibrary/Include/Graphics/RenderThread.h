/*************************************************************************//*!
					
					@file	RenderThread.h
					@brief	�}���`�X���b�h�p�`��X���b�h

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__RENDERTHREAD__H__

#define		__RENDERTHREAD__H__

//INCLUDE
#include	"../Common/Queue.h"
#include	"../Common/Thread.h"
#include	"RenderCommand.h"

namespace Mof {

	//�`��R�}���h�L���[
	typedef CQueue< LPRenderCommandList > CRenderCommandQueue, *LPRenderCommandQueue;

	/*******************************//*!
	@brief	���b�N

			���b�N

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRenderThread : public CThread {
	protected:
		/*******************//*!
		�X���b�h�p���t���O
		*//********************/
		MofBool						m_bRunnable;
		/*******************//*!
		�R�}���h�L���[
		*//********************/
		CRenderCommandQueue			m_CommandQueue;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CRenderThread();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CRenderThread();

		/*************************************************************************//*!
				@brief			�X���b�h�̓������s����
				@param			None

				@return			None
		*//**************************************************************************/
		virtual void Run(void);
		/*************************************************************************//*!
				@brief			�R�}���h���v�b�V������
				@param[in]		pCmd			�ǉ��R�}���h

				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool PushCommand(LPRenderCommandList pCmd);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			�R�}���h�o�^����
				@param			�R�}���h�o�^������

				@return			TRUE			�o�^�L<br>
								����ȊO		�o�^�Ȃ��B
		*//**************************************************************************/
		virtual MofBool IsCommand(void);
		/*************************************************************************//*!
				@brief			�R�}���h�����ҋ@

				@return			TRUE			�ҋ@����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool WaitCommandFlush(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CRenderThread, MOF_RENDERTHREADCLASS_ID);
	};

	//�u������
	typedef CRenderThread*		LPRenderThread;

	#include	"RenderThread.inl"
}

#endif

//[EOF]