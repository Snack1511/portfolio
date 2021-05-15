using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MapObj : MonoBehaviour
{
    GameObject[] children;
    int currentactive;
    public int nextactive;
    // Start is called before the first frame update
    void Start()
    {
        children = new GameObject[transform.childCount];
        for(int i = 0; i < transform.childCount; i++)
        {
            children[i] = transform.GetChild(i).gameObject;
            if (children[i].activeSelf) {
                currentactive = i;
                nextactive = currentactive;
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(nextactive != currentactive)
        {
            children[currentactive].SetActive(false);
            children[nextactive].SetActive(true);
            currentactive = nextactive;
        }
    }
}
