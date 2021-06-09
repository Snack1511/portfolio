using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Boundary : MonoBehaviour
{
    public PlayerSet GetPoint;
    // Start is called before the first frame update
    void Start()
    {
        
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.tag == "BALL")
        {
            Debug.Log("AAA");
            GetPoint.AddPoint();
        }
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
