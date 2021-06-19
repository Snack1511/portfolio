using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Custom;
public class RoomManager : MonoBehaviour
{
    /*
     * 씬 조작 및 설정
     */
    // Start is called before the first frame update
    /*
     * usable values >>
     * 1. NetworkMgr
     * 2. InputMgr -> Lobby 진입 후
     * 3. RoundMgr -> Play 진입 후

     */
    /*
     * Game->Room->Round->Player
     */
    //★ : UIMgr만들기 전 까지만 유지

    ROOMTAG Tag;
    UIManager UIMgr;
    RoundManager RoundMgr;

    public bool GamePauseflg;//중지플레그
    public bool Tutorialchkflg;//튜토리얼 확인 플레그

    GameObject MenuPanel;//★
    GameObject ScoreboardPanel;//★
    //InputManager
    public RoundManager ROUNDMGR
    {
        get { return RoundMgr; }
    }
    void InitRoomMgr()
    {
        //플레이씬으로 넘어갈때 동작
        RoundMgr = GenericFuncs.InitMgr<RoundManager>("RoundMgr").GetComponent<RoundManager>();
        
        GamePauseflg = true;
        Tutorialchkflg = false;

        MenuPanel = GameObject.Find("MenuCanvas");//★
        MenuPanel.transform.SetParent(transform);//★

        ScoreboardPanel = GameObject.Find("ScoreboardCanvas");//★
        ScoreboardPanel.transform.SetParent(transform);//★
    }
    public void ResetRoomMgr()
    {
        MenuPanel.SetActive(false);
        RoundMgr.ResetRoundMgr();
    }
    public void SetManager(SelectData[] Selected, int n = 0)
    {
        RoundMgr.SetManager(Selected, ScoreboardPanel, n);
        //ResetRoomMgr();
    }//생성자를 대신해 초기화 시키는 함수
    void Awake()
    {
        InitRoomMgr();
    }
    void Start()
    {
        RoundMgr.RoundStart();
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
        }//★
    }
    IEnumerator MenuOpen()
    {

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


    }//★
    public enum ROOMTAG
    {
        Menu,
        Local,
        Online,
        Lobby,
        Play,
        Ending,
    }
}
