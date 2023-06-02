#ifdef SHADER_INCLUDE

const char* g_GBlur_VS =
"attribute vec4 pos;\n"
"attribute vec2 Tex;\n"
"varying vec2 OUVS[7];\n"
"varying vec4 OVCOL;\n"
"uniform vec4 cbvOffset;\n"
"uniform vec4 cbvSize;\n"
"uniform vec4 cbtOffset;\n"
"uniform vec4 cbtSize;\n"
"uniform vec4 cbColor;\n"
"uniform mat4 mtxWorld;\n"
"uniform mat4 mtxView;\n"
"uniform mat4 mtxProj;\n"
"uniform vec4 texOffsets[7];\n"
"void main(){\n"
	"vec4 pv = vec4(pos.xyz * cbvSize.xyz + cbvOffset.xyz, 1) * mtxWorld;\n"
	"mat4 mtxVP = mtxView * mtxProj;\n"
	"gl_Position = vec4(pv.xyz, 1) * mtxVP ;\n"
	"OVCOL = cbColor;\n"
	"OUVS[0] = Tex * cbtSize.xy + cbtOffset.xy + texOffsets[0].xy;\n"
	"OUVS[1] = Tex * cbtSize.xy + cbtOffset.xy + texOffsets[1].xy;\n"
	"OUVS[2] = Tex * cbtSize.xy + cbtOffset.xy + texOffsets[2].xy;\n"
	"OUVS[3] = Tex * cbtSize.xy + cbtOffset.xy + texOffsets[3].xy;\n"
	"OUVS[4] = Tex * cbtSize.xy + cbtOffset.xy + texOffsets[4].xy;\n"
	"OUVS[5] = Tex * cbtSize.xy + cbtOffset.xy + texOffsets[5].xy;\n"
	"OUVS[6] = Tex * cbtSize.xy + cbtOffset.xy + texOffsets[6].xy;\n"
"}\n";

const char* g_GBlur_PS =
"precision mediump float;\n"
"varying vec2 OUVS[7];\n"
"varying vec4 OVCOL;\n"
"uniform sampler2D txDiffuse;\n"
"uniform vec4 reverseOffset;\n"
"void main(){\n"
	"vec4 color;\n"
	"color =  0.099736f * (texture2D(txDiffuse, OUVS[0])\n"
	                    "+ texture2D(txDiffuse, OUVS[6] + reverseOffset.xy));\n"
	"color += 0.176033f * (texture2D(txDiffuse, OUVS[1])\n"
	                    "+ texture2D(txDiffuse, OUVS[5] + reverseOffset.xy));\n"
	"color += 0.120985f * (texture2D(txDiffuse, OUVS[2])\n"
	                    "+ texture2D(txDiffuse, OUVS[4] + reverseOffset.xy));\n"
	"color += 0.064759f * (texture2D(txDiffuse, OUVS[3])\n"
	                    "+ texture2D(txDiffuse, OUVS[3] + reverseOffset.xy));\n"
	"color += 0.026995f * (texture2D(txDiffuse, OUVS[4])\n"
	                    "+ texture2D(txDiffuse, OUVS[2] + reverseOffset.xy));\n"
	"color += 0.008764f * (texture2D(txDiffuse, OUVS[5])\n"
	                    "+ texture2D(txDiffuse, OUVS[1] + reverseOffset.xy));\n"
	"color += 0.002216f * (texture2D(txDiffuse, OUVS[6])\n"
	                    "+ texture2D(txDiffuse, OUVS[0] + reverseOffset.xy));\n"
	"gl_FragColor = color * OVCOL;\n"
"}\n";


#else
extern const char* g_GBlur_VS;
extern const char* g_GBlur_PS;
#endif
