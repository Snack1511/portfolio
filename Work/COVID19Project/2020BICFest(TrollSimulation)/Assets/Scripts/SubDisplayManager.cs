using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using USERDEFINE;

public class SubDisplayManager : MonoBehaviour
{
    //------------------- 기본 변수 ------------------- >> 1
    CGameManager CGM;
    CCities CityScript;

    GameObject MainTabObj;
    GameObject BoardTabObj;

    Text Clock;

    GameObject[] Views;
    Toggle[] Toggles;
    int BeforeIdx;
    //------------------- NewsTab 컨트롤 시 필요한 변수 ------------------- >> 2
    GameObject Articles;
    GameObject ArticleContents;
    Text[] buttonsTitles;
    Dictionary<string, int> ButtonIdx;
    Scrollbar scroll;
    ArticleSelect arti;
    Text ArticleTitle;
    Text ArticleContent;
    Text Attribute;

    //------------------- StatisticsTab 컨트롤 시 필요한 변수 ------------------- >> 3
    Text[] InfoData = new Text[14];

    void Start()
    {
        // >> 1
        CGM = GameObject.Find("GameManager").GetComponent<CGameManager>();
        CityScript = GameObject.Find("Cities").GetComponent<CCities>();

        MainTabObj = GameObject.Find("MainTab");
        BoardTabObj = GameObject.Find("BoardTab");

        Clock = GameObject.Find("Clock").GetComponent<Text>();

        Views = new GameObject[GameObject.Find("Views").GetComponentInChildren<Transform>().childCount];
        for (int i = 0; i <Views.Length; i++) {
            Views[i] = GameObject.Find("Views").GetComponentInChildren<Transform>().GetChild(i).gameObject;
        }
        Toggles = new Toggle[GameObject.Find("Toggles").GetComponentInChildren<Transform>().childCount];
        for (int i = 0; i < Toggles.Length; i++)
        {
            Toggles[i] = GameObject.Find("Toggles").GetComponentInChildren<Transform>().GetChild(i).gameObject.GetComponent<Toggle>();
        }
        BeforeIdx = 0;

        // >> 2
        Articles = GameObject.Find("Articles");
        ArticleContents = GameObject.Find("ArticleContents");
        buttonsTitles = new Text[Articles.GetComponentInChildren<Transform>().childCount];
        ButtonIdx = new Dictionary<string, int>();
        for (int i = 0; i < buttonsTitles.Length; i++)
        {
            buttonsTitles[i] = GameObject.Find("Article" + i.ToString()).GetComponent<Transform>().GetChild(0).GetComponent<Text>();
            buttonsTitles[i].name = "Title" + i.ToString();
            ButtonIdx.Add(Articles.GetComponentInChildren<Transform>().GetChild(i).name, i);
        }
        scroll = GameObject.Find("Scrollbar Vertical").GetComponent<Scrollbar>();
        arti = GameObject.Find("UserSelectableManager").GetComponent<UserSelectable>().ChosenArticle;
        ArticleTitle = GameObject.Find("ArticleTitle").GetComponent<Text>();
        ArticleContent = GameObject.Find("ArticleContent").GetComponent<Text>();
        Attribute = GameObject.Find("Attribute").GetComponent<Text>();


        // >> 3
        InfoData = new Text[GameObject.Find("Info_Data").GetComponentInChildren<Transform>().childCount];
        for (int i = 0; i < GameObject.Find("Info_Data").GetComponentInChildren<Transform>().childCount; i++)
        {
            InfoData[i] = GameObject.Find("Info_Data").GetComponentInChildren<Transform>().GetChild(i).GetComponent<Text>();
        }

        UIInit();
    }
    
    void Update()
    {
        PrintTime(CGM.GetTensHour(), CGM.GetUnitsHour(), CGM.GetTensMinute());
        UpdateDay();
        SetInfoData(CityScript.ClickCityData);
    }

    //------------------- 내부사용 함수 -------------------
    void PrintTime(int Tens_hour, int Units_hour, int Tens_Minute)
    {
        Clock.text = Tens_hour.ToString() + Units_hour.ToString() + " : "
            + Tens_Minute.ToString() + "0";
    }//시간 출력 함수

    void DisplayOnOffControl()
    {
        MainTabObj.SetActive(!MainTabObj.activeSelf);
        BoardTabObj.SetActive(!BoardTabObj.activeSelf);
    }//디스플레이 OnOff 컨트롤 함수
    
    void ChangeViews(ref int BeforeIdx, int CurrentIdx)
    {
        Toggles[BeforeIdx].isOn = false;
        Views[BeforeIdx].SetActive(false);
        Views[CurrentIdx].SetActive(true);
        BeforeIdx = CurrentIdx;
    }//View OnOff 컨트롤 함수

    void UpdateDay()
    {
        if (CGM.DayFlag)
        {
            ArticleTitlePrint();
        }
    }

