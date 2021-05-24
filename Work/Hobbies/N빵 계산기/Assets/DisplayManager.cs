using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DisplayManager : MonoBehaviour
{
    SystemManager SysMng;
    // Start is called before the first frame update
    void Start()
    {
        SysMng = GameObject.Find("SystemManager").GetComponent<SystemManager>();
        DisplayInit();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    void DisplayInit() {
        SysMng.DisplaySetting(true, false, false);
    }
    public void AddList() {
        SysMng.GetPeople();
        SysMng.DisplaySetting(false, true, false);
    }
    public void Calculate() {
        SysMng.DisplaySetting(false, false, true);
    }
    public void ReturnTitle() {
        SysMng.DisplaySetting(true, false, false);
    }
}
