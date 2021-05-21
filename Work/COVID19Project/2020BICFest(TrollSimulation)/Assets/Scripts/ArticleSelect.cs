using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using USERDEFINE;


public class ArticleSelect : USERDEFINE.ISelectable
{
    public ArticleData[] AD{ get; private set;}
    public bool ArticleSelected;
    public ArticleSelect()
    {
        AD = new ArticleData[10];
        AD[0] = ArticleData.Base;
        for (int i = 1; i < AD.Length; i++)
        {
            AD[i] = new ArticleData("Title" + i, "Content" + i, "Attribute_1\nAttribute_2\nAttribute_3", PolicyData.Base, new QuarantineData(), new Popular(), 0, 0, true);
        }
        ArticleSelected = false;
    }
    public void Select(int n = 0)
    {

    }
    public void ArticleSelectFlag()
    {
        ArticleSelected = true;
    }
}
