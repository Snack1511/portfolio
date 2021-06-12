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
        SoundManager.Instance.PlaySFX(Custom.SFXTAG.BUTTONCLICK);
        RoomMgr.TAG = Custom.ROOMTAG.Play;
        RoomMgr.TagChange = true;
    }
    public void btnMenu()
    {
        SoundManager.Instance.PlaySFX(Custom.SFXTAG.BUTTONCLICK);
        RoomMgr.TAG = Custom.ROOMTAG.Menu;
        RoomMgr.TagChange = true;
    }
    public void btnQuit()
    {
        SoundManager.Instance.PlaySFX(Custom.SFXTAG.BUTTONCLICK);
        #if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
        #else
        Application.Quit();
        #endif
    }
    /*public void btnTest()
    {
        SoundManager.Instance.PlaySFX(Custom.SFXTAG.BUTTONCLICK);
    }*/
}
