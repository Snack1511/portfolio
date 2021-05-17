using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
//using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Utilities;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.SceneManagement;



public class GameManager : MonoBehaviour
{
    bool[] bMapChack;
    bool bRoundCheckflg = false;
    bool bScoreboardCheckflg = false;
    Vector3[] pos = {
        new Vector3(-Dist, 3, 0), new Vector3(Dist, 3, 0), new Vector3(0, 3, -Dist), new Vector3(0, 3, Dist)
    };
    GameObject Winner;
    GameObject MenuPanel;
    GameObject ScoreboardPanel;
    PlayerInput[] InputPlayers;
    PlayerSet[] PlayerDatas;
    List<Player_Cal> PlayersCalculates = new List<Player_Cal>();
    
    public const float Dist = 20;
    public int Leaveplayer;
    public int RoundNum;
    public bool Gamestartflg;
    public bool GamePauseflg;
    public bool Tutorialchkflg;
    public static GameManager GM;
    public static SelectData[] Selected = new SelectData[4];
    public int PlayerCount = 0;
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
        Selected[0] = new SelectData(null, 0, "Keyboard", InputSystem.devices[0], "Ch_roundFlask");
        Selected[1] = new SelectData(null, 1, "XInputControllerWindows", InputSystem.devices[2], "Ch_roundFlask");//디버깅용

        Gamestartflg = true;
        GamePauseflg = true;
        Tutorialchkflg = false;
        InputPlayers = new PlayerInput[4];
        PlayerDatas = new PlayerSet[4];
        MenuPanel = transform.GetChild(0).gameObject;
        ScoreboardPanel = transform.GetChild(1).gameObject;
        for (int i = 0; i < Selected.Length; i++)
        {
          if (Selected[i].IsActive())
            {
                InputPlayers[i] = PlayerInput.Instantiate(Resources.Load<GameObject>("Prefabs/PlayerObj"), Selected[i].GetIndex(), GetScheme(Selected[i].GetDVName()), -1, Selected[i].GetInputDv());
                InputPlayers[i].GetComponent<PlayerSet>().ModelName = Selected[i].GetName();
                InputPlayers[i].GetComponent<PlayerSet>().ColorNum = Selected[i].GetIndex();
                PlayerDatas[i] = InputPlayers[i].GetComponent<PlayerSet>();
                PlayersCalculates.Add(InputPlayers[i].GetComponent<Player_Cal>());
                DontDestroyOnLoad(InputPlayers[i].gameObject);
                PlayerCount++;

            }
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

        for (int i = 0; i < PlayerCount; i++)
        {
            //Debug.Log(PlayersCalculates[i]);
            if (PlayersCalculates[i] != null)
            {
                PlayersCalculates[i].gameObject.transform.position = pos[i];
                PlayersCalculates[i].GetComponent<PlayerSet>().ResetData();
                PlayersCalculates[i].gameObject.SetActive(true);
            }
        }
        Leaveplayer = 0;
        //RoundEndCheck();
        bRoundCheckflg = false;
        
    }
    public int SetLeavePlayer()
    {
        Leaveplayer++;
        return PlayerCount - (Leaveplayer - 1);

    }
    void RoundEndCheck() {
        //Leaveplayer = Players.Count;
        if (Leaveplayer >= PlayerCount - 1)
        {
            if (!bRoundCheckflg)
            {
                for (int i = 0; i < PlayerCount; i++)
                {
                    if (PlayersCalculates[i].gameObject.activeSelf)
                    {
                        PlayerDatas[i].GetPlayerData().POINT = 1;
                        PlayerDatas[i].GetPlayerData().CalTotalPoint(RoundNum);
                    }
                }
            }
            bRoundCheckflg = true;
            //OpenScore
            
            GameEndCheck();
        }
        else bRoundCheckflg = false;
    }
    
    void ScoreboardCheck()
    {
        if(Gamepad.current.IsPressed() || Keyboard.current.IsPressed())
        {
            Debug.Log("Click");
            bScoreboardCheckflg = true;
        }
        
    }

    IEnumerator WaitScoreBoard()
    {
        Debug.Log("TimeCheck");
        yield return new WaitForSecondsRealtime(5.0f);
        if (!bScoreboardCheckflg)
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
                if (!bScoreboardCheckflg)
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
        Debug.Log("Winner is " + Winner.name);
    }

    void GameEndCheck() {
        Gamestartflg = GetWinner();
        
    }
    bool GetWinner()
    {
        for(int i = 0; i < PlayerCount; i++)
        {
            if(/*PlayerDatas[i] != null && */PlayerDatas[i].GetPlayerData().POINT >= 15)
            {
                Winner = PlayerDatas[i].gameObject;
                return false;
            }
        }
        return true;
    }
    public string GetScheme(string device)
    {
        if (device == "XInputControllerWindows")
        {
            return "Xbox";
        }
        else if (device == "Keyboard")
        {
            return "Keyboard";
        }
        else if (device == "DualShock4GamepadHID")
        {
            return "PS4";
        }
        else
        {
            return "";
        }
    }

    IEnumerator MenuOpen() {

        MenuPanel.SetActive(true);
        Time.timeScale = 0f;
        while (InputPlayers[0].actions["Dash"].phase == InputActionPhase.Waiting && GamePauseflg)
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
        
        /*if (Players[0].GetComponent<Control>() != null)
        {
            
        }*/
        
    }

    void ChangeMap(int n = 0)
    {
        int MapNum = Random.Range(0, 5);
        if (TravelAllMap()) RefreshMap();
        while (bMapChack[MapNum]) { MapNum = Random.Range(0, 5); }
        Debug.Log(MapNum);
        bMapChack[MapNum] = true;
        RoundNum++;
        //DontDestroyOnLoad(gameObject);
        //SceneManager.LoadScene("Map_Forest");

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