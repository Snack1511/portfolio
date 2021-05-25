using UnityEngine;
using System.Collections;

public class gameroot : MonoBehaviour {
    public static int flag = 0, a = 0;
    public static uint score = 0, OnOff = 0, PR = 0, PG = 0, PB = 0;
    public GameObject enemy_R, enemy_G, enemy_B, change_R, change_G, change_B;
    float Ecosx = 20, Cposx = 2, Eposy = 0, Cposy = 0;
    public static bool EdeadFlag = false, PdeadFlag = false;
    void Start () {
    }
	
	void Update () {

        Distinguishflag(flag);

        if (Input.GetKey(KeyCode.Return))
        {
            Application.LoadLevel("title");
            Debug.Log("이건가..");
        }
        if (PdeadFlag == true) {
            Application.LoadLevel("GameOver");
            savedata();
            PdeadFlag = false;
        }
    }
    void Distinguishflag(int flag) {
        if (flag == 1)
        {
            
            Eposy = Random.Range(-1, 2);
            Vector2 PositionValueR = new Vector2(Ecosx += 4, Eposy) * 2.0f;
            GameObject Summon_enemy_R = (GameObject)Instantiate(enemy_R, PositionValueR, Quaternion.identity);
            
            Eposy = Random.Range(-1, 2);
            Vector2 PositionValueG = new Vector2(Ecosx += 8, Eposy) * 2.0f;
            GameObject Summon_enemy_G = (GameObject)Instantiate(enemy_G, PositionValueG, Quaternion.identity);
            
            Eposy = Random.Range(-1, 2);
            Vector2 PositionValueB = new Vector2(Ecosx += 12, Eposy) * 2.0f;
            GameObject Summon_enemy_B = (GameObject)Instantiate(enemy_B, PositionValueB, Quaternion.identity);
            System.GC.Collect();
            flag = 0;
        }

        if (flag == 2)
        {
            Eposy = Random.Range(-1, 2);
            Vector2 PositionValueG = new Vector2(Ecosx += 4, Eposy) * 2.0f;
            GameObject Summon_enemy_G = (GameObject)Instantiate(enemy_G, PositionValueG, Quaternion.identity);
            
            Eposy = Random.Range(-1, 2);
            Vector2 PositionValueB = new Vector2(Ecosx += 8, Eposy) * 2.0f;
            GameObject Summon_enemy_B = (GameObject)Instantiate(enemy_B, PositionValueB, Quaternion.identity);
            
            Eposy = Random.Range(-1, 2);
            Vector2 PositionValueR = new Vector2(Ecosx += 12, Eposy) * 2.0f;
            GameObject Summon_enemy_R = (GameObject)Instantiate(enemy_R, PositionValueR, Quaternion.identity);
            System.GC.Collect();
            flag = 0;
        }

        if (flag == 3)
        {
            
            Eposy = Random.Range(-1, 2);
            Vector2 PositionValueB = new Vector2(Ecosx += 4, Eposy) * 2.0f;
            GameObject Summon_enemy_B = (GameObject)Instantiate(enemy_B, PositionValueB, Quaternion.identity);
            
            Eposy = Random.Range(-1, 2);
            Vector2 PositionValueR = new Vector2(Ecosx += 8, Eposy) * 2.0f;
            GameObject Summon_enemy_R = (GameObject)Instantiate(enemy_R, PositionValueR, Quaternion.identity);
           
            Eposy = Random.Range(-1, 2);
            Vector2 PositionValueG = new Vector2(Ecosx += 12, Eposy) * 2.0f;
            GameObject Summon_enemy_G = (GameObject)Instantiate(enemy_G, PositionValueG, Quaternion.identity);
            System.GC.Collect();
            flag = 0;

        }
    }
    void savedata() {
        int a = 0;
        a = (int)score;
        PlayerPrefs.SetInt(TitleScript.name, a);
    }
    
   
}
