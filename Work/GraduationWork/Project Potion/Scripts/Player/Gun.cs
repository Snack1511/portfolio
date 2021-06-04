using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    List<GameObject> Bullets = new List<GameObject>();
    Transform Tr;
    int Idx;
    public Control control;
    private void Awake()
    {
        Tr = GetComponent<Transform>();
        /*
         SetBullet();
         */
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
       
        
    }

    void OnTriggerEnter(Collider other) {
        if (other.tag == "Player") {
        
        }
    }
    
    
    IEnumerator ShootDelay() {
        Bullets[Idx].SetActive(true);
        Bullets[Idx].GetComponent<Bullet>().Dir = control.AimDir;
        yield return new WaitForSeconds(1f);
        Idx += 1;
    }

    void SetBullet() {
        control = transform.root.gameObject.GetComponent<Control>();
        for (int i = 0; i < 15; i++)
        {
            Bullets.Add(Instantiate(Resources.Load<GameObject>("Prefabs/Bullet")));
            Bullets[i].name = gameObject.transform.parent.parent.name + "Bullet" + i;
            Bullets[i].transform.localScale *= 0.2f;
            Bullets[i].transform.SetParent(Tr);
            Bullets[i].transform.position = Tr.position;
            Bullets[i].SetActive(false);

            Bullets[i].name = gameObject.transform.parent.parent.name + "Bullet" + i;
            Bullets[i].GetComponent<Bullet>().Owner = control.gameObject.name;
        }

        Idx = 0;
    }

    void ShootBullet() {
        if (Idx >= 15) { Idx = 0; }
        if (control.bAttackflg)
        {
            StartCoroutine("ShootDelay");

        }
    }
}
