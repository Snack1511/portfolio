using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SystemManager : MonoBehaviour
{
    GameObject Title;
    GameObject ListAdd;
    GameObject Calculate;

    int TotalPeople, NoneMeetingFeePeople;

    List<CListData> Lists;

    GameObject DelBtn;

    GameObject ScrollViewContent;

    GameObject ListField;
    // Start is called before the first frame update
    private void Awake()
    {
        Title = GameObject.Find("Title");
        ListAdd = GameObject.Find("ListAdd");
        Calculate = GameObject.Find("Calculate");
        Lists = new List<CListData>();
        Lists.Add(new CListData());
        DelBtn = GameObject.Find("DelBtn");
        ScrollViewContent = GameObject.Find("Content");
        ListField = GameObject.Find("ListField");
    }
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        SubOnOff();
    }
    public void DisplaySetting(bool bTitle, bool bList, bool bCal)
    {
        Title.SetActive(bTitle);
        ListAdd.SetActive(bList);
        Calculate.SetActive(bCal);
    }

    public void GetPeople() {
        TotalPeople = int.Parse(GameObject.Find("TotalInputField").GetComponent<InputField>().text);
        NoneMeetingFeePeople = int.Parse(GameObject.Find("NoneMeetingFeeInputField").GetComponent<InputField>().text);
    }

    public void Click_AddBtn() {
        Lists.Add(new CListData());
        ScrollHeightSet(true);
        CreateListField();
    }
    public void Click_Delete() {
        int n = Lists.Count - 1;
        Lists.RemoveAt(n);
        ScrollHeightSet(false);
        DeleteListField();
    }
    public void SubOnOff()
    {
        if (Lists.Count <= 1 && DelBtn.activeSelf)
        {
            DelBtn.SetActive(false);
        }
        else if (Lists.Count > 1 && !DelBtn.activeSelf) {
            DelBtn.SetActive(true);
        }
    }
    void ScrollHeightSet(bool flag) {
        if (flag)
        {
            ScrollViewContent.GetComponent<RectTransform>().sizeDelta += new Vector2(0f, 124f);
        }
        else
        {
            ScrollViewContent.GetComponent<RectTransform>().sizeDelta += new Vector2(0f, - 124f);
        }
    }

    void CreateListField() {
        Instantiate(ListField, ScrollViewContent.transform);
    }
    void DeleteListField() {
        Destroy(ScrollViewContent.GetComponentInChildren<Transform>().GetChild(ScrollViewContent.GetComponentInChildren<Transform>().childCount-1).gameObject);
    }
}
