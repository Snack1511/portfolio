using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Custom;
public class Player_AnimControl : MonoBehaviour
{
    Animator Anima;
    public Control control;
    public Player_Cal calculate;
    public PlayerRender Render;
    public void ResetRotate()
    {
        transform.localEulerAngles = new Vector3(0, -90, 0);
    }
    public void InitParameters() {
        Anima.SetBool("IsRun", false);
        Anima.SetBool("IsAttack", false);
        Anima.SetFloat("Blend", 0);
        Anima.SetBool("IsDash", false);
        Anima.SetBool("IsHIt", false);
        Anima.SetBool("IsDie", false);
        Anima.SetBool("IsDeadAnimPlay", false);
        Anima.SetBool("IsThrow", false);
    }
    //------------------------------------------------씬 시작시 초기화 >> Start에서 호출
    
    
    // Start is called before the first frame update
    void Start()
    {
        Anima = GetComponent<Animator>();
        control = transform.root.GetComponent<Control>();
        calculate = transform.root.GetComponent<Player_Cal>();
        Render = transform.root.GetComponentInChildren<PlayerRender>();
        
        InitParameters();
        ResetRotate();
    }
    
    private void Update()
    {
        if (!calculate.bDieflg)
        {
            Play_Run(control.bAnim_Moveflg);
            Play_Att(control.bAnim_Attflg, (int)calculate.WT);
            Play_Dash(control.bAnim_Dashflg);
            Play_Throw(control.bAnim_Throwflg);
            
        }
        else {
            Play_Die(true, calculate.bDeadAnimEnd);
            
        }
        
    }

    

    public void Play_Run(bool flg) {
        Anima.SetBool("IsRun", flg);
    }

    public void Play_Att(bool flg, int MotionNum) {
        Anima.SetBool("IsAttack", flg);
        Anima.SetFloat("Blend", MotionNum);
    }//Player_Cal의 WT int 데이터따라 모션 변경 

    public void Play_Dash(bool flg)
    {
        Anima.SetBool("IsDash", flg);
    }
    
    public void Play_HIt()
    {
        Anima.SetTrigger("HItTrg");
    }//Player_Cal에서 충돌 시 호출

    public void Play_Die(bool flg, bool playEndflg)
    {
        Render.bHitflg = true;
        Anima.SetBool("IsDie", flg);
        Anima.SetBool("IsDeadAnimPlay", playEndflg);
    }
    public void Play_Throw(bool flg)
    {
        Anima.SetBool("IsThrow", flg);
    }
    
    
}
