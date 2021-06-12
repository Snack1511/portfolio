using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RoundManager : MonoBehaviour
{
    PlayerManager PlayerMgr;
    public BallManager BallMgr;
    ScoreManager ScoreMgr;
    bool bRoundEnd = false;
    GameObject WinnerObj;
    GameManager GM;
    int time = 3;
    int iRoundTime = 0;
    int itmpScore = 0;
    GameObject objPlayerScore, objCPUScore;
    public static RoundManager CreateObj(int RoundTime = 1)
    {
        GameObject RoundMgr = GameObject.Find("RoundMgr");
        if (RoundMgr == null)
        {
            RoundMgr = new GameObject();
            RoundMgr.name = "RoundMgr";
            RoundMgr.AddComponent<RoundManager>();
        }
        DontDestroyOnLoad(RoundMgr);
        var a = RoundMgr.GetComponent<RoundManager>();
        a.SetValue(RoundTime);
        return RoundMgr.GetComponent<RoundManager>();
    }
    void SetValue(int RoundTime)
    {
        iRoundTime = RoundTime;
    }
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("start");
        objPlayerScore = GameObject.Find("PlayerScore");
        objCPUScore = GameObject.Find("CPUScore");
        PlayerMgr = new PlayerManager();
        BallMgr = new BallManager(GameObject.FindGameObjectWithTag("BALL").GetComponent<BallScript>());
        ScoreMgr = new ScoreManager(objPlayerScore, objCPUScore);
        GM = GameObject.Find("GameMgr").GetComponent<GameManager>();
        StartCoroutine("RoundCheck");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void SetTotalScore(GameObject TotalScore)
    {
        ScoreMgr.GetTotalScore(TotalScore);
    }
    public void ResetRound()
    {
        Debug.Log("ResetRound");
        WinnerObj = PlayerMgr.ResetPlayerMgr();
        if (WinnerObj.name == "Bar_Player") {
            ScoreMgr.UpdateScore(true, PlayerMgr.GetPoint());
            BallMgr.ResetBallMgr(true); 
        }
        else {
            ScoreMgr.UpdateScore(false, PlayerMgr.GetPoint());
            BallMgr.ResetBallMgr(false);
        }
        if (PlayerMgr.Pointdifference() >= iRoundTime)
        {
            GM.bGameEnd = true;
        }
        else
        {
            ScoreMgr.SetEachScore(objPlayerScore, objCPUScore);
            time = 3;
        }
    }
    
    IEnumerator RoundCheck()
    {
        
        //while (time >= 1)
        //{
        //    Time.timeScale = 0;
        //    Debug.Log(time);
        //    yield return new WaitForSecondsRealtime(1);
        //    time -= 1;
        //}
        //Time.timeScale = 1;
        while (!GM.bGameEnd)
        {
            if (time >= 1)
            {
                if (Time.timeScale == 1)
                {
                    Time.timeScale = 0;
                }
                Debug.Log(time);
                yield return new WaitForSecondsRealtime(1);
                SoundManager.Instance.PlaySFX(Custom.SFXTAG.COUNTDONW);
                time -= 1;
            }
            else
            {
                if (Time.timeScale == 0)
                {
                    yield return new WaitForSecondsRealtime(1);
                    SoundManager.Instance.PlaySFX(Custom.SFXTAG.STARTROUND);
                    Time.timeScale = 1;
                }
                if (PlayerMgr.IsGetPoint())
                {
                    ResetRound();
                }
                yield return new WaitForEndOfFrame();
            }
        }
        GM.ROOM.TAG = Custom.ROOMTAG.Ending;
        GM.ROOM.TagChange = true;
    }
    public PlayerManager PMGR
    {
        get { return PlayerMgr; }
    }
    public BallManager BMGR
    {
        get { return BallMgr; }
    }
}
