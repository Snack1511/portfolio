using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreManager
{
    string strTotalScoreString;
    string strPlayerScore;
    string strCPUScore;
    public ScoreManager(GameObject Playerobj, GameObject Cpuobj)
    {
        UpdateScores();
        SetEachScore(Playerobj, Cpuobj);
    }
    public void SetEachScore(GameObject obj, string str)
    {
        obj.GetComponent<Text>().text = str;
    }
    public void SetEachScore(GameObject Playerobj, GameObject Cpuobj)
    {
        Playerobj.GetComponent<Text>().text = strPlayerScore;
        Cpuobj.GetComponent<Text>().text = strCPUScore;
    }
    public void UpdateScores(int Player = 0, int Cpu = 0)
    {
        strPlayerScore = Player.ToString();
        strCPUScore = Cpu.ToString();
    }
    public void UpdateScore(bool flg, int score)
    {
        if (flg)
        {
            strPlayerScore = score.ToString();
        }
        else
        {
            strCPUScore = score.ToString();
        }
    }
    public void GetTotalScore(GameObject TotalScore)
    {
        TotalScore.GetComponent<Text>().text = strPlayerScore + "  :  " + strCPUScore;
    }
}
