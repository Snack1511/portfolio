using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class OnOFFMgr : MonoBehaviour {



	// Use this for initialization
	void Start () {

    }
	
	// Update is called once per frame
	void Update () {
        
	}

    public void StartGame()
    {
        SoundMgr.instance.PlaySound();
        SoundMgr.instance.soundchangeflag = 1;
        SoundMgr.instance.updateout = false;
        PlayerMove.mod.ModuleInit();
        Slime.mod.ModuleInit();
        SceneManager.LoadScene("PAP");
        PlayerMove.iResource = 0;
        PlayerMove2.iResource = 0;
    }

    public void GotoMenu()
    {
        SoundMgr.instance.PlaySound();
        SoundMgr.instance.soundchangeflag = 0;
        SoundMgr.instance.updateout = false;
        Destroy(GameObject.Find("SoundManager").gameObject);
        SceneManager.LoadScene("Start");
    }

    public void ExitGame()
    {
        SoundMgr.instance.PlaySound();
        Application.Quit();
    }

    public void Intutorial()
    {
        SoundMgr.instance.PlaySound();
        GameObject.Find("Canvas").transform.Find("InTutorial").gameObject.SetActive(true);
    }
    public void OutTutorial()
    {
        SoundMgr.instance.PlaySound();
        GameObject.Find("Canvas").transform.Find("InTutorial").gameObject.SetActive(false);
    }
    public void InStroy()
    {
        SoundMgr.instance.PlaySound();
        GameObject.Find("Canvas").transform.Find("InStory").gameObject.SetActive(true);
    }
    public void OutStory()
    {
        SoundMgr.instance.PlaySound();
        GameObject.Find("Canvas").transform.Find("InStory").gameObject.SetActive(false);
    }
}
