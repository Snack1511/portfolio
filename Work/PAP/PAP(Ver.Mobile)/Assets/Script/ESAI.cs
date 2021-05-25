using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ESAI : MonoBehaviour {


    public enum AIstate
    {
        idle,
        attack,
        collect,
        comeback,
        trace, 
        module
    };
   


    public AIstate aistate = AIstate.idle;


    //자원흡수 변수
    int iCollectResource = 0;
    int Collectable = 1;


    //이동 변수
    private Vector2 dir;//방향
    private float fSlimeSpeed;//이속
    Transform tTr;//자신
    public Transform PTrainTr;//기차
    public Transform ETrainTr;//기차
    public Transform playerslimeTr;//상대슬라임
    public RFscript rfscript;//자원

    
    //공격 변수
    public float attackDist = 1.0f;//사정거리
    bool attackedflag = false;

    //모듈변수
    Module mod = new Module(false);

    //애니메이션 변수
    Animator Anim;


    // Use this for initialization
    void Start()
    {

        fSlimeSpeed = 4f;
        tTr = gameObject.GetComponent<Transform>();
        playerslimeTr = GameObject.FindGameObjectWithTag("Collector").GetComponent<Transform>();
        PTrainTr = GameObject.FindGameObjectWithTag("Player").GetComponent<Transform>();
        ETrainTr = GameObject.FindGameObjectWithTag("Enemy").GetComponent<Transform>();
        rfscript = GameObject.Find("ResourceFactory").GetComponent<RFscript>();
        Anim = GetComponent<Animator>();

        StartCoroutine(AICheckState());
        StartCoroutine(AIAction());

    }


    IEnumerator AICheckState()
    {
        while (true)
        {
            yield return new WaitForSeconds(0.2f);
            if (!attackedflag)
            {
                if (mod.CheckMod())
                {
                    float Pdist = Vector2.Distance(playerslimeTr.position, tTr.position);
                    float Tdist = Vector2.Distance(PTrainTr.position, playerslimeTr.position);
                    if (PlayerMove.iResource >= 0 && PlayerMove.iResource < 30)
                    {
                        aistate = AIstate.collect;//1자원흡수
                        Debug.Log("pattern1");
                        Collectable = 1;
                    }

                    else if (PlayerMove.iResource >= 30 && PlayerMove.iResource < 50)
                    {
                        aistate = AIstate.collect;//2~3자원흡수
                        Debug.Log("pattern2");
                        Collectable = 2;
                    }

                    else if (PlayerMove.iResource >= 50 && PlayerMove.iResource < 80)
                    {
                        Debug.Log("pattern3");
                        if (Pdist <= attackDist)
                        {
                            aistate = AIstate.attack;
                            Anim.SetBool("IsAtt", false);
                            Anim.SetInteger("IsDirection", -1);
                            //attflag = true;
                            //Debug.Log("att");
                        }
                        else
                            //Debug.Log("in");
                            aistate = AIstate.trace;


                    }

                    else if (PlayerMove.iResource >= 80)
                    {
                        Debug.Log("pattern4");
                        if (Slime.iCollectResource <= 1)
                        {
                            if (Pdist <= attackDist)
                            {
                                aistate = AIstate.attack;
                                Anim.SetBool("IsAtt", false);
                                Anim.SetInteger("IsDirection", -1);

                            }
                            else
                                aistate = AIstate.trace;
                        }
                        if (Slime.iCollectResource == 2)
                        {
                            aistate = AIstate.collect;
                            Collectable = 3;
                        }
                        if (Slime.iCollectResource == 3)
                        {
                            if (Pdist <= attackDist)
                            {
                                aistate = AIstate.attack;
                                Anim.SetBool("IsAtt", false);
                                Anim.SetInteger("IsDirection", -1);
                            }
                            else
                                aistate = AIstate.trace;

                        }
                        if (Slime.iCollectResource > 4)
                        {

                            if (Tdist <= attackDist + 2.0f)
                            {

                                if (Pdist <= attackDist)
                                {
                                    aistate = AIstate.attack;
                                    Anim.SetBool("IsAtt", false);
                                    Anim.SetInteger("IsDirection", -1);

                                }
                                else
                                    aistate = AIstate.trace;
                            }
                            else
                                aistate = AIstate.collect;
                            Collectable = (int)Random.Range(3.5f, 5.4f);

                        }

                    }
                }
                else
                {

                    aistate = AIstate.module;
                    if (mod.Carry)
                    {
                        aistate = AIstate.comeback;
                    }
                }
            }
            else
            {
                Anim.SetBool("IsAttacked", true);
                Anim.SetBool("IsAttacked", false);
                attackedflag = false;
            }
        }

    }

    IEnumerator AIAction()
    {
        
        while (true)
        {
            
            switch (aistate)
            {
                //idle
                case AIstate.idle:
                    
                    break;

                //attack
                case AIstate.attack:
                    Anim.SetBool("IsAtt", true);
                    SoundMgr.instance.AttEffectSound();

                    break;

                //collect
                case AIstate.collect:
                    if (Collectable > iCollectResource)
                    {
                        SetDir(GetResDir());
                    }
                    
                    if (Collectable <= iCollectResource)
                    {
                        aistate = AIstate.comeback;
                    }
                    Move(tTr, dir);
                    break;

                case AIstate.comeback:
                    SetDir(ETrainTr.position);
                    Move(tTr, dir);
                    break;

                case AIstate.trace:
                    SetDir(playerslimeTr.position);
                    Move(tTr, dir);
                    break;

                case AIstate.module:
                    SetDir(GetModDIr());
                    

                    Move(tTr, dir);
                    
                    break;
            }
            yield return null;
        }
    }


    // Update is called once per frame
    void Update()
    {
        SlimeSize();

    }

    

    void OnTriggerEnter2D(Collider2D col)
    {
        
        if (mod.CheckMod())
        {
            if (Collectable > iCollectResource)
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
                    rfscript.maxCount--;
                }
            }
        }

        if (!mod.CheckMod())
        {
            
            if (!mod.Carry)
            {

                if (col.gameObject.name == "Engine(Clone)")
                {
                    if (!mod.Engine)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Engine = true;
                        mod.Carry = true;
                    }
                }
                if (col.gameObject.name == "Frame(Clone)")
                {
                    if (!mod.Frame)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Frame = true;
                        mod.Carry = true;
                    }
                }
                if (col.gameObject.name == "Gear(Clone)")
                {
                    if (!mod.Gear)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Gear = true;
                        mod.Carry = true;
                    }
                }
                if (col.gameObject.name == "Wheel(Clone)")
                {
                    if (!mod.Wheel)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Wheel = true;
                        mod.Carry = true;
                    }
                }
                if (col.gameObject.name == "Reacter(Clone)")
                {
                    if (!mod.Reacter)
                    {
                        SoundMgr.instance.modsound();
                        Destroy(col.gameObject);
                        mod.Reacter = true;
                        mod.Carry = true;
                    }
                }
            }
        }

        if (col.gameObject.tag == "Enemy")
        {

            if (!mod.CheckMod())
            {
                mod.Carry = false;
                SoundMgr.instance.collectmodsound();
            }
            else
            {
                PlayerMove2.iResource += iCollectResource;
                iCollectResource = 0;
                fSlimeSpeed = 4f;
                SoundMgr.instance.collectressound();
            }
        }

        if (col.gameObject.tag == "PAttMotion")
        {
            attackedflag = true;
        }
    }



    void SlimeSize()
    {
        float fSizeValue = iCollectResource;
        if (iCollectResource <= 1)
        {
            tTr.localScale = new Vector3(1.0f, 1.0f, 0.0f);

        }
        else
        {
            tTr.localScale = new Vector3(fSizeValue / 2, fSizeValue / 2, 0.0f);
        }

    }


    void SetDir(Vector2 pos)
    {
        dir = GetDir(pos);
        Anim.SetBool("IsMove", true);
        if (dir.x > 0)
        {
            Anim.SetInteger("IsDirection", 1);
        }
        else if (dir.x <= 0)
        {
            Anim.SetInteger("IsDirection", -1);
        }
    }//변수dir에 GetDir에서 받은 방향 넣어줌


    
    Vector2 GetDir(Vector2 pos)
    {
        float fHorizontal = pos.x - tTr.position.x;
        float fVertical = pos.y - tTr.position.y;

        Vector2 _dir = new Vector2(fHorizontal, fVertical).normalized;
        return _dir;
    }//_dir에 tr의 x값과 y값을 이용한 방향벡터를 넣어준다


    public void Move(Transform tr, Vector2 dir)
    {
        tr.Translate(dir * fSlimeSpeed * Time.deltaTime);
        tr.position = new Vector3( Mathf.Clamp(tr.position.x, -24.5f, 24.5f),
                                   Mathf.Clamp(tr.position.y, -9.0f, 3.5f), 0);


    }



    Vector2 GetResDir()
    {
        Vector2 _dir;
        float min = 100.0f;
        int index = 0;
        for (int i = 0; i < rfscript.maxCount; i++)
        {
            
            float dist = Vector2.Distance(rfscript.resourcepool[i].transform.position, tTr.position);
            if (dist < min)
            {
                min = dist;
                index = i;
            }
            

        }
        
        _dir = rfscript.resourcepool[index].transform.position;
        return _dir;


    }//자원 스폰장소의 Transform리턴

    Vector2 GetModDIr()
    {
        Vector2 _dir;
        float min = 100.0f;
        float dist;
        int index = 0;
        GameObject[] Modules = GameObject.FindGameObjectsWithTag("Module");
        for (int i = 0; i < Modules.Length; i++)
        {

            
            dist = Vector2.Distance(Modules[i].GetComponent<Transform>().position, tTr.position);
            if (dist < min)
            {
                if (checkmod(Modules[i]))
                {
                    min = dist;
                    index = i;
                }
            }
            if (!Modules[i].activeInHierarchy)
            {
                GetModDIr();
            }
            
        }
        _dir = Modules[index].GetComponent<Transform>().position;
        

        return _dir;
    }


    bool checkmod(GameObject obj)
    {
        bool flag = false;

        if (obj.name == "Engine(Clone)")
        {
            if (!mod.Engine)
            {
                flag = true;
            }
        }
        if (obj.name == "Frame(Clone)")
        {
            if (!mod.Frame)
            {
                flag = true;
            }
        }
        if (obj.name == "Gear(Clone)")
        {
            if (!mod.Gear)
            {
                flag = true;
            }
        }
        if (obj.name == "Wheel(Clone)")
        {
            if (!mod.Wheel)
            {
                flag = true;
            }
        }
        if (obj.name == "Reacter(Clone)")
        {
            if (!mod.Reacter)
            {
                flag = true;
            }
        }

        return flag;
    }
    

}
