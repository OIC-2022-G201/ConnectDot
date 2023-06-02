#ifdef SHADER_INCLUDE
const char* g_2DPrimitiveBase_VS =
"attribute vec4 pos;\n"
"attribute vec4 color;\n"
"varying vec4 OVCOL;\n"
"uniform vec4 cbvOffset;\n"
"uniform vec4 cbvSize;\n"
"uniform vec4 cbColor1;\n"
"uniform vec4 cbColor2;\n"
"uniform vec4 cbColor3;\n"
"uniform vec4 cbColor4;\n"
"uniform mat4 mtxWorld;\n"
"uniform mat4 mtxView;\n"
"uniform mat4 mtxProj;\n"
"void main(){\n"
	"vec4 pv = vec4(pos.xyz * cbvSize.xyz + cbvOffset.xyz, 1) * mtxWorld;\n"
	"mat4 mtxVP = mtxView * mtxProj;\n"
	"gl_Position = vec4(pv.xyz, 1) * mtxVP;\n"
	"OVCOL = cbColor1 * color.x + cbColor2 * color.y + cbColor3 * color.z + cbColor4 * color.w;\n"
"}\n";

const char* g_2DPrimitiveBase_PS =
"precision mediump float;\n"
"varying vec4 OVCOL;\n"
"void main(){\n"
	"gl_FragColor = OVCOL;\n"
"}\n";
#else
extern const char* g_2DPrimitiveBase_VS;
extern const char* g_2DPrimitiveBase_PS;
#endif
