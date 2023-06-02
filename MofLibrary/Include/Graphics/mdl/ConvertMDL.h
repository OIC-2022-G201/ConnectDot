/*************************************************************************//*!
					
					@file	ConvertMDL.h
					@brief	MDL�t�@�C���̕ϊ����s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTMDLFILE__H__

#define		__CONVERTMDLFILE__H__

//INCLUDE
#include	"../MomCommon.h"
#include	"MDLCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�l�c�k�t�@�C���ϊ��N���X

			�l�c�k�t�@�C���̕ϊ����s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertMDL : public CWriteChunkFile {
	private:
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertMDL();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertMDL();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pInName		���̓t�@�C����
				@param[out]		pOutName	�o�̓t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPCMofChar pOutName);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pVL			�`�撸�_
				@param[in]		pIL			�`��C���f�b�N�X
				@param[in]		pOffset		�`��I�t�Z�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertVertex(LPMBSMODELVERTEXLIST pVL,LPMBSMODELINDEXLIST pIL,LPMBSMODELINDEXOFFSET pOffset);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pIL			�`��C���f�b�N�X
				@param[in]		pOffset		�`��I�t�Z�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertIndex(LPMBSMODELINDEXLIST pIL,LPMBSMODELINDEXOFFSET pOffset);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pMaterial	�`��}�e���A��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMaterial(LPMBSMATERIAL pMaterial);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pWeight		�E�F�C�g
				@param[in]		pMesh		���b�V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertWeight(LPMBSBONEWEIGHTLIST pWeight,LPMBSMESH pMesh);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CConvertMDL,MOF_CONVERTMDLCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertMDL.inl"

}

#endif	//__CONVERTMDLFILE__H__

//[EOF]