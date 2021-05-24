Shader "Custom/ShaderTest/Light/PBR/PBS/06.PBR_PBS"
{
    Properties
    {
        _Color ("Color", Color) = (1,1,1,1)
        _MainTex ("Albedo (RGB)", 2D) = "white" {}
	    _Specular("Specular", Color) = (1, 1, 1 ,1)
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        CGPROGRAM

        #pragma surface surf StandardSpecular
        #pragma target 3.0

        sampler2D _MainTex;

        struct Input
        {
            float2 uv_MainTex;
        };

        fixed4 _Color;


        void surf (Input IN, inout SurfaceOutputStandardSpecular o)
        {
            fixed4 c = tex2D (_MainTex, IN.uv_MainTex) * _Color;
            o.Albedo = c.rgb;
			o.Specular = 0.5;
            o.Alpha = c.a;
        }
        ENDCG
    }
    FallBack "Diffuse"
}
