using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class flask : MonoBehaviour
{
    static float MAXHP = 10;
    // Start is called before the first frame update
    float HP;
    Material Mat;
    Text txt;
    private void Awake()
    {
        HP = MAXHP;
        Mat = GetComponent<Transform>().GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material;
        txt = GameObject.Find("HPTEXT").GetComponent<Text>();
        txt.text = "HP : " + HP;
    }
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.KeypadPlus)) {
            HP -= 1f;
            txt.text = "HP : " + HP;
            MatCal();
            
        }
    }
    void MatCal() {
        float value2 = Mat.GetFloat("_FillAmount") + 0.2f;
        Mat.SetFloat("_FillAmount", value2);
    }

    //min = 0.5
    //max = -1.5
}
