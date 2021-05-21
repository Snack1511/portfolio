using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using USERDEFINE;

public class CGameManager : MonoBehaviour
{
    //------------------- 기본 변수 -------------------
    CCities CityScript;
    UserSelectable US;
    //------------------- 시간관련 변수 -------------------
    int Tens_Hour, Units_Hour, Tens_Minute, Timerate, DayTick;//Time
    float _Time, StartTime, Timevalue;

    //------------------- MainDisplay용 변수 -------------------
    Text Total_Budget, WorldRecover, WorldFatal;
    bool UpdateDayflag;
    int WorldRecoverate;
    int WorldFatalirate;

    float CountryTotalBudget;

    GameObject CityFloatingPanel, CityQuarantinePanel;
    Text CityName, CityConfirm, CityIncrease;

    //------------------- SubDisplay용 변수 -------------------
    Text[] InfoData = new Text[14];
    public bool DayFlag;
    
    void Start()
    {
        CityScript = GameObject.Find("Cities").GetComponent<CCities>();
        US = GameObject.Find("UserSelectableManager").GetComponent<UserSelectable>();
        
        Timerate = 12;
        DayTick = 1;
        StartTime = Time.time;
        Timevalue = 480;

        Total_Budget = GameObject.Find("Totalbudget").GetComponent<Text>();
        WorldRecover = GameObject.Find("Recoverate").GetComponent<Text>();
        WorldFatal = GameObject.Find("Fatality").GetComponent<Text>();
        UpdateDayflag = false;
        WorldRecoverate = 0;
        WorldFatalirate = 100;
        CityScript.SetWorldPlague(WorldRecoverate, WorldFatalirate);

        CountryTotalBudget = 10000000000;

        CityFloatingPanel = GameObject.Find("CityFloatingPanel");
        CityQuarantinePanel = GameObject.Find("QuarantinePanelGroup");

        CityName = GameObject.Find("CityName").GetComponent<Text>();
        CityConfirm = GameObject.Find("CityConfirmed").GetComponent<Text>();
        CityIncrease = GameObject.Find("CityIIncreaseConfirmed").GetComponent<Text>();
        CityFloatingPanel.SetActive(false);

        //=========DebugLine
        

    }

    // Update is called once per frame
    void Update()//5초 = 1시간
    {
        TimeUpdate();
        Total_Budget.text = Functions.GetFormat(CountryTotalBudget);
        WorldRecover.text = WorldRecoverate.ToString() + "%";
        WorldFatal.text = WorldFatalirate.ToString() + "%";

        OnToggleFloatingPanel(CityScript.FloatingPanelflag, CityScript.FloatingPanelpos);
        SetPanel(CityScript);

        if (!CityScript.DayChackflag&& DayTick >= USERDEFINE.Const.DefaultDayGone) { CityScript.DayChackflag = true; }

        if (CityScript.GameOverFlag())
        {
            Debug.Log("GameOver");
            Debug.Break();
        }

        //=========DebugLine
        if (Input.GetKeyDown(KeyCode.F)) {
            setDebugFastest();
        }
        if (Input.GetKeyDown(KeyCode.D))
        {
            setDebugFast();
        }
        if (Input.GetKeyDown(KeyCode.S))
        {
            setDebugNormal();
        }
        if (Input.GetKeyDown(KeyCode.A))
        {
            setDebugStop();
        }

        if (Input.GetKeyDown(KeyCode.M))
        {
            CountryTotalBudget *= 10;
        }
        
    }

    //------------------- 시간 관련 함수 -------------------
    void TimeUpdate() {

        SetTime(Timerate);
        UpdateDate();
    }//시간 업데이트

    void SetTime(int _timerate) {
        _Time = Time.deltaTime - StartTime;
        Timevalue += _Time * _timerate * Time.timeScale;
        if (Timevalue / 60 >= 32) {
            Timevalue = 480;
            _Time = Time.time;
            DayTick += 1;
            UpdateDayflag = true;
        }
        Tens_Hour = (int)((Timevalue / 60) % 24) / 10;
        Units_Hour = (int)((Timevalue / 60) % 24) % 10;
        Tens_Minute = (int)(Timevalue % 60) / 10;
    }//날자, 시간 계산

    void UpdateDate() {
        if (UpdateDayflag) {
            CityScript.IsNext = true;
            US.FlagOnControl(DayTick);
            DayFlag = true;
        }
        UpdateDayflag = false;
        DayFlag = false;
    }//날자 업데이트

    //------------------- MainDisplayManager용 함수 -------------------
    public int GetDayTick() { return DayTick; }//변수전송

    //------------------- SubDisplayManager용 함수 -------------------
    public int GetTensHour() { return Tens_Hour; }    //<시간
    public int GetUnitsHour() { return Units_Hour; }  // 변수
    public int GetTensMinute() { return Tens_Minute; }// 전송 >
    


    void OnToggleFloatingPanel(bool Onflag, Vector3 pos)
    {
        if (Onflag)
        {
            CityFloatingPanel.SetActive(true);
            SetFloatingPanelPos(pos);
            SetFloatingPanelData(CityScript);
        }
        else { CityFloatingPanel.SetActive(false); }
    }

    void SetFloatingPanelPos(Vector3 Rate)
    {
        CityFloatingPanel.GetComponent<RectTransform>().anchoredPosition3D = Rate;
    }

    void SetFloatingPanelData(CCities Script) {
        CityName.text = Script.FloatingPanelData.GetPop().NAME;
        CityConfirm.text = Functions.GetFormat_Int(Script.FloatingPanelData.GetPop().CONFIRMED) + " 명";
        CityIncrease.text = "+ " + Functions.GetFormat_Int(Script.FloatingPanelData.GetPop("Today").CONFIRMED) + " 명";
    }

    void SetPanel(CCities Script)
    {
        if (Script.ClickCityData != "NoneData")
        {

            SetPanelPos(true);
        }
        else
        {
            SetPanelPos(false);
        }
    }

    void SetPanelPos(bool flag)
    {
        if (flag)
        {
            CityQuarantinePanel.GetComponent<RectTransform>(). anchoredPosition= new Vector3(-200, 0, 0);
        }
        else
        {
            CityQuarantinePanel.GetComponent<RectTransform>().anchoredPosition = new Vector3(-400, 0, 0);
        }
    }




    public void setFast() {
        Debug.Log("Fast");
        Timerate = 60;
    }
    public void setNormal() {
        Debug.Log("Normal");
        Timerate = 24;
    }


    //=========DebugLine
    void setDebugFastest()
    {
        Debug.Log("DebugFastest");
        Timerate = 76800;
    }
    void setDebugFast()
    {
        Debug.Log("DebugFast");
        Timerate = 4800;
    }
    void setDebugNormal()
    {
        Debug.Log("DebugNormal");
        Timerate = 2400;
    }
    void setDebugStop() {
        Debug.Log("DebugStop");
        Timerate = 0;
    }

    

}
