Shader "Custom/LightTest/08.CustomLight"
{
	Properties
	{
		_MainTex("Albedo (RGB)", 2D) = "white" {}
	}
		SubShader
	{
		Tags { "RenderType" = "Opaque" }

		CGPROGRAM
		#pragma surface surf MyLight //noambient

		#pragma target 3.0

		sampler2D _MainTex;

		struct Input
		{
			float2 uv_MainTex;
		};


		void surf(Input IN, inout SurfaceOutput o)
		{
			fixed4 c = tex2D(_MainTex, IN.uv_MainTex);
			o.Albedo = c.rgb;
			o.Alpha = c.a;
		}

		/*float4 LightingMyLight(SurfaceOutput s, float3 lightDir, float atten) {
		// 커스텀 조명을 만들기 위한 함수
		// 대충 Light<ShaderName>(SurfaceOutput s, float3 lightDir, float atten)형태로 생겼다.

			float fDot = saturate(dot(s.Normal, lightDir));//벡터두개 내적
			//대충 0이하는 0, 1이상은 1로 고정시키는 함수
			return fDot;
			//DirectionLight 받게
		}*/

		float4 LightingMyLight(SurfaceOutput s, float3 lightDir, float atten) {
			float fDot = dot(normalize(s.Normal), normalize(lightDir))*0.5+0.5;//Half Lambert
			
			//라이트 색상을 받는 코드
			float4 fLight;
			fLight.rgb = fDot * _LightColor0.rgb * atten; // _LightColor0 -> Lighting에 있는 내장함수 -> ()아님 0임 -> 라이트 색상을 가져옴
			fLight.a = s.Alpha;
			return fLight;
		}

		ENDCG
	}
		FallBack "Diffuse"
}