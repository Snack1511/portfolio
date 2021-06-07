using System.Collections;
using System.Collections.Generic;
using UnityEngine;


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
    

}