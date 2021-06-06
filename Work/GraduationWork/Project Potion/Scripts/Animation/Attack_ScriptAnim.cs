using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attack_ScriptAnim : StateMachineBehaviour
{
    public override void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        if (animator.GetComponent<Player_AnimControl>().calculate.WT == 0)
        {
            animator.GetComponent<Player_AnimControl>().calculate.RightHandTr.tag = "FIST";
        }
        //base.OnStateEnter(animator, stateInfo, layerIndex);
    }
    public override void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        //base.OnStateUpdate(animator, stateInfo, layerIndex);
        /*if (stateInfo.normalizedTime > 0.45f)
        {
            animator.GetComponent<Player_AnimControl>().calculate.bAttackControlAnim = true;
        }*/
    }
    override public void OnStateExit(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        //base.OnStateExit(animator, stateInfo, layerIndex);
        if (animator.GetComponent<Player_AnimControl>().calculate.WT == 0)
        {
            animator.GetComponent<Player_AnimControl>().calculate.RightHandTr.tag =
            animator.GetComponent<Player_AnimControl>().calculate.RightHandTr.parent.tag;
            animator.GetComponent<Player_AnimControl>().control.bAnim_Attflg = false;
        }
        else
        {

            animator.GetComponent<Player_AnimControl>().control.bAnim_Attflg = false;
        }
    }
    // OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
    //override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    //{
    //    
    //}

    // OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
    //override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    //{
    //    
    //}

    // OnStateExit is called when a transition ends and the state machine finishes evaluating this state
    //override public void OnStateExit(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    //{
    //    
    //}

    // OnStateMove is called right after Animator.OnAnimatorMove()
    //override public void OnStateMove(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    //{
    //    // Implement code that processes and affects root motion
    //}

    // OnStateIK is called right after Animator.OnAnimatorIK()
    //override public void OnStateIK(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    //{
    //    // Implement code that sets up animation IK (inverse kinematics)
    //}
}
