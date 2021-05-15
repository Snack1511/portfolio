using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor.Animations;
using UnityEngine.UI;
using Custom;
public class PlayerRender : MonoBehaviour
{
    Transform Tr;
    Slider Hpbar;
    GameObject PlayerFbx;
    Material Mat_Liquid, Mat_PlayerColor;
    MeshRenderer MRender;//플레이어별 색 할당용...?
    string MeshName, ColorName, Parent;
    //public bool CaculateHit;

    PlayerSet script;
    Control control;
    Player_Cal Calculate;

    public bool bHitflg;
    bool bDieflg;

    // Start is called before the first frame update
    private void Awake()
    {
        //StartCoroutine("StartCheck");
        Tr = GetComponent<Transform>();
        Hpbar = Tr.parent.GetChild(2).GetChild(0).GetComponent<Slider>();
        AttachScript();
        //SetFbx("fbx이름을 변수로 받음");
    }

    void Start()
    {
        Debug.Log("RenderStart");
        SetFbx(script.ModelName, script.ColorNum);
        name = transform.parent.name + "_Render";
        Parent = gameObject.transform.parent.name;
        ResetData();
        //AttachScript();
        //SetFbx("fbx이름을 변수로 받음");
        //SetRender(script.GetcurrentSchreme());
    }

    // Update is called once per frame
    void Update()
    {
        if (!Calculate.bDieflg)
        {
            /*if (!control.Anim_Throwflg)//!control.ThrowChargeflg)
            {
                Tr.rotation = Quaternion.AngleAxis(control.AimVal, Vector3.down);
                
            }*/
            Tr.rotation = Quaternion.AngleAxis(control.AimVal, Vector3.down);

            
        }
        if (bHitflg&&!Calculate.bDeadAnimEnd)//bHitflg가 Player_Cal내에서 동작을 처리하고 끝나버림
        {                     //가장 간단하게는 SetHitflg를 Update내에서 따로 처리하면 될거 같음
                              //Debug.Log(transform.parent.name + "Ouch!!!");
            Debug.Log("Hit");
            if (!bDieflg)
            {
                MatCal(script.GetPlayerData().HP);
            }
        }


    }

    /*private void OnTriggerEnter(Collider other)
    {
        
        if (other.tag == "Bullet")
        {
            Calculate.SetEnemy(other.GetComponent<Bullet>().Owner);
            Calculate.SetHitflg(true);
            MatCal();
            Debug.Log(transform.parent.name + "Ouch!!!");
        }
    }
    */
    /*IEnumerator StartCheck() {
        while (!GameManager.GM.Gamestartflg) {
            yield return new WaitForEndOfFrame();
        }
        
    }*/

    public void ResetData()
    {
        bHitflg = false;
        bDieflg = false;
        Hpbar.value = 0.9f;
        if (transform.childCount > 0)
        {

            transform.GetChild(0).GetComponent<Player_AnimControl>().ResetRotate();
        }
    }
    void AttachScript() {
        script = transform.parent.gameObject.GetComponent<PlayerSet>();
        control = transform.parent.gameObject.GetComponent<Control>();
        Calculate = transform.parent.gameObject.GetComponent<Player_Cal>();
    }

