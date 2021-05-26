using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Melee : Weapon
{
    //무기의 데이터를 플레이어에게 복사
    private void Awake()
    {
        
    }
    private void Start()
    {
        InitWeapon("Dummy", ITEMTYPE.ITEM, WeaponType.SWORD, 1, 0.5f, 25f);
        ResetWeapon();


    }
    //--------한번만
    
    private void OnTriggerEnter(Collider other)
    {
        if(tag == "WEAPON")
        {
            if (bEquiped)
            {
                if (other.tag == "Player" && other.name != Owner)
                {
                    other.GetComponent<Player_Cal>().SetEnemy(Owner, true, WData);
                    //Use(Dmg, other.gameObject);
                }
            }//일반공격시
            else
            {
                if (!bThrowEnd && !bIsCollision)
                {
                    if (other.tag == "MAP")
                    {
                        //bThrowEnd = true;

                        bIsCollision = true;
                    }
                    else if (other.tag == "Player" && other.name != Owner)
                    {
                        other.GetComponent<Player_Cal>().SetEnemy(Owner, true, WData);
                        //Use(Dmg, other.gameObject);
                        //Debug.Log(Dmg);
                        //bThrowEnd = true;
                        bIsCollision = true;
                    }
                }
            }//투척시
            
        }
        else if(tag == "ITEM" )
        {
            if (other.tag == "Player")
            {
                //Debug.Log("Else");
                CheckPlayerCal_HaveWeapon(other);
                if (bEquiped)
                {
                    Equiped(other);
                    
                }
            }
        }
    }
    
    /*private void OnCollisionEnter(Collision collision)
    {
        Debug.Log("ssssssssss");
        Debug.Log(collision.collider.name);
        //if
    }*/
    private void FixedUpdate()
    {
        Throwed();
    }

    


    private void Update()
    {
        ChangeChildTag();//child의 태그를 지속적으로 바꿔줌 -> 나중에 필요할때만 호출되도록 바꿔주어야함
        CheckIsThrow();
        CheckTouchHeight();
    }
    void ChangeChildTag() {

        if (bEquiped)
        {
            if (PlayerControl.Anim_Attflg)
            {
                transform.GetChild(0).tag = ChangeTag(ITEMTYPE.WEAPON); //ChangeTag(ITEMTYPE.);
            }
            else
            {
                transform.GetChild(0).tag = ChangeTag(ITEMTYPE.NONE);
            }
        }
        else
        {
            if (!bThrowEnd)
            {
                transform.GetChild(0).tag = ChangeTag(ITEMTYPE.WEAPON);
            }
            else
            {
                transform.GetChild(0).tag = ChangeTag(ITEMTYPE.ITEM);
            }
        }
        
    }
    protected override void SetWeaponPos_InGround()
    {
        Tr.rotation = Quaternion.Euler(new Vector3(Tr.rotation.eulerAngles.x, Tr.rotation.eulerAngles.y, 180));
        Tr.position = new Vector3(Tr.position.x, 2.5f, Tr.position.z);
        rigid.Sleep();
        //Debug.Log("푹-");
    }

    protected override void ResetWeapon(ITEMTYPE Type = ITEMTYPE.ITEM)
    {
        //SetOwner();
        tag = ChangeTag(Type);
        transform.GetChild(0).tag = tag;
        bIsCollision = false;
        ResetWeapon_Value();
        SetWeaponPos_InGround();
        //if()
        /*bEnemyCollision = false;
        IsTouchLimitHeight = false;
        //ThrowDistance = 10f;
        ThrowingForce = 5f;*/
    }
    protected override void Equiped(Collider other)
    {

        if (Owner == "" && tag == "ITEM")
        {
            rigid.Sleep();
            tag = ChangeTag(ITEMTYPE.WEAPON);
            transform.GetChild(0).tag = tag;
            ResetWeapon_Value();
            GetItem(other.gameObject);
            WData.OWNER = Owner;
            //PlayerCalculate.script.GetPlayerData().ConfirmWeaponData(WData);
            PlayerCalculate.WT = WData.WT;
            
            bIsCollision = false;
            
        }
    }
    protected override void CheckTouchHeight()
    {
        if (Tr.position.y >= 2f)
        {
            tag = ChangeTag(ITEMTYPE.ITEM);
            transform.GetChild(0).tag = tag;
            ResetWeapon_Value(true);
            //IsTouchLimitHeight = true;
        }
    }
    public CWeaponData GetWeapondata()
    {
        return WData;
    }
}

