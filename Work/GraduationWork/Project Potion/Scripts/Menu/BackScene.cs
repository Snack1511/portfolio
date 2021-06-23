using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class BackScene : MonoBehaviour
{
    public GameObject ButtonMgr;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(IsButtonPress())
        {
            ButtonMgr.GetComponent<ButtonScript>().EventStartToBack();
        }
    }

    bool IsButtonPress()
    {
        if(Gamepad.current != null && Gamepad.current.buttonEast.isPressed)
        {
            return true;
        }
        else if (Keyboard.current != null && Keyboard.current.escapeKey.isPressed)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
