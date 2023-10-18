/*************************************************************************//*!
					
					@file	Matrix44.h
					@brief	4�~4�s�񉉎Z�֘A

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MATRIX44__H__

#define		__MATRIX44__H__

//INCLUDE
#include	"Matrix33.h"

namespace Mof {
	
	//�N�I�[�^�j�I���s��̑O����`
	struct MOFLIBRARY_API Quaternion;

	/*******************************//*!
	@brief	4x4�s��\����

			4x4�s����������߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API Matrix44 {
		union {
			struct {
				MofFloat				_11, _12, _13, _14;
				MofFloat				_21, _22, _23, _24;
				MofFloat				_31, _32, _33, _34;
				MofFloat				_41, _42, _43, _44;
			};
			MofFloat rc[4][4];
			MofFloat val[16];
		};
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		Matrix44();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		f11			11����
				@param[in]		f12			12����
				@param[in]		f13			13����
				@param[in]		f14			14����
				@param[in]		f21			21����
				@param[in]		f22			22����
				@param[in]		f23			23����
				@param[in]		f24			24����
				@param[in]		f31			31����
				@param[in]		f32			32����
				@param[in]		f33			33����
				@param[in]		f34			34����
				@param[in]		f41			41����
				@param[in]		f42			42����
				@param[in]		f43			43����
				@param[in]		f44			44����

				@return			None
		*//**************************************************************************/
		Matrix44(	MofFloat f11 ,MofFloat f12 ,MofFloat f13 ,MofFloat f14,
					MofFloat f21 ,MofFloat f22 ,MofFloat f23 ,MofFloat f24,
					MofFloat f31 ,MofFloat f32 ,MofFloat f33 ,MofFloat f34,
					MofFloat f41 ,MofFloat f42 ,MofFloat f43 ,MofFloat f44 );
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pf			�p�����[�^�[�i16�ȏ�̔z��ł��邱�Ɓj

				@return			None
		*//**************************************************************************/
		Matrix44( MofFloat* pf );
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�s��

				@return			None
		*//**************************************************************************/
		Matrix44( const Matrix33& pObj );
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�s��

				@return			None
		*//**************************************************************************/
		Matrix44( const Matrix44& pObj );
	
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			float�L���X�g<br>
								�����̍��W��float�|�C���^�Ƃ��Ă��̂܂ܕԂ��B
		*//**************************************************************************/
		operator LPMofFloat ();
		/*************************************************************************//*!
				@brief			+�擾
		*//**************************************************************************/
		Matrix44 operator + () const;
		/*************************************************************************//*!
				@brief			-�擾
		*//**************************************************************************/
		Matrix44 operator - () const;
		/*************************************************************************//*!
				@brief			���
		*//**************************************************************************/
		Matrix44& operator = ( const Matrix33& m );
		/*************************************************************************//*!
				@brief			+=���Z
		*//**************************************************************************/
		Matrix44& operator += ( const Matrix44& m );
		/*************************************************************************//*!
				@brief			-=���Z
		*//**************************************************************************/
		Matrix44& operator -= ( const Matrix44& m );
		/*************************************************************************//*!
				@brief			float�Ƃ�*=���Z
		*//**************************************************************************/
		Matrix44& operator *= ( const MofFloat m );
		/*************************************************************************//*!
				@brief			Matrix33�Ƃ�*=���Z
		*//**************************************************************************/
		Matrix44& operator *= ( const Matrix33& m );
		/*************************************************************************//*!
				@brief			Matrix44�Ƃ�*=���Z
		*//**************************************************************************/
		Matrix44& operator *= ( const Matrix44& m );
		/*************************************************************************//*!
				@brief			float�Ƃ�/=���Z
		*//**************************************************************************/
		Matrix44& operator /= ( const MofFloat m );
		/*************************************************************************//*!
				@brief			+���Z
		*//**************************************************************************/
		Matrix44 operator + ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			-���Z
		*//**************************************************************************/
		Matrix44 operator - ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			float�Ƃ�*���Z
		*//**************************************************************************/
		Matrix44 operator * ( const MofFloat m ) const;
		/*************************************************************************//*!
				@brief			Vector2�Ƃ�*���Z
		*//**************************************************************************/
		Vector2 operator * ( const Vector2& v ) const;
		/*************************************************************************//*!
				@brief			Vector3�Ƃ�*���Z
		*//**************************************************************************/
		Vector3 operator * ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Vector4�Ƃ�*���Z
		*//**************************************************************************/
		Vector4 operator * ( const Vector4& v ) const;
		/*************************************************************************//*!
				@brief			Matrix33�Ƃ�*���Z
		*//**************************************************************************/
		Matrix44 operator * ( const Matrix33& m ) const;
		/*************************************************************************//*!
				@brief			Matrix44�Ƃ�*���Z
		*//**************************************************************************/
		Matrix44 operator * ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			float�Ƃ�/���Z
		*//**************************************************************************/
		Matrix44 operator / ( const MofFloat m ) const;
		/*************************************************************************//*!
				@brief			�z��w��ɂ��Matrix44�����o�ւ̃A�N�Z�X
		*//**************************************************************************/
		MofFloat& operator [] ( int i );
		/*************************************************************************//*!
				@brief			�z��w��ɂ��Matrix44�����o�ւ̃A�N�Z�X
		*//**************************************************************************/
		const MofFloat& operator [] ( int i ) const;
		/*************************************************************************//*!
				@brief			==���f
		*//**************************************************************************/
		bool operator == ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			!=���f
		*//**************************************************************************/
		bool operator != ( const Matrix44& m ) const;
	}Matrix44;
	
	/*******************************//*!
	@brief	4x4�s�񉉎Z�N���X

			Matrix44�\���̂��������߂̃X�^�e�B�b�N�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMatrix44Utilities {
	public:
		/*************************************************************************//*!
				@brief			�P�ʍs��ݒ�
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Identity(Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�]�u�s��ݒ�<br>
								���͍s��Əo�͍s��ɓ����Q�Ƃ�ݒ肷��ꍇ�A��������̕��𗘗p���邱��
				@param[in]		InMat		���͍s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Transpose(const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�]�u�s��ݒ�
				@param[in,out]	OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Transpose(Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			������W�n��Target�ւ̒����s��v�Z
				@param[in]		Pos			���W
				@param[in]		Target		�������W
				@param[in]		Up			����x�N�g��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void LookAtLH(const Vector3& Pos,const Vector3& Target,const Vector3& Up,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�E����W�n��Target�ւ̒����s��v�Z
				@param[in]		Pos			���W
				@param[in]		Target		�������W
				@param[in]		Up			����x�N�g��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void LookAtRH(const Vector3& Pos,const Vector3& Target,const Vector3& Up,Matrix44& OutMat);
	
		/*************************************************************************//*!
				@brief			������W�n�Ŏˉe�s��v�Z
				@param[in]		vr			����p
				@param[in]		Aspect		�A�X�y�N�g��
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void PerspectiveFovLH(const MofFloat vr,const MofFloat Aspect,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			������W�n�Ńp�[�X�y�N�e�B�u�ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void PerspectiveLH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			������W�n�Ő��ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void OrthoLH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			������W�n�Ő��ˉe�s��v�Z
				@param[in]		l			��
				@param[in]		r			�E
				@param[in]		b			��
				@param[in]		t			��
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void OrthoOffCenterLH(const MofFloat l,const MofFloat r,const MofFloat b,const MofFloat t,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			�E����W�n�Ŏˉe�s��v�Z
				@param[in]		vr			����p
				@param[in]		Aspect		�A�X�y�N�g��
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void PerspectiveFovRH(const MofFloat vr,const MofFloat Aspect,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�E����W�n�Ńp�[�X�y�N�e�B�u�ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void PerspectiveRH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�E����W�n�Ő��ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void OrthoRH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�E����W�n�Ő��ˉe�s��v�Z
				@param[in]		l			��
				@param[in]		r			�E
				@param[in]		b			��
				@param[in]		t			��
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void OrthoOffCenterRH(const MofFloat l,const MofFloat r,const MofFloat b,const MofFloat t,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			�s�񎮌v�Z
				@param[in]		Mat			�v�Z�s��

				@return			�s��
		*//**************************************************************************/
		static MofFloat Determinant(const Matrix44& Mat);
		/*************************************************************************//*!
				@brief			�t�s��v�Z
				@param[in]		InMat		���s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Inverse(const Matrix44& InMat,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			��Ԍv�Z
				@param[in]		m1			��ԍs��
				@param[in]		m2			��ԍs��
				@param[in]		t			��Ԏ���(0�`1)
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Interpolate(Matrix44& m1, Matrix44& m2, MofFloat t, Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z
				@param[in]		v			���W
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Translation(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z
				@param[in]		x			X���W
				@param[in]		y			Y���W
				@param[in]		z			Z���W
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Translation(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z<br>
								���s�� �~ ���s�ړ��s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		v			���W
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Translation(const Matrix44& InMat,const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z<br>
								���s�� �~ ���s�ړ��s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		x			X���W
				@param[in]		y			Y���W
				@param[in]		z			Z���W
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Translation(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z<br>
								���s�ړ��s�� �~ ���s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		v			���W
				@param[in]		InMat		���s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Translation(const Vector3& v,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z<br>
								���s�ړ��s�� �~ ���s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		x			X���W
				@param[in]		y			Y���W
				@param[in]		z			Z���W
				@param[in]		InMat		���s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Translation(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z
				@param[in]		v			�{��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Scaling(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z
				@param[in]		s			�{��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Scaling(const MofFloat s,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z
				@param[in]		x			X�{��
				@param[in]		y			Y�{��
				@param[in]		z			Z�{��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Scaling(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								���s�� �~ �g��s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		v			�{��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Scaling(const Matrix44& InMat,const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								���s�� �~ �g��s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		s			�{��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Scaling(const Matrix44& InMat,const MofFloat s,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								���s�� �~ �g��s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		x			X�{��
				@param[in]		y			Y�{��
				@param[in]		z			Z�{��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Scaling(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								�g��s�� �~ ���s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		v			�{��
				@param[in]		InMat		���s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Scaling(const Vector3& v,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								�g��s�� �~ ���s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		s			�{��
				@param[in]		InMat		���s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Scaling(const MofFloat s,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								�g��s�� �~ ���s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		x			X�{��
				@param[in]		y			Y�{��
				@param[in]		z			Z�{��
				@param[in]		InMat		���s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void Scaling(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Y��Z�̏��ŉ�]���s��
				@param[in]		v			��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationXYZ(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Y��Z�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationXYZ(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Z��Y�̏��ŉ�]���s��
				@param[in]		v			��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationXZY(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Z��Y�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationXZY(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Y��X��Z�̏��ŉ�]���s��
				@param[in]		v			��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationYXZ(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Y��X��Z�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationYXZ(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Y��Z��X�̏��ŉ�]���s��
				@param[in]		v			��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationYZX(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Y��Z��X�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationYZX(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��X��Y�̏��ŉ�]���s��
				@param[in]		v			��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationZXY(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��X��Y�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationZXY(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��Y��X�̏��ŉ�]���s��
				@param[in]		v			��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationZYX(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��Y��X�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationZYX(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			X����]�s��v�Z
				@param[in]		ax			X��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationX(const MofFloat ax,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			X����]�s��v�Z<br>
								���s�� �~ X��]�s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		ax			X��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationX(const Matrix44& InMat,const MofFloat ax,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			X����]�s��v�Z<br>
								X��]�s�� �~ ���s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		ax			X��]
				@param[in]		InMat		���s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationX(const MofFloat ax,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Y����]�s��v�Z
				@param[in]		ay			Y��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationY(const MofFloat ay,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Y����]�s��v�Z<br>
								���s�� �~ Y��]�s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		ay			Y��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationY(const Matrix44& InMat,const MofFloat ay,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Y����]�s��v�Z<br>
								Y��]�s�� �~ ���s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		ay			Y��]
				@param[in]		InMat		���s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationY(const MofFloat ay,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Z����]�s��v�Z
				@param[in]		az			Z��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationZ(const MofFloat az,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Z����]�s��v�Z<br>
								���s�� �~ Z��]�s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		az			Z��]
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationZ(const Matrix44& InMat,const MofFloat az,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Z����]�s��v�Z<br>
								Z��]�s�� �~ ���s��̌��ʂ����ʍs��ɐݒ肷��B
				@param[in]		az			Z��]
				@param[in]		InMat		���s��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationZ(const MofFloat az,const Matrix44& InMat,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			�w�莲��]�s��v�Z
				@param[in]		a			��]
				@param[in]		v			��
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotationAxis(const MofFloat a,const CVector3& v,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			���̎p������w����W�������s��̍쐬
				@param[in]		src			���̎p��
				@param[in]		target		�ڕW���W
				@param[in]		forward		�O������
				@param[out]		out			���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotateLookAt(Matrix44& src, Vector3& target, Vector3& forward, Matrix44& out);
		/*************************************************************************//*!
				@brief			���̎p������w����W�������s��̍쐬
				@param[in]		src			���̎p��
				@param[in]		target		�ڕW���W
				@param[out]		out			���ʍs��

				@return			None
		*//**************************************************************************/
		static void RotateLookAt(Matrix44& src, Vector3& target, Matrix44& out);

		/*************************************************************************//*!
				@brief			�w�肵���_�𒆐S�Ƃ�����]������s������߂�
				@param[in]		src			���̎p��
				@param[in]		pivot		���S
				@param[in]		Angle		��]�p�x
				@param[out]		out			�o�͍s��

				@return			None
		*//**************************************************************************/
		static void RotateAroundLocal(Matrix44& src, Matrix44& pivot, Vector3& Angle, Matrix44& out);
		/*************************************************************************//*!
				@brief			�w�肵���_�𒆐S�Ƃ�����]������s������߂�
				@param[in]		src			���̎p��
				@param[in]		pivot		���S
				@param[in]		Angle		��]�p�x
				@param[out]		out			�o�͍s��

				@return			None
		*//**************************************************************************/
		static void RotateAround(Matrix44& src, Matrix44& pivot, Vector3& Angle, Matrix44& out);
		/*************************************************************************//*!
				@brief			�w�肵���_�𒆐S�Ƃ�����]������s������߂�
				@param[in]		src			���̎p��
				@param[in]		pivot		���S
				@param[in]		Axis		��]��
				@param[in]		Angle		��]�p�x
				@param[out]		out			�o�͍s��

				@return			None
		*//**************************************************************************/
		static void RotateAround(Matrix44& src, Matrix44& pivot, Vector3& Axis, MofFloat Angle, Matrix44& out);

		/*************************************************************************//*!
				@brief			�s��P�ƍs��Q�̕�ԍs��̍쐬
				@param[in]		m1			�s��P
				@param[in]		m2			�s��Q
				@param[in]		t			��Ԏ���
				@param[in,out]	o			���ʍs��

				@return			None
		*//**************************************************************************/
		static void Integrate(const Matrix44& m1,const Matrix44& m2,MofFloat t,Matrix44& o);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���ʍs��̕��s�ړ��x�N�g���ݒ�
				@param[in]		v			���s�ړ�
				@param[in,out]	OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void SetTranslation(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			���ʍs��̕��s�ړ��x�N�g���ݒ�
				@param[in]		x			X���W
				@param[in]		y			Y���W
				@param[in]		z			Z���W
				@param[in,out]	OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		static void SetTranslation(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���s��̕��s�ړ��x�N�g���擾
				@param[in]		InMat		���s��
				@param[out]		v			���s�ړ�

				@return			None
		*//**************************************************************************/
		static void GetTranslation(const Matrix44& InMat,Vector3& v);
		/*************************************************************************//*!
				@brief			���s��̊g��x�N�g���擾
				@param[in]		InMat		���s��
				@param[out]		v			�{��

				@return			None
		*//**************************************************************************/
		static void GetScaling(const Matrix44& InMat,Vector3& v);
		/*************************************************************************//*!
				@brief			���s��̉�]�����݂̂̍s��擾
				@param[in]		InMat		���s��
				@param[out]		m			��]

				@return			None
		*//**************************************************************************/
		static void GetRotation(const Matrix44& InMat,Matrix33& m);
		/*************************************************************************//*!
				@brief			���s��̉�]�N�I�[�^�j�I���擾
				@param[in]		InMat		���s��
				@param[out]		q			��]

				@return			None
		*//**************************************************************************/
		static void GetRotation(const Matrix44& InMat,Quaternion& q);
		/*************************************************************************//*!
				@brief			���s��̉�]�x�N�g���擾
				@param[in]		InMat		���s��
				@param[out]		v			��]

				@return			None
		*//**************************************************************************/
		static void GetRotation(const Matrix44& InMat,Vector3& v);
		/*************************************************************************//*!
				@brief			���s��̉�]�x�N�g���擾
				@param[in]		InMat		���s��
				@param[out]		v			��]

				@return			None
		*//**************************************************************************/
		static void GetYawPitchRoll(const Matrix44& InMat,Vector3& v);

	private:
		//�쐬���֎~����
		CMatrix44Utilities(){};
		CMatrix44Utilities(const CMatrix44Utilities& pObj){};
	};

	/*******************************//*!
	@brief	4x4�s��N���X

			Matrix44�\���̂��������߂̊֐����܂߂��N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMatrix44 : public Matrix44 , public IMofBase {
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CMatrix44();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		f11			11����
				@param[in]		f12			12����
				@param[in]		f13			13����
				@param[in]		f14			14����
				@param[in]		f21			21����
				@param[in]		f22			22����
				@param[in]		f23			23����
				@param[in]		f24			24����
				@param[in]		f31			31����
				@param[in]		f32			32����
				@param[in]		f33			33����
				@param[in]		f34			34����
				@param[in]		f41			41����
				@param[in]		f42			42����
				@param[in]		f43			43����
				@param[in]		f44			44����

				@return			None
		*//**************************************************************************/
		CMatrix44(	MofFloat f11 ,MofFloat f12 ,MofFloat f13 ,MofFloat f14,
					MofFloat f21 ,MofFloat f22 ,MofFloat f23 ,MofFloat f24,
					MofFloat f31 ,MofFloat f32 ,MofFloat f33 ,MofFloat f34,
					MofFloat f41 ,MofFloat f42 ,MofFloat f43 ,MofFloat f44 );
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pf			�p�����[�^�[�i16�ȏ�̔z��ł��邱�Ɓj

				@return			None
		*//**************************************************************************/
		CMatrix44( MofFloat* pf );
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�s��

				@return			None
		*//**************************************************************************/
		CMatrix44( const Matrix33& pObj );
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�s��

				@return			None
		*//**************************************************************************/
		CMatrix44( const CMatrix33& pObj );
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�s��

				@return			None
		*//**************************************************************************/
		CMatrix44( const Matrix44& pObj );
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�s��

				@return			None
		*//**************************************************************************/
		CMatrix44( const CMatrix44& pObj );
		
		/*************************************************************************//*!
				@brief			�P�ʍs��ݒ�
				@param			None

				@return			None
		*//**************************************************************************/
		void Identity(void);
		/*************************************************************************//*!
				@brief			�]�u�s��ݒ�
				@param			None

				@return			None
		*//**************************************************************************/
		void Transpose(void);

		/*************************************************************************//*!
				@brief			������W�n��Target�ւ̒����s��v�Z
				@param[in]		Pos			���W
				@param[in]		Target		�������W
				@param[in]		Up			����x�N�g��

				@return			None
		*//**************************************************************************/
		void LookAtLH(const Vector3& Pos,const Vector3& Target,const Vector3& Up);
		/*************************************************************************//*!
				@brief			�E����W�n��Target�ւ̒����s��v�Z
				@param[in]		Pos			���W
				@param[in]		Target		�������W
				@param[in]		Up			����x�N�g��

				@return			None
		*//**************************************************************************/
		void LookAtRH(const Vector3& Pos,const Vector3& Target,const Vector3& Up);

		/*************************************************************************//*!
				@brief			������W�n�Ŏˉe�s��v�Z
				@param[in]		vr			����p
				@param[in]		Aspect		�A�X�y�N�g��
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���

				@return			None
		*//**************************************************************************/
		void PerspectiveFovLH(const MofFloat vr,const MofFloat Aspect,const MofFloat Near,const MofFloat Far);
		/*************************************************************************//*!
				@brief			������W�n�Ńp�[�X�y�N�e�B�u�ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���

				@return			None
		*//**************************************************************************/
		void PerspectiveLH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far);
		/*************************************************************************//*!
				@brief			������W�n�Ő��ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���

				@return			None
		*//**************************************************************************/
		void OrthoLH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far);
				
		/*************************************************************************//*!
				@brief			�E����W�n�Ŏˉe�s��v�Z
				@param[in]		vr			����p
				@param[in]		Aspect		�A�X�y�N�g��
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���

				@return			None
		*//**************************************************************************/
		void PerspectiveFovRH(const MofFloat vr,const MofFloat Aspect,const MofFloat Near,const MofFloat Far);
		/*************************************************************************//*!
				@brief			�E����W�n�Ńp�[�X�y�N�e�B�u�ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���

				@return			None
		*//**************************************************************************/
		void PerspectiveRH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far);
		/*************************************************************************//*!
				@brief			�E����W�n�Ő��ˉe�s��v�Z
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		Near		�ŋߖ�
				@param[in]		Far			�ŉ���

				@return			None
		*//**************************************************************************/
		void OrthoRH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far);

		/*************************************************************************//*!
				@brief			�s�񎮌v�Z
				@param			None

				@return			�s��
		*//**************************************************************************/
		MofFloat Determinant(void) const;
		/*************************************************************************//*!
				@brief			�t�s��v�Z
				@param			None

				@return			None
		*//**************************************************************************/
		void Inverse(void);
		/*************************************************************************//*!
				@brief			�t�s��v�Z
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		void Inverse(Matrix44& OutMat) const;
		
		/*************************************************************************//*!
				@brief			��Ԍv�Z
				@param[in]		m			��ԍs��
				@param[in]		t			��Ԏ���(0�`1)
				@param[out]		OutMat		���ʍs��

				@return			None
		*//**************************************************************************/
		void Interpolate(Matrix44& m, MofFloat t, Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z
				@param[in]		v			���W

				@return			None
		*//**************************************************************************/
		void Translation(const Vector3& v);
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z
				@param[in]		x			X���W
				@param[in]		y			Y���W
				@param[in]		z			Z���W

				@return			None
		*//**************************************************************************/
		void Translation(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z<br>
								���s�� �~ ���s�ړ��s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		v			���W

				@return			None
		*//**************************************************************************/
		void Translation(const Matrix44& InMat,const Vector3& v);
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z<br>
								���s�� �~ ���s�ړ��s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		x			X���W
				@param[in]		y			Y���W
				@param[in]		z			Z���W

				@return			None
		*//**************************************************************************/
		void Translation(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z<br>
								���s�ړ��s�� �~ ���s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		v			���W
				@param[in]		InMat		���s��

				@return			None
		*//**************************************************************************/
		void Translation(const Vector3& v,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			���s�ړ��s��v�Z<br>
								���s�ړ��s�� �~ ���s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		x			X���W
				@param[in]		y			Y���W
				@param[in]		z			Z���W
				@param[in]		InMat		���s��

				@return			None
		*//**************************************************************************/
		void Translation(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat);
		
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z
				@param[in]		v			�{��

				@return			None
		*//**************************************************************************/
		void Scaling(const Vector3& v);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z
				@param[in]		s			�{��

				@return			None
		*//**************************************************************************/
		void Scaling(const MofFloat s);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z
				@param[in]		x			X�{��
				@param[in]		y			Y�{��
				@param[in]		z			Z�{��

				@return			None
		*//**************************************************************************/
		void Scaling(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								���s�� �~ �g��s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		v			�{��

				@return			None
		*//**************************************************************************/
		void Scaling(const Matrix44& InMat,const Vector3& v);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								���s�� �~ �g��s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		s			�{��

				@return			None
		*//**************************************************************************/
		void Scaling(const Matrix44& InMat,const MofFloat s);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								���s�� �~ �g��s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		x			X�{��
				@param[in]		y			Y�{��
				@param[in]		z			Z�{��

				@return			None
		*//**************************************************************************/
		void Scaling(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z);

		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								�g��s�� �~ ���s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		v			�{��
				@param[in]		InMat		���s��

				@return			None
		*//**************************************************************************/
		void Scaling(const Vector3& v,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								�g��s�� �~ ���s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		s			�{��
				@param[in]		InMat		���s��

				@return			None
		*//**************************************************************************/
		void Scaling(const MofFloat s,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			�X�P�[�����O�s��v�Z<br>
								�g��s�� �~ ���s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		x			X�{��
				@param[in]		y			Y�{��
				@param[in]		z			Z�{��
				@param[in]		InMat		���s��

				@return			None
		*//**************************************************************************/
		void Scaling(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat);

		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Y��Z�̏��ŉ�]���s��
				@param[in]		v			��]

				@return			None
		*//**************************************************************************/
		void RotationXYZ(const Vector3& v);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Y��Z�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationXYZ(const MofFloat x,const MofFloat y,const MofFloat z);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Z��Y�̏��ŉ�]���s��
				@param[in]		v			��]

				@return			None
		*//**************************************************************************/
		void RotationXZY(const Vector3& v);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Z��Y�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationXZY(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Y��X��Z�̏��ŉ�]���s��
				@param[in]		v			��]

				@return			None
		*//**************************************************************************/
		void RotationYXZ(const Vector3& v);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Y��X��Z�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationYXZ(const MofFloat x,const MofFloat y,const MofFloat z);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Y��Z��X�̏��ŉ�]���s��
				@param[in]		v			��]

				@return			None
		*//**************************************************************************/
		void RotationYZX(const Vector3& v);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Y��Z��X�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationYZX(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��X��Y�̏��ŉ�]���s��
				@param[in]		v			��]

				@return			None
		*//**************************************************************************/
		void RotationZXY(const Vector3& v);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��X��Y�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationZXY(const MofFloat x,const MofFloat y,const MofFloat z);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��Y��X�̏��ŉ�]���s��
				@param[in]		v			��]

				@return			None
		*//**************************************************************************/
		void RotationZYX(const Vector3& v);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��Y��X�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationZYX(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Y�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]

				@return			None
		*//**************************************************************************/
		void RotationXY(const MofFloat x,const MofFloat y);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Z�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationXZ(const MofFloat x,const MofFloat z);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								X��Y�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		y			Y��]

				@return			None
		*//**************************************************************************/
		void RotationYX(const MofFloat x,const MofFloat y);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Y��Z�̏��ŉ�]���s��
				@param[in]		y			Y��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationYZ(const MofFloat y,const MofFloat z);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��X�̏��ŉ�]���s��
				@param[in]		x			X��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationZX(const MofFloat x,const MofFloat z);
		/*************************************************************************//*!
				@brief			��]�s��v�Z<br>
								Z��Y�̏��ŉ�]���s��
				@param[in]		y			Y��]
				@param[in]		z			Z��]

				@return			None
		*//**************************************************************************/
		void RotationZY(const MofFloat y,const MofFloat z);

		/*************************************************************************//*!
				@brief			X����]�s��v�Z
				@param[in]		ax			X��]

				@return			None
		*//**************************************************************************/
		void RotationX(const MofFloat ax);
		/*************************************************************************//*!
				@brief			X����]�s��v�Z<br>
								���s�� �~ X��]�s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		ax			X��]

				@return			None
		*//**************************************************************************/
		void RotationX(const Matrix44& InMat,const MofFloat ax);
		/*************************************************************************//*!
				@brief			X����]�s��v�Z<br>
								X��]�s�� �~ ���s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		ax			X��]
				@param[in]		InMat		���s��

				@return			None
		*//**************************************************************************/
		void RotationX(const MofFloat ax,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			Y����]�s��v�Z
				@param[in]		ay			Y��]

				@return			None
		*//**************************************************************************/
		void RotationY(const MofFloat ay);
		/*************************************************************************//*!
				@brief			Y����]�s��v�Z<br>
								���s�� �~ Y��]�s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		ay			Y��]

				@return			None
		*//**************************************************************************/
		void RotationY(const Matrix44& InMat,const MofFloat ay);
		/*************************************************************************//*!
				@brief			Y����]�s��v�Z<br>
								Y��]�s�� �~ ���s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		ay			Y��]
				@param[in]		InMat		���s��

				@return			None
		*//**************************************************************************/
		void RotationY(const MofFloat ay,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			Z����]�s��v�Z
				@param[in]		az			Z��]

				@return			None
		*//**************************************************************************/
		void RotationZ(const MofFloat az);
		/*************************************************************************//*!
				@brief			Z����]�s��v�Z<br>
								���s�� �~ Z��]�s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		InMat		���s��
				@param[in]		az			Z��]

				@return			None
		*//**************************************************************************/
		void RotationZ(const Matrix44& InMat,const MofFloat az);
		/*************************************************************************//*!
				@brief			Z����]�s��v�Z<br>
								Z��]�s�� �~ ���s��̌��ʂ����g�ɐݒ肷��B
				@param[in]		az			Z��]
				@param[in]		InMat		���s��

				@return			None
		*//**************************************************************************/
		void RotationZ(const MofFloat az,const Matrix44& InMat);

		/*************************************************************************//*!
				@brief			�w�莲��]�s��v�Z
				@param[in]		a			��]
				@param[in]		v			��

				@return			None
		*//**************************************************************************/
		void RotationAxis(const MofFloat a,const CVector3& v);

		/*************************************************************************//*!
				@brief			���̎p������w����W�������s��̍쐬
				@param[in]		target		�ڕW���W
				@param[in]		forward		�O������

				@return			None
		*//**************************************************************************/
		void RotateLookAt(Vector3& target, Vector3& forward);
		/*************************************************************************//*!
				@brief			���̎p������w����W�������s��̍쐬
				@param[in]		target		�ڕW���W
				@param[in]		forward		�O������
				@param[out]		out			���ʍs��

				@return			None
		*//**************************************************************************/
		void RotateLookAt(Vector3& target, Vector3& forward, Matrix44& out);
		/*************************************************************************//*!
				@brief			���̎p������w����W�������s��̍쐬
				@param[in]		target		�ڕW���W

				@return			None
		*//**************************************************************************/
		void RotateLookAt(Vector3& target);
		/*************************************************************************//*!
				@brief			���̎p������w����W�������s��̍쐬
				@param[in]		target		�ڕW���W
				@param[out]		out			���ʍs��

				@return			None
		*//**************************************************************************/
		void RotateLookAt(Vector3& target, Matrix44& out);
		/*************************************************************************//*!
				@brief			�w�肵���_�𒆐S�Ƃ�����]������s������߂�
				@param[in]		pivot		���S
				@param[in]		Angle		��]�p�x

				@return			None
		*//**************************************************************************/
		void RotateAroundLocal(Matrix44& pivot, Vector3& Angle);
		/*************************************************************************//*!
				@brief			�w�肵���_�𒆐S�Ƃ�����]������s������߂�
				@param[in]		pivot		���S
				@param[in]		Angle		��]�p�x
				@param[out]		out			�o�͍s��

				@return			None
		*//**************************************************************************/
		void RotateAroundLocal(Matrix44& pivot, Vector3& Angle, Matrix44& out);
		/*************************************************************************//*!
				@brief			�w�肵���_�𒆐S�Ƃ�����]������s������߂�
				@param[in]		pivot		���S
				@param[in]		Angle		��]�p�x

				@return			None
		*//**************************************************************************/
		void RotateAround(Matrix44& pivot, Vector3& Angle);
		/*************************************************************************//*!
				@brief			�w�肵���_�𒆐S�Ƃ�����]������s������߂�
				@param[in]		pivot		���S
				@param[in]		Angle		��]�p�x
				@param[out]		out			�o�͍s��

				@return			None
		*//**************************************************************************/
		void RotateAround(Matrix44& pivot, Vector3& Angle, Matrix44& out);
		/*************************************************************************//*!
				@brief			�w�肵���_�𒆐S�Ƃ�����]������s������߂�
				@param[in]		pivot		���S
				@param[in]		Axis		��]��
				@param[in]		Angle		��]�p�x

				@return			None
		*//**************************************************************************/
		void RotateAround(Matrix44& pivot, Vector3& Axis, MofFloat Angle);
		/*************************************************************************//*!
				@brief			�w�肵���_�𒆐S�Ƃ�����]������s������߂�
				@param[in]		pivot		���S
				@param[in]		Axis		��]��
				@param[in]		Angle		��]�p�x
				@param[out]		out			�o�͍s��

				@return			None
		*//**************************************************************************/
		void RotateAround(Matrix44& pivot, Vector3& Axis, MofFloat Angle, Matrix44& out);

		/*************************************************************************//*!
				@brief			3x3�����݂̂̊|���Z
				@param[in]		m			�v�Z�s��

				@return			None
		*//**************************************************************************/
		void Multiply3x3(const Matrix33& m);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�l�̐ݒ�
				@param[in]		f11			11����
				@param[in]		f12			12����
				@param[in]		f13			13����
				@param[in]		f14			14����
				@param[in]		f21			21����
				@param[in]		f22			22����
				@param[in]		f23			23����
				@param[in]		f24			24����
				@param[in]		f31			31����
				@param[in]		f32			32����
				@param[in]		f33			33����
				@param[in]		f34			34����
				@param[in]		f41			41����
				@param[in]		f42			42����
				@param[in]		f43			43����
				@param[in]		f44			44����

				@return			None
		*//**************************************************************************/
		void SetValue(	MofFloat f11 ,MofFloat f12 ,MofFloat f13 ,MofFloat f14,
						MofFloat f21 ,MofFloat f22 ,MofFloat f23 ,MofFloat f24,
						MofFloat f31 ,MofFloat f32 ,MofFloat f33 ,MofFloat f34,
						MofFloat f41 ,MofFloat f42 ,MofFloat f43 ,MofFloat f44 );
		/*************************************************************************//*!
				@brief			�������s�ړ��x�N�g���ݒ�
				@param[in]		v			���s�ړ�

				@return			None
		*//**************************************************************************/
		void SetTranslation(const Vector3& v);
		/*************************************************************************//*!
				@brief			�������s�ړ��x�N�g���ݒ�
				@param[in]		x			X���W
				@param[in]		y			Y���W
				@param[in]		z			Z���W

				@return			None
		*//**************************************************************************/
		void SetTranslation(const MofFloat x,const MofFloat y,const MofFloat z);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			����3�~3�s��擾
				@param[out]		m			3�~3�s��

				@return			None
		*//**************************************************************************/
		void GetMatrix33(Matrix33& m) const;
		/*************************************************************************//*!
				@brief			�������s�ړ��x�N�g���擾
				@param[out]		v			���s�ړ�

				@return			None
		*//**************************************************************************/
		void GetTranslation(Vector3& v) const;
		/*************************************************************************//*!
				@brief			�����g��x�N�g���擾
				@param[out]		v			�{��

				@return			None
		*//**************************************************************************/
		void GetScaling(Vector3& v) const;
		/*************************************************************************//*!
				@brief			������]�����݂̂̍s��擾
				@param[out]		m			��]

				@return			None
		*//**************************************************************************/
		void GetRotation(Matrix33& m) const;
		/*************************************************************************//*!
				@brief			������]�N�I�[�^�j�I���擾
				@param[out]		q			��]

				@return			None
		*//**************************************************************************/
		void GetRotation(Quaternion& q) const;
		/*************************************************************************//*!
				@brief			������]�x�N�g���擾
				@param[out]		v			��]

				@return			None
		*//**************************************************************************/
		void GetRotation(Vector3& v) const;
		/*************************************************************************//*!
				@brief			������]�x�N�g���擾
				@param[out]		v			��]

				@return			None
		*//**************************************************************************/
		void GetYawPitchRoll(Vector3& v) const;
		
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------
		
		/*************************************************************************//*!
				@brief			���
		*//**************************************************************************/
		CMatrix44& operator = ( const Matrix33& m );
		/*************************************************************************//*!
				@brief			���
		*//**************************************************************************/
		CMatrix44& operator = ( const Matrix44& m );

		//�N���X��{��`
		MOF_LIBRARYCLASS(CMatrix44,MOF_MATRIX44CLASS_ID);
	};

	//�|�C���^�u������
	typedef CMatrix44*			LPMatrix44;

	//INLINE INCLUDE
	#include	"Matrix44.inl"

}

#endif

//[EOF]