    void Article_OnControl(int n)
    {
        ArticleContents.SetActive(!ArticleContents.activeSelf);
        ClickArticle(n);
        Articles.SetActive(!Articles.activeSelf);
        scroll.value = 1.0f;
    }//Article On 컨트롤 함수
    void Article_OffControl()
    {
        Articles.SetActive(!Articles.activeSelf);
        ArticleContents.SetActive(!ArticleContents.activeSelf);
        scroll.value = 1.0f;
    }//Article Off 컨트롤 함수

    void ClickArticle(int n)
    {
        
        ArticleContentPrint(arti.AD[n]);
        if (arti.AD[n].Chackflag) {
            //설정적용 함수 삽입
            Debug.Log("SetAttribute");
            arti.AD[n].ChangeChackflag();
        }
    }//ArticleContent의 string 데이터 변경 함수

    //------------------- UI 세팅 -------------------
    public void UIInit()
    {
        ArticleTitlePrint();
        ArticleInit();
        ToggleInit();
        ViewInit();
        BoardInit();
    }//UI 초기 셋팅
    public void BoardInit()
    {
        MainTabObj.SetActive(true);
        BoardTabObj.SetActive(false);
    }//Board 초기 셋팅
    public void ViewInit()
    {
        Views[0].SetActive(true);
        Views[1].SetActive(false);
        BeforeIdx = 0;
    }//View 초기 셋팅
    public void ToggleInit() {
        Toggles[0].isOn = true;
        Toggles[1].isOn = false;
    }//Toggles 초기 셋팅 
    public void ArticleInit()
    {
        scroll.value = 1.0f;
        Articles.SetActive(true);
        ArticleContents.SetActive(false);
    }//Article 초기 셋팅

    //------------------- 기본 버튼 컨트롤 -------------------
    public void Click_ChackVirusPannel() {
        DisplayOnOffControl();
    }//바이러스 현황 버튼 클릭시

    public void Toggle_NewsTab() {
        ChangeViews(ref BeforeIdx, 0);
    }//뉴스탭 클릭시

    public void Toggle_StatisticsTab() {
        ChangeViews(ref BeforeIdx, 1);
    }//통계탭 클릭시

    public void Click_BackButton() {
        DisplayOnOffControl();
        //UIInit();
    }//뒤로가기 버튼 클릭시

    //------------------- NewsTab의 String 데이터 출력 -------------------
    void ArticleTitlePrint()
    {
        for (int i = 0; i < buttonsTitles.Length; i++) {
            buttonsTitles[i].text = arti.AD[i].Title;
        }
    }

    void ArticleContentPrint(ArticleData a)
    {
        ArticleTitle.text = a.Title;
        ArticleContent.text = a.Content;
        Attribute.text = a.Attribute;
    }//ArticleContent string데이터 출력


    //------------------- NewsTab의 버튼 컨트롤 -------------------

    
    public void Article_Click()
    {
        //Debug.Log(EventSystem.current.currentSelectedGameObject.name);
        Article_OnControl(ButtonIdx[EventSystem.current.currentSelectedGameObject.name]);
    }//기사 클릭시
    
    public void Article_BackButton()
    {
        Article_OffControl();
    }//기사 뒤로가기 버튼 클릭시

    //------------------- StatisticsTab의 String 데이터 출력 -------------------

    void SetInfoData(string name)
    {
        if (name == "NoneData")
        {
            name = "Seoul";
        }
        InfoData[0].text = CityScript.GetObj(name).GetPop().NAME.ToString();
        InfoData[1].text = Functions.GetFormat_Int(CityScript.GetObj(name).GetPop().TOTAL) + "명";
        InfoData[2].text = Functions.GetFormat_Int(CityScript.GetObj(name).GetInfo().GetPop("Today").EXAMINATION) + "명";
        InfoData[3].text = Functions.GetFormat_Int(CityScript.GetObj(name).GetPop().QUARANTINE) + "명";
        InfoData[4].text = Functions.GetFormat_Int(CityScript.GetObj(name).GetPop().CONFIRMED) + "명";
        InfoData[5].text = Functions.GetFormat_Int(CityScript.GetObj(name).GetInfo().GetPop("Today").CURED) + "명";
        InfoData[6].text = Functions.GetFormat_Int(CityScript.GetObj(name).GetPop().DEAD) + "명";
        InfoData[7].text = Functions.GetFormat_N2(CityScript.GetObj(name).GetInfo().RATE_TROLL) + "%";
        InfoData[8].text = Functions.GetFormat_N2(CityScript.GetObj(name).GetInfo().RATE_CARRY) + "%";
        InfoData[9].text = Functions.GetFormat_N2(CityScript.GetObj(name).GetInfo().RATE_EXAM) + "%";
        InfoData[10].text = Functions.GetFormat_N2(CityScript.GetObj(name).GetInfo().RATE_CONFIRM) + "%";
        InfoData[11].text = Functions.GetFormat_N2(CityScript.GetObj(name).GetInfo().RATE_DEAD) + "%";
        InfoData[12].text = Functions.GetFormat_N2(CityScript.GetObj(name).GetInfo().RATE_CURED) + "%";
        InfoData[13].text = Functions.GetFormat_N2(CityScript.GetObj(name).GetInfo().RATE_QUARANTINE) + "%";
    }//통계자료 출력 함수

    //------------------- Debug용 함수 -------------------
}
