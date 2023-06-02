/*************************************************************************//*!
					
					@file	ConvertMQO.h
					@brief	MQO�t�@�C���̕ϊ����s���N���X�B

															@author	CDW
															@date	2015.12.14
*//**************************************************************************/

//ONCE
#ifndef		__CONVERTMQOFILE__H__

#define		__CONVERTMQOFILE__H__

//INCLUDE
#include	"AnalysMQO.h"
#include	"../MomCommon.h"
#include	"../MeshContainer.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MQO�t�@�C���ϊ��N���X

			MQO�t�@�C���̕ϊ����s�����߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CConvertMQO : public CWriteChunkFile {
	private:
		/*************************************************************************//*!
				@brief			���b�V���t�@�C����ϊ�����
				@param[in]		pModel		MQO�t�@�C��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMesh(LPMQOModel pModel);
		/*************************************************************************//*!
				@brief			���_��ϊ�����
				@param[in]		TempVertices	���_�̔z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertVertex(MOFMQOTEMPVERTEXARRAY& TempVertices);
		/*************************************************************************//*!
				@brief			�C���f�b�N�X��ϊ�����
				@param[in]		Indices		�C���f�b�N�X�̔z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertIndex(CDynamicArray<MofU32>& Indices);
		/*************************************************************************//*!
				@brief			�}�e���A����ϊ�����
				@param[in]		pMQOMat		�}�e���A��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool ConvertMaterial(LPMOFMQOMATERIAL pMQOMat);

		/*************************************************************************//*!
				@brief			MQO�̃I�u�W�F�N�g���𒆊ԃW�I���g���f�[�^�ɕϊ�����
				@param[in]		pMQOObj			MQO�̃I�u�W�F�N�g���
				@param[in]		MaterialIndex	�Ώۂ̃}�e���A���C���f�b�N�X
				@param[out]		TempGeo			�o��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool ConvertTempGeometry(LPMOFMQOOBJECT pMQOObj,MofU32 MaterialIndex,MOFMQOTEMPGEOMETRY& TempGeo);
		/*************************************************************************//*!
				@brief			�~���[�̍쐬
				@param[in]		pMQOObj			MQO�̃I�u�W�F�N�g���
				@param[in,out]	TempGeometrys	�~���[�������s���W�I���g���z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool CreateMirror(LPMOFMQOOBJECT pMQOObj,MOFMQOTEMPGEOMETRYARRAY& TempGeometrys);
		/*************************************************************************//*!
				@brief			�w��̕ӂ��t�`���ǂ�������
				@param[in]		TempGeometrys		�W�I���g���z��
				@param[in]		FirstMirrorFaces	�~���[�����Œǉ����ꂽ�ŏ��̖�
				@param[in]		TargetA				�t�`���ǂ����𔻒肷��ӂ��\�������ڂ̒��_���W
				@param[in]		TargetB				�t�`���ǂ����𔻒肷��ӂ��\�������ڂ̒��_���W
				
				@return			TRUE		�t�`<br>
								����ȊO	�t�`�ł͂Ȃ�
		*//**************************************************************************/
		static MofBool IsBoundaryEdge(MOFMQOTEMPGEOMETRYARRAY &TempGeometrys,LPMOFMQOTEMPFACE* FirstMirrorFaces,const Vector3& TargetA,const Vector3& TargetB);
		/*************************************************************************//*!
				@brief			�@���̌v�Z
				@param[in]		pMQOObj			MQO�̃I�u�W�F�N�g���
				@param[in,out]	TempGeometrys	�@���̌v�Z���s���W�I���g���z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool CalculationNormal(LPMOFMQOOBJECT pMQOObj,MOFMQOTEMPGEOMETRYARRAY &TempGeometrys);
		/*************************************************************************//*!
				@brief			�ʂ̏W�܂�𒸓_�̔z��ƃC���f�b�N�X�̔z��ɕϊ�
				@param[in]		TempGeo		�ʂ̏W�܂�
				@param[out]		Vertices	���_�o�͔z��
				@param[out]		Indices		�C���f�b�N�X�o�͔z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool CreateTempVertexArray(MOFMQOTEMPGEOMETRY& TempGeo,MOFMQOTEMPVERTEXARRAY& Vertices,CDynamicArray<MofU32>& Indices);
		/*************************************************************************//*!
				@brief			���_�z�񂩂�w�肵�����_�Ɠ���̒��_������C���f�b�N�X���擾
				@param[in,out]	Vertices	���_�z��A���꒸�_��������Ȃ��ꍇ�����ɒǉ������
				@param[in]		TmpVert		�������_
				
				@return			���_�̃C���f�b�N�X
		*//**************************************************************************/
		static MofU32 GetTempVertexIndex(MOFMQOTEMPVERTEXARRAY& Vertices,const MOFMQOTEMPVERTEX& TmpVert);
		/*************************************************************************//*!
				@brief			���_�z�񂩂�w�肵�����_�Ɠ���̒��_������C���f�b�N�X���擾
				@param[in]		Vertices		���_�z��
				@param[in]		TargetVertex	�������_
				
				@return			���_�̃C���f�b�N�X<br>
								������Ȃ��ꍇ��MOF_U32_MAX��Ԃ�
		*//**************************************************************************/
		static MofU32 FindTempVertex(MOFMQOTEMPVERTEXARRAY& Vertices,const MOFMQOTEMPVERTEX& TargetVertex);

	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CConvertMQO();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CConvertMQO();
		/*************************************************************************//*!
				@brief			�t�@�C�����J���ĉ�͂��s���A�Ǝ��`���ŏo�͂��s��
				@param[in]		pInName		���̓t�@�C����
				@param[in]		pOutName	�o�̓t�@�C����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool Convert(const LPMofChar pInName,const LPMofChar pOutName);
		
		/*************************************************************************//*!
				@brief			MQO�̖ʍ\���̂��璸�_���擾����
				@param[in]		Face		MQO�̖ʍ\����
				@param[in]		Index		���_�̃C���f�b�N�X
				
				@return			�ʂ��\�����钸�_
		*//**************************************************************************/
		static LPMOFMQOTEMPVERTEX GetFaceVertex(MOFMQOTEMPFACE& Face,MofU32 Index);
		/*************************************************************************//*!
				@brief			MQO�̖ʍ\���̂���O�p�`���擾����
				@param[in]		Face		MQO�̖ʍ\����
				@param[in]		Index		�O�p�`�̃C���f�b�N�X
				@param[out]		pOut		�O�p�`�̊e���_���i�[���钷��3�̔z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool GetFaceTriangle(MOFMQOTEMPFACE& Face,MofU32 Index,LPMOFMQOTEMPVERTEX* pOut);
		/*************************************************************************//*!
				@brief			MQO�̖ʍ\���̂���ӂ��擾����
				@param[in]		Face		MQO�̖ʍ\����
				@param[in]		Index		�ӂ̃C���f�b�N�X
				@param[out]		pOutVertA	�ӂ��\�������ڂ̒��_
				@param[out]		pOutVertB	�ӂ��\�������ڂ̒��_
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool GetFaceEdge(MOFMQOTEMPFACE& Face,MofU32 Index,LPMOFMQOTEMPVERTEX& pOutVertA,LPMOFMQOTEMPVERTEX& pOutVertB);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CConvertMQO,MOF_CONVERTMQOCLASS_ID);
	};

	//INLINE INCLUDE
	#include	"ConvertMQO.inl"

}

#endif	//__CONVERTMQOFILE__H__

//[EOF]