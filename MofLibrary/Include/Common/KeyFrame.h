/*************************************************************************//*!
					
					@file	KeyFrame.h
					@brief	�L�[�t���[���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__KEYFRAME__H__

#define		__KEYFRAME__H__

//INCLUDE
#include	"DynamicArray.h"
#include	"../Math/Quaternion.h"
#include	"../Collision/Rectangle.h"
#include	"../Collision/Circle.h"

//DEFINE

//!���
#define		MOF_KEYFRAMEINTERPOLATIONCOUNT		16

namespace Mof {
	
	/*******************************//*!
	@brief	�L�[�t���[����ԕ��@��

			�L�[�t���[����ԕ��@�񋓁B

	@author	CDW
	*//********************************/
	typedef enum tag_KEYFRAMEINTERPOLATIONTYPE {
		KEYINTERPOLATION_NONE,						//!<��Ԃ��s��Ȃ�
		KEYINTERPOLATION_LINEAR,					//!<���j�A���
		KEYINTERPOLATION_EASE,						//!<�ȈՃC�[�Y
		KEYINTERPOLATION_HERMITE,					///<�G���~�[�g
		KEYINTERPOLATION_BEZIER1,					///<�x�W�F
		KEYINTERPOLATION_BEZIER2,					///<�x�W�F
		KEYINTERPOLATION_BEZIER2_VECTOR3,			///<�x�W�F
		KEYINTERPOLATION_BEZIER2_VECTOR4,			///<�x�W�F
	}KeyFrameInterpolationType;

	/*******************************//*!
	@brief	�L�[�t���[���N���X

			�L�[�t���[���N���X�B

	@author	CDW
	*//********************************/
	template < typename T >
	class MOFLIBRARY_API CKeyFrame : public IMofBase , public IMofCopyObject< CKeyFrame< T > > {
		template < typename T2 > friend class CKeyFrameArray;
	protected:
		/*******************//*!
		�t���[�����e
		*//********************/
		T								m_Value;
		/*******************//*!
		�t���[���ݒu����
		*//********************/
		MofFloat						m_Time;
		/*******************//*!
		�t���O
		*//********************/
		MofU32							m_Flag;
		/*******************//*!
		��ԕ��@
		*//********************/
		KeyFrameInterpolationType		m_InterpolationType;
		/*******************//*!
		��ԏ��
		*//********************/
		MofFloat						m_InterpolationValue[MOF_KEYFRAMEINTERPOLATIONCOUNT];
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CKeyFrame();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		v			�v�f
				@param[in]		t			����
				@param[in]		f			�t���O
				@param[in]		inter		��ԕ��@
				@param[in]		pinterval	��ԃp�����[�^�[

				@return			None
		*//**************************************************************************/
		CKeyFrame(const T& v,MofFloat t,MofU32 f,KeyFrameInterpolationType inter,LPCMofFloat pinterval);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�t���[��

				@return			None
		*//**************************************************************************/
		CKeyFrame(const CKeyFrame< T >& pObj);
		
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CKeyFrame();
		
		/*************************************************************************//*!
				@brief			�R�s�[�L�[�t���[���̍쐬
				@param			None

				@return			�쐬���ꂽ�R�s�[�L�[�t���[��<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		CKeyFrame< T >* CreateCopyObject(void) const;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�f�[�^�ݒ�
				@param[in]		v			�f�[�^
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool SetValue(T& v);
		/*************************************************************************//*!
				@brief			���Ԑݒ�
				@param[in]		t			�f�[�^
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool SetTime(MofFloat t);
		/*************************************************************************//*!
				@brief			��Ԑݒ�
				@param[in]		inter		��ԕ��@
				@param[in]		pinterval	��ԃp�����[�^�[

				@return			None
		*//**************************************************************************/
		MofBool SetInterpolation(KeyFrameInterpolationType inter, LPCMofFloat pinterval);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���Ԏ擾
				@param			None

				@return			����
		*//**************************************************************************/
		MofFloat GetTime(void) const;
		/*************************************************************************//*!
				@brief			�t���O�擾
				@param			None

				@return			�t���O
		*//**************************************************************************/
		MofU32 GetFlag(void) const;
		/*************************************************************************//*!
				@brief			��ԕ��@�擾
				@param			None

				@return			��ԕ��@
		*//**************************************************************************/
		KeyFrameInterpolationType GetInterpolationType(void) const;
		/*************************************************************************//*!
				@brief			��ԏ��擾
				@param			None

				@return			��ԏ��
		*//**************************************************************************/
		LPCMofFloat GetInterpolationValue(void) const;
		/*************************************************************************//*!
				@brief			�f�[�^�擾
				@param			None

				@return			�f�[�^
		*//**************************************************************************/
		T& GetValue(void);
		/*************************************************************************//*!
				@brief			�f�[�^�擾
				@param			None

				@return			�f�[�^
		*//**************************************************************************/
		const T& GetValue(void) const;

		//�N���X��{��`
		MOF_LIBRARYCLASS(CKeyFrame,MOF_KEYFRAMECLASS_ID);
	};

	//INCLUDE
	#include	"KeyFrame.inl"

	//�u������
	typedef CKeyFrame< MofBool >			CBoolKeyFrame,*LPBoolKeyFrame;
	typedef CKeyFrame< MofS32 >			CS32KeyFrame,*LPS32KeyFrame;
	typedef CKeyFrame< MofU32 >			CU32KeyFrame,*LPU32KeyFrame;
	typedef CKeyFrame< MofFloat >		CFloatKeyFrame,*LPFloatKeyFrame;
	typedef CKeyFrame< Vector2 >		CVector2KeyFrame,*LPVector2KeyFrame;
	typedef CKeyFrame< Vector3 >		CVector3KeyFrame,*LPVector3KeyFrame;
	typedef CKeyFrame< Vector4 >		CVector4KeyFrame,*LPVector4KeyFrame;
	typedef CKeyFrame< Quaternion >		CQuaternionKeyFrame,*LPQuaternionKeyFrame;
	typedef CKeyFrame< Rectangle >		CRectangleKeyFrame,*LPRectangleKeyFrame;
}

#endif

//[EOF]