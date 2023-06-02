#ifdef SHADER_INCLUDE

const char* g_Bloom_VS =
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

const char* g_Bloom_PS =
"precision mediump float;\n"
"varying vec2 OUV;\n"
"varying vec4 OVCOL;\n"
"uniform float cbBloomScale;\n"
"uniform sampler2D txDiffuse;\n"
"uniform sampler2D txBloom;\n"
"void main(){\n"
	"vec4 ocol = texture2D(txDiffuse, OUV);\n"
	"ocol.rgb += texture2D(txBloom, OUV).rgb * cbBloomScale;\n"
	"gl_FragColor = ocol * OVCOL;\n"
"}\n";


#else
extern const char* g_Bloom_VS;
extern const char* g_Bloom_PS;
#endif
