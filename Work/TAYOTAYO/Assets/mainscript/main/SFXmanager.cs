using UnityEngine;
using System.Collections;

public class SFXmanager : MonoBehaviour {
    public AudioClip symberse, hat_O, hat_C, kick;
    AudioSource Audio;
    // Use this for initialization

    public static SFXmanager instance;

    void Awake()
    {
        if (SFXmanager.instance == null) { SFXmanager.instance = this; }
    }
    void Start () {
        Audio = GetComponent<AudioSource>();
        Audio.volume = 1.0f;
    }
	
	void Update () {
	}
    public void soundEffect(uint a)
    {
        switch(a){
            case 1:
                
                Audio.PlayOneShot(symberse);
                
                gameroot.OnOff = 0;
                break;
            case 2:
                
                if (enemy_G.count == 4)
                {
                    Audio.PlayOneShot(hat_O);
                }
                else
                {
                    Audio.PlayOneShot(hat_C);
                }
                gameroot.OnOff = 0;
                break;
            case 3:
                
                Audio.PlayOneShot(kick);
                    
                
                gameroot.OnOff = 0;
                break;
        }

    }
}
