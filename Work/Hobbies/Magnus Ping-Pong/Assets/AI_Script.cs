using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using BallValuse;

public class AI_Script : MonoBehaviour
{
    GiveData Data;
    Transform AI_Tr;//, Ball_Tr, Player_Tr;
    Vector2 AI_Dir = new Vector2(1f, 0f);
    float AI_Speed = 5f;
    // Start is called before the first frame update
    void Start()
    {
        AI_Tr = GetComponent<Transform>();
        //Player_Tr = GetComponent<Transform>();
        //Ball_Tr = GameObject.Find("Ball").GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        
        AI_Dir.y = 0f;
        
        Data = GameObject.Find("Ball").GetComponent<BallScript>().DATA;
        SetAI_Position(Cal_BallXpos(Data.POS, Data.DIR, Data.SPD));
    }

    float Cal_BallXpos(Vector2 BallPos, Vector2 BallDir, float BallSpd) {
        float time = (AI_Tr.position.y - BallPos.y)/(BallDir.y * 0.02f * BallSpd);//0.02f => 프레임당 Timescale
        float Ball_xpos = BallPos.x + (BallDir.x * 0.02f * BallSpd * time);
        if (Ball_xpos >= 17f)//17f => 화면 가로
        {
            Ball_xpos %= 17f;
        }
        Ball_xpos -= (Ball_xpos % 8.5f);
        return Ball_xpos;
    }

    void SetAI_Position(float Destination)
    {
        Vector2 dir = new Vector2(Destination - AI_Tr.position.x, 0).normalized;
        if (AI_Tr.position.x + 8.5f <= Destination + 8.55f || AI_Tr.position.x + 8.5f >= Destination + 8.45f)
        {
            AI_Tr.Translate(dir * AI_Speed * Time.deltaTime);
        }
    }
}
/*
 공이 씹 예각으로 맞으면 도망치는 버그 수정
     */
