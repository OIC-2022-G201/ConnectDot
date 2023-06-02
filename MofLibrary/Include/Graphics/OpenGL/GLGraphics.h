/*************************************************************************//*!
					
					@file	GLGraphics.h
					@brief	OpenGL�ł̃O���t�B�b�N�X�̏������s�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLGRAPHICS__H__

#define		__GLGRAPHICS__H__

//INCLUDE
#include	"../Graphics.h"
#include	"GLRenderTarget.h"
#include	"GLDepthTarget.h"

namespace Mof {
	
	/*******************************//*!
	@brief	OpenGL�O���t�B�b�N�X�X�e�[�^�X�\����

			�O���t�B�b�N�X�̃X�e�[�^�X��\���\����

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_OPENGLGRAPHICSSTATUS : public tag_GRAPHICSSTATUS {
		MofS32					ScreenWidth;			//!<��
		MofS32					ScreenHeight;			//!<����
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		tag_OPENGLGRAPHICSSTATUS() :
		tag_GRAPHICSSTATUS(),
		ScreenWidth(0),
		ScreenHeight(0) {
		}
	}OPENGLGRAPHICSSTATUS,*LPOPENGLGRAPHICSSTATUS;

	/*******************************//*!
	@brief	�O���t�B�b�N�X���C���^�[�t�F�C�X

			�O���t�B�b�N�X�̊��ƂȂ�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLGraphics : public IGraphics {
	protected:
		/*******************//*!
		�O���t�B�b�N�X�X�e�[�^�X
		*//********************/
		OPENGLGRAPHICSSTATUS	m_Status;
		/*******************//*!
		�`��^�[�Q�b�g
		*//********************/
		LPRenderTarget			m_pDefaultRenderTarget;
		/*******************//*!
		�[�x�^�[�Q�b�g
		*//********************/
		LPDepthTarget			m_pDefaultDepthTarget;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLGraphics();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLGraphics();

		/*************************************************************************//*!
				@brief			�O���t�B�b�N�X�I�u�W�F�N�g�̐���
				@param[in]		pInfo		�O���t�B�b�N�X�̐������
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPGRAPHICSCREATEINFO pInfo);
		
		/*************************************************************************//*!
				@brief			��ʃ��[�h��ݒ肷��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ChangeScreenMode(void);

		/*************************************************************************//*!
				@brief			�`��̊J�n
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderStart(void);
		/*************************************************************************//*!
				@brief			�S�^�[�Q�b�g�̃N���A
				@param[in]		d			�[�x
				@param[in]		s			�X�e���V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearTarget(void);
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
		virtual MofBool ClearTarget(MofFloat r,MofFloat g,MofFloat b,MofFloat a,MofFloat d,MofU32 s);
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g�̃N���A
				@param[in]		r			��
				@param[in]		g			��
				@param[in]		b			��
				@param[in]		a			�A���t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearRenderTarget(MofFloat r,MofFloat g,MofFloat b,MofFloat a);
		/*************************************************************************//*!
				@brief			�[�x�X�e���V���^�[�Q�b�g�̃N���A
				@param[in]		d			�[�x
				@param[in]		s			�X�e���V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearDepthStencilTarget(MofFloat d,MofU32 s);
		/*************************************************************************//*!
				@brief			�[�x�^�[�Q�b�g�̃N���A
				@param[in]		d			�[�x
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearDepthTarget(MofFloat d);
		/*************************************************************************//*!
				@brief			�X�e���V���^�[�Q�b�g�̃N���A
				@param[in]		s			�X�e���V��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool ClearStencilTarget(MofU32 s);
		/*************************************************************************//*!
				@brief			�`��̏I��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool RenderEnd(void);
		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�`��p��ʃT�C�Y��ݒ肷��
				@param[in]		sw				��
				@param[in]		sh				����
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetScreenSize(MofS32 sw,MofS32 sh);
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
		virtual MofBool SetViewPort(const MofFloat px,const MofFloat py,const MofFloat w,const MofFloat h,const MofFloat n,const MofFloat f);
		/*************************************************************************//*!
				@brief			�r���[�|�[�g�ݒ�
				@param[in]		v			�r���[�|�[�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetViewPort(const ViewPort& v);
		/*************************************************************************//*!
				@brief			�u�����h�X�e�[�g�̐ݒ�
				@param[in]		Blend		�u�����h���@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBlending(Blending Blend);
		/*************************************************************************//*!
				@brief			�F�������݂̐ݒ�
				@param[in]		bEnable		�L���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetColorWriteEnable(MofBool bEnable);
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�̐ݒ�
				@param[in]		bEnable		����L���t���O
				@param[in]		bWEnable	�������ݗL���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthEnable(MofBool bEnable,MofBool bWEnable);
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�̐ݒ�
				@param[in]		bEnable		����L���t���O
				@param[in]		bWEnable	�������ݗL���t���O
				@param[in]		fn			��r�֐�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthEnable(MofBool bEnable,MofBool bWEnable,ComparisonFunc fn);
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�̐ݒ�
				@param[in]		bEnable		�L���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthEnable(MofBool bEnable);
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�������݂̐ݒ�
				@param[in]		bEnable		�L���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthWriteEnable(MofBool bEnable);
		/*************************************************************************//*!
				@brief			�[�x�o�b�t�@�̐ݒ�
				@param[in]		fn			��r�֐�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetDepthFunction(ComparisonFunc fn);
		/*************************************************************************//*!
				@brief			�X�e���V���o�b�t�@�̐ݒ�
				@param[in]		bEnable		�L���t���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetStencilEnable(MofBool bEnable);
		/*************************************************************************//*!
				@brief			�X�e���V���o�b�t�@�̐ݒ�
				@param[in]		ref			�ݒ萔�l
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetStencilValue(MofU32 ref);
		/*************************************************************************//*!
				@brief			�X�e���V���o�b�t�@�̐ݒ�
				@param[in]		fn			�u��������r�֐�
				@param[in]		PassOp		�u��������r�֐�
				@param[in]		ZFailOp		�u��������r�֐�
				@param[in]		FailOp		�u��������r�֐�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetStencilControl(ComparisonFunc fn,StencilOp PassOp,StencilOp ZFailOp,StencilOp FailOp);
		/*************************************************************************//*!
				@brief			�v���~�e�B�u�`����@�ݒ�
				@param[in]		Topology	�`����@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTopology(PrimitiveTopology Topology);
		/*************************************************************************//*!
				@brief			�h��Ԃ��`����@�ݒ�
				@param[in]		Mode		�h��Ԃ����@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetFillMode(FillMode Mode);
		/*************************************************************************//*!
				@brief			�J�����O���@�ݒ�
				@param[in]		Mode		�J�����O���@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetCullMode(CullMode Mode);
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�ݒ�
				@param[in]		pBuff		���_�o�b�t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetVertexBuffer(LPVertexBuffer pBuff);
		/*************************************************************************//*!
				@brief			���_�o�b�t�@�ݒ�
				@param[in]		pBuff1		���_�o�b�t�@
				@param[in]		pBuff2		���_�o�b�t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetVertexBuffer(LPVertexBuffer pBuff1, LPVertexBuffer pBuff2);
		/*************************************************************************//*!
				@brief			���_���C�A�E�g�ݒ�
				@param[in]		pLayout		���_���C�A�E�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetVertexLayout(MofVertexLayout pLayout);
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�o�b�t�@�ݒ�
				@param[in]		pBuff		�C���f�b�N�X�o�b�t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetIndexBuffer(LPIndexBuffer pBuff);
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g�ݒ�
				@param[in]		pRenderTarget	�`��^�[�Q�b�g
				@param[in]		pDepthTarget	�[�x�^�[�Q�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetRenderTarget(LPRenderTarget pRenderTarget, LPDepthTarget pDepthTarget);
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g�ݒ�
				@param[in]		NumViews		�`��^�[�Q�b�g�̐�
				@param[in]		ppRenderTarget	�`��^�[�Q�b�g�z��ւ̃|�C���^
				@param[in]		pDepthTarget	�[�x�^�[�Q�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetMultiRenderTarget(MofU32 NumViews,LPRenderTarget* ppRenderTarget,LPDepthTarget pDepthTarget);
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g����ς����Ɏw�肵���ԍ��̕`��^�[�Q�b�g�������ւ���
				@param[in]		index			�C���f�b�N�X
				@param[in]		pRenderTarget	�`��^�[�Q�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetRenderTargetAt(MofU32 index,LPRenderTarget pRenderTarget);
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g����ς����Ɏw�肵���ԍ��̕`��^�[�Q�b�g�������ւ���
				@param[in]		index			�C���f�b�N�X
				@param[in]		pRenderTarget	�`��^�[�Q�b�g
				@param[in]		pDepthTarget	�[�x�^�[�Q�b�g
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetRenderTargetAt(MofU32 index,LPRenderTarget pRenderTarget, LPDepthTarget pDepthTarget);
		/*************************************************************************//*!
				@brief			�`��^�[�Q�b�g���ݒ�
				@param			NumViews	�`��^�[�Q�b�g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetRenderTargetCount(MofU32 NumViews);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�O���t�B�b�N�X�f�o�C�X�擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�O���t�B�b�N�X�f�o�C�X
		*//**************************************************************************/
		virtual MofGraphicsDevice GetDevice(void);
		/*************************************************************************//*!
				@brief			�X���b�v�`�F�C���擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�X���b�v�`�F�C��
		*//**************************************************************************/
		virtual MofSwapChain GetSwapChain(void);
		/*************************************************************************//*!
				@brief			�R���e�L�X�g�擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�R���e�L�X�g
		*//**************************************************************************/
		virtual MofDeviceContext GetDeviceContext(void);
		/*************************************************************************//*!
				@brief			�T���v���[�X�e�[�g�擾<br>
								�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
				@param			None

				@return			�T���v���[�X�e�[�g
		*//**************************************************************************/
		virtual MofSamplerState GetSamplerState(MofU32 s);
		/*************************************************************************//*!
				@brief			�^�[�Q�b�g�E�C���h�E�̕��擾
				@param			None

				@return			�^�[�Q�b�g�E�C���h�E�̕�
		*//**************************************************************************/
		virtual MofS32 GetTargetWidth(void);
		/*************************************************************************//*!
				@brief			�^�[�Q�b�g�E�C���h�E�̍����擾
				@param			None

				@return			�^�[�Q�b�g�E�C���h�E�̍���
		*//**************************************************************************/
		virtual MofS32 GetTargetHeight(void);
		/*************************************************************************//*!
				@brief			�Ή���ʃT�C�Y���X�g�擾�ݒ�
				@param[out]		pList		�C���f�b�N�X�o�b�t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool GetDisplayModeList(LPDISPLAYMODELIST pList);
		/*************************************************************************//*!
				@brief			�ݒ���擾
				@param			None
				
				@return			�O���t�B�b�N�ݒ�
		*//**************************************************************************/
		virtual const GRAPHICSSTATUS& GetStatus(void);
		/*************************************************************************//*!
				@brief			���݂̕`��^�[�Q�b�g�擾
				@param[out]		None
				
				@return			���݂̕`��^�[�Q�b�g
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTarget(void);
		/*************************************************************************//*!
				@brief			�w�肵���ԍ��̕`��^�[�Q�b�g�擾
				@param[in]		index		
				
				@return			���݂̕`��^�[�Q�b�g
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTargetAt(MofU32 index);
		/*************************************************************************//*!
				@brief			���݂̕`��^�[�Q�b�g�����擾
				@param			None
				
				@return			���݂̕`��^�[�Q�b�g��
		*//**************************************************************************/
		virtual MofU32 GetRenderTargetCount(void);
		/*************************************************************************//*!
				@brief			���݂̐[�x�^�[�Q�b�g�擾
				@param[out]		None
				
				@return			���݂̐[�x�^�[�Q�b�g
		*//**************************************************************************/
		virtual LPDepthTarget GetDepthTarget(void);
		/*************************************************************************//*!
				@brief			�u�����h�X�e�[�g�擾
				@param[out]		None
				
				@return			���݂̃u�����h�X�e�[�g
		*//**************************************************************************/
		virtual Blending GetBlending(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CGLGraphics,MOF_GLGRAPHICSCLASS_ID);
	};
	
	#include	"GLGraphics.inl"

}

#endif

//[EOF]
