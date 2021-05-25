using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HookSystem : MonoBehaviour {

    static public FixedJoint fixjoint;
    static public HingeJoint hngjoint;

	// Use this for initialization
	void Start () {
        fixjoint = GetComponent<FixedJoint>();
        hngjoint = GetComponent<HingeJoint>();
    }
	
	// Update is called once per frame
	void Update () {
		
	}

    
}
