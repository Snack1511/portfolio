using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using Custom;

public class RoomManager
{
    ROOMTAG tag;
    public bool TagChange = false;
    public RoomManager(ROOMTAG _tag = ROOMTAG.Menu)
    {
        tag = _tag;
    }
    public void SceneMove()
    {
        switch (tag)
        {
            case ROOMTAG.Menu:
                SceneManager.LoadScene("MainMenu");
                break;
            case ROOMTAG.Play:
                SceneManager.LoadScene("Play");
                break;
            case ROOMTAG.Ending:
                SceneManager.LoadScene("Ending");
                break;
        }
    }
    public ROOMTAG TAG
    {
        get { return tag; }
        set { tag = value; }
    }

    
}
