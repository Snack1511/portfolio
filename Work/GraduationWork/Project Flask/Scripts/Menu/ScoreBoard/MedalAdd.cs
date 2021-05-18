using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class MedalAdd : MonoBehaviour
{
    public int RoundNum;
    public int PlayerDegree;

    ScoreboardScript SBscript;
    List<Image> Medals = new List<Image>();
    Vector2 SizeValue = new Vector2(100, 0);
    Vector2 SizeValueY = new Vector2(0, 100);
    Vector2 Anchor = new Vector2(0, 0.5f);
    GameObject Img;
    private void Awake()
    {
        SBscript = transform.parent.parent.GetComponent<ScoreboardScript>();
        
    }
    private void OnEnable()
    {
        AddStageMedal();
        
        
    }
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    private void LateUpdate()
    {
        IncreaseMedal(Medals[RoundNum], PlayerDegree, false);
    }
    void AddStageMedal()
    {
        Img = new GameObject();
        Img.name = "Stage " + RoundNum + " Medal";
        Img.AddComponent<RectTransform>().SetParent(transform.GetChild(0));
        Img.GetComponent<RectTransform>().anchorMin = Anchor;
        Img.GetComponent<RectTransform>().anchorMax = Anchor;
        Img.GetComponent<RectTransform>().anchoredPosition3D = new Vector3(Img.GetComponent<RectTransform>().sizeDelta.x * 0.5f, 0, 0);
        Img.AddComponent<Image>().type = Image.Type.Tiled;
        Img.GetComponent<Image>().pixelsPerUnitMultiplier = SBscript.PixelMultiple;
        Medals.Add(Img.GetComponent<Image>());
    }
    void IncreaseMedal(Image img, int Degree = 0, bool flg = false)
    {
        if (img.GetComponent<Image>().sprite == null)
        {
            img.GetComponent<Image>().sprite = SBscript.sprites[Degree - 1];
        }
        if (flg)
        {
            
            img.GetComponent<RectTransform>().sizeDelta += SizeValue;
        }
        else
        {
            img.GetComponent<RectTransform>().sizeDelta = (SizeValue * (4 - Degree));
            img.GetComponent<RectTransform>().sizeDelta += SizeValueY;
        }
    }
    public void SetData(int RNum, int Degree)
    {
        RoundNum = RNum;
        PlayerDegree = Degree;
        
    }
    
}
