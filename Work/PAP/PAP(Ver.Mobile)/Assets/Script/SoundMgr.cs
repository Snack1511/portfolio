using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundMgr : MonoBehaviour {
    public AudioClip Ui;
    public AudioClip Menubgm;
    public AudioClip Playbgm;
    public AudioClip Resource;
    public AudioClip Module;
    public AudioClip walk;
    public AudioClip returnres;
    public AudioClip returnmod;
    public AudioClip TrainSound;
    public AudioClip Attsound;
    AudioSource sound;

    public int soundchangeflag = 0;
    public bool updateout = true;

    public static SoundMgr instance;
    private void Awake()
    {
        if (SoundMgr.instance == null)
        {
            SoundMgr.instance = this;
        }
        DontDestroyOnLoad(this.gameObject);
    }
    // Use this for initialization
    void Start () {
        sound = GetComponent<AudioSource>();

        updateout = false;
    }

    

    

    public void PlaySound()
    {
        sound.PlayOneShot(Ui);
    }

    public void GetResSound()
    {
        sound.PlayOneShot(Resource);
    }

    public void modsound()
    {
        sound.PlayOneShot(Module);
    }

    public void walksound()
    {
        
        sound.PlayOneShot(walk);
    }

    public void collectressound()
    {
        sound.PlayOneShot(returnres);
    }
    public void collectmodsound()
    {
        sound.PlayOneShot(returnmod);
    }
    public void AttEffectSound()
    {
        sound.PlayOneShot(Attsound);
    }
	// Update is called once per frame
	void Update () {
        if (!updateout)
        {
            ChangeBgm();
        }
        
    }

    void ChangeBgm()
    {
        switch (soundchangeflag)
        {
            case 0:
                sound.clip = Menubgm;
                sound.Play();
                updateout = true;
                break;
            case 1:
                sound.clip = Playbgm;
                sound.Play();
                updateout = true;
                break;
            case 2:
                sound.clip = TrainSound;
                sound.Play();
                updateout = true;
                break;
        }
        
    }
}
