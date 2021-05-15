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
    
    bool bRoundCheckflg = false;
    int Leaveplayer;
    List<Player_Cal> Players = new List<Player_Cal>();
    Vector3[] pos = {
        new Vector3(-Dist, 3, 0), new Vector3(Dist, 3, 0), new Vector3(0, 3, -Dist), new Vector3(0, 3, Dist)
    };
    GameObject Winner;
    GameObject MenuPanel;
    PlayerInput[] InputPlayers;
    
    public const float Dist = 20;
    public bool Gamestartflg;
    public bool GamePauseflg;
    public bool Tutorialchkflg;
    public int RoundNum = 2;
    public static GameManager GM;
    public static SelectData[] Selected = new SelectData[4];
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
        RoundEndCheck();
    }
    void LateUpdate()
    {
        if (GamePauseflg)
        {
            StartCoroutine("MenuOpen");
        }
    }

    /*void GameManagerInit() {
        
    }*/
    void InitGameMgr()
    {
        
        Selected[0] = new SelectData(null, 0, "Keyboard", InputSystem.devices[0], "Ch_roundFlask");
        Selected[1] = new SelectData(null, 1, "XInputControllerWindows", InputSystem.devices[2], "Ch_roundFlask");//디버깅용

        Gamestartflg = true;
        GamePauseflg = true;
        Tutorialchkflg = false;
        InputPlayers = new PlayerInput[4];
        MenuPanel = transform.GetChild(0).gameObject;
        for (int i = 0; i < Selected.Length; i++)
        {
          if (Selected[i].IsActive())
            {
                InputPlayers[i] = PlayerInput.Instantiate(Resources.Load<GameObject>("Prefabs/PlayerObj"), Selected[i].GetIndex(), GetScheme(Selected[i].GetDVName()), -1, Selected[i].GetInputDv());
                InputPlayers[i].GetComponent<PlayerSet>().ModelName = Selected[i].GetName();
                InputPlayers[i].GetComponent<PlayerSet>().ColorNum = Selected[i].GetIndex();
                DontDestroyOnLoad(InputPlayers[i].gameObject);

            }
        }
        for (int i = 0; i < GameObject.FindGameObjectsWithTag("Player").Length; i++)
        {
            Players.Add(GameObject.FindGameObjectsWithTag("Player")[i].GetComponent<Player_Cal>());

        }
        ResetGameMgr();
    }
    void ResetGameMgr()
    {
        MenuPanel.SetActive(false);

        for (int i = 0; i < Players.Count; i++)
        {
            Debug.Log("d");
            Players[i].transform.position = pos[i];
            Players[i].GetComponent<PlayerSet>().ResetData();
            Players[i].gameObject.SetActive(true);
        }
        Leaveplayer = Players.Count;
        RoundEndCheck();
        bRoundCheckflg = false;
        
    }
    public void SetLeavePlayer()
    {
        Leaveplayer--;
    }
    void RoundEndCheck() {
        //Leaveplayer = Players.Count;
        if (Leaveplayer <= 1)
        {
            bRoundCheckflg = true;
        }
        else bRoundCheckflg = false;
    }

    IEnumerator RoundChange() {
        while (Gamestartflg)
        {
            if (bRoundCheckflg)
            {
                //Random.Range(0, 5);
                //RoundNum--;
                Debug.Log("RoundChange");
                ChangeMap();
                ResetGameMgr();
                //InitGameMgr();
            }
            else
            {
                yield return new WaitForEndOfFrame();
            }
        }
    }

    void GameEndCheck() {
        if(RoundNum <= 0)
        {
            Gamestartflg = false;
        }   
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
        while (Players[0].GetComponent<PlayerInput>().actions["Dash"].phase == InputActionPhase.Waiting && GamePauseflg)
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
        DontDestroyOnLoad(gameObject);
        SceneManager.LoadScene("Map_Forest");
        
    }
    
}