using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Module {

    private bool Engineflag;
    private bool Wheelflag;
    private bool Frameflag;
    private bool Gearflag;
    private bool Reacterflag;
    private bool isCarry;
    private bool Moduleflag;

    

    public Module(bool setvalue)
    {
        Engineflag = setvalue;
        Wheelflag = setvalue;
        Frameflag = setvalue;
        Gearflag = setvalue;
        Reacterflag = setvalue;
        isCarry = setvalue;
        Moduleflag = setvalue;
    }
    public bool Engine
    {
        get { return Engineflag; }
        set { Engineflag = value; }
    }
    public bool Wheel
    {
        get { return Wheelflag; }
        set { Wheelflag = value; }
    }
    public bool Frame
    {
        get { return Frameflag; }
        set { Frameflag = value; }
    }
    public bool Gear
    {
        get { return Gearflag; }
        set { Gearflag = value; }
    }
    public bool Reacter
    {
        get { return Reacterflag; }
        set { Reacterflag = value; }
    }
    public bool Carry
    {
        get { return isCarry; }
        set { isCarry = value; }
    }

    public bool CheckMod()
    {
        if (Engineflag && Wheelflag && Frameflag && Gearflag && Reacterflag)
        {
            return true;
        }
        else
            return false;
    }

    public bool Modflag
    {
        get { return Moduleflag; }
        set { Moduleflag = value; }
    }

    public void ModuleInit()
    {
        Engineflag = false;
        Wheelflag = false;
        Frameflag = false;
        Gearflag = false;
        Reacterflag = false;
        isCarry = false;
        Moduleflag = false;
}
}
