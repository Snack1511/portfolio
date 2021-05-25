using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class backward : MonoBehaviour {
    public Image ColorB;

    // Use this for initialization
    void Start()
    {
        ColorB = GameObject.Find("backwardcolor").GetComponent<Image>();
    }

    // Update is called once per frame
    void Update()
    {
        ChangeColor(player.ChangeC_flag);
    }
    void ChangeColor(uint flag)
    {
        uint a = (flag % 3);
        switch (a)
        {
            case 0:
                ColorB.color = new Color(0.0f, 0.0f, 1.0f);
                break;
            case 1:
                ColorB.color = new Color(1.0f, 0.0f, 0.0f);
                break;
            case 2:
                ColorB.color = new Color(0.0f, 1.0f, 0.0f);
                break;
        }
    }
}
