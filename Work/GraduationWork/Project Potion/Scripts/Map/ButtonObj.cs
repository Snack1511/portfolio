using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ButtonObj : MonoBehaviour
{
    public bool bSwitchpush;
    // Start is called before the first frame update
    void Start()
    {
        bSwitchpush = false;
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.tag == "WEAPON" || other.tag == "FIST")
        {
            bSwitchpush = true;
            Debug.Log("Click");
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
