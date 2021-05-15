using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StartBlockMotion : MonoBehaviour
{
    // Start is called before the first frame update
    RectTransform RTR;
    float IncreaseValue;
    public float MotionSpd = 30;
    public float Limit = 90;
    public int Topbottomflg = -1;//-1 = top, 1 = bottom
    void Start()
    {
        RTR = GetComponent<RectTransform>();
        RTR.anchoredPosition = new Vector2(0, 90*Topbottomflg*-1);
        //IncreaseMotion();
    }

    // Update is called once per frame
    void Update()
    {
        MoveMotion();
    }



    void MoveMotion()
    {

        Vector2 value = new Vector2(0, IncreaseValue*Topbottomflg);
        if (RTR.anchoredPosition.y*Topbottomflg < Limit)
        {
            RTR.anchoredPosition += value;
            IncreaseValue += MotionSpd * Time.deltaTime;
        }
        else
        {
            RTR.anchoredPosition = new Vector2(0, Limit * Topbottomflg);
            //GetComponent<PlayerSelectMotion>().enabled = false;
        }


    }
}
