using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Slime : MonoBehaviour {
	
	private Vector2 dir;
	private JoyStick joystick;
    

	private float fSlimeSpeed;
    
    public static int iCollectResource;
    Transform tTr;
    int MaxCollect = 5;//최대개수 이용해서 그 이상 못먹게
    public float attackDist = 2.0f;//사정거리

    public static Module mod = new Module(false);//모듈변수

    public static bool moveflag = true;
    public static bool attackedflag = false;






    private void Awake()
    {
        
    }
    // Use this for initialization
    void Start () {
        joystick = GameObject.Find("StickBg").GetComponent<JoyStick>();
        iCollectResource = 0;
        fSlimeSpeed = 5f;
        tTr = GetComponent<Transform>();
        FolliowCam.tTargetTr = tTr;


        
	}


	// Update is called once per frame
	void Update () {
        SlimeSize();
		HandleInput();
        if (PlayerMove.mod.CheckMod())
        {
            GameObject.Find("Canvas").transform.Find("ModuleArrow").gameObject.SetActive(false);
            GameObject.Find("Canvas").transform.Find("ResourceArrow").gameObject.SetActive(true);
        }
        Keyboard();
        UnActiveEArrow();
    }

	void FixedUpdate () {
        if (!attackedflag)
        {
            if (moveflag)
            {

                Move(tTr, dir);
                
            }
            else
            {
                attackedflag = false;
                joystick.Anim.SetBool("IsAttacked", false);
            }
        }
        
        

    }

    void OnTriggerEnter2D(Collider2D col)
    {
        if (PlayerMove.mod.CheckMod())
        {
            if (iCollectResource < MaxCollect)
            {
                if (col.gameObject.tag == "Resource")
                {
                    SoundMgr.instance.GetResSound();
                    iCollectResource++;
                    fSlimeSpeed -= 0.5f;
                    if (fSlimeSpeed == 0.0f)
                    {
                        fSlimeSpeed = 0.5f;
                        
                    }
                    //수집한 자원의 태그를 Untagged로 변경
                    col.gameObject.tag = "Untagged";
                    GameObject.Find("ResourceFactory").GetComponent<RFscript>().maxCount--;


                }
            }
        }
        if (!PlayerMove.mod.CheckMod())
        {
            if (!mod.Carry)
            {
                if (col.gameObject.name == "Engine(Clone)")
                {
                    if (!PlayerMove.mod.Engine)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Engine = true;
                        mod.Carry = true;
                    }
                }
                if (col.gameObject.name == "Frame(Clone)")
                {
                    if (!PlayerMove.mod.Frame)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Frame = true;
                        mod.Carry = true;
                    }
                }
                if (col.gameObject.name == "Gear(Clone)")
                {
                    if (!PlayerMove.mod.Gear)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Gear = true;
                        mod.Carry = true;
                    }
                }
                if (col.gameObject.name == "Wheel(Clone)")
                {
                    if (!PlayerMove.mod.Wheel)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Wheel = true;
                        mod.Carry = true;
                    }
                }
                if (col.gameObject.name == "Reacter(Clone)")
                {
                    if (!PlayerMove.mod.Reacter)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Reacter = true;
                        mod.Carry = true;
                    }
                }
            }
        }
        if (col.gameObject.tag == "Player") {
            //PlayerMove.iResource += iCollectResource;
            //iCollectResource = 0;
            fSlimeSpeed = 5f;

        }
        if (col.gameObject.tag == "PAttMotion")
        {
            attackedflag = true;
            joystick.Anim.SetBool("IsAttacked", true);
        }

    }



    void SlimeSize() {
        float fSizeValue = iCollectResource;
        if (iCollectResource <= 1) {
            tTr.localScale = new Vector3(1.0f, 1.0f, 0.0f);

        }
        else{
            tTr.localScale = new Vector3(fSizeValue/2, fSizeValue/2, 0.0f);
        }
        
    }

	void HandleInput() {
		dir = GetDir ();
	}

	public Vector2 GetDir() {
		float fHorizontal = joystick.Horizontal ();
		float fVertical = joystick.Vertical ();

		Vector2 _dir = new Vector2 (fHorizontal, fVertical).normalized;

		return _dir;
	}

	public void Move(Transform tr, Vector2 dir)
	{
		tr.Translate (dir*fSlimeSpeed*Time.deltaTime);
        tr.position = new Vector3(
                                         Mathf.Clamp(tr.position.x, -24.5f, 24.5f),
                                         Mathf.Clamp(tr.position.y, -9.0f, 3.5f), 0);

        

    }

    public void UnActiveEArrow()
    {
        Vector2 PlayerPos = tTr.position;
        Vector2 EnemyPos = GameObject.Find("EnemySlime").GetComponent<Transform>().position;
        float Dist = Vector2.Distance(PlayerPos, EnemyPos);
        

        if (Dist < 3.0f)
        {
            GameObject.Find("Canvas").transform.Find("EArrow").gameObject.SetActive(false);
        }
        else if (Dist >= 3.0f)
        {
            GameObject.Find("Canvas").transform.Find("EArrow").gameObject.SetActive(true);
        }
    }

    public void UnActiveTArrow()
    {
        Vector2 PlayerPos = tTr.position;
        Vector2 EnemyPos = GameObject.Find("player1").GetComponent<Transform>().position;
        float Dist = Vector2.Distance(PlayerPos, EnemyPos);


        if (Dist < 3.0f)
        {
            GameObject.Find("Canvas").transform.Find("TrainArrow").gameObject.SetActive(false);
        }
        else if (Dist >= 3.0f)
        {
            GameObject.Find("Canvas").transform.Find("TrainArrow").gameObject.SetActive(true);
        }
    }



    void Keyboard()
    {
        if (Input.GetKeyDown(KeyCode.A))
        {
            joystick.Anim.SetInteger("IsDirection", -1);
        }
        if (Input.GetKeyDown(KeyCode.D))
        {
            joystick.Anim.SetInteger("IsDirection", 1);
        }
    }

}
