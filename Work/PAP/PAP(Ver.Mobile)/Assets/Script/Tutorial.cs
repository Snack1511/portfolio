using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tutorial : MonoBehaviour {

    public GameObject[] Tuto = new GameObject[7];

    int index = 0;

	// Use this for initialization
	void Start () {
        Tuto = GameObject.FindGameObjectsWithTag("Tutorial");
        for (int i = 0; i < Tuto.Length; i++)
        {
            Tuto[i].gameObject.SetActive(false);
        }
        Tuto[index].SetActive(true);
	}
	
	// Update is called once per frame
	void Update () {
        
        
	}

    public void NextPage()
    {
        SoundMgr.instance.PlaySound();
        Tuto[index].SetActive(false);

        index++;
        if (index > 6)
        {
            index = 6;
        }
        Tuto[index].SetActive(true);

    }

    public void PrevPage()
    {
        SoundMgr.instance.PlaySound();
        Tuto[index].SetActive(false);
        index--;
        if (index < 0)
        {
            index = 0;
        }
        Tuto[index].SetActive(true);
    }
}
