#ifdef SHADER_INCLUDE

const char* g_DepthOutputSkinned_Single_VS =
"attribute vec4 pos;\n"
"attribute vec3 normal;\n"
"attribute vec4 weight;\n"
"attribute vec4 bindex;\n"
"attribute vec2 Tex;\n"
"attribute vec4 color;\n"
"varying vec4 OVPOS;\n"
"uniform vec4 mtxWorld[3 * 128];\n"
"uniform mat4 mtxView;\n"
"uniform mat4 mtxProj;\n"
"uniform vec4 vecViewPos;\n"
"uniform vec4 colRevise;\n"
"uniform vec4 CoordsRevise;\n"
"void main(){\n"
	"vec4 tPos = vec4(0.0, 0.0, 0.0, 1.0);\n"
	"int idx;\n"
	"idx = int(bindex[0]) * 3;\n"
	"tPos.x += dot( pos, mtxWorld[idx + 0] ) * weight[0];\n"
	"tPos.y += dot( pos, mtxWorld[idx + 1] ) * weight[0];\n"
	"tPos.z += dot( pos, mtxWorld[idx + 2] ) * weight[0];\n"
	"idx = int(bindex[1]) * 3;\n"
	"tPos.x += dot( pos, mtxWorld[idx + 0] ) * weight[1];\n"
	"tPos.y += dot( pos, mtxWorld[idx + 1] ) * weight[1];\n"
	"tPos.z += dot( pos, mtxWorld[idx + 2] ) * weight[1];\n"
	"idx = int(bindex[2]) * 3;\n"
	"tPos.x += dot( pos, mtxWorld[idx + 0] ) * weight[2];\n"
	"tPos.y += dot( pos, mtxWorld[idx + 1] ) * weight[2];\n"
	"tPos.z += dot( pos, mtxWorld[idx + 2] ) * weight[2];\n"
	"idx = int(bindex[3]) * 3;\n"
	"tPos.x += dot( pos, mtxWorld[idx + 0] ) * weight[3];\n"
	"tPos.y += dot( pos, mtxWorld[idx + 1] ) * weight[3];\n"
	"tPos.z += dot( pos, mtxWorld[idx + 2] ) * weight[3];\n"
	"mat4 mtxVP = mtxView * mtxProj;\n"
	"gl_Position = tPos * mtxVP;\n"
	"OVPOS = tPos * mtxView;\n"
	"OVPOS.w = vecViewPos.w;\n"
"}\n";

const char* g_DepthOutputSkinned_Single_PS =
"precision mediump float;\n"
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
"uniform sampler2D txDiffuse;\n"
"void main(){\n"
	"gl_FragColor = vec4(vec3(OVPOS.z/OVPOS.w),1);\n"
"}\n";


#else
extern const char* g_DepthOutputSkinned_Single_VS;
extern const char* g_DepthOutputSkinned_Single_PS;
#endif
