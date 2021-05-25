using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class score : MonoBehaviour {
    Text scoreboard;
    // Use this for initialization
    void Awake()
    {
        scoreboard = GetComponent<Text>();
        
    }
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        
        //scoreboard.fontSize = Screen.height * size / 100;
        scoreboard.text = gameroot.score.ToString();//ToString = 문자열로 변환하는 함수
    }
}
