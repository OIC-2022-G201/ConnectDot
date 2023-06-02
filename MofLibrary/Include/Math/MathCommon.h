/*************************************************************************//*!
					
					@file	MathCommon.h
					@brief	���C�u�����̎Z�p�n��{��`���s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MATHCOMMON__H__

#define		__MATHCOMMON__H__

#define		MOF_USE_SSE

//INCLUDE
#include	<math.h>
#include	<float.h>

#ifdef		MOF_USE_SSE

#include	<emmintrin.h>
#include	<smmintrin.h>

#endif		//MOF_USE_SSE

#include	"../Common/MofCommon.h"

//TYPEDEF

//----------------------------------
////�u������
//----------------------------------
#ifndef		__MOFDATATYPETYPEDEF__
#define		__MOFDATATYPETYPEDEF__

//�W���^�u������
typedef		void*				LPMofVoid;
typedef		const void*			LPCMofVoid;

typedef		int					MofInt;
typedef		MofInt*				LPMofInt;
typedef		const MofInt*		LPCMofInt;
typedef		unsigned int		MofUInt;
typedef		MofUInt*			LPMofUInt;
typedef		const MofUInt*		LPCMofUInt;
typedef		int					MofBool;
typedef		MofBool*			LPMofBool;
typedef		const MofBool*		LPCMofBool;

typedef		char				MofS8;
typedef		MofS8*				LPMofS8;
typedef		const MofS8*		LPCMofS8;
typedef		short				MofS16;
typedef		MofS16*				LPMofS16;
typedef		const MofS16*		LPCMofS16;
typedef		long				MofS32;
typedef		MofS32*				LPMofS32;
typedef		const MofS32*		LPCMofS32;
typedef		long long			MofS64;
typedef		MofS64*				LPMofS64;
typedef		const MofS64*		LPCMofS64;

typedef		unsigned char		MofU8;
typedef		MofU8*				LPMofU8;
typedef		const MofU8*		LPCMofU8;
typedef		unsigned short		MofU16;
typedef		MofU16*				LPMofU16;
typedef		const MofU16*		LPCMofU16;
typedef		unsigned long		MofU32;
typedef		MofU32*				LPMofU32;
typedef		const MofU32*		LPCMofU32;
typedef		unsigned long long	MofU64;
typedef		MofU64*				LPMofU64;
typedef		const MofU64*		LPCMofU64;

typedef		float				MofFloat;
typedef		MofFloat*			LPMofFloat;
typedef		const MofFloat*		LPCMofFloat;
typedef		double				MofDouble;
typedef		MofDouble*			LPMofDouble;
typedef		const MofDouble*	LPCMofDouble;

#ifdef		MOF_USE_SSE

typedef		__m128				MofSimdFloat4;

FORCE_INLINE MofSimdFloat4 operator + (const MofSimdFloat4& A, const MofSimdFloat4& B)
{
	return _mm_add_ps(A, B);
}

FORCE_INLINE MofSimdFloat4 operator - (const MofSimdFloat4& A, const MofSimdFloat4& B)
{
	return _mm_sub_ps(A, B);
}

FORCE_INLINE MofSimdFloat4 operator * (const MofSimdFloat4& A, const MofSimdFloat4& B)
{
	return _mm_mul_ps(A, B);
}

FORCE_INLINE MofSimdFloat4 operator / (const MofSimdFloat4& A, const MofSimdFloat4& B)
{
	return _mm_div_ps(A, B);
}

FORCE_INLINE MofSimdFloat4& operator += (MofSimdFloat4& A, const MofSimdFloat4& B)
{
	A = _mm_add_ps(A, B);
	return A;
}

FORCE_INLINE MofSimdFloat4& operator -= (MofSimdFloat4& A, const MofSimdFloat4& B)
{
	A = _mm_sub_ps(A, B);
	return A;
}

FORCE_INLINE MofSimdFloat4& operator *= (MofSimdFloat4& A, const MofSimdFloat4& B)
{
	A = _mm_mul_ps(A, B);
	return A;
}

FORCE_INLINE MofSimdFloat4& operator /= (MofSimdFloat4& A, const MofSimdFloat4& B)
{
	A = _mm_div_ps(A, B);
	return A;
}

#else

typedef MOF_ALIGNED16_STRUCT tag_SimdFloat4 {
	MofFloat					f[4];

	tag_SimdFloat4 operator + (const tag_SimdFloat4& B) const
	{
		tag_SimdFloat4 re = { f[0] + B.f[0], f[1] + B.f[1], f[2] + B.f[2], f[3] + B.f[3] };
		return re;
	}

	FORCE_INLINE tag_SimdFloat4 operator - (const tag_SimdFloat4& B) const
	{
		tag_SimdFloat4 re = { f[0] - B.f[0], f[1] - B.f[1], f[2] - B.f[2], f[3] - B.f[3] };
		return re;
	}

	FORCE_INLINE tag_SimdFloat4 operator * (const tag_SimdFloat4& B) const
	{
		tag_SimdFloat4 re = { f[0] * B.f[0], f[1] * B.f[1], f[2] * B.f[2], f[3] * B.f[3] };
		return re;
	}

	FORCE_INLINE tag_SimdFloat4 operator / (const tag_SimdFloat4& B) const
	{
		tag_SimdFloat4 re = { f[0] / B.f[0], f[1] / B.f[1], f[2] / B.f[2], f[3] / B.f[3] };
		return re;
	}

	FORCE_INLINE tag_SimdFloat4& operator += (const tag_SimdFloat4& B)
	{
		f[0] += B.f[0];
		f[1] += B.f[1];
		f[2] += B.f[2];
		f[3] += B.f[3];
		return *this;
	}

	FORCE_INLINE tag_SimdFloat4& operator -= (const tag_SimdFloat4& B)
	{
		f[0] -= B.f[0];
		f[1] -= B.f[1];
		f[2] -= B.f[2];
		f[3] -= B.f[3];
		return *this;
	}

	FORCE_INLINE tag_SimdFloat4& operator *= (const tag_SimdFloat4& B)
	{
		f[0] *= B.f[0];
		f[1] *= B.f[1];
		f[2] *= B.f[2];
		f[3] *= B.f[3];
		return *this;
	}

	FORCE_INLINE tag_SimdFloat4& operator /= (const tag_SimdFloat4& B)
	{
		f[0] /= B.f[0];
		f[1] /= B.f[1];
		f[2] /= B.f[2];
		f[3] /= B.f[3];
		return *this;
	}
}MofSimdFloat4;


#endif		//MOF_USE_SSE

//----------------------------------
////�����^�C�v��`
//----------------------------------
#ifndef		MOF_DECIMALTYPE

//!�����^�C�v(Float)
#define		MOF_DECIMALTYPE_FLOAT					0

//!�����^�C�v(Double)
#define		MOF_DECIMALTYPE_DOUBLE					1

//!<�����^�C�v
#define		MOF_DECIMALTYPE							MOF_DECIMALTYPE_FLOAT

#endif		//#ifndef		MOF_DECIMALTYPE

#if			(MOF_DECIMALTYPE == MOF_DECIMALTYPE_FLOAT)
#define		MOF_DECIMAL_LARGE						1e18f
#define		MOF_DECIMAL_EPSILON						FLT_EPSILON
typedef		MofFloat			MofDecimal;
typedef		LPMofFloat			LPMofDecimal;
#else
#define		MOF_DECIMAL_LARGE						1e30
#define		MOF_DECIMAL_EPSILON						DBL_EPSILON
typedef		MofDouble			MofDecimal;
typedef		LPMofDouble			LPMofDecimal;
#endif		//#if			(MOF_DECIMALTYPE == MOF_DECIMALTYPE_FLOAT)

#endif		//__DEFAULTTYPEDEF__

//DEFINE

//----------------------------------
////�Z�p�n�萔�ƃ}�N��
//----------------------------------

//!<DOUBLE���E
#define		MOF_DOUBLE_EPSILON						DBL_EPSILON
#define		MOF_DOUBLE_INFINITY						DBL_MAX

//!FLOAT���E
#define		MOF_FLOAT_EPSILON						FLT_EPSILON
#define		MOF_FLOAT_INFINITY						FLT_MAX
#define		MOF_FLOAT_QNAN							0x7FC00000
#define		MOF_FLOAT_IND							0xFFC00000
#define		MOF_FLOAT_INF							0x7F800000
#define		MOF_FLOAT_MINF							0xFF800000

//!SQRT12
#define		MOF_SQRT12								(0.7071067811865475244008443621048490)

//!�~����1/4
#define		MOF_MATH_QUADPI							(0.785398164f)

//!�~��������
#define		MOF_MATH_HALFPI							(1.570796327f)

//!�~����
#define		MOF_MATH_PI								(3.141592654f)

//!�~����2�{
#define		MOF_MATH_2PI							(6.283185307f)

//!���W�A���ɕϊ�
#define		MOF_ToRadian(dir)						(MOF_MATH_PI / 180 * (dir))

//!�n�[�t���W�A���ɕϊ�
#define		MOF_ToHarfRadian(dir)					(MOF_MATH_PI / 180 * 0.5f * (dir))

//!���W�A������ϊ�
#define		MOF_ToDegree(dir)						((dir) * 180 / MOF_MATH_PI)

//!�C�[�Y�Z�o
#define		MOF_EaseTime(t,e)						((1 - (e)) * (t) + (e) * (t) * (t))

//!���`���
#define		MOF_LERP(s,e,t)							((s) + ((e) - (s)) * (t))

//!���`���
#define		MOF_LINSTEP(s,e,p)						((((p) < (s)) ? (0) : (((e) < (p)) ? (1) : (MofFloat)((p) - (s)) / (MofFloat)((e) - (s)))))

//!�͈͓��N���b�s���O
#define		MOF_CLIPING(x,l,h)						((((x) < (l)) ? (l) : (((h) < (x)) ? (h) : (x))))

//!�ő�
#define		MOF_MAX(a,b)							(((a) > (b)) ? (a) : (b))

//!�ŏ�
#define		MOF_MIN(a,b)							(((a) < (b)) ? (a) : (b))

//!MofU64�ő吔
#define		MOF_U64_MAX								0xffffffffffffffff

//!MofU32�ő吔
#define		MOF_U32_MAX								0xffffffff

//!MofS32�ŏ���
#define		MOF_S32_MIN								(-2147483647 - 1)

//!MofS32�ő吔
#define		MOF_S32_MAX								2147483647

//!MofU16�ő吔
#define		MOF_U16_MAX								0xffff

//!MofS16�ŏ���
#define		MOF_S16_MIN								(-32768)

//!MofS16�ő吔
#define		MOF_S16_MAX								32767

//!MofU8�ő吔
#define		MOF_U8_MAX								0xff

//!MofS8�ŏ���
#define		MOF_S8_MIN								(-128)

//!MofS8�ő吔
#define		MOF_S8_MAX								127

//!�A���O�����K���i0 <= a < 360.0f)
#define		MOF_NORMALIZE_DEGREEANGLE(a)			(((a) >= 360.0f) ? (a) -= 360.0f : (((a) < 0.0f) ? (a) += 360.0f : (a)))

//!���W�A���A���O�����K���i0 <= a < MOF_MATH_2PI)
#define		MOF_NORMALIZE_RADIANANGLE(a)			(((a) >= MOF_MATH_2PI) ? (a) -= MOF_MATH_2PI : (((a) < 0.0f) ? (a) += MOF_MATH_2PI : (a)))

//!�A���O���i-180 <= a < 180.0f)
#define		MOF_ROTDIRECTION_DEGREEANGLE(a)			(((a) > 180.0f) ? (a) -= 180.0f : (((a) < -180.0f) ? (a) += 180.0f : (a)))

//!���W�A���A���O���i-MOF_MATH_PI <= a < MOF_MATH_PI)
#define		MOF_ROTDIRECTION_RADIANANGLE(a)			(((a) > MOF_MATH_PI) ? (a) -= MOF_MATH_2PI : (((a) < -MOF_MATH_PI) ? (a) += MOF_MATH_2PI : (a)))

//!�������߂�
#define		MOF_SQUARE(x)							((x) * (x))

//!MofFloat,MofU32�ϊ�
#define		MOF_FLOAT_AS_U32(x)						(*(LPMofU32)&(x))

//!MofFloat Most 0
#define		MOF_FLOATALMOST_ZERO(x)					((MOF_FLOAT_AS_U32(x) & 0x7f800000L) == 0)

//!Raoundup
#define		MOF_ROUNDUP(size,align)					((size + (align - 1u)) & (~(align - 1u)))

//�^�C�v�ɂ��Z�p�֐��u������
#if			(MOF_DECIMALTYPE == MOF_DECIMALTYPE_FLOAT)

//!������
#define		MOF_SQRT								sqrtf
//!��Βl
#define		MOF_ABS(x)								(((x) >= 0) ? (x) : (-(x)))
//!�R�T�C��
#define		MOF_COS									cosf
//!�T�C��
#define		MOF_SIN									sinf
//!�^���W�F���g
#define		MOF_TAN									tanf
//!�A�[�N�R�T�C��
#define		MOF_ACOS								acosf
//!�A�[�N�T�C��
#define		MOF_ASIN								asinf
//!�A�[�N�^���W�F���g
#define		MOF_ATAN								atanf
//!�A�[�N�^���W�F���g
#define		MOF_ATAN2								atan2f
//!�搔
#define		MOF_POW									powf
//!��]
#define		MOF_FMOD								fmodf
//!�w���ϊ�
#define		MOF_EXP									expf
//!�ΐ��ϊ�
#define		MOF_LOG									logf
//!�؎̂�
#define		MOF_FLOOR(a,b)							(floorf((a) * (b) + 0.01f) / (MofDecimal)(b))
//!�؂�グ
#define		MOF_CEILING(a,b)						(ceilf((a) * (b)) / (MofDecimal)(b))
//!�l�̌ܓ�
#define		MOF_ROUND(a,b)							(floorf((a) * (b) + 0.5f) / (MofDecimal)(b))
//�I��
#define		MOF_APPROXIMATELY(a,b)					((MOF_ABS(a - b) < 0.00001f ? true : false))

#else

//!������
#define		MOF_SQRT								sqrt
//!��Βl
#define		MOF_ABS(x)								(((x) >= 0) ? (x) : -(x))
//!�R�T�C��
#define		MOF_COS									cos
//!�T�C��
#define		MOF_SIN									sin
//!�^���W�F���g
#define		MOF_TAN									tan
//!�A�[�N�R�T�C��
#define		MOF_ACOS								acos
//!�A�[�N�T�C��
#define		MOF_ASIN								asin
//!�A�[�N�^���W�F���g
#define		MOF_ATAN								atan
//!�A�[�N�^���W�F���g
#define		MOF_ATAN2								atan2
//!�搔
#define		MOF_POW									pow
//!��]
#define		MOF_FMOD								fmod
//!�w���ϊ�
#define		MOF_EXP									exp
//!�ΐ��ϊ�
#define		MOF_LOG									log
//!�؎̂�
#define		MOF_FLOOR(a,b)							(floor((a) * (b) + 0.01) / (MofDecimal)(b))
//!�؂�グ
#define		MOF_CEILING(a,b)						(ceil((a) * (b)) / (MofDecimal)(b))
//!�l�̌ܓ�
#define		MOF_ROUND(a,b)							(floor((a) * (b) + 0.5) / (MofDecimal)(b))
//�I��
#define		MOF_APPROXIMATELY(a,b)					((MOF_ABS(a - b) < 0.00001f ? true : false))

#endif		//#if			(MOF_DECIMALTYPE == MOF_DECIMALTYPE_FLOAT)

//�J���[���o���p�L�[
#define		MOF_RED_KEY								0x00ff0000
#define		MOF_GREEN_KEY							0x0000ff00
#define		MOF_BLUE_KEY							0x000000ff
#define		MOF_ALPHA_KEY							0xff000000
#define		MOF_FToColor(c)							((MofU8)(MOF_CLIPING(c,0.0f,1.0f) * MOF_U8_MAX))

//�F�w��p
#define		MOF_ARGB(a,r,g,b)						((MofU32)((((a) & 0xff) << 24) | (((r) & 0xff) << 16) | (((g) & 0xff) << 8) | ((b) & 0xff)))
#define		MOF_XRGB(r,g,b)							((MofU32)((MOF_ALPHA_KEY) | (((r) & 0xff) << 16) | (((g) & 0xff) << 8) | ((b) & 0xff)))

//��
#define		MOF_COLOR_BLACK							MOF_XRGB(0,0,0)
#define		MOF_COLOR_CBLACK						MOF_XRGB(64,64,64)
#define		MOF_COLOR_HBLACK						MOF_XRGB(128,128,128)
#define		MOF_ALPHA_BLACK(a)						MOF_ARGB(a,0,0,0)
#define		MOF_ALPHA_CBLACK(a)						MOF_ARGB(a,64,64,64)
#define		MOF_ALPHA_HBLACK(a)						MOF_ARGB(a,128,128,128)

//��
#define		MOF_COLOR_WHITE							MOF_XRGB(255,255,255)
#define		MOF_COLOR_CWHITE						MOF_XRGB(192,192,192)
#define		MOF_COLOR_HWHITE						MOF_XRGB(128,128,128)
#define		MOF_ALPHA_WHITE(a)						MOF_ARGB(a,255,255,255)
#define		MOF_ALPHA_CWHITE(a)						MOF_ARGB(a,192,192,192)
#define		MOF_ALPHA_HWHITE(a)						MOF_ARGB(a,128,128,128)

//��
#define		MOF_COLOR_RED							MOF_XRGB(255,0,0)
#define		MOF_COLOR_HRED							MOF_XRGB(255,128,128)
#define		MOF_ALPHA_RED(a)						MOF_ARGB(a,255,0,0)
#define		MOF_ALPHA_HRED(a)						MOF_ARGB(a,255,128,128)

//��
#define		MOF_COLOR_GREEN							MOF_XRGB(0,255,0)
#define		MOF_COLOR_HGREEN						MOF_XRGB(128,255,128)
#define		MOF_ALPHA_GREEN(a)						MOF_ARGB(a,0,255,0)
#define		MOF_ALPHA_HGREEN(a)						MOF_ARGB(a,128,255,128)

//��
#define		MOF_COLOR_BLUE							MOF_XRGB(0,0,255)
#define		MOF_COLOR_HBLUE							MOF_XRGB(128,128,255)
#define		MOF_ALPHA_BLUE(a)						MOF_ARGB(a,0,0,255)
#define		MOF_ALPHA_HBLUE(a)						MOF_ARGB(a,128,128,255)

//���F
#define		MOF_COLOR_YELLOW						MOF_XRGB(255,255,0)
#define		MOF_COLOR_HYELLOW						MOF_XRGB(255,255,128)
#define		MOF_ALPHA_YELLOW(a)						MOF_ARGB(a,255,255,0)
#define		MOF_ALPHA_HYELLOW(a)					MOF_ARGB(a,255,255,128)

//�J���[���o���p�}�N��
#define		MOF_GetRed(c)							((c & MOF_RED_KEY) >> 16)
#define		MOF_GetGreen(c)							((c & MOF_GREEN_KEY) >> 8)
#define		MOF_GetBlue(c)							((c & MOF_BLUE_KEY))
#define		MOF_GetAlpha(c)							((c & MOF_ALPHA_KEY) >> 24)

namespace Mof {
	/*************************************************************************//*!
			@brief			�����Ă���r�b�g���𐔂���
			@param[in]		v			��

			@return			�r�b�g�̐�
	*//**************************************************************************/
	FORCE_INLINE MofS32 MOFCOUNTBIT(MofU8 v) {
		unsigned count = (v & 0x55) + ((v >> 1) & 0x55);
		count = (count & 0x33) + ((count >> 2) & 0x33);
		return (count & 0x0f) + ((count >> 4) & 0x0f);
	}
	/*************************************************************************//*!
			@brief			�����Ă���r�b�g���𐔂���
			@param[in]		v			��

			@return			�r�b�g�̐�
	*//**************************************************************************/
	FORCE_INLINE MofS32 MOFCOUNTBIT(MofU16 v) {
		unsigned short count = (v & 0x5555) + ((v >> 1) & 0x5555);
		count = (count & 0x3333) + ((count >> 2) & 0x3333);
		count = (count & 0x0f0f) + ((count >> 4) & 0x0f0f);
		return (count & 0x00ff) + ((count >> 8) & 0x00ff);
	}
	/*************************************************************************//*!
			@brief			�����Ă���r�b�g���𐔂���
			@param[in]		v			��

			@return			�r�b�g�̐�
	*//**************************************************************************/
	FORCE_INLINE MofS32 MOFCOUNTBIT(MofU32 v) {
		unsigned count = (v & 0x55555555) + ((v >> 1) & 0x55555555);
		count = (count & 0x33333333) + ((count >> 2) & 0x33333333);
		count = (count & 0x0f0f0f0f) + ((count >> 4) & 0x0f0f0f0f);
		count = (count & 0x00ff00ff) + ((count >> 8) & 0x00ff00ff);
		return (count & 0x0000ffff) + ((count >> 16) & 0x0000ffff);
	}
	/*************************************************************************//*!
			@brief			�����Ă���r�b�g���𐔂���
			@param[in]		v			��

			@return			�r�b�g�̐�
	*//**************************************************************************/
	FORCE_INLINE MofS32 MOFCOUNTBIT(MofU64 v) {
		unsigned __int64 count = (v & 0x5555555555555555) + ((v >> 1) & 0x5555555555555555);
		count = (count & 0x3333333333333333) + ((count >> 2) & 0x3333333333333333);
		count = (count & 0x0f0f0f0f0f0f0f0f) + ((count >> 4) & 0x0f0f0f0f0f0f0f0f);
		count = (count & 0x00ff00ff00ff00ff) + ((count >> 8) & 0x00ff00ff00ff00ff);
		count = (count & 0x0000ffff0000ffff) + ((count >> 16) & 0x0000ffff0000ffff);
		return (int)((count & 0x00000000ffffffff) + ((count >> 32) & 0x00000000ffffffff));
	}
	/*************************************************************************//*!
			@brief			MSB�̈ʒu�����߂�
			@param[in]		v			��

			@return			MSB
	*//**************************************************************************/
	FORCE_INLINE MofS32 MOFMSB(MofU8 v) {
		v |= (v >> 1);
		v |= (v >> 2);
		v |= (v >> 4);
		return MOFCOUNTBIT(v) - 1;
	}
	/*************************************************************************//*!
			@brief			MSB�̈ʒu�����߂�
			@param[in]		v			��

			@return			MSB
	*//**************************************************************************/
	FORCE_INLINE MofS32 MOFMSB(MofU16 v) {
		v |= (v >> 1);
		v |= (v >> 2);
		v |= (v >> 4);
		v |= (v >> 8);
		return MOFCOUNTBIT(v) - 1;
	}
	/*************************************************************************//*!
			@brief			MSB�̈ʒu�����߂�
			@param[in]		v			��

			@return			MSB
	*//**************************************************************************/
	FORCE_INLINE MofS32 MOFMSB(MofU32 v) {
		v |= (v >> 1);
		v |= (v >> 2);
		v |= (v >> 4);
		v |= (v >> 8);
		v |= (v >> 16);
		return MOFCOUNTBIT(v) - 1;
	}
	/*************************************************************************//*!
			@brief			MSB�̈ʒu�����߂�
			@param[in]		v			��

			@return			MSB
	*//**************************************************************************/
	FORCE_INLINE MofS32 MOFMSB(MofU64 v) {
		v |= (v >> 1);
		v |= (v >> 2);
		v |= (v >> 4);
		v |= (v >> 8);
		v |= (v >> 16);
		v |= (v >> 32);
		return MOFCOUNTBIT(v) - 1;
	}
}

#endif

//[EOF]