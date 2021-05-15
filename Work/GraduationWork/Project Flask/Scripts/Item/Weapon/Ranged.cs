using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ranged : Weapon
{
    protected override void SetWeaponPos_InGround()
    {
        /*Tr.rotation = Quaternion.Euler(new Vector3(Tr.rotation.eulerAngles.x, Tr.rotation.eulerAngles.y, 180));
        Tr.position = new Vector3(Tr.position.x, 1.25f, Tr.position.z);
        rigid.Sleep();
        Debug.Log("푹-");*/
    }
    protected override void ResetWeapon(ITEMTYPE Type = ITEMTYPE.NONE)
    {
        //SetOwner();
       /* tag = ChangeTag(Type);
        transform.GetChild(0).tag = tag;
        bIsCollision = false;
        ResetWeapon_Value();
        SetWeaponPos_InGround();*/
    }
    protected override void Equiped(Collider other)
    {

        /*if (Owner == "" && tag == "ITEM")
        {
            rigid.Sleep();
            tag = ChangeTag(ITEMTYPE.WEAPON);
            transform.GetChild(0).tag = tag;
            //rigid.useGravity = false;
            //GetComponentInChildren<BoxCollider>().isTrigger = true;

            ResetWeapon_Value();
            GetItem(other.gameObject);
            bIsCollision = false;
        }*/
    }
    protected override void CheckTouchHeight()
    {
        /*if (Tr.position.y >= 5f)
        {
            tag = ChangeTag(ITEMTYPE.NONE);
            transform.GetChild(0).tag = tag;
            ResetWeapon_Value(true);
            //IsTouchLimitHeight = true;
        }*/
    }

}
