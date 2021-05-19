using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class MedalAdd : MonoBehaviour
{
    public int RoundNum;
    public int PlayerDegree;
    public float spd = 0.05f;
    public int idxmax;

    int idx;
    ScoreboardScript SBscript;
    Image[] Medals = new Image[20];
    GameObject Img;
    private void Awake()
    {
        idx = 0;
        SBscript = transform.parent.parent.GetComponent<ScoreboardScript>();
        for(int i = 0; i < transform.childCount; i++)
        {
            Medals[i] = transform.GetChild(i).GetComponent<Image>();
        }
    }
    private void OnEnable()
    {
        
        //AddStageMedal();
    }
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void OnDisable()
    {
        if (!Medals[idxmax - 1].GetComponent<MedalEffect>().bPlayEnd)
        {
            for (int i = idx; i < idxmax; i++)
            {

                Medals[i].sprite = SBscript.sprites[PlayerDegree - 1];
                Medals[i].gameObject.SetActive(true);
                //Medals[i - 1].GetComponent<MedalEffect>().bLoadCheck = true;
            }
        }
    }
    private void LateUpdate()
    {
        MedalImgChange(PlayerDegree);
    }
    
    void MedalImgChange(int Degree)
    {
        if (idx == 0 || Medals[idx-1].GetComponent<MedalEffect>().bPlayEnd)
        {
            if (idxmax - idx > 0)//4 - Degree)
            {
                Medals[idx].sprite = SBscript.sprites[Degree - 1];
                Medals[idx].gameObject.SetActive(true);
                idx++;
            }
            
        }
        
    }

    public void SetData(int RNum, int Degree)
    {
        RoundNum = RNum;
        PlayerDegree = Degree;
        
    }
    
}
