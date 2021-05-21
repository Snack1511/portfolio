using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using USERDEFINE;

public struct CitiesObj {
    GameObject CityObj;
    CCityInitialize CityInfo;
    string Tag;
    bool Highlighting;

    public CitiesObj(USERDEFINE.Popular Pop, GameObject _obj, bool _flag) {
        CityInfo = new CCityInitialize(Pop);
        Tag = CityInfo.GetPop().TAG;
        CityObj = _obj;
        Highlighting = _flag;
    }

    public bool CompareName(string _name) {
        if (Tag == _name)
        {
            return true;
        }
        else {
            return false;
        }
    }

    public void SetHighLight(bool flag) {
        Highlighting = flag;
    }

    public void ChangeColor()
    {
        if (Tag != "North")
        {
            if (Highlighting)
            {
                CityObj.GetComponent<MeshRenderer>().materials[0].color = new Color(1, 1, 0);
            }
            else
            {
                //CityObj.GetComponent<MeshRenderer>().materials[0].color = new Color(1, 1 - (CityInfo.RATE_DEAD * 0.01f), 1 - (CityInfo.RATE_DEAD * 0.01f));
                CityObj.GetComponent<MeshRenderer>().materials[0].color = new Color(1.0f, 1.0f - (CityInfo.RATE_DEAD * 0.01f), 1.0f - (CityInfo.RATE_DEAD * 0.01f));
            }
        }
    }
    public GameObject getObj()
    {
        return CityObj;
    }
    public string GetTag() { return Tag; }
    public string getName() { return GetPop().NAME; }
    public Popular GetPop() {
        return CityInfo.GetPop();
    }
    
    public CCityInitialize GetInfo() {
        return CityInfo;
    }
}

public class CCities : MonoBehaviour
{

    public string filename = string.Empty;
    int CitiesCount;
    CPlayercontrol Cpc;
    CitiesObj[] CityObj;
    Dictionary<string, int> NameToIndex;

    bool NextDayFlag;

    public int WorldRecoveryrate;
    public int WorldFatalityrate;

    public bool FloatingPanelflag;
    public Vector3 FloatingPanelpos;
    public CCityInitialize FloatingPanelData;

    public string ClickCityData { get; private set; }
    public bool Panelflag, DayChackflag;

    void Start()
    {
        List<Popular> TempPop = new List<Popular>();
        List<Dictionary<string, object>> TempDic = CSVParsing.Read(filename);
        for (int n = 0; n < TempDic.Count; n++)
        {
            Popular AddData = new Popular(
                TempDic[n]["TAG"].ToString(),
                TempDic[n]["NAME"].ToString(),
               int.Parse(TempDic[n]["TOTAL"].ToString()),
               int.Parse(TempDic[n]["EXAMINATION"].ToString()),
               int.Parse(TempDic[n]["QUARANTINE"].ToString()),
               int.Parse(TempDic[n]["CONFIRMED"].ToString()),
               int.Parse(TempDic[n]["CURED"].ToString()),
               int.Parse(TempDic[n]["DEAD"].ToString()));
            TempPop.Add(AddData);
        }

        CitiesCount = TempPop.Count;
        Cpc = GameObject.Find("PlayerControl").GetComponent<CPlayercontrol>();
        CityObj = new CitiesObj[CitiesCount];
        NameToIndex = new Dictionary<string, int>();
        for (int i = 0; i < CitiesCount; ++i)
        {
            CityObj[i] = new CitiesObj(TempPop[i], GameObject.Find(TempPop[i].TAG).gameObject,false);
            NameToIndex.Add(CityObj[i].GetTag(), i);
        }

        NextDayFlag = false;

        ClickCityData = "NoneData";

        DayChackflag = false;
    }

    // Update is called once per frame
    void Update()
    {
        ChangeColor(Cpc.OnMouseCity, Cpc.OnClickCity);
        GetCityFloat(Cpc);
        GetCityInfo(Cpc);
        UpdateCities(WorldRecoveryrate, WorldFatalityrate);
        
    }

    void ChangeColor(string name_OnMouse, string name_OnClick)
    {
        for (int i = 0; i < CitiesCount; ++i) {
            if (CityObj[i].CompareName(name_OnMouse)|| CityObj[i].CompareName(name_OnClick))
            {
                CityObj[i].SetHighLight(true);
            }
            else
            {
                CityObj[i].SetHighLight(false);
            }
            CityObj[i].ChangeColor();
        }
        
    }

    void UpdateCities(int _Recoveryrate = 0, int _Fatalityrate = 0)
    {
        if (NextDayFlag) {

            for (int i = 0; i < CitiesCount; ++i)
            {
                if (!CityObj[i].GetInfo().EXTICNT)
                {
                    CityObj[i].GetInfo().SetQuaranSave(DayChackflag);
                    CityObj[i].GetInfo().RateUpdate();
                    CityObj[i].GetInfo().PopUpdate(_Recoveryrate, _Fatalityrate);
                    CityObj[i].GetInfo().LocalEventLaunch();
                    CityObj[i].GetInfo().SetExtinctionflag();
                }
            }
        }
        NextDayFlag = false;
    }//하루 지날때 마다 동작
    //chack

    
    public void GetCityFloat(CPlayercontrol Script) {
        if (Script.TogglePanelfalg)
        {
            FloatingPanelflag = true;
            FloatingPanelpos = Script.PanelPos;
            FloatingPanelData = CityObj[NameToIndex[Script.OnMouseCity]].GetInfo();
        }
        else
        {
            FloatingPanelflag = false;
        }
    }//CityPanelInfo동작함수

    public void GetCityInfo(CPlayercontrol Script) {
        ClickCityData = Script.OnClickCity;
        Panelflag = Script.ClickFlag;
    }//사이드패널에 보낼 도시정보 불러오기

    public void SetWorldPlague(int _Recover, int _Fatal) {
        WorldRecoveryrate = _Recover;
        WorldFatalityrate = _Fatal;
    }//질병의 사망률, 완치율 설정

    public bool IsNext {
        get { return NextDayFlag; } set { NextDayFlag = value; }
    }//날 지나는 flag 활성 비활성 함수

    public CitiesObj GetObj(string name) {
        return CityObj[NameToIndex[name]];
    }//CityObj불러오기

    public bool GameOverFlag() {
        if (CityObj[0].GetInfo().EXTICNT&& CityObj[1].GetInfo().EXTICNT &&
            CityObj[2].GetInfo().EXTICNT && CityObj[3].GetInfo().EXTICNT &&
            CityObj[4].GetInfo().EXTICNT && CityObj[5].GetInfo().EXTICNT &&
            CityObj[6].GetInfo().EXTICNT && CityObj[7].GetInfo().EXTICNT &&
            CityObj[8].GetInfo().EXTICNT && CityObj[9].GetInfo().EXTICNT &&
            CityObj[10].GetInfo().EXTICNT && CityObj[11].GetInfo().EXTICNT &&
            CityObj[12].GetInfo().EXTICNT && CityObj[13].GetInfo().EXTICNT &&
            CityObj[14].GetInfo().EXTICNT && CityObj[15].GetInfo().EXTICNT &&
            CityObj[16].GetInfo().EXTICNT && CityObj[17].GetInfo().EXTICNT ) { return true; }
        else { return false; }
    }//게임오버플레그 동작함수 대충 총 인구수 0이면 true되게
    //chack
    
    //=========DebugLine
    

}
