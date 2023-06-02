/*************************************************************************//*!
					
					@file	GraphicsUtilities.h
					@brief	�`��֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GRAPHICSUTILITIES__H__

#define		__GRAPHICSUTILITIES__H__

//INCLUDE
#include	"../Graphics/Graphics.h"

#include	"../Graphics/Geometry.h"
#include	"../Graphics/GeometryInstancedBase.h"

#include	"../Graphics/CameraBase.h"
#include	"../Graphics/DirectionalLight.h"

#include	"../Graphics/Shader.h"
#include	"../Graphics/ShaderBindBase.h"
#include	"../Graphics/ShaderEffect.h"

#include	"../Graphics/Font.h"
#include	"../Graphics/Sprite2DContainer.h"
#include	"../Graphics/Sprite3D.h"
#include	"../Graphics/SpriteMotionController.h"

#include	"../Graphics/RenderCommandProxy.h"

namespace Mof {

	/*******************************//*!
	@brief	�`��֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X

			�`��֘A�̔ėp�������܂Ƃ߂��X�^�e�B�b�N�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGraphicsUtilities {
	private:
		/*******************//*!
		�`��p�O���t�B�b�N�X
		*//********************/
		static LPGraphics			m_pGraphics;
		/*******************//*!
		�}���`�X���b�h�p�v���L�V
		*//********************/
		static LPRenderCommandProxy m_pCommandProxy;
		/*******************//*!
		�`��p�J����
		*//********************/
		static LPCamera				m_pCamera;
		/*******************//*!
		�`��p��{���C�g
		*//********************/
		static LPDirectionalLight	m_pDirectionalLight;
	public:
		/*************************************************************************//*!
				@brief			�`��p��b�f�[�^���쐬����<br>
								IGraphics�N���X���p�������O���t�B�b�N�X�N���X�̏��������Ɏ��s�����B<br>
								���̊֐��̎��s�O�ɃN���X���̊֐������s���Ȃ����ƁB
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool CreateUtilities(void);
		/*************************************************************************//*!
				@brief			�`��p��b�f�[�^��j������
								IGraphics�N���X���p�������O���t�B�b�N�X�N���X�̉�����Ɏ��s�����B<br>
								���̊֐��̎��s��ɃN���X���̊֐������s���Ȃ����ƁB
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool ReleaseUtilities(void);

		//----------------------------------------------------------------------------
		////�v���~�e�B�u�̐���
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�v���~�e�B�u���쐬����<br>
								��{�̒��_�z��̎w��݂̂Œ��_�o�b�t�@�̐����������Ȃ��A
								�C���f�b�N�X�o�b�t�@�̓g���C�A���O�����X�g�Ŏ�����������B
				@param[in]		pv			���_�z��
				@param[in]		vcnt		���_�z��̐�
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateGeometry(DefaultGeometryVertex* pv, MofU32 vcnt, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�v���~�e�B�u���쐬����<br>
								��{�̒��_�z��ƃC���f�b�N�X�z��Ńo�b�t�@�̐����������Ȃ��B
				@param[in]		pv			���_�z��
				@param[in]		vf			���_�v�f�t���O(VertexFlag�񋓑̂̑g�ݍ��킹�Ŏw��)
				@param[in]		vcnt		���_�z��̐�
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateGeometry(LPCMofVoid pv, MofU32 vf, MofU32 vcnt, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�v���~�e�B�u���쐬����<br>
								��{�̒��_�z��ƃC���f�b�N�X�z��Ńo�b�t�@�̐����������Ȃ��B
				@param[in]		pv			���_�z��
				@param[in]		vcnt		���_�z��̐�
				@param[in]		pi			�C���f�b�N�X�z��
				@param[in]		icnt		�C���f�b�N�X�z��̐�
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateGeometry(DefaultGeometryVertex* pv, MofU32 vcnt, MofU16* pi, MofU32 icnt, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�v���~�e�B�u���쐬����<br>
								��{�̒��_�z��ƃC���f�b�N�X�z��Ńo�b�t�@�̐����������Ȃ��B
				@param[in]		pv			���_�z��
				@param[in]		vf			���_�v�f�t���O(VertexFlag�񋓑̂̑g�ݍ��킹�Ŏw��)
				@param[in]		vcnt		���_�z��̐�
				@param[in]		pi			�C���f�b�N�X�z��
				@param[in]		icnt		�C���f�b�N�X�z��̐�
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateGeometry(LPCMofVoid pv, MofU32 vf, MofU32 vcnt, MofU16* pi, MofU32 icnt, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);

		/*************************************************************************//*!
				@brief			���v���~�e�B�u���쐬����
				@param[in]		c			������
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateLineGeometry(MofU32 c = 1, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			���v���~�e�B�u���쐬����
				@param[in]		c			������
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateLine3DGeometry(MofU32 c = 1, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			����`�v���~�e�B�u���쐬����
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateLineRectGeometry(BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			��`�v���~�e�B�u���쐬����
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateRectGeometry(BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			���~�`�v���~�e�B�u���쐬����
				@param[in]		c			������
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateLineCircleGeometry(MofU32 c = 36, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�~�`�v���~�e�B�u���쐬����
				@param[in]		c			������
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateCircleGeometry(MofU32 c = 36, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�O�p�`�v���~�e�B�u���쐬����
				@param[in]		w			��
				@param[in]		d			���s
				@param[in]		sw			������
				@param[in]		sd			������
				@param[in]		bRev		���ʃt���O
				@param[in]		cp			���S���W
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateTriangleGeometry(BufferAccess VUsage, BufferAccess IUsage);
		/*************************************************************************//*!
				@brief			���ʃv���~�e�B�u���쐬����
				@param[in]		w			��
				@param[in]		d			���s
				@param[in]		sw			������
				@param[in]		sd			������
				@param[in]		bRev		���ʃt���O
				@param[in]		cp			���S���W
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreatePlaneGeometry(MofFloat w, MofFloat d, MofU32 sw, MofU32 sd, MofBool bRev, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			���v���~�e�B�u���쐬����
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		d			���s
				@param[in]		sw			������
				@param[in]		sh			�c����
				@param[in]		sd			������
				@param[in]		cp			���S���W
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateBoxGeometry(MofFloat w, MofFloat h, MofFloat d, MofU32 sw, MofU32 sh, MofU32 sd, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			���v���~�e�B�u���쐬����
				@param[in]		w			��
				@param[in]		h			����
				@param[in]		d			���s
				@param[in]		sw			������
				@param[in]		sh			�c����
				@param[in]		sd			������
				@param[in]		cp			���S���W
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateLineBoxGeometry(MofFloat w, MofFloat h, MofFloat d, MofU32 sw, MofU32 sh, MofU32 sd, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			���v���~�e�B�u���쐬����
				@param[in]		r			���a
				@param[in]		s			����
				@param[in]		cp			���S���W
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateSphereGeometry(MofFloat r, MofU32 s, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			���v���~�e�B�u���쐬����
				@param[in]		r			���a
				@param[in]		s			����
				@param[in]		cp			���S���W
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateLineSphereGeometry(MofFloat r, MofU32 s, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�~���v���~�e�B�u���쐬����
				@param[in]		r			���a
				@param[in]		h			����
				@param[in]		s			����
				@param[in]		sh			�c����
				@param[in]		cp			���S���W
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateCylinderGeometry(MofFloat r, MofFloat h, MofU32 s, MofU32 sh, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�J�v�Z���v���~�e�B�u���쐬����
				@param[in]		r			���a
				@param[in]		h			����
				@param[in]		s			����
				@param[in]		sh			�c����
				@param[in]		cp			���S���W
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateCapsuleGeometry(MofFloat r, MofFloat h, MofU32 s, MofU32 sh, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�R�[���v���~�e�B�u���쐬����
				@param[in]		r			���a
				@param[in]		h			����
				@param[in]		s			����
				@param[in]		sh			�c����
				@param[in]		cp			���S���W
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry CreateConeGeometry(MofFloat r, MofFloat h, MofU32 s, MofU32 sh, const Vector3& cp, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		
		/*************************************************************************//*!
				@brief			�X�v���C�g�v���~�e�B�u���쐬����
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry Create2DSpriteGeometry(BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�X�v���C�g�v���~�e�B�u���쐬����
				@param[in]		VUsage		���_�Ǘ����@
				@param[in]		IUsage		�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometry Create3DSpriteGeometry(BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		
		/*************************************************************************//*!
				@brief			�X�v���C�g�v���~�e�B�u���쐬����
				@param[in]		InstanceCount	�C���X�^���X�ő吔
				@param[in]		VUsage			���_�Ǘ����@
				@param[in]		IUsage			�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometryInstanced Create2DSpriteGeometryInstanced(MofU32 InstanceCount, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�X�v���C�g�v���~�e�B�u���쐬����
				@param[in]		InstanceFlag	�C���X�^���X�t���O
				@param[in]		InstanceCount	�C���X�^���X�ő吔
				@param[in]		VUsage			���_�Ǘ����@
				@param[in]		IUsage			�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometryInstanced Create2DSpriteGeometryInstanced(VertexFlag InstanceFlag, MofU32 InstanceCount, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�X�v���C�g�v���~�e�B�u���쐬����
				@param[in]		InstanceCount	�C���X�^���X�ő吔
				@param[in]		VUsage			���_�Ǘ����@
				@param[in]		IUsage			�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometryInstanced Create3DSpriteGeometryInstanced(MofU32 InstanceCount, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);
		/*************************************************************************//*!
				@brief			�X�v���C�g�v���~�e�B�u���쐬����
				@param[in]		InstanceFlag	�C���X�^���X�t���O
				@param[in]		InstanceCount	�C���X�^���X�ő吔
				@param[in]		VUsage			���_�Ǘ����@
				@param[in]		IUsage			�C���f�b�N�X�Ǘ����@

				@return			���������W�I���g��<br>
								���s�����ꍇNULL
		*//**************************************************************************/
		static LPGeometryInstanced Create3DSpriteGeometryInstanced(VertexFlag InstanceFlag, MofU32 InstanceCount, BufferAccess VUsage = BUFFERACCESS_GPUREADWRITE, BufferAccess IUsage = BUFFERACCESS_GPUREADWRITE);

		//----------------------------------------------------------------------------
		////�`��
		//----------------------------------------------------------------------------
				
		//----------------------------------------------------------------------------
		////�v���~�e�B�u�̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�v���~�e�B�u�̕`��
				@param[in]		prp			�`��p�����[�^�[
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pBind		�o�C���_
				@param[in]		pGeom		�W�I���g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderPrimitive(PrimitiveRenderParameter& prp, LPShader pShader, LPShaderBind pBind, LPGeometry pGeom);

		//----------------------------------------------------------------------------
		////���̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���̕`��
				@param[in]		sv			�J�n�ʒu
				@param[in]		ev			�I���ʒu
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLine(const Vector2& sv,const Vector2& ev,MofU32 col);
		/*************************************************************************//*!
				@brief			���̕`��
				@param[in]		sv			�J�n�ʒu
				@param[in]		ev			�I���ʒu
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLine(const Vector3& sv,const Vector3& ev,MofU32 col);
		/*************************************************************************//*!
				@brief			���̕`��
				@param[in]		sx			�J�n�ʒuX
				@param[in]		sy			�J�n�ʒuY
				@param[in]		ex			�I���ʒuX
				@param[in]		ey			�I���ʒuY
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLine(MofFloat sx,MofFloat sy,MofFloat ex,MofFloat ey,MofU32 col);
		/*************************************************************************//*!
				@brief			���̕`��
				@param[in]		sx			�J�n�ʒuX
				@param[in]		sy			�J�n�ʒuY
				@param[in]		sz			�J�n�ʒuZ
				@param[in]		ex			�I���ʒuX
				@param[in]		ey			�I���ʒuY
				@param[in]		ez			�I���ʒuZ
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLine(MofFloat sx, MofFloat sy, MofFloat sz, MofFloat ex, MofFloat ey, MofFloat ez, MofU32 col);
		
		/*************************************************************************//*!
				@brief			�O���b�h�̕`��
				@param[in]		bet			�Ԋu
				@param[in]		s			�T�C�Y
				@param[in]		col			�`��F
				@param[in]		plane		�\������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGrid(MofFloat bet, MofFloat s, MofU32 col, PlaneAxis plane);
		/*************************************************************************//*!
				@brief			�O���b�h�̕`��
				@param[in]		cp			���S
				@param[in]		bet			�Ԋu
				@param[in]		s			�T�C�Y
				@param[in]		col			�`��F
				@param[in]		plane		�\������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGrid(const Vector3& cp, MofFloat bet, MofFloat s, MofU32 col, PlaneAxis plane);

		//----------------------------------------------------------------------------
		////��`�̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			��`�̕`��
				@param[in]		rec			��`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRect(const Rectangle& rec,MofU32 col);
		/*************************************************************************//*!
				@brief			��`�̕`��
				@param[in]		l			��
				@param[in]		t			��
				@param[in]		r			�E
				@param[in]		b			��
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b,MofU32 col);
				
		/*************************************************************************//*!
				@brief			�h��Ԃ���`�̕`��
				@param[in]		rec			��`
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillRect(const Rectangle& rec,MofU32 col);
		/*************************************************************************//*!
				@brief			�h��Ԃ���`�̕`��
				@param[in]		rec			��`
				@param[in]		ltc			����`��F
				@param[in]		lbc			�����`��F
				@param[in]		rtc			�E��`��F
				@param[in]		rbc			�E���`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillRect(const Rectangle& rec,MofU32 ltc,MofU32 lbc,MofU32 rtc,MofU32 rbc);
		/*************************************************************************//*!
				@brief			�h��Ԃ���`�̕`��
				@param[in]		l			��
				@param[in]		t			��
				@param[in]		r			�E
				@param[in]		b			��
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b,MofU32 col);
		/*************************************************************************//*!
				@brief			�h��Ԃ���`�̕`��
				@param[in]		l			��
				@param[in]		t			��
				@param[in]		r			�E
				@param[in]		b			��
				@param[in]		ltc			����`��F
				@param[in]		lbc			�����`��F
				@param[in]		rtc			�E��`��F
				@param[in]		rbc			�E���`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b,MofU32 ltc,MofU32 lbc,MofU32 rtc,MofU32 rbc);

		//----------------------------------------------------------------------------
		////�~�̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�~�̕`��
				@param[in]		c			�`��~
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderCircle(const Circle& c,MofU32 col);
		/*************************************************************************//*!
				@brief			�~�̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		r			�`�攼�a
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderCircle(MofFloat px,MofFloat py,MofFloat r,MofU32 col);
		
		/*************************************************************************//*!
				@brief			�h��Ԃ��~�̕`��
				@param[in]		c			�`��~
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillCircle(const Circle& c,MofU32 col);
		/*************************************************************************//*!
				@brief			�h��Ԃ��~�̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		r			�`�攼�a
				@param[in]		col			�`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillCircle(MofFloat px,MofFloat py,MofFloat r,MofU32 col);
		/*************************************************************************//*!
				@brief			�h��Ԃ��~�̕`��
				@param[in]		c			�`��~
				@param[in]		Ccol		���S�`��F
				@param[in]		Ocol		�O���`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillCircle(const Circle& c,MofU32 Ccol,MofU32 Ocol);
		/*************************************************************************//*!
				@brief			�h��Ԃ��~�̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		r			�`�攼�a
				@param[in]		Ccol		���S�`��F
				@param[in]		Ocol		�O���`��F
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillCircle(MofFloat px,MofFloat py,MofFloat r,MofU32 Ccol,MofU32 Ocol);

		/*************************************************************************//*!
				@brief			�h��Ԃ��~�ʂ̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		r			�`�攼�a
				@param[in]		sang		�`��J�n�p�x
				@param[in]		eang		�`��I���p�x
				@param[in]		Ccol		���S�`��F
				@param[in]		Ocol		�O���`��F

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillArc(MofFloat px, MofFloat py, MofFloat r, MofFloat sang, MofFloat eang, MofU32 Ccol, MofU32 Ocol);

		//----------------------------------------------------------------------------
		////�O�p�`�̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�h��Ԃ��O�p�`�̕`��
				@param[in]		t			�O�p�`�̏�̓_
				@param[in]		rb			�O�p�`�̉E���̓_
				@param[in]		lb			�O�p�`�̍����̓_
				@param[in]		tc			�O�p�`�̏�̓_�̐F
				@param[in]		rbc			�O�p�`�̉E���̓_�̐F
				@param[in]		lbc			�O�p�`�̍����̓_�̐F

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillTriangle(Vector2& t, Vector2& rb, Vector2& lb, MofU32 tc, MofU32 rbc, MofU32 lbc);

		//----------------------------------------------------------------------------
		////�l�p�`�̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�h��Ԃ��l�p�`�̕`��
				@param[in]		lt			�l�p�`�̍���̓_
				@param[in]		lb			�l�p�`�̍����̓_
				@param[in]		rt			�l�p�`�̉E��̓_
				@param[in]		rb			�l�p�`�̉E���̓_
				@param[in]		ltc			�l�p�`�̍���̓_�̐F
				@param[in]		lbc			�l�p�`�̍����̓_�̐F
				@param[in]		rtc			�l�p�`�̉E��̓_�̐F
				@param[in]		rbc			�l�p�`�̉E���̓_�̐F

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderFillQuad(Vector2& lt, Vector2& lb, Vector2& rt, Vector2& rb, MofU32 ltc, MofU32 lbc, MofU32 rtc, MofU32 rbc);

		//----------------------------------------------------------------------------
		////���ʂ̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D���ʂ̕`��
				@param[in]		wMat		�ϊ��s��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderPlane(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D���ʂ̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderPlane(const Matrix44& wMat, const Vector4& col);
		
		//----------------------------------------------------------------------------
		////���̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D���̕`��<br>
								�����\������ӂ̐��̂ݕ`��������Ȃ��B
				@param[in]		b			AABB
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLineBox(const BoxAABB& b);
		/*************************************************************************//*!
				@brief			3D���̕`��<br>
								�����\������ӂ̐��̂ݕ`��������Ȃ��B
				@param[in]		b			OBB
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLineBox(const BoxOBB& b);
		/*************************************************************************//*!
				@brief			3D���̕`��<br>
								�����\������ӂ̐��̂ݕ`��������Ȃ��B
				@param[in]		wMat		�ϊ��s��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLineBox(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D���̕`��<br>
								�����\������ӂ̐��̂ݕ`��������Ȃ��B
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLineBox(const Matrix44& wMat, const Vector4& col);

		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		b			AABB
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderBox(const BoxAABB& b);
		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		b			AABB
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderBox(const BoxAABB& b, const Vector4& col);
		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		b			OBB
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderBox(const BoxOBB& b);
		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		b			OBB
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderBox(const BoxOBB& b, const Vector4& col);
		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		wMat		�ϊ��s��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderBox(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderBox(const Matrix44& wMat, const Vector4& col);

		//----------------------------------------------------------------------------
		////���̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D���̕`��<br>
								����X,Y,Z���̐��̂ݕ`��������Ȃ��B
				@param[in]		s			����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLineSphere(const Sphere& s);
		/*************************************************************************//*!
				@brief			3D���̕`��<br>
								����X,Y,Z���̐��̂ݕ`��������Ȃ��B
				@param[in]		s			����
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLineSphere(const Sphere& s, const Vector4& col);
		/*************************************************************************//*!
				@brief			3D���̕`��<br>
								����X,Y,Z���̐��̂ݕ`��������Ȃ��B
				@param[in]		wMat		�ϊ��s��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLineSphere(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D���̕`��<br>
								����X,Y,Z���̐��̂ݕ`��������Ȃ��B
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderLineSphere(const Matrix44& wMat, const Vector4& col);

		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		s			����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderSphere(const Sphere& s);
		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		s			����
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderSphere(const Sphere& s,const Vector4& col);
		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		wMat		�ϊ��s��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderSphere(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderSphere(const Matrix44& wMat, const Vector4& col);

		//----------------------------------------------------------------------------
		////�~���̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D�~���̕`��
				@param[in]		wMat		�ϊ��s��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderCylinder(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D�~���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderCylinder(const Matrix44& wMat, const Vector4& col);

		//----------------------------------------------------------------------------
		////�J�v�Z���̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D�J�v�Z���̕`��
				@param[in]		wMat		�ϊ��s��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderCapsule(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D�J�v�Z���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderCapsule(const Matrix44& wMat, const Vector4& col);

		//----------------------------------------------------------------------------
		////�R�[���̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			3D�R�[���̕`��
				@param[in]		wMat		�ϊ��s��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderCone(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			3D�R�[���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderCone(const Matrix44& wMat, const Vector4& col);
		
		//----------------------------------------------------------------------------
		////�W�I���g���̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�W�I���g���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		pGeom		�W�I���g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGeometry(const Matrix44& wMat,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			�W�I���g���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		pGeom		�W�I���g��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGeometry(const Matrix44& wMat, LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�W�I���g���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				@param[in]		uv			UV�␳
				@param[in]		pGeom		�W�I���g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGeometry(const Matrix44& wMat,const Vector4& col,const Vector2& uv,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			�W�I���g���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�F�␳
				@param[in]		uv			UV�␳
				@param[in]		pGeom		�W�I���g��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGeometry(const Matrix44& wMat, const Vector4& col, const Vector2& uv, LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�W�I���g���̕`��
				@param[in]		pMotion		���[�V�����R���g���[��
				@param[in]		pGeom		�W�I���g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGeometry(LPMeshMotionController pMotion,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			�W�I���g���̕`��
				@param[in]		pMotion		���[�V�����R���g���[��
				@param[in]		pGeom		�W�I���g��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGeometry(LPMeshMotionController pMotion, LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�W�I���g���̕`��
				@param[in]		pMotion		���[�V�����R���g���[��
				@param[in]		col			�F�␳
				@param[in]		uv			UV�␳
				@param[in]		pGeom		�W�I���g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGeometry(LPMeshMotionController pMotion,const Vector4& col,const Vector2& uv,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			�W�I���g���̕`��
				@param[in]		pMotion		���[�V�����R���g���[��
				@param[in]		col			�F�␳
				@param[in]		uv			UV�␳
				@param[in]		pGeom		�W�I���g��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGeometry(LPMeshMotionController pMotion, const Vector4& col, const Vector2& uv, LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�W�I���g���̕`��
				@param[in]		pGeom		�W�I���g��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderGeometry(LPGeometry pGeom, LPShader pShader, LPShaderBind pShaderBind);

		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////���W�w��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);



		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
				
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pTex		�e�N�X�`��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px, MofFloat py, const Rectangle& srec, MofU32 col, TextureAlignment Alignment, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px				�`��X���W
				@param[in]		py				�`��Y���W
				@param[in]		pTex			�e�N�X�`��
				@param[in]		pShaderEffect	�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(MofFloat px,MofFloat py,LPTexture pTex,LPShaderEffect pShaderEffect);

		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////�o�͋�`�ւ̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		alpha		�`��s�����x
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,MofFloat alpha,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		pTex		�e�N�X�`��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,MofU32 col,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);


		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		srec		�摜�\����`
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		srec		�摜�\����`
				@param[in]		pTex		�e�N�X�`��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec, const Rectangle& srec, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		drec		�`���`
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Rectangle& drec, const Rectangle& srec, MofU32 col, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind);

		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////�g��{���w��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,MofU32 col,TextureAlignment Alignment,LPTexture pTex);


		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofU32 col,TextureAlignment Alignment,LPTexture pTex,LPShader pShader,LPShaderBind pShaderBind);
				


		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat s,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);



		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pShaderBind	�V�F�[�_�[�o�C���h

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleTexture(MofFloat px, MofFloat py, MofFloat sx, MofFloat sy, const Rectangle& srec, MofU32 col, TextureAlignment Alignment, LPTexture pTex, LPShader pShader, LPShaderBind pShaderBind);
				
		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////��]�p�x�w��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,MofU32 col,TextureAlignment Alignment,LPTexture pTex);


				
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderRotateTexture(MofFloat px,MofFloat py,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);

		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////�g��{���A��]�p�x�w��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,MofU32 col,TextureAlignment Alignment,LPTexture pTex);



		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		s			�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat s,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pz			�`��Z���W
				@param[in]		sx			�w�g��{��
				@param[in]		sy			�x�g��{��
				@param[in]		ang			��]�p�x
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderScaleRotateTexture(MofFloat px,MofFloat py,MofFloat pz,MofFloat sx,MofFloat sy,MofFloat ang,const Rectangle& srec,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
				
		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////2D��Ԃł̍s��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Pivot		�A���C�����g�ʒu
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec,MofU32 col,const Vector3& Pivot,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		Pivot		�A���C�����g�ʒu
				@param[in]		Size		�T�C�Y
				@param[in]		uvp			UV�ړ�
				@param[in]		uvs			UV�g��
				@param[in]		uva			UV��]
				@param[in]		vpos		���_�ړ�
				@param[in]		vcol		���_�J���[
				@param[in]		vcolr		���_�J���[���[�g
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec, const Vector4& col,const Vector3& Pivot, const Vector3& Size, const Vector2& uvp, const Vector2& uvs,const MofFloat uva,LPVector2 vpos, LPVector4 vcol, MofFloat vcolr,LPTexture pTex);

		//----------------------------------------------------------------------------
		////�e�N�X�`���̕`��
		////3D��Ԃł̍s��ł̕`��
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		col			�`��F
				@param[in]		bRatio		�䗦�ێ��t���O
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,MofU32 col,MofBool bRatio,LPTexture pTex);
		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec,MofU32 col,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		wMat		�ϊ��s��
				@param[in]		srec		�摜�\����`
				@param[in]		col			�`��F
				@param[in]		bRatio		�䗦�ێ��t���O
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(const Matrix44& wMat,const Rectangle& srec,MofU32 col,MofBool bRatio,LPTexture pTex);
		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̕`��
				@param[in]		trp			�`��p�����[�^�[
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pBind		�o�C���_
				@param[in]		pGeom		�W�I���g��
				@param[in]		pTex		�e�N�X�`��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderTexture(TextureRenderParameter& trp, LPShader pShader, LPShaderBind pBind, LPGeometry pGeom, LPTexture pTex);

		//----------------------------------------------------------------------------
		////�t�H���g�̕`��
		////�����Ő��������f�t�H���g�̃t�H���g�ŕ`����s��
		////�f�t�H���g�t�H���g��MS�S�V�b�N��24pt�ō쐬�����
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderString(MofFloat px, MofFloat py, LPCMofChar pText, ...);
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderString(MofFloat px, MofFloat py, MofU32 col, LPCMofChar pText, ...);
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		drec		�`���`
				@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderString(Rectangle& drec, LPCMofChar pText, ...);
		/*************************************************************************//*!
				@brief			�����`��
				@param[in]		drec		�`���`
				@param[in]		col			�`��F
				@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool RenderString(Rectangle& drec, MofU32 col, LPCMofChar pText, ...);

		/*************************************************************************//*!
				@brief			�����`���`�̌v�Z
				@param[in]		px			�`��X���W
				@param[in]		py			�`��Y���W
				@param[in]		pText		�`�敶����
				@param[out]		Out			�o�͋�`
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		static MofBool CalculateStringRect(MofFloat px,MofFloat py,LPCMofChar pText,Rectangle& Out);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�`��p�O���t�B�b�N�X��ݒ肷��
				@param[in]		pg				�O���t�B�b�N�X

				@return			None
		*//**************************************************************************/
		static void SetGraphics(LPGraphics pg);
		/*************************************************************************//*!
				@brief			�`��p�O���t�B�b�N�X�R�}���h�v���L�V��ݒ肷��
				@param[in]		pg				�O���t�B�b�N�X�R�}���h�v���L�V

				@return			None
		*//**************************************************************************/
		static void SetCommandProxy(LPRenderCommandProxy pg);
		/*************************************************************************//*!
				@brief			�`��p��ʃT�C�Y��ݒ肷��
				@param[in]		sw				��
				@param[in]		sh				����

				@return			None
		*//**************************************************************************/
		static MofBool SetScreenSize(MofS32 sw,MofS32 sh);
		/*************************************************************************//*!
				@brief			�`��p��ʃT�C�Y��ݒ肷��
				@param[in]		sw				��
				@param[in]		sh				����
				@param[in]		pBind			�o�C���h

				@return			None
		*//**************************************************************************/
		static MofBool SetScreenSize(MofS32 sw,MofS32 sh,LPShaderBind pBind);
		/*************************************************************************//*!
				@brief			�`��p�J������ݒ肷��
				@param[in]		pc				�J����

				@return			None
		*//**************************************************************************/
		static void SetCamera(LPCamera pc);
		/*************************************************************************//*!
				@brief			�`��p��{���C�g��ݒ肷��
				@param[in]		pl				���C�g

				@return			None
		*//**************************************************************************/
		static void SetDirectionalLight(LPDirectionalLight pl);
		/*************************************************************************//*!
				@brief			��{�t�H���g�̊�{�F�ݒ�
				@param[in]		c				�F
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		static MofBool SetDefaultFontColor(MofU32 c);
		/*************************************************************************//*!
				@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[�̐ݒ�
				@param[in]		p3DPrimitiveShader		3D�v���~�e�B�u�`��p�V�F�[�_�[
				@param[in]		p3DPrimitiveBind		3D�v���~�e�B�u�`��p�o�C���h
				
				@return			None
		*//**************************************************************************/
		static MofBool Set3DPrimitiveShader(LPShader p3DPrimitiveShader, LPShaderBind p3DPrimitiveBind);
		/*************************************************************************//*!
				@brief			3D�X�L�j���O�`��p�V�F�[�_�[�̐ݒ�
				@param[in]		pSkinGeometryShader		3D�X�L�j���O�`��p�V�F�[�_�[
				@param[in]		pSkinGeometryBind		3D�X�L�j���O�`��p�o�C���h
				
				@return			None
		*//**************************************************************************/
		static MofBool SetSkinGeometryShader(LPShader pSkinGeometryShader, LPShaderBind pSkinGeometryBind);
		/*************************************************************************//*!
				@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[�̐ݒ�
				@param[in]		p3DPrimitiveShader		3D�v���~�e�B�u�`��p�V�F�[�_�[
				@param[in]		p3DPrimitiveBind		3D�v���~�e�B�u�`��p�o�C���h
				
				@return			None
		*//**************************************************************************/
		static MofBool Set3DPrimitiveShaderImpl(LPShader p3DPrimitiveShader, LPShaderBind p3DPrimitiveBind);
		/*************************************************************************//*!
				@brief			3D�X�L�j���O�`��p�V�F�[�_�[�̐ݒ�
				@param[in]		pSkinGeometryShader		3D�X�L�j���O�`��p�V�F�[�_�[
				@param[in]		pSkinGeometryBind		3D�X�L�j���O�`��p�o�C���h
				
				@return			None
		*//**************************************************************************/
		static MofBool SetSkinGeometryShaderImpl(LPShader pSkinGeometryShader, LPShaderBind pSkinGeometryBind);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�`��p�O���t�B�b�N�X���擾����
				@param			None

				@return			�`��p�O���t�B�b�N�X
		*//**************************************************************************/
		static LPGraphics GetGraphics(void);
		/*************************************************************************//*!
				@brief			�`��p�O���t�B�b�N�X�R�}���h�v���L�V���擾����
				@param			None

				@return			�`��p�O���t�B�b�N�X�R�}���h�v���L�V
		*//**************************************************************************/
		static LPRenderCommandProxy GetCommandProxy(void);
		/*************************************************************************//*!
				@brief			�`��p�J�������擾����
				@param			None

				@return			�`��p�J����
		*//**************************************************************************/
		static LPCamera GetCamera(void);
		/*************************************************************************//*!
				@brief			�`��p��{���C�g���擾����
				@param			None

				@return			�`��p��{���C�g
		*//**************************************************************************/
		static LPDirectionalLight GetDirectionalLight(void);
		/*************************************************************************//*!
				@brief			�f�t�H���g�e�N�X�`�����擾����
				@param			None

				@return			�`��p�J����
		*//**************************************************************************/
		static LPTexture GetDefaultTexture(void);
		/*************************************************************************//*!
				@brief			2D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
				@param			None

				@return			2D�v���~�e�B�u�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShader Get2DPrimitiveShader(void);
		/*************************************************************************//*!
				@brief			2D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
				@param			None

				@return			2D�v���~�e�B�u�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShaderBind Get2DPrimitiveBind(void);
		/*************************************************************************//*!
				@brief			2D�X�v���C�g�`��p�V�F�[�_�[���擾����
				@param			None

				@return			2D�X�v���C�g�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShader Get2DSpriteShader(void);
		/*************************************************************************//*!
				@brief			2D�X�v���C�g�`��p�V�F�[�_�[���擾����
				@param			None

				@return			2D�X�v���C�g�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShaderBind Get2DSpriteBind(void);
		/*************************************************************************//*!
				@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
				@param			None

				@return			3D�v���~�e�B�u�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShader Get3DPrimitiveShader(void);
		/*************************************************************************//*!
				@brief			3D�v���~�e�B�u�`��p�V�F�[�_�[���擾����
				@param			None

				@return			3D�v���~�e�B�u�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShaderBind Get3DPrimitiveBind(void);
		/*************************************************************************//*!
				@brief			3D�X�v���C�g�`��p�V�F�[�_�[���擾����
				@param			None

				@return			3D�X�v���C�g�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShader Get3DSpriteShader(void);
		/*************************************************************************//*!
				@brief			3D�X�v���C�g�`��p�V�F�[�_�[���擾����
				@param			None

				@return			3D�X�v���C�g�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShaderBind Get3DSpriteBind(void);
		/*************************************************************************//*!
				@brief			3D�X�L�j���O�`��p�V�F�[�_�[���擾����
				@param			None

				@return			3D�X�L�j���O�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShader GetSkinGeometryShader(void);
		/*************************************************************************//*!
				@brief			3D�X�L�j���O�`��p�V�F�[�_�[���擾����
				@param			None

				@return			3D�X�L�j���O�`��p�V�F�[�_�[
		*//**************************************************************************/
		static LPShaderBind GetSkinGeometryBind(void);

	private:
		//�쐬���֎~����
		CGraphicsUtilities(){};
		CGraphicsUtilities(const CGraphicsUtilities& pObj){};
	};
					
	#include	"GraphicsUtilities.inl"
}

#endif

//[EOF]