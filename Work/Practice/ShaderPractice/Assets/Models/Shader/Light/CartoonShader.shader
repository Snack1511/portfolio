Shader "Custom/ShaderTest/NonPhotoRealistic/CartoonShader"
{
	//ToonShading, ToonRendering, Cell Shading
	//3D그래픽 만화같은 느낌을 주는 렌더링 방식이다.
	//셀 셰이딩을 구현하기 위해서는 외곽선을 만들어줘야한다. ==> 2Pass를 이용해 만들수 있다.
	//1Pass => 1번 그리기, 2Pass => 2번 그리기, 3Pass => 3번 그리기
    Properties
    {
        
        
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        
		//1Pass
		//외곽선을 그리는 곳
		cull front//먼저 호출
        CGPROGRAM
        #pragma surface surf Lambert vertex:vert
        sampler2D _MainTex;
        struct Input
        {
            float _Blank;
        };

		void vert(inout appdata_full v) {
			v.vertex.xyz += v.normal.xyz*0.01;
			
			//vertex 의 normal크기를 조절해 검게 나오게 함
			//이 위에 제대로된 셰이딩이 씌임면서 외곽선 효과가 나옴
		}

        void surf (Input IN, inout SurfaceOutput o)
        {
            o.Albedo = 0;//Albedo 내 전체 인수 전부 0으로
        }
        ENDCG



		//2Pass
		//본격적인 셀 셰이딩을 코딩하는곳
		cull back//다음 호출
		CGPROGRAM
        #pragma surface surf Lambert
		sampler2D _MainTex;
		struct Input
		{
			float _Blank;
		};

		void surf(Input IN, inout SurfaceOutput o)
		{
			o.Albedo = 1;
		}
		ENDCG
    }
    FallBack "Diffuse"
}
