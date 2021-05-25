using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class forwardcolor : MonoBehaviour {
    public Image ColorF;

    // Use this for initialization
    void Start () {
        ColorF = GameObject.Find("forwardcolor").GetComponent<Image>();
    }
	
	// Update is called once per frame
	void Update () {
        ChangeColor(player.ChangeC_flag);
    }
    void ChangeColor(uint flag)
    {
        uint a = (flag % 3);
        switch (a)
        {
            case 0:
                ColorF.color = new Color(0.0f, 1.0f, 0.0f);
                break;
            case 1:
                ColorF.color = new Color(0.0f, 0.0f, 1.0f);
                break;
            case 2:
                ColorF.color = new Color(1.0f, 0.0f, 0.0f);
                break;
        }
    }
}
