using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Interactions;


public class Control : MonoBehaviour
{
    PlayerSet script;
    //Transform tr;
    InputPlayer Player_Input;
    PlayerInput P_Input;
    //bool Alterflg;
    public Vector3 MoveVal { private set; get; }
    public float AimVal { private set; get; }
    public Vector3 AimDir { private set; get; }
    //public float Speed;
    // Start is called before the first frame update
    public bool Attackflg { private set; get; }
    public bool Dashflg { private set; get; }
    public Vector3 DashDir { private set; get; }
    //public bool ThrowChargeflg { private set; get; }
    public bool bPauseflg { private set; get; }
    //public float ThrowPower { private set; get; }

    public bool haveWeapon;
    public bool havePassive;
    public bool haveEffect;

    public bool Anim_Moveflg;
    public bool Anim_Attflg;
    public bool Anim_Dashflg;
    public bool Anim_Throwflg;

    private void Awake()
    {
        InitInput();

    }
    private void OnEnable()
    {
        Player_Input.Enable();

    }
    void Start()
    {
        script = GetComponent<PlayerSet>();

    }

    // Update is called once per frame
    /*void Update()
    {
        
    }
    */
    private void OnDisable()
    {
        Player_Input.Disable();
    }

    //=====UserCustomMathod
    void InitInput()
    {
        Player_Input = new InputPlayer();

        P_Input = GetComponent<PlayerInput>();
        if (P_Input.currentControlScheme == null)
        {
            P_Input.SwitchCurrentControlScheme(InputSystem.GetDevice("Keyboard"));
            //P_Input.SwitchCurrentControlScheme(InputSystem.GetDevice("XInputControllerWindows1"));
        }
        ResetData();
    }

    public void ResetData(){
        MoveVal = Vector3.zero;
        AimVal = 0;
        AimDir = Vector3.zero;

        Attackflg = false;
        Dashflg = false;
        //ThrowChargeflg = false;
        bPauseflg = false;

        //haveWeapon = true;
        haveWeapon = false;
        havePassive = false;
        haveEffect = false;
        //P_Input.SwitchCurrentControlScheme(InputSystem.GetDevice("Keyboard"));

        Anim_Moveflg = false;
        Anim_Attflg = false;
        Anim_Dashflg = false;
        Anim_Throwflg = false;
    }
    public void Move(InputAction.CallbackContext ctx)
    {
        if (!bPauseflg && !GameManager.GM.GamePauseflg)
        {
            Anim_Moveflg = ctx.action.triggered;
            MoveVal = new Vector3(ctx.ReadValue<Vector2>().x, 0, ctx.ReadValue<Vector2>().y);
            if (ctx.ReadValue<Vector2>() != new Vector2(0, 0))
            {
                if (!Anim_Throwflg)
                {
                    AimVal = Mathf.Atan2(ctx.ReadValue<Vector2>().y, ctx.ReadValue<Vector2>().x) * Mathf.Rad2Deg;
                    AimVal += 90;
                    AimDir = new Vector3(ctx.ReadValue<Vector2>().x, 0, ctx.ReadValue<Vector2>().y).normalized;
                }
            }
            
            /*if (Alterflg)
            {
                if (ctx.ReadValue<Vector2>() != new Vector2(0, 0))
                {
                    AimVal = Mathf.Atan2(ctx.ReadValue<Vector2>().y, ctx.ReadValue<Vector2>().x) * Mathf.Rad2Deg;
                    AimVal += 90;
                    AimDir = new Vector3(ctx.ReadValue<Vector2>().x, 0, ctx.ReadValue<Vector2>().y).normalized;
                }
            }*/
        }
    }
    public void Join(InputAction.CallbackContext ctx)
    {
        Debug.Log(ctx.ReadValueAsButton());//bool
    }
    public void Aim(InputAction.CallbackContext ctx) {

        /*if (ctx.ReadValue<Vector2>() != new Vector2(0, 0))
        {
            AimVal = Mathf.Atan2(ctx.ReadValue<Vector2>().y, ctx.ReadValue<Vector2>().x) * Mathf.Rad2Deg;
            AimVal += 90;
            AimDir = new Vector3(ctx.ReadValue<Vector2>().x, 0, ctx.ReadValue<Vector2>().y).normalized;
            Alterflg = false;
        }
        else Alterflg = true;*/
    }

    public void Attack(InputAction.CallbackContext ctx) {
        if (!bPauseflg && !GameManager.GM.GamePauseflg)
        {
            //Debug.Log("Attack");
            Anim_Attflg = true;
            Attackflg = ctx.ReadValueAsButton();
            //Debug.Log(Attackflg);
            /*if (haveWeapon)
            {
                Attackflg = ctx.ReadValueAsButton();
                Debug.Log(Attackflg);
                //Debug.Log("Bang"+ Shootflg);
            }*/
        }
    }

    public void Dash(InputAction.CallbackContext ctx) {
        if (!bPauseflg && !GameManager.GM.GamePauseflg)
        {
            //Debug.Log("Dash" + " " + ctx.phase);
            DashDir = AimDir;
            Anim_Dashflg = ctx.started;
            Dashflg = ctx.started;
            //Dashflg = ctx.action.triggered;
        }
    }

    public void Throw(InputAction.CallbackContext ctx) {
        if (!bPauseflg && !GameManager.GM.GamePauseflg)
        {
            if (haveWeapon)
            {
                Anim_Throwflg = true;
                haveWeapon = false;
                //Debug.Log("Throw " + ctx.action.phase);
                /*if (ctx.action.phase != InputActionPhase.Canceled)
                {
                    //Anim_Throwflg = ctx.action.triggered;
                    //Debug.Log(ctx.performed);
                    //ThrowPower = (float)ctx.duration;
                    //ThrowChargeflg = ctx.action.triggered;
                    Anim_Throwflg = ctx.started;
                }
                if (ctx.action.phase == InputActionPhase.Canceled)
                {
                    //Debug.Log(ctx.performed);
                    haveWeapon = false;
                    //ThrowChargeflg = false;
                    Anim_Throwflg = ctx.performed;
                }*/
            }
            
        }
    }
    public void Menu(InputAction.CallbackContext ctx)
    {
        GameManager.GM.GamePauseflg = true;
    }
    public void DeviceLost()
    {
        Debug.Log("DeviceLost");
        Time.timeScale = 0f;
    }
    public void DeviceRegained()
    {
        Debug.Log("DeviceRegained");
        Time.timeScale = 1f;
    }
    public void ControlChanged()
    {

    }
    
    public void SetInputDevice() {
        if (P_Input.currentControlScheme == null)
        {
            //InputSystem.devices
            P_Input.SwitchCurrentControlScheme(InputSystem.GetDevice("Keyboard"), InputSystem.GetDevice("Mouse"));
            //P_Input.SwitchCurrentControlScheme(InputSystem.GetDevice("XInputControllerWindows1"));
        }
    }
    
    public void SetPauseflg(bool _flg) {
        bPauseflg = _flg;
    }
}
