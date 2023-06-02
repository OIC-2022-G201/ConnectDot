/*************************************************************************//*!
					
					@file	GraphicsCommon.h
					@brief	�O���t�B�b�N�X�֘A�̊�{��`���s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GRAPHICSCOMMON__H__

#define		__GRAPHICSCOMMON__H__

//INCLUDE
#include	"../Common/Lock.h"
#include	"../Framework/Window/Window.h"
#include	"../Math/Quaternion.h"
#include	"../Collision/Rectangle.h"
#include	"../Collision/Circle.h"
#include	"../Collision/Box.h"
#include	"../Collision/Sphere.h"
#include	"../Collision/Capsule.h"
#include	"../Collision/Ray.h"

//DEFINE

//!�`��^�[�Q�b�g�ݒ�ő吔
#define		MOF_RENDERTARGET_MAX							( 8 )

namespace Mof {
		
	/*******************************//*!
	@brief	�o�b�t�@�������}�b�v���@��

			���_�o�b�t�@��C���f�b�N�X�o�b�t�@�Ȃǂ̃������}�b�v�̗��p���@���

	@author	CDW
	*//********************************/
	enum tag_BUFFERMAP {
        BUFFERMAP_READ,								//!<�ǂݍ��ݐ�p�Ń}�b�v�������Ȃ�
        BUFFERMAP_WRITE,							//!<�������ݐ�p�Ń}�b�v�������Ȃ�
        BUFFERMAP_READ_WRITE,						//!<�ǂݏ����\�Ń}�b�v�������Ȃ�
        BUFFERMAP_WRITE_DISCARD,					//!<�������ݐ�p�Ń}�b�v�������Ȃ��A�}�b�v�������Ȃ��o�b�t�@�����I���p�ō쐬����Ă���K�v������
        BUFFERMAP_WRITE_NO_OVERWRITE,				//!<�������ݐ�p�Ń}�b�v�������Ȃ��A�}�b�v�������Ȃ��o�b�t�@�����I���p�ō쐬����Ă���K�v������

		BUFFERMAP_MAX,
	};

	/*******************************//*!
	@brief	�|���S���`��\����

			�|���S���`��\���񋓁B<br>
			�|���S���̃C���f�b�N�X���ǂ����������ō\������Ă��邩���`����B

	@author	CDW
	*//********************************/
	typedef enum tag_PRIMITIVETOPOLOGY {
		PRIMITIVETOPOLOGY_POINTLIST,				//!<���_�̃��X�g�݂̂Ń|���S�����\������B
		PRIMITIVETOPOLOGY_LINELIST,					//!<���̃��X�g�Ń|���S�����\������B
		PRIMITIVETOPOLOGY_LINESTRIP,				//!<�A���������̃��X�g�Ń|���S�����\������B
		PRIMITIVETOPOLOGY_TRIANGLELIST,				//!<�O�p�`�̃��X�g�Ń|���S�����`������B
		PRIMITIVETOPOLOGY_TRIANGLESTRIP,			//!<�A�������O�p�`�̃��X�g�Ń|���S�����`������B
	}PrimitiveTopology;
	
	/*******************************//*!
	@brief	�|���S���h��Ԃ����[�h��

			�|���S���h��Ԃ����[�h�񋓁B

	@author	CDW
	*//********************************/
	typedef enum tag_FILLMODE {
		FILLMODE_SOLID,								//!<�h��Ԃ��`��
		FILLMODE_WIREFRAME,							//!<���C���[�t���[���`��

		FILLMODE_MAX,
	}FillMode;
	
	/*******************************//*!
	@brief	�J�����O���[�h��

			�J�����O���[�h�񋓁B

	@author	CDW
	*//********************************/
	typedef enum tag_CULLMODE {
		CULLMODE_NONE,								//!<�J�����O�������Ȃ�Ȃ�
		CULLMODE_FRONT,								//!<�O�ʂ��J�����O����
		CULLMODE_BACK,								//!<�w�ʂ��J�����O����

		CULLMODE_MAX,
	}CullMode;

	/*******************************//*!
	@brief	�u�����f�B���O���@��

			�`��̃A���t�@�u�����f�B���O���@���

	@author	CDW
	*//********************************/
	typedef enum Blending {
		BLEND_NONE,								//!<�u�����f�B���O�Ȃ�
		BLEND_NORMAL,							//!<�ʏ�
		BLEND_ADD,								//!<���Z����
		BLEND_SUB,								//!<���Z����
		BLEND_SCREENADD,						//!<�X�N���[�����Z
		BLEND_MULTIPLY,							//!<��Z����
		BLEND_ONE,								//!<�A���t�@�������Z

		BLEND_MAX,								//!<�ő吔

		BLEND_USER,								//!<��`�ȊO�̃��[�U�[�w��̃u�����h���@��ݒ蒆
	}Blending;
	
	/*******************************//*!
	@brief	��r���@��

			��r���@���

	@author	CDW
	*//********************************/
	typedef enum tag_ComparisonFunc {
		COMPARISON_NEVER,
		COMPARISON_LESS,
		COMPARISON_EQUAL,
		COMPARISON_LESS_EQUAL,
		COMPARISON_GREATER,
		COMPARISON_NOT_EQUAL,
		COMPARISON_GREATER_EQUAL,
		COMPARISON_ALWAYS,
	}ComparisonFunc;

	/*******************************//*!
	@brief	�X�e���V���u���������@��

			�X�e���V���o�b�t�@�u���������@���

	@author	CDW
	*//********************************/
	typedef enum tag_StencilOp {
		STENCIL_KEEP,							//!<�X�e���V���̏����ێ�����
		STENCIL_ZERO,							//!<�X�e���V���̏����O�ɂ���
		STENCIL_REPLACE,						//!<�X�e���V���̏����Q�ƒl�ŏ㏑������
		STENCIL_INCR_SAT,						//!<�X�e���V���̏��̃C���N�������g�������Ȃ�
		STENCIL_DECR_SAT,						//!<�X�e���V���̏��̃f�N�������g�������Ȃ�
		STENCIL_INVERT,							//!<�X�e���V���̏��̔��]�������Ȃ�
		STENCIL_INCR,							//!<�X�e���V���̏��̃C���N�������g�������Ȃ�
		STENCIL_DECR,							//!<�X�e���V���̏��̃f�N�������g�������Ȃ�
	}StencilOp;

	/*******************************//*!
	@brief	���_�e���v���[�g��

			���_�̏��^�C�v���

	@author	CDW
	*//********************************/
	typedef enum VertexFlag {
		VERTEXFLAG_UNKOWN			=	0x00000000,						//!<�s��
		VERTEXFLAG_POSITION			=	0x00000001,						//!<���_���W
		VERTEXFLAG_NORMAL			=	0x00000002,						//!<���_�@��
		VERTEXFLAG_TANGENT			=	0x00000004,						//!<���_�ڐ�
		VERTEXFLAG_BINORMAL			=	0x00000008,						//!<���_�]�@��
		VERTEXFLAG_TEXTURECOORDS1	=	0x00000010,						//!<���_UV
		VERTEXFLAG_TEXTURECOORDS2	=	0x00000020,						//!<���_UV
		VERTEXFLAG_TEXTURECOORDS3	=	0x00000040,						//!<���_UV
		VERTEXFLAG_TEXTURECOORDS4	=	0x00000080,						//!<���_UV
		VERTEXFLAG_COLOR1			=	0x00000100,						//!<���_�J���[
		VERTEXFLAG_COLOR2			=	0x00000200,						//!<���_�J���[
		VERTEXFLAG_COLOR3			=	0x00000400,						//!<���_�J���[
		VERTEXFLAG_COLOR4			=	0x00000800,						//!<���_�J���[
		VERTEXFLAG_COLORF1			=	0x00001000,						//!<���_�J���[
		VERTEXFLAG_COLORF2			=	0x00002000,						//!<���_�J���[
		VERTEXFLAG_COLORF3			=	0x00004000,						//!<���_�J���[
		VERTEXFLAG_COLORF4			=	0x00008000,						//!<���_�J���[

		VERTEXFLAG_WAIT1			=	0x00010000,						//!<���_�E�F�C�g�P
		VERTEXFLAG_BLENDINDICES1	=	0x00020000,						//!<���_�E�F�C�g�P
		VERTEXFLAG_WAIT2			=	0x00100000,						//!<���_�E�F�C�g�Q
		VERTEXFLAG_BLENDINDICES2	=	0x00200000,						//!<���_�E�F�C�g�Q
		VERTEXFLAG_WAIT3			=	0x01000000,						//!<���_�E�F�C�g�R
		VERTEXFLAG_BLENDINDICES3	=	0x02000000,						//!<���_�E�F�C�g�R
		VERTEXFLAG_WAIT4			=	0x10000000,						//!<���_�E�F�C�g�S
		VERTEXFLAG_BLENDINDICES4	=	0x20000000,						//!<���_�E�F�C�g�S
		
		VERTEXFLAG_WAIT				=	VERTEXFLAG_WAIT1,				//!<���_�E�F�C�g�P
		VERTEXFLAG_BLENDINDICES		=	VERTEXFLAG_BLENDINDICES1,		//!<���_�E�F�C�g�P

		VERTEXFLAG_POINTSIZE		=	0x00040000,						//!<���_�|�C���g�T�C�Y

		VERTEXFLAG_MATRIX			=	0x00080000,						//!<�C���X�^���X�p�s��
		
		VERTEXFLAG_TEXTURECOORDSALL	=	0x000000F0,						//!<���_UV
		VERTEXFLAG_COLORALL			=	0x0000FF00,						//!<���_�J���[
	}VertexFlag;

	/*******************************//*!
	@brief	�s�N�Z���t�H�[�}�b�g��

			�s�N�Z���t�H�[�}�b�g���

	@author	CDW
	*//********************************/
	typedef enum tag_PixelFormat {
		PIXELFORMAT_UNKNOWN,											//!<�s���ȃt�H�[�}�b�g

		PIXELFORMAT_R8G8B8A8_UNORM,										//!<RGBA�e�W�r�b�g�ō\������
		PIXELFORMAT_R16G16B16A16_UNORM,									//!<RGBA�e�P�U�r�b�g�ō\������

		PIXELFORMAT_R16G16B16A16_FLOAT,									//!<RGBA�e�P�U�r�b�g���������^�ō\������
		PIXELFORMAT_R32G32B32A32_FLOAT,									//!<RGBA�e�R�Q�r�b�g���������^�ō\������

		PIXELFORMAT_R16G16_FLOAT,										//!<RG�e�P�U�r�b�g���������^�ō\������
		PIXELFORMAT_R32G32_FLOAT,										//!<RG�e�R�Q�r�b�g���������^�ō\������

		PIXELFORMAT_R16_FLOAT,											//!<R�e�P�U�r�b�g���������^�ō\������
		PIXELFORMAT_R32_FLOAT,											//!<R�e�R�Q�r�b�g���������^�ō\������

		PIXELFORMAT_D32_FLOAT,											//!<�[�x�R�Q�r�b�g���������^�ō\������
		PIXELFORMAT_D24S8_UNORM,										//!<�[�x�Q�S�r�b�g�ƃX�e���V���W�r�b�g�ō\������
		PIXELFORMAT_D32S8X24_FLOAT,										//!<�[�x�R�Q�r�b�g�ƃX�e���V���W�r�b�g���������^�ō\������
	}PixelFormat;
	
	/*******************************//*!
	@brief	�o�b�t�@�A�N�Z�X���[�h��

			�o�b�t�@�ւ̃A�N�Z�X���[�h���

	@author	CDW
	*//********************************/
	typedef enum tag_BufferAccess {
		BUFFERACCESS_GPUREADWRITE,
		BUFFERACCESS_GPUREAD,
		BUFFERACCESS_GPUREAD_CPUWRITE,
	}BufferAccess;
	
	/*******************************//*!
	@brief	���ʎ���

			���ʎ����

	@author	CDW
	*//********************************/
	typedef enum tag_PlaneAxis {
		PLANEAXIS_XZ			=	0x01,		//!<XZ����
		PLANEAXIS_XY			=	0x02,		//!<XY����
		PLANEAXIS_YZ			=	0x04,		//!<YZ����

		PLANEAXIS_ALL			=	0x07,		//!<�S��
	}PlaneAxis;

	/*******************************//*!
	@brief	�T���v�����O���@��

			�`��̃e�N�X�`���T���v�����O���@���

	@author	CDW
	*//********************************/
	enum tag_SAMPLER {
		SAMPLER_POINT,							//!<�Ȃ�
		SAMPLER_LINER,							//!<���`���
		SAMPLER_ANISOTROPIC,					//!<�ٕ����t�B���^�[

		SAMPLER_MAX,							//!<�ő吔

		SAMPLER_USER,							//!<��`�ȊO�̃��[�U�[�w��̃e�N�X�`���T���v�����O���@��ݒ蒆
	};

	/*******************************//*!
	@brief	���_�f�[�^

			�����_�����O�p�̒��_�f�[�^<br>
			���W����ێ�����

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX {
		MofFloat					px;			//!<X���W
		MofFloat					py;			//!<Y���W
		MofFloat					pz;			//!<Z���W
	}VERTEX,*LPVERTEX;

	/*******************************//*!
	@brief	���_�f�[�^

			�����_�����O�p�̒��_�f�[�^<br>
			���W�A�F(U32)�̏���ێ�����

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_COLORU1 {
		MofFloat					px;			//!<X���W
		MofFloat					py;			//!<Y���W
		MofFloat					pz;			//!<Z���W

		MofU32						c;			//!<�F
	}VERTEX_COLORU1,*LPVERTEX_COLORU1;

	/*******************************//*!
	@brief	���_�f�[�^

			�����_�����O�p�̒��_�f�[�^<br>
			���W�AUV�̏���ێ�����

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_TEXTURE1 {
		MofFloat					px;			//!<X���W
		MofFloat					py;			//!<Y���W
		MofFloat					pz;			//!<Z���W

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV
	}VERTEX_TEXTURE1,*LPVERTEX_TEXTURE1;

	/*******************************//*!
	@brief	���_�f�[�^

			�����_�����O�p�̒��_�f�[�^<br>
			���W�AUV�A�F(U32)�̏���ێ�����

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_TEXTURE1_COLORU1 {
		MofFloat					px;			//!<X���W
		MofFloat					py;			//!<Y���W
		MofFloat					pz;			//!<Z���W

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV

		MofU32						c;			//!<�F
	}VERTEX_TEXTURE1_COLORU1,*LPVERTEX_TEXTURE1_COLORU1;

	/*******************************//*!
	@brief	���_�f�[�^

			�����_�����O�p�̒��_�f�[�^<br>
			���W�AUV�A�F(U32)�̏���ێ�����

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_NORMAL_TEXTURE1_COLORU1 {
		MofFloat					px;			//!<X���W
		MofFloat					py;			//!<Y���W
		MofFloat					pz;			//!<Z���W

		MofFloat					nx;			//!<X�@��
		MofFloat					ny;			//!<Y�@��
		MofFloat					nz;			//!<Z�@��

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV

		MofU32						c;			//!<�F
	}VERTEX_NORMAL_TEXTURE1_COLORU1,*LPVERTEX_NORMAL_TEXTURE1_COLORU1;

	/*******************************//*!
	@brief	���_�f�[�^

			�����_�����O�p�̒��_�f�[�^<br>
			���W�A�F(U32)�̏���ێ�����

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_COLORF1 {
		MofFloat					px;			//!<X���W
		MofFloat					py;			//!<Y���W
		MofFloat					pz;			//!<Z���W

		MofFloat					cr;			//!<�F
		MofFloat					cg;			//!<�F
		MofFloat					cb;			//!<�F
		MofFloat					ca;			//!<�F
	}VERTEX_COLORF1,*LPVERTEX_COLORF1;

	/*******************************//*!
	@brief	���_�f�[�^

			�����_�����O�p�̒��_�f�[�^<br>
			���W�AUV�A�F(U32)�̏���ێ�����

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_TEXTURE1_COLORF1 {
		MofFloat					px;			//!<X���W
		MofFloat					py;			//!<Y���W
		MofFloat					pz;			//!<Z���W

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV

		MofFloat					cr;			//!<�F
		MofFloat					cg;			//!<�F
		MofFloat					cb;			//!<�F
		MofFloat					ca;			//!<�F
	}VERTEX_TEXTURE1_COLORF1,*LPVERTEX_TEXTURE1_COLORF1;

	/*******************************//*!
	@brief	���_�f�[�^

			�����_�����O�p�̒��_�f�[�^<br>
			���W�AUV�A�F(U32)�̏���ێ�����

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_NORMAL_TEXTURE1_COLORF1 {
		MofFloat					px;			//!<X���W
		MofFloat					py;			//!<Y���W
		MofFloat					pz;			//!<Z���W

		MofFloat					nx;			//!<X�@��
		MofFloat					ny;			//!<Y�@��
		MofFloat					nz;			//!<Z�@��

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV

		MofFloat					cr;			//!<�F
		MofFloat					cg;			//!<�F
		MofFloat					cb;			//!<�F
		MofFloat					ca;			//!<�F
	}VERTEX_NORMAL_TEXTURE1_COLORF1,*LPVERTEX_NORMAL_TEXTURE1_COLORF1;

	/*******************************//*!
	@brief	�v���~�e�B�u�����̓R���X�^���g�o�b�t�@

	@author	CDW
	*//********************************/
	typedef struct tag_PrimitiveRenderParameter {
		Vector4					vOffset;
		Vector4					vSize;
		Vector4					Color1;
		Vector4					Color2;
		Vector4					Color3;
		Vector4					Color4;
		Matrix44				World;
	}PrimitiveRenderParameter,*LPPrimitiveRenderParameter;
	
	/*******************************//*!
	@brief	�r���[�|�[�g���\����

			�r���[�|�[�g�̕��A�����Ȃǃr���[�|�[�g�̐ݒ�ɕK�v�ȏ����W�߂��\����

	@author	CDW
	*//********************************/
	typedef struct tag_VIEWPORT {
		MofFloat				x;					//!<X���W
		MofFloat				y;					//!<Y���W
		MofFloat				w;					//!<��
		MofFloat				h;					//!<����
		MofFloat				n;					//!<�ŋ�
		MofFloat				f;					//!<�ŉ�
	}ViewPort,*LPViewPort;

}

