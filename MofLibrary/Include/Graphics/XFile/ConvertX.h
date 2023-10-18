/*************************************************************************//*!
					
					@file	ConvertX.h
					@brief	X�t�@�C���̕ϊ����s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTXFILE__H__

#define		__CONVERTXFILE__H__

//INCLUDE
#include	"AnalysX.h"
#include	"../MomCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�w�t�@�C���ϊ��N���X

			�e�L�X�g�`���̂w�t�@�C���̕ϊ����s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertX : public CWriteChunkFile {
	private:
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pModel		X�t�@�C��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMesh(LPXModel pModel);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pMesh		�������b�V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMesh(LPMOFXMESH pMesh);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pMesh		�������b�V��
				@param[in]		pOffset		�`��I�t�Z�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertVertex(LPMOFXMESH pMesh,LPMOFXMATERIALOFFSET pOffset);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pMesh		�������b�V��
				@param[in]		pOffset		�`��I�t�Z�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertIndex(LPMOFXMESH pMesh,LPMOFXMATERIALOFFSET pOffset);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pMaterial	�`��}�e���A��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMaterial(LPMOFXMATERIAL pMaterial);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pFrame		�t���[��
				@param[in]		pWeight		�E�F�C�g
				@param[in]		pMesh		���b�V��
				@param[in]		bCount		�{�[����
				@param[in]		mCount		���b�V����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertBone(LPMOFXMESHFRAME pFrame,LPMOFXSKINWEIGHTS* pWeight,LPMOFXMESH* pMesh,MofU32 bCount,MofU32 mCount);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pWeight		�E�F�C�g
				@param[in]		pMesh		���b�V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertWeight(LPMOFXSKINWEIGHTS pWeight,LPMOFXMESH pMesh);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pAC			�A�j���[�V����
				@param[in]		at			�A�j���[�V�����t���[��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertAnimation(LPMOFXANIMATIONSET pAC,MofFloat at);
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pAKey		�A�j���[�V����
				@param[in]		at			�A�j���[�V�����t���[��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertAnimationKey(LPMOFXANIMATIONKEY pAKey,MofFloat at);

	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertX();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertX();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pInName		���̓t�@�C����
				@param[out]		pOutName	�o�̓t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(LPCMofChar pInName,LPCMofChar pOutName);
		
		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CConvertX,MOF_CONVERTXCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertX.inl"

}

#endif	//__CONVERTXFILE__H__

//[EOF]