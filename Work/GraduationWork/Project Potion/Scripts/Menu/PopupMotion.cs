using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PopupMotion : MonoBehaviour
{
    RectTransform RTR;
    float IncreaseValue;
    public float MotionSpd = 30;
    public float Limit = 300;
    public Vector2 AspectVector = new Vector2(1, 1);

    
    void Start()
    {
        RTR = GetComponent<RectTransform>();
        RTR.sizeDelta = AspectVector * 10;
        //IncreaseMotion();
    }


    // Update is called once per frame
    void Update()
    {
        if (gameObject.activeSelf)
        {
            IncreaseMotion();
        }


    }

    private void OnDisable()
    {
        //GetComponent<PlayerSelectMotion>().enabled = true;
        ResetMotion();
    }

    void ResetMotion()
    {
        RTR.sizeDelta = AspectVector * 10;
        IncreaseValue = 0;
    }

    void IncreaseMotion()
    {

        Vector2 value = new Vector2(IncreaseValue, IncreaseValue);
        if (Time.timeScale != 0)
        {
            if (RTR.sizeDelta.x < Limit * AspectVector.x && RTR.sizeDelta.y < Limit * AspectVector.y)
            {
                RTR.sizeDelta += value;
                IncreaseValue += MotionSpd * Time.deltaTime;
            }
            else
            {
                RTR.sizeDelta = AspectVector * Limit;
                //GetComponent<PlayerSelectMotion>().enabled = false;
            }
        }
        else
        {
            if (RTR.sizeDelta.x < Limit * AspectVector.x && RTR.sizeDelta.y < Limit * AspectVector.y)
            {
                RTR.sizeDelta += value;
                IncreaseValue += MotionSpd * 0.04f;
            }
            else
            {
                RTR.sizeDelta = AspectVector * Limit;
                //GetComponent<PlayerSelectMotion>().enabled = false;
            }
        }

    }
}