//�v���b�g�t�H�[�����Ƃ̃C���N���[�h�ƒu������
#ifdef		MOFLIB_DIRECTX12
#include	"DirectX12/DX12Common.h"
#endif
#ifdef		MOFLIB_DIRECTX11
#include	"DirectX11/DX11Common.h"
#endif
#ifdef		MOFLIB_DIRECTX9
//LIBRARY
#pragma comment (lib,"d3d9.lib")
//INCLUDE
#include	<d3d9.h>
	typedef		LPDIRECT3DDEVICE9					MofGraphicsDevice;
	typedef		LPDIRECT3DSWAPCHAIN9				MofSwapChain;
	typedef		LPMofVoid							MofDeviceContext;
	typedef		LPDIRECT3DSURFACE9					MofRenderTarget;
	typedef		LPDIRECT3DSURFACE9					MofDepthTarget;
	typedef		LPDIRECT3DTEXTURE9					MofTexture;
	typedef		LPD3DXEFFECT						MofVertexShader;
	typedef		LPD3DXEFFECT						MofPixelShader;
	typedef		LPD3DXEFFECT						MofShaderEffect;
	typedef		ID3DX11Effect*						MofShaderEffect;
	typedef		LPDIRECT3DVERTEXBUFFER9				MofVertexBuffer;
	typedef		LPDIRECT3DVERTEXDECLARATION9		MofVertexLayout;
	typedef		LPDIRECT3DINDEXBUFFER9				MofIndexBuffer;
	typedef		MofU32								MofSamplerState;
#endif
#ifdef		MOFLIB_OPENGL
#include	"OpenGL/GLCommon.h"
#endif

#endif

//[EOF]
