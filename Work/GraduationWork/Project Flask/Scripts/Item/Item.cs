using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Item : MonoBehaviour
{
    //protected abstract string Owner { get; set; }
    //protected abstract ITEMTYPE Type { get; set; }

    protected abstract void InitItem(ITEMTYPE Type, float _Dmg = 0);
    protected abstract void GetItem(GameObject obj);
    protected abstract void Use();
    
}
public enum ITEMTYPE
{
    NONE = 0,
    ITEM,
    WEAPON,
    EFFECT,
    PASSIVE
}