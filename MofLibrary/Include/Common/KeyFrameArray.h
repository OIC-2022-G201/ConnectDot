/*************************************************************************//*!
					
					@file	KeyFrameArray.h
					@brief	�L�[�t���[���z��N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__KEYFRAMEARRAY__H__

#define		__KEYFRAMEARRAY__H__

//INCLUDE
#include	"KeyFrame.h"

//!�x�W�F�œK�����s��
#define		MOF_KEYINTERPOLATIONBEZIER1COUNT		8
#define		MOF_KEYINTERPOLATIONBEZIER2COUNT		16

namespace Mof {
	
	/*******************************//*!
	@brief	�L�[�t���[���z��Ǘ��t���O��

			�L�[�t���[���z��̊Ǘ��t���O�񋓁B

	@author	CDW
	*//********************************/
	enum tag_KEYFRAMEARRAYFLAG {
		KEYFRAMEARRAY_ARRAYMEMBERDELETE		=		DYNAMICARRAY_ARRAYMEMBERDELETE,
		KEYFRAMEARRAY_ARRAYMEMBERCOPY		=		DYNAMICARRAY_ARRAYMEMBERCOPY,
		
		KEYFRAMEARRAY_LOOPALLFRAME			=		0x00010000,
		KEYFRAMEARRAY_LOOPSTARTFRAME		=		0x00020000,

		KEYFRAMEARRAY_FLAGALL				=		0xFFFFFFFF,
		KEYFRAMEARRAY_LOOPFLAG				=		KEYFRAMEARRAY_LOOPALLFRAME | KEYFRAMEARRAY_LOOPSTARTFRAME,
	};

	/*******************************//*!
	@brief	�L�[�t���[���z��N���X�������ꉻ��`

			�L�[�t���[���z��N���X�̓����e���v���[�g��
			��`��������N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CKeyFrameArrayImpl {
	protected:
		/*************************************************************************//*!
				@brief			�������
				@param[in]		Data1		�O�̃L�[�̒l
				@param[in]		Data2		���̃L�[�̒l
				@param[in]		t			��Ԏ���
				@param[out]		Out			�o��

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		template < typename TX > struct InterpolationImpl {
			static MofBool GetInterpolationValue(const TX& Data1,const TX& Data2, const MofFloat t,TX& Out)
			{
				Out = Data1 + (TX)((Data2 - Data1) * t);
				return TRUE;
			}
			static MofBool GetInterpolateBezierValue(const TX& Data1, const TX& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, TX& Out)
			{
				MofFloat vt = CKeyFrameArrayImpl::GetInterpolateBezierTime(x1, x2, y1, y2, pt, nt, t);
				return GetInterpolationValue(Data1, Data2, vt, Out);
			}
			static MofBool GetVector3TimeInterpolationValue(const TX& Data1, const TX& Data2, const Vector3& t, TX& Out)
			{
				Out = Data1 + (TX)((Data2 - Data1) * t.x);
				return TRUE;
			}
			static MofBool GetVector4TimeInterpolationValue(const TX& Data1, const TX& Data2, const Vector4& t, TX& Out)
			{
				Out = Data1 + (TX)((Data2 - Data1) * t.x);
				return TRUE;
			}
		};
		/*************************************************************************//*!
				@brief			�G���~�[�g��ԂŌ��݂̎��Ԃ����߂�
				@param[in]		x1			X�R���g���[���|�C���g
				@param[in]		x2			X�R���g���[���|�C���g
				@param[in]		x			���݈ʒu
				
				@return			����
		*//**************************************************************************/
		static MofFloat GetInterpolateHermiteTime(const MofFloat x1, const MofFloat x2, const MofFloat t);
		/*************************************************************************//*!
				@brief			�R���x�W�F��ԂŌ��݂̎��Ԃ����߂�
				@param[in]		x1			X�R���g���[���|�C���g
				@param[in]		x2			X�R���g���[���|�C���g
				@param[in]		y1			Y�R���g���[���|�C���g
				@param[in]		y2			Y�R���g���[���|�C���g
				@param[in]		pt			�O�̃L�[�̎���
				@param[in]		nt			���̃L�[�̎���
				@param[in]		t			���݈ʒu
				
				@return			����
		*//**************************************************************************/
		static MofFloat GetInterpolateBezierTime(const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t);
		/*************************************************************************//*!
				@brief			�R���x�W�F��ԂŌ��݂̎��Ԃ����߂�
				@param[in]		x1			X�R���g���[���|�C���g
				@param[in]		x2			X�R���g���[���|�C���g
				@param[in]		y1			Y�R���g���[���|�C���g
				@param[in]		y2			Y�R���g���[���|�C���g
				@param[in]		x			���݈ʒu
				
				@return			����
		*//**************************************************************************/
		static MofFloat GetInterpolateBezierTime(const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat x);
	public:
	};

	/*******************************//*!
	@brief	�L�[�t���[���z��N���X

			�L�[�t���[���z��N���X�B

	@author	CDW
	*//********************************/
	template < typename T >
	class MOFLIBRARY_API CKeyFrameArray : public CDynamicArray< CKeyFrame< T >* > , public CKeyFrameArrayImpl {
	protected:
		/*************************************************************************//*!
				@brief			�f�[�^�̃\�[�g�����s�����r�֐�
				@param[in]		A			�t���[���`
				@param[in]		B			�t���[���a

				@return			<0			A���O
								>0			B���O
								0			����
		*//**************************************************************************/
		static int KeySortCompare(const void* A,const void* B);
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CKeyFrameArray();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�z��

				@return			None
		*//**************************************************************************/
		CKeyFrameArray(const CKeyFrameArray< T >& pObj);
		
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CKeyFrameArray();

		/*************************************************************************//*!
				@brief			�L�[�t���[���̒ǉ�
				@param[in]		Time		�ǉ��L�[�t���[������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AddKeyFrame(MofFloat Time);
		/*************************************************************************//*!
				@brief			�L�[�t���[���̒ǉ�
				@param[in]		Data		�ǉ��L�[�t���[�����e
				@param[in]		Time		�ǉ��L�[�t���[������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool AddKeyFrame(const T& Data,MofFloat Time);
		/*************************************************************************//*!
				@brief			�L�[�t���[���̍폜
				@param[in]		Time		�폜�L�[�t���[������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool DeleteKeyFrame(MofFloat Time);
		
		/*************************************************************************//*!
				@brief			�z��̃\�[�g�����s����
				@param[in]		pFunc			��r�֐�
				
				@return			TRUE			����<br>
								����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Sort(int (*pFunc)(const void *, const void *) = KeySortCompare);
		
		/*************************************************************************//*!
				@brief			���[�v�t���O�����邩�𔻒肷��
				@param			None
				
				@return			TRUE			���[�v����<br>
								FALSE			���[�v���Ȃ�
		*//**************************************************************************/
		virtual MofBool IsLoop(void);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���[�v�t���O�̐ݒ�
				@param[in]		Loop		���[�v�t���O<br>
											���[�v��L���ɂ���ꍇ��KEYFRAMEARRAY_LOOPALLFRAME��KEYFRAMEARRAY_LOOPSTARTFRAME���w��<br>
											���[�v�𖳌��ɂ���ꍇ��0���w�肷��B
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool SetLoop(MofU32 Loop);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ŏ��̃L�[�t���[���̎��Ԏ擾
				@param			None

				@return			�ŏ��̃L�[�t���[���̎���
		*//**************************************************************************/
		MofFloat GetStartKeyTime(void) const;
		/*************************************************************************//*!
				@brief			�ŏI�̃L�[�t���[���̎��Ԏ擾
				@param			None

				@return			�ŏI�̃L�[�t���[���̎���
		*//**************************************************************************/
		MofFloat GetLastKeyTime(void) const;
		/*************************************************************************//*!
				@brief			���̎��Ԃ̃��[�v�̏I�����Ԏ擾
				@param[in]		t			����

				@return			���̎��Ԃ̃��[�v�̏I������
		*//**************************************************************************/
		MofFloat GetLoopLastTime(MofFloat t) const;
		/*************************************************************************//*!
				@brief			�w�莞�Ԃ̃L�[���擾
				@param[in]		t			����

				@return			NULL		�L�[��������Ȃ�<br>
								����ȊO	�������L�[�t���[��
		*//**************************************************************************/
		CKeyFrame< T >* GetKeyFrame(MofFloat t) const;
		/*************************************************************************//*!
				@brief			�w�莞�Ԃ̃L�[�ԍ����擾
				@param[in]		t			����

				@return			�z��v�f�ԍ�
		*//**************************************************************************/
		MofU32 GetKeyFrameNo(MofFloat t) const;
		/*************************************************************************//*!
				@brief			�w�莞�Ԃ̃L�[���擾
				@param[in]		t			����

				@return			NULL		�L�[��������Ȃ�<br>
								����ȊO	�������L�[�t���[��
		*//**************************************************************************/
		CKeyFrame< T >* GetNowKeyFrame(MofFloat t) const;
		/*************************************************************************//*!
				@brief			�w�莞�Ԃ̃L�[�ԍ����擾
				@param[in]		t			����

				@return			�z��v�f�ԍ�
		*//**************************************************************************/
		MofU32 GetNowKeyFrameNo(MofFloat t) const;
		/*************************************************************************//*!
				@brief			�w�莞�Ԃ̃L�[���擾
				@param[in]		t			����

				@return			NULL		�L�[��������Ȃ�<br>
								����ȊO	�������L�[�t���[��
		*//**************************************************************************/
		CKeyFrame< T >* GetNextKeyFrame(MofFloat t) const;
		/*************************************************************************//*!
				@brief			�w�莞�Ԃ̃L�[�ԍ����擾
				@param[in]		t			����

				@return			�z��v�f�ԍ�
		*//**************************************************************************/
		MofU32 GetNextKeyFrameNo(MofFloat t) const;
		/*************************************************************************//*!
				@brief			�w�莞�Ԃ̃L�[��Ԃ��擾
				@param[in]		Time		����
				@param[out]		Out			�o��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		MofBool GetTimeState(MofFloat Time,T& Out) const;

		//�N���X��{��`
		MOF_LIBRARYCLASS(CKeyFrameArray,MOF_KEYFRAMEARRAYCLASS_ID);
	};

	//INCLUDE
	#include	"KeyFrameArray.inl"

	//�u������
	typedef CKeyFrameArray< MofBool >		CBoolKeyFrameArray,*LPBoolKeyFrameArray;
	typedef CKeyFrameArray< MofS32 >		CS32KeyFrameArray,*LPS32KeyFrameArray;
	typedef CKeyFrameArray< MofU32 >		CU32KeyFrameArray,*LPU32KeyFrameArray;
	typedef CKeyFrameArray< MofFloat >		CFloatKeyFrameArray,*LPFloatKeyFrameArray;
	typedef CKeyFrameArray< Vector2 >		CVector2KeyFrameArray, *LPVector2KeyFrameArray;
	typedef CKeyFrameArray< Vector3 >		CVector3KeyFrameArray,*LPVector3KeyFrameArray;
	typedef CKeyFrameArray< Vector4 >		CVector4KeyFrameArray,*LPVector4KeyFrameArray;
	typedef CKeyFrameArray< Quaternion >	CQuaternionKeyFrameArray,*LPQuaternionKeyFrameArray;
	typedef CKeyFrameArray< Rectangle >		CRectangleKeyFrameArray,*LPRectangleKeyFrameArray;
}

#endif

//[EOF]