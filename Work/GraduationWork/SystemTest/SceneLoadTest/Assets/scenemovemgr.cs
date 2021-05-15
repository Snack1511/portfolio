using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class scenemovemgr : MonoBehaviour
{
    
    public Scene[] scenes;

    public MapObj map;
    
    // Start is called before the first frame update
    void Start()
    {
        DontDestroyOnLoad(gameObject);
        map = GameObject.Find("MapObj").GetComponent<MapObj>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space)) {
            var num = Random.Range(0, 5);
            SceneManager.LoadScene(num);
        }
        if (Input.GetKeyDown(KeyCode.Return)) {
            var num = Random.Range(0, 5);
            map.nextactive = num;
        }
    }
}
