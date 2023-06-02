/*************************************************************************//*!
					
					@file	ConvertPsd.h
					@brief	PhotoShop��psd�t�@�C���̕ϊ����s�����߂̃N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTPSD__H__

#define		__CONVERTPSD__H__

//INCLUDE
#include	"../MosCommon.h"
#include	"../Texture.h"
#include	"PSDReader.h"

namespace Mof {
	
	/*******************************//*!
	@brief	PSD�t�@�C���ϊ��N���X

			PhotoShop��psd�t�@�C���̕ϊ����s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertPsd : public CWriteChunkFile {
	private:
		/*******************//*!
		PSD�t�@�C��
		*//********************/
		CPSDReader					m_Psd;
		
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(void);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pLayer		�ϊ����C���[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertSprite(LPPSDLAYERINFO pLayer);
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pLayer		�ϊ����C���[
				@param[in,out]	Offset		���݃I�t�Z�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertSprite(LPPSDLAYERINFO pLayer,MofU32& Offset);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertPsd();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertPsd();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pInName		���̓t�@�C����
				@param[out]		pOutName	�o�̓t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPCMofChar pOutName);
		
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CConvertPsd,MOF_CONVERTPSDCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertPsd.inl"

}

#endif	//__CONVERTPSD__H__

//[EOF]