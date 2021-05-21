using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UserSelectable : MonoBehaviour
{
    PolicySelect ChosenPolicy;
    int PolicyType;
    bool PolicySelectFlag;

    QuarantineGuideSelect ChosenQG;
    bool QGSelectFlag;

    public ArticleSelect ChosenArticle { get; private set; }
    bool ArticleSelectFlag;

    private void Awake()
    {
        ChosenPolicy = new PolicySelect();
        ChosenQG = new QuarantineGuideSelect();
        ChosenArticle = new ArticleSelect();
        
    }

    private void Start()
    {
        PolicyType = 0;
        PolicySelectFlag = false;
        //-----------Policy
        QGSelectFlag = false;
        //----------QuarantineGuideline
        ArticleSelectFlag = false;
        //----------Article
    }
    private void Update()
    {
        if (PolicySelectFlag)
        {
            ChosenPolicy.Select(PolicyType);
        }//Day 30 Update
        /*
        if (QGSelectFlag)
        {
            
        }//Day 7 Update
        */
        if (ArticleSelectFlag)
        {
            ChosenArticle.Select();
            
        }//Day 1 Update
    }

    public void FlagOnControl(int _Day)
    {
        if (_Day % 30 == 0)
        {
            PolicySelectFlag = true;
        }

        if (_Day % 7 == 0)
        {
            QGSelectFlag = true;
        }

        ArticleSelectFlag = true;

    }
    public void FlagOffControl() {
        if (ChosenPolicy.PolicySelected)
        {
            PolicySelectFlag = false;
        }
        /*if (ChosenQG.QuarantineSelected) {QGSelectFlag = false; }*/
        if (ChosenArticle.ArticleSelected)
        {
            ArticleSelectFlag = false;
        }
    }

}
