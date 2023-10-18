/*************************************************************************//*!
					
					@file	UdpSocket.h
					@brief	UDP�\�P�b�g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__UDPSOCKET__H__

#define		__UDPSOCKET__H__

//INCLUDE
#include	"SocketBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	UDP�\�P�b�g�N���X

			UDP�\�P�b�g�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CUdpSocket : public CSocket {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CUdpSocket();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CUdpSocket();

		/*************************************************************************//*!
				@brief			�\�P�b�g�̏�����
				@param			None

				@return			TRUE			����I��<br>
								����ȊO		�������G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Initialize(void);
		
		/*************************************************************************//*!
				@brief			�\�P�b�g�̃o�C���h
				@param[in]		port			�|�[�g�ԍ�

				@return			TRUE			����I��<br>
								����ȊO		�������G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool Bind(const MofU16 port);
		/*************************************************************************//*!
				@brief			�\�P�b�g�̃o�C���h
				@param[in]		addr			�ڑ��p�A�h���X�\����

				@return			TRUE			����I��<br>
								����ȊO		�������G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool Bind(const MOFSOCKETADDR& addr);
		
		/*************************************************************************//*!
				@brief			�f�[�^�̑��M
				@param[in]		addr			���M�A�h���X
				@param[in]		pBuf			���M�o�b�t�@
				@param[in]		size			���M�o�b�t�@�T�C�Y

				@return			���M�T�C�Y
		*//**************************************************************************/
		MofU32 Send(const MOFSOCKETADDR& addr, LPCMofVoid pBuf, const MofU32 size);
		/*************************************************************************//*!
				@brief			�f�[�^�̑��M
				@param[in]		addr			���M�A�h���X
				@param[in]		port			���M�|�[�g
				@param[in]		pBuf			���M�o�b�t�@
				@param[in]		size			���M�o�b�t�@�T�C�Y

				@return			���M�T�C�Y
		*//**************************************************************************/
		MofU32 Send(MofU32 addr, MofU16 port, LPCMofVoid pBuf, const MofU32 size);

		/*************************************************************************//*!
				@brief			�f�[�^�̎�M
				@param[in]		pBuf			��M�o�b�t�@
				@param[in]		size			��M�o�b�t�@�T�C�Y
				@param[out]		addr			��M�A�h���X

				@return			��M�T�C�Y
		*//**************************************************************************/
		MofU32 Receive(LPMofVoid pBuf, const MofU32 size, MOFSOCKETADDR& addr);
		/*************************************************************************//*!
				@brief			�f�[�^�̎�M
				@param[in]		pBuf			��M�o�b�t�@
				@param[in]		size			��M�o�b�t�@�T�C�Y
				@param[in]		bKeep			��M�o�b�t�@�ۑ��t���O
				@param[out]		addr			��M�A�h���X

				@return			��M�T�C�Y
		*//**************************************************************************/
		MofU32 Receive(LPMofVoid pBuf, const MofU32 size, MofBool bKeep, MOFSOCKETADDR& addr);

		/*************************************************************************//*!
				@brief			�\�P�b�g�̃N���[�Y
				@param			None

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Close(void);
		
		/*************************************************************************//*!
				@brief			��M�f�[�^����
				@param			None

				@return			TRUE			��M�f�[�^������<br>
								����ȊO		��M�f�[�^�͂Ȃ��B
		*//**************************************************************************/
		MofBool IsReceive(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CUdpSocket, MOF_UDPSOCKETCLASS_ID);
	};

#include	"UdpSocket.inl"

}

#endif

//[EOF]