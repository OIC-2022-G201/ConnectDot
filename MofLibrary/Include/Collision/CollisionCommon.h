/*************************************************************************//*!
					
					@file	CollisionCommon.h
					@brief	���C�u�����̃R���W�����n��{��`���s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__COLLISIONCOMMON__H__

#define		__COLLISIONCOMMON__H__

//INCLUDE
#include	"../Math/Matrix44.h"
#include	"../Common/DynamicArray.h"

namespace Mof {

	//�O����`
	class IGeometry;
	typedef IGeometry*				LPGeometry;
	class IMesh;
	typedef IMesh*					LPMesh;
	class IMeshContainer;
	typedef IMeshContainer*			LPMeshContainer;

	/*******************************//*!
	@brief	�O�p�`�̐ڐG����p�L���b�V��

			�O�p�`�̐ڐG����p�L���b�V���\���́B<br>
			�W�I���g���Ƃ̐ڐG����̏�����s���ɃW�I���g�������ɕۑ������B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_TRIANGLECOLLISIONCACHE{
		MofU32					Index[3];					//!<�C���f�b�N�X
		Vector3					Vertex[3];					//!<���_
		Vector3					Edge[3];					//!<��
		Vector3					Normal;						//!<�@��

		MOF_ALIGNED_NEW_OPERATOR(tag_TRIANGLECOLLISIONCACHE);
	}TRIANGLECOLLISIONCACHE, *LPTRIANGLECOLLISIONCACHE;
	typedef CDynamicArray< LPTRIANGLECOLLISIONCACHE >		CGeometryCollisionCache, *LPGeometryCollisionCache;
	typedef MofBool(*IsTriangleCollision)(LPTRIANGLECOLLISIONCACHE);
	/*******************************//*!
	@brief	�W�I���g���Ƃ̐ڐG���o��

			�W�I���g���Ƃ̐ڐG���o�͍\���́B<br>
			CollisionGeometry���̐ڐG����֐��̏o�͂Ƃ��ė��p�����B<br>
			�ڐG�����|���S�����\������C���f�b�N�X���A�|���S���̖@���x�N�g���A�ڐG�ʒu�܂ł̋��������B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_COLLISIONOUTGEOMETRY{
		MofU32					Index1;						//!<�C���f�b�N�X�P
		MofU32					Index2;						//!<�C���f�b�N�X�Q
		MofU32					Index3;						//!<�C���f�b�N�X�R
		Vector3					Normal;						//!<�@��
		MofFloat				d;							//!<����

		MOF_ALIGNED_NEW_OPERATOR(tag_COLLISIONOUTGEOMETRY);
	}COLLISIONOUTGEOMETRY, *LPCOLLISIONOUTGEOMETRY;

	/*******************************//*!
	@brief	���b�V���Ƃ̐ڐG���o��

			���b�V���Ƃ̐ڐG���o�͍\���́B<br>
			�W�I���g���̐ڐG���ɉ����ڐG�����W�I���g���̃��b�V�����̗v�f�ԍ���������

	@author	CDW
	*//********************************/
	typedef struct tag_COLLISIONOUTMESH {
		MofU32					No;							//!<�ڐG�W�I���g���ԍ�
		COLLISIONOUTGEOMETRY	Geometry;					//!<�ڐG�W�I���g�����
	}COLLISIONOUTMESH, *LPCOLLISIONOUTMESH;

	/*******************************//*!
	@brief	���b�V���R���e�i�Ƃ̐ڐG���o��

			���b�V���R���e�i�Ƃ̐ڐG���o�͍\���́B<br>
			���b�V���̐ڐG���ɉ����ڐG�������b�V���̃R���e�i���̗v�f�ԍ���������

	@author	CDW
	*//********************************/
	typedef struct tag_COLLISIONOUTMESHCONTAINER {
		MofU32					No;							//!<�ڐG���b�V���ԍ�
		COLLISIONOUTMESH		Mesh;						//!<�ڐG���b�V�����
	}COLLISIONOUTMESHCONTAINER, *LPCOLLISIONOUTMESHCONTAINER;

}

#endif

//[EOF]