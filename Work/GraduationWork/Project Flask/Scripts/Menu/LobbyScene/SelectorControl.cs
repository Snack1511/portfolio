using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using Custom;

public class SelectorControl : MonoBehaviour
{
    Vector2 Moveval;
    GraphicRaycaster GHit;
    RectTransform Rtr;
    Toggle[] toggles;
    public int SelectedModelNum;
    public int PlayerSelectNum;
    public GameObject PSCObj;
    //public GameObject PlayerSelectObj;
    //GameObject PopupDisplay;
    public InputMgr inputmgr;
    public bool Backflg;
    AddPlayerScript APS;
    float Limitx;
    bool Disconnectflg;
    public SelectData sd;
    GameObject TextureCams;
    // Start is called before the first frame update
    private void Awake()
    {
        Backflg = false;
        inputmgr = GameObject.Find("InputMgr").GetComponent<InputMgr>();
        Rtr = GetComponent<RectTransform>();
        
        APS = GameObject.Find("PlayerSelectObj").GetComponent<AddPlayerScript>();
        TextureCams = GameObject.Find("TextureRenderCams");
    }
    private void OnEnable()
    {
        SetSCDescription(PSCObj.GetComponent<PlayerSelect>().sd);
    }
    void Start()
    {
        GHit = transform.root.GetComponent<GraphicRaycaster>();
        sd = PSCObj.GetComponent<PlayerSelect>().sd;
        
        SetSCDescription(sd);
        var togglesobj = transform.parent.parent.GetChild(0);
        toggles = new Toggle[togglesobj.childCount];
        for (int i = 0; i < togglesobj.childCount; i++)
        {
            toggles[i] = togglesobj.GetChild(i).GetComponent<Toggle>();
        }
        Limitx = (toggles.Length - 1) / 2 * 120f;
        var startposx = (((toggles.Length + 1) / 2) - 1) * 120;
        Rtr.anchoredPosition3D = new Vector3(-startposx, 120, 0);


        /*transform.GetChild(0).GetComponent<Image>().material = inputmgr.SData[PlayerSelectNum].GetMat();
        transform.GetChild(0).GetChild(0).GetComponent<Text>().color = inputmgr.SData[PlayerSelectNum].GetMat().color;
        transform.GetChild(0).GetChild(0).GetComponent<Text>().text = PSCObj.transform.GetChild(2).GetChild(0).GetComponent<Text>().text;*/

        //Rtr.anchoredPosition3D = toggles[PSObj.GetComponent<PlayerSelect>().sd.GetIndex()].gameObject.GetComponent<RectTransform>().anchoredPosition3D + new Vector3(0, 0, -10);
        //string str = toggles[PSObj.GetComponent<PlayerSelect>().sd.GetIndex()].name;//GetRaycastResult(GHit, "Background").gameObject.transform.parent.name;
        //toggles[PSObj.GetComponent<PlayerSelect>().sd.GetIndex()].name;//GetRaycastResult(GHit, "Background").gameObject.transform.parent.name;
        //Debug.Log(str);
        //var screenobj = GetRaycastResult(GHit, "Background").gameObject;
        //Debug.Log(GetRaycastResult(GHit, "Background").gameObject.name);
        string str = "Ch_roundFlask";//screenobj.transform.parent.name;
        //PSCObj.transform.GetChild(2).GetComponent<RawImage>().texture = Resources.Load<CustomRenderTexture>("Materials/Texture/" + str + "Texture");
        TextureCams.GetComponent<TextureRenderer>().InitTexture(sd.GetIndex(), str);
        SelectedModelNum = GetStringToInt.GetModel(str);
        //screenobj.GetComponent<>
        //transform.position = 
        //PopupDisplay = transform.parent.parent.GetChild(2).gameObject;
        //toggles[0].isOn = true;
        //ToggleCheck(toggles);
        //GetLastSDATA();
    }
    
    // Update is called once per frame
    void Update()
    {
        if (Disconnectflg)
        {

            gameObject.SetActive(false);
            Disconnectflg = false;
        }
    }

    private void OnDisable()
    {
        PSCObj.SetActive(false);
        /*Debug.Log("aa");
        inputmgr.idx -= 1;
        inputmgr.SData[PlayerSelectNum].ResetAll();
        inputmgr.SortSD();
        APS.UpdateplayerImg();*/

        //inputmgr.SData[PlayerSelectNum].SetName("");
    }

    public void SetSCDescription(SelectData sd)
    {
        if (sd.GetDVName() != null)
        {
            transform.GetChild(0).GetComponent<Image>().material = sd.GetMat();
            transform.GetChild(0).GetChild(0).GetComponent<Text>().color = sd.GetMat().color;
            transform.GetChild(0).GetChild(0).GetComponent<Text>().text = PSCObj.transform.GetChild(2).GetChild(0).GetComponent<Text>().text;
        }
    }

