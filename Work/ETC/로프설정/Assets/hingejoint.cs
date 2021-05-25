using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class hingejoint : MonoBehaviour {

    HingeJoint hing;
	// Use this for initialization
	void Start () {
        hing = GetComponent<HingeJoint>();

	}
	

	// Update is called once per frame
	void Update () {
        if (Input.GetKey(KeyCode.RightArrow)) {
            hing.currentTorque.Set(10, 0, 0);
        }
	}
}
