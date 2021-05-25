using UnityEngine;
using System.Collections;

public class GameOverScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKey(KeyCode.Return))
        {
            Application.LoadLevel("title");
            gameroot.score = 0;
            enemy_R.count = 0;
            enemy_G.count = 0;
            enemy_B.count = 0;
        }
    }
    /*void roaddata() {
        PlayerPrefs.GetInt(TitleInput.name, gameroot.a);
    }*/
    /*void OnGUI()
    {
        GUI.TextField(new Rect(100, 100, 100, 200), TitleInput.name);
    }*/
}
