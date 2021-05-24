Shader "Custom/ShaderTest/Light/Non-PBS/05.BlinnphongLight"
{
	Properties
	{
		_Color("Color", Color) = (1, 1, 1, 1)
		_MainTex("Albedo (RGB)", 2D) = "white" {}
	    _SpecColor("Specular", Color) = (1,1,1,1)
	}
		SubShader
	{
		Tags { "RenderType" = "Opaque" }

		CGPROGRAM
		#pragma surface surf BlinnPhong

		#pragma target 3.0

		sampler2D _MainTex;

		struct Input
		{
			float2 uv_MainTex;
		};
		fixed4 _Color;


		void surf(Input IN, inout SurfaceOutput o)
		{
			fixed4 c = tex2D(_MainTex, IN.uv_MainTex) * _Color;
			o.Albedo = c.rgb;
			o.Specular = 0.5;
			o.Gloss = 1;
			o.Alpha = c.a;
		}
		ENDCG
	}
		FallBack "Diffuse"
}