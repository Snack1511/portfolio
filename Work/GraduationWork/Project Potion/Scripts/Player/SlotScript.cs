using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class SlotScript : MonoBehaviour
{
    public int iSlotnum = 3;
    public bool bSlotOn = false;
    int idx = 0;
    List<GameObject> Slots = new List<GameObject>();

    private void Awake()
    {
        InitSlots(iSlotnum);
        gameObject.SetActive(false);
    }
    // Start is called before the first frame update
    
    private void OnEnable()
    {
        StartCoroutine("SlotOnoff");
    }
    // Update is called once per frame
    void Update()
    {
        
    }

    void InitSlots(int n)
    {
        for(int i = 0; i < n; i++)
        {
            SetSlotInfo(i);
        }
    }

    void SetSlotInfo(int n)
    {
        Slots.Add(new GameObject());
        Slots[n].transform.SetParent(gameObject.transform);
        Slots[n].AddComponent<SlotInfo>().index = n;
        Slots[n].GetComponent<SlotInfo>().SetSlotInfo();
        Slots[n].name = "Slot" + n;
        /*Slots[n].AddComponent<RectTransform>().anchoredPosition3D = new Vector3(n - 1, 3, 0);
        Slots[n].GetComponent<RectTransform>().sizeDelta = new Vector2(1, 1);
        Slots[n].AddComponent<Image>();*/
        //Slots[n].SetActive(false);
        
    }
    public void FillSlot(string str)
    {
        //str로 이름받아서 아이콘 불러올수 있게
        Slots[idx].GetComponent<Image>().color = Color.red;
        Slots[idx].SetActive(true);
        idx++;
    }
    public void ReleaseSlot()
    {
        Slots[idx-1].GetComponent<Image>().color = Color.white;
        Slots[idx-1].SetActive(false);
        idx--;

    }
    IEnumerator SlotOnoff()
    {
        
        yield return new WaitForSeconds(3);
        gameObject.SetActive(false);
        bSlotOn = false;
        
    }
    
}
