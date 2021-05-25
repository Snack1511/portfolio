using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class name : MonoBehaviour {
    Text textA;
    // Use this for initialization
    void Awake() {
        textA = GetComponent<Text>();
    }
	void Start () {
        
	}
	
	// Update is called once per frame
	void Update () {
        textA.text = TitleScript.name;
	}
}
