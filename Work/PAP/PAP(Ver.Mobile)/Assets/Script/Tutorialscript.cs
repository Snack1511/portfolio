using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tutorialscript : MonoBehaviour {

    public GameObject[] Tuto = new GameObject[7];
    int index = 0;
	// Use this for initialization
	void Start () {
        Tuto = GameObject.FindGameObjectsWithTag("Tutorial");
        for (int i = 0; i < Tuto.Length; i++)
        {
            Tuto[i].SetActive(false);
        }
        Tuto[index].SetActive(true);
	}
	// Update is called once per frame
	void Update () {
        if (index < 0)
        {
            index = 0;
        }
        if (index > 7)
        {
            index = 7;
        }
        Debug.Log(index);
	}

    public void ClickNext()
    {
        Tuto[index].gameObject.SetActive(false);
        index++;
        Tuto[index].gameObject.SetActive(true);
    }

    public void ClickPrev()
    {
        Tuto[index].gameObject.SetActive(false);
        index--;
        Tuto[index].gameObject.SetActive(true);
    }

    
}
