using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class GameManager : MonoBehaviour {


	public static float fDir = 0;

    public GameObject P1Text;
    public GameObject P2Text;
    public int winflag = 0;

    public GameObject Gear;
    public GameObject Wheel;
    public GameObject Frame;
    public GameObject Engine;
    public GameObject Reacter;

    //Text countext;

    bool notplaytrainsound = true;


    // Use this for initialization

    void Start () {
        SetInit();
        
    }

    /*IEnumerator Waiting()
    {
        int Startcount = 3;
        countext.text = Startcount.ToString();
        //GameObject.Find("Canvas").
        yield return new WaitForSeconds(1.0f);
    }*/

    // Update is called once per frame
    void Update() {


        fDir = (PlayerMove2.iResource - PlayerMove.iResource)*0.1f;
        P1Text.GetComponent<Text>().text = "Resource : " + PlayerMove.iResource;
        P2Text.GetComponent<Text>().text = "Resource : " + PlayerMove2.iResource;
        if (notplaytrainsound)
        {
            if (PlayerMove.iResource > 0|| PlayerMove2.iResource > 0)
            {
                SoundMgr.instance.soundchangeflag = 2;
                SoundMgr.instance.updateout = false;
                notplaytrainsound = false;
            }
        }
        

        if (winflag == -1)
        {
            GameObject.Find("Canvas").transform.Find("Winner").gameObject.SetActive(true);
            GameObject.Find("Winner").GetComponent<Text>().color = Color.red;
            GameObject.Find("Winner").GetComponent<Text>().text = "Enemy Win";
            

        }
        else if (winflag == 1)
        {
            GameObject.Find("Canvas").transform.Find("Winner").gameObject.SetActive(true);
            GameObject.Find("Winner").GetComponent<Text>().color = Color.blue;
            GameObject.Find("Winner").GetComponent<Text>().text = "Player Win";

        }
        
        

    }
    void SetInit()
    {
        Transform[] Tr;
        Tr = GameObject.Find("SpawnPoint").GetComponentsInChildren<Transform>();
        Vector2[] pos = new Vector2[10];
        int[] idx = new int[10];
        for (int i = 0; i < 10; i++)
        {
            pos[i] = (Vector2)Tr[i % 5].position + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f));
        }
        for (int i = 0; i < 10; i++)
        {
            idx[i] = Random.Range(0, pos.Length);
            for (int j = 0; j < i; j++)
            {
                if (idx[i] == idx[j])
                {
                    idx[i] = (idx[i] + 1) % 10;
                }
            }
        }
        Instantiate(Gear, pos[idx[0]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);
        Instantiate(Wheel, pos[idx[1]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);
        Instantiate(Frame, pos[idx[2]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);
        Instantiate(Engine, pos[idx[3]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);
        Instantiate(Reacter, pos[idx[4]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);
        Instantiate(Gear, pos[idx[5]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);
        Instantiate(Wheel, pos[idx[6]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);
        Instantiate(Frame, pos[idx[7]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);
        Instantiate(Engine, pos[idx[8]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);
        Instantiate(Reacter, pos[idx[9]] + new Vector2((int)Random.Range(-2.0f, 2.0f), (int)Random.Range(-2.0f, 2.0f)), Quaternion.identity);

    }

    











}
