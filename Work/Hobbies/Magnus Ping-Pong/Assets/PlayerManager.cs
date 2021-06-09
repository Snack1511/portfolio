using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerManager : MonoBehaviour
{
    PlayerSet[] Players = new PlayerSet[2];
    // Start is called before the first frame update
    public PlayerManager()
    {
        SetPlayers();
    }
    //public bool 
    void SetPlayers()
    {
        var obj = GameObject.FindGameObjectsWithTag("Player");
        for (int i = 0; i < Players.Length; i++) {
            Players[i] = obj[i].GetComponent<PlayerSet>();
        }
    }
    public bool IsGetPoint()
    {
        if(Players[0].bGetPoiint || Players[1].bGetPoiint) {
            return true;
        }
        else
        {
            return false;
        }
    }
    public void ResetPlayerMgr()
    {
        Players[0].ResetPlayerset();
        Players[1].ResetPlayerset();
    }
}
