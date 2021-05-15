using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Throw_ScriptAnim : StateMachineBehaviour
{

    public override void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        //base.OnStateUpdate(animator, stateInfo, layerIndex);
        if(stateInfo.normalizedTime > 0.45f)
        {
            animator.GetComponent<Player_AnimControl>().calculate.bThrowControlAnim = true;
        }
    }
    override public void OnStateExit(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        //base.OnStateExit(animator, stateInfo, layerIndex);
        animator.GetComponent<Player_AnimControl>().control.Anim_Throwflg = false;
    }
}
