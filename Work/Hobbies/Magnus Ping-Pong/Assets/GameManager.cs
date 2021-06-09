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
        RoomMgr = new RoomManager();
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
        }
        RoundMgr = RoundManager.CreateObj();
    }//룸메니저 업데이트용 함수
}
