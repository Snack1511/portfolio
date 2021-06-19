using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
public class ControlGuidePanelScript : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject DeviceDescription;
    bool XInputCheck;
    bool KeyboardCheck;
    bool D4SCheck;
    int idx = 0;
    private void Awake()
    {
        
        
    }
    void OnEnable()
    {

    }
    void Start()
    {
        
        var lastpos = Vector3.zero;
        for (int i = 0; i < GameManager.Selected.Length; i++)
        {
            if (GameManager.Selected[i].GetDVName() == "XInputControllerWindows")
            {
                XInputCheck = true;
            }
            else if (GameManager.Selected[i].GetDVName() == "Keyboard")
            {
                KeyboardCheck = true;
            }
            else if (GameManager.Selected[i].GetDVName() == "DualShock4GamepadHID")
            {
                D4SCheck = true;
            }
        }
        if (XInputCheck) {
            transform.GetChild(1).GetChild(0).GetComponent<RectTransform>().anchoredPosition3D = lastpos;
            lastpos.x += 420;
            idx++;
            transform.GetChild(1).GetChild(0).gameObject.SetActive(true);
        }
        if (KeyboardCheck)
        {
            transform.GetChild(1).GetChild(1).GetComponent<RectTransform>().anchoredPosition3D = lastpos;
            lastpos.x += 420;
            idx++;
            transform.GetChild(1).GetChild(1).gameObject.SetActive(true);
        }
        if (D4SCheck)
        {
            transform.GetChild(1).GetChild(2).GetComponent<RectTransform>().anchoredPosition3D = lastpos;
            lastpos.x += 420;
            idx++;
            transform.GetChild(1).GetChild(2).gameObject.SetActive(true);
        }
        SetDescriptionPos();

    }
    /*
     XInputControllerWindows
     Keyboard
     Dual4Shock
     */
    void OnDisable()
    {
        //GameManager.GM.Tutorialchkflg = true;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void ClickContinuebtnEvent()
    {
        if (!GameManager.GM.ROOMMGR.Tutorialchkflg)
        {
            GameManager.GM.ROOMMGR.Tutorialchkflg = true;
            GameManager.GM.ROOMMGR.GamePauseflg = false;
            gameObject.SetActive(false);
        }
        else gameObject.SetActive(false);
    }

    void SetDescriptionPos()
    {
        //var GetChildCount = transform.GetChild(1).childCount;
        var pos = new Vector3(-180, 0, 0);
        for(int i = 0; i < idx-1; i++)
        {
            transform.GetChild(1).GetChild(0).GetComponent<RectTransform>().anchoredPosition3D += pos;
            transform.GetChild(1).GetChild(1).GetComponent<RectTransform>().anchoredPosition3D += pos;
            transform.GetChild(1).GetChild(2).GetComponent<RectTransform>().anchoredPosition3D += pos;
            transform.GetChild(1).GetChild(3).GetComponent<RectTransform>().anchoredPosition3D += pos;
        }
    }
    
}
