using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class ScoreboardScript : MonoBehaviour
{
    // Start is called before the first frame update
    public Sprite[] sprites = new Sprite[3];
    public float Height = 100;
    public float padding = 30;
    public float PixelMultiple = 2.5f;
    public bool bPlayEnd;
    Vector3 HeightMoveValue;
    UIManager UIMgr;
    private void Awake()
    {
        
    }
    public void InitScoreboard(UIManager UI)
    {
        bPlayEnd = false;
        HeightMoveValue = new Vector3(0, Height + padding, 0);
        UIMgr = UI;
        for (int i = 1; i <= UI.ROUNDMGR.PMGR.PlayerCount; i++)
        {
            InitScoreMeter(i);
        }//룸매니저쪽으로 받아줘야함
    }
    private void OnEnable()
    {
        
        if (UIMgr != null && UIMgr.ROUNDMGR.ReadRoundCheck)
        {
            for (int i = 1; i <= UIMgr.ROUNDMGR.PMGR.PlayerCount; i++)
            {
                transform.GetChild(i).GetComponent<RectTransform>().GetChild(1).GetComponent<MedalAdd>().SetData(
                    UIMgr.ROUNDMGR.RoundNum,
                    UIMgr.ROUNDMGR.PMGR.ReadPlyerDatas()[i - 1].GetPlayerData().DEGREE,
                    UIMgr.ROUNDMGR.PMGR.ReadPlyerDatas()[i - 1].GetPlayerData().POINT
                    );
                transform.GetChild(i).GetComponent<RectTransform>().GetChild(1).GetComponent<MedalAdd>().idxmax = UIMgr.ROUNDMGR.PMGR.ReadPlyerDatas()[i - 1].GetPlayerData().POINT;
            }
        }
    }
    void Start()
    {
        
        //InitScoreMeter();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnDisable()
    {
        bPlayEnd = false;
    }
    void InitScoreMeter(int ChildNum = 1)
    {
        var objrtr = transform.GetChild(ChildNum).GetComponent<RectTransform>();
        objrtr.anchoredPosition3D += (HeightMoveValue * 0.5f);
        objrtr.anchoredPosition3D -= (HeightMoveValue) * ChildNum;
        objrtr.gameObject.SetActive(true);
    }


    

    
    
}
