using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class movescript : MonoBehaviour {




    static private float fHoriMove = 0.0f;
    static private float fVertiMove = 0.0f;
    static private float fJump = 0.0f;
    static public float fMoveSpeed = 10.0f;

    // Use this for initialization
    void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public static void PlayerMovePos(Transform tr)
    {
        fHoriMove = Input.GetAxis("Horizontal");
        fVertiMove = Input.GetAxis("Vertical");
        fJump = Input.GetAxis("Jump");
        Vector3 moveDir = (Vector3.forward * fVertiMove) + (Vector3.right * fHoriMove);
        Vector3 jumpDir = (Vector3.up * fJump);

        tr.Translate(moveDir.normalized * Time.deltaTime * fMoveSpeed, Space.Self);

        if (Input.GetKeyDown("space"))
        {
            tr.Translate(jumpDir.normalized * Time.deltaTime * fMoveSpeed * 10.0f, Space.Self);
        }


    }

    
}
