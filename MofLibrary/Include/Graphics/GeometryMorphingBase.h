/*************************************************************************//*!
					
					@file	GeometryMorphingBase.h
					@brief	�W�I���g�����[�t�B���O���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GEOMETRYMORPHINGANIMATIONBASE__H__

#define		__GEOMETRYMORPHINGANIMATIONBASE__H__

//INCLUDE
#include	"GeometryMorphing.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���A�j���[�V�������N���X

			���b�V���A�j���[�V�������ƂȂ�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGeometryMorphing : public IGeometryMorphing {
	protected:
		/*******************//*!
		���O
		*//********************/
		CString								m_Name;
		/*******************//*!
		���_���W���[�t�B���O
		*//********************/
		LPGeometryMorphingPositionArray		m_pPosition;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGeometryMorphing();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[���b�V���A�j���[�V����

				@return			None
		*//**************************************************************************/
		CGeometryMorphing(const CGeometryMorphing& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGeometryMorphing();
		
		/*************************************************************************//*!
				@brief			���b�V���A�j���[�V�����̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[CGeometryMorphing<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual IGeometryMorphing* CreateCopyObject(void) const;

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
		/*************************************************************************//*!
				@brief			���_���W���[�t�B���O�ݒ�<br>
								�Â��f�[�^������ꍇ��������
				@param[in]		pArray			�ݒ肷��L�[
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetMorphingPosition(LPGeometryMorphingPositionArray pArray);

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
				@brief			���_���W���[�t�B���O�擾
				@param			None

				@return			���_���W���[�t�B���O
		*//**************************************************************************/
		virtual LPGeometryMorphingPositionArray GetMorphingPosition(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CGeometryMorphing,MOF_GEOMETRYMORPHINGANIMATIONCLASS_ID);
	};

	#include	"GeometryMorphingBase.inl"

}

#endif

//[EOF]