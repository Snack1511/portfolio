using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEditor;

[Serializable]
public class CPlayer
{
    //private string Name;
    private float MaxHp;
    private float Hp;
    private float Dmg;
    private float StunTime;
    private float Knockforce;
    private float Speed;
    private int Point;


    public CPlayer()
    {
        //Name = "";
        MaxHp = 3;
        Hp = MaxHp;
        Dmg = 0;
        StunTime = 0.5f;
        Knockforce = 50f;
        Point = 0;
        Speed = 7.5f;
    }
    
    public CPlayer(/*string name, */float _Mhp = 3, float _Dmg = 0, float _Stuntime = 0.5f, float _Knockforce = 50f, float _Speed = 7.5f, int point = 0) {
        //Name = name;
        MaxHp = _Mhp;
        Hp = MaxHp;
        StunTime = _Stuntime;
        Knockforce = _Knockforce;
        Point = point;
        Speed = _Speed;
    }
    
    //public string NAME { get { return Name; } set { } }
    public float HP { get { return Hp; } set { Hp = value; } }
    public float DMG { get { return Dmg; } set { } }
    public float STUNTIME { get { return StunTime; } set { } }
    public float KNOCKFORCE { get { return Knockforce; } set { } }
    public int POINT { get { return Point; } set { Point = value; } }
    public float SPD { get { return Speed; } set { } }
    public string print() {
        string str = "HP : " + Hp + "\n" + "DMG : " + Dmg + "\n" + "POINT : " + Point + "\n" + "SPD : " + Speed + "\n";
        return str;
    }

    /*public void SetName(string str) {
        Name = str;
    }*/

    public void SetAttackValue(float _Dmg, float _stunTime, float _knockforce) {
        Dmg = _Dmg;
        StunTime = _stunTime;
        Knockforce = _knockforce;
    }
    public void ResetAttackValue() {
        Dmg = 0;
        StunTime = 0.5f;
        Knockforce = 50f;
    }

    public void ConfirmWeaponData(CWeaponData a) {
        Dmg = a.DMG;
        StunTime = a.STUNTIME;
        Knockforce = a.KNOCKFORCE;
    }
    public void ResetHp()
    {
        Hp = MaxHp;
    }
}
