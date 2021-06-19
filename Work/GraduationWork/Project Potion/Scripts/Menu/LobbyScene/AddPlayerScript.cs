using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using Custom;
public class AddPlayerScript : MonoBehaviour
{
    float padding = 30;
    float sizex = 300;
    public List<GameObject> playerimg;
    public GameObject prefab;
    RectTransform RTr;
    // Start is called before the first frame update
    void Start()
    {
        playerimg = new List<GameObject>();
        RTr = GetComponent<RectTransform>();
    }

    // Update is called once per frame
    

    public void AddPlayer(SelectData _sd, float size, int n = 0)
    {
        if (playerimg.Count > 0)
        {
            Vector3 LastPos;
            for (int i = 0; i < playerimg.Count; i++)
            {
                playerimg[i].GetComponent<RectTransform>().position += new Vector3(-(size*0.5f + padding), 0, 0);
            }
            LastPos = playerimg[playerimg.Count - 1].GetComponent<RectTransform>().position;
            if (n + 1 > playerimg.Count)
            {
                if (transform.childCount <= playerimg.Count)
                {
                    playerimg.Add(Instantiate(prefab, transform));
                }
                else
                {
                    for (int i = 0; i < transform.childCount; i++)
                    {
                        if (!transform.GetChild(i).gameObject.activeSelf)
                        {
                            //Debug.Log("bb " + i);
                            transform.GetChild(i).gameObject.SetActive(true);
                            playerimg.Add(transform.GetChild(i).gameObject);
                            break;

                        }
                    }
                }
            }
            else
            {
                Debug.Log("aa " + (playerimg.Count - 1));
                /*for(int i = 0; i< playerimg.Count; i++)
                {
                    if (!playerimg[i].activeSelf)
                    {
                        Debug.Log("bb " + i);
                        playerimg[i].SetActive(true);
                        LastPos = playerimg[i].GetComponent<RectTransform>().position - new Vector3((size + padding * 2), 0, 0);
                        
                    }
                }
                */

            }
            playerimg[playerimg.Count - 1].GetComponent<RectTransform>().position = LastPos + new Vector3((size + padding*2), 0, 0);
        }
        else
        {
            playerimg.Add(Instantiate(prefab, transform));
        }
        playerimg[playerimg.Count - 1].GetComponent<PlayerSelect>().sd = _sd;
        playerimg[playerimg.Count - 1].GetComponent<PlayerSelect>().SetObjectDescription(_sd);
    }

    public void SetPlayeSelectObj(SelectData sd)
    {
        //transform.GetChild(sd.GetIndex()).GetComponent<PlayerSelect>().SetObjectDescription(sd);
        //playerimg[sd.GetIndex()].gameObject.name = "PlayerSelect" + sd.GetIndex();
        //playerimg[sd.GetIndex()].GetComponent<PlayerSelect>().SetObjectDescription(sd);
        //playerimg[sd.GetIndex()].GetComponent<PlayerSelect>().SetObjInputPair();

        //transform.GetChild(sd.GetIndex()).GetComponent<PlayerSelect>().SetModelName(sd, UISelect.GetComponent<SelectorControl>().GetModelNum());

    }

    public void RemovePlayer(int n, float size = 420)
    {
        /*if (playerimg.Count >= 1)
        {
            playerimg[playerimg.Count - 1].SetActive(false);
        }
        else
        {
            //playerimg[playerimg.Count - 1].SetActive(false);
        }*/
        //Vector3 LastPos;
        //Debug.Log(n);
        for (int i = 0; i < playerimg.Count; i++)
        {
            if (i <= n)
            {
                playerimg[i].GetComponent<RectTransform>().anchoredPosition3D += new Vector3(size*0.5f+padding, 0, 0);
            }
            else 
            {
                playerimg[i].GetComponent<RectTransform>().anchoredPosition3D += new Vector3(-(size * 0.5f + padding), 0, 0);
            }
            

        }
        Debug.Log(n);
        //playerimg[n].SetActive(false);
        playerimg.RemoveAt(n);
        if (GameObject.Find("InputMgr") != null)
        {
            UpdateplayerImg(n);
        }
        //LastPos = playerimg[playerimg.Count - 1].GetComponent<RectTransform>().position;
        //playerimg[playerimg.Count - 1].GetComponent<RectTransform>().position = LastPos - new Vector3((size + padding * 2), 0, 0);

    }

    public void UpdateplayerImg(int n)
    {
        InputMgr inputmgr = GameObject.Find("InputMgr").GetComponent<InputMgr>();
        inputmgr.idx -= 1;
        inputmgr.SData[n].ResetAll();
        inputmgr.SortSD();
        int idx = 0;
        for (int i = 0; i < playerimg.Count; i++)
        {
            if (playerimg[i].activeSelf)
            {
                Debug.Log(playerimg[i] + " " + inputmgr.SData[idx]);
                playerimg[i].GetComponent<PlayerSelect>().sd = inputmgr.SData[idx];
                playerimg[i].GetComponent<PlayerSelect>().SetObjectDescription(inputmgr.SData[idx]);
                idx++;
            }
        }
        /*if (GameObject.Find("InputMgr") != null)
        {
            InputMgr inputmgr = GameObject.Find("InputMgr").GetComponent<InputMgr>();
            inputmgr.idx -= 1;
            inputmgr.SData[n].ResetAll();
            inputmgr.SortSD();
            int idx = 0;
            for (int i = 0; i < playerimg.Count; i++)
            {
                if (playerimg[i].activeSelf)
                {
                    Debug.Log(playerimg[i] + " " + inputmgr.SData[idx]);
                    playerimg[i].GetComponent<PlayerSelect>().sd = inputmgr.SData[idx];
                    playerimg[i].GetComponent<PlayerSelect>().SetObjectDescription(inputmgr.SData[idx]);
                    idx++;
                }
            }
        }
        else
        {
            Debug.Log("InputMgr is Null");
        }*/
    }

}
