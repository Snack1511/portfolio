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
    public void InitUIMgr()
    {
        GamePauseflg = true;//★
        
    }
    public void ResetUIMgr()
    {
        MenuPanel.SetActive(false);
        ScoreboardPanel.SetActive(!RoomMgr.Tutorialchkflg);
    }
    public void SetManager()
    {
        RoomMgr = GameObject.Find("RoomMgr").GetComponent<RoomManager>();
        MenuPanel = GameObject.Find("MenuCanvas");//★
        Debug.Log(MenuPanel);
        MenuPanel.transform.SetParent(transform);//★

        ScoreboardPanel = GameObject.Find("ScoreboardCanvas");//★
        ScoreboardPanel.transform.SetParent(transform);//★
    }
    private void Awake()
    {
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
        
        if (MenuPanel != null && ScoreboardPanel != null && GamePauseflg)
        {
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
            Time.timeScale = 1f;
            MenuPanel.SetActive(false);
        }


    }//★
    public void SetPause(bool flg)
    {
        GamePauseflg = flg;
    }
}
