using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Wobble : MonoBehaviour
{
    Renderer rend;
    //렌더러변수
    Vector3 lastPos;//마지막 위치
    Vector3 velocity;//속도
    Vector3 lastRot;//마지막 각도
    Vector3 angularVelocity;//각속도
    //벡터3 변수
    public float MaxWobble = 0.03f;//최대흔들림
    public float WobbleSpeed = 1f;//흔들림 속도
    public float Recovery = 1f;//흔들림 회복 속도
    //에디터에서 건드려지는 부분
    float wobbleAmountX;//x축 흔들림 현재크기
    float wobbleAmountZ;//z축 흔들림 현재크기
    float wobbleAmountToAddX;//x축 흔들림 크기 추가
    float wobbleAmountToAddZ;//z축 흔들림 크기 추가
    float pulse;//반복량
    float time = 0.5f;//흔들리는 시간
    //float형 변수
    // Use this for initialization
    void Start()
    {
        rend = GetComponent<Renderer>();
    }
    private void Update()
    {
        Wobbles();
    }

    void Wobbles() {
        time += Time.deltaTime;
        // decrease wobble over time
        wobbleAmountToAddX = Mathf.Lerp(wobbleAmountToAddX, 0, Time.deltaTime * (Recovery));
        wobbleAmountToAddZ = Mathf.Lerp(wobbleAmountToAddZ, 0, Time.deltaTime * (Recovery));
        //wobbleAmountToAddX/Z에서 0까지 Time.deltaTime*(Recovery)만큼 선형보간

        // make a sine wave of the decreasing wobble
        pulse = 2 * Mathf.PI * WobbleSpeed;//Sin에서 반복되는 크기량
        wobbleAmountX = wobbleAmountToAddX * Mathf.Sin(pulse * time);
        wobbleAmountZ = wobbleAmountToAddZ * Mathf.Sin(pulse * time);
        //sin파형을 이용해 흔들림을 감소


        // send it to the shader
        rend.material.SetFloat("_WobbleX", wobbleAmountX);
        rend.material.SetFloat("_WobbleZ", wobbleAmountZ);
        //쉐이더파일에서 _Wobble변수의 값을 WobbleAmount로 바꿔줌 

        // velocity
        velocity = (lastPos - transform.position)*0.05f/ Time.deltaTime;//현재 속도를 계산
        angularVelocity = transform.rotation.eulerAngles - lastRot;//현재 각속도를 계산


        // add clamped velocity to wobble
        wobbleAmountToAddX += Mathf.Clamp((velocity.x + (angularVelocity.z * 0.2f)) * MaxWobble, -MaxWobble, MaxWobble);
        wobbleAmountToAddZ += Mathf.Clamp((velocity.z + (angularVelocity.x * 0.2f)) * MaxWobble, -MaxWobble, MaxWobble);
        //(velocity.x/z + (angularVelocity.z/x * 0.2f)) * MaxWobble 이 -MaxWobble과 MaxWobble사이 외의 값이 되지 않도록 범위제한

        // keep last position
        lastPos = transform.position;
        lastRot = transform.rotation.eulerAngles;
        //현재위치와 각도를 업데이트
    }

}