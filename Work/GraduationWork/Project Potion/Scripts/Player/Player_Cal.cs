using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/* Player_Cal
 * 유니티 내에서의 수치 계산 및 물리효과적용에만 사용
 */

public class Player_Cal : MonoBehaviour
{
   
    public bool bHitflg { private set; get; }
    public bool bDieflg { set; get; }
    public bool bDeadAnimEnd { set; get; }
    public bool bInvincibilityflg { private set; get; }
    bool bKillflg;
    
    public bool bIsTouchItem { get; set; }
    public bool bThrowflg { get; set; }
    public bool bThrowControlAnim { get; set; }
    public bool bAttackControlAnim { get; set; }
    bool bCollisionflg;
    public Vector3 ToWeaponAttDir { get; set; }
    public Transform RightHandTr { private set; get; }
    public float fAttactedDmg { set; get; }
    public float fKnockbackforce { set; get; }
    public float Speed;
    public float fDashforce = 5.5f;
    public PlayerSet SetPlayer;
    public WeaponType WT;
    public Player_AnimControl AnimControl;
    //float fMoveThrough;

    Transform Tr;
    Rigidbody Rigid;
    PlayerSet AttByEnemy;
    CWeaponData WeaponData;
    Control control;
    GameObject Slots;
    Vector3 MoveDir;
    Vector3 AttactedDir;//없어도 될거 같음
    //차후 수정 필요
    // Start is called before the first frame update


    private void Awake()
    {
        Init();
    }
    void Start()
    {
        
        ResetData();
    }
    void FixedUpdate() {
        Cal_Dash();
        //대시
    }
    // Update is called once per frame
    void Update()
    {
        if(transform.position.y <= -1f)
        {
            bDieflg = true;
        }
        if (!bDieflg)
        {

            Cal_Attacked();// 피격

            SetDieflg(AttByEnemy);

            Cal_Throw();//투척

            Cal_Move(bCollisionflg);//이동


        }//사망 확인
        else {
            State_Dead();
        }
        Cal_Point(ref bKillflg, IsKillSelf(bDieflg, AttByEnemy));
        //포인트 계산
        //SetEnemy();//필요없는 연산같음
    }


    private void OnTriggerEnter(Collider other)
    {
        
        if (other.tag == "WEAPON")
        {
            
            SetHitflg(true);//sword -> blade
            AttactedDir = other.transform.parent.position;//없어도 될거 같음
           
        }
        else if(other.tag == "FIST")
        {
            AttactedDir = other.transform.root.position;//없어도 될거 같음
            SetEnemy(other.transform.root.name);
            SetHitflg(true);

        }
        else if(other.tag == "ITEM")
        {
            if (other.transform.parent == null)
            {
                CheckItem(other.gameObject);
            }
            else
            {
                CheckItem(other.transform.parent.gameObject);//sword -> blade

            }//tag -> Melee Range를 세분화 시키면 더 직관적일거 같음
            
            
        }
    }//아이템 습득 및 무기 피격 구현
    
    private void OnTriggerStay(Collider other)
    {
        if (!control.bAttackflg)
        {
            if (other.tag == "Player"|| other.tag == "MAP")
            {
                bCollisionflg = true;
                MoveDir = transform.position - other.transform.position;
                MoveDir = new Vector3(MoveDir.x, 0, MoveDir.z);
                MoveDir = (MoveDir + control.MoveVal).normalized;
            }
        }
    }
    private void OnTriggerExit(Collider other)
    {
        if (other.tag == "MAP" || other.tag == "Player")
        {
            bCollisionflg = false;
        }
    }
    
    void Init() {
        SetPlayer = GetComponent<PlayerSet>();
        control = GetComponent<Control>();
        Rigid = GetComponent<Rigidbody>();
        Tr = SetPlayer.GetTr();
        Speed = SetPlayer.GetPlayerData().SPD;
        Slots = Tr.GetChild(2).GetChild(1).gameObject;
        
    }
    //초기화 -> 게임시작시 동작

