using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameRoot : MonoBehaviour {

    int maxbullet = 6;
    int resultbullet;
    static public int minusbullet;
    int remainbullet;
    float timevalue = 0.5f;
    float nextime = 0.0f;
    

    public struct bullet
    {
        private int element;
        //private float bullet;
        private float inc_dmg;
        




        public int setelement(int _ele)
        {
            element = _ele;
            return element;
        }
        /*public int setbullet(int _ele)
        {
            element = _ele;
            return element;
        }*/
        public float setdmg()
        {
            if (element != 0)
            {
                inc_dmg = 0.5f;
                return inc_dmg;

            }
            return inc_dmg;
        }

        public int showelement()
        {
            return element;
        }
        /*public int showbullet()
        {
            return element;
        }*/
        public float showdmg()
        {
        
            return inc_dmg;
        }

    };
    bullet[] bull = new bullet[4];

    // Use this for initialization
    void Start () {
        
        //0 = none
        //1 = fire
        //2 = ice
        minusbullet = 1;
        remainbullet = 0;
        
	}

    // Update is called once per frame
    //Time.frameCount/60 => 초 계산 공식 ver unity
	void Update () {
        
        resultbullet = maxbullet - minusbullet;
        reload();
        //Debug.Log(remainbullet);
        /*if (Input.GetKeyDown(KeyCode.Z))
        {
            nextime = Time.time + timevalue * 20;
            if (remainbullet > 0)
            {
                
                if(Time.time > nextime) {
                    remainbullet--;
                }
            }
            else
                Debug.Log("not enough bullet");
                //https://docs.unity3d.com/kr/current/ScriptReference/Time-time.html 참조
        }*/

    }

    void reload()
    {
        if (remainbullet <= resultbullet)
        {
            if (Input.GetKey(KeyCode.LeftShift))
            {
                if (Input.GetKeyDown(KeyCode.W))
                {
                    bull[remainbullet].setelement(1);
                    remainbullet++;
                    Debug.Log("inputfire");
                }
                if (Input.GetKeyDown(KeyCode.S))
                {
                    bull[remainbullet].setelement(2);
                    remainbullet++;
                    Debug.Log("inputice");
                }
                if (Input.GetKeyDown(KeyCode.D))
                {
                    bull[remainbullet].setelement(3);
                    remainbullet++;
                    Debug.Log("inputwind");
                }
                if (Input.GetKeyDown(KeyCode.A))
                {
                    bull[remainbullet].setelement(4);
                    remainbullet++;
                    Debug.Log("inputearth");
                }
            }
        }
    }

}