    void SetFbx(string _str, int n) {
        //string _str = "Ch_roundFlask";
        PlayerFbx = Instantiate(Resources.Load<GameObject>("Objects/"+ _str), Tr);
        //Fbx파일 불러오기


        PlayerFbx.transform.GetChild(0).GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material =
            new Material(Resources.Load<Material>("Materials/Player_Mat"));//Body->Flask->Bottle
        //불러온 파일의 유리부분에 유리 마테리얼 할당
        PlayerFbx.transform.GetChild(0).GetChild(0).GetChild(1).GetComponent<MeshRenderer>().material =
            new Material(Resources.Load<Material>("Materials/Cap_Mat"));

        Mat_Liquid = new Material(Resources.Load<Material>("Materials/Liquid_Mat"));
        //액체 로드 후 마테리얼 할당
        Mat_Liquid.SetFloat("_FillAmount", 0.2f);
        //할당한 마테리얼의 FillAmount값 초기화
        Color[] Colors = new Color[3];
        Colors = ColorFunction.SetColor(n);
        
        Mat_Liquid.SetColor("_Tint", Colors[2]);
        //Mat_Liquid.color = Colors[2];
        PlayerFbx.transform.GetChild(0).GetChild(0).GetChild(2).GetComponent<MeshRenderer>().material = Mat_Liquid;
        //할당한 마테리얼을 Liquid오브젝트에 할당
        var FootMat = new Material(Resources.Load<Material>("Materials/PlayerMat_Colored"));
        FootMat.SetColor("_Color", Colors[1]);
        var HandMat = new Material(Resources.Load<Material>("Materials/PlayerMat_Colored"));
        HandMat.SetColor("_Color", Colors[0]);
        PlayerFbx.transform.GetChild(1).GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material = HandMat;
        PlayerFbx.transform.GetChild(2).GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material = FootMat;
        PlayerFbx.transform.GetChild(3).GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material = HandMat;
        PlayerFbx.transform.GetChild(4).GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material = FootMat;

        PlayerFbx.transform.GetChild(0).GetChild(0).GetChild(2).gameObject.AddComponent<Wobble>();//Body->Flask -> Liquid
        //출렁임 효과 위한 스크립트 등록


        
        PlayerFbx.GetComponent<Animator>().runtimeAnimatorController =
            Resources.Load<AnimatorController>("Animators/Player_Animator");
        //Debug.Log(Resources.Load<Material>("Materials/Player_Mat"));
        //애니메이션 추가   Ch_roundFlask_Animator
        //PlayerFbx.GetComponent<Animator>().cullingMode = AnimatorCullingMode.CullUpdateTransforms;
        //PlayerFbx.GetComponent<Animator>().applyRootMotion = true;
        PlayerFbx.AddComponent<Player_AnimControl>();
        //애니메이션 재생위한 스크립트 추가

        // 애니메이션 해제용 주석 -> 애니메이션 수정 완료 시 주석 제거

        //PlayerFbx.AddComponent<BoxCollider>().size = new Vector3(1.5f, 2.25f, 1.5f);
        //PlayerFbx.GetComponent<BoxCollider>().center = new Vector3(0, -0.2f, 0);
        //PlayerFbx.AddComponent<Rigidbody>();
        //PlayerFbx.GetComponent<Rigidbody>().constraints =
        //    (RigidbodyConstraints.FreezeAll - (int)RigidbodyConstraints.FreezePositionY);


        Calculate.SetRightHandTr(PlayerFbx.transform.GetChild(3).GetChild(0).GetChild(0));
        //오른손 위치값 할당 -> R_Arm -> PlayerFbx.transform.GetChild(3).GetChild(0).GetChild(0)
        //ArmBon -> 팔 회전 -> PlayerFbx.transform.GetChild(3)
        //HandBon -> 손 회전 -> ArmBon.GetChild(0)
        //Arm -> 마테리얼 존재위치 -> HandBon.GetChild(0)

        PlayerFbx.transform.GetChild(3).GetChild(0).GetChild(0).gameObject.AddComponent<BoxCollider>().isTrigger = true;
        //오른손 박스콜라이더 설정 -> RHand

        PlayerFbx.transform.GetChild(3).GetChild(0).GetChild(0).gameObject.tag = "FIST";
        //-> 충돌시 루트 오브젝트의 태그값을 읽음
        Calculate.AnimControl = PlayerFbx.GetComponent<Player_AnimControl>();
        //PlayerFbx.transform.GetChild(0).GetChild(3).GetChild(1).gameObject.GetComponent<BoxCollider>().enabled = false;

        //PlayerFbx.GetComponent<Transform>().rotation = Quaternion.Euler(0, -90, 0);

        //Calculate.ResetData();
        //PlayerFbx.transform.GetChild(2).GetChild(0).GetChild(0).gameObject.AddComponent<BoxCollider>();
        //PlayerFbx.transform.GetChild(4).GetChild(0).GetChild(0).gameObject.AddComponent<BoxCollider>();
        //불러온 Fbx파일 회전
    }
/*
    Color[] SetColor(int _Colornum)
    {
        Color[] Cols = new Color[3];
        switch (_Colornum)
        {
            case 0:
                Cols[0] = Hexadecimal( "FC8370");//손
                Cols[1] = Hexadecimal("FB6D51");//발
                Cols[2] = Hexadecimal("E8563F");//Liquid
                break;

            case 1:
                Cols[0] = Hexadecimal("62DDBD");
                Cols[1] = Hexadecimal("46CEAD");
                Cols[2] = Hexadecimal("35BB9B");
                break;

            case 2:
                Cols[0] = Hexadecimal("FCD277");
                Cols[1] = Hexadecimal("FECD57");
                Cols[2] = Hexadecimal("F5BA45");
                break;

            case 3:
                Cols[0] = Hexadecimal("B3A5EF");
                Cols[1] = Hexadecimal("AC92EA");
                Cols[2] = Hexadecimal("967ADA");
                break;
        }
        Debug.Log(Cols[0] + Cols[1] + Cols[2]);
        return Cols;

    }

    Color Hexadecimal(string Colorcode)
    {
        //string[] strsplit = ;
        
        byte br = System.Convert.ToByte(Colorcode.Substring(0, 2), 16);
        byte bg = System.Convert.ToByte(Colorcode.Substring(2, 2), 16);
        byte bb = System.Convert.ToByte(Colorcode.Substring(4, 2), 16);
        byte ba = 255;

        Color32 GetCol = new Color32(br, bg, bb, ba);

        return GetCol;
    }
    */ //--------------------------------필요시 주석해제
    void MatCal(float value)
    {
        Mat_Liquid.SetFloat("_FillAmount", (3-value)*0.2f);
        //Mat_Liquid.SetFloat("_FillAmount", Mat_Liquid.GetFloat("_FillAmount") + 0.2f);
        PlayerFbx.transform.GetChild(0).GetChild(0).GetChild(2).GetComponent<MeshRenderer>().material = Mat_Liquid;
        Hpbar.value = 0.3f*value;

        bHitflg = false;
        if (Calculate.bDieflg)
        {
            bDieflg = true;
        }
    }

    void MatCal2()
    {
        Debug.Log("Shrink");
        Mat_Liquid.SetFloat("_FillAmount", Mat_Liquid.GetFloat("_FillAmount") + 0.2f);
        PlayerFbx.transform.GetChild(0).GetChild(0).GetChild(2).GetComponent<MeshRenderer>().material = Mat_Liquid;
        Hpbar.value -= 0.3f;

        bHitflg = false;
        if (Calculate.bDieflg)
        {
            bDieflg = true;
        }
    }//Run on Ontrigger
}
