using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using Custom;
//using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static GameManager GM;
    public bool GamePauseflg;
    //public static SelectData[] Selected = new SelectData[4];//플레이어 정보 담는 데이터
    RoomManager RoomMgr;
    public RoomManager ROOMMGR
    {
        get {
            
            return RoomMgr;
        }
        set
        {
            RoomMgr = value;
        }
    }
    public SelectData[] Selected
    {
        get { return ROOMMGR.Selected; }
    }
    public RoundManager ROUNDMGR
    {
        get { return RoomMgr.ROUNDMGR; }
        
    }
    public PlayerManager PMGR
    {
        get {
            Debug.Log(gameObject + ", " + RoomMgr);
            return RoomMgr.PMGR; }
    }
    

    //public bool GamePauseflg;//중지플레그
    //public bool Tutorialchkflg;//튜토리얼 확인 플레그
    //GameObject MenuPanel;
    //GameObject ScoreboardPanel;
    
    //List<PlayerInput> P_Input;
    // Start is called before the first frame update
    void InitGameMgr()
    {
        
        DontDestroyOnLoad(gameObject);
        if(GameObject.Find("GameMgr") != gameObject)
        {
            Destroy(gameObject);
        }
        
        GamePauseflg = true;
        /*if (!Selected[0].IsActive())
        {
            Selected[0] = new SelectData(null, 0, "Keyboard", InputSystem.devices[0], "Ch_roundFlask");
            Selected[1] = new SelectData(null, 1, "XInputControllerWindows", InputSystem.devices[2], "Ch_roundFlask");//디버깅용
        }*///Input for Debug -> 라운드매니저에서 받아야 할듯

        //GamePauseflg = true;
        //Tutorialchkflg = false;
        //MenuPanel = transform.GetChild(0).gameObject;

        /*RoomMgr = GenericFuncs.InitMgr<RoomManager>("RoomMgr").GetComponent<RoomManager>();
        RoomMgr.SetManager(Selected);*/

        /*for (int i = 0; i < ROUNDMGR.PMGR.PlayerCount; i++)
        {
            DontDestroyOnLoad(ROUNDMGR.PMGR.InputPlayers[i].gameObject);
        }*/
        ResetGameMgr();
    }
    private void Awake()
    {
        Debug.Log("GameMgr Awake");
        InitGameMgr();
        GM = this;
    }
    void Start()
    {
        //RoundMgr.RoundStart();
        //StartCoroutine("ResetValues", RoomMgr.ROUNDMGR);
        //이거도 룸메니저에서 돌리는거 생각해 봐야함

    }

    // Update is called once per frame
    void Update()
    {
        if(GM.GamePauseflg != GamePauseflg)
        {
            GamePauseflg = GM.GamePauseflg;
        }
        
    }
    /*void LateUpdate()
    {

        //RoundMgr.RoundEndCheck();
        if (GamePauseflg)
        {
            StartCoroutine("MenuOpen");
        }
    }*/

    public void CreateRoomMgr()
    {
        RoomMgr = GenericFuncs.InitMgr<RoomManager>("RoomMgr").GetComponent<RoomManager>();
        Debug.Log(gameObject + ", "+RoomMgr);
        //RoomMgr.SetManager(Selected);
    }

    void ResetGameMgr()
    {
        
        //RoomMgr.ResetRoomMgr();

    }
    
    
    /*IEnumerator ResetValues(RoundManager RMGR)
    {
        while (RMGR.Gamestartflg)
        {
            if (RMGR.bCallResetGameMgr)
            {
                ResetGameMgr();
            }
            else yield return new WaitForEndOfFrame();
        }
    }*///RoundMgr의 bCallResetGameMgr변수를 받아서 원하는 타이밍에 변수를 초기화시키는 함수
    
    /*IEnumerator MenuOpen() {

        MenuPanel.SetActive(true);
        Time.timeScale = 0f;
        while (ROUNDMGR.PMGR.InputNextButton() && GamePauseflg)
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
    */
}