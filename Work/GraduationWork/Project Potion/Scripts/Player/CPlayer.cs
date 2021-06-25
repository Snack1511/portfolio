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
    private float fMaxHp;
    private float fHp;
    private float fDmg;
    private float fStunTime;
    private float fKnockforce;
    private float fSpeed;
    private float fDash;
    private float fInvincibilityTime;
    private List<int> lstPoint;
    private int iTotalPoint;


    public CPlayer()
    {
        //Name = "";
        fMaxHp = 3;
        fHp = fMaxHp;
        fDmg = 0;
        fStunTime = 5f;
        fKnockforce = 50f;
        fSpeed = 7.5f;
        fDash = 2.5f;
        fInvincibilityTime = 5f;
        lstPoint = new List<int>();
        iTotalPoint = 0;
    }
   

    public CPlayer(/*string name, */float _Mhp = 3, float _Dmg = 0, float _Stuntime = 0.5f, float _Knockforce = 50f, float _Speed = 7.5f, float _Dash = 2.5f, float _Invincivility = 1f)
    {
        //Name = name;
        fMaxHp = _Mhp;
        fHp = fMaxHp;
        fDmg = _Dmg;
        fStunTime = _Stuntime;
        fKnockforce = _Knockforce;
        fSpeed = _Speed;
        fDash = _Dash;
        fInvincibilityTime = _Invincivility;
        lstPoint = new List<int>();
        iTotalPoint = 0;

    }
    public static CPlayer DEBUG
    {
        get { return new CPlayer(3, 0, 5, 50, 7.5f, 5); }
    }

    //public string NAME { get { return Name; } set { } }
    public float HP { get { return fHp; } set { fHp = value; } }
    public float DMG { get { return fDmg; } set { } }
    public float STUNTIME { get { return fStunTime; } set { } }
    public float KNOCKFORCE { get { return fKnockforce; } set { } }
    public int POINT { 
        get { 
            return iTotalPoint;
        }
        set {
            lstPoint.Add(value);
            /*for(int i = 0; i < Point.Count; i++)
            {
                UnityEngine.Debug.Log(Point[i]);
            }*/
        }
    }
    public int DEGREE
    {
        get { return lstPoint[lstPoint.Count - 1]; }
    }
    public float SPD { get { return fSpeed; } set { } }
    public float DSH { get {return fDash; } set { } }
    public float INVIN { get { return fInvincibilityTime; } }
    //-----------------------------프로퍼티

    public string print() {
        string str = "HP : " + fHp + "\n" + "DMG : " + fDmg + "\n" + "POINT : " + lstPoint + "\n" + "SPD : " + fSpeed + "\n";
        return str;
    }
    
    public void CalTotalPoint(int n)
    {
        if (lstPoint.Count > 0)
        {
            UnityEngine.Debug.Log("Point"+lstPoint[n]);
            iTotalPoint += (4 - lstPoint[n]);
        }
    }

    public void SetAttackValue(float _Dmg, float _stunTime, float _knockforce) {
        fDmg = _Dmg;
        fStunTime = _stunTime;
        fKnockforce = _knockforce;
    }
    public void ResetAttackValue() {
        fDmg = 0;
        fStunTime = 0.5f;
        fKnockforce = 50f;
    }
    
    public void ConfirmWeaponData(CWeaponData a) {
        fDmg = a.DMG;
        fStunTime = a.STUNTIME;
        fKnockforce = a.KNOCKFORCE;
    }
    public void ResetHp()
    {
        fHp = fMaxHp;
    }
}