    public void ResetData() {
        bHitflg = false;
        bDieflg = false;
        bDeadAnimEnd = false;
        bKillflg = false;
        bInvincibilityflg = false;
        bIsTouchItem = false;
        bThrowflg = false;
        bThrowControlAnim = false;
        AttByEnemy = null;
        bCollisionflg = false;
        WT = WeaponType.PUNCH;
        if (RightHandTr != null)
        {
            RightHandTr.tag = RightHandTr.parent.tag;
        }
        control.SetPauseflg(false);
    }
    //데이터 리셋 -> 라운드 변화시 동작
    //나중에 만들 GameMgr 구현시 함께 사용

    void Cal_Move(bool flg) {
        if (!control.bDashflg && !control.bAnim_Dashflg)
        {
            if (!control.bAnim_Throwflg && !control.bAnim_Attflg)
            {
                if (flg)
                {
                    Tr.Translate(MoveDir.normalized * Speed * Time.deltaTime);
                }
                else
                {
                    Tr.Translate(control.MoveVal.normalized * Speed * Time.deltaTime);
                }
            }

        }
    }

    /*
   void Cal_Attack(GameObject obj) {
        if (control.Attackflg)
        {
            if (!control.haveWeapon)
            {

                RightHandTr.tag = "FIST";
            }
        }

    }*/

    void Cal_Dash() {
        if (!bCollisionflg)
        {
            if (control.bDashflg)
            {
                Rigid.AddForce(control.DashDir * fDashforce, ForceMode.VelocityChange);
            }
            /*else
            {
                bDashEndflg = true;
            }*/
            Rigid.AddForceAtPosition(Vector3.zero, Tr.position, ForceMode.VelocityChange);
        }
    }
    //Dash키 입력시 활성화

    void Cal_Throw() {
        if (!control.bHaveWeapon && RightHandTr.childCount != 0)
        {
            if (bThrowControlAnim)
            {
                WT = WeaponType.PUNCH;
                ToWeaponAttDir = control.AimDir;
                bThrowflg = true;
                SetPlayer.GetPlayerData().ResetAttackValue();
                Slots.GetComponent<SlotScript>().ReleaseSlot();
            }
        }
        bThrowControlAnim = false;
        
    }
    //투척
    void Cal_Attacked() {
        if (bHitflg)
        {
            if (WeaponData != null)
            {
                Move_KnockBack(AttByEnemy, WeaponData);
                State_Stun(WeaponData.STUNTIME);
                State_Invicibility(SetPlayer.GetPlayerData().INVIN);
                Cal_Dmg(WeaponData.DMG);
            }
            else
            {
                Move_KnockBack(AttByEnemy);
                State_Stun(AttByEnemy.GetPlayerData().STUNTIME);
                State_Invicibility(SetPlayer.GetPlayerData().INVIN);
                Cal_Dmg(AttByEnemy.GetPlayerData().DMG);
            }
        }
    }
    //피격

    void Move_KnockBack(PlayerSet Enemy, CWeaponData WD = null)
    {
        float Knockforce = Enemy.GetPlayerData().KNOCKFORCE;
        Vector3 KnockDir;
        if (WD != null) {
            Knockforce = WD.KNOCKFORCE;
        }
        KnockDir = new Vector3((Tr.position.x - Enemy.GetTr().position.x), 0f, (Tr.position.z - Enemy.GetTr().position.z)).normalized;
        Rigid.AddForceAtPosition(KnockDir * Knockforce, Tr.position, ForceMode.VelocityChange);
    }
    //충돌 시 활성화

    void State_Stun(float _Time) {
        if (!bDieflg)
        {
            control.SetPauseflg(true);
            StartCoroutine("DelayAndChangePause", _Time);
        }
    }
    //상태이상 : 스턴 >> CPlayer의 fStuntime 변수사용
    IEnumerator DelayAndChangePause(float time) {
        yield return new WaitForSeconds(time);
        control.SetPauseflg(false);
    }
    //time 만큼시간 이후 SetPauseflg false

