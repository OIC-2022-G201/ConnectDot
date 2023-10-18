#ifdef SHADER_INCLUDE

const char* g_DownScale3x3Lum_VS =
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

const char* g_DownScale3x3Lum_PS =
"precision mediump float;\n"
"varying vec2 OUV;\n"
"varying vec4 OVCOL;\n"
"uniform vec2 cbPOffset;\n"
"uniform sampler2D txDiffuse;\n"
"void main(){\n"
	"float color = texture2D(txDiffuse, OUV - cbPOffset).r;\n"
	"color +=      texture2D(txDiffuse, OUV + vec2( 0,-cbPOffset.y)).r;\n"
	"color +=      texture2D(txDiffuse, OUV + vec2( cbPOffset.x,-cbPOffset.y)).r;\n"
	"color +=      texture2D(txDiffuse, OUV + vec2(-cbPOffset.x, 0)).r;\n"
	"color +=      texture2D(txDiffuse, OUV).r;\n"
	"color +=      texture2D(txDiffuse, OUV + vec2( cbPOffset.x, 0)).r;\n"
	"color +=      texture2D(txDiffuse, OUV + vec2(-cbPOffset.x, cbPOffset.y)).r;\n"
	"color +=      texture2D(txDiffuse, OUV + vec2( 0, cbPOffset.y)).r;\n"
	"color +=      texture2D(txDiffuse, OUV + cbPOffset).r;\n"
	"color /= 9.0f;\n"
	"gl_FragColor = vec4(color);\n"
"}\n";


#else
extern const char* g_DownScale3x3Lum_VS;
extern const char* g_DownScale3x3Lum_PS;
#endif
