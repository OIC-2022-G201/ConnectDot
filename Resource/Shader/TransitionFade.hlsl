cbuffer cbSceneParam : register(b0)
{
    matrix mtxView : packoffset(c0);
    matrix mtxProj : packoffset(c4);
};

cbuffer cbMeshParam : register(b1)
{
    float4 cbvOffset : packoffset(c0);
    float4 cbvSize : packoffset(c1);
    float4 cbtOffset : packoffset(c2);
    float4 cbtSize : packoffset(c3);
    float4 cbColor : packoffset(c4);
    matrix mtxWorld : packoffset(c5);
};
cbuffer Progress : register(b4)
{
    float progress;
};
Texture2D txDiffuse : register(t0);
SamplerState samLinear : register(s0);

struct InputVS
{
    float4 pos : POSITION;
    float2 Tex : TEXCOORD;
};
struct OutputVS
{
    float4 pos : SV_POSITION;
    float2 Tex : TEXCOORD0;
    float4 color : COLOR0;
};

// 頂点シェーダー
OutputVS RenderVS(InputVS inVert)
{
    OutputVS outVert;

    float3 pv = mul(float4(inVert.pos * cbvSize.xyz + cbvOffset.xyz, 1), mtxWorld);
    float4 Pos = mul(float4(pv, 1), mtxView);
    outVert.pos = mul(Pos, mtxProj);

    outVert.color = cbColor;

    outVert.Tex = inVert.Tex * cbtSize.xy + cbtOffset.xy;

    return outVert;
}

// フラグメントシェーダー
float4 RenderPS(OutputVS inPixel)
    : SV_TARGET
{
    float4 col = txDiffuse.Sample(samLinear, inPixel.Tex);
    float alpha = smoothstep(progress - 0.2, progress, 1 - col.rgb);
    col.rgb = inPixel.color.rgb;
    col.a = inPixel.color.a * alpha;
    return col;
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
