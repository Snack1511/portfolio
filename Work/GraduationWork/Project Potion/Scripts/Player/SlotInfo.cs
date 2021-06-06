using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class SlotInfo : MonoBehaviour
{
    public int index;
    RectTransform RTr;

    private void Awake()
    {
        Debug.Log("SlotInfo");
        InitSlotInfo();
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void InitSlotInfo()
    {
        gameObject.AddComponent<RectTransform>();
        gameObject.AddComponent<Image>();
        RTr = GetComponent<RectTransform>();
        gameObject.SetActive(false);
    }

    public void SetSlotInfo()
    {
        RTr.anchoredPosition3D = new Vector3(index - 1, 0, 0);
        RTr.Rotate(new Vector3(35, 0, 0), Space.Self);
        RTr.sizeDelta = new Vector2(1, 1);
    }
}
