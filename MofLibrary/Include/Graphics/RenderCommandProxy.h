/*************************************************************************//*!
					
					@file	RenderCommandProxy.h
					@brief	�`��R�}���h�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__RENDERCOMMANDPROXY__H__

#define		__RENDERCOMMANDPROXY__H__

//INCLUDE
#include	"RenderThread.h"
#include	"../Graphics/Shader.h"
#include	"../Graphics/ShaderBindBase.h"

namespace Mof {

	/*******************************//*!
	@brief	�`��R�}���h�N���X

			�`��R�}���h�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRenderCommandProxy : public IMofBase {
	protected:
		/*******************//*!
		�R�}���h�t���b�V���X���b�h
		*//********************/
		LPRenderThread						m_pRenderThread;
		/*******************//*!
		�R�}���h�ǉ����X�g
		*//********************/
		LPRenderCommandList					m_pCommandList;
		/*******************//*!
		�R�}���h���s�O�̃X�e�[�^�X�ۑ�
		*//********************/
		GRAPHICSSTATUS						m_ProxyStatus;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CRenderCommandProxy();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pThread		�`��X���b�h

				@return			None
		*//**************************************************************************/
		CRenderCommandProxy(LPRenderThread pThread);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param[in]		None

				@return			None
		*//**************************************************************************/
		virtual ~CRenderCommandProxy(void);
		
		/*************************************************************************//*!
				@brief			�]���p�R�}���h���X�g�̍쐬
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CreateCommandList(void);

		/*************************************************************************//*!
				@brief			�R�}���h�̃t���b�V��
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool CommandFlush(void);
		
		/*************************************************************************//*!
				@brief			�ۑ���Ԃ̐ݒ�
				@param[in]		st			�ݒ�
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetStatus(const GRAPHICSSTATUS& st);
		
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

		//�R�}���h�̃C���N���[�h
#define	MOF_RENDERCOMMANDPROXY_INCLUDE
		#include	"RenderCommandProxyImpl.h"
#undef	MOF_RENDERCOMMANDPROXY_INCLUDE

		class MOFLIBRARY_API CShaderBindTextureCommand : public IRenderCommand {
		protected:
			LPShaderBind								m_pBind;
			LPTexture									m_pTexture;
			MofU32										m_No;
		public:
			CShaderBindTextureCommand(LPShaderBind pBind, LPTexture pTex, MofU32 n) : m_pBind(pBind), m_pTexture(pTex), m_No(n) { }
			virtual MofBool Execute(void){ return m_pBind->SetTexture(m_No, m_pTexture); }
		};
		MofBool SetBindTexture(LPShaderBind pBind, LPTexture pTex, MofU32 n){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindTextureCommand >(pBind, pTex, n)) ? TRUE : FALSE); }

		class MOFLIBRARY_API CShaderBindSamplerTypeCommand : public IRenderCommand {
		protected:
			LPShaderBind								m_pBind;
			MofU32										m_SamplerType;
			MofU32										m_No;
		public:
			CShaderBindSamplerTypeCommand(LPShaderBind pBind, MofU32 type, MofU32 n) : m_pBind(pBind), m_SamplerType(type), m_No(n) { }
			virtual MofBool Execute(void){ return m_pBind->SetSamplerType(m_No, m_SamplerType); }
		};
		MofBool SetBindSampler(LPShaderBind pBind, MofU32 type, MofU32 n){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindSamplerTypeCommand >(pBind, type, n)) ? TRUE : FALSE); }

		class MOFLIBRARY_API CShaderBindSamplerStateCommand : public IRenderCommand {
		protected:
			LPShaderBind								m_pBind;
			MofSamplerState								m_pSampler;
			MofU32										m_No;
		public:
			CShaderBindSamplerStateCommand(LPShaderBind pBind, MofSamplerState ps, MofU32 n) : m_pBind(pBind), m_pSampler(ps), m_No(n) { }
			virtual MofBool Execute(void){ return m_pBind->SetSamplerState(m_No, m_pSampler); }
		};
		MofBool SetBindSampler(LPShaderBind pBind, MofSamplerState ps, MofU32 n){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindSamplerStateCommand >(pBind, ps, n)) ? TRUE : FALSE); }

		template < typename T >
		class MOFLIBRARY_API CShaderBindCommand : public IRenderCommand {
		protected:
			LPShaderBind								m_pBind;
			T											m_Data;
			MofU32										m_No;
		public:
			CShaderBindCommand(LPShaderBind pBind, const T& param, MofU32 n) : m_pBind(pBind), m_Data(param), m_No(n) { }
			virtual MofBool Execute(void){ return m_pBind->SetBuffer(m_No, &m_Data); }
		};
		template < typename T > MofBool SetBindBuffer(LPShaderBind pBind, const T& param, MofU32 n){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindCommand< T > >(pBind, param, n)) ? TRUE : FALSE); }

		template < typename B, typename T, typename F >
		class MOFLIBRARY_API CShaderBindFunctionCommand : public IRenderCommand {
		protected:
			B											m_pBind;
			T											m_Data;
			F											m_Func;
		public:
			CShaderBindFunctionCommand(B pBind, const T& param, F func) : m_pBind(pBind), m_Data(param), m_Func(func) { }
			virtual MofBool Execute(void){ (m_pBind->*m_Func)(m_Data); return TRUE; }
		};
		template < typename B, typename T, typename F > MofBool SetBindFunction(B pBind, const T& param, F func){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindFunctionCommand< B, T, F > >(pBind, param, func)) ? TRUE : FALSE); }

		template < typename B, typename T, typename F >
		class MOFLIBRARY_API CShaderBindPointerFunctionCommand : public IRenderCommand {
		protected:
			B											m_pBind;
			T											m_Data;
			F											m_Func;
		public:
			CShaderBindPointerFunctionCommand(B pBind, const T& param, F func) : m_pBind(pBind), m_Data(param), m_Func(func) { }
			virtual MofBool Execute(void){ (m_pBind->*m_Func)(&m_Data); return TRUE; }
		};
		template < typename B, typename T, typename F > MofBool SetBindPointerFunction(B pBind, const T& param, F func){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CShaderBindPointerFunctionCommand< B, T, F > >(pBind, param, func)) ? TRUE : FALSE); }

		template < typename T >
		class MOFLIBRARY_API CResourceReleaseCommand : public IRenderCommand {
		protected:
			T											m_Data;
		public:
			CResourceReleaseCommand(T& param) : m_Data(param) { }
			virtual MofBool Execute(void){ MOF_SAFE_RELEASE(m_Data); return TRUE; }
		};
		template < typename T > MofBool ResourceRelease(T& param){ if (!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< CResourceReleaseCommand< T > >(param)) ? TRUE : FALSE); }

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTCOPY(CRenderCommandProxy, MOF_RENDERCOMMANDPROXYCLASS_ID);
	};

	typedef CRenderCommandProxy* LPRenderCommandProxy;

	#include	"RenderCommandProxy.inl"
}

#endif

//[EOF]