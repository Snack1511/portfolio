using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class AMoe : MonoBehaviour
{
    Transform tr;
    Vector3 MoveVal;
    // Start is called before the first frame update

    private void Awake()
    {
        tr = GetComponent<Transform>();
    }
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        tr.Translate(MoveVal.normalized * 3 * Time.deltaTime);
    }

    public void Move(InputAction.CallbackContext ctx)
    {
        MoveVal = new Vector3(ctx.ReadValue<Vector2>().x, -ctx.ReadValue<Vector2>().y, 0);
    }
}
