using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public struct wire
{
    private bool Ishand;
    private Vector3 Hook_dir;
    

    

    //set
    public bool sethand(bool _hand)
    {
        Ishand = _hand;
        return Ishand;
    }
    public Vector3 setdir(Vector3 _dir)
    {
        Hook_dir = _dir;
        return Hook_dir;
    }
    

    //show
    public bool showhand()
    {
        return Ishand;
    }
    public Vector3 showdir()
    {
        return Hook_dir;
    }
   

};

public class WireSystem : MonoBehaviour {
    const float wiremove = 20.0f;
    const float wirestop = 0.0f;
    public static short srtColflag = 0;// 1 =  obj, 2 = wall
    public static bool bShootflag = false;//발사체크
    static public Transform wiretr;//와이어 위치

 

    static public wire hook = new wire();
    
    

    // Use this for initialization
    void Start () {
        wiretr = GetComponent<Transform>();
        hook.sethand(false);
    }
	
	// Update is called once per frame
	void Update () {
        hook.sethand(true);
        hook.setdir(CubeCtrl.wiredir_Keyboard(CubeCtrl.iDirnum));
        if (bShootflag)
        {
            if (srtColflag == 0)
            {
                shoot(hook.showdir(), wiremove);
            }
            //wireshoot(hook.showdir(), wirestop);

        }//발사 코드
        else if (!bShootflag)
        {
            HookSystem.fixjoint.connectedBody = null;
            HookSystem.hngjoint.connectedBody = null;
            wiretr.transform.position = CubeCtrl.tr.position;
        }


        if (srtColflag == 1)
        {
            if (Input.GetKey(KeyCode.DownArrow))
            {
                if (CubeCtrl.tr.position.x > wiretr.position.x)
                {
                    wiretr.transform.Translate(OperateHookToPlayer().normalized * wiremove * Time.deltaTime);
                }
                else
                    wiretr.transform.Translate(-OperateHookToPlayer().normalized * wiremove * Time.deltaTime);
            }

        }//후크반환

        if (srtColflag == 2)
        {
            if (Input.GetKey(KeyCode.UpArrow))
            {

                CubeCtrl.tr.Translate((wiretr.transform.position - CubeCtrl.tr.position).normalized *
                    movescript.fMoveSpeed * Time.deltaTime, Space.Self);
                Debug.Log("click");
            }
            if (Input.GetKey(KeyCode.DownArrow))
            {

                CubeCtrl.tr.Translate((CubeCtrl.tr.position - wiretr.transform.position).normalized *
                    movescript.fMoveSpeed * Time.deltaTime, Space.Self);
                Debug.Log("click");
            }
        }//후크반환
        

        Debug.Log(hook.showdir());
    }
    
    private void OnTriggerStay(Collider col)
    {

        if (bShootflag)
        {
            if (col.tag == "Object")
            {
                srtColflag = 1;
                wiretr.transform.position = col.transform.position;
                HookSystem.fixjoint.connectedBody = col.attachedRigidbody;
            }
            if (col.tag == "Wall")
            {
                srtColflag = 2;
                HookSystem.hngjoint.connectedBody = col.attachedRigidbody;
                wiretr.transform.position = col.transform.position;
            }

        }
        else { srtColflag = 0; }

    }

    static public void shoot(Vector3 _dir, float speed)
    {
        wiretr.transform.Translate(_dir.normalized * speed * Time.deltaTime);
        
    }

    static public Vector3 OperateHookToPlayer()
    {
        if (CubeCtrl.tr.position.x > wiretr.position.x)
        {
            return CubeCtrl.tr.position - wiretr.position;
        }
        else
            return wiretr.position - CubeCtrl.tr.position;
    }

    

    void renderer() { }

    
}
