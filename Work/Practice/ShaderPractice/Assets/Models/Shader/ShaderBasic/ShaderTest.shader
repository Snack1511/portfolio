Shader "Custom/ShaderTest/Texture/01.StandardSurfaceShaderTest"
{
    Properties
    {
        _Color ("Color", Color) = (1,1,1,1)
        _MainTex ("Albedo (RGB)", 2D) = "white" {}
		_Glossiness("Smoothness", Range(0,1)) = 0.5
		_Metallic("Metallic", Range(0,1)) = 0.0

		fVal1("NonRange Test", float) = 0.5
		fVal2("Range Test", Range(0, 1)) = 0.5

		fR("Red", Range(0, 1)) = 0.0
		fG("Green", Range(0, 1)) = 0.0
		fB("Blue", Range(0, 1)) = 0.0


    }// 프로퍼티 부분으로, Inspector 상에서 조절 할 수 있는 부분이 들어감.
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        LOD 200

//==========CG start ====================================================
        CGPROGRAM
        #pragma surface surf Standard fullforwardshadows

        #pragma target 3.0

        sampler2D _MainTex;

        struct Input
        {
            float2 uv_MainTex;
        };

		//fixed, half == float
        half _Glossiness;
        half _Metallic;
        fixed4 _Color;

		float fR;
		float fG;
		float fB;

        UNITY_INSTANCING_BUFFER_START(Props)
        UNITY_INSTANCING_BUFFER_END(Props)

        void surf (Input IN, inout SurfaceOutputStandard o)
        {
			
			//o.Albedo = float3(1, 0, 0);
			o.Emission = float3(fR, fG, fB);
        }
        ENDCG
//==========CG end ====================================================
    }//실제 쉐이더 코드가 작성되는 곳
    FallBack "Diffuse"//SubShader가 실패 할 경우, 출력하게 될 쉐이더
}
