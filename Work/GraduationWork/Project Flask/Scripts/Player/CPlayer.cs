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
    private List<int> Point;
    private int TotalPoint;


    public CPlayer()
    {
        //Name = "";
        MaxHp = 3;
        Hp = MaxHp;
        Dmg = 0;
        StunTime = 0.5f;
        Knockforce = 50f;
        Speed = 7.5f;
        Point = new List<int>();
        TotalPoint = 0;
    }

    public CPlayer(/*string name, */float _Mhp = 3, float _Dmg = 0, float _Stuntime = 0.5f, float _Knockforce = 50f, float _Speed = 7.5f)
    {
        //Name = name;
        MaxHp = _Mhp;
        Hp = MaxHp;
        StunTime = _Stuntime;
        Knockforce = _Knockforce;
        Speed = _Speed;
        Point = new List<int>();
        TotalPoint = 0;

    }


    //public string NAME { get { return Name; } set { } }
    public float HP { get { return Hp; } set { Hp = value; } }
    public float DMG { get { return Dmg; } set { } }
    public float STUNTIME { get { return StunTime; } set { } }
    public float KNOCKFORCE { get { return Knockforce; } set { } }
    public int POINT { 
        get { 
            return TotalPoint;
        }
        set {
            Point.Add(value);
            /*for(int i = 0; i < Point.Count; i++)
            {
                UnityEngine.Debug.Log(Point[i]);
            }*/
        }
    }
    public void CalTotalPoint(int n)
    {
        if (Point.Count > 0)
        {
            UnityEngine.Debug.Log(Point[n]);
            TotalPoint += (4 - Point[n]);
        }
    }
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
