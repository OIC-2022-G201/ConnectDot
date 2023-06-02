/*************************************************************************//*!
					
					@file	RenderCommand.h
					@brief	�`��R�}���h�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__RENDERCOMMAND__H__

#define		__RENDERCOMMAND__H__

//INCLUDE
#include	"Graphics.h"

//DEFINE
#define		MOFRENDERCOMMAND_DEFAULTSIZE			(1024 * 1024)				//!<�R�}���h�o�b�t�@�̕W���T�C�Y

namespace Mof {

	/*******************************//*!
	@brief	�`��R�}���h�N���X

			�`��R�}���h�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IRenderCommand : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R�}���h�̎��s
				@param			None
				
				@return			None
		*//**************************************************************************/
		virtual MofBool Execute(void) = 0;

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTEQUAL(IRenderCommand, MOF_RENDERCOMMANDCLASS_ID);
	};
	//�|�C���^�u������
	typedef IRenderCommand*				LPRenderCommand;
	
	/*******************************//*!
	@brief	�`��R�}���h���X�g�N���X

			�`��R�}���h���X�g�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRenderCommandList : public IMofBase {
	protected:
		/*******************//*!
		�o�b�t�@
		*//********************/
		LPMofU8					m_pBuffer;
		/*******************//*!
		�o�b�t�@�T�C�Y
		*//********************/
		MofU32					m_Size;
		/*******************//*!
		�o�b�t�@�I�t�Z�b�g
		*//********************/
		MofU32					m_Offset;
			
		/*************************************************************************//*!
				@brief			�R�}���h�p�̃������m��
				@param			None

				@return			�������|�C���^
		*//**************************************************************************/
		template< typename T > LPMofVoid AllocateCommandSpace(void);
	public:
		
		/*******************************//*!
		@brief	�����R�}���h���s�p�|�C���^

				�����R�}���h���s�p�|�C���^

		@author	CDW
		*//********************************/
		class MOFLIBRARY_API CCommandPointer {
		private:
			/*******************//*!
			�Q�ƈʒu
			*//********************/
			LPMofU8					m_pPointer;
		public:
			/*************************************************************************//*!
					@brief			�R���X�g���N�^
			*//**************************************************************************/
			CCommandPointer(LPMofU8 pCurrent) : m_pPointer(pCurrent){}
			/*************************************************************************//*!
					@brief			���̈ʒu�Ɉړ�
			*//**************************************************************************/
			CCommandPointer& operator++(){ size_t size = *reinterpret_cast< MofU32* >(m_pPointer); m_pPointer += sizeof(MofU32) + size; return *this; }
			/*************************************************************************//*!
					@brief			�����R�}���h�ւ̃A�N�Z�X
			*//**************************************************************************/
			LPRenderCommand operator->(){ return reinterpret_cast< LPRenderCommand >(m_pPointer + sizeof(MofU32)); }
			/*************************************************************************//*!
					@brief			�����R�}���h�ւ̃A�N�Z�X
			*//**************************************************************************/
			void operator() (){ reinterpret_cast< LPRenderCommand >(m_pPointer + sizeof(MofU32))->Execute(); }
			/*************************************************************************//*!
					@brief			�|�C���^��r
			*//**************************************************************************/
			bool operator!=(LPCMofU8 rcp){ return (m_pPointer != rcp); }
		};

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		bs			�o�b�t�@�T�C�Y

				@return			None
		*//**************************************************************************/
		CRenderCommandList(MofU32 bs = MOFRENDERCOMMAND_DEFAULTSIZE);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CRenderCommandList();
		
		/*************************************************************************//*!
				@brief			�R�}���h�̒ǉ�
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		template < typename T > T* AddCommand(void);
		/*************************************************************************//*!
				@brief			�R�}���h�̒ǉ�
				@param[in]		p0			�ݒ�p�����[�^�[

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		template < typename T, typename P0 > T* AddCommand(P0& p0);
		/*************************************************************************//*!
				@brief			�R�}���h�̒ǉ�
				@param[in]		p0			�ݒ�p�����[�^�[
				@param[in]		p1			�ݒ�p�����[�^�[

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		template < typename T, typename P0, typename P1 > T* AddCommand(P0& p0, P1& p1);
		/*************************************************************************//*!
				@brief			�R�}���h�̒ǉ�
				@param[in]		p0			�ݒ�p�����[�^�[
				@param[in]		p1			�ݒ�p�����[�^�[
				@param[in]		p2			�ݒ�p�����[�^�[

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		template < typename T, typename P0, typename P1, typename P2 > T* AddCommand(P0& p0, P1& p1, P2& p2);
		/*************************************************************************//*!
				@brief			�R�}���h�̒ǉ�
				@param[in]		p0			�ݒ�p�����[�^�[
				@param[in]		p1			�ݒ�p�����[�^�[
				@param[in]		p2			�ݒ�p�����[�^�[
				@param[in]		p3			�ݒ�p�����[�^�[

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		template < typename T, typename P0, typename P1, typename P2, typename P3 > T* AddCommand(P0& p0, P1& p1, P2& p2, P3& p3);
		/*************************************************************************//*!
				@brief			�R�}���h�̒ǉ�
				@param[in]		p0			�ݒ�p�����[�^�[
				@param[in]		p1			�ݒ�p�����[�^�[
				@param[in]		p2			�ݒ�p�����[�^�[
				@param[in]		p3			�ݒ�p�����[�^�[
				@param[in]		p4			�ݒ�p�����[�^�[

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		template < typename T, typename P0, typename P1, typename P2, typename P3, typename P4 > T* AddCommand(P0& p0, P1& p1, P2& p2, P3& p3, P4& p4);
		/*************************************************************************//*!
				@brief			�R�}���h�̒ǉ�
				@param[in]		p0			�ݒ�p�����[�^�[
				@param[in]		p1			�ݒ�p�����[�^�[
				@param[in]		p2			�ݒ�p�����[�^�[
				@param[in]		p3			�ݒ�p�����[�^�[
				@param[in]		p4			�ݒ�p�����[�^�[
				@param[in]		p5			�ݒ�p�����[�^�[

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		template < typename T, typename P0, typename P1, typename P2, typename P3, typename P4, typename P5 > T* AddCommand(P0& p0, P1& p1, P2& p2, P3& p3, P4& p4, P5& p5);

		/*************************************************************************//*!
				@brief			�R�}���h�̎��s
				@param			None
				
				@return			None
		*//**************************************************************************/
		virtual MofBool Execute(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CRenderCommandList, MOF_RENDERCOMMANDLISTCLASS_ID);
	};
	//�|�C���^�u������
	typedef CRenderCommandList*				LPRenderCommandList;

	#include	"RenderCommand.inl"
}

#endif

//[EOF]