/*************************************************************************//*!
					
					@file	AnalysMQO.h
					@brief	MQO�t�@�C���̉�͂��s���N���X�B

															@author	CDW
															@date	2015.12.14
*//**************************************************************************/

//ONCE
#ifndef		__ANALYSMQOFILE__H__

#define		__ANALYSMQOFILE__H__

//INCLUDE
#include	"../../Common/ReadFile.h"
#include	"MQOModel.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MQO�t�@�C����̓N���X

			MQO�t�@�C���̉�͂��s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CAnalysMQO : public CReadTextFile {
	protected:
		/*************************************************************************//*!
				@brief			�`�����N���X�L�b�v����
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool SkipChunk(void);
		/*************************************************************************//*!
				@brief			�}�e���A���̉�͂��s��
				@param[out]		pMaterials	�}�e���A���z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysMaterial(LPMOFMQOMATERIALARRAY pMaterials);
		/*************************************************************************//*!
				@brief			�I�u�W�F�N�g�̉�͂��s��
				@param[out]		pObj		�I�u�W�F�N�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysObject(LPMOFMQOOBJECT pObj);
		/*************************************************************************//*!
				@brief			���_�̉�͂��s��
				@param[out]		pVertices	���_�z����o�͂���|�C���^�ւ̎Q��
				@param[out]		Count		���_��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysVertex(Vector3*& pVertices,MofU32& Count);
		/*************************************************************************//*!
				@brief			�ʂ̉�͂��s��
				@param[out]		pFaces	�ʔz����o�͂���|�C���^�ւ̎Q��
				@param[out]		Count		�ʐ�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AnalysFaces(LPMOFMQOFACE& pFaces,MofU32& Count);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CAnalysMQO();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAnalysMQO();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s��
				@param[in]		pName		�t�@�C����
				@param[out]		pModel		�o�̓��f��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Analys(const LPMofChar pName,LPMQOModel pModel);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CAnalysMQO,MOF_ANALYSMQOCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"AnalysMQO.inl"

}

#endif	//__ANALYSMQOFILE__H__

//[EOF]