/*************************************************************************//*!
					
					@file	Ray.h
					@brief	���C���Z�֘A<br>
							���C���g�p���������蔻��p�̃��C�\���̂ƁA�e��`��p�̐ڐG����֐���񋟂���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__RAY__H__

#define		__RAY__H__

//INCLUDE
#include	"Sphere.h"
#include	"Box.h"

namespace Mof {

	/*******************************//*!
	@brief	3D���C�\����

			3D���C���������߂̍\���́B<br>
			���C�̎n�_(Position)�ƕ���(Direction)�Ń��C�̏���\���B

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT Ray3D {
		Vector3				Position;					//!<�n�_
		Vector3				Direction;					//!<����
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		Ray3D();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pos			���W
				@param[in]		dir			����

				@return			None
		*//**************************************************************************/
		Ray3D(const Vector3& pos,const Vector3& dir);
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pv			���W

				@return			None
		*//**************************************************************************/
		Ray3D(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[���C

				@return			None
		*//**************************************************************************/
		Ray3D(const Ray3D& pObj);
		
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			+=���Z
		*//**************************************************************************/
		Ray3D& operator += ( const Vector3& v );
		/*************************************************************************//*!
				@brief			+=���Z
		*//**************************************************************************/
		Ray3D& operator += ( const Ray3D& v );
		/*************************************************************************//*!
				@brief			-=���Z
		*//**************************************************************************/
		Ray3D& operator -= ( const Vector3& v );
		/*************************************************************************//*!
				@brief			-=���Z
		*//**************************************************************************/
		Ray3D& operator -= ( const Ray3D& v );
		/*************************************************************************//*!
				@brief			Vector3�Ƃ�+���Z
		*//**************************************************************************/
		Ray3D operator + ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Ray3D�Ƃ�+���Z
		*//**************************************************************************/
		Ray3D operator + ( const Ray3D& v ) const;
		/*************************************************************************//*!
				@brief			Vector3�Ƃ�-���Z
		*//**************************************************************************/
		Ray3D operator - ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Ray3D�Ƃ�-���Z
		*//**************************************************************************/
		Ray3D operator - ( const Ray3D& v ) const;
	}Ray3D;
	
	/*******************************//*!
	@brief	3D���C���Z�N���X

			Ray3D�\���̂��������߂̃X�^�e�B�b�N�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRay3DUtilities {
	public:
		/*************************************************************************//*!
				@brief			���C�̃��[�J���ϊ�<br>
								ray��mat�Ŏw�肳�ꂽ�s��̃��[�J����Ԃɕϊ��������Ȃ�out�Ɋi�[����B
				@param[in]		ray			�ϊ����C
				@param[in]		mat			�ϊ��s��
				@param[out]		out			�ϊ��ς݃��C

				@return			None
		*//**************************************************************************/
		static void ToLocal(const Ray3D& ray, const Matrix44& mat, Ray3D& out);

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����ʂƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		pos			���ʓ_
				@param[in]		nrm			�@��
				@param[in]		ray			���背�C
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionPlane(const Vector3& pos,const Vector3& nrm,const Ray3D& ray,MofFloat& od);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����ʂƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		pos			���ʓ_
				@param[in]		nrm			�@��
				@param[in]		rpos		���C�̍��W
				@param[in]		rdir		���C�̕���
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionPlane(const Vector3& pos,const Vector3& nrm, const Vector3& rpos, const Vector3& rdir,MofFloat& od);

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		sph			���苅
				@param[in]		ray			���背�C
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionSphere(const Sphere& sph,const Ray3D& ray,MofFloat& od);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵��AABB�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		aabb		����AABB
				@param[in]		ray			���背�C
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionAABB(const BoxAABB& aabb,const Ray3D& ray,MofFloat& od);
		
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���O�p�`�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		ptc			�O�p�`
				@param[in]		ray			���背�C
				@param[in,out]	od			������E����/�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionTriangle(LPTRIANGLECOLLISIONCACHE ptc, const Ray3D& ray, MofFloat& od);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���O�p�`�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		ta			�O�p�`���_�P
				@param[in]		tb			�O�p�`���_�Q
				@param[in]		tc			�O�p�`���_�R
				@param[in]		ray			���背�C
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc,const Ray3D& ray,MofFloat& od);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���O�p�`�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		ta			�O�p�`���_�P
				@param[in]		tb			�O�p�`���_�Q
				@param[in]		tc			�O�p�`���_�R
				@param[in]		ray			���背�C
				@param[out]		od			�o�͐ڐG����
				@param[out]		on			�o�͎O�p�`�@��

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc,const Ray3D& ray,MofFloat& od,Vector3& on);
		
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���O�p�`�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		ptc			�O�p�`
				@param[in]		pos			���C�̍��W
				@param[in]		dir			���C�̕���
				@param[in,out]	od			������E����/�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionTriangle(LPTRIANGLECOLLISIONCACHE ptc, const Vector3& pos, const Vector3& dir, MofFloat& od);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���O�p�`�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		ta			�O�p�`���_�P
				@param[in]		tb			�O�p�`���_�Q
				@param[in]		tc			�O�p�`���_�R
				@param[in]		pos			���C�̍��W
				@param[in]		dir			���C�̕���
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc, const Vector3& pos, const Vector3& dir,MofFloat& od);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���O�p�`�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		ta			�O�p�`���_�P
				@param[in]		tb			�O�p�`���_�Q
				@param[in]		tc			�O�p�`���_�R
				@param[in]		pos			���C�̍��W
				@param[in]		dir			���C�̕���
				@param[out]		od			�o�͐ڐG����
				@param[out]		on			�o�͎O�p�`�@��

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc, const Vector3& pos, const Vector3& dir,MofFloat& od,Vector3& on);

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B
				@param[in]		pGeom		����W�I���g��
				@param[in]		ray			���背�C

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionGeometry(LPGeometry pGeom, const Ray3D& ray);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�|���S���̏���out�Ɋi�[����
				@param[in]		pGeom		����W�I���g��
				@param[in]		ray			���背�C
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionGeometry(LPGeometry pGeom, const Ray3D& ray, COLLISIONOUTGEOMETRY& out);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B
				@param[in]		pGeom		����W�I���g��
				@param[in]		ray			���背�C
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionGeometry(LPGeometry pGeom, const Ray3D& ray, IsTriangleCollision pFunc);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�|���S���̏���out�Ɋi�[����
				@param[in]		pGeom		����W�I���g��
				@param[in]		ray			���背�C
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionGeometry(LPGeometry pGeom, const Ray3D& ray, IsTriangleCollision pFunc, COLLISIONOUTGEOMETRY& out);

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMesh pMesh, const Ray3D& ray);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMesh pMesh, const Ray3D& ray, COLLISIONOUTMESH& out);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMesh pMesh, const Ray3D& ray, IsTriangleCollision pFunc);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMesh pMesh, const Ray3D& ray, IsTriangleCollision pFunc, COLLISIONOUTMESH& out);

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, COLLISIONOUTGEOMETRY& out);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, COLLISIONOUTMESHCONTAINER& out);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, IsTriangleCollision pFunc);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, IsTriangleCollision pFunc, COLLISIONOUTGEOMETRY& out);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[in]		ray			���背�C
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		static MofBool CollisionMesh(LPMeshContainer pMesh, const Ray3D& ray, IsTriangleCollision pFunc, COLLISIONOUTMESHCONTAINER& out);
	private:
		//�쐬���֎~����
		CRay3DUtilities(){};
		CRay3DUtilities(const CRay3DUtilities& pObj){};
	};
	
	/*******************************//*!
	@brief	2D���C�N���X

			2D���C���������߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRay3D : public Ray3D , public IMofBase {
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CRay3D();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pos			���W
				@param[in]		dir			����

				@return			None
		*//**************************************************************************/
		CRay3D(const Vector3& pos,const Vector3& dir);
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pv			���W

				@return			None
		*//**************************************************************************/
		CRay3D(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[���C

				@return			None
		*//**************************************************************************/
		CRay3D(const Ray3D& pObj);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[���C

				@return			None
		*//**************************************************************************/
		CRay3D(const CRay3D& pObj);
		
		/*************************************************************************//*!
				@brief			�ړ�<br>
								m�ړ�����B
				@param[in]		m			�ړ���
				
				@return			None
		*//**************************************************************************/
		void Translation(const Vector3& m);
		/*************************************************************************//*!
				@brief			�ړ�<br>
								pos�̈ʒu�Ɉړ�����B
				@param[in]		pos			�ʒu
				
				@return			None
		*//**************************************************************************/
		void SetPosition(const Vector3& pos);

		/*************************************************************************//*!
				@brief			���C�̃��[�J���ϊ�<br>
								mat�Ŏw�肳�ꂽ�s��̃��[�J����Ԃɕϊ��������Ȃ��B
				@param[in]		mat			�ϊ��s��

				@return			None
		*//**************************************************************************/
		void ToLocal(Matrix44& mat);
		/*************************************************************************//*!
				@brief			���C�̃��[�J���ϊ�<br>
								mat�Ŏw�肳�ꂽ�s��̃��[�J����Ԃɕϊ��������Ȃ�out�Ɋi�[����B
				@param[in]		mat			�ϊ��s��
				@param[out]		out			�ϊ��ς݃��C

				@return			None
		*//**************************************************************************/
		void ToLocal(Matrix44& mat, Ray3D& out) const;

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����ʂƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		pos			���ʓ_
				@param[in]		nrm			�@��
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionPlane(const Vector3& pos,const Vector3& nrm,MofFloat& od) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		sph			���苅
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionSphere(const Sphere& sph,MofFloat& od) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵��AABB�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		aabb		����AABB
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionAABB(const BoxAABB& aabb, MofFloat& od) const;
		
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���O�p�`�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		ptc			�O�p�`
				@param[in,out]	od			������E����/�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionTriangle(LPTRIANGLECOLLISIONCACHE ptc, MofFloat& od) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���O�p�`�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		ta			�O�p�`���_�P
				@param[in]		tb			�O�p�`���_�Q
				@param[in]		tc			�O�p�`���_�R
				@param[out]		od			�o�͐ڐG����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc,MofFloat& od) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���O�p�`�ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG����܂ł̋�����od�ɓ����
				@param[in]		ta			�O�p�`���_�P
				@param[in]		tb			�O�p�`���_�Q
				@param[in]		tc			�O�p�`���_�R
				@param[out]		od			�o�͐ڐG����
				@param[out]		on			�o�͎O�p�`�@��

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionTriangle(const Vector3& ta,const Vector3& tb,const Vector3& tc,MofFloat& od,Vector3& on) const;

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B
				@param[in]		pGeom		����W�I���g��

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�|���S���̏���out�Ɋi�[����
				@param[in]		pGeom		����W�I���g��
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom, COLLISIONOUTGEOMETRY& out) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B
				@param[in]		pGeom		����W�I���g��
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom, IsTriangleCollision pFunc) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�|���S���̏���out�Ɋi�[����
				@param[in]		pGeom		����W�I���g��
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom, IsTriangleCollision pFunc, COLLISIONOUTGEOMETRY& out) const;

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pMesh		���胁�b�V��

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh, COLLISIONOUTMESH& out) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pMesh		���胁�b�V��
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh, IsTriangleCollision pFunc) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh, IsTriangleCollision pFunc, COLLISIONOUTMESH& out) const;

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pMesh		���胁�b�V��

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, COLLISIONOUTGEOMETRY& out) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, COLLISIONOUTMESHCONTAINER& out) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pMesh		���胁�b�V��
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, IsTriangleCollision pFunc) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pMesh		���胁�b�V��
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, IsTriangleCollision pFunc, COLLISIONOUTGEOMETRY& out) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pGeom		���胁�b�V��
				@param[in]		pFunc		����ȗ��p�֐��i���̊֐���TRUE��Ԃ����|���S���Ƃ�����������s���Ȃ��j
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, IsTriangleCollision pFunc, COLLISIONOUTMESHCONTAINER& out) const;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------

		/*************************************************************************//*!
				@brief			���
		*//**************************************************************************/
		CRay3D& operator = ( const Ray3D& v );

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTEQUAL(CRay3D,MOF_RAY3DCLASS_ID);
	};

	//�|�C���^�u������
	typedef CRay3D*				LPRay3D;

	#include	"Ray.inl"

}

#endif

//[EOF]