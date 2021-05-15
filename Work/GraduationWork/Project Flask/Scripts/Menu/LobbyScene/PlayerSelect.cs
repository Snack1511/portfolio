using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using System.Collections;

public class PlayerSelect : MonoBehaviour
{
    Text playerInputIdx;
    Text InputDevice;
    int num;
    PlayerInput UIInput;
    public SelectData sd;
    public GameObject UISelector;
    public InputDevice InputDv;
    private void Awake()
    {
        InitPS();
    }
    private void OnEnable()
    {

        if (UIInput != null && !UIInput.gameObject.activeSelf)
        {
            UIInput.gameObject.SetActive(true);
            SetUIInput();
        }
    }
    void Start()
    {
        SetUIInput();
        //SetObjectDescription(sd);

        /*UISelector.GetComponent<SelectorControl>().PSCObj = gameObject;
        //UISelector.GetComponent<SelectorControl>().PlayerSelectObj = transform.parent.gameObject;
        UISelector.GetComponent<SelectorControl>().PlayerSelectNum = sd.GetIndex();
        UIInput = PlayerInput.Instantiate(UISelector, sd.GetIndex(), GetScheme(sd.GetDVName()), -1, sd.GetInputDv());
        UIInput.transform.SetParent(GameObject.Find("ModelPanel").transform.GetChild(1));
        UIInput.SwitchCurrentActionMap("UISelector");
        UIInput.SwitchCurrentControlScheme(sd.GetInputDv());
        UIInput.gameObject.name = UIInput.currentControlScheme + " " + UIInput.currentActionMap.name;*/

    }


    

    // Update is called once per frame
    void Update()
    {
        /*if (Disconnectflg)
        {
            //transform.parent.GetComponent<AddPlayerScript>().RemovePlayer(sd.GetIndex());
            Disconnectflg = false;
        }*/


    }
    private void OnDisable()
    {
        if (transform.parent.GetComponent<AddPlayerScript>() != null)
        {
            transform.parent.GetComponent<AddPlayerScript>().RemovePlayer(sd.GetIndex());
        }
        /*if (UIInput.gameObject.activeSelf)
        {
            UIInput.gameObject.SetActive(false);
        }*/
    }
    public void SetObjectDescription(SelectData sd)
    {
        gameObject.name = "PlayerSelect" + sd.GetIndex();
        gameObject.transform.GetChild(1).GetComponent<Image>().material = sd.GetMat();
        //Debug.Log(gameObject.name);
        playerInputIdx = transform.GetChild(2).GetChild(0).GetComponent<Text>();
        InputDevice = transform.GetChild(2).GetChild(1).GetComponent<Text>();
        var num = sd.GetIndex();
        num += 1;
        transform.GetChild(2).GetComponent<RawImage>().texture = Resources.Load<CustomRenderTexture>("Materials/Texture/Player" + num);
        playerInputIdx.text = "P" + num;//+1;
        InputDevice.text = sd.GetDVName();
        UIInput.GetComponent<SelectorControl>().sd = sd;
        UIInput.GetComponent<SelectorControl>().SetSCDescription(sd);
        
        //num = sd.GetIndex();
        //InputDv = sd.GetInputDv();
        
    }

    public void InitPS()
    {
        UISelector.GetComponent<SelectorControl>().PSCObj = gameObject;
        //UISelector.GetComponent<SelectorControl>().PlayerSelectObj = transform.parent.gameObject;
        UISelector.GetComponent<SelectorControl>().PlayerSelectNum = sd.GetIndex();
        UIInput = PlayerInput.Instantiate(UISelector, sd.GetIndex(), GetScheme(sd.GetDVName()), -1, sd.GetInputDv());
        UIInput.transform.SetParent(GameObject.Find("ModelPanel").transform.GetChild(1));
        
    }

    public void SetUIInput()
    {
        UIInput.SwitchCurrentActionMap("UISelector");
        UIInput.SwitchCurrentControlScheme(sd.GetInputDv());
        UIInput.gameObject.name = UIInput.currentControlScheme + " " + UIInput.currentActionMap.name;
    }

    public string GetScheme(string device)
    {
        if(device == "XInputControllerWindows")
        {
            return "Xbox";
        }
        else if(device == "Keyboard")
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

    public void SetObjInputPair()
    {
        UIInput.SwitchCurrentControlScheme(InputDv);
        //UIInput.user.
    }


    /*public int GetNum()
    {
        return num;
    }*/

    

}
