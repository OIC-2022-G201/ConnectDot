/*************************************************************************//*!
					
					@file	RenderCommandProxyImpl.h
					@brief	描画コマンドクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

#ifndef MOF_RENDERCOMMANDPROXY_DEFINE

#define	MOF_RENDERCOMMANDPROXY_DEFINE

#define	MOF_GRAPHICS_COMMANDMEMBER(...)								__VA_ARGS__

#define	MOF_GRAPHICSUTILITIES_COMMAND(cmd,param,member,copy,arg1,arg2)																	\
	class MOFLIBRARY_API MOF_VALUECONNECT2(C,cmd,Command) : public IRenderCommand {														\
	protected:																															\
		member																															\
	public:																																\
		MOF_VALUECONNECT2(C,cmd,Command) param { copy };																				\
		virtual MofBool Execute(void);																									\
		};																																	\
	virtual MofBool cmd param { if(!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< MOF_VALUECONNECT2(C,cmd,Command) > arg1 ) ? TRUE : FALSE); }

#define	MOF_GRAPHICSUTILITIES_COMMANDNO(cmd,param,member,copy,arg1,arg2,No)																\
	class MOFLIBRARY_API MOF_VALUECONNECT3(C,cmd,Command,No) : public IRenderCommand {													\
	protected:																															\
		member																															\
	public:																																\
		MOF_VALUECONNECT3(C,cmd,Command,No) param { copy };																				\
		virtual MofBool Execute(void);																									\
		};																																	\
	virtual MofBool cmd param { if(!m_pCommandList){ CreateCommandList(); } return ((m_pCommandList->AddCommand< MOF_VALUECONNECT2(C,cmd,Command) > arg1 ) ? TRUE : FALSE); }

#define	MOF_GRAPHICS_COMMAND(cmd,param,member,copy,arg1,arg2,...)																		\
	class MOFLIBRARY_API MOF_VALUECONNECT2(C,cmd,Command) : public IRenderCommand {														\
	protected:																															\
		member																															\
	public:																																\
		MOF_VALUECONNECT2(C,cmd,Command) param { copy };																				\
		virtual MofBool Execute(void);																									\
		};																																	\
	virtual MofBool cmd param { if(!m_pCommandList){ CreateCommandList(); } __VA_ARGS__ return ((m_pCommandList->AddCommand< MOF_VALUECONNECT2(C,cmd,Command) > arg1 ) ? TRUE : FALSE); }

#define	MOF_GRAPHICS_COMMANDNO(cmd,param,member,copy,arg1,arg2,No,...)																	\
	class MOFLIBRARY_API MOF_VALUECONNECT3(C,cmd,Command,No) : public IRenderCommand {													\
	protected:																															\
		member																															\
	public:																																\
		MOF_VALUECONNECT3(C,cmd,Command,No) param { copy };																				\
		virtual MofBool Execute(void);																									\
		};																																	\
	virtual MofBool cmd param { if(!m_pCommandList){ CreateCommandList(); } __VA_ARGS__ return ((m_pCommandList->AddCommand< MOF_VALUECONNECT3(C,cmd,Command,No) > arg1 ) ? TRUE : FALSE); }

#define	MOF_GRAPHICS_COMMAND2(cmd,param1,param2,member,copy1,copy2,arg1,arg2,arg3,...)													\
	class MOFLIBRARY_API MOF_VALUECONNECT2(C,cmd,Command) : public IRenderCommand {														\
	protected:																															\
		member																															\
	public:																																\
		MOF_VALUECONNECT2(C,cmd,Command) param1 { copy1 };																				\
		MOF_VALUECONNECT2(C,cmd,Command) param2 { copy2 };																				\
		virtual MofBool Execute(void);																									\
		};																																	\
	virtual MofBool cmd param1 { if(!m_pCommandList){ CreateCommandList(); } __VA_ARGS__ return ((m_pCommandList->AddCommand< MOF_VALUECONNECT2(C,cmd,Command) > arg1 ) ? TRUE : FALSE); }		\
	virtual MofBool cmd param2 { if(!m_pCommandList){ CreateCommandList(); } __VA_ARGS__ return ((m_pCommandList->AddCommand< MOF_VALUECONNECT2(C,cmd,Command) > arg2 ) ? TRUE : FALSE); }		

#define	MOF_GRAPHICS_COMMAND3(cmd,param1,param2,param3,member,copy1,copy2,copy3,arg1,arg2,arg3,arg4,...)								\
	class MOFLIBRARY_API MOF_VALUECONNECT2(C,cmd,Command) : public IRenderCommand {														\
	protected:																															\
		member																															\
	public:																																\
		MOF_VALUECONNECT2(C,cmd,Command) param1 { copy1 };																				\
		MOF_VALUECONNECT2(C,cmd,Command) param2 { copy2 };																				\
		MOF_VALUECONNECT2(C,cmd,Command) param3 { copy3 };																				\
		virtual MofBool Execute(void);																									\
		};																																	\
	virtual MofBool cmd param1 { if(!m_pCommandList){ CreateCommandList(); } __VA_ARGS__ return ((m_pCommandList->AddCommand< MOF_VALUECONNECT2(C,cmd,Command) > arg1 ) ? TRUE : FALSE); }		\
	virtual MofBool cmd param2 { if(!m_pCommandList){ CreateCommandList(); } __VA_ARGS__ return ((m_pCommandList->AddCommand< MOF_VALUECONNECT2(C,cmd,Command) > arg2 ) ? TRUE : FALSE); }		\
	virtual MofBool cmd param3 { if(!m_pCommandList){ CreateCommandList(); } __VA_ARGS__ return ((m_pCommandList->AddCommand< MOF_VALUECONNECT2(C,cmd,Command) > arg3 ) ? TRUE : FALSE); }		

#endif

#ifdef MOF_RENDERCOMMANDPROXY_INCLUDE

MOF_GRAPHICS_COMMAND(RenderStart,
	(void),
	;,
	;,
	(),
	());

MOF_GRAPHICS_COMMANDNO(ClearTarget,
	(void),
	; ,
	; ,
	(),
	(),
	1);

MOF_GRAPHICS_COMMANDNO(ClearTarget,
	(MofFloat r, MofFloat g, MofFloat b, MofFloat a, MofFloat d, MofU32 s),
	MOF_GRAPHICS_COMMANDMEMBER(MofFloat m_Red; MofFloat m_Green; MofFloat m_Blue; MofFloat m_Alpha; MofFloat m_Depth; MofU32 m_Stencil;),
	m_Red = r; m_Green = g; m_Blue = b; m_Alpha = a; m_Depth = d; m_Stencil = s;,
	(r, g, b, a, d, s),
	(m_Red, m_Green, m_Blue, m_Alpha, m_Depth, m_Stencil),
	2);

MOF_GRAPHICS_COMMAND(ClearRenderTarget,
	(MofFloat r, MofFloat g, MofFloat b, MofFloat a),
	MOF_GRAPHICS_COMMANDMEMBER( MofFloat m_Red; MofFloat m_Green; MofFloat m_Blue; MofFloat m_Alpha;),
	m_Red = r; m_Green = g; m_Blue = b; m_Alpha = a; ,
	(r, g, b, a),
	(m_Red, m_Green, m_Blue, m_Alpha));

MOF_GRAPHICS_COMMAND(ClearDepthStencilTarget,
	(MofFloat d, MofU32 s),
	MOF_GRAPHICS_COMMANDMEMBER(MofFloat m_Depth; MofU32 m_Stencil;),
	m_Depth = d; m_Stencil = s; ,
	(d,s),
	(m_Depth, m_Stencil));

MOF_GRAPHICS_COMMAND(ClearDepthTarget,
	(MofFloat d),
	MOF_GRAPHICS_COMMANDMEMBER(MofFloat m_Depth;),
	m_Depth = d;,
	(d),
	(m_Depth));

MOF_GRAPHICS_COMMAND(ClearStencilTarget,
	(MofU32 s),
	MOF_GRAPHICS_COMMANDMEMBER(MofU32 m_Stencil;),
	m_Stencil = s;,
	(s),
	(m_Stencil));

MOF_GRAPHICS_COMMAND(RenderEnd,
	(void) ,
	; ,
	; ,
	() ,
	());
		

MOF_GRAPHICS_COMMAND(ChangeScreenMode,
	(void),
	; ,
	; ,
	(),
	());
MOF_GRAPHICS_COMMAND(SetScreenSize,
	(MofS32 sw, MofS32 sh),
	MOF_GRAPHICS_COMMANDMEMBER(MofS32 m_Width;  MofS32 m_Height;),
	m_Width = sw; m_Height = sh; ,
	(sw,sh),
	(m_Width,m_Height));

MOF_GRAPHICS_COMMAND2(SetViewPort,
	(const MofFloat px, const MofFloat py, const MofFloat w, const MofFloat h, const MofFloat n, const MofFloat f),
	(const ViewPort& v),
	MOF_GRAPHICS_COMMANDMEMBER(ViewPort m_ViewPort;),
	m_ViewPort.x = px;	m_ViewPort.y = py;	m_ViewPort.w = w;	m_ViewPort.h = h;	m_ViewPort.n = n;	m_ViewPort.f = f; ,
	m_ViewPort = v; ,
	(px, py, w, h, n, f),
	(v),
	(m_ViewPort));

MOF_GRAPHICS_COMMAND(SetBlending,
	(Blending Blend),
	MOF_GRAPHICS_COMMANDMEMBER(Blending m_Blend;),
	m_Blend = Blend; ,
	(Blend),
	(m_Blend),
	m_ProxyStatus.BlendType[0] = Blend; );

MOF_GRAPHICS_COMMAND(SetColorWriteEnable ,
	(MofBool bEnable) ,
	MOF_GRAPHICS_COMMANDMEMBER(MofBool m_bEnable;),
	m_bEnable = bEnable; ,
	(bEnable),
	(m_bEnable),
	m_ProxyStatus.bColorWriteEnable = bEnable; );
		
MOF_GRAPHICS_COMMANDNO(SetDepthEnable,
	(MofBool bEnable, MofBool bWEnable),
	MOF_GRAPHICS_COMMANDMEMBER(MofBool m_bEnable; MofBool m_bWEnable;),
	m_bEnable = bEnable; m_bWEnable = bWEnable; ,
	(bEnable, bWEnable),
	(m_bEnable, m_bWEnable),
	1,
	m_ProxyStatus.bDepthEnable = bEnable; m_ProxyStatus.bDepthWriteEnable = bWEnable; );

MOF_GRAPHICS_COMMANDNO(SetDepthEnable,
	(MofBool bEnable, MofBool bWEnable, ComparisonFunc fn),
	MOF_GRAPHICS_COMMANDMEMBER(MofBool m_bEnable; MofBool m_bWEnable; ComparisonFunc m_Func;),
	m_bEnable = bEnable; m_bWEnable = bWEnable; m_Func = fn; ,
	(bEnable, bWEnable, fn),
	(m_bEnable, m_bWEnable, m_Func),
	2,
	m_ProxyStatus.bDepthEnable = bEnable; m_ProxyStatus.bDepthWriteEnable = bWEnable; m_ProxyStatus.DepthFunc = fn; );

MOF_GRAPHICS_COMMAND(SetDepthEnable,
	(MofBool bEnable),
	MOF_GRAPHICS_COMMANDMEMBER(MofBool m_bEnable;),
	m_bEnable = bEnable;,
	(bEnable),
	(m_bEnable),
	m_ProxyStatus.bDepthEnable = bEnable; );

MOF_GRAPHICS_COMMAND(SetDepthWriteEnable,
	(MofBool bEnable),
	MOF_GRAPHICS_COMMANDMEMBER(MofBool m_bEnable;),
	m_bEnable = bEnable; ,
	(bEnable),
	(m_bEnable),
	m_ProxyStatus.bDepthWriteEnable = bEnable; );

MOF_GRAPHICS_COMMAND(SetDepthFunction,
	(ComparisonFunc fn),
	MOF_GRAPHICS_COMMANDMEMBER(ComparisonFunc m_Func;),
	m_Func = fn;,
	(fn),
	(m_Func),
	m_ProxyStatus.DepthFunc = fn; );

MOF_GRAPHICS_COMMAND(SetStencilEnable,
	(MofBool bEnable),
	MOF_GRAPHICS_COMMANDMEMBER(MofBool m_bEnable;),
	m_bEnable = bEnable;,
	(bEnable),
	(m_bEnable),
	m_ProxyStatus.bStencilEnable = bEnable; );

MOF_GRAPHICS_COMMAND(SetStencilValue,
	(MofU32 ref),
	MOF_GRAPHICS_COMMANDMEMBER(MofU32 m_RefCount;),
	m_RefCount = ref; ,
	(ref),
	(m_RefCount),
	m_ProxyStatus.StencilRef = ref; );

MOF_GRAPHICS_COMMAND(SetStencilControl,
	(ComparisonFunc fn, StencilOp PassOp, StencilOp ZFailOp, StencilOp FailOp),
	MOF_GRAPHICS_COMMANDMEMBER(ComparisonFunc m_Func; StencilOp m_PassOp; StencilOp m_ZFailOp; StencilOp m_FailOp;),
	m_Func = fn; m_PassOp = PassOp; m_ZFailOp = ZFailOp; m_FailOp = FailOp; ,
	(fn, PassOp, ZFailOp, FailOp),
	(m_Func, m_PassOp, m_ZFailOp, m_FailOp),
	m_ProxyStatus.StencilFunc = fn; m_ProxyStatus.StencilPassOp = PassOp; m_ProxyStatus.StencilZFailOp = ZFailOp; m_ProxyStatus.StencilFailOp = FailOp;);

MOF_GRAPHICS_COMMAND(SetTopology,
	(PrimitiveTopology Topology),
	MOF_GRAPHICS_COMMANDMEMBER(PrimitiveTopology m_Topology;),
	m_Topology = Topology; ,
	(Topology),
	(m_Topology),
	m_ProxyStatus.Topology = Topology; );

MOF_GRAPHICS_COMMAND(SetFillMode,
	(FillMode Mode),
	MOF_GRAPHICS_COMMANDMEMBER(FillMode m_Mode;),
	m_Mode = Mode; ,
	(Mode),
	(m_Mode),
	m_ProxyStatus.FillType = Mode;);

MOF_GRAPHICS_COMMAND(SetCullMode,
	(CullMode Mode),
	MOF_GRAPHICS_COMMANDMEMBER(CullMode m_Mode;),
	m_Mode = Mode;,
	(Mode),
	(m_Mode),
	m_ProxyStatus.CullType = Mode;);

MOF_GRAPHICS_COMMAND(SetVertexBuffer,
	(LPVertexBuffer pBuff),
	MOF_GRAPHICS_COMMANDMEMBER(LPVertexBuffer m_pBuffer;),
	m_pBuffer = pBuff; ,
	(pBuff),
	(m_pBuffer),
	m_ProxyStatus.pVertexBuffer = pBuff;);

MOF_GRAPHICS_COMMAND(SetVertexLayout,
	(MofVertexLayout pLayout),
	MOF_GRAPHICS_COMMANDMEMBER(MofVertexLayout m_pLayout;),
	m_pLayout = pLayout; ,
	(pLayout),
	(m_pLayout),
	m_ProxyStatus.pVertexLayout = pLayout;);

MOF_GRAPHICS_COMMAND(SetIndexBuffer,
	(LPIndexBuffer pBuff),
	MOF_GRAPHICS_COMMANDMEMBER(LPIndexBuffer m_pBuffer;),
	m_pBuffer = pBuff;,
	(pBuff),
	(m_pBuffer),
	m_ProxyStatus.pIndexBuffer = pBuff;);

MOF_GRAPHICS_COMMAND(SetRenderTarget,
	(LPRenderTarget pRenderTarget, LPDepthTarget pDepthTarget),
	MOF_GRAPHICS_COMMANDMEMBER(LPRenderTarget m_pRenderTarget; LPDepthTarget m_pDepthTarget;),
	m_pRenderTarget = pRenderTarget; m_pDepthTarget = pDepthTarget; ,
	(pRenderTarget, pDepthTarget),
	(m_pRenderTarget, m_pDepthTarget),
	m_ProxyStatus.pRenderTargets[0] = pRenderTarget; m_ProxyStatus.pDepthTarget = pDepthTarget; m_ProxyStatus.RenderTargetCount = 1;);

MOF_GRAPHICS_COMMAND(SetMultiRenderTarget,
	(MofU32 NumViews, LPRenderTarget* ppRenderTarget, LPDepthTarget pDepthTarget),
	MOF_GRAPHICS_COMMANDMEMBER(MofU32 m_NumViews; LPRenderTarget m_pRenderTarget[MOF_RENDERTARGET_MAX]; LPDepthTarget m_pDepthTarget;),
	m_NumViews = NumViews; for (MofU32 i = 0; i < m_NumViews; i++){ m_pRenderTarget[i] = ppRenderTarget[i]; } m_pDepthTarget = pDepthTarget; ,
	(NumViews, ppRenderTarget, pDepthTarget),
	(m_NumViews, m_pRenderTarget, m_pDepthTarget),
	m_ProxyStatus.pDepthTarget = pDepthTarget; m_ProxyStatus.RenderTargetCount = NumViews; for (MofU32 i = 0; i < m_ProxyStatus.RenderTargetCount; i++) { m_ProxyStatus.pRenderTargets[i] = ppRenderTarget[i]; } );

MOF_GRAPHICS_COMMANDNO(SetRenderTargetAt,
	(MofU32 index, LPRenderTarget pRenderTarget, LPDepthTarget pDepthTarget),
	MOF_GRAPHICS_COMMANDMEMBER(MofU32 m_Index; LPRenderTarget m_pRenderTarget; LPDepthTarget m_pDepthTarget;),
	m_Index = index; m_pRenderTarget = pRenderTarget; m_pDepthTarget = pDepthTarget;,
	(index, pRenderTarget, pDepthTarget),
	(m_Index, m_pRenderTarget, m_pDepthTarget),
	1,
	m_ProxyStatus.pRenderTargets[index] = pRenderTarget; m_ProxyStatus.pDepthTarget = pDepthTarget;);

MOF_GRAPHICS_COMMANDNO(SetRenderTargetAt,
	(MofU32 index, LPRenderTarget pRenderTarget),
	MOF_GRAPHICS_COMMANDMEMBER(MofU32 m_Index; LPRenderTarget m_pRenderTarget; ),
	m_Index = index; m_pRenderTarget = pRenderTarget; ,
	(index, pRenderTarget),
	(m_Index, m_pRenderTarget),
	2,
	m_ProxyStatus.pRenderTargets[index] = pRenderTarget; );

MOF_GRAPHICS_COMMAND(SetRenderTargetCount,
	(MofU32 NumViews),
	MOF_GRAPHICS_COMMANDMEMBER(MofU32 m_NumViews;),
	m_NumViews = NumViews;,
	(NumViews),
	(m_NumViews),
	m_ProxyStatus.RenderTargetCount = 1; );

MOF_GRAPHICSUTILITIES_COMMAND(Set3DPrimitiveShaderImpl,
	(LPShader pShader, LPShaderBind pBind),
	MOF_GRAPHICS_COMMANDMEMBER(LPShader m_pShader; LPShaderBind m_pBind;),
	m_pShader = pShader; m_pBind = pBind; ,
	(pShader, pBind),
	(m_pShader, m_pBind));

MOF_GRAPHICSUTILITIES_COMMAND(SetSkinGeometryShaderImpl,
	(LPShader pShader, LPShaderBind pBind),
	MOF_GRAPHICS_COMMANDMEMBER(LPShader m_pShader; LPShaderBind m_pBind;),
	m_pShader = pShader; m_pBind = pBind;,
	(pShader, pBind),
	(m_pShader, m_pBind));

MOF_GRAPHICSUTILITIES_COMMAND(RenderPrimitive,
	(PrimitiveRenderParameter& prp, LPShader pShader, LPShaderBind pBind, LPGeometry pGeom),
	MOF_GRAPHICS_COMMANDMEMBER(PrimitiveRenderParameter m_RenderParameter; LPShader m_pShader; LPShaderBind m_pShaderBind; LPGeometry m_pGeometry;),
	m_RenderParameter = prp;  m_pShader = pShader; m_pShaderBind = pBind; m_pGeometry = pGeom; ,
	(prp, pShader, pBind, pGeom),
	(m_RenderParameter, m_pShader, m_pShaderBind, m_pGeometry));

MOF_GRAPHICSUTILITIES_COMMAND(RenderTexture,
	(const TextureRenderParameter& trp, LPShader pShader, LPShaderBind pBind, LPGeometry pGeom, LPTexture pTex),
	MOF_GRAPHICS_COMMANDMEMBER(TextureRenderParameter m_RenderParameter; LPShader m_pShader; LPShaderBind m_pShaderBind; LPGeometry m_pGeometry; LPTexture m_pTexture;),
	m_RenderParameter = trp;  m_pShader = pShader; m_pShaderBind = pBind; m_pGeometry = pGeom; m_pTexture = pTex; ,
	(trp, pShader, pBind, pGeom, pTex),
	(m_RenderParameter, m_pShader, m_pShaderBind, m_pGeometry, m_pTexture));

MOF_GRAPHICSUTILITIES_COMMAND(RenderGeometry,
	(LPGeometry pGeom, LPShader pShader, LPShaderBind pBind),
	MOF_GRAPHICS_COMMANDMEMBER(LPShader m_pShader; LPShaderBind m_pShaderBind; LPGeometry m_pGeometry;),
	m_pShader = pShader; m_pShaderBind = pBind; m_pGeometry = pGeom;,
	(pGeom, pShader, pBind),
	(m_pGeometry, m_pShader, m_pShaderBind));

#endif

//[EOF]