using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using BallValuse;

public class AI_Script : MonoBehaviour
{
    /*GiveData Data;
    Transform AI_Tr;//, Ball_Tr, Player_Tr;
    Vector2 AI_Dir = new Vector2(1f, 0f);
    float AI_Speed = 5f;*/
    const float DefaultdiffValue = 3f;
    float fDiffValue;
    float fDiff = 0f;
    float fDestRpm;
    float AIHori;
    float AIVerti;
    CONDITION condition;
    int pointdiff;//포인트차이
    bool bWInner;
    PlayerManager PMgr;
    BallScript Ball;
    PlayerSet CPU_Set;
    PlayerSet Player_Set;
    
    private void Start()
    {
        fDiffValue = DefaultdiffValue;
        AIHori = 0f;
        AIVerti = 0f;
        condition = CONDITION.IDLE;
        CPU_Set = GetComponent<PlayerSet>();
        Player_Set = GameObject.Find("Bar_Player").GetComponent<PlayerSet>();
    }

    private void Update()
    {
        valueCheck();
        stateChange();
        
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.name == "Ball")
        {
            fDiff = Random.Range(0, fDiffValue);
            fDestRpm = (CPU_Set.POS.x - Player_Set.POS.x) * 5;
        }
    }

    void valueCheck()
    {
        if(PMgr == null)
        {
            PMgr = GameObject.Find("RoundMgr").GetComponent<RoundManager>().PMGR;
            Ball = GameObject.Find("Ball").GetComponent<BallScript>();
        }
        pointdiff = PMgr.Pointdifference();
        bWInner = PMgr.GetWinner() == gameObject ? true : false;
    }
    void stateChange()
    {
        if (pointdiff != 0)
        {
            if (bWInner)
            {
                if (pointdiff > 3)
                {
                    condition = CONDITION.SNEER;
                    fDiffValue = 5f;
                }
                else
                {
                    condition = CONDITION.DEFENCE;
                    fDiffValue = 4f;
                }
            }
            else
            {
                if (pointdiff > 0)
                {
                    condition = CONDITION.OFFENCE;
                    fDiffValue = 1f;
                }
            }
        }
        else
        {
            condition = CONDITION.IDLE;
            fDiffValue = DefaultdiffValue;
        }
        AIBehave();
    }

    void AIBehave()
    {
        SetRotate(fDiff);
        if (condition == CONDITION.DEFENCE)
        {
            BehaveDefence();
        }
        else if (condition == CONDITION.OFFENCE)
        {
            BehaveOffence();
        }
        else if (condition == CONDITION.SNEER)
        {
            BehaveSneer();
        }
        else
        {
            BehaveIdle();
        }
    }
    void BehaveDefence()
    {
        SetDestination(Ball, fDiff);
        Debug.Log("Defence");
    }
    void BehaveOffence()
    {
        SetDestination(Ball.DATA.POS, Ball.DATA.DIR, fDiff);
        Debug.Log("Offence");
    }
    void BehaveSneer()
    {
        Debug.Log("Sneer");
        condition = CONDITION.DEFENCE;
    }
    void BehaveIdle()
    {
        
        SetDestination(Ball, fDiff);
        Debug.Log("Idle");
    }
    void SetDestination(BallScript ball, float Diff)
    {
        if (ball.DATA.DIR.y > 0)
        {
            if (ball.DATA.POS.x - CPU_Set.POS.x > Diff)
            {
                AIHori = 1;
            }
            else if (ball.DATA.POS.x - CPU_Set.POS.x < -Diff)
            {
                AIHori = -1;
            }
            else
            {
                AIHori = 0;
            }
        }
        else
        {
            AIHori = 0;
        }
    }
    void SetDestination(Vector2 Pos, Vector2 Dir,float Diff)
    {
        if (Dir.y > 0&& Pos.y - CPU_Set.POS.y <= Diff)
        {
            if (Pos.x - CPU_Set.POS.x > Diff)
            {
                AIHori = 1;
            }
            else if (Pos.x - CPU_Set.POS.x < -Diff)
            {
                AIHori = -1;
            }
            else
            {
                AIHori = 0;
            }
        }
        else
        {
            AIHori = 0;
        }
    }
    void SetRotate(float Diff)
    {
        if(fDestRpm - CPU_Set.BAR.NOWRPM > Diff)
        {
            AIVerti = 1;
        }
        else if(fDestRpm - CPU_Set.BAR.NOWRPM < Diff)
        {
            AIVerti = -1;
        }
        else
        {
            AIVerti = 0;
        }
    }
    public float HORI
    {
        get { return AIHori; }
    }
    public float VERTI
    {
        get { return AIVerti; }
    }
    
    enum CONDITION
    {
        IDLE,
        DEFENCE,
        OFFENCE,
        SNEER,
    }

    // Start is called before the first frame update
    /*void Start()
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
    }*/
}
/*
 공이 씹 예각으로 맞으면 도망치는 버그 수정
     */
