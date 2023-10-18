/*************************************************************************//*!
					
					@file	XAudioStreamingSoundBuffer.h
					@brief	XAudio2�ł̊e��T�E���h�o�b�t�@�̏������s�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__XAUDIOSTREAMINGSOUNDBUFFER__H__

#define		__XAUDIOSTREAMINGSOUNDBUFFER__H__

//INCLUDE
#include	"../SoundBufferBase.h"

namespace Mof {

#ifdef		MOFLIB_WINDOWS_DESKTOP
	/*******************************//*!
	@brief	WAVE�X�g���[�~���O�Đ��p�X�g���[��

			WAVE�X�g���[�~���O�Đ��p�X�g���[���\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_WAVESTREAM {
		HMMIO						file;				//!<FILE
		WAVEFORMATEX*				pcwf;				//!<WAVEFORMAT
		MMCKINFO					CkIn;				//!<MMINFO
		MMCKINFO					CkRiffIn;			//!<MMINFO

		~tag_WAVESTREAM(){
			mmioClose(file,0);
			MOF_SAFE_FREE(pcwf,"WAVESTREAM");
		}
	}WAVESTREAM,*LPWAVESTREAM;
#endif

	/*******************************//*!
	@brief	OGG�X�g���[�~���O�Đ��p�X�g���[��

			OGG�X�g���[�~���O�Đ��p�X�g���[���\���́B

	@author	CDW
	*//********************************/
	typedef struct tag_OGGSTREAM {
		CReadBinaryFile				bf;					//!<FILE
		OggVorbis_File				file;				//!<FILE
		WAVEFORMATEX				pcwf;				//!<WAVEFORMAT

		~tag_OGGSTREAM() {
			bf.Release();
			ov_clear(&file);
		}
	}OGGSTREAM,*LPOGGSTREAM;

	/*******************************//*!
	@brief	XAudio2�ł̃T�E���h�o�b�t�@�N���X

			XAudio2�ł̃T�E���h�o�b�t�@�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CXAudioStreamingSoundBuffer : public CSoundBufferBase {
	protected:
		/*******************//*!
		�T�E���h�o�b�t�@
		*//********************/
		IXAudio2SourceVoice*		m_pBuffer;
		/*******************//*!
		1�b�̃o�C�g��
		*//********************/
		MofU32						m_BytesPerSec;
		/*******************//*!
		�Đ��J�[�\��
		*//********************/
		MofU32						m_AddedDataSize;
		/*******************//*!
		�Đ��J�[�\��
		*//********************/
		MofU32						m_AddedDataNo;
#ifdef		MOFLIB_WINDOWS_DESKTOP
		/*******************//*!
		�Đ��p�X�g���[��
		*//********************/
		LPWAVESTREAM				m_pWaveStream;
		/*******************//*!
		�Đ��p�X�g���[��
		*//********************/
		LPMp3File					m_pMp3Stream;
#else
		/*******************//*!
		�Đ��p�X�g���[��
		*//********************/
		LPUWPStream					m_pStream;
#endif
		/*******************//*!
		�Đ��p�X�g���[��
		*//********************/
		LPOGGSTREAM					m_pOggStream;
		/*******************//*!
		�Đ��t���O
		*//********************/
		MofBool						m_bPlay;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CXAudioStreamingSoundBuffer();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj			�R�s�[�o�b�t�@

				@return			None
		*//**************************************************************************/
		CXAudioStreamingSoundBuffer(const CXAudioStreamingSoundBuffer& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CXAudioStreamingSoundBuffer();

		/*************************************************************************//*!
				@brief			�T�E���h�̓ǂݍ���
				@param[in]		pName			�t�@�C����
				@param[in]		Flags			�ǂݍ��݃t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,const MofU32 Flags = 0);
		/*************************************************************************//*!
				@brief			�T�E���h�̓ǂݍ���
				@param[in]		pName			���O
				@param[in]		pData			�������A�h���X
				@param[in]		Size			�T�C�Y
				@param[in]		Flags			�ǂݍ��݃t���O
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size,const MofU32 Flags = 0);
		
		/*************************************************************************//*!
				@brief			�T�E���h�̍X�V
				@param			None
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Update(void);
		/*************************************************************************//*!
				@brief			�T�E���h�̍Đ�
				@param			None
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Play(void);
		/*************************************************************************//*!
				@brief			�T�E���h�̍Đ�
				@param[out]		on				�Đ��J�n�ԍ�
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Play(MofU32& on);
		
		/*************************************************************************//*!
				@brief			�T�E���h�̈ꎞ��~
				@param			None
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Pause(void);
		/*************************************************************************//*!
				@brief			�T�E���h�̈ꎞ��~
				@param[in]		n				�Đ��ԍ�
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Pause(MofU32 n);
		/*************************************************************************//*!
				@brief			�T�E���h�̍ĊJ
				@param			None
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Resume(void);
		/*************************************************************************//*!
				@brief			�T�E���h�̍ĊJ
				@param[in]		n				�Đ��ԍ�
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Resume(MofU32 n);
		
		/*************************************************************************//*!
				@brief			�T�E���h�̒�~
				@param			None
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Stop(void);
		/*************************************************************************//*!
				@brief			�T�E���h�̒�~
				@param[in]		n				�Đ��ԍ�
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Stop(MofU32 n);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			�Đ���������
				@param			None

				@return			TRUE			�Đ����Ă���<br>
								FALSE			�Đ����Ă��Ȃ�
		*//**************************************************************************/
		virtual MofBool IsPlay(void);
		/*************************************************************************//*!
				@brief			�Đ���������
				@param[in]		n				�Đ��ԍ�

				@return			TRUE			�Đ����Ă���<br>
								FALSE			�Đ����Ă��Ȃ�
		*//**************************************************************************/
		virtual MofBool IsPlay(MofU32 n);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�Đ����ʐݒ�
				@param[in]		Vol			����(0.0(����)�`1.0(�ʏ�))
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetVolume(MofFloat Vol);
		/*************************************************************************//*!
				@brief			�Đ����ʐݒ�
				@param[in]		Vol			����(0.0(����)�`1.0(�ʏ�))
				@param[in]		n			�Đ��ԍ�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetVolume(MofFloat Vol,MofU32 n);
		/*************************************************************************//*!
				@brief			�Đ��s�b�`�ݒ�
				@param[in]		Pitch		�s�b�`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetPitch(MofFloat Pitch);
		/*************************************************************************//*!
				@brief			�����Đ����̐ݒ�
				@param[in]		cnt			��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBufferCount(MofU32 cnt);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�T�E���h�o�b�t�@�擾
				@param			None

				@return			�T�E���h�o�b�t�@
		*//**************************************************************************/
		virtual MofSoundBuffer GetBuffer(void);
		/*************************************************************************//*!
				@brief			���t�@�C���̎��Ԏ擾
				@param			None
				
				@return			���t�@�C���̎���
		*//**************************************************************************/
		virtual MofFloat GetPlayTime(void);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS(CXAudioStreamingSoundBuffer,MOF_XAUDIOSTREAMINGSOUNDBUFFERCLASS_ID);
	};

	#include	"XAudioStreamingSoundBuffer.inl"

	//�u������
	typedef CXAudioStreamingSoundBuffer		CStreamingSoundBuffer;
}

#endif

//[EOF]