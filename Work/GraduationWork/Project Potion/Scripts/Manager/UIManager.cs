using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIManager : MonoBehaviour
{
    /*
     * UI창 관리
     */
    //Game -> Room -> Round -> UI
    public bool GamePauseflg;//중지플레그
    GameObject MenuPanel;
    GameObject ScoreboardPanel;
    RoomManager RoomMgr;
    RoundManager RoundMgr;
    public RoundManager ROUNDMGR
    {
        get { return RoundMgr; }
    }

    public void InitUIMgr()
    {
        GamePauseflg = GameManager.GM.GamePauseflg;//★

    }
    public void ResetUIMgr()
    {
        MenuPanel.SetActive(!RoomMgr.Tutorialchkflg);
        ScoreboardPanel.SetActive(false);
    }
    public void SetManager()
    {
        RoomMgr = GameObject.Find("RoomMgr").GetComponent<RoomManager>();
        RoundMgr = GameObject.Find("RoundMgr").GetComponent<RoundManager>();
        MenuPanel = GameObject.Find("MenuCanvas");//★
        Debug.Log(MenuPanel);
        MenuPanel.transform.SetParent(transform);//★

        ScoreboardPanel = GameObject.Find("ScoreboardCanvas");//★
        ScoreboardPanel.transform.SetParent(transform);//★
        ScoreboardPanel.transform.GetChild(1).GetComponent<ScoreboardScript>().InitScoreboard(this);
    }
    private void Awake()
    {
        InitUIMgr();
        //SetManager();
    }
    // Start is called before the first frame update
    void Start()
    {
        //RoomMgr = GameObject.Find("RoomMgr").GetComponent<RoomManager>();
    }

    // Update is called once per frame
    void Update()
    {

        if (MenuPanel != null && ScoreboardPanel != null && GameManager.GM.GamePauseflg)
        {
            GamePauseflg = GameManager.GM.GamePauseflg;
            Debug.Log("MenuPanelFind");
            StartCoroutine("MenuOpen");
        }//★
    }
    IEnumerator MenuOpen()
    {

        MenuPanel.SetActive(true);
        Time.timeScale = 0f;
        while (RoomMgr.ROUNDMGR.PMGR.InputNextButton() && GamePauseflg)
        {
            yield return new WaitForEndOfFrame();
        }
        GamePauseflg = false;
        if (!GamePauseflg)
        {
            if (!RoomMgr.Tutorialchkflg) RoomMgr.Tutorialchkflg = true;//주의
            GameManager.GM.GamePauseflg = GamePauseflg;
            Time.timeScale = 1f;
            MenuPanel.SetActive(false);
        }


    }//★
    public void SetPause(bool flg)
    {
        GamePauseflg = flg;
    }
    public void ScoreboardCheck(bool flg)
    {
        if (flg)
        {
            Debug.Log("ScoreboardCheck On");
            if (ScoreboardPanel.transform.GetChild(1).GetComponent<ScoreboardScript>().bPlayEnd)
            {
                Debug.Log("SCORECHECK True");
                RoundMgr.SCORECHECK = true;
            }
            else
            {
                Debug.Log("Click");
                ScoreboardPanel.transform.GetChild(1).GetComponent<ScoreboardScript>().bPlayEnd = true;
            }
        }//버튼 입력시 스코어 보드 비활성화
    }
    public void SwitchScorePanel(bool flg)
    {
        if (!flg)
        {
            Debug.Log("ScoreOn");
            if (!ScoreboardPanel.activeSelf) ScoreboardPanel.SetActive(true);
        }
        else
        {
            Debug.Log("ScoreOff");
            if (ScoreboardPanel.activeSelf) ScoreboardPanel.SetActive(false);
        }

    }
    public bool IsScoreOn()
    {
        return ScoreboardPanel.activeSelf;
    }
}
