using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Custom;
public class GameManager : MonoBehaviour
{
    RoomManager RoomMgr;
    ButtonManager BtnMgr;
    RoundManager RoundMgr;
    public bool bGameEnd = true;
    // Start is called before the first frame update
    private void Awake()
    {
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
                    bGameEnd = false;
                }
                yield return new WaitForEndOfFrame();
                if (!bGameEnd) RoundMgr = RoundManager.CreateObj();
            }
            yield return new WaitForEndOfFrame();
        }
        
    }//룸메니저 업데이트용 함수
    public RoomManager ROOM
    {
        get { return RoomMgr; }
    }
}
