using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MedalEffect : MonoBehaviour
{
    // Start is called before the first frame update
    
    
    public bool bPlayEnd;
    float spd;
    RectTransform RTr;
    Vector3 MaxSize = new Vector3(2, 2, 2);
    Vector3 ChangeValue = new Vector3(1, 1, 1);
    private void Awake()
    {
        spd = transform.parent.GetComponent<MedalAdd>().spd;
        bPlayEnd = false;
        RTr = GetComponent<RectTransform>();
        RTr.localScale = Vector3.zero;
    }
    private void OnEnable()
    {
        
    }
    void Start()
    {
        
    }
    private void OnDisable()
    {
    }
    // Update is called once per frame
    void Update()
    {
        
    }
    private void LateUpdate()
    {
        EffectPlay();
    }
    void EffectPlay()
    {
        if (!bPlayEnd)
        {
            if (RTr.localScale.x < MaxSize.x)
            {
                RTr.localScale += ChangeValue * spd;
            }
            else
            {
                RTr.localScale = ChangeValue;
                bPlayEnd = true;
            }
        }
        
        
    }
    
}
