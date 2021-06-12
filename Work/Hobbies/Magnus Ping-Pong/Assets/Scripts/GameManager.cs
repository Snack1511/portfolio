using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Custom;
public class GameManager : MonoBehaviour
{
    //public static GameManager Instance;
    RoomManager RoomMgr;
    ButtonManager BtnMgr;
    RoundManager RoundMgr;
    public bool bGameEnd = true;
    public int iRoundTime = 0;
    // Start is called before the first frame update
    private void Awake()
    {
        var a = GameObject.Find("GameMgr");
        if (a != null && a != gameObject)
        {
            Destroy(gameObject);
            return;
        }
        DontDestroyOnLoad(gameObject);
        RoomMgr =RoomManager.CreateObj();
        //RoomMgr = new RoomManager();
        BtnMgr = GameObject.Find("ButtonMgr").GetComponent<ButtonManager>();
        BtnMgr.RoomMgr = RoomMgr;
    }
    void Start()
    {
        StartCoroutine("RoomMgrUpdate");

    }

    // Update is called once per frame
    void Update()
    {
        
    }
    void ResetRoundMgr()
    {
        if (RoundMgr != null) {
            Destroy(RoundMgr.gameObject);
        
        }
    }
    IEnumerator RoomMgrUpdate()
    {
        while (true)
        {
            while (bGameEnd)
            {
                if (RoomMgr.TagChange)
                {
                    RoomMgr = BtnMgr.RoomMgr;
                    RoomMgr.SceneMove();
                    RoomMgr.TagChange = false;
                    if (RoomMgr.TAG == ROOMTAG.Play)
                    {
                        ResetRoundMgr();
                        bGameEnd = false;
                    }
                }
                if (RoomMgr.TAG == ROOMTAG.Ending)
                {
                    if (GameObject.Find("TotalScore") != null)
                    {
                        RoundMgr.SetTotalScore(GameObject.Find("TotalScore"));
                        GameObject.Find("TotalScore").name += "Confirm";
                    }
                }
                yield return new WaitForEndOfFrame();
                if (!bGameEnd) RoundMgr = RoundManager.CreateObj(iRoundTime);
            }
            yield return new WaitForEndOfFrame();
        }
        
    }//룸메니저 업데이트용 함수
    public RoomManager ROOM
    {
        get { return RoomMgr; }
    }
}
