using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MedalEffect : MonoBehaviour
{
    // Start is called before the first frame update
    
    public float spd = 0.005f;
    public float MoveWidth = 100;
    public float MoveHeight = 100;

    ScoreboardScript SBscript;
    Image img;
    RectTransform RTr;
    Vector3 MaxSize = new Vector3(5, 5, 5);
    Vector3 ChangeValue = new Vector3(1, 1, 1);
    Vector3 WidthMoveValue, HeightMoveValue;
    bool EffectStartflg = true;
    bool EffectEndflg = false;
    void Start()
    {
        SBscript = transform.parent.GetComponent<ScoreboardScript>();
        img = GetComponent<Image>();
        RTr = GetComponent<RectTransform>();
        WidthMoveValue = new Vector3(MoveWidth, 0, 0);
        HeightMoveValue = new Vector3(0, MoveHeight, 0);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void LateUpdate()
    {
        MedalAdd_Effect(1);
    }
    void ChangeSprite(int n)
    {
        img.sprite = SBscript.sprites[n - 1];
        RTr.localScale = MaxSize;
    }
    void MedalAdd_Effect(int n)
    {
        if (!EffectEndflg)
        {
            if (EffectStartflg)
            {
                ChangeSprite(n);
                EffectStartflg = false;
            }
            if (RTr.localScale.x > ChangeValue.x - 0.05f && RTr.localScale.x > ChangeValue.x)
            {
                RTr.localScale -= ChangeValue * spd * Time.fixedDeltaTime;
            }
            else
            {
                RTr.localScale = ChangeValue;
                EffectEndflg = true;
            }
        }
    }
    void EffectionMove(Vector3 Value, float Plusflg = 1)
    {
        RTr.anchoredPosition3D += Value * Plusflg;
    }
    /*
     
     */
    
}
