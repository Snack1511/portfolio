Shader "Custom/LightTest/07.Rimlight"
{
	Properties
	{
		_MainTex("Albedo (RGB)", 2D) = "white" {}
	}
		SubShader
	{
		Tags { "RenderType" = "Opaque" }
		//cull off// RimLight 2Side

		CGPROGRAM
		#pragma surface surf Lambert noambient

		#pragma target 3.0

		sampler2D _MainTex;

		struct Input
		{
			float2 uv_MainTex;
			float3 viewDir;//유니티 쉐이더에서 제공하는 내장변수 -> 뷰방향 -> 카메라가 보는 벡터를 제공
		};


		void surf(Input IN, inout SurfaceOutput o)
		{
			fixed4 c = tex2D(_MainTex, IN.uv_MainTex);
			float rim = dot(IN.viewDir, o.Normal);//카메라 벡터에 따라 그림자 극대화

			o.Emission = pow(1-rim, 4)*float3(1, 0, 0);//극대화된 그림자 반전 -> 1에서 rim값 뺀 후 4제곱
		}
		ENDCG
	}
		FallBack "Diffuse"
}