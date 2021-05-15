using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ButtonScript : MonoBehaviour
{
    public GameObject MainCanvas, MultiCanvas, OptionCanvas;
    public void btnEventStart() {
        Debug.Log("Start");
        MainCanvas.SetActive(false);
        MultiCanvas.SetActive(true);

    }
    public void EventStartToBack()
    {
        Debug.Log("back");
        MultiCanvas.SetActive(false);
        MainCanvas.SetActive(true);
    }
    public void btnEventOption()
    {
        Debug.Log("Option");
        MainCanvas.SetActive(false);
        OptionCanvas.SetActive(true);

    }
    public void btnEventExit() {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }


    public void btnEventLocal() {
        //Debug.Log("Local");
        SceneManager.LoadScene("Scenes/1.LocalRobbyScene");
    }
    public void btnEventOnline() {
        Debug.Log("Online");
    }
    public void btnEventBack()
    {
        OptionCanvas.SetActive(false);
        MainCanvas.SetActive(true);
        Debug.Log("Back");
    }

    
}
