using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

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
public class InputMgr : MonoBehaviour
{
    PlayerInput P_A, P_B;//ForDebug
    PlayerInput[] Players;
    PlayerInput UISelector;
    Text txt;
    public SelectData[] SData;
    public static SelectData[] Selected;
    public GameObject Prefab;
    public GameObject UISelectorobj;
    public int idx;
    public bool GameStartflg;
    public Material[] ColorMats = new Material[4]; 
    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
        //PlayerInput.isSinglePlayer = false;
        GameStartflg = false;
        SData = new SelectData[4];
        Selected = new SelectData[4];
        Players = new PlayerInput[4];
        //Debug.Log("a");
        for (int i = 0; i < SData.Length; i++)
        {
            SData[i].ResetAll();
        }
        //ForDebuginTutorial();


        /*P_A = PlayerInput.Instantiate(Resources.Load<GameObject>("Prefabs/PlayerA"),0,"Xbox");
        P_B = PlayerInput.Instantiate(Resources.Load<GameObject>("Prefabs/PlayerB"), 1, "PS4");
        */
        //txt = GameObject.Find("PressButton_Text").GetComponent<Text>();

        //StartCoroutine("PlayerJoined");

        //WaitUntil waitUntil = new WaitUntil();

        //Debug.Log(Input_Manager.playerJoinedEvent);
        //Input_Manager.onPlayerJoined += PlayerJoined;
    }
    // Start is called before the first frame update
    void Start()
    {
       StartCoroutine("ReadSetDevice");
       

    }

    // Update is called once per frame
    void Update()
    {
        
    }

    /*private void OnLevelWasLoaded(int level)
    {
        if(level == 2)
        {
            for(int i = 0; i < Selected.Length; i++)
            {
                Debug.Log(GameManager.Selected[i].PrintForDebug());
            }
        }
    }
    */
    void ForDebuginTutorial()
    {
        P_A = PlayerInput.Instantiate(Resources.Load<GameObject>("Prefabs/PlayerObj"), 0, "Xbox");
        P_A.GetComponent<Transform>().position = new Vector3(2, 0, 0);
        P_B = PlayerInput.Instantiate(Resources.Load<GameObject>("Prefabs/PlayerObj"), 0, "PS4");
        P_B.GetComponent<Transform>().position = new Vector3(-2, 0, 0);
    }
    void DisplayBindingText() {
        txt.text = "Need to Binding Gamepad" + P_A.name;
    }

    public void SetSelectMode() {
        Debug.Log("SelectMode");
    }

    bool Search(SelectData[] a, string name)
    {
        for (int i = 0; i < a.Length; i++)
        {
            if (a[i].GetDVName() == name)
            {
                return true;
            }

        }
        return false;
    }

    public bool ReadyAll()
    {
        int cnt = 0;
        for(int i = 0; i < idx; i++)
        {
            if (SData[i].IsActive())
            {
                cnt++;
                if (!SData[i].IsReady())
                {
                    return false;
                }
            }
            
        }
        if (cnt >= 2)
        {
            return true;
        }
        else return false;
    }

    public void SortSD()
    {
        for (int i = 1; i < SData.Length; i++)
        {
            //Debug.Log(i);
            if (SData[i].IsActive())
            {
                if (!SData[i - 1].IsActive())
                {
                    SData[i].SetPreviousData(i - 1, ColorMats[i - 1]);
                    SData[i - 1] = SData[i];
                    SData[i].ResetAll();
                    i -= 1;
                }
                
                
            }
        }
    }

    IEnumerator ReadSetDevice()
    {
        InputDevice InputDv = new InputDevice();
        //UISelector = PlayerInput.Instantiate(UISelectorobj);
        //UISelector.transform.SetParent(GameObject.Find("ModelPanel").transform);
        //UISelector.SwitchCurrentActionMap("UISelector");
        //UISelector.gameObject.SetActive(false);

        string DeviceName = "";
        idx = 0;

        var gamepad = Gamepad.all;
        var keyboard = Keyboard.current;
        //Debug.Log();
        
        for (int i = 0; i < Gamepad.all.Count && i < 4; i++)
        {
            
            DeviceName = gamepad[i].name;
            InputDv = gamepad[i];
            
            if (DeviceName != "")
            {
                if (!Search(SData, DeviceName))
                {
                    SData[idx] = new SelectData(ColorMats[idx], idx, DeviceName, InputDv);
                    //UISelector.gameObject.SetActive(true);
                    //UISelector.SwitchCurrentControlScheme(InputDv);
                    Prefab.GetComponent<AddPlayerScript>().AddPlayer(SData[idx], 420, idx);
                    //Prefab.GetComponent<AddPlayerScript>().SetPlayeSelectObj(SData[idx]);
                    idx++;
                }
                //SData
                DeviceName = "";
                InputDv = null;
            }
            Debug.Log(i);
        }
        if (idx < 4)
        {
            DeviceName = keyboard.name;
            InputDv = keyboard;

            if (DeviceName != "")
            {
                if (!Search(SData, DeviceName))
                {
                    SData[idx] = new SelectData(ColorMats[idx], idx, DeviceName, InputDv);
                    Prefab.GetComponent<AddPlayerScript>().AddPlayer(SData[idx], 420, idx);
                    idx++;
                }
                //SData
                DeviceName = "";
                InputDv = null;
            }
        }
        

        while (!ReadyAll() || !GameStartflg)//빠져나오는 조건 설정해줘야함
        {
            //Debug.Log(Gamepad.current.CheckStateIsAtDefault());
            if (Gamepad.all.Count != idx-1)
            {
                //Debug.Log("aaa");
                for (int i = 0; i < Gamepad.all.Count && i < 4; i++)
                {
                    DeviceName = Gamepad.all[i].name;
                    InputDv = Gamepad.all[i];

                    if (DeviceName != "")
                    {
                        if (!Search(SData, DeviceName))
                        {
                            SData[idx] = new SelectData(ColorMats[idx], idx, DeviceName, InputDv);
                            //UISelector.gameObject.SetActive(true);
                            //UISelector.SwitchCurrentControlScheme(InputDv);
                            Prefab.GetComponent<AddPlayerScript>().AddPlayer(SData[idx], 420, idx);
                            //Prefab.GetComponent<AddPlayerScript>().SetPlayeSelectObj(SData[idx]);
                            idx++;
                        }
                        //SData
                        DeviceName = "";
                        InputDv = null;
                    }
                }
            }



                /*if (Gamepad.current.startButton.IsActuated() && Gamepad.current.startButton.wasPressedThisFrame)
                {//엑박보다 조이트론이 먼저 잡힐 경우 조이트론의 지속 초기화로 엑박버튼 인풋이 인식이 안되는듯
                 //Key = Gamepad.current.name;
                    if (Gamepad.all.Count <= 1)
                    {
                        DeviceName = Gamepad.current.name;
                        InputDv = Gamepad.current;

                    }
                    else
                    {
                        if (Gamepad.current.name == Gamepad.all[0].name)
                        {
                            Debug.Log("a");
                        }
                        if (Gamepad.current.name == Gamepad.all[1].name)
                        {
                            Debug.Log("b");
                        }
                    }
                    //InputSystem.GetDevice(DeviceName).name;

                }
                if (Keyboard.current.enterKey.IsActuated() && Keyboard.current.enterKey.wasPressedThisFrame)
                {

                    DeviceName = "Keyboard1";
                    InputDv = Keyboard.current;
                    //UISelector.SwitchCurrentControlScheme(Keyboard.current);
                    Debug.Log(DeviceName);
                }
                if (Keyboard.current.numpadEnterKey.IsActuated() && Keyboard.current.numpadEnterKey.wasPressedThisFrame)
                {
                    DeviceName = "Keyboard2";
                    InputDv = Keyboard.current;
                    Debug.Log(DeviceName);
                }

                if (Keyboard.current.spaceKey.IsActuated() && Keyboard.current.spaceKey.wasPressedThisFrame)
                {
                    //Gamestartflg = true;
                    for (int i = 0; i < SData.Length; i++)
                    {
                        Debug.Log(SData[i].PrintForDebug());
                    }
                }
                else
                {
                    if (DeviceName != "")
                    {
                        if (!Search(SData, DeviceName))
                        {
                            SData[idx] = new SelectData(ColorMats[idx], idx, DeviceName, InputDv);
                            //UISelector.gameObject.SetActive(true);
                            //UISelector.SwitchCurrentControlScheme(InputDv);
                            Prefab.GetComponent<AddPlayerScript>().AddPlayer(SData[idx], 420, idx);
                            //Prefab.GetComponent<AddPlayerScript>().SetPlayeSelectObj(SData[idx]);
                            idx++;
                        }
                        //SData
                        DeviceName = "";
                        InputDv = null;
                    }
                    //Players.Add(PlayerInput.Instantiate(Resources.Load<GameObject>("Prefabs/PlayerObj"), Players.Count, GetSchemeName));
                }*/

                /*if(idx >= 1)
                {
                    if (UISelector.gameObject.GetComponent<SelectorControl>().Backflg)
                    {
                        if (SData[idx - 1].IsReady())
                        {
                            Debug.Log("a");
                            SData[idx - 1].SetReady(false);
                        }
                        else {
                            if (idx - 1 >= 1)
                            {
                                idx--;
                                Prefab.GetComponent<AddPlayerScript>().RemovePlayer();
                                SData[idx].Reset();


                                //UISelector.gameObject.SetActive(false);
                            }
                            else if (idx - 1 == 0)
                            {
                                idx--;
                                Prefab.GetComponent<AddPlayerScript>().RemovePlayer();
                                SData[idx].Reset();
                                //UISelector.gameObject.SetActive(false);
                            }
                        }
                        //UISelector.GetComponent<SelectorControl>().Backflg = false;
                    }
                }*/
                yield return null;
        }
        //if()

        //Debug.LogAssertion("Start");
        for (int i = 0; i < SData.Length; i++)
        {
            GameManager.Selected[i].SetData(SData[i]);
        }

        SceneManager.LoadScene("Scenes/Maps/TutorialScene");
        //Debug.Log(Selected[0].GetDVName());
    }

    
}


/*
    PA Device입력
    현재 입력중인 Device확인
    DeviceInfo ControlA에 전송
    PB Device입력
    현재 입력중인 Device확인
    DeviceInfo ControlB에 전송
 */