    void State_Invicibility(float _Time) {
        
        StartCoroutine("SetInvincivbility", _Time);
    }
    //상태이상 : 무적
    IEnumerator SetInvincivbility(float _Time) {
        bInvincibilityflg = true;
        yield return new WaitForSeconds(_Time);
        bInvincibilityflg = false;
    }
    //bInvincibilityflg 값 변화

    void State_Dead() {
        if (bDeadAnimEnd)
        {
            StartCoroutine("RemainDead");
        }
    }
    //상태이상 : 스턴

    void SetDieflg(PlayerSet Enemy) {
        if (SetPlayer.GetPlayerData().HP <= 0f || SetPlayer.GetTr().position.y <= -1f) {
            if (Enemy != null) {
                Enemy.GetComponent<Player_Cal>().bKillflg = true;
            }
            
            bDieflg = true; 
        }
        else bDieflg = false;
    }
    //PlayerSet안의 플레이어 데이터의Hp가 0일경우 동작
    //상대 오브젝트의 Killflg를 대신 동작시켜줌

    IEnumerator RemainDead()
    {
        
        yield return new WaitForSeconds(3f);
        control.SetPauseflg(true);
        gameObject.SetActive(false);
        transform.GetChild(1).GetChild(0).localPosition = new Vector3(0, 1, 0);

    }

    public void Cal_Point(ref bool IsKill, bool IsKillself)
    {
        /*if (IsKill) script.GetPlayerData().POINT += 1;
        if (IsKillself) script.GetPlayerData().POINT -= 1;*/
        IsKill = false;
    }
    //상대 플레이어 오브젝트가 변경한 Killflg가 변경시 점수 적용
    //아래의 IsKillSelf와 연동해 자살일 경우 포인트 감소

    bool IsKillSelf(bool Dieflg, PlayerSet Enemy) {
        if (Dieflg && Enemy == null) return true;
        else return false;
    }
    //포인트 계산시 매개변수로 쓰임

    void CheckItem(GameObject obj)
    {
        
        if (!control.bHaveWeapon&&RightHandTr.childCount == 0)
        {
            RightHandTr.tag = RightHandTr.parent.tag;
            bIsTouchItem = true;
            WeaponData = obj.GetComponent<Melee>().GetWeapondata();
            Slots.GetComponent<SlotScript>().FillSlot(obj.GetComponent<Melee>().GetWeapondata().IMG);
            Slots.SetActive(true);
            control.bHaveWeapon = true;
        }

    }
    //무기 소지 상태 변화 함수 -> 현재 소지 무기가 없을 경우 동작

    public void SetHitflg(bool flg) {
        if (flg)
        {
            if (!bInvincibilityflg)//SetInvincivbility:IEnumerator 에서 변경
            {
                AnimControl.Play_HIt();
                bHitflg = flg;
            }
        }
        else
        {
            bHitflg = flg;
        }
    }//충돌 처리부분에서 사용
    
    public void Cal_Dmg(float _Dmg)
    {
        SetPlayer.GetPlayerData().HP -= _Dmg;
        Debug.Log(gameObject.name + "HP : " + SetPlayer.GetPlayerData().HP + " AttackedDmg : " + _Dmg);
        SetHitflg(false);
    }//받은 Dmg에 따른 Hp계산

    public void SetEnemy(string Enemy = null, bool flg = false, CWeaponData WD = null) {
        if (flg)
        {
            WeaponData = WD;
            AttByEnemy = GameObject.Find(WD.OWNER).GetComponent<PlayerSet>();
            Debug.Log(name + "AttByEnemy : " + AttByEnemy.name);
        }
        else
        {
            WeaponData = null;
            AttByEnemy = GameObject.Find(Enemy).GetComponent<PlayerSet>();
            Debug.Log(name + "AttByEnemy : " + AttByEnemy.name);
        }
    }//상대의 무기데이터를 받아 동작


    public void SetRightHandTr(Transform tr) {
        RightHandTr = tr;
    }
    //RightHandTr함수를 외부에서 등록하는 함수

    





}