    public void Move(InputAction.CallbackContext ctx)
    {//
        if (ctx.action.phase == InputActionPhase.Started)
        {
            if (!inputmgr.SData[sd.GetIndex()].IsReady())
            {
                Moveval = ctx.ReadValue<Vector2>();//new Vector3(ctx.ReadValue<Vector2>().x, ctx.ReadValue<Vector2>().y);
                                                   //transform.position\
                Moveval = new Vector3(Mathf.RoundToInt(Moveval.x), Mathf.RoundToInt(Moveval.y), 0);
                Debug.Log(Moveval);
                Rtr.anchoredPosition3D += (Vector3)(Moveval * 240);
                if (Rtr.anchoredPosition3D.x <= -Limitx) Rtr.anchoredPosition3D = new Vector3(-Limitx, Rtr.anchoredPosition3D.y, Rtr.anchoredPosition3D.z);
                else if (Rtr.anchoredPosition3D.x >= Limitx) Rtr.anchoredPosition3D = new Vector3(Limitx, Rtr.anchoredPosition3D.y, Rtr.anchoredPosition3D.z);
                if (Rtr.anchoredPosition3D.y >= 120) Rtr.anchoredPosition3D = new Vector3(Rtr.anchoredPosition3D.x, 120, Rtr.anchoredPosition3D.z);
                else if (Rtr.anchoredPosition3D.y <= -120) Rtr.anchoredPosition3D = new Vector3(Rtr.anchoredPosition3D.x, -120, Rtr.anchoredPosition3D.z);

                string str = GetRaycastResult(GHit, "Background").gameObject.transform.parent.name;
                TextureCams.GetComponent<TextureRenderer>().SetTextureObj(sd.GetIndex(), SelectedModelNum, str);
                SelectedModelNum = GetStringToInt.GetModel(str);
                //Debug.Log(str);
                //PSCObj.transform.GetChild(2).GetComponent<RawImage>().texture = Resources.Load<CustomRenderTexture>("Materials/Texture/" + str+"Texture");
            }
        }

    }
    public void Select(InputAction.CallbackContext ctx)
    {

        if (!inputmgr.SData[sd.GetIndex()].IsReady())
        {
            /*var ped = new PointerEventData(null);
            ped.position = transform.position;
            List<RaycastResult> results = new List<RaycastResult>();
            GHit.Raycast(ped, results);
            if (results.Count <= 0) return;
            //Debug.Log(results[1].gameObject.name);
            //Debug.Log(results[2].gameObject.name);
            //Debug.Log(results[3].gameObject.name);
            results.Find(x => x.gameObject.name == "Background")*/
            if (!GetRaycastResult(GHit, "Background").gameObject.transform.parent.GetComponent<Toggle>().isOn)
            {
                var name = GetRaycastResult(GHit, "Background").gameObject.transform.parent.name;//GetComponent<Toggle>().isOn = true;
                GetLastSDATA(name);
                GetRaycastResult(GHit, "Background").gameObject.transform.parent.GetComponent<Toggle>().isOn = true;
                //results[2].gameObject.transform.parent.GetComponent<Toggle>().isOn = true;

                //ToggleCheck(toggles);

            }
            if (inputmgr.SData[sd.GetIndex()].GetName() != "")
            {
                SetReady();
                PSCObj.transform.GetChild(2).GetChild(2).gameObject.SetActive(true);
            }
        }
        else
        {
            inputmgr.SData[sd.GetIndex()].SetReady(false);
            PSCObj.transform.GetChild(2).GetChild(2).gameObject.SetActive(false);
            GetRaycastResult(GHit, "Background").gameObject.transform.parent.GetComponent<Toggle>().isOn = false;
        }
        /*if(Physics.Raycast(transform.position, transform.forward, out hit, 5))
        {
            Debug.Log("Hit");
            Debug.Log(hit.transform.gameObject.name);
        }*/
    }

    public void Ready(InputAction.CallbackContext ctx)
    {
        //SetReady();
    }

    public void Back(InputAction.CallbackContext ctx)
    {
        /*if (ctx.performed)
        {
            if (inputmgr.SData[PlayerSelectNum].IsReady())
            {
                
                inputmgr.SData[PlayerSelectNum].SetReady(false);
            }
            else {
                APS.RemovePlayer(420);
                PSCObj.SetActive(false);
            }
        }*/
    }

    public void Start(InputAction.CallbackContext ctx)
    {
        if (inputmgr.ReadyAll())
        {
            if (ctx.action.phase == InputActionPhase.Performed)
            {
                inputmgr.GameStartflg = true;
            }
        }
    }

    RaycastResult GetRaycastResult(GraphicRaycaster _GHit, string str)
    {
        RaycastResult RayResult = new RaycastResult();
        var ped = new PointerEventData(null);
        ped.position = transform.position;
        List<RaycastResult> results = new List<RaycastResult>();
        _GHit.Raycast(ped, results);
        if (results.Count <= 0) return RayResult;
        RayResult = results.Find(x => x.gameObject.name == str);
        return RayResult;
    }

    void ToggleCheck(Toggle[] _toggles) {
        for(int i = 0; i < _toggles.Length; i++)
        {
            if (_toggles[i].isOn)
            {
                SelectedModelNum = i;
                break;
            }
        }
    }

    

    public void GetLastSDATA(string str)
    {
        
        inputmgr.SData[sd.GetIndex()].SetName(str/*GetModelName(SelectedModelNum)*/);
    }
    public void SetReady()
    {
        //var num = psObj.transform.GetChild(psObj.transform.childCount - 1).GetComponent<PlayerSelect>().GetNum();
        inputmgr.SData[sd.GetIndex()].SetReady();
    }
    public void ResetSelect()
    {
        
    }
    
    public void DeviceLostEvt(PlayerInput input)
    {
        Disconnectflg = true;
        //PSCObj.gameObject.SetActive(false);
        //var n = input.playerIndex;
        //PlayerSelectObj.GetComponent<AddPlayerScript>().RemovePlayer(input.playerIndex);
        //inputmgr.idx--;
        //PSCObj.GetComponent<PlayerSelect>().Disconnectflg = true;
        /*
        if (!PopupDisplay.activeSelf)
        {
            PopupDisplay.SetActive(true);
        }
        PopupDisplay.transform.GetChild(0).GetComponent<Text>().text += "\nPlayer" + input.user.index + " is lost";
        */
    }
    
    
    /*public void DeviceReainedEvt(PlayerInput input)
    {

    }*/
}
