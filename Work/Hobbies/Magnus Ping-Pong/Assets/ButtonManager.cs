using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ButtonManager : MonoBehaviour
{
    public RoomManager RoomMgr;
    public void btnStart()
    {
        RoomMgr.TAG = Custom.ROOMTAG.Play;
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
