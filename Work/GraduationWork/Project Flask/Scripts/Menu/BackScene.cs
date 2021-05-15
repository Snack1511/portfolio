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
        if(Gamepad.current.buttonEast.isPressed || Keyboard.current.escapeKey.isPressed)
        {
            ButtonMgr.GetComponent<ButtonScript>().EventStartToBack();
        }
    }


}
