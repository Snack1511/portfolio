using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
//using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static GameManager GM;
    public static SelectData[] Selected = new SelectData[4];//플레이어 정보 담는 데이터
    RoundManager RoundMgr;
    public RoundManager ROUNDMGR
    {
        get { return RoundMgr; }
    }
    public PlayerManager PMGR
    {
        get { return ROUNDMGR.PMGR; }
    }
    

    public bool GamePauseflg;//중지플레그
    public bool Tutorialchkflg;//튜토리얼 확인 플레그
    GameObject MenuPanel;
    //GameObject ScoreboardPanel;
    
    //List<PlayerInput> P_Input;
    // Start is called before the first frame update
    void InitGameMgr()
    {
        
        if (!Selected[0].IsActive())
        {
            Selected[0] = new SelectData(null, 0, "Keyboard", InputSystem.devices[0], "Ch_roundFlask");
            Selected[1] = new SelectData(null, 1, "XInputControllerWindows", InputSystem.devices[2], "Ch_roundFlask");//디버깅용
        }
        GamePauseflg = true;
        Tutorialchkflg = false;
        
        MenuPanel = transform.GetChild(0).gameObject;
        RoundMgr = RoundManager.InitRoundMgr(Selected, transform.GetChild(1).gameObject).GetComponent<RoundManager>();//new RoundManager(Selected, transform.GetChild(1).gameObject);
        for (int i = 0; i < RoundMgr.PMGR.PlayerCount; i++)
        {
            DontDestroyOnLoad(RoundMgr.PMGR.InputPlayers[i].gameObject);
        }
        ResetGameMgr();
        DontDestroyOnLoad(gameObject);
    }
    private void Awake()
    {
        GM = this;
        InitGameMgr();
    }
    void Start()
    {
        RoundMgr.RoundStart();
        StartCoroutine("ResetValues", RoundMgr);

    }

    // Update is called once per frame
    void Update()
    {
        
        
    }
    void LateUpdate()
    {

        RoundMgr.RoundEndCheck();
        if (GamePauseflg)
        {
            StartCoroutine("MenuOpen");
        }
    }

    
    void ResetGameMgr()
    {
        MenuPanel.SetActive(false);
        RoundMgr.ResetRoundMgr();



    }
    
    
    IEnumerator ResetValues(RoundManager RMGR)
    {
        while (RMGR.Gamestartflg)
        {
            if (RMGR.bCallResetGameMgr)
            {
                ResetGameMgr();
            }
            else yield return new WaitForEndOfFrame();
        }
    }//RoundMgr의 bCallResetGameMgr변수를 받아서 원하는 타이밍에 변수를 초기화시키는 함수
    IEnumerator MenuOpen() {

        MenuPanel.SetActive(true);
        Time.timeScale = 0f;
        while (RoundMgr.PMGR.InputNextButton() && GamePauseflg)
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
    
}