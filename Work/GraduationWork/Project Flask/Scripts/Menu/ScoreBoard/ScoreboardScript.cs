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
    public bool Readflg = false;
    GameObject MedalEffect;
    Vector3 HeightMoveValue;
    private void Awake()
    {
        HeightMoveValue = new Vector3(0, Height + padding, 0);
        MedalEffect = transform.GetChild(transform.childCount - 1).gameObject;
        for (int i = 0; i < GameManager.GM.PlayerCount; i++)
        {
            InitScoreMeter(i);
        }
    }
    private void OnEnable()
    {
        if (GameManager.GM.ReadRoundCheck)
        {
            for (int i = 0; i < GameManager.GM.PlayerCount; i++)
            {
                transform.GetChild(i).GetComponent<RectTransform>().GetChild(1).GetComponent<MedalAdd>().SetData(
                    GameManager.GM.RoundNum,
                    GameManager.GM.ReadPlyerDatas[i].GetPlayerData().Degree
                    );
            }
            Readflg = true;
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
        
    }
    void InitScoreMeter(int ChildNum = 0)
    {
        var objrtr = transform.GetChild(ChildNum).GetComponent<RectTransform>();
        objrtr.anchoredPosition3D += (HeightMoveValue * 0.5f);
        objrtr.anchoredPosition3D -= (HeightMoveValue) * ChildNum;
        objrtr.gameObject.SetActive(true);
    }


    

    
    
}
