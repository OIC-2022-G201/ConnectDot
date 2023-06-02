/*************************************************************************//*!
					
					@file	PackFile.h
					@brief	�t�@�C���p�b�L���O�N���X

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/


//ONCE
#ifndef		__PACKFILE__H__

#define		__PACKFILE__H__

//INCLUDE
#include	"ReadFile.h"
#include	"WriteFile.h"
#include	"DynamicArray.h"

//DEFINE

//!�R�s�[�̃o�b�t�@�T�C�Y
#define		MOF_PACKFILE_COPYBUFFERSIZE		1024
//!�t�@�C����
#define		MOF_PACKFILE_HEADERPATH			260

namespace Mof {
	
	//TYPEDEF STRUCT

	/*******************************//*!
	@brief	�p�b�N�t�@�C�����̃t�@�C�����w�b�_�[

			�p�b�N�t�@�C�����̃t�@�C�����w�b�_�[�\����

	@author	CDW
	*//********************************/
	typedef struct tag_PackFileHeader {
		MofChar				Name[MOF_PACKFILE_HEADERPATH];		//!<�t�@�C����
		MofU32				Size;								//!<�t�@�C���T�C�Y
		MofU32				StartAdress;						//!<�t�@�C���̊J�n�A�h���X
	}PackFileHeader,*LPPackFileHeader;
	
	/*******************************//*!
	@brief	�p�b�N�t�@�C��

			�p�b�N�t�@�C���������N���X

	@author	CDW
	*//********************************/
	class CPackFile : public IMofNamedObject {
	private:
		/*******************//*!
		���O
		*//********************/
		CString						m_Name;
		/*******************//*!
		�t�@�C����
		*//********************/
		MofU32						m_FileNum;
		/*******************//*!
		�t�@�C�����
		*//********************/
		LPPackFileHeader			m_pPackHeader;
		
		/*************************************************************************//*!
				@brief			�p�b�N�������������֐�
				@param[in]		Name			�쐬�f�B���N�g����

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool CreateDirectory(LPCMofChar Name);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CPackFile();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[

				@return			None
		*//**************************************************************************/
		CPackFile(const CPackFile& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CPackFile();

		/*************************************************************************//*!
				@brief			�p�b�N�t�@�C���쐬
				@param[in]		InFile			�p�b�N�Ɏ��߂�t�@�C�����̔z��
				@param[in]		InCount			�p�b�N�Ɏ��߂�t�@�C����
				@param[in]		OutFile			�o�̓p�b�N�t�@�C����
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool Packing(LPMofChar* InFile,MofU32 InCount,LPCMofChar OutFile);
		/*************************************************************************//*!
				@brief			�p�b�N�t�@�C���쐬<br>
								�p�b�N�t�@�C�����̃t�@�C�����Ƀp�X�̏����܂߂Ȃ�
				@param[in]		InFile			�p�b�N�Ɏ��߂�t�@�C�����̔z��
				@param[in]		InCount			�p�b�N�Ɏ��߂�t�@�C����
				@param[in]		OutFile			�o�̓p�b�N�t�@�C����
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool PackingNoPath(LPMofChar* InFile,MofU32 InCount,LPCMofChar OutFile);
		/*************************************************************************//*!
				@brief			�p�b�N��������
				@param[in]		file			�����t�@�C����

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool Split(LPCMofChar file);

		/*************************************************************************//*!
				@brief			�ǂݍ���<br>
								�p�b�N�t�@�C���̃w�b�_�[��ǂݍ���
				@param[in]		file			�t�@�C����

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool Load(LPCMofChar file);
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
		/*************************************************************************//*!
				@brief			�p�b�N�t�@�C�����ɕۑ�����Ă���t�@�C����
				@param			None

				@return			�p�b�N�t�@�C�����ɕۑ�����Ă���t�@�C�����̎擾
		*//**************************************************************************/
		MofU32 GetFileCount(void) const;
		/*************************************************************************//*!
				@brief			�p�b�N�t�@�C���w�b�_�[
				@param			None

				@return			�p�b�N�t�@�C���w�b�_�[�̎擾
		*//**************************************************************************/
		LPPackFileHeader GetFileInfo(void);
		/*************************************************************************//*!
				@brief			�p�b�N�t�@�C���w�b�_�[
				@param[in]		file			�t�@�C����

				@return			�p�b�N�t�@�C���w�b�_�[�̎擾
		*//**************************************************************************/
		LPPackFileHeader GetFileInfo(LPCMofChar file);
		/*************************************************************************//*!
				@brief			�p�b�N�t�@�C���w�b�_�[
				@param[in]		No				�t�@�C���ԍ�

				@return			�p�b�N�t�@�C���w�b�_�[�̎擾
		*//**************************************************************************/
		LPPackFileHeader GetFileInfo(MofU32 No);
		/*************************************************************************//*!
				@brief			�t�@�C���f�[�^
				@param[in]		file			�t�@�C����

				@return			�t�@�C���f�[�^�̎擾
		*//**************************************************************************/
		LPMofVoid GetFileData(LPCMofChar file);
		/*************************************************************************//*!
				@brief			�t�@�C���f�[�^
				@param[in]		file			�t�@�C����
				@param[out]		pData			�o�̓f�[�^
				
				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		MofBool GetFileData(LPCMofChar file,LPMofVoid pData);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CPackFile,MOF_PACKFILECLASS_ID);
	};

	//TYPEDEF
	typedef CPackFile* LPPackFile;
	//���X�g�u������
	typedef CDynamicArray< LPPackFile > CPackFileArray,*LPPackFileArray;

	//INLINE INCLUDE
	#include	"PackFile.inl"

}

#endif		//__PACKFILE__H__

//[EOF]