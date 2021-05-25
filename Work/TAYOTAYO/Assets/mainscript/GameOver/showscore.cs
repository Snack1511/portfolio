using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class showscore : MonoBehaviour {
    Text SS;
	// Use this for initialization
	void Start () {
        
        SS = GetComponent<Text>();
	}
	
	// Update is called once per frame
	void Update () {
        
        SS.text = PlayerPrefs.GetInt(TitleScript.name, gameroot.a).ToString();
	}
    
}
