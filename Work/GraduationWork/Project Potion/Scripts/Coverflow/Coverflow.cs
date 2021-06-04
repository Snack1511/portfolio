using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class Coverflow : MonoBehaviour
{
    int idx = 0;
    int Max = 7;
    List<RectTransform> Imgs = new List<RectTransform>();
    // Start is called before the first frame update
    void Start()
    {
        var cover = transform.GetChild(0).GetChild(2);
        for(int n = 0; n < Max; n++)
        {
            Imgs.Add(cover.GetChild(n).GetComponent<RectTransform>());
            Imgs[n].gameObject.SetActive(false);
        }


        InitCoverflow();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void InitCoverflow()
    {
        Imgs[0].gameObject.SetActive(true);
        Imgs[0].anchoredPosition = new Vector2(0, 0);
        Imgs[0].sizeDelta = new Vector2(400, 600);

        Imgs[Max - 1].gameObject.SetActive(true);
        Imgs[Max - 1].anchoredPosition = new Vector2(-500, 0);
        Imgs[Max - 1].sizeDelta = new Vector2(200, 300);

        Imgs[1].gameObject.SetActive(true);
        Imgs[1].anchoredPosition = new Vector2(500, 0);
        Imgs[1].sizeDelta = new Vector2(200, 300);
    }

    void SetCoverPos(bool Lflg, int max)
    {
        if (Lflg)
        {
            idx += 1;
        }
        else
        {
            idx -= 1; 
        }
        if (idx < 0) idx = max - 1;
        else if (idx > max - 1) idx = 0;
        int previous = idxchange(idx - 1, max), current = idxchange(idx, max), next = idxchange(idx + 1, max);


        Imgs[current].gameObject.SetActive(true);
        Imgs[current].anchoredPosition = new Vector2(0, 0);
        Imgs[current].sizeDelta = new Vector2(400, 600);

        Imgs[previous].gameObject.SetActive(true);
        Imgs[previous].anchoredPosition = new Vector2(-500, 0);
        Imgs[previous].sizeDelta = new Vector2(200, 300);

        Imgs[next].gameObject.SetActive(true);
        Imgs[next].anchoredPosition = new Vector2(500, 0);
        Imgs[next].sizeDelta = new Vector2(200, 300);
    }

    int idxchange(int n, int max) {
        if (n < 0) return (n + max);
        else if (n >= max) return (n - max);
        else return n;

    }
    
    public void btnLeft() {
        //Debug.Log("Left");
        Imgs[idxchange(idx - 1, Max)].gameObject.SetActive(false);
        SetCoverPos(true, Max);
    }
    public void btnRight() {
        Imgs[idxchange(idx + 1, Max)].gameObject.SetActive(false);
        SetCoverPos(false, Max);
    }

  
}
