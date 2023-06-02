#ifdef SHADER_INCLUDE

const char* g_EdgeBaseOutput_Single_VS =
"attribute vec4 pos;\n"
"attribute vec4 normal;\n"
"attribute vec2 Tex;\n"
"attribute vec4 color;\n"
"varying vec2 OUV;\n"
"varying vec3 ONORMAL;\n"
"varying vec4 OVCOL;\n"
"varying vec4 OVPOS;\n"
"uniform mat4 mtxWorld;\n"
"uniform vec4 colRevise;\n"
"uniform vec4 CoordsRevise;\n"
"uniform mat4 mtxView;\n"
"uniform mat4 mtxProj;\n"
"uniform vec4 vecViewPos;\n"
"void main(){\n"
	"mat4 mtxVP = mtxView * mtxProj;\n"
	"mat4 mtxWVP = mtxWorld * mtxVP;\n"
	"mat3 nmWorld = mat3(mtxWorld);\n"
	"vec4 wpos = pos * mtxWorld;\n"
	"gl_Position = pos * mtxWVP;\n"
	"OVPOS = wpos * mtxView;\n"
	"OVPOS.w = vecViewPos.w;\n"
	"ONORMAL = normalize( normal.xyz * nmWorld);\n"
	"OVCOL = color * colRevise;\n"
	"OUV = Tex + CoordsRevise.xy;\n"
"}\n";

const char* g_EdgeBaseOutput_Single_PS =
"precision mediump float;\n"
"varying vec2 OUV;\n"
"varying vec3 ONORMAL;\n"
"varying vec4 OVCOL;\n"
"varying vec4 OVPOS;\n"
"uniform vec4 matDiffuse;\n"
"uniform vec4 matAmbient;\n"
"uniform vec4 matSpeculer;\n"
"uniform vec4 matEmissive;\n"
"uniform float matPower;\n"
"uniform vec3 litDirection;\n"
"uniform vec4 litDiffuse;\n"
"uniform vec4 litAmbient;\n"
"uniform vec4 litSpeculer;\n"
"uniform float cbMask;\n"
"uniform sampler2D txDiffuse;\n"
"void main(){\n"
	"float alpha = matDiffuse.w * OVCOL.w * texture2D(txDiffuse, OUV).w;\n"
	"if(alpha < 0.004f){ discard; }\n"
	"gl_FragColor = vec4(normalize(ONORMAL)*0.5f+0.5f, OVPOS.z / OVPOS.w);\n"
"}\n";

#else
extern const char* g_EdgeBaseOutput_Single_VS;
extern const char* g_EdgeBaseOutput_Single_PS;
#endif
