/*************************************************************************//*!
					
					@file	SoundUtilities.h
					@brief	�T�E���h�֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SOUNDUTILITIES__H__

#define		__SOUNDUTILITIES__H__

//INCLUDE
#include	"../Sound/Sound.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�T�E���h�֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X

			�T�E���h�֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSoundUtilities {
	private:
		/*******************//*!
		�T�E���h
		*//********************/
		static LPSound				m_pSound;
	public:
#ifdef		MOFLIB_WINDOWS_DESKTOP
		/*************************************************************************//*!
				@brief			WAVE�t�@�C���̃`�����N��ǂݍ���
				@param[in]		hmmio			�t�@�C���n���h��
				@param[out]		mmdata			MMINFO
				@param[out]		mmriff			MMINFO
				@param[out]		pcwf			WAVEFORMAT
		
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool ReadWaveFormat(HMMIO hmmio,MMCKINFO* mmdata,MMCKINFO* mmriff,WAVEFORMATEX** pcwf);
		/*************************************************************************//*!
				@brief			WAVE�t�@�C���̃f�[�^��ǂݍ���
				@param[in]		hmmio			�t�@�C���n���h��
				@param[in]		pCkIn			MMINFO
				@param[in]		pRiff			MMINFO
				@param[in]		Size			�ǂݍ��݃T�C�Y
				@param[out]		pData			�ǂݍ��݃f�[�^
		
				@return			�ǂݍ��񂾃o�C�g��
		*//**************************************************************************/
		static MofU32 ReadWave(HMMIO hmmio,MMCKINFO* pCkIn,MMCKINFO* pRiff,MofU32 Size,LPMofVoid pData);
		/*************************************************************************//*!
				@brief			WAVE�t�@�C���̓ǂݍ��݈ʒu������������
				@param[in]		hmmio			�t�@�C���n���h��
				@param[in]		mmdata			MMINFO
				@param[in]		mmriff			MMINFO
		
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool ResetWavePosition(HMMIO hmmio,MMCKINFO* mmdata,MMCKINFO* mmriff);
		/*************************************************************************//*!
				@brief			WAVE�t�@�C���̓ǂݍ��݈ʒu������������
				@param[in]		hmmio			�t�@�C���n���h��
				@param[in]		mmdata			MMINFO
				@param[in]		mmriff			MMINFO
				@param[in]		off				�I�t�Z�b�g�ʒu

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool SetWavePosition(HMMIO hmmio, MMCKINFO* mmdata, MMCKINFO* mmriff, MofU32 off);
#endif

#ifdef		MOFLIB_WINDOWS
		/*************************************************************************//*!
				@brief			OGG�t�@�C����ǂݍ���<br>
								�ǂݍ��񂾃t�@�C���̃o�b�t�@�A�T�C�Y�A�t�H�[�}�b�g���o�͂���B
				@param[in]		pFile			�ǂݍ��݃t�@�C��
				@param[out]		pData			�o�̓o�b�t�@
				@param[out]		Size			�o�̓T�C�Y
				@param[out]		pcwf			�o�̓t�H�[�}�b�g
		
				@return			TRUE			����I��<br>
								FALSE			�G���[
		*//**************************************************************************/
		static MofBool ReadOGG(CReadBinaryFile* pFile,LPMofU8* pData,MofU32* Size,WAVEFORMATEX* pcwf);
		/*************************************************************************//*!
				@brief			�J�����t�@�C������OGG�t�@�C����ǂݍ���<br>
								�ǂݍ��񂾃t�@�C���A�T�C�Y�A�t�H�[�}�b�g���o�͂���B
				@param[in]		fp				�ǂݍ��݃t�@�C��
				@param[out]		pFile			�o�̓t�@�C��
				@param[out]		Size			�o�̓T�C�Y
				@param[out]		pcwf			�o�̓t�H�[�}�b�g
		
				@return			TRUE			����I��<br>
								FALSE			�G���[
		*//**************************************************************************/
		static MofBool ReadOGG(FILE* fp,OggVorbis_File* pFile,MofU32* Size,WAVEFORMATEX* pcwf);
		/*************************************************************************//*!
				@brief			�J�����t�@�C������OGG�t�@�C����ǂݍ���<br>
								�ǂݍ��񂾃t�@�C���A�T�C�Y�A�t�H�[�}�b�g���o�͂���B
				@param[in]		fp				�ǂݍ��݃t�@�C��
				@param[out]		pFile			�o�̓t�@�C��
				@param[out]		Size			�o�̓T�C�Y
				@param[out]		pcwf			�o�̓t�H�[�}�b�g
		
				@return			TRUE			����I��<br>
								FALSE			�G���[
		*//**************************************************************************/
		static MofBool ReadOGG(CReadBinaryFile* fp,OggVorbis_File* pFile,MofU32* Size,WAVEFORMATEX* pcwf);
		/*************************************************************************//*!
				@brief			OGG�t�@�C������w��T�C�Y�����ǂݍ���<br>
								�T�C�Y�ǂݍ��݈ȑO�Ƀo�b�t�@�̏I�[�܂œ��B�����ꍇLoopPos�܂ŃI�t�Z�b�g���ړ�������B
				@param[out]		pData			�o�̓f�[�^
				@param[in]		pFile			�ǂݍ��݃t�@�C��
				@param[in]		Size			�ǂݍ��݃T�C�Y
				@param[in]		LoopPos			���[�v�|�C���g
		
				@return			TRUE			����I��<br>
								FALSE			�G���[
		*//**************************************************************************/
		static MofBool ReadOGG(LPMofU8 pData,OggVorbis_File* pFile,MofU32 Size,MofFloat LoopPos);
#endif
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�T�E���h�C���^�[�t�F�C�X��ݒ肷��
				@param[in]		pg				�T�E���h�C���^�[�t�F�C�X

				@return			None
		*//**************************************************************************/
		static void SetSound(LPSound pg);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�T�E���h�C���^�[�t�F�C�X���擾����
				@param			None

				@return			�T�E���h�C���^�[�t�F�C�X
		*//**************************************************************************/
		static LPSound GetSound(void);

	private:
		//�쐬���֎~����
		CSoundUtilities(){};
		CSoundUtilities(const CSoundUtilities& pObj){};
	};
					
	#include	"SoundUtilities.inl"
}

#endif

//[EOF]