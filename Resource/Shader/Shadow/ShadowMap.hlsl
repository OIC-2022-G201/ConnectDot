//! コンスタントバッファ
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

cbuffer cbShadowMapParam : register(b4)
{
    float2 resolution;
    float upScale;
    float accuracy;
};

Texture2D txDiffuse : register(t0);
SamplerState samLinear : register(s0);

const float PI = 3.14159;
const float THRESHOLD = 0.75;
//! 頂点属性
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
//! 頂点シェーダ
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

//! ピクセルシェーダ
float4 RenderPS(OutputVS inPixel)
    : SV_TARGET
{

    float distance = 1.0;
    float theta =  PI * 1.0 + (inPixel.Tex.x * 2.0 - 1.0) * PI;
    float add = 2.0 / 512.0;
    float2 pre_coord = float2(cos(theta), sin(theta)) * 0.5;
    for (float r = 0.0; r < 1.0; r += add)
    {

        float2 coord = -r * pre_coord + 0.5;

        float4 data = txDiffuse.Sample(samLinear, coord);

        if (data.a > THRESHOLD)
        {
            distance = r;
            break;
        }
    }
    return float4(distance / upScale, 0.0, 0.0, 1.0);;
}

technique11 TShader
{
    pass P0
    {
        SetVertexShader(CompileShader(vs_5_0, RenderVS()));
        SetGeometryShader(NULL);
        SetHullShader(NULL);
        SetDomainShader(NULL);
        SetPixelShader(CompileShader(ps_5_0, RenderPS()));
        SetComputeShader(NULL);
    }
}
