using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    Transform Tr, Gunhole_Tr, PlayerTr, Tr_Shoot;
    SphereCollider Col;
    float Spd = 3f;
    public string Owner;
    public Vector3 Dir;

    // Start is called before the first frame update
    
    void Start()
    {
        Gunhole_Tr = GetComponent<Transform>().parent;
        PlayerTr = Gunhole_Tr.parent.transform;
        Tr = GetComponent<Transform>();
        if (gameObject.activeSelf)
        {
            Tr.SetParent(null);
        }
        Col = GetComponent<SphereCollider>();
    }
    

    // Update is called once per frame
    void Update()
    {
        Tr.Translate(Dir * Spd * Time.deltaTime, Space.World);
        StartCoroutine("BulletLiveTime");
    }

    private void OnTriggerEnter(Collider other)
    {
        Debug.Log(other.transform.parent.gameObject.name+"Hit");
        HitEnd();
    }

    IEnumerable BulletLiveTime() {

        yield return new WaitForSeconds(3f);
        HitEnd();
    }
    private void OnDisable()
    {
        if (Tr != null)
        {
            if (Tr.parent == null)
            {
                if (Gunhole_Tr != null)
                {
                    Tr.SetParent(Gunhole_Tr);
                }
            }
            Tr.position = Gunhole_Tr.position;
        }
    }
    void HitEnd() {
        gameObject.SetActive(false);
        
    }
}
