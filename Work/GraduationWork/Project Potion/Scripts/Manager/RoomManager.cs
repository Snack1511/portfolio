using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;
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

    public SelectData[] Selected = new SelectData[4];

    RoundManager RoundMgr;

    bool bTutorial;
    bool bOnline;
    bool bPlay;

    
    public bool Tutorialchkflg { 
        get { return bTutorial; }
        set { bTutorial = value; }
    }//튜토리얼 확인 플레그
    public bool Onlineflg
    {
        get { return bOnline; }
        //set { bOnline = value; }
    }//온라인 확인 플레그
    public bool PlaySceneflg
    {
        get { return bPlay; }
        //set { bPlay = value; }
    }
    public bool GamePauseflg
    {
        get { return RoundMgr.UIMGR.GamePauseflg; }
    }

    public RoundManager ROUNDMGR
    {
        get { return RoundMgr; }
    }
    void InitRoomMgr()
    {
        //플레이씬으로 넘어갈때 동작
        //RoundMgr = GenericFuncs.InitMgr<RoundManager>("RoundMgr").GetComponent<RoundManager>();
        ResetRoomMgr();

    }
    public void ResetRoomMgr()
    {
        bOnline = false;
        bPlay = false;
        Tutorialchkflg = false;
        //MenuPanel.SetActive(false);
        //RoundMgr.ResetRoundMgr();
    }
    /*public void SetManager(SelectData[] Selected, int n = 0)
    {
        RoundMgr.SetManager(Selected, n);
        //ResetRoomMgr();
    }//생성자를 대신해 초기화 시키는 함수*/
    void Awake()
    {
        InitRoomMgr();
        StartCoroutine("ChangeRoom");
    }
    void Start()
    {
        //RoundMgr.RoundStart();
    }
    IEnumerator ChangeRoom()
    {
        while (!bPlay)
        {
            yield return new WaitForEndOfFrame();
        }
        SceneManager.LoadScene("Scenes/Maps/TutorialScene");
        
        CreateRoundMgr();
    }
    private void OnLevelWasLoaded(int level)
    {
        if(level == 2)
        {
            Debug.Log("tutorial");
        }
    }
    void CreateRoundMgr()
    {
        Debug.Log("CRM");
        if (!Selected[0].IsActive())
        {
            Debug.Log("DebugSelected");
            Selected[0] = new SelectData(null, 0, "Keyboard", InputSystem.devices[0], "Ch_roundFlask");
            Selected[1] = new SelectData(null, 1, "XInputControllerWindows", InputSystem.devices[2], "Ch_roundFlask");//디버깅용
        }
        RoundMgr = GenericFuncs.InitMgr<RoundManager>("RoundMgr").GetComponent<RoundManager>();
        RoundMgr.SetManager(Selected /*ScoreboardPanel,*/);
    }

    public void SetPlay(bool flg = true)
    {
        bPlay = flg;
    }
    public void SetLocal(bool flg = true)
    {
        //Debug.Log("Create NetWorkMgr");
    }
    public void SetOnline(bool flg = true)
    {
        Debug.Log("Create NetWorkMgr");
    }
    // Update is called once per frame
    void Update()
    {
        
    }
    
}
