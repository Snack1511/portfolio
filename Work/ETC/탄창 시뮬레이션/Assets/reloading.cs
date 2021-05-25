using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;




public class reloading : MonoBehaviour {

    public static SortedList<int, int> slBullet = new SortedList<int, int>();
    
    
    public static int iResultBullet = 0;
    

    // Use this for initialization
    void Start() {
            
        }
	
	// Update is called once per frame
	void Update () {
        /*
        if (Input.GetKeyDown(KeyCode.Z)) {
            if (iResultBullet > 0) {
                iResultBullet--;
                Debug.Log("Remain : " + iResultBullet);
                Debug.Log("Elements : " + slBullet[iResultBullet]);
            }
            else
                Debug.Log("please reload");
        }//발사
        */
        
        Elereload();
        
        if (Input.GetKeyDown(KeyCode.Return)) {
            SceneManager.LoadScene("PlayView");
        }//선택완료


        //if (Input.GetKeyDown(KeyCode.R)) {
        //    iResultBullet = 15;
        //    Debug.Log("reload complete");
        //}재장전
	}

    void Elereload() {
        if (Input.GetKey(KeyCode.R))
        {
            if (iResultBullet < 15)
            {
                if (Input.GetKeyDown(KeyCode.LeftArrow))
                {
                    Debug.Log("FireChoose");
                    slBullet.Add(iResultBullet, 1);
                    iResultBullet++;
                    Debug.Log(iResultBullet);

                }
                if (Input.GetKeyDown(KeyCode.RightArrow))
                {

                    Debug.Log("IceChoose");
                    slBullet.Add(iResultBullet, 2);
                    iResultBullet++;
                    Debug.Log(iResultBullet);

                }
                if (Input.GetKeyDown(KeyCode.UpArrow))
                {

                    Debug.Log("EarthChoose");
                    slBullet.Add(iResultBullet, 3);
                    iResultBullet++;
                    Debug.Log(iResultBullet);

                }
                if (Input.GetKeyDown(KeyCode.DownArrow))
                {
                    Debug.Log("WindChoose");
                    slBullet.Add(iResultBullet, 4);
                    iResultBullet++;
                    Debug.Log(iResultBullet);

                }
            }

        }//속성선택
    }
}
