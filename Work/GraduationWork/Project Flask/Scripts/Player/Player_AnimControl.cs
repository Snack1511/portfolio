using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player_AnimControl : MonoBehaviour
{
    Animator Anima;
    public Control control;
    public Player_Cal calculate;
    public PlayerRender Render;

    private void Awake()
    {
        
    }
    // Start is called before the first frame update
    void Start()
    {
        Anima = GetComponent<Animator>();
        control = transform.root.GetComponent<Control>();
        calculate = transform.root.GetComponent<Player_Cal>();
        Render = transform.root.GetComponentInChildren<PlayerRender>();
        
        InitParameters();
        ResetRotate();
        //Debug.Log(Anima.runtimeAnimatorController);
    }
    
    private void Update()
    {
        if (!calculate.bDieflg)
        {
            Play_Run(control.Anim_Moveflg);
            Play_Att(control.Anim_Attflg, (int)calculate.WT);
            Play_Dash(control.Anim_Dashflg);
            //Play_HIt(calculate.bHitflg);
            Play_Throw(control.Anim_Throwflg);
            /*if (calculate.bHitflg)
            {
                Play_HIt();
            }*/
            
        }
        else {
            Play_Die(true, calculate.bDeadAnimEnd);
            
        }
        
    }
    public void ResetRotate()
    {
        transform.localEulerAngles = new Vector3(0, -90, 0);
        //transform.SetPositionAndRotation(transform.position, Quaternion.Euler(0, -90, 0));

    }
    public void InitParameters() {
        //transform.rotation = Quaternion.Euler(0, -90, 0);
        Anima.SetBool("IsRun", false);
        Anima.SetBool("IsAttack", false);
        //Debug.Log(MotionNum);
        Anima.SetFloat("Blend", 0);
        Anima.SetBool("IsDash", false);
        Anima.SetBool("IsHIt", false);
        Anima.SetBool("IsDie", false);
        Anima.SetBool("IsDeadAnimPlay", false);
        Anima.SetBool("IsThrow", false);
    }

    public void Play_Run(bool flg) {
        Anima.SetBool("IsRun", flg);
    }
    public void Play_Att(bool flg, int MotionNum) {
        Anima.SetBool("IsAttack", flg);
        //Debug.Log(MotionNum);
        Anima.SetFloat("Blend", MotionNum);
    }
    public void Play_Dash(bool flg)
    {
        Anima.SetBool("IsDash", flg);
    }
    public void Play_HIt(bool flg)
    {
        Anima.SetBool("IsHIt", flg);
    }
    public void Play_HIt()
    {
        Anima.SetTrigger("HItTrg");
    }//Trigger

    public void Play_Die(bool flg, bool playEndflg)
    {
        Render.bHitflg = true;
        Anima.SetBool("IsDie", flg);
        Anima.SetBool("IsDeadAnimPlay", playEndflg);
    }
    public void Play_Throw(bool flg)
    {
        Anima.SetBool("IsThrow", flg);
        /*if (!Anima.GetCurrentAnimatorStateInfo(0).IsName("Throw"))
        {
            Debug.Log("aa");
            control.Anim_Throwflg = false;
            
        }
        */
    }
    
}
