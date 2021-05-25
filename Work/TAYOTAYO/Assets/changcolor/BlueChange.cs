using UnityEngine;
using System.Collections;

public class BlueChange : MonoBehaviour {

	// Use this for initialization
	void Start () {
        
    }
	
	// Update is called once per frame
	void Update () {
        transform.Translate(new Vector2(-1.5f * Time.deltaTime, 0.0f));
    }
    void OnTriggerEnter2D(Collider2D col_color)
    {
        if (col_color.gameObject.tag.Equals("Player"))
        {
            Destroy(gameObject);
            gameroot.flag = Random.Range(1, 4);
        }
    }
}
