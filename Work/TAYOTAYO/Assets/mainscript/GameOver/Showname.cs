using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class Showname : MonoBehaviour {
    Text SN;
    // Use this for initialization
    void Start () {
        SN = GetComponent<Text>();
    }
	
	// Update is called once per frame
	void Update () {
        SN.text = TitleScript.name;
    }
}
