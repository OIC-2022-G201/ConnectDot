/*************************************************************************//*!
					
					@file	Camera.h
					@brief	�J�������C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CAMERA__H__

#define		__CAMERA__H__

//INCLUDE
#include	"Graphics.h"

namespace Mof {

	/*******************************//*!
	@brief	���W�n�^�C�v��

			�S�̂̍��W�n�̃^�C�v�̗�

	@author	CDW
	*//********************************/
	typedef enum CoordinateType {
		COORDINATETYPE_LEFTHAND,							//!<������W�n
		COORDINATETYPE_RIGHTHAND,							//!<�E����W�n
	}CoordinateType;
	
	
	/*******************************//*!
	@brief	�J�������C���^�[�t�F�C�X

			�J�������ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API ICamera : public IMofNamedObject {
	public:
		/*******************************//*!
		@brief	�v���W�F�N�V�����^�C�v��

				�v���W�F�N�V�����^�C�v�̗�

		@author	CDW
		*//********************************/
		typedef enum ProjectionType {
			PROJECTION_PERSPECTIVEFOV,						//!<�p�[�X�y�N�e�B�u
			PROJECTION_PERSPECTIVE,							//!<�p�[�X�y�N�e�B�u
			PROJECTION_ORTHO,								//!<���ˉe
		}ProjectionType;
		
		/*******************************//*!
		@brief	�v���W�F�N�V�������\����

				�v���W�F�N�V�����s��̐ݒ�ɕK�v�ȏ����i�[����\����

		@author	CDW
		*//********************************/
		typedef struct tag_PROJECTION {
			ProjectionType				Type;				//!<�^�C�v
			MofFloat					Fov;				//!<����p
			MofFloat					Aspect;				//!<�A�X�y�N�g��
			MofFloat					Width;				//!<��
			MofFloat					Height;				//!<����
			MofFloat					Near;				//!<�ߕ���
			MofFloat					Far;				//!<������
		}Projection,*LPProjection;
		
		/*******************************//*!
		@brief	��������\����

				����������i�[����\����

		@author	CDW
		*//********************************/
		typedef struct tag_VIEWFRUSTUM {
			MofFloat					Near;				//!<�ߕ���
			MofFloat					Far;				//!<������
			CVector3					TopPlane;			//�㕽��
			CVector3					BottomPlane;		//������
			CVector3					LeftPlane;			//������
			CVector3					RightPlane;			//�E����

			tag_VIEWFRUSTUM() :
			Near(0.0f) ,
			Far(0.0f) ,
			TopPlane() ,
			BottomPlane() ,
			LeftPlane() ,
			RightPlane() {
			}
			tag_VIEWFRUSTUM(const tag_VIEWFRUSTUM& obj) :
			Near(obj.Near) ,
			Far(obj.Far),
			TopPlane(obj.TopPlane),
			BottomPlane(obj.BottomPlane),
			LeftPlane(obj.LeftPlane),
			RightPlane(obj.RightPlane) {
			}
		}ViewFrustum,*LPViewFrustum;

	protected:
	public:
		/*************************************************************************//*!
				@brief			�J�����̍X�V<br>
								�ݒ肳��Ă����񂩂�J�����ɕK�v�Ȋe��s����v�Z���Ȃ���
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Update(void) = 0;

		/*************************************************************************//*!
				@brief			Target�ւ̒����s��v�Z
				@param[in]		Pos			���W
				@param[in]		Target		�������W
				@param[in]		Up			����x�N�g��

				@return			None
		*//**************************************************************************/
		virtual void LookAt(const Vector3& Pos,const Vector3& Target,const Vector3& Up) = 0;
		
		/*************************************************************************//*!
				@brief			�ˉe�s��v�Z
				@param[in]		fov			����p
				@param[in]		Aspect		�A�X�y�N�g��
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���

				@return			None
		*//**************************************************************************/
		virtual void PerspectiveFov(const MofFloat fov,const MofFloat Aspect,const MofFloat Near,const MofFloat Far) = 0;
		/*************************************************************************//*!
				@brief			�p�[�X�y�N�e�B�u�ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���

				@return			None
		*//**************************************************************************/
		virtual void Perspective(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far) = 0;
		/*************************************************************************//*!
				@brief			���ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���

				@return			None
		*//**************************************************************************/
		virtual void Ortho(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far) = 0;

		/*************************************************************************//*!
				@brief			3D��ԏ�̍��W���X�N���[�����W�ɕϊ�����
				@param[in]		v			3D���W
				@param[out]		OutX		X���W�o��
				@param[out]		OutY		Y���W�o��
				@param[out]		OutZ		Z���W�o��
				@param[out]		OutW		W���W�o��

				@return			None
		*//**************************************************************************/
		virtual void WorldToScreen(const Vector3& v,MofFloat* OutX,MofFloat* OutY,MofFloat* OutZ = NULL,MofFloat* OutW = NULL) = 0;
		/*************************************************************************//*!
				@brief			�X�N���[�����W��3D��ԏ�̃��C�ɕϊ�����
				@param[in]		px			X���W
				@param[in]		py			Y���W
				@param[out]		Out			3D���W�o��

				@return			None
		*//**************************************************************************/
		virtual void ScreenToWorld(const MofFloat px,const MofFloat py,Vector3& Out) = 0;
		/*************************************************************************//*!
				@brief			�X�N���[�����W��3D��ԏ�̃��C�ɕϊ�����
				@param[in]		p			���W
				@param[out]		Out			3D���W�o��

				@return			None
		*//**************************************************************************/
		virtual void ScreenToWorld(const Vector2& p,Vector3& Out) = 0;
		/*************************************************************************//*!
				@brief			�t���X�^�����ɑ��݂��邩���肷��
				@param[in]		p			���W
				@param[out]		r			���a
				
				@return			TRUE		����<br>
								FALSE		�Ȃ�
		*//**************************************************************************/
		virtual MofBool IsFrustumInside(const Vector3& p,MofFloat r) = 0;
		/*************************************************************************//*!
				@brief			Y������r���{�[�h�s��v�Z
				@param[out]		Out			���ʍs��

				@return			None
		*//**************************************************************************/
		virtual void CalculateYBillBoardMatrix(CMatrix33& Out) = 0;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���W�n�ݒ�
				@param[in]		c			���W�n
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetCoordinateType(const CoordinateType c) = 0;
		/*************************************************************************//*!
				@brief			�r���[�|�[�g�ݒ�<br>
								��ʃT�C�Y���玩���I�ɐݒ���s���B
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetViewPort(void) = 0;
		/*************************************************************************//*!
				@brief			�r���[�|�[�g�ݒ�
				@param[in]		r			��ʋ�`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetViewPort(const Rectangle& r) = 0;
		/*************************************************************************//*!
				@brief			�r���[�|�[�g�ݒ�
				@param[in]		px			X�ʒu
				@param[in]		py			Y�ʒu
				@param[in]		w			��
				@param[in]		h			����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetViewPort(const MofFloat px,const MofFloat py,const MofFloat w,const MofFloat h) = 0;
		/*************************************************************************//*!
				@brief			�r���[�|�[�g�ݒ�
				@param[in]		px			X�ʒu
				@param[in]		py			Y�ʒu
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		n			�ŋ�
				@param[in]		f			�ŉ�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetViewPort(const MofFloat px,const MofFloat py,const MofFloat w,const MofFloat h,const MofFloat n,const MofFloat f) = 0;
		/*************************************************************************//*!
				@brief			�r���[�|�[�g�ݒ�
				@param[in]		v			�r���[�|�[�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetViewPort(const ViewPort& v) = 0;
		/*************************************************************************//*!
				@brief			�J�������W�ݒ�
				@param[in]		v			�ݒ���W
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetViewPosition(const Vector3& v) = 0;
		/*************************************************************************//*!
				@brief			�J�������W�ݒ�
				@param[in]		x			�ݒ�X���W
				@param[in]		y			�ݒ�Y���W
				@param[in]		z			�ݒ�Z���W
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetViewPosition(MofFloat x,MofFloat y,MofFloat z) = 0;
		/*************************************************************************//*!
				@brief			�J���������_�ݒ�
				@param[in]		v			�ݒ���W
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTargetPosition(const Vector3& v) = 0;
		/*************************************************************************//*!
				@brief			�J���������_�ݒ�
				@param[in]		x			�ݒ�X���W
				@param[in]		y			�ݒ�Y���W
				@param[in]		z			�ݒ�Z���W
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTargetPosition(MofFloat x, MofFloat y, MofFloat z) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�J�����ʒu�擾
				@param			None

				@return			�J�����ʒu
		*//**************************************************************************/
		virtual CVector3& GetViewPosition(void) = 0;
		/*************************************************************************//*!
				@brief			�J�����ʒu�擾
				@param			None

				@return			�J�����ʒu
		*//**************************************************************************/
		virtual const CVector3& GetViewPosition(void) const = 0;
		/*************************************************************************//*!
				@brief			�����_�擾
				@param			None

				@return			�����_
		*//**************************************************************************/
		virtual CVector3& GetTargetPosition(void) = 0;
		/*************************************************************************//*!
				@brief			�����_�擾
				@param			None

				@return			�����_
		*//**************************************************************************/
		virtual const CVector3& GetTargetPosition(void) const = 0;
		/*************************************************************************//*!
				@brief			�����x�N�g���擾
				@param			None

				@return			�����x�N�g��
		*//**************************************************************************/
		virtual CVector3& GetViewFront(void) = 0;
		/*************************************************************************//*!
				@brief			�����x�N�g���擾
				@param			None

				@return			�����x�N�g��
		*//**************************************************************************/
		virtual const CVector3& GetViewFront(void) const = 0;
		/*************************************************************************//*!
				@brief			����x�N�g���擾
				@param			None

				@return			����x�N�g��
		*//**************************************************************************/
		virtual CVector3& GetViewUp(void) = 0;
		/*************************************************************************//*!
				@brief			����x�N�g���擾
				@param			None

				@return			����x�N�g��
		*//**************************************************************************/
		virtual const CVector3& GetViewUp(void) const = 0;
		/*************************************************************************//*!
				@brief			�r���[�|�[�g�ݒ�擾
				@param			None

				@return			�r���[�|�[�g
		*//**************************************************************************/
		virtual LPViewPort GetViewPort(void) = 0;
		/*************************************************************************//*!
				@brief			�r���[�s��擾
				@param			None

				@return			�r���[�s��
		*//**************************************************************************/
		virtual CMatrix44& GetViewMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			�r���[�s��擾
				@param			None

				@return			�r���[�s��
		*//**************************************************************************/
		virtual const CMatrix44& GetViewMatrix(void) const = 0;
		/*************************************************************************//*!
				@brief			�r���{�[�h�s��擾
				@param			None

				@return			�r���{�[�h�s��
		*//**************************************************************************/
		virtual CMatrix33& GetBillBoardMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			�r���{�[�h�s��擾
				@param			None

				@return			�r���{�[�h�s��
		*//**************************************************************************/
		virtual const CMatrix33& GetBillBoardMatrix(void) const = 0;
		/*************************************************************************//*!
				@brief			�v���W�F�N�V�����s��擾
				@param			None

				@return			�v���W�F�N�V�����s��
		*//**************************************************************************/
		virtual CMatrix44& GetProjectionMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			�v���W�F�N�V�����s��擾
				@param			None

				@return			�v���W�F�N�V�����s��
		*//**************************************************************************/
		virtual const CMatrix44& GetProjectionMatrix(void) const = 0;
		/*************************************************************************//*!
				@brief			�r���[�v���W�F�N�V�����s��擾
				@param			None

				@return			�r���[�v���W�F�N�V�����s��
		*//**************************************************************************/
		virtual CMatrix44& GetViewProjectionMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			�r���[�v���W�F�N�V�����s��擾
				@param			None

				@return			�r���[�v���W�F�N�V�����s��
		*//**************************************************************************/
		virtual const CMatrix44& GetViewProjectionMatrix(void) const = 0;
		/*************************************************************************//*!
				@brief			���W�n�擾
				@param			None

				@return			���W�n
		*//**************************************************************************/
		virtual CoordinateType GetCoordinateType(void) const = 0;
		/*************************************************************************//*!
				@brief			�v���W�F�N�V�������\���̎擾
				@param			None

				@return			���W�n
		*//**************************************************************************/
		virtual const Projection& GetProjectionInfo(void) const = 0;
	};

	//�|�C���^�u������
	typedef ICamera*			LPCamera;
}

#endif

//[EOF]