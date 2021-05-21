using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MainDisplayManager : MonoBehaviour
{
    //------------------- 기본 변수 -------------------
    CGameManager CGM;
    Text Date;

    void Start()
    {
        CGM = GameObject.Find("GameManager").GetComponent<CGameManager>();
        Date = GameObject.Find("Date").GetComponent<Text>();
    }


    void Update()
    {
        PrintDate(CGM.GetDayTick());
    }
    //------------------- 내부사용 함수 -------------------
    public void PrintDate(int DayTick)
    {
        Date.text = "Day " + DayTick.ToString();
    }//날자 출력 함수

}
