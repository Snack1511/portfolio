Shader "Custom/ShaderTest/Texture/03.UVAnimating"
{
    Properties
    {
        _MainTex ("Albedo (RGB)", 2D) = "white" {}
	    _MainTex2("Albedo (RGB)", 2D) = "white" {}
		_MainTex3("Albedo (RGB)", 2D) = "white" {}
		_Noise("찌그러짐", Range(0, 1)) = 1

    }
    SubShader
    {
        //Tags { "RenderType"="Opaque" }
		Tags { "RenderType" = "Transparent" "Queue" = "Transparent" }//이건 꼼수임

        CGPROGRAM
        //#pragma surface surf Standard 
        #pragma surface surf Standard alpha:fade//이거도 꼼수임 (최적화 영향ㅇㅇ)


        sampler2D _MainTex;
        sampler2D _MainTex2;
        sampler2D _MainTex3;

        struct Input
        {
            float2 uv_MainTex;
            float2 uv_MainTex2;
            float2 uv_MainTex3;
        };

		float _Noise;


        void surf (Input IN, inout SurfaceOutputStandard o)
        {
			float2 fPos = float2(0, -_Time.y);
            //fixed4 c = tex2D (_MainTex, IN.uv_MainTex + fPos);

			fixed4 d = tex2D(_MainTex2, IN.uv_MainTex2 + fPos);
			fixed4 e = tex2D(_MainTex3, IN.uv_MainTex3 - fPos);
			fixed4 c = tex2D(_MainTex, IN.uv_MainTex+e.r*_Noise + fPos);

            o.Emission = c.rgb*2;
			o.Alpha = c.a*d.a;
        }
        ENDCG
    }
    FallBack "Diffuse"
}
