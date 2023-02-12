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
cbuffer cbShadowRenderParam : register(b6)
{
    float2 resolution;
    float softShadows;
};

Texture2D txDiffuse : register(t0);
SamplerState samLinear : register(s0);

Texture2D u_texture2 : register(t1);
SamplerState samLiner2 : register(s1);

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
float sample(float2 coord, float r)
{
    return u_texture2.Sample(samLiner2, coord).r < r ? 0.0 : 1.0;
}
//! ピクセルシェーダ
float4 RenderPS(OutputVS inPixel)
    : SV_TARGET
{
    float2 norm = inPixel.Tex.xy * 2.0 - 1.0;
    float theta = atan2(norm.y, norm.x);

    float r = length(norm);
    float coord = (theta + PI) / (2.0 * PI);


    float2 tc = float2(coord, 0.0);

    float center = sample(tc, r);

    float blur = (1.0 / resolution.x) * smoothstep(0.0, 1.0, r);

    float sum = 0.0;

    sum += sample(float2(tc.x - 4.0 * blur, tc.y), r) * 0.05;
    sum += sample(float2(tc.x - 3.0 * blur, tc.y), r) * 0.09;
    sum += sample(float2(tc.x - 2.0 * blur, tc.y), r) * 0.12;
    sum += sample(float2(tc.x - 1.0 * blur, tc.y), r) * 0.15;

    sum += center * 0.16;

    sum += sample(float2(tc.x + 1.0 * blur, tc.y), r) * 0.15;
    sum += sample(float2(tc.x + 2.0 * blur, tc.y), r) * 0.12;
    sum += sample(float2(tc.x + 3.0 * blur, tc.y), r) * 0.09;
    sum += sample(float2(tc.x + 4.0 * blur, tc.y), r) * 0.05;

    float lit = min(0.3,lerp(center, sum, 1));

    return inPixel.color * float4(float3(1.0, 1.0, 1.0),lit * smoothstep(0.8, 0.0, r));
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
