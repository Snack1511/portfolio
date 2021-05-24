using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class BarScript : MonoBehaviour
{
    Transform Player_Tr;
    float Horizon = 0f;
    Vector2 Player_Dir = new Vector2(0f, 0f);
    float Player_Speed = 5f;

    float NowRPM = 0f;
    float TickTime = 0f;
    // Start is called before the first frame update
    void Start()
    {
        Player_Tr = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        Horizon = Input.GetAxis("Horizontal");
        TickTime += Time.deltaTime;
        if (Input.GetKey(KeyCode.UpArrow)) {
            if (TickTime >= 0.04f)
            {
                NowRPM += 0.5f;
                TickTime = 0f;
            }
        }
        if (Input.GetKey(KeyCode.DownArrow)) {
            if (TickTime >= 0.04f)
            {
                NowRPM -= 0.5f;
                TickTime = 0f;
            }
        }
        
        if (NowRPM > 100) { NowRPM = 100f; }
        if (NowRPM < -100) { NowRPM = -100f; }
        if (Input.GetKeyDown(KeyCode.Space)) {
            Debug.Log(NowRPM);
        }
        Player_Dir.x = Horizon;
        Player_Tr.Translate(Player_Dir * Player_Speed * Time.deltaTime);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.name == "Ball")
        {
            collision.gameObject.GetComponent<BallScript>().RPM = NowRPM;
            Debug.Log(collision.gameObject.GetComponent<BallScript>().RPM);
        }
    }
}
