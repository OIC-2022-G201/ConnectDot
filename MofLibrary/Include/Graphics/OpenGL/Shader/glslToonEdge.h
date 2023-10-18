#ifdef SHADER_INCLUDE

const char* g_ToonEdge_VS =
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

const char* g_ToonEdge_PS =
"precision mediump float;\n"
"varying vec2 OUV;\n"
"varying vec4 OVCOL;\n"
"uniform vec3 cbEdgeColor;\n"
"uniform float cbEdgeAlpha;\n"
"uniform float cbThresholdD;\n"
"uniform float cbThresholdN;\n"
"uniform float cbAtten;\n"
"uniform float cbFar;\n"
"uniform vec2 cbPOffset;\n"
"uniform sampler2D txDiffuse;\n"
"uniform sampler2D txDepthNormal;\n"
"uniform sampler2D txMask;\n"
"void main(){\n"
	"float maskValue = texture2D(txMask, OUV).r+\n"
		"texture2D(txMask, OUV + vec2(-cbPOffset.x, 0)).r+\n"
		"texture2D(txMask, OUV + vec2( cbPOffset.x, 0)).r+\n"
		"texture2D(txMask, OUV + vec2(0, -cbPOffset.y)).r+\n"
		"texture2D(txMask, OUV + vec2(0,  cbPOffset.y)).r;\n"
	
	"if(maskValue<=0){\n"
		"gl_FragColor = texture2D(txDiffuse, OUV);\n"
	"}else{\n"
		"vec4 c0 = texture2D(txDepthNormal, OUV);\n"
		"vec4 h0 = texture2D(txDepthNormal, OUV + vec2(-cbPOffset.x, 0));\n"
		"vec4 h1 = texture2D(txDepthNormal, OUV + vec2( cbPOffset.x, 0));\n"
		"vec4 v0 = texture2D(txDepthNormal, OUV + vec2(0, -cbPOffset.y));\n"
		"vec4 v1 = texture2D(txDepthNormal, OUV + vec2(0,  cbPOffset.y));\n"
		
		"// [“x\n"
		"float alphaD = smoothstep(0,cbThresholdD,abs((c0.a - (h0.a + h1.a + v0.a + v1.a)/4.0f)));\n"
		
		"// –@ü\n"
		"vec3 hN = h0.rgb - h1.rgb;\n"
		"vec3 vN = v0.rgb - v1.rgb;\n"
		"float alphaN = sqrt(dot(hN,hN) + dot(vN,vN));\n"
		"alphaN = smoothstep(cbThresholdN,1,alphaN);\n"
		"//return max(alphaD,alphaN);\n"

		"// ‹——£‚Å‚Ì“§–¾“x\n"
		"float alpha = max(0, 1.0f - c0.a * cbFar * cbAtten);\n"

		"gl_FragColor = mix(texture2D(txDiffuse, OUV),vec4(cbEdgeColor,1),max(alphaD,alphaN)*cbEdgeAlpha*alpha);\n"
	"}\n"
"}\n";


#else
extern const char* g_ToonEdge_VS;
extern const char* g_ToonEdge_PS;
#endif
