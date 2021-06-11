using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerManager : MonoBehaviour
{
    PlayerSet[] Players = new PlayerSet[2];
    PlayerSet Winner;
    int iWinnerIdx = 0;
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
        if (Players[0].bGetPoiint) {
            Winner = Players[0];
            iWinnerIdx = 0;
            return true;
        }
        else if (Players[1].bGetPoiint)
        {
            Winner = Players[1];
            iWinnerIdx = 1;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    public GameObject ResetPlayerMgr()
    {
        Players[0].ResetPlayerset();
        Players[1].ResetPlayerset();
        return Winner.gameObject;
    }
    public int Pointdifference()
    {
        int Diff = 0;
        Diff = Mathf.Abs(Players[0].Point - Players[1].Point);
        return Diff;
    }
    public int GetPoint(int n)
    {
        return Players[n].Point;
    }
    public int GetPoint()
    {
        return Players[iWinnerIdx].Point;
    }
    public int WINNERIDX
    {
        get { return iWinnerIdx; }
    }
}
