/*************************************************************************//*!
					
					@file	GLCommon.h
					@brief	�O���t�B�b�N�X�֘A�̊�{��`���s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLCOMMON__H__

#define		__GLCOMMON__H__

#ifdef		MOFLIB_ANDROID

#include	<GLES2/gl2.h>
#include	<GLES2/gl2ext.h>

//�ꕔ���O�Ⴂ�̊֐��̒u������
#define			glClearDepth						glClearDepthf

#else

#include	<gl/GL.h>

#endif

namespace Mof {
	typedef struct tag_GLVERTEX_LAYOUT{
		GLuint			indx;
		GLint			size;
		GLenum			type;
		GLboolean		normalized;
		GLsizei			stride;
		const GLvoid*	ptr;
	}GLVERTEX_LAYOUT, *LPGLVERTEX_LAYOUT;
	typedef CDynamicArray<GLVERTEX_LAYOUT> CGLLayoutArray;
	typedef CGLLayoutArray* LPGLLayoutArray;
}


typedef		LPMofVoid							MofGraphicsDevice;
typedef		LPMofVoid							MofSwapChain;
typedef		LPMofVoid							MofDeviceContext;
typedef		GLuint					MofRenderTarget;
typedef		GLuint					MofDepthTarget;
typedef		GLuint								MofTexture;
typedef		GLuint								MofTextureHandle;
typedef		GLuint								MofVertexShader;
typedef		GLuint								MofPixelShader;
typedef		GLuint								MofShaderEffect;
typedef		GLuint								MofVertexBuffer;
typedef		Mof::LPGLLayoutArray	MofVertexLayout;
typedef		GLuint								MofIndexBuffer;
typedef		LPMofVoid							MofSamplerState;
typedef		GLuint								MofFont;

//DEFINE
#define		SHADERPARAM_ALIGNMENT		
#define		SHADERCOMPILE_DEFAULTFLAG			0
#define		SHADERLOAD_DEFAULT(f)				(LPMofVoid)MOF_VALUECONNECT_IN(f,_VS),sizeof(MOF_VALUECONNECT_IN(f,_VS)),(LPMofVoid)MOF_VALUECONNECT_IN(f,_PS),sizeof(MOF_VALUECONNECT_IN(f,_PS))
#define		MOF_DEFAULTFONTFACE					"Arial"

namespace Mof {

	typedef		VERTEX_NORMAL_TEXTURE1_COLORF1		DefaultGeometryVertex;
#define		DEFAULT_GEOMETRYVERTEXCOLOR(v)			v.cr = 1.0f;	v.cg = 1.0f;	v.cb = 1.0f;	v.ca = 1.0f;

	namespace GLImpl {

		/*************************************************************************//*!
			@brief			GLenum�����p��r�֐��ϊ��֐�
			@param[in]		f			��r�֐�

			@return			OpenGL�p��r�֐�
		*//**************************************************************************/
		GLenum ConvertComparisonFunc(ComparisonFunc f);

		/*************************************************************************//*!
				@brief			OpenGL�����p�X�e���V�������ϊ��֐�
				@param[in]		op			�X�e���V������

				@return			OpenGL�p�X�e���V������
		*//**************************************************************************/
		GLenum ConvertStencilOp(StencilOp op);
	}
}

#endif
