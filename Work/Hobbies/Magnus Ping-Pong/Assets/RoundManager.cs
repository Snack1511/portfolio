using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RoundManager : MonoBehaviour
{
    public PlayerManager PlayerMgr;
    bool bRoundEnd = false;
    GameManager GM;
    public static RoundManager CreateObj()
    {
        GameObject RoundMgr = new GameObject();
        DontDestroyOnLoad(RoundMgr);
        RoundMgr.name = "RoundMgr";
        RoundMgr.AddComponent<RoundManager>();
        return RoundMgr.GetComponent<RoundManager>();
    }
    // Start is called before the first frame update
    void Start()
    {
        PlayerMgr = new PlayerManager();
        GM = GameObject.Find("GameMgr").GetComponent<GameManager>();
        StartCoroutine("RoundCheck");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void ResetRound()
    {
        Debug.Log("ResetRound");
        PlayerMgr.ResetPlayerMgr();
    }
    
    IEnumerator RoundCheck()
    {
        int time = 3;
        Time.timeScale = 0;
        while (time >= 1)
        {
            Debug.Log(time);
            yield return new WaitForSecondsRealtime(1);
            time -= 1;
        }
        Time.timeScale = 1;
        while (!GM.bGameEnd)
        {
            
            if (PlayerMgr.IsGetPoint())
            {
                ResetRound();
            }
            yield return new WaitForEndOfFrame();
        }
    }
}
