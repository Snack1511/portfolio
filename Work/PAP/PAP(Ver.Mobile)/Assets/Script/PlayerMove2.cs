using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove2 : MonoBehaviour {

    public static Transform tTr;
	public static int iResource = 0;


    // Use this for initialization
    private void Awake()
    {

    }
    void Start () {
		tTr = GetComponent<Transform> ();

        StartCoroutine(ConsumptionResource());
    }

	// Update is called once per frame
	void Update () {
		tTr.Translate (GameManager.fDir*Time.deltaTime, 0.0f, 0.0f, Space.Self);
        changeres();
    }

    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag == "PlayerG"){
            GameManager gm = GameObject.Find("GameManager").GetComponent<GameManager>();
            gm.winflag = 1;
        }
        
    }

    IEnumerator ConsumptionResource()
    {
        if (iResource > 0)
        {
            iResource--;
        }

        yield return new WaitForSeconds(10f);
        
        StartCoroutine(ConsumptionResource());
        
    }

    void changeres()
    {
        if (Input.GetKeyDown(KeyCode.Q))
        {
            iResource = 30;
        }
        if (Input.GetKeyDown(KeyCode.W))
        {
            iResource = 50;
        }
        if (Input.GetKeyDown(KeyCode.E))
        {
            iResource = 80;
        }
        if (Input.GetKeyDown(KeyCode.R))
        {
            iResource = 100;
        }
    }
}
