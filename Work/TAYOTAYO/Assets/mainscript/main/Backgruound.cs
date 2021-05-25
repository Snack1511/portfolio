using UnityEngine;
using System.Collections;

public class Backgruound : MonoBehaviour {
    public const float scrollspeed = -1.2f;

    Material thisMatrial;
    // Use this for initialization
    void Start () {
	    thisMatrial = GetComponent< Renderer > ().material;
	}
	
	// Update is called once per frame
	void Update () {
        Vector2 newOffset = thisMatrial.mainTextureOffset;

        newOffset.Set(0, newOffset.x + (scrollspeed * Time.deltaTime));
        thisMatrial.mainTextureOffset = newOffset;
	}
}
