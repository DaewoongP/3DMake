#include "Shader_Client_Defines.hlsli"

Texture2D gTexture;
float4x4 gWorldMatrix, gViewMatrix, gProjMatrix;

struct VS_IN
{
    float3 vPosition : POSITION;
    float2 vTexUV : TEXCOORD0;
};

struct VS_OUT
{
    float4 vPosition : SV_POSITION;
    float2 vTexUV : TEXCOORD0;
};

VS_OUT VS_MAIN(VS_IN _vsIn)
{
    VS_OUT vsOut = (VS_OUT) 0;

    float4x4 wvMatrix = mul(gWorldMatrix, gViewMatrix);
    float4x4 wvpMatrix = mul(wvMatrix, gProjMatrix);

    vsOut.vPosition = mul(vector(_vsIn.vPosition, 1.f), wvpMatrix);
    vsOut.vTexUV = _vsIn.vTexUV;

    return vsOut;
}

struct PS_IN
{
    float4 vPosition : SV_POSITION;
    float2 vTexUV : TEXCOORD0;
};

float4 PS_MAIN(PS_IN _psIn) : SV_TARGET0
{
    float4 color = (float4) 0;

    //color *= _psIn.vTexUV.x;
    
    color.a = 1.f;
    
    return color;
}

technique11 DefaultTechnique
{
    pass Test
    {
        SetRasterizerState(RS_Default);
        SetDepthStencilState(DSS_Default, 0);
        SetBlendState(BS_Default, float4(0.f, 0.f, 0.f, 0.f), 0xffffffff);

        VertexShader = compile vs_5_0 VS_MAIN();
        GeometryShader = NULL /*compile gs_5_0 GS_MAIN()*/;
        HullShader = NULL /*compile hs_5_0 HS_MAIN()*/;
        DomainShader = NULL /*compile ds_5_0 DS_MAIN()*/;
        PixelShader = compile ps_5_0 PS_MAIN();
    }
}