using UnityEngine;
using System.Collections;

public class TitleScript : MonoBehaviour {
    public static string name = "your score";
    // Use this for initialization
    void Start () {
        gameroot.score = 0;
        enemy_R.count = 0;
        enemy_G.count = 0;
        enemy_B.count = 0;
    }
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKey(KeyCode.Return)) {
            Application.LoadLevel("tutorial");
            
        }
        if (Input.GetKey(KeyCode.Space))
        {
            Application.LoadLevel("main_play");
           
        }
    }
}
