Shader "Custom/ShaderTest/Texture/02.UV&Lerp"
{
    Properties
    {
        _MainTex ("Texture1", 2D) = "white" {}
		_MainTex2("Texture2", 2D) = "white" {}
		_Add("Add(Offset)", Range(-1, 1)) = 0
		_Multiply("Multiply(Tilting)", Range(-1, 1)) = 0
		_Increasing("Increasing(증감량)", Range(-10, 10)) = 0
		_LerpTest("러프실험", Range(0, 1)) = 0
	    _Brightness ("밝기조절", Range(-1, 1)) = 0

    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }

        CGPROGRAM
        #pragma surface surf Standard 


        sampler2D _MainTex;
		sampler2D _MainTex2;
		float _Add;
		float _Multiply;
		float _Increasing;
		float _LerpTest;
		float _Brightness;

        struct Input
        {
            float2 uv_MainTex;
			float2 uv_MainTex2;
        };



        void surf (Input IN, inout SurfaceOutputStandard o)
        {
			//fixed4 c = tex2D(_MainTex, IN.uv_MainTex+(_Add +_Increasing));
			//fixed4 d = tex2D(_MainTex2, IN.uv_MainTex2*(_Multiply*_Increasing));

			fixed4 c = tex2D(_MainTex, IN.uv_MainTex);
			fixed4 d = tex2D(_MainTex2, IN.uv_MainTex2);

            //o.Albedo = c.rgb + _Brightness;
			//o.Emission = float3(IN.uv_MainTex.x, IN.uv_MainTex.y, 0);

			//o.Emission = c.rgb;
			//o.Emission = d.rgb;
			//o.Emission = lerp(c.rgb, d.rgb, _LerpTest);
			//o.Emission = lerp(d.rgb, c.rgb, c.a);
			o.Emission = lerp(c.rgb, d.rgb, c.a);
        }
        ENDCG
    }
    FallBack "Diffuse"
}
