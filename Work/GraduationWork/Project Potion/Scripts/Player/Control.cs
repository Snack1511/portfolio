using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;


public class Control : MonoBehaviour
{
    PlayerSet script;
    //Transform tr;
    InputPlayer Player_Input;
    PlayerInput P_Input;
    //bool Alterflg;
    public float fAimVal { private set; get; }
    public bool bAttackflg { private set; get; }
    public bool bDashflg { private set; get; }
    //public bool ThrowChargeflg { private set; get; }
    public bool bPauseflg { private set; get; }
    public Vector3 MoveVal { private set; get; }
    public Vector3 AimDir { private set; get; }
    public Vector3 DashDir { private set; get; }
    //public float Speed;
    // Start is called before the first frame update
    //public float ThrowPower { private set; get; }

    public bool bHaveWeapon;
    public bool bHavePassive;
    public bool bHaveEffect;

    public bool bAnim_Moveflg;
    public bool bAnim_Attflg;
    public bool bAnim_Dashflg;
    public bool bAnim_Throwflg;
    
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
        fAimVal = 0;
        AimDir = Vector3.zero;

        bAttackflg = false;
        bDashflg = false;
        bPauseflg = false;

        bHaveWeapon = false;
        bHavePassive = false;
        bHaveEffect = false;

        bAnim_Moveflg = false;
        bAnim_Attflg = false;
        bAnim_Dashflg = false;
        bAnim_Throwflg = false;
    }
    public void Move(InputAction.CallbackContext ctx)
    {
        if (!bPauseflg && !GameManager.GM.ROOMMGR.GamePauseflg)
        {
            
            bAnim_Moveflg = true;
            MoveVal = new Vector3(ctx.ReadValue<Vector2>().x, 0, ctx.ReadValue<Vector2>().y);
            if (ctx.ReadValue<Vector2>() != new Vector2(0, 0))
            {
                if (!bAnim_Throwflg && !bAnim_Dashflg && !bAnim_Attflg)
                {
                    fAimVal = Mathf.Atan2(ctx.ReadValue<Vector2>().y, ctx.ReadValue<Vector2>().x) * Mathf.Rad2Deg;
                    fAimVal += 90;
                    AimDir = new Vector3(ctx.ReadValue<Vector2>().x, 0, ctx.ReadValue<Vector2>().y).normalized;
                }
            }
            else
            {
                bAnim_Moveflg = false;
            }
        }
    }//다른 애니메이션 재생 중 입력 불가

    public void Join(InputAction.CallbackContext ctx)
    {
        Debug.Log(ctx.ReadValueAsButton());//bool
    }
    

    public void Attack(InputAction.CallbackContext ctx) {
        if (!bPauseflg && !GameManager.GM.ROOMMGR.GamePauseflg)
        {
            bAnim_Attflg = true;
            bAttackflg = ctx.ReadValueAsButton();
        }
    }

    public void Dash(InputAction.CallbackContext ctx) {
        if (!bPauseflg && !GameManager.GM.ROOMMGR.GamePauseflg && !bAnim_Dashflg)
        {
            //Debug.Log("Dash" + " " + ctx.phase);
            DashDir = AimDir;
            bDashflg = true;
            bAnim_Dashflg = true;
            //Dashflg = ctx.action.triggered;
        }
        else
        {
            bDashflg = false;
        }
    }

    public void Throw(InputAction.CallbackContext ctx) {
        if (!bPauseflg && !GameManager.GM.ROOMMGR.GamePauseflg)
        {
            if (bHaveWeapon)
            {
                bAnim_Throwflg = true;
                bHaveWeapon = false;
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
        GameManager.GM.ROOMMGR.GamePauseflg = true;
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
