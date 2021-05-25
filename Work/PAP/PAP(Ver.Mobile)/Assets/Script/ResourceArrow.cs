using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ResourceArrow : MonoBehaviour {

    Vector2 targetPos;
    Vector2 PlayerPos;


    Transform tr;

    public RFscript rfscript;

    void Start()
    {
        tr = GetComponent<Transform>();
        rfscript = GameObject.Find("ResourceFactory").GetComponent<RFscript>();
    }


    void Update()
    {

    }

    private void FixedUpdate()
    {
        moveArrow();
    }

    void moveArrow()
    {
        targetPos = GetResDir();
        PlayerPos = GameObject.FindGameObjectWithTag("Collector").GetComponent<Transform>().position;
        float dist = Vector2.Distance(targetPos, PlayerPos);
        float Cos = (targetPos.x - PlayerPos.x) / dist;
        float Sdegree = 0;
        float Cdegree = 0;
        Cdegree = Mathf.Acos(Cos);
        if (targetPos.y - PlayerPos.y >= 0)
        {
            Sdegree = Mathf.Acos(Cos);
        }
        else
        {
            Sdegree = Mathf.Acos(Cos) + Mathf.PI;
        }



        float SetDeg = 180 / Mathf.PI;
        float angle = Cdegree * SetDeg;

        if (targetPos.y - PlayerPos.y < 0)
        {
            angle *= -1;
        }

        tr.position = new Vector2(Mathf.Cos(Cdegree) + PlayerPos.x, Mathf.Sin(Sdegree) + PlayerPos.y);
        Quaternion rotate = Quaternion.AngleAxis(angle - 90, Vector3.forward);
        tr.rotation = rotate;




    }

    Vector2 GetResDir()
    {
        Vector2 _dir;
        float min = 100.0f;
        int index = 0;
        for (int i = 0; i < rfscript.maxCount; i++)
        {
            float dist = Vector2.Distance(rfscript.resourcepool[i].transform.position, tr.position);
            if (dist < min)
            {
                min = dist;
                index = i;
            }
        }
        _dir = rfscript.resourcepool[index].transform.position;
        return _dir;


    }//자원 스폰장소의 Transform리턴
}
