using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using BallValuse;



public class BallScript : MonoBehaviour
{
    float Ball_Speed = 3f;

    public float RPM = 60f;//--> Target에서 받아와야함
    float POSY = 0f, POSX = 1f;
    Vector2 BasicRoute = new Vector2(0, -1);
    Vector2 RadiRoute = new Vector2(0, 0);
    Vector2 Target = new Vector2(0, 0);

    Vector2 Ball_Dir = new Vector2(0, -1);
    bool SideCheck = false;
    Transform Ball_Tr, Player_Tr, Enemy_Tr;
    GiveData Values = new GiveData();


    // Start is called before the first frame update
    void Start()
    {
        Ball_Tr = GetComponent<Transform>();
        Player_Tr = GameObject.Find("Bar_Player").GetComponent<Transform>();
        Enemy_Tr = GameObject.Find("Bar_CPU").GetComponent<Transform>();

    }

    // Update is called once per frame
    void Update()
    {
        if (Ball_Tr.position.x < 8.4 && Ball_Tr.position.x > -8.4)
        {
            SideCheck = false;
        }
        if (Target != new Vector2(0, 0))
        {
            Ball_Dir = ContrallDir(Target);
            
        }
        
        
        Ball_Tr.transform.Translate(Ball_Dir * Ball_Speed * Time.deltaTime);
        Values.DataUpdate(Ball_Tr.position, Ball_Dir, Ball_Speed);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        SoundManager.Instance.PlaySFX(Custom.SFXTAG.BALLCOLLISION);
        //SideCheck = false;
        Ball_Speed += 0.025f;
        Target = new Vector2(Ball_Tr.position.x- collision.gameObject.transform.position.x, collision.gameObject.transform.position.y);

        if (Target.y >= 0) { POSY = -1f; }
        else { POSY = 1f; }
        BasicRoute = new Vector2(Target.x /* 0.25f*/, POSY);
        

        DATA = new GiveData(Ball_Tr.position, BALLDIR, BALLSPEED);

    }

    public void ResetBall(bool side)
    {
        Debug.Log("ResetBall");
        Ball_Tr.position = Vector2.zero;
        SideCheck = false;
        RPM = 60f;
        POSY = 0f;
        POSX = 1f;
        BasicRoute = new Vector2(0, -1);
        RadiRoute = Vector2.zero;
        Target = Vector2.zero;
        Ball_Speed = 3f;
        if (side) Ball_Dir = new Vector2(0, -1);
        else Ball_Dir = new Vector2(0, 1);
    }

    private Vector2 ContrallDir(Vector2 TObject)
    {
        if (SideCheck == false)
        {
            if (Ball_Tr.position.x >= 8.5 || Ball_Tr.position.x <= -8.5)
            {
                SoundManager.Instance.PlaySFX(Custom.SFXTAG.BALLCOLLISION);
                POSX = -1f;
                SideCheck = true;
            }
        }
        else
        {
            POSX = 1f;
        }
        RadiRoute = new Vector2(MagnusForce(RPM, BALLSPEED, 1) * POSX * RotateDir_Cal(RPM), 0).normalized;
        
        
        //결과값
        BasicRoute.x *= POSX;
        BasicRoute += RadiRoute*Time.deltaTime;

        return BasicRoute.normalized;
    }

    public float MagnusForce(float RPM, float BallSpd, float Density = 1f, float proportional_constant = 0.01f) {
        return Mathf.Abs(0.5f * Density * BallSpd * Time.deltaTime * proportional_constant * RPM * Time.deltaTime );
    }

    public float RotateDir_Cal(float value) {
        float flag = 0f;
        flag = value /Mathf.Abs(value);
        return flag;

        /// 회전 방향따른 방향만 결정
    }
    


    public Vector2 BALLDIR
    {
        private set { Ball_Dir = value; }
        get { return Ball_Dir; }
    }
    public float BALLSPEED
    {
        private set { Ball_Speed = value; }
        get { return Ball_Speed; }
    }
    public GiveData DATA
    {
        private set { Values = value; }
        get { return Values; }
    }
}
/*
 마그누스 효과 -> 회전방향 및 유체이동방향 동일 -> 압력작음
                  회전방향 및 유체이동방향 차이 -> 압력 큼
 마그누스 효과 적용

마그누스수식 -> F = 0.5pwrVA*l
                    p => 유체 밀도 -> 1
                    w=> 회전각 속도 -> Angle * Mathf.PI * Time.deltaTime / (180)
                            시계방향 회전 -> 좌측힘
                            반시계        -> 우측힘
                    r => 공 반지름 -> 1
                    V => 공 속도 -> SPD
                    A => 공의 단면적 -> 1
                    l => 상수 -> 1
마그누스 진행방향 => MG_Dir = New Vector2(Ball_Dir.y, Ball_Dir.x)

            계산 => BallTranslate = Ball_Dir*spd + MG_Dir*F -> alpha
                                    (alpha.x * alpha.x + alpha.y*alpha.y)sqrt => scalar...?
     */
