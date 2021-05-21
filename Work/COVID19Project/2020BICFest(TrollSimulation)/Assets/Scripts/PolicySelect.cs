using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using USERDEFINE;



public class PolicySelect : USERDEFINE.ISelectable
{
    public PolicyData ChosenPolicy { get; private set; }
    public bool PolicySelected;
    public PolicySelect()
    {
        ChosenPolicy = new PolicyData();
        PolicySelected = false;
    }
    public void Select(int n = 0)
    {
        switch ((POLICYLIST)n)
        {
            case POLICYLIST.BASE:
                ChosenPolicy = PolicyData.Base;
                break;
            case POLICYLIST.CAPITALISM:
                ChosenPolicy = PolicyData.Capitalism;
                break;
            case POLICYLIST.QUARANTINISM:
                ChosenPolicy = PolicyData.Quarantinism;
                break;
            case POLICYLIST.LIBERALISM:
                ChosenPolicy = PolicyData.Liberalism;
                break;
            case POLICYLIST.ANARCHISM:
                ChosenPolicy = PolicyData.Anarchism;
                break;
        }
    }
    public void GetEvent() { }//Policy를 통한 이벤트 불러오기
    public void PolicySelectFlag()
    {
        PolicySelected = true;
    }


}
