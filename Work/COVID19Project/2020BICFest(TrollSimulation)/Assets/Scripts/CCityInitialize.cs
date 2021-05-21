using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using USERDEFINE;

public class CCityInitialize
{
    
    //-------인구-------------
    Popular TotalPop;
    //-------증감치-----------
    Popular IncreasePop;
    //-------하루변동인구----------
    Popular TodayPop;
    //--------비율--------
    int Trollrate;//트롤률
    int Carryrate;//캐리율
    float TotalConfirmrate;//확진자비율
    float TotalExamrate;//검사율 -- > 확진자 수, 사망률에 간접적 영향
    float TotalDeadrate;//사망률
    float TotalCuredrate;//감염률
    float TotalQuarantinerate;//방역률 -->  감염률에 반비례적 영향
    //--------기타--------
    int Quarantinebudget;//방역예산(Changable) -- > 캐리율, 트롤율, 검사율, 방역률에 영향
    bool Extinctionflag;//봉쇄플래그 -- > 전체인구 => 0일때 true
    Queue<float> QuarantineSave;//날 별 격리자수 저장

    

    public CCityInitialize(Popular Pop)
    {
        TotalPop = Pop;
        IncreasePop = new Popular("Increase", "Increase");
        TodayPop = new Popular("Today","Today");

        Trollrate = Const.DefaultTroll;
        Carryrate = Const.DefaultCarry;
        TotalConfirmrate = 0;
        TotalCuredrate = 0;
        TotalDeadrate = 0;
        TotalExamrate = 0;
        TotalQuarantinerate = 0;

        Quarantinebudget = 0;
        Extinctionflag = false;
        QuarantineSave = new Queue<float>(Const.DefaultDayGone);
    }
    

    public void PopUpdate(int _Recoveryrate, int _Fatalityrate)
    {
        IncreaseUpdate(_Recoveryrate, _Fatalityrate);
        TotalPop.SetPop(IncreasePop);
        TodayPop.SetTodayPop(IncreasePop);
        TotalPop.CalTotalPop(IncreasePop.DEAD);
    }//하루 지날때마다 업데이트
    
    public void RateUpdate()
    {
        //----------------누적 변동치
        TotalExamrate = ((float)TotalPop.EXAMINATION / TotalPop.TOTAL * 100);
        TotalConfirmrate = ((float)TotalPop.CONFIRMED / TotalPop.EXAMINATION * 100);
        TotalDeadrate = ((float)TotalPop.DEAD / TotalPop.TOTAL * 100);
        TotalCuredrate = ((float)TotalPop.CURED/ TotalPop.CONFIRMED * 100);
        TotalQuarantinerate = ((float)TotalPop.QUARANTINE/ TotalPop.TOTAL*100);
        //----------------누적 변동치

    }//하루 지날때마다 업데이트

    public void SetExtinctionflag() {
        
        if (TotalPop.TOTAL <= 0) {
            Extinctionflag = true;
        }
    }//하루 지날때마다 확인

    public void IncreaseUpdate(int _Recoveryrate, int _Fatalityrate)
    {
        IncreasePop.IncreasePop(TotalPop.TOTAL ,Trollrate, Carryrate, _Recoveryrate, _Fatalityrate);
    }//전체인구 업데이트시 업데이트

    public void SetQuaranSave(bool DayChackflag)
    {
        QuarantineSave.Enqueue(TotalPop.QUARANTINE);
        if (DayChackflag)
        {
            TotalPop.CalQuarantine(QuarantineSave.Dequeue());
        }
    }//하루 지날때마다 실행
    
    public void LocalEventLaunch(int _Trollrate = Const.DefaultTroll, int _Carryrate = Const.DefaultCarry)
    {
        //SetQuarantinebudget();
        SetTrollCarry(_Trollrate, _Carryrate);
        //Debug.Log("GetLocalEvent");
    }//하루지날때마다 실행

    public void SetQuarantinebudget(int Increase)
    {
        Quarantinebudget += Increase;
    }//이벤트마다 업데이트

    public void SetTrollCarry(int _Trollrate, int _Carryrate)
    {
        Trollrate = _Trollrate;
        Carryrate = _Carryrate;
    }//이벤트때마다 실행

    public Popular GetPop(string name = "")
    {
        if (name == "Increase")
        {
            return IncreasePop;
        }
        else if (name == "Today")
        {
            return TodayPop;
        }
        else
        {
            return TotalPop;
        }
    }

    public int BUDGET {
        get { return Quarantinebudget; }
    }
    public bool EXTICNT {
        get { return Extinctionflag; }
    }

    //=========DebugLine
    public int RATE_TROLL { get { return Trollrate; } }
    public int RATE_CARRY { get { return Carryrate; } }
    public float RATE_EXAM { get { return TotalExamrate; } }
    public float RATE_CONFIRM { get { return TotalConfirmrate; } }
    public float RATE_DEAD { get { return TotalDeadrate; } }
    public float RATE_CURED { get { return TotalCuredrate; } }
    public float RATE_QUARANTINE { get { return TotalQuarantinerate; } }
}
