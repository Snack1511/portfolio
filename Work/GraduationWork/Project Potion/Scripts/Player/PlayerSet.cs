using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;


public class PlayerSet : MonoBehaviour
{
    GameObject Text_3d;
    //렌더링 관련
    public PlayerInput P_input;
    string currentscheme;
    public string ModelName;
    public int ColorNum;
    Transform Tr;
    //조작관련

    CPlayer playerData;
    //게임데이터 관련
    Player_Cal Cal;
    Control Con;
    PlayerRender Render;
    PlayerManager PlayerMgr;
    public Rigidbody rigid;
    void Awake() {
        //Render = GetComponent<MeshRenderer>();
        //PlayerMat = new Material(Shader.Find("Standard"));
        Con = gameObject.GetComponent<Control>();
        Cal = GetComponent<Player_Cal>();
        Render = GetComponentInChildren<PlayerRender>();
        rigid = GetComponent<Rigidbody>();

        playerData = new CPlayer();
        playerData = CPlayer.DEBUG;
        Text_3d = GetComponent<Transform>().GetChild(0).gameObject;
        P_input = GetComponent<PlayerInput>();
        Tr = GetComponent<Transform>();
        PlayerInit();
    }
    private void OnEnable()
    {
        
    }
    void Start() {
        Debug.Log(ModelName +" "+"Reset");
        ResetData();
        //SetRender(currentscheme);
    }
    // Start is called before the first frame update


    // Update is called once per frame
    void Update()
    {
        //PlayerDead();
    }
    
    private void OnDisable()
    {
        Debug.Log("Dead");
        playerData.POINT = GameManager.GM.PMGR.SetLeavePlayer();//튜토리얼맵에서 넘어갈땐 안뜨게
        playerData.CalTotalPoint(GameManager.GM.RoundNum);
        
    }
    public void OnTriggerEnter(Collider other)
    {
        if (other.tag == "GROUND")
        {
            if (rigid.useGravity)
            {
                transform.position = new Vector3(transform.position.x, 1, transform.position.z);
                rigid.velocity = Vector3.zero;
                rigid.drag = 10;
                rigid.useGravity = false;
            }
        }

    }
    public void OnTriggerExit(Collider other)
    {
        if (other.tag == "GROUND")
        {
            if (!rigid.useGravity)
            {
                Debug.Log("aa");
                rigid.useGravity = true;
                rigid.drag = 0;
            }
        }
        
    }
    void PlayerInit()
    {
        currentscheme = P_input.currentControlScheme;
        name = currentscheme;
        //playerData.SetName(name);
        Text_3d.GetComponent<TextMesh>().text = currentscheme;


        //로드시 안불러와짐
        /*Con = gameObject.GetComponent<Control>();
        Cal = GetComponent<Player_Cal>();
        Render = GetComponentInChildren<PlayerRender>();
        rigid = GetComponent<Rigidbody>();*/
        //GetComponent<Transform>()position = ;
    }

    public void ResetData()
    {
        rigid.useGravity = true;
        rigid.drag = 0;
        rigid.velocity = Vector3.zero;
        playerData.ResetHp();
        Con.ResetData();
        Cal.ResetData();
        Render.ResetData();
    }
 
    public CPlayer GetPlayerData() {
        return playerData;
    }

    public Transform GetTr() {
        return Tr;
    }
    public string GetcurrentSchreme() {
        return currentscheme;
    }

    /*void PlayerDead() {
        if (!gameObject.activeSelf)
        {
            GameManager.GM.SetLeavePlayer();
        }
    }*/
    

    

}
