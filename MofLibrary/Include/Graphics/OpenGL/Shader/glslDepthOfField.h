#ifdef SHADER_INCLUDE

const char* g_DepthOfField_VS =
"attribute vec4 pos;\n"
"attribute vec2 Tex;\n"
"varying vec2 OUV;\n"
"varying vec4 OVCOL;\n"
"uniform vec4 cbvOffset;\n"
"uniform vec4 cbvSize;\n"
"uniform vec4 cbtOffset;\n"
"uniform vec4 cbtSize;\n"
"uniform vec4 cbColor;\n"
"uniform mat4 mtxWorld;\n"
"uniform mat4 mtxView;\n"
"uniform mat4 mtxProj;\n"
"void main(){\n"
	"vec4 pv = vec4(pos.xyz * cbvSize.xyz + cbvOffset.xyz, 1) * mtxWorld;\n"
	"mat4 mtxVP = mtxView * mtxProj;\n"
	"gl_Position = vec4(pv.xyz, 1) * mtxVP ;\n"
	"OVCOL = cbColor;\n"
	"OUV = Tex * cbtSize.xy + cbtOffset.xy;\n"
"}\n";

const char* g_DepthOfField_PS =
"precision mediump float;\n"
"varying vec2 OUV;\n"
"varying vec4 OVCOL;\n"
"uniform float cbFocalDistance;\n"
"uniform float cbFocalRange;\n"
"uniform float cbFocalAttenuation;\n"
"uniform float cbFar;\n"
"uniform sampler2D txDiffuse;\n"
"uniform sampler2D txBlur;\n"
"uniform sampler2D txDepth;\n"
"void main(){\n"
	"float depth = texture2D(txDepth,OUV).z * cbFar;\n"
	"float alpha = min(1,max(0,abs(depth - cbFocalDistance) - cbFocalRange) / cbFocalAttenuation);\n"
	"vec4 color = texture2D(txDiffuse,OUV);\n"
	"vec4 blur  = texture2D(txBlur,OUV);\n"
	"gl_FragColor =  mix(color,blur,alpha) * OVCOL;\n"
"}\n";


#else
extern const char* g_DepthOfField_VS;
extern const char* g_DepthOfField_PS;
#endif
