//! コンスタントバッファ
cbuffer cbSceneParam : register(b0)
{
	matrix	mtxView			: packoffset( c0 );
	matrix	mtxProj			: packoffset( c4 );
};

cbuffer cbMeshParam : register( b1 )
{
	float4	cbvOffset		: packoffset( c0 );
	float4	cbvSize			: packoffset( c1 );
	float4	cbtOffset		: packoffset( c2 );
	float4	cbtSize			: packoffset( c3 );
	float4	cbColor			: packoffset( c4 );
	matrix	mtxWorld		: packoffset( c5 );
};

cbuffer cbGameParam : register(b4)
{
	float2 Screen;    // x:画面幅,y:画面高さ
	int    nCount;    // 参照数
};

Texture2D txDiffuse : register( t0 );
SamplerState samLinear : register( s0 );

//! 頂点属性
struct InputVS
{
	float4	pos			: POSITION;
    float2	Tex			: TEXCOORD;
};
struct OutputVS
{
	float4	pos			: SV_POSITION;
    float2	Tex			: TEXCOORD0;
	float4	color		: COLOR0;
};

//! 頂点シェーダ
OutputVS RenderVS( InputVS inVert )
{
	OutputVS	outVert;
	
	float3 pv = mul( float4(inVert.pos * cbvSize.xyz + cbvOffset.xyz, 1), mtxWorld );
	float4 Pos = mul(float4(pv, 1), mtxView);
	outVert.pos = mul(Pos, mtxProj);

	outVert.color = cbColor;

    outVert.Tex = inVert.Tex * cbtSize.xy + cbtOffset.xy;

	return outVert;
}

//! ピクセルシェーダ
float4 RenderPS( OutputVS inPixel ) : SV_TARGET
{
	int  AllPixel = nCount * nCount;
	// 平均化するための基準矩形座用を求める
	int2 stex = int2(
		int(floor(inPixel.Tex.x * Screen.x / nCount)) * nCount,
		int(floor(inPixel.Tex.y * Screen.y / nCount)) * nCount
		);
	float2 tex = stex / Screen;

	float4 color = float4(0, 0, 0, 0);
	// 基準座標から参照数分のピクセルをサンプリングして平均化する
	for (int x = 0; x < nCount; ++x)
	{
		for (int y = 0; y < nCount; ++y)
		{
			color += txDiffuse.Sample(samLinear, tex + float2(x, y) / Screen);
		}
	}
	color /= AllPixel;
        return color * inPixel.color;
}

technique11 TShader
{
	pass P0
	{
		SetVertexShader(CompileShader(vs_4_0, RenderVS()));
		SetGeometryShader(NULL);
		SetHullShader(NULL);
		SetDomainShader(NULL);
		SetPixelShader(CompileShader(ps_4_0, RenderPS()));
		SetComputeShader(NULL);
	}
}
