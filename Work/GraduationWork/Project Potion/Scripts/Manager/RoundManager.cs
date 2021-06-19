using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using Custom;
public class RoundManager:MonoBehaviour
{
    bool bRoundCheckflg = false;//라운드 전환 활성화 변수
    bool[] bMapChack;//맵 방문 정보 변수
    bool bScoreboardCheckflg = false;//스코어보드 확인 변수
    GameObject ScoreboardPanel;//스코어 보드 오브젝트 변수
    PlayerManager PlayerMgr;//플레이어매니저 변수

    public int RoundNum;//라운드 번호
    public bool Gamestartflg;//시작 플레그
    public bool bCallResetGameMgr;//GameMgr에 변수 타이밍 알림 변수
    public PlayerManager PMGR
    {
        get { return PlayerMgr; }
    }//PlayerMgr읽기용 프로퍼티
    public bool ReadRoundCheck
    {
        get { return bRoundCheckflg; }
    }//RoundCheck변수 읽기용 프로퍼티
    public bool ReadScoreboardCheck
    {
        get { return bScoreboardCheckflg; }
    }//스코어보드확인변수 읽기용 프로퍼티

    // Start is called before the first frame update

    public void RoundStart()
    {
        StartCoroutine("RoundChange");
        /*
         모노비해비어를 이용할 경우 필수적으로 게임 오브젝트에 할당한 후 코루틴을 동작시켜야 한다.
         쓰레딩 클래스를 이용해서 코루틴을 대체하려 해봤으나 유니티 엔진이 싱글쓰레드를 상정하고 만들었다는 것을 간과했다.
         결론 : 스레딩 클래스는 서버에서 데이터 호출및 변경시에나 사용하는 것이 좋다.
         */
    }//GameMgr의 Start함수에서 동작 -> 코루틴 호출용
    
    public void SetManager(SelectData[] Selected, GameObject Scoreboard, int n)
    {
        PlayerMgr = new PlayerManager(Selected);
        ScoreboardPanel = Scoreboard;
        RoundNum = n;
        Gamestartflg = true;
        ResetRoundMgr();
    }//생성자를 대신해 초기화 시키는 함수


    public static GameObject InitMgr(SelectData[] Selected, GameObject Scoreboard, int n = 0)
    {
        GameObject Mgrobj = GameObject.Find("RoundMgr");
        if (Mgrobj == null)
        {
            Mgrobj = new GameObject();
            Mgrobj.name = "RoundMgr";
            Mgrobj.AddComponent<RoundManager>();
            Mgrobj.GetComponent<RoundManager>().SetManager(Selected, Scoreboard, n);
            DontDestroyOnLoad(Mgrobj);
        }
        return Mgrobj;
    }//GameMgr에서 변수 생성시 동시에 RoundMgr객체를 생성하도록 하는 함수

    public void ResetRoundMgr()
    {
        bMapChack = new bool[5];
        bRoundCheckflg = false;
        bScoreboardCheckflg = false;
        PlayerMgr.ResetPlayerMgr();
        bCallResetGameMgr = false;
    }//GameMgr의 ResetGameMgr에서 동작하는 함수 -> 라운드 진행시 변수 초기화용
    public void RoundEndCheck()
    {
        //Leaveplayer = Players.Count;
        if (PlayerMgr.IsLeaveBiggerThanPlayer())//플레이어가 1명이하로 남을 경우 동작하게 설정
        {
            if (!bRoundCheckflg)
            {
                PlayerMgr.GivePointToPlayer(RoundNum);
            }
            bRoundCheckflg = true;

            GameEndCheck();
        }
        else bRoundCheckflg = false;
    }// 라운드 종료를 확인하는 함수
    void ScoreboardCheck()
    {
        if (PlayerMgr.InputAnyButton())
        {
            if (ScoreboardPanel.transform.GetChild(1).GetComponent<ScoreboardScript>().bPlayEnd)
            {
                bScoreboardCheckflg = true;
            }
            else
            {
                Debug.Log("Click");
                ScoreboardPanel.transform.GetChild(1).GetComponent<ScoreboardScript>().bPlayEnd = true;
            }
        }

    }//버튼 입력시 스코어 보드 비활성화

    IEnumerator WaitScoreBoard()
    {
        Debug.Log("TimeCheck");
        yield return new WaitForSecondsRealtime(5.0f);
        if (ScoreboardPanel.activeSelf && !bScoreboardCheckflg)
        {

            Debug.Log("TimeOut");
            bScoreboardCheckflg = true;
        }

    }//일정시간후 스코어보드 비활성화

    IEnumerator RoundChange()
    {
        while (Gamestartflg)
        {
            if (bRoundCheckflg)
            {
                if (!bScoreboardCheckflg && SceneManager.GetActiveScene().name != "TutorialScene")
                {

                    Debug.Log("Score");
                    if (!ScoreboardPanel.activeSelf) ScoreboardPanel.SetActive(true);
                    bScoreboardCheckflg = true;
                    ScoreboardCheck();
                    StartCoroutine("WaitScoreBoard");
                }
                else
                {
                    if (ScoreboardPanel.activeSelf) ScoreboardPanel.SetActive(false);
                    Debug.Log("RoundChange");
                    ChangeMap();
                    bCallResetGameMgr = true;
                }
            }
            yield return new WaitForEndOfFrame();
        }
        //씬전환 - 엔딩씬
        Debug.Log("Winner is " + PlayerMgr.Winner.name);
    }//라운드 전환 함수
     //-> 코루틴을 이용해 라운드가 종료되면 튜토리얼 맵이 아닐경우 스코어보드를 활성화해 점수 상황을 표시하고
     //라운드를 전환하도록 설정
    void GameEndCheck()
    {
        Gamestartflg = PlayerMgr.GetWinner();

    }//승자 결정시 Gamestartflg를 false로 받도록 설정
    void ChangeMap(int n = 0)
    {
        int MapNum = Random.Range(0, 5);
        if (TravelAllMap()) RefreshMap();
        while (bMapChack[MapNum]) { MapNum = Random.Range(0, 5); }
        Debug.Log(MapNum);
        bMapChack[MapNum] = true;
        RoundNum++;
        
        SceneManager.LoadScene("Map_Forest");//디버그용

    }//맵 전환 함수 -> 라운드 종료시 호출
    bool TravelAllMap()
    {
        for (int i = 0; i < 5; i++)
        {
            if (!bMapChack[i]) return false;
        }
        return true;
    }//ChangeMap에서 모든 맵을 한번씩 다 돌아본 경우 true 호출
    void RefreshMap()
    {
        for (int i = 0; i < 5; i++)
        {
            bMapChack[i] = false;
        }
    }//TravelAllMap에서 true 반환 시 방문정보를 모두 리셋하는 함수
}
