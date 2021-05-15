using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[Serializable]
public class CWeaponData
{
    string strOwner;
    WeaponType Type;
    float fDmg;
    float fStuntime;
    float fKnockforce;
    //bool bAttflg;

    public CWeaponData(string name, WeaponType _Type, float dmg, float stuntime, float knockforce) {
        strOwner = name;
        Type = _Type;
        fDmg = dmg;
        fStuntime = stuntime;
        fKnockforce = knockforce;
        //bAttflg = false;
    }

    public void Setname(string str) => strOwner = str;

    public string OWNER { get { return strOwner; } set { } }
    public float DMG { get { return fDmg; } set { } }
    public float STUNTIME { get { return fStuntime; } set { } }
    public float KNOCKFORCE { get { return fKnockforce; } set { } }
    
    public WeaponType WT { get { return Type; } set { } }
    //public bool ATTFLG { get { return bAttflg; } set { bAttflg = value; } }
    public CPlayer ReturnCPlayer() {
        CPlayer a = new CPlayer();
        a.ConfirmWeaponData(this);
        return a;
    }
}
public enum WeaponType
{
    PUNCH = 0,
    SWORD = 1,
    GUNTLET = 2,
}