using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class CubeCtrl : MonoBehaviour  {


    public static Transform tr;
    private Renderer rend;
    public static int iDirnum = 0;
    
    // Use this for initialization
    void Start () {
        tr = GetComponent<Transform>();
        tr.position = Vector3.up;
        
        renderer();
	}
	
	// Update is called once per frame
	void Update () {
        movescript.PlayerMovePos(tr);
        Dir_num();

        if (Input.GetKeyDown(KeyCode.Z))
        {
            WireSystem.bShootflag = !WireSystem.bShootflag;
        }//발사
    }

 
    private void OnTriggerStay(Collider col)
    {
        if (col.tag == "Portal")
        {
            if (Input.GetKeyDown(KeyCode.UpArrow))
            {
                Debug.Log("Portal");
            }
        }
    }



    public static void Dir_num()
    {

        if (Input.GetKey(KeyCode.D))
        {
            if (Input.GetKey(KeyCode.W))
            {
                iDirnum = 2;
            }
            else if (Input.GetKey(KeyCode.S))
            {
                iDirnum = 8;
            }
            else
            {
                iDirnum = 1;
            }
        }

        if (Input.GetKey(KeyCode.W))
        {
            if (Input.GetKey(KeyCode.D))
            {
                iDirnum = 2;
            }
            else if (Input.GetKey(KeyCode.A))
            {
                iDirnum = 4;
            }
            else
            {
                iDirnum = 3;
            }

        }

        if (Input.GetKey(KeyCode.A))
        {
            if (Input.GetKey(KeyCode.W))
            {
                iDirnum = 4;
            }
            else if (Input.GetKey(KeyCode.S))
            {
                iDirnum = 6;
            }
            else
            {
                iDirnum = 5;
            }
        }
        
        if (Input.GetKey(KeyCode.S))
        {
            if (Input.GetKey(KeyCode.D))
            {
                iDirnum = 8;
            }
            else if (Input.GetKey(KeyCode.A))
            {
                iDirnum = 6;
            }
            else
            {
                iDirnum = 7;
            }
        }
        
    }

    public static Vector3 wiredir_Keyboard(int n)
    {
        Vector3 dir = new Vector3();
        switch (n) {
            case 1:
                dir = new Vector3(Mathf.Cos(0.0f), Mathf.Sin(0.0f), 0);
                break;

            case 2:
                dir = new Vector3(Mathf.Cos(Mathf.PI*0.25f), Mathf.Sin(Mathf.PI * 0.25f), 0);
                break;

            case 3:
                dir = new Vector3(Mathf.Cos(Mathf.PI * 0.5f), Mathf.Sin(Mathf.PI * 0.5f), 0);
                break;

            case 4:
                dir = new Vector3(Mathf.Cos(Mathf.PI * 0.75f), Mathf.Sin(Mathf.PI * 0.75f), 0);
                break;

            case 5:
                dir = new Vector3(Mathf.Cos(Mathf.PI), Mathf.Sin(Mathf.PI), 0);
                break;

            case 6:
                dir = new Vector3(Mathf.Cos(Mathf.PI * 1.25f), Mathf.Sin(Mathf.PI * 1.25f), 0);
                break;

            case 7:
                dir = new Vector3(Mathf.Cos(Mathf.PI * 1.5f), Mathf.Sin(Mathf.PI * 1.5f), 0);
                break;

            case 8:
                dir = new Vector3(Mathf.Cos(Mathf.PI * 1.75f), Mathf.Sin(Mathf.PI * 1.75f), 0);
                break;
        }

        return dir;
    }

    void renderer()
    {
        rend = GetComponent<Renderer>();
        rend.material.SetColor("_Color", Color.red);
    }
}
