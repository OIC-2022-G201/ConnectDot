#ifdef SHADER_INCLUDE

const char* g_ToonShader_VS =
"attribute vec4 pos;\n"
"attribute vec4 normal;\n"
"attribute vec2 Tex;\n"
"attribute vec4 color;\n"
"varying vec2 OUV;\n"
"varying vec3 ONORMAL;\n"
"varying vec3 OEYE;\n"
"varying vec4 OVCOL;\n"
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
	"ONORMAL = normalize( normal.xyz * nmWorld);\n"
	"OEYE = normalize( wpos.xyz - vecViewPos.xyz );\n"
	"OVCOL = color * colRevise;\n"
	"OUV = Tex + CoordsRevise.xy;\n"
"}\n";

const char* g_ToonShader_PS =
"precision mediump float;\n"
"varying vec2 OUV;\n"
"varying vec3 ONORMAL;\n"
"varying vec3 OEYE;\n"
"varying vec4 OVCOL;\n"
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
"uniform sampler2D txToonMap;\n"
"void main(){\n"
	"vec3 amb = litAmbient.xyz * matAmbient.xyz;\n"
	"vec3 l = texture2D( txToonMap, vec2( 0.5f + dot( ONORMAL, -litDirection )/2, 0)).rgb;\n"
	"vec3 diff = l * litDiffuse.xyz * matDiffuse.xyz;\n"
	"vec4 LP = vec4( clamp( matEmissive.xyz + amb + diff, 0.0, 1.0 ) , matDiffuse.w ) * OVCOL;\n"
	"vec4 ocol = LP * texture2D( txDiffuse, OUV);\n"
	"vec3 R = reflect( OEYE, ONORMAL );\n"
	"ocol.xyz += litSpeculer.xyz * matSpeculer.xyz * pow( abs( max( 0 , dot( R, -litDirection ) ) ) , matPower );\n"
	"gl_FragColor = ocol;\n"
"}\n";

#else
extern const char* g_ToonShader_VS;
extern const char* g_ToonShader_PS;
#endif
