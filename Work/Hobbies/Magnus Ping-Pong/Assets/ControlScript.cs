using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ControlScript : MonoBehaviour
{
    AI_Script Ai;
    float Horizon = 0f;
    float Verti = 0f;
    // Start is called before the first frame update
    void Start()
    {
        if(gameObject.name == "Bar_CPU")
        {
            Ai = GetComponent<AI_Script>();
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (Ai == null)
        {
            Horizon = Input.GetAxis("Horizontal");
            Verti = Input.GetAxis("Vertical");
        }
        else
        {
            Horizon = Ai.HORI;
            Verti = Ai.VERTI;
        }
    }
    public float HORI
    {
        get { return Horizon; }
    }
    public float VERTI
    {
        get { return Verti; }
    }
}
