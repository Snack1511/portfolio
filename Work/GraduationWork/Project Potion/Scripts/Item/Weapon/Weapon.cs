using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Weapon : Item
{
    protected string Owner;
    protected ITEMTYPE Type;
    //--------------Item 프로퍼티 재정의 부분

    protected bool bEquiped;        //장착된지 여부
    protected bool bThrowEnd; // 투척 끝
    protected bool bIsCollision;///투척시 충돌 여부

    protected CWeaponData WData;
    protected float Dmg;                      //무기마다 다를경우 -> 하위클래스에서 정의

    Vector3 AttDir;                 //원거리 공격방향 -> Melee의 경우 투척방향
    Vector3 OwnerPosition;          //OwnerObj위치

    protected Transform Tr;                   //무기Transform
    GameObject HandObj;             //OwnerObj의 R_Armbon..?
    protected Rigidbody rigid;                //하위 클래스에서 정의
    protected Player_Cal PlayerCalculate;     //OwnerObj의 Player_Cal
    protected Control PlayerControl;

    float ThrowingForce = 5f;       //투척시 가해지는 힘
    float ThrowDistance = 10f;      //투척거리 -> 버튼 입력시간따라 변화
    bool IsTouchLimitHeight;

    protected override void InitItem(ITEMTYPE Type, float _Dmg = 0)
    {
        Dmg = _Dmg;
        tag = ChangeTag(Type);
        Tr = GetComponent<Transform>();
        rigid = GetComponent<Rigidbody>();
        rigid.maxAngularVelocity = 20f;
        SetWeaponPos_InGround();
        /*Tr.rotation = Quaternion.Euler(new Vector3(Tr.rotation.eulerAngles.x, Tr.rotation.eulerAngles.y, 180));
        Tr.position = new Vector3(Tr.position.x, 1.25f, Tr.position.z);
        rigid.Sleep();

        Debug.Log("푹-");*/
        SetOwner();
    }
    protected override void GetItem(GameObject obj)
    {
        SetOwner(obj);
        Tr.position = HandObj.transform.position;
        Tr.localRotation = Quaternion.Euler(0f, 0f, 0f);
    }

    protected override void Use() {
        /*if (obj.GetComponent<Player_Cal>() != null)
        {
            //obj.GetComponent<Player_Cal>().SetAttackedvalue(_Dmg, )
            obj.GetComponent<Player_Cal>().script.GetPlayerData().SetAttackValue(_Dmg, 0.5f, 25f);
        }*/
        //PlayerCalculate.script.GetPlayerData().SetAttackValue(Dmg, 0.5f, Knockbackforce);
    }
    //--------------Item 함수 재정의 부분

    protected void InitWeapon(string name, ITEMTYPE Type, WeaponType weaponType, float _Dmg, float _Stuntime, float _Knockforce) {
        InitItem(Type, _Dmg);
        WData = new CWeaponData(name, "", weaponType, _Dmg, _Stuntime, _Knockforce);
        /*StunTime = _Stuntime;
        Knockbackforce = _Knockforce;*/
    }

    void UnEquiped()
    {
        //InitItem(ITEMTYPE.NONE);
        ResetWeapon();
        
    }

    protected abstract void ResetWeapon(ITEMTYPE Type = ITEMTYPE.ITEM);
   /* {
        //SetOwner();
        tag = ChangeTag(Type);
        bIsCollision = false;
        ResetWeapon_Value();
        SetWeaponPos_InGround();
    }*/

    protected abstract void SetWeaponPos_InGround();
    /*{
        Tr.rotation = Quaternion.Euler(new Vector3(Tr.rotation.eulerAngles.x, Tr.rotation.eulerAngles.y, 180));
        Tr.position = new Vector3(Tr.position.x, 1.25f, Tr.position.z);
        rigid.Sleep();
        Debug.Log("푹-");
    }*/

    protected void ResetWeapon_Value(bool flag = false, float value = 5f)
    {
        SetOwner();
        WData.OWNER = Owner;
        bThrowEnd = true;
        //bIsCollision = false;
        IsTouchLimitHeight = flag;
        //ThrowDistance = 10f;
        ThrowingForce = value;
    }

    void SetOwner(GameObject obj = null)
    {
        if(tag == "WEAPON" && obj != null)
        {
            Owner = obj.name;
            PlayerCalculate = obj.GetComponent<Player_Cal>();
            PlayerControl = obj.GetComponent<Control>();
            Tr.SetParent(PlayerCalculate.RightHandTr);
            HandObj = PlayerCalculate.RightHandTr.gameObject;
        }
        else
        {
            Owner = "";
            HandObj = null;
            PlayerControl = null;
            PlayerCalculate = null;
        }
        
    }

    void SetAttDir()
    {
        AttDir = PlayerCalculate.ToWeaponAttDir;
    }
    void SetOwnerPos()
    {
        OwnerPosition = PlayerCalculate.transform.position;
    }
    protected string ChangeTag(ITEMTYPE Type) => Type switch
    {
        ITEMTYPE.ITEM => "ITEM",
        ITEMTYPE.WEAPON => "WEAPON",
        ITEMTYPE.EFFECT => "EFFECT",
        ITEMTYPE.PASSIVE => "PASSIVE",
        _ => "Untagged",

    };
    //----------내부사용함수


    protected abstract void Equiped(Collider other);
    /*{
        
        if (Owner == "" && tag == "ITEM")
        {
            rigid.Sleep();
            tag = ChangeTag(ITEMTYPE.WEAPON);
            //rigid.useGravity = false;
            //GetComponentInChildren<BoxCollider>().isTrigger = true;

            ResetWeapon_Value();
            GetItem(other.gameObject);
            bIsCollision = false;
        }
    }*/

    protected void Throwed()
    {
        if (!bEquiped)
        {
            if (!bThrowEnd) {
                rigid.AddForce(AttDir * ThrowingForce, ForceMode.VelocityChange);

                if ((OwnerPosition - Tr.position).magnitude > ThrowDistance || bIsCollision)
                {

                    ThrowingForce = 0;
                    rigid.velocity = Vector3.zero;//속도 0
                    bThrowEnd = true;
                }
                
            }
            else
            {

                if (bIsCollision) {
                    
                    ReflectWeapon(IsTouchLimitHeight);
                }//무기 튕김
                else
                {
                    if (tag != "ITEM")
                    {
                        UnEquiped();
                    }
                }
            }
        }
        
    }

    protected void ReflectWeapon(bool _IsTouchLimitHeight, int _ReflecDist = 6, float _ReflecForec = 5f, float _TorqueForce = 20f)
    {
        if (!_IsTouchLimitHeight)
        {
            rigid.AddForce(
                ((AttDir * -1f) + (Vector3.up * _ReflecDist)).normalized
                * _ReflecForec, ForceMode.VelocityChange);
            rigid.AddRelativeTorque(Vector3.back * _TorqueForce, ForceMode.VelocityChange);

        }
        else
        {
            rigid.AddForce(
                ((AttDir * -1f) + (Vector3.down * _ReflecDist)).normalized
                * _ReflecForec, ForceMode.VelocityChange);
            rigid.AddRelativeTorque(Vector3.back * _TorqueForce, ForceMode.VelocityChange);
            if (Tr.position.y <= OwnerPosition.y + 0.25f)
            {
                UnEquiped();
            }
        }//_ReflecDist -> 커질수록 거리 짧아짐
    }
    protected void CheckPlayerCal_HaveWeapon(Collider other)
    {

        if (other.GetComponent<Player_Cal>().bIsTouchItem)
        {
            bEquiped = true;
            other.GetComponent<Player_Cal>().bIsTouchItem = false;
        }
    }

    protected void CheckIsThrow()
    {
        
        if (PlayerCalculate != null && PlayerCalculate.bThrowflg)
        {
            SetAttDir();
            SetOwnerPos();
            Tr.SetParent(null);
            //rigid.useGravity = true;
            //GetComponentInChildren<BoxCollider>().isTrigger = false;
            //Debug.Log(Mathf.Atan2(AttDir.z, AttDir.x) * 180 / Mathf.PI);
            Tr.rotation = Quaternion.Euler(0f, Mathf.Atan2(AttDir.z, -AttDir.x)*180/Mathf.PI, 90f);
            bEquiped = false;
            bThrowEnd = false;
            PlayerCalculate.bThrowflg = false;
        }
    }
    protected abstract void CheckTouchHeight();
    /*{
        if (Tr.position.y >= 5f)
        {
            tag = ChangeTag(ITEMTYPE.NONE);
            ResetWeapon_Value(true);
            //IsTouchLimitHeight = true;
        }
    }*/
    //-----------하위 클래스가 참조할 부분

    

    //--------비동기 함수
}
