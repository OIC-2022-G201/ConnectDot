/*************************************************************************//*!
					
					@file	ShaderBind.h
					@brief	�V�F�[�_�[�o�C���h���C���^�[�t�F�C�X�B<br>
							�e�ݒ�o�b�t�@����̓��C�A�E�g���`���e���p�V�F�[�_�[���Ƀp�C�v���C���ɐݒ肷��B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERBIND__H__

#define		__SHADERBIND__H__

//INCLUDE
#include	"Material.h"
#include	"MeshMotionController.h"
#include	"CameraBase.h"
#include	"DirectionalLight.h"
#include	"ShaderBufferBase.h"
#include	"ShaderResourceBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�o�C���h�p���C�A�E�g�I�u�W�F�N�g

			�V�F�[�_�[�̂��߂̒��_���C�A�E�g�ݒ���s�����C�A�E�g�I�u�W�F�N�g�B

	@author	CDW
	*//********************************/
	typedef struct tag_SHADERBINDLAYOUT {
		VertexFlag							Flag;
		MofVertexLayout						pLayout;

		tag_SHADERBINDLAYOUT() :
		Flag(VERTEXFLAG_UNKOWN) ,
		pLayout(NULL) {
		}

		tag_SHADERBINDLAYOUT(const tag_SHADERBINDLAYOUT& pObj) :
			Flag(pObj.Flag),
			pLayout(pObj.pLayout) {
#ifdef		MOFLIB_DIRECTX11
			if (pLayout)
			{
				pLayout->AddRef();
			}
#endif
#ifdef		MOFLIB_DIRECTX12
			if (pLayout)
			{
				pLayout = new tag_MofVertexLayout(*pObj.pLayout);
			}
#endif
#ifdef		MOFLIB_OPENGL
			if (pLayout)
			{
				pLayout = new CGLLayoutArray(*pLayout);
			}
#endif
		}

		~tag_SHADERBINDLAYOUT(){
#ifdef		MOFLIB_DIRECTX11
			MOF_SAFE_RELEASE(pLayout);
#endif
#ifdef		MOFLIB_DIRECTX12
			MOF_SAFE_DELETE(pLayout);
#endif
#ifdef		MOFLIB_OPENGL
			MOF_SAFE_DELETE(pLayout);
#endif
		}
	}SHADERBINDLAYOUT, *LPSHADERBINDLAYOUT;
	typedef CDynamicArray< LPSHADERBINDLAYOUT > CBindLayout, *LPBindLayout;

	/*******************************//*!
	@brief	�V�F�[�_�[�o�C���h���C���^�[�t�F�C�X

			�V�F�[�_�[�̂��߂̃o�b�t�@�̐ݒ���s���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShaderBind : public IMofObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader) = 0;
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pvb			���_�o�b�t�@�z��
				@param[in]		Cnt			���_�o�b�t�@�z��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateVertexLayout(LPVertexBuffer* pvb, MofU32 Cnt = 0) = 0;

		/*************************************************************************//*!
				@brief			�o�C���h�̎��s
				@param[in]		pGeom		�W�I���g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Bind(LPGeometry pGeom = NULL) = 0;
		/*************************************************************************//*!
				@brief			�o�C���h�̎��s
				@param[in]		pGeom		�W�I���g��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool BindLayout(LPGeometry pGeom) = 0;
	
		/*************************************************************************//*!
				@brief			�o�b�t�@�̒ǉ�
				@param[in]		pName		���O
				@param[in]		size		�T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateShaderBuffer(LPCMofChar pName, MofU32 size) = 0;
		/*************************************************************************//*!
				@brief			�o�b�t�@�̒ǉ�
				@param[in]		pBuf		�o�b�t�@
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool AddShaderBuffer(LPShaderBuffer pBuf) = 0;
		/*************************************************************************//*!
				@brief			���\�[�X�̒ǉ�
				@param[in]		pName		���O
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateShaderResource(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			���\�[�X�̒ǉ�
				@param[in]		pRes		���\�[�X
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool AddShaderResource(LPShaderResource pRes) = 0;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n) = 0;
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pData		�f�[�^
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData) = 0;
		/*************************************************************************//*!
				@brief			�T���v���̐ݒ�<br>
								DirectX11�Ŏ��s���̂ݗL��<br>
								DirectX9�̏ꍇ�̓V�F�[�_�[�ł̎w�肪�AOpenGL�n�̏ꍇ�̓e�N�X�`���ł̎w�肪�L���ɂȂ�B
				@param[in]		n			�ԍ�
				@param[in]		st			�T���v���^�C�v
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetSamplerType(MofU32 n,MofU32 st) = 0;
		/*************************************************************************//*!
				@brief			�T���v���̐ݒ�<br>
								DirectX11�Ŏ��s���̂ݗL��<br>
								DirectX9�̏ꍇ�̓V�F�[�_�[�ł̎w�肪�AOpenGL�n�̏ꍇ�̓e�N�X�`���ł̎w�肪�L���ɂȂ�B
				@param[in]		n			�ԍ�
				@param[in]		pSamp		�T���v��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetSamplerState(MofU32 n,MofSamplerState pSamp) = 0;
		/*************************************************************************//*!
				@brief			�e�N�X�`���̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pTex		�e�N�X�`��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex) = 0;
		
		/*************************************************************************//*!
				@brief			�`��p�s���ݒ肷��
				@param[in]		wMat			�s��

				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(const Matrix44& wMat) = 0;
		/*************************************************************************//*!
				@brief			�`��p�s���ݒ肷��
				@param[in]		pMotion		���[�V�����R���g���[��
				@param[in]		pGeom		�W�I���g��
				
				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(LPMeshMotionController pMotion,LPGeometry pGeom) = 0;
		/*************************************************************************//*!
				@brief			�`��p�v���~�e�B�u�p�����[�^�[��ݒ肷��
				@param[in]		pPar			�e�N�X�`���p�����[�^�[

				@return			None
		*//**************************************************************************/
		virtual void SetPrimitiveParameter(LPPrimitiveRenderParameter pPar) = 0;
		/*************************************************************************//*!
				@brief			�`��p�e�N�X�`���p�����[�^�[��ݒ肷��
				@param[in]		pPar			�e�N�X�`���p�����[�^�[

				@return			None
		*//**************************************************************************/
		virtual void SetTextureParameter(LPTextureRenderParameter pPar) = 0;
		/*************************************************************************//*!
				@brief			�`��p�}�e���A����ݒ肷��
				@param[in]		pMat			�}�e���A��

				@return			None
		*//**************************************************************************/
		virtual void SetMaterial(LPMaterial pMat) = 0;
		/*************************************************************************//*!
				@brief			�`��p�J������ݒ肷��
				@param[in]		pc				�J����

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(LPCamera pc) = 0;
		/*************************************************************************//*!
				@brief			�`��p�J������ݒ肷��
				@param[in]		mv				�J����
				@param[in]		mp				�v���W�F�N�V����

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(Matrix44& mv,Matrix44& mp) = 0;
		/*************************************************************************//*!
				@brief			�`��p��{���C�g��ݒ肷��
				@param[in]		pl				���C�g

				@return			None
		*//**************************************************************************/
		virtual void SetDirectionalLight(LPDirectionalLight pl) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ݒ�p�����[�^�[�����擾����
				@param			None

				@return			�p�����[�^�[�̐�
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const = 0;
		/*************************************************************************//*!
				@brief			�ݒ�p�����[�^�[���擾����
				@param			None

				@return			�p�����[�^�[
		*//**************************************************************************/
		virtual LPShaderBufferArray GetShaderBuffer(void) = 0;
		/*************************************************************************//*!
				@brief			�ݒ�p�����[�^�[���擾����
				@param[in]		n				�ԍ�

				@return			�p�����[�^�[
		*//**************************************************************************/
		virtual LPShaderBuffer GetShaderBuffer(MofU32 n) = 0;
		/*************************************************************************//*!
				@brief			�ݒ�p�����[�^�[���擾����
				@param[in]		pName			���O

				@return			�p�����[�^�[
		*//**************************************************************************/
		virtual LPShaderBuffer GetShaderBufferByName(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			�ݒ胊�\�[�X���擾����
				@param			None

				@return			���\�[�X
		*//**************************************************************************/
		virtual LPShaderResourceArray GetShaderResource(void) = 0;
		/*************************************************************************//*!
				@brief			�ݒ胊�\�[�X���擾����
				@param[in]		n				�ԍ�

				@return			���\�[�X
		*//**************************************************************************/
		virtual LPShaderResource GetShaderResource(MofU32 n) = 0;
		/*************************************************************************//*!
				@brief			�ݒ胊�\�[�X���擾����
				@param[in]		pName			���O

				@return			���\�[�X
		*//**************************************************************************/
		virtual LPShaderResource GetShaderResourceByName(LPCMofChar pName) = 0;
	};
	
	//�|�C���^�u������
	typedef IShaderBind*			LPShaderBind;
}

#endif

//[EOF]
