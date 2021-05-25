using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FolliowCam : MonoBehaviour {

    //타겟의 위치를 할당할 변수생성
    public static Transform tTargetTr;//추적할 타겟 게임오브젝트의 Transform변수
                               //카메라 거리 셋팅
    public float fDist = 10.0f;//카메라와의 일정거리
    public float fHeight = 3.0f;//카메라의 높이 설정

    //부드러운 추적 위한 변수 생성
    public float fDampTrace = 20.0f;//부드러운 추적을 위한 변수

    //카메라의 위치변수
    private Transform tr;//카메라 자신의 Transform변수


    // Use this for initialization
    void Start()
    {
        //카메라 자신의 Transform컴포넌트를 tr에 할당
        tr = GetComponent<Transform>();
        tr.position = new Vector3(0, 0, -10);
    }

    // Update is called once per frame
    void Update()
    {

    }

    //update함수 호출 이후 한번씩 호출하는 함수인 LateUpdate함수 사용
    //추적할 타깃의 이동이 종료된 이후에 카메라가 추적하기 위해 사용
    void LateUpdate()
    {
        //카메라의 위치를 추적대상의 dist변수만큼 뒤쪽으로 배치하고
        //height변수 만큼 위로 올림
        //Vector3.Lerp(Vector3 시작위치, Vector3종료위치, float 시간)
        tr.position = Vector3.Lerp(tr.position,//시작위치
            tTargetTr.position +new Vector3(0, 0, -10),//종료위치
            Time.deltaTime * fDampTrace);//보간시간(DampTrace조절하면 추적감도 조절가능)
        //(여기서는 new Vector3로 바로 받아보면 어떨까?)
        //카메라가 타깃 오브젝트를 바라보게 설정
        //tr.LookAt(tTargetTr);


    }
}
