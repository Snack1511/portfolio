using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CListData
{
    bool PMFlag;
    string MoneyData;
    int MoneyValue;

    public CListData(bool flag = false, string data = "", int value = 0)
    {
        PMFlag = flag;
        MoneyData = data;
        MoneyValue = value;
    }
}
