#ifdef SHADER_INCLUDE

const char* g_ToneMap_VS =
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

const char* g_ToneMap_PS =
"precision mediump float;\n"
"varying vec2 OUV;\n"
"varying vec4 OVCOL;\n"
"uniform float cbMiddleGray;\n"
"uniform float cbBloomScale;\n"
"uniform sampler2D txDiffuse;\n"
"uniform sampler2D txAdaptedLum;\n"
"uniform sampler2D txBloom;\n"
"void main(){\n"
	//"gl_FragColor = vec4(texture2D(txAdaptedLum, vec2(0.5f,0.5f)).rrr,1);\n"
	//"gl_FragColor = texture2D(txBloom, OUV);\n"
	
	"float AdaptedLum = texture2D(txAdaptedLum, vec2(0.5f,0.5f)).r;\n"
	"vec3 Bloom = texture2D(txBloom, OUV).rgb;\n"

	"vec4 vSample = texture2D(txDiffuse, OUV);\n"
	"vSample.rgb *= cbMiddleGray/(AdaptedLum + 0.001f);\n"
	"vSample.rgb /= (1.0f+vSample.rgb);\n"

	"vSample.rgb += cbBloomScale * Bloom;\n"

	"gl_FragColor = vSample;\n"
	
"}\n";


#else
extern const char* g_ToneMap_VS;
extern const char* g_ToneMap_PS;
#endif
