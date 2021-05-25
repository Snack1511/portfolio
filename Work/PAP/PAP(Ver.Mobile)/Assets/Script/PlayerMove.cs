using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour {
    public static Transform tTr;
    
	public static int iResource = 0;

    private RFscript rfscript;

    public bool attflag = false;


    public static Module mod = new Module(false);
    

    void Start () {
        //Slime.bControlflag = true;
		tTr = GetComponent<Transform> ();
        //RFscript 스크립트 할당
        rfscript = GameObject.Find("ResourceFactory").GetComponent<RFscript>();
        
        StartCoroutine(ConsumptionResource());
        
    }

    IEnumerator ConsumptionResource()
    {
        if (iResource > 0)
        {
            iResource--;
            
        }
        yield return new WaitForSeconds(10f);
        
        StartCoroutine(ConsumptionResource());

    }

    // Update is called once per frame
    void Update () {
		tTr.Translate (GameManager.fDir*Time.deltaTime, 0.0f, 0.0f, Space.Self);
        
    }

    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag == "EnemyG")
        {
            GameManager gm = GameObject.Find("GameManager").GetComponent<GameManager>();
            gm.winflag = -1;
        }
        if (col.gameObject.tag == "Collector")
        {
            if (Slime.mod.Carry)
            {
                if (!mod.CheckMod())
                {
                    if (Slime.mod.Engine)
                    {
                        mod.Engine = true;
                    }
                    if (Slime.mod.Frame)
                    {

                        mod.Frame = true;

                    }
                    if (Slime.mod.Gear)
                    {

                        mod.Gear = true;

                    }
                    if (Slime.mod.Wheel)
                    {

                        mod.Wheel = true;

                    }
                    if (Slime.mod.Reacter)
                    {

                        mod.Reacter = true;

                    }
                    Slime.mod.Carry = false;
                    SoundMgr.instance.collectmodsound();
                }
                
                
            }
            else if(Slime.iCollectResource > 0)
            {
                SoundMgr.instance.collectressound();
                iResource += Slime.iCollectResource;
                Slime.iCollectResource = 0;
            }
        }

    }


    void GameOver() {
        //RFscript의 isGameOver변숫값을 변경해 자원 출현 중지
        rfscript.isGameOver = true;
    }

    void changeres()
    {
        if (Input.GetKeyDown(KeyCode.Q))
        {
            iResource = 30;
        }
        if (Input.GetKeyDown(KeyCode.W))
        {
            iResource = 50;
        }
        if (Input.GetKeyDown(KeyCode.E))
        {
            iResource = 80;
        }
        if (Input.GetKeyDown(KeyCode.R))
        {
            iResource = 100;
        }
    }

}
