using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Users;
using UnityEngine.UI;

public class DisplayController : MonoBehaviour
{
    InputDevice Device_KB, Device_PS4, Device_Xbox;
    Text Textobj;
    
    string[] str = new string[5];
    // Start is called before the first frame update
    void Start()
    {
        Textobj = GameObject.Find("Text").GetComponent<Text>();
        /*Debug.Log(InputSystem.devices[0]);
        Debug.Log(InputSystem.devices[1]);
        Debug.Log(InputSystem.devices.Count);*/
        int i = 0;
        foreach (PlayerInput a in PlayerInput.all)
        {
            str[i] = a.name + " : " + a.currentControlScheme.ToString();
            i++;
        }//오브젝트별 연결된 컨트롤스키마 확인

        foreach (InputDevice dn in InputSystem.devices)
        {
            switch (dn.device.name)
            {
                case "KeyboardMouse":
                    Device_KB = InputSystem.GetDevice(dn.device.name);
                break;
                case "XInputControllerWindows":
                    Device_Xbox = InputSystem.GetDevice(dn.device.name);
                break;
                case "DualShock4GamepadHID":
                    Device_PS4 = InputSystem.GetDevice(dn.device.name);
                break;
            }
        }//현재 연결중인 디바이스 해당 변수에 할당
    }

    // Update is called once per frame
    void Update()
    {
        DisplayMsg(str[0], str[1], str[2]);
    }

    public void DisplayMsg(string txt1, string txt2,string txt3) {
        Textobj.text = txt1 + "\n" + txt2 + "\n" + txt3 + "\n";

        /*
        if (Device_KB.IsPressed()) {
            Textobj.text += "CurrentInputDevice : " + Device_KB.name + "\n";
        }
        if (Device_Xbox.IsPressed())
        {
            Textobj.text += "CurrentInputDevice : " + Device_Xbox.name + "\n";
        }
        if (Device_PS4.IsPressed())
        {
            Textobj.text += "CurrentInputDevice : " + Device_PS4.name + "\n";
        }
        *///--> 실패 : 듀쇽이 버튼을 안눌러도 인식이 됨
        //Textobj.text = txt1 + "\n" + txt2 + "\n";
        //Debug.Log("");
    }
}
