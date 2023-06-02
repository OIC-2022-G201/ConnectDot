/*************************************************************************//*!
					
					@file	Graphics.h
					@brief	�O���t�B�b�N�X�̏������s�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GRAPHICS__H__

#define		__GRAPHICS__H__

//INCLUDE
#include	"VertexBuffer.h"
#include	"IndexBuffer.h"

namespace Mof {

	// �O����`
	class IRenderTarget;
	typedef IRenderTarget* LPRenderTarget;
	class IDepthTarget;
	typedef IDepthTarget* LPDepthTarget;
	class IShader;
	typedef IShader* LPShader;

	/*******************************//*!
	@brief	�O���t�B�b�N�X�������\����

			�O���t�B�b�N�X�̐����ɕK�v�ȏ����܂Ƃ߂��\����

	@author	CDW
	*//********************************/
	typedef struct tag_GRAPHICSCREATEINFO {
		MofU32					Size;						//!<�\���̃T�C�Y
		MofU32					Buffers;					//!<�o�b�t�@�̐�
		MofBool					bMultiThread;				//!<�}���`�X���b�h���p�t���O
		MofBool					bMSAA;						//!<MSAA�L���t���O
		MofU32					RefreshRate;				//!<���t���b�V�����[�g
		MofU32					Flags;						//!<�����t���O

		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GRAPHICSCREATEINFO() :
		Size(sizeof(tag_GRAPHICSCREATEINFO)),
		Buffers(1) ,
		bMultiThread(TRUE) ,
		bMSAA(TRUE) ,
		RefreshRate(60) ,
		Flags(0) {
		}
	}GRAPHICSCREATEINFO,*LPGRAPHICSCREATEINFO;
	
	/*******************************//*!
	@brief	�f�B�X�v���C���[�h���\����

			�f�B�X�v���C���[�h�\����

	@author	CDW
	*//********************************/
	typedef struct tag_DISPLAYMODE {
		MofS32					RefreshRate;				//!<���t���b�V�����[�g
		MofS32					Width;						//!<��
		MofS32					Height;						//!<����
	}DISPLAYMODE,*LPDISPLAYMODE;

	/*******************************//*!
	@brief	�f�B�X�v���C���[�h��񃊃X�g�\����

			�f�B�X�v���C���[�h��񋓂����\����

	@author	CDW
	*//********************************/
	typedef struct tag_DISPLAYMODELIST {
		MofU32					DisplayModeCount;			//!<�f�B�X�v���C���[�h��
		LPDISPLAYMODE			pMode;						//!<���[�h
			
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_DISPLAYMODELIST() :
		DisplayModeCount(0) ,
		pMode(NULL) {
		}
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_DISPLAYMODELIST() {
			MOF_SAFE_DELETE_ARRAY(pMode);
		}
	}DISPLAYMODELIST,*LPDISPLAYMODELIST;
	
	/*******************************//*!
	@brief	�O���t�B�b�N�X�X�e�[�^�X�\����

			�O���t�B�b�N�X�̃X�e�[�^�X��\���\����

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_GRAPHICSSTATUS {
		//----------------------------------------------------------------------------
		////���݂̐ݒ��ۑ����邽�߂̃p�����[�^�[
		//----------------------------------------------------------------------------
		Blending				BlendType[MOF_RENDERTARGET_MAX];						//!<���݂̐ݒ�u�����h�^�C�v
		MofBool					bColorWriteEnable;										//!<�F�������ݗL���t���O
		MofBool					bMSAA;													//!<MSAA�L���t���O
		MofU32					MSAACount;												//!<MSAA�ݒ�
		MofU32					MSAAQuality;											//!<MSAA�ݒ�
		MofBool					bAlphaToCoverageEnable;									//!<�W���̃u�����h�X�e�[�g�ł̃A���t�@�J�o���b�W�t���O
		MofBool					bDepthEnable;											//!<�[�x�o�b�t�@�L���t���O
		MofBool					bDepthWriteEnable;										//!<�[�x�o�b�t�@�������ݗL���t���O
		ComparisonFunc			DepthFunc;												//!<�[�x�o�b�t�@��r�֐�
		MofBool					bStencilEnable;											//!<�X�e���V���o�b�t�@�L���t���O
		MofU32					StencilRef;												//!<�X�e���V����r�l
		ComparisonFunc			StencilFunc;											//!<�u�������֐�
		StencilOp				StencilPassOp;											//!<�u�������֐�
		StencilOp				StencilZFailOp;											//!<�u�������֐�
		StencilOp				StencilFailOp;											//!<�u�������֐�
		PrimitiveTopology		Topology;												//!<���݂̐ݒ�v���~�e�B�u�`����@
		FillMode				FillType;												//!<���݂̐ݒ�h��Ԃ����[�h
		CullMode				CullType;												//!<���݂̐ݒ�J�����O���[�h
		LPVertexBuffer			pVertexBuffer;											//!<���݂̐ݒ蒸�_�o�b�t�@
		LPIndexBuffer			pIndexBuffer;											//!<���݂̐ݒ�C���f�b�N�X�o�b�t�@
		MofVertexLayout			pVertexLayout;											//!<���݂̐ݒ蒸�_���C�A�E�g
		LPRenderTarget			pRenderTargets[MOF_RENDERTARGET_MAX];					//!<�`��^�[�Q�b�g
		LPDepthTarget			pDepthTarget;											//!<�[�x�^�[�Q�b�g
		MofU32					RenderTargetCount;										//!<�`��^�[�Q�b�g�̐�
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GRAPHICSSTATUS() :
		bColorWriteEnable(TRUE) ,
		bMSAA(TRUE) ,
		MSAACount(1) ,
		MSAAQuality(0) ,
		bAlphaToCoverageEnable(FALSE) ,
		bDepthEnable(FALSE) ,
		bDepthWriteEnable(TRUE) ,
		DepthFunc(COMPARISON_LESS) ,
		bStencilEnable(FALSE) ,
		StencilRef(0) ,
		StencilFunc(COMPARISON_NEVER) ,
		StencilPassOp(STENCIL_KEEP) ,
		StencilZFailOp(STENCIL_KEEP) ,
		StencilFailOp(STENCIL_KEEP) ,
		Topology(PRIMITIVETOPOLOGY_POINTLIST) ,
		FillType(FILLMODE_SOLID) ,
		CullType(CULLMODE_BACK) ,
		pVertexBuffer(NULL) ,
		pIndexBuffer(NULL) ,
		pVertexLayout(NULL),
		pDepthTarget(NULL),
		RenderTargetCount(1) {
			memset(pRenderTargets, 0, sizeof(LPRenderTarget) * MOF_RENDERTARGET_MAX);
			for (int i = 0; i < MOF_RENDERTARGET_MAX; i++)
			{
				BlendType[i] = BLEND_NORMAL;
			}
		}
	}GRAPHICSSTATUS,*LPGRAPHICSSTATUS;

	/*******************************//*!
	@brief	�O���t�B�b�N�X���C���^�[�t�F�C�X

			�O���t�B�b�N�X�̊��ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IGraphics : public IMofObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�O���t�B�b�N�X�I�u�W�F�N�g�̐���
				@param[in]		pInfo		�O���t�B�b�N�X�̐������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPGRAPHICSCREATEINFO pInfo) = 0;
		
		/*************************************************************************//*!
				@brief			��ʃ��[�h��ݒ肷��<br>
								Windows�ł̂ݏ��������s����B<br>
								Android�łł͂��̏����̌��ʂ͕K��FALSE�ɂȂ�B
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeScreenMode(void) = 0;

		/*************************************************************************//*!
				@brief			�`��̊J�n
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderStart(void) = 0;
		/*************************************************************************//*!
				@brief			�S�^�[�Q�b�g�̃N���A
				@param[in]		d			�[�x
				@param[in]		s			�X�e���V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearTarget(void) = 0;
		/*************************************************************************//*!
				@brief			�S�^�[�Q�b�g�̃N���A
				@param[in]		r			��
				@param[in]		g			��
				@param[in]		b			��
				@param[in]		a			�A���t�@
				@param[in]		d			�[�x
				@param[in]		s			�X�e���V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearTarget(MofFloat r,MofFloat g,MofFloat b,MofFloat a,MofFloat d,MofU32 s) = 0;
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g�̃N���A
				@param[in]		r			��
				@param[in]		g			��
				@param[in]		b			��
				@param[in]		a			�A���t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearRenderTarget(MofFloat r,MofFloat g,MofFloat b,MofFloat a) = 0;
		/*************************************************************************//*!
				@brief			�[�x�X�e���V���^�[�Q�b�g�̃N���A
				@param[in]		d			�[�x
				@param[in]		s			�X�e���V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearDepthStencilTarget(MofFloat d,MofU32 s) = 0;
		/*************************************************************************//*!
				@brief			�[�x�^�[�Q�b�g�̃N���A
				@param[in]		d			�[�x
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearDepthTarget(MofFloat d) = 0;
		/*************************************************************************//*!
				@brief			�X�e���V���^�[�Q�b�g�̃N���A
				@param[in]		s			�X�e���V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearStencilTarget(MofU32 s) = 0;
		/*************************************************************************//*!
				@brief			�`��̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderEnd(void) = 0;
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�`��p�o�b�t�@�T�C�Y��ݒ肷��
				@param[in]		sw				��
				@param[in]		sh				����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBackBufferSize(MofS32 sw, MofS32 sh) = 0;
		/*************************************************************************//*!
				@brief			�X�N���[�����[�h��ݒ肷��
				@param[in]		m			TRUE:�E�C���h�E���[�h�A:FALSE:�t���X�N���[�����[�h

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetScreenMode(MofBool m) = 0;
		/*************************************************************************//*!
				@brief			�`��p��ʃT�C�Y��ݒ肷��
				@param[in]		sw				��
				@param[in]		sh				����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetScreenSize(MofS32 sw,MofS32 sh) = 0;
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
				@brief			�u�����h�X�e�[�g�̐ݒ�
				@param[in]		Blend		�u�����h���@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBlending(Blending Blend) = 0;
		/*************************************************************************//*!
				@brief			�u�����h�X�e�[�g�̐ݒ�
				@param[in]		Blend		�u�����h���@
				@param[in]		target		�^�[�Q�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBlending(Blending Blend, MofS32 target) = 0;
		/*************************************************************************//*!
				@brief			�F�������݂̐ݒ�
				@param[in]		bEnable		�L���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetColorWriteEnable(MofBool bEnable) = 0;
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�̐ݒ�
				@param[in]		bEnable		����L���t���O
				@param[in]		bWEnable	�������ݗL���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthEnable(MofBool bEnable,MofBool bWEnable) = 0;
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�̐ݒ�
				@param[in]		bEnable		����L���t���O
				@param[in]		bWEnable	�������ݗL���t���O
				@param[in]		fn			��r�֐�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthEnable(MofBool bEnable,MofBool bWEnable,ComparisonFunc fn) = 0;
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�̐ݒ�
				@param[in]		bEnable		�L���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthEnable(MofBool bEnable) = 0;
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�������݂̐ݒ�
				@param[in]		bEnable		�L���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthWriteEnable(MofBool bEnable) = 0;
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�̐ݒ�
				@param[in]		fn			��r�֐�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthFunction(ComparisonFunc fn) = 0;
		/*************************************************************************//*!
				@brief			�X�e���V���o�b�t�@�̐ݒ�
				@param[in]		bEnable		�L���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetStencilEnable(MofBool bEnable) = 0;
		/*************************************************************************//*!
				@brief			�X�e���V���o�b�t�@�̐ݒ�
				@param[in]		ref			�ݒ萔�l
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetStencilValue(MofU32 ref) = 0;
		/*************************************************************************//*!
				@brief			�X�e���V���o�b�t�@�̐ݒ�
				@param[in]		fn			�u��������r�֐�
				@param[in]		PassOp		�u��������r�֐�
				@param[in]		ZFailOp		�u��������r�֐�
				@param[in]		FailOp		�u��������r�֐�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetStencilControl(ComparisonFunc fn,StencilOp PassOp,StencilOp ZFailOp,StencilOp FailOp) = 0;
		/*************************************************************************//*!
				@brief			�v���~�e�B�u�`����@�ݒ�
				@param[in]		Topology	�`����@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTopology(PrimitiveTopology Topology) = 0;
		/*************************************************************************//*!
				@brief			�h��Ԃ��`����@�ݒ�
				@param[in]		Mode		�h��Ԃ����@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetFillMode(FillMode Mode) = 0;
		/*************************************************************************//*!
				@brief			�J�����O���@�ݒ�
				@param[in]		Mode		�J�����O���@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetCullMode(CullMode Mode) = 0;
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�ݒ�
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetShader(LPShader pShader) = 0;
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�ݒ�
				@param[in]		pBuff		���_�o�b�t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetVertexBuffer(LPVertexBuffer pBuff) = 0;
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�ݒ�
				@param[in]		pBuff1		���_�o�b�t�@
				@param[in]		pBuff2		���_�o�b�t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetVertexBuffer(LPVertexBuffer pBuff1, LPVertexBuffer pBuff2) = 0;
		/*************************************************************************//*!
				@brief			���_���C�A�E�g�ݒ�
				@param[in]		pLayout		���_���C�A�E�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetVertexLayout(MofVertexLayout pLayout) = 0;
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�o�b�t�@�ݒ�
				@param[in]		pBuff		�C���f�b�N�X�o�b�t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetIndexBuffer(LPIndexBuffer pBuff) = 0;
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g�ݒ�
				@param[in]		pRenderTarget	�`��^�[�Q�b�g
				@param[in]		pDepthTarget	�[�x�^�[�Q�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetRenderTarget(LPRenderTarget pRenderTarget, LPDepthTarget pDepthTarget) = 0;
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g�ݒ�
				@param[in]		NumViews		�`��^�[�Q�b�g�̐�
				@param[in]		ppRenderTarget	�`��^�[�Q�b�g�z��ւ̃|�C���^
				@param[in]		pDepthTarget	�[�x�^�[�Q�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetMultiRenderTarget(MofU32 NumViews,LPRenderTarget* ppRenderTarget,LPDepthTarget pDepthTarget) = 0;
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g����ς����Ɏw�肵���ԍ��̕`��^�[�Q�b�g�������ւ���
				@param[in]		index			�C���f�b�N�X
				@param[in]		pRenderTarget	�`��^�[�Q�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetRenderTargetAt(MofU32 index,LPRenderTarget pRenderTarget) = 0;
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g����ς����Ɏw�肵���ԍ��̕`��^�[�Q�b�g�������ւ���
				@param[in]		index			�C���f�b�N�X
				@param[in]		pRenderTarget	�`��^�[�Q�b�g
				@param[in]		pDepthTarget	�[�x�^�[�Q�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetRenderTargetAt(MofU32 index,LPRenderTarget pRenderTarget, LPDepthTarget pDepthTarget) = 0;
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g���ݒ�
				@param			NumViews	�`��^�[�Q�b�g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetRenderTargetCount(MofU32 NumViews) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�O���t�B�b�N�X�f�o�C�X�擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�O���t�B�b�N�X�f�o�C�X
		*//**************************************************************************/
		virtual MofGraphicsDevice GetDevice(void) = 0;
		/*************************************************************************//*!
				@brief			�X���b�v�`�F�C���擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�X���b�v�`�F�C��
		*//**************************************************************************/
		virtual MofSwapChain GetSwapChain(void) = 0;
		/*************************************************************************//*!
				@brief			�R���e�L�X�g�擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�R���e�L�X�g
		*//**************************************************************************/
		virtual MofDeviceContext GetDeviceContext(void) = 0;
		/*************************************************************************//*!
				@brief			�T���v���[�X�e�[�g�擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param[in]		s		�擾����T���v���^�C�v(tag_SAMPLER�񋓑̂̒l��ݒ肷��)

				@return			�T���v���[�X�e�[�g
		*//**************************************************************************/
		virtual MofSamplerState GetSamplerState(MofU32 s) = 0;
		/*************************************************************************//*!
				@brief			�^�[�Q�b�g�E�C���h�E�̕��擾
				@param			None

				@return			�^�[�Q�b�g�E�C���h�E�̕�
		*//**************************************************************************/
		virtual MofS32 GetTargetWidth(void) = 0;
		/*************************************************************************//*!
				@brief			�^�[�Q�b�g�E�C���h�E�̍����擾
				@param			None

				@return			�^�[�Q�b�g�E�C���h�E�̍���
		*//**************************************************************************/
		virtual MofS32 GetTargetHeight(void) = 0;
		/*************************************************************************//*!
				@brief			�Ή���ʃT�C�Y���X�g�擾�ݒ�
				@param[out]		pList		�C���f�b�N�X�o�b�t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool GetDisplayModeList(LPDISPLAYMODELIST pList) = 0;
		/*************************************************************************//*!
				@brief			�ݒ���擾
				@param			None
				
				@return			�O���t�B�b�N�ݒ�
		*//**************************************************************************/
		virtual const GRAPHICSSTATUS& GetStatus(void) = 0;
		/*************************************************************************//*!
				@brief			���݂̕`��^�[�Q�b�g�擾
				@param			None
				
				@return			���݂̕`��^�[�Q�b�g
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTarget(void) = 0;
		/*************************************************************************//*!
				@brief			�w�肵���ԍ��̕`��^�[�Q�b�g�擾
				@param[in]		index		�C���f�b�N�X
				
				@return			���݂̕`��^�[�Q�b�g
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTargetAt(MofU32 index) = 0;
		/*************************************************************************//*!
				@brief			���݂̕`��^�[�Q�b�g�����擾
				@param			None
				
				@return			���݂̕`��^�[�Q�b�g��
		*//**************************************************************************/
		virtual MofU32 GetRenderTargetCount(void) = 0;
		/*************************************************************************//*!
				@brief			���݂̐[�x�^�[�Q�b�g�擾
				@param[out]		None
				
				@return			���݂̐[�x�^�[�Q�b�g
		*//**************************************************************************/
		virtual LPDepthTarget GetDepthTarget(void) = 0;
		/*************************************************************************//*!
				@brief			�u�����h�X�e�[�g�擾
				@param[out]		None
				
				@return			���݂̃u�����h�X�e�[�g
		*//**************************************************************************/
		virtual Blending GetBlending(void) = 0;
	};

	//�|�C���^�u������
	typedef IGraphics*			LPGraphics;
}

#endif

//[EOF]