using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ModuleArrow : MonoBehaviour {

    Vector2 targetPos;
    Vector2 PlayerPos;


    Transform tr;


    void Start()
    {
        tr = GetComponent<Transform>();
    }


    void Update()
    {
        if (Slime.mod.CheckMod())
        {
            this.gameObject.SetActive(false);
        }
    }

    private void FixedUpdate()
    {
        moveArrow();
    }

    void moveArrow()
    {
        targetPos = GetModDIr();
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

    Vector2 GetModDIr()
    {
        Vector2 _dir;
        float min = 100.0f;
        float dist;
        int index = 0;
        GameObject[] Modules = GameObject.FindGameObjectsWithTag("Module");
        for (int i = 0; i < Modules.Length; i++)
        {
            dist = Vector2.Distance(Modules[i].GetComponent<Transform>().position, tr.position);

            if (dist < min)
            {
                if (checkmod(Modules[i]))
                {
                    min = dist;
                    index = i;
                }
            }
        }
        _dir = Modules[index].GetComponent<Transform>().position;


        return _dir;
    }


    bool checkmod(GameObject obj)
    {
        bool flag = false;

        if (obj.name == "Engine(Clone)")
        {
            if (!PlayerMove.mod.Engine)
            {
                flag = true;
            }
        }
        if (obj.name == "Frame(Clone)")
        {
            if (!PlayerMove.mod.Frame)
            {
                flag = true;
            }
        }
        if (obj.name == "Gear(Clone)")
        {
            if (!PlayerMove.mod.Gear)
            {
                flag = true;
            }
        }
        if (obj.name == "Wheel(Clone)")
        {
            if (!PlayerMove.mod.Wheel)
            {
                flag = true;
            }
        }
        if (obj.name == "Reacter(Clone)")
        {
            if (!PlayerMove.mod.Reacter)
            {
                flag = true;
            }
        }

        return flag;
    }
}

