using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerSet : MonoBehaviour
{
    public bool bGetPoiint = false;
    public int Point = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void AddPoint()
    {
        Point++;
        bGetPoiint = true;
    }
    public void ResetPlayerset()
    {
        bGetPoiint = false;
    }
}
