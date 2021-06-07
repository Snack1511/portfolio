using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static GameManager GM;
    public static SelectData[] Selected = new SelectData[4];//플레이어 정보 담는 데이터
    PlayerManager PlayerMgr;
    public PlayerManager PMGR
    {
        get { return PlayerMgr; }
    }
    /*public const float Dist = 20;//플레이어 스폰 위치정보
    public int Leaveplayer;//남은 플레이어 수
    public int PlayerCount = 0;//전체 플레이어 수
    PlayerSet[] PlayerDatas;
    public PlayerSet[] ReadPlyerDatas
    {
        get { return PlayerDatas; }
    }//
    Vector3[] pos = {
        new Vector3(-Dist, 3, 0), new Vector3(Dist, 3, 0), new Vector3(0, 3, -Dist), new Vector3(0, 3, Dist)
    };
    PlayerInput[] InputPlayers;
    List<Player_Cal> PlayersCalculates = new List<Player_Cal>();
    GameObject Winner;
    */

    public int RoundNum;//라운드 번호
    public bool ReadRoundCheck
    {
        get { return bRoundCheckflg; }
    }
    public bool ReadScoreboardCheck
    {
        get { return bScoreboardCheckflg; }
    }
    bool bRoundCheckflg = false;
    bool bScoreboardCheckflg = false;
    bool[] bMapChack;


    public bool Gamestartflg;//시작 플레그
    public bool GamePauseflg;//중지플레그
    public bool Tutorialchkflg;//튜토리얼 확인 플레그
    GameObject MenuPanel;
    GameObject ScoreboardPanel;
    
    //List<PlayerInput> P_Input;
    // Start is called before the first frame update
    private void Awake()
    {
        GM = this;
        InitGameMgr();
        //GameManagerInit();
    }
    void Start()
    {

        //PlayerInput.Instantiate(Resources.Load<GameObject>("Prefabs/PlayerObj"));

        //InputSystem.GetDevice();


        //*****************************************************************************************

        StartCoroutine("RoundChange");

        //foreach(GameObject a in )
        //Players.Add
        
    }

    // Update is called once per frame
    void Update()
    {
        
        /*if (RoundEndCheck()) {
            GameEndCheck();
            RoundChange();
        }*/
    }
    void LateUpdate()
    {

        RoundEndCheck();
        if (GamePauseflg)
        {
            StartCoroutine("MenuOpen");
        }
    }

    /*void GameManagerInit() {
        
    }*/
    void InitGameMgr()
    {
        RoundNum = 0;
        bMapChack = new bool[5];
        if (!Selected[0].IsActive())
        {
            Selected[0] = new SelectData(null, 0, "Keyboard", InputSystem.devices[0], "Ch_roundFlask");
            Selected[1] = new SelectData(null, 1, "XInputControllerWindows", InputSystem.devices[2], "Ch_roundFlask");//디버깅용
        }
        Gamestartflg = true;
        GamePauseflg = true;
        Tutorialchkflg = false;
        
        MenuPanel = transform.GetChild(0).gameObject;
        ScoreboardPanel = transform.GetChild(1).gameObject;
        PlayerMgr = new PlayerManager(Selected);
        Debug.Log(PlayerMgr.InputPlayers[0].gameObject);
        for (int i = 0; i < PlayerMgr.PlayerCount; i++)
        {
            DontDestroyOnLoad(PlayerMgr.InputPlayers[i].gameObject);
        }
        

        /*for (int i = 0; i < GameObject.FindGameObjectsWithTag("Player").Length; i++)
        {
            //PlayersCalculates.Add(GameObject.FindGameObjectsWithTag("Player")[i].GetComponent<Player_Cal>());
            PlayersCalculates[i] = GameObject.FindGameObjectsWithTag("Player")[i].GetComponent<Player_Cal>();
        }*/
        ResetGameMgr();
    }
    void ResetGameMgr()
    {
        MenuPanel.SetActive(false);

        /*for (int i = 0; i < PlayerCount; i++)
        {
            //Debug.Log(PlayersCalculates[i]);
            if (PlayersCalculates[i] != null)
            {
                PlayersCalculates[i].gameObject.transform.position = pos[i];
                PlayersCalculates[i].GetComponent<PlayerSet>().ResetData();
                PlayersCalculates[i].gameObject.SetActive(true);
            }
        }
        Leaveplayer = 0;*/
        //RoundEndCheck();
        PlayerMgr.ResetPlayerMgr();
        bRoundCheckflg = false;
        bScoreboardCheckflg = false;


    }
    /*public int SetLeavePlayer()
    {
        Leaveplayer++;
        return PlayerCount - (Leaveplayer - 1);
    }*/
    void RoundEndCheck() {
        //Leaveplayer = Players.Count;
        if (PlayerMgr.IsLeaveBiggerThanPlayer())
        {
            Debug.Log("Hello");
            if (!bRoundCheckflg)
            {
                PlayerMgr.GivePointToPlayer(RoundNum);
            }
            bRoundCheckflg = true;
            
            GameEndCheck();
        }
        else bRoundCheckflg = false;
    }
    
    void ScoreboardCheck()
    {
        if((Gamepad.current.IsPressed()&&Gamepad.current.wasUpdatedThisFrame)||(Keyboard.current.IsPressed()&&Keyboard.current.wasUpdatedThisFrame))
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
        
    }

    IEnumerator WaitScoreBoard()
    {
        Debug.Log("TimeCheck");
        yield return new WaitForSecondsRealtime(5.0f);
        if (ScoreboardPanel.activeSelf && !bScoreboardCheckflg)
        {
            
            Debug.Log("TimeOut");
            bScoreboardCheckflg = true;
        }
        
    }

    IEnumerator RoundChange() {
        while (Gamestartflg)
        {
            if (bRoundCheckflg)
            {
                //Random.Range(0, 5);
                //RoundNum--;
                if (!bScoreboardCheckflg && SceneManager.GetActiveScene().name != "TutorialScene")
                {
                    
                    Debug.Log("Score");
                    if (!ScoreboardPanel.activeSelf) ScoreboardPanel.SetActive(true);
                    //bScoreboardCheckflg = true;
                    ScoreboardCheck();
                    StartCoroutine("WaitScoreBoard");
                    yield return new WaitForEndOfFrame();
                }
                else
                {
                    if (ScoreboardPanel.activeSelf) ScoreboardPanel.SetActive(false);
                    Debug.Log("RoundChange");
                    ChangeMap();
                    ResetGameMgr();
                }
                //InitGameMgr();
            }
            else
            {
                yield return new WaitForEndOfFrame();
            }
        }
        //씬전환 - 엔딩씬
        Debug.Log("Winner is " + PlayerMgr.Winner.name);
    }

    void GameEndCheck() {
        Gamestartflg = PlayerMgr.GetWinner();
        
    }
    /*bool GetWinner()
    {
        for(int i = 0; i < PlayerCount; i++)
        {
            if(PlayerDatas[i].GetPlayerData().POINT >= 15)
            {
                Winner = PlayerDatas[i].gameObject;
                return false;
            }
        }
        return true;
    }*/
    

    IEnumerator MenuOpen() {

        MenuPanel.SetActive(true);
        Time.timeScale = 0f;
        while (PlayerMgr.InputNextButton() && GamePauseflg)
        {
            yield return new WaitForEndOfFrame();
        }
        GamePauseflg = false;
        if (!GamePauseflg)
        {
            if (!Tutorialchkflg) Tutorialchkflg = true;
            Time.timeScale = 1f;
            MenuPanel.SetActive(false);
        }
        
        
    }
    /*bool InputNextButton(PlayerInput pInput)
    {
        if(pInput.currentControlScheme == "Keyboard")
        {
            if(InputPlayers[0].actions["Attack"].phase == InputActionPhase.Waiting)
            {
                return true;
            }
        }
        else
        {
            if(InputPlayers[0].actions["Dash"].phase == InputActionPhase.Waiting)
            {
                return true;
            }
        }
        return false;
    }*/
    void ChangeMap(int n = 0)
    {
        int MapNum = Random.Range(0, 5);
        if (TravelAllMap()) RefreshMap();
        while (bMapChack[MapNum]) { MapNum = Random.Range(0, 5); }
        Debug.Log(MapNum);
        bMapChack[MapNum] = true;
        RoundNum++;
        DontDestroyOnLoad(gameObject);
        SceneManager.LoadScene("Map_Forest");

    }
    bool TravelAllMap()
    {
        for(int i = 0; i < 5; i++)
        {
            if (!bMapChack[i]) return false;
        }
        return true;
    }
    void RefreshMap()
    {
        for (int i = 0; i < 5; i++)
        {
            bMapChack[i] = false;
        }
    }
}