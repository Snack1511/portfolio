using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attack : MonoBehaviour {

    //private int iIndex = reloading.iResultBullet;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        
        if (Input.GetKeyDown(KeyCode.Z))
        {
            if (reloading.iResultBullet > 0)
            {
                reloading.iResultBullet--;
                Debug.Log("Remain : " + reloading.iResultBullet);
                Debug.Log("ElementsNum : " + reloading.slBullet[reloading.iResultBullet]);
                printElement(reloading.slBullet[reloading.iResultBullet]);
                
                reloading.slBullet.Remove(reloading.iResultBullet);
                
            }
            else
                Debug.Log("please reload");
        }
        if (Input.GetKeyDown(KeyCode.X))
        {
            Debug.Log("FireChoose");
            reloading.slBullet.Add(reloading.iResultBullet, 1);
            reloading.iResultBullet++;
            Debug.Log(reloading.iResultBullet);
        }
    }


    void printElement(int _index)
    {
        switch (_index)
        {
            case 1:
                Debug.Log("Elements : Fire");
                break;
            case 2:
                Debug.Log("Elements : Ice");
                break;
            case 3:
                Debug.Log("Elements : Wind");
                break;
            case 4:
                Debug.Log("Elements : Earth");
                break;
        }

    }
}


