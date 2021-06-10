using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RoundManager : MonoBehaviour
{
    public PlayerManager PlayerMgr;
    public BallManager BallMgr;
    bool bRoundEnd = false;
    GameObject WinnerObj;
    GameManager GM;
    int time = 3;
    public static RoundManager CreateObj()
    {
        GameObject RoundMgr = GameObject.Find("RoundMgr");
        if (RoundMgr == null)
        {
            RoundMgr = new GameObject();
            DontDestroyOnLoad(RoundMgr);
            RoundMgr.name = "RoundMgr";
            RoundMgr.AddComponent<RoundManager>();
        }
        return RoundMgr.GetComponent<RoundManager>();
    }
    // Start is called before the first frame update
    void Start()
    {
        PlayerMgr = new PlayerManager();
        BallMgr = new BallManager(GameObject.FindGameObjectWithTag("BALL").GetComponent<BallScript>());
        GM = GameObject.Find("GameMgr").GetComponent<GameManager>();
        StartCoroutine("RoundCheck");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void ResetRound()
    {

        bool side;
        Debug.Log("ResetRound");
        WinnerObj = PlayerMgr.ResetPlayerMgr();
        if (WinnerObj.name != "Bar_Player") BallMgr.ResetBallMgr(true);
        else BallMgr.ResetBallMgr(false);
        if (PlayerMgr.Pointdifference() >= 5)
        {
            GM.bGameEnd = true;
        }
        else
        {
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
                time -= 1;
            }
            else
            {
                if (Time.timeScale == 0)
                {
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
}
