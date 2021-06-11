using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ButtonManager : MonoBehaviour
{
    public RoomManager RoomMgr;
   
    private void Start()
    {
        RoomMgr = GameObject.Find("RoomMgr").GetComponent<RoomManager>();
    }
    public void btnStart()
    {
        RoomMgr.TAG = Custom.ROOMTAG.Play;
        RoomMgr.TagChange = true;
    }
    public void btnMenu()
    {
        RoomMgr.TAG = Custom.ROOMTAG.Menu;
        RoomMgr.TagChange = true;
    }
    public void btnQuit()
    {
        #if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
        #else
        Application.Quit();
        #endif
    }
}
