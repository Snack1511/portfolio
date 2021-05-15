using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CubeControl : MonoBehaviour
{
    Transform tr;
    Vector3 dir;
    Vector3 startpos;
    // Start is called before the first frame update
    void Start()
    {
        DontDestroyOnLoad(gameObject);
        tr = GetComponent<Transform>();
        startpos = tr.position;
        var flg = Random.Range(0, 6);
        if(flg % 2 == 0)
        {
            dir = Vector3.right;
        }
        else
        {
            dir = Vector3.forward;
        }
    }

    // Update is called once per frame
    void Update()
    {
        tr.Translate(dir * 2f * Time.deltaTime);
        Debug.Log((tr.position - startpos).magnitude);
        if ((tr.position - startpos).magnitude > 6f)
        {
            dir *= -1f;
        }
    }
}
