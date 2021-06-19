using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;


namespace Custom
{
    public class GetStringToInt {
        public static int GetModel(string str) => str switch
        {
            "Ch_roundFlask" => 0,
            "Ch_erlenmeyerFlask" => 1,
            _ => -1,
        };
    }
    public class ColorFunction {
        public static Color[] SetColor(int _Colornum)
        {
            Color[] Cols = new Color[3];
            switch (_Colornum)
            {
                case 0:
                    Cols[0] = Hexadecimal("FC8370");//¼Õ
                    Cols[1] = Hexadecimal("FB6D51");//¹ß
                    Cols[2] = Hexadecimal("E8563F");//Liquid
                    break;

                case 1:
                    Cols[0] = Hexadecimal("62DDBD");
                    Cols[1] = Hexadecimal("46CEAD");
                    Cols[2] = Hexadecimal("35BB9B");
                    break;

                case 2:
                    Cols[0] = Hexadecimal("FCD277");
                    Cols[1] = Hexadecimal("FECD57");
                    Cols[2] = Hexadecimal("F5BA45");
                    break;

                case 3:
                    Cols[0] = Hexadecimal("B3A5EF");
                    Cols[1] = Hexadecimal("AC92EA");
                    Cols[2] = Hexadecimal("967ADA");
                    break;
            }
            Debug.Log(Cols[0] + Cols[1] + Cols[2]);
            return Cols;

        }

        public static Color Hexadecimal(string Colorcode)
        {
            //string[] strsplit = ;

            byte br = System.Convert.ToByte(Colorcode.Substring(0, 2), 16);
            byte bg = System.Convert.ToByte(Colorcode.Substring(2, 2), 16);
            byte bb = System.Convert.ToByte(Colorcode.Substring(4, 2), 16);
            byte ba = 255;

            Color32 GetCol = new Color32(br, bg, bb, ba);

            return GetCol;
        }
    }

    public class GetScheme
    {
        public static string GetSchemeDatas(string device)
        {
            if (device == "XInputControllerWindows")
            {
                return "Xbox";
            }
            else if (device == "Keyboard")
            {
                return "Keyboard";
            }
            else if (device == "DualShock4GamepadHID")
            {
                return "PS4";
            }
            else
            {
                return "";
            }
        }
    }
    
    public class GenericFuncs
    {
        public static GameObject InitMgr<T>(string _name) where T:class, new()
        {
            var a = new T();
            a.GetType();
            GameObject Mgrobj = GameObject.Find(_name);
            if (Mgrobj == null)
            {
                Mgrobj = new GameObject();
                Mgrobj.name = _name;
                Mgrobj.AddComponent(a.GetType());
                Object.DontDestroyOnLoad(Mgrobj);
            }
            return Mgrobj;
        }
    }

    [System.Serializable]
    public struct SelectData
    {

        int Index;
        Material Mat;
        string charactername;
        string device;
        InputDevice InputDv;
        bool Readyflg;
        bool Activeflg;
        //delegate bool SetReadyflg(bool value);

        public SelectData(Material _Mat, int idx = -1, string _device = "", InputDevice _InputDv = null, string name = "")
        {
            Index = idx;
            Mat = _Mat;
            charactername = name;
            device = _device;
            InputDv = _InputDv;
            Readyflg = false;
            Activeflg = true;
        }

        public string GetDVName()
        {
            return device;
        }
        public string GetIndexTostr()
        {
            return Index.ToString();
        }
        public int GetIndex()
        {
            return Index;
        }
        public InputDevice GetInputDv()
        {
            return InputDv;
        }
        public string GetName()
        {
            return charactername;
        }
        public Material GetMat()
        {
            return Mat;
        }
        public bool IsReady()
        {
            return Readyflg;
        }
        public bool IsActive()
        {
            return Activeflg;
        }
        public void SetName(string value)
        {
            charactername = value;
        }
        public void SetReady(bool value = true)
        {
            Readyflg = value;
        }
        public void SetActive(bool value = true)
        {
            Activeflg = value;
        }
        public void ResetAll()
        {
            Index = 0;
            Mat = null;
            charactername = "";
            device = "";
            InputDv = null;
            Readyflg = false;
            Activeflg = false;
        }

        public string PrintForDebug()
        {
            string str;
            str = Index + " " + device + " " + Mat + " " + charactername;
            return str;
        }

        public void SetData(SelectData sd)
        {
            Index = sd.Index;
            Mat = sd.Mat;//c;
            charactername = sd.charactername;
            device = sd.device;
            InputDv = sd.InputDv;
            Readyflg = sd.Readyflg;
            Activeflg = sd.Activeflg;
        }
        public void SetPreviousData(int n, Material _Mat)
        {
            Index = n;
            Mat = _Mat;
        }


    };
    /*
         Keyboard
         XInputControllerWindows
         Dual4Shock
     */

}