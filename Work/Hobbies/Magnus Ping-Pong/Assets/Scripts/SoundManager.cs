using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Custom;
public class SoundManager : MonoBehaviour
{
    public static SoundManager Instance;
    public AudioClip BallCollision;
    public AudioClip ButtonClick;
    public AudioClip GoalBall;
    public AudioClip StartRound;
    public AudioClip Coundown;

    AudioSource source;
    // Start is called before the first frame update
    void Start()
    {
        if (Instance == null)
        {
            Instance = this;
        }
        var a = GameObject.Find("SoundMgr");
        if (a != null && a != gameObject)
        {
            Destroy(gameObject);
            return;
        }
        DontDestroyOnLoad(gameObject);
        source = GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    AudioClip GetAudio(SFXTAG tag) => tag switch
    {
        SFXTAG.BUTTONCLICK => ButtonClick,
        SFXTAG.BALLCOLLISION => BallCollision,
        SFXTAG.COUNTDONW => Coundown,
        SFXTAG.STARTROUND => StartRound,
        SFXTAG.GOAL => GoalBall,
        _ => null

    };
    public void PlaySFX(SFXTAG tag)
    {
        source.PlayOneShot(GetAudio(tag));
    }
}
