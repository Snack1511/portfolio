using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerSet : MonoBehaviour
{
    public bool bGetPoint = false;
    public int Point = 0;
    Transform tr;
    Vector2 DefaultPos;
    BarScript Bar;
    // Start is called before the first frame update
    void Start()
    {
        tr = GetComponent<Transform>();
        Bar = GetComponent<BarScript>();
        DefaultPos = tr.position;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    public void AddPoint()
    {
        Point++;
        bGetPoint = true;
    }
    public void ResetPlayerset()
    {
        bGetPoint = false;
        tr.position = DefaultPos;
        Bar.ResetBarValues();
    }
    public Vector2 POS
    {
        get { return tr.position; }
    }
    public BarScript BAR
    {
        get { return Bar; }
    }
}
