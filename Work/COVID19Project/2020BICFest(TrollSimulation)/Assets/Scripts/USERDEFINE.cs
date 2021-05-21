
namespace USERDEFINE
{

    public class Const
    {
        //-------상수값정의-------
        public const int DefaultTroll = 50;
        public const int DefaultCarry = 50;
        public const int DefaultDayGone = 14;
    }
    public class Functions {
        public static string GetFormat(float n)
        {

            return string.Format("{0:#,###}", n);
        }

        public static string GetFormat_N2(float n)
        {

            return string.Format("{0:F2}", n);
        }

        public static string GetFormat_Int(float n)
        {
            int value = 0;
            value = UnityEngine.Mathf.RoundToInt(n);
            return string.Format("{0:#,###;#,###;0}", value);
        }
    }
    public struct Popular
    {
        string tag;
        //-----도시이름
        string name;
        //-------인구-------------
        float TotalPopular;//전체인구
        float Examination; //검사자 // 하루단위만 보여줌
        float Quarantine; //격리자
        float Confirmedcase;//확진자
        float Curedcase;//완치자 // 하루단위만 보여줌
        float Deadcase;//사망자

        public Popular(string _tag, string _name, float _totalPop = 0, float _examination = 0, float _quarantine = 0, float _confirmedcase = 0, float _curedcitizen = 0, float _dead = 0)
        {
            tag = _tag;
            name = _name;
            TotalPopular = _totalPop;
            Examination = _examination;
            Quarantine = _quarantine;
            Confirmedcase = _confirmedcase;
            Curedcase = _curedcitizen;
            Deadcase = _dead;
        }

        public void SetPop(Popular a)
        {
            //TotalPopular += a.TOTAL;
            Examination += a.Examination;
            Quarantine += a.QUARANTINE;
            Confirmedcase += a.CONFIRMED;
            Curedcase += a.CURED;
            Deadcase += a.DEAD;

        }

        public void SetTodayPop(Popular a) {
            Examination = a.Examination;
            Quarantine = a.QUARANTINE;
            Confirmedcase = a.CONFIRMED;
            Curedcase = a.CURED;
            Deadcase = a.DEAD;
        }//TodayPop전용

        //-------------Update용
        public void CalTotalPop(float _Dead)
        {
            TotalPopular -= _Dead;
        }

        public void CalQuarantine(float Release)
        {
            Quarantine -= Release;
        }

        //--------------Increase용
        public void IncreasePop(float Total, float _trollrate, float _carryrate, float _Recoveryrate, float _Fatalityrate)
        {
            SetExamination(Total, _trollrate, _carryrate);
            SetQuarantine(Total, _trollrate, _carryrate);
            SetConfirmed(_trollrate);
            SetCured(_carryrate, _Recoveryrate);
            SetDead(_trollrate, _Fatalityrate);
        }
        
        public void SetExamination(float Total, float _trollrate, float _carryrate) {
            Examination = (Total * (_trollrate * _carryrate) * 0.01f * 0.01f);
            Examination = Ceiling(Examination);
        }//검사자 계산
        public void SetQuarantine(float Total, float _trollrate, float _carryrate) {
            float Runner = Examination * _trollrate * 0.01f;
            float Carry = (Total * _carryrate * 0.01f);
            Quarantine = Examination + Runner + Carry;
            Quarantine = Ceiling(Quarantine);
        }//격리자 계산
        public void SetConfirmed(float _trollrate) {
            Confirmedcase = (Examination * _trollrate * 0.01f);
            Confirmedcase = Ceiling(Confirmedcase);
        }//확진자 계산
        public void SetCured(float _carryrate, float _Recoveryrate) {
            float value = (Confirmedcase * 0.01f * _carryrate);
            Curedcase = (value * _Recoveryrate * 0.01f);
            Curedcase = Ceiling(Curedcase);
            Confirmedcase -= Curedcase;
        }//완치자 계산
        public void SetDead(float _trollrate, float _Fatalityrate) {
            float value = (Confirmedcase * 0.01f *  _trollrate);
            Deadcase = (value * _Fatalityrate  * 0.01f);
            Deadcase = Ceiling(Deadcase);
            Confirmedcase -= Deadcase;
        }//사망자계산

        //-------------내부변수 변경용
        private float Ceiling(float n)
        {
            float value = 0f;
            if (n > 0)
            {
                value = n - (n - (int)n) + 1;
            }
            return value;
        }
        
        //-------------내부변수 참조용
        public string TAG { get { return tag; } }
        public string NAME { get { return name; } }
        public float TOTAL { get { return TotalPopular; } }
        public float EXAMINATION { get { return Examination; } }
        public float QUARANTINE { get { return Quarantine; } }
        public float CONFIRMED { get { return Confirmedcase; } }
        public float CURED { get { return Curedcase; } }
        public float DEAD { get { return Deadcase; } }


        //----------Operator
        public static Popular operator +(Popular a, Popular b) {
            a.TotalPopular += b.TotalPopular;
            a.Examination += b.Examination;
            a.Quarantine += b.Quarantine;
            a.Confirmedcase += b.Confirmedcase;
            a.Curedcase += b.Curedcase;
            a.Deadcase += b.Deadcase;
            return a;
        }

        //----------DebugLine
        
    }
    public enum POLICYLIST:int
    {
        BASE = 0,
        CAPITALISM,
        QUARANTINISM,
        LIBERALISM,
        ANARCHISM

    }
    public interface ISelectable
    {
        //void Change();
        void Select(int n);
    }
    public struct PolicyData
    {
        int DayIncreaseTrollrate;
        int DayInceeaseCarryrate;
        int DayIncreaseMoneyrate;
        public int Type { get; }

        public PolicyData(int troll = 0, int carry = 0, int money = 0, int type = (int)USERDEFINE.POLICYLIST.BASE)
        {
            DayIncreaseTrollrate = troll;
            DayInceeaseCarryrate = carry;
            DayIncreaseMoneyrate = money;
            Type = type;
        }

        public float[] GetRates()
        {
            float[] arr = { DayIncreaseTrollrate * 0.01f, DayInceeaseCarryrate * 0.01f, DayIncreaseMoneyrate * 0.01f };
            return arr;
        }

        public static readonly PolicyData Base = new PolicyData(0, 0, 0, (int)USERDEFINE.POLICYLIST.BASE);
        public static readonly PolicyData Capitalism = new PolicyData(10, 10, 100, (int)USERDEFINE.POLICYLIST.CAPITALISM);
        public static readonly PolicyData Quarantinism = new PolicyData(5, 30, 100, (int)USERDEFINE.POLICYLIST.QUARANTINISM);
        public static readonly PolicyData Liberalism = new PolicyData(20, 20, 100, (int)USERDEFINE.POLICYLIST.LIBERALISM);
        public static readonly PolicyData Anarchism = new PolicyData(100, 0, 0, (int)USERDEFINE.POLICYLIST.ANARCHISM);


    }
    public struct QuarantineData
    {
        int n;//예시임ㅇㅇ
        //무조건 다시짜야함
        public QuarantineData(int _n) { n = 0; }
    }
    public struct ArticleData
    {
        public string Title { get; }
        public string Content { get; }
        public string Attribute { get; }

        public PolicyData PolicyChange { get; }
        public QuarantineData QuarantineChange { get; }
        public Popular PopChange { get; }
        public int Money { get; }
        public float ADrhari { get; }
        public bool Chackflag { get; private set; }

        public ArticleData(string _Title, string _Content, string _Attribute,
                            PolicyData _PD, QuarantineData _QD, Popular _Pop, 
                            int _Money, int _ADrhari, bool _Chack)
        {
            Title = _Title;
            Content = _Content;
            Attribute = _Attribute;

            PolicyChange = _PD;
            QuarantineChange = _QD;
            PopChange = _Pop;
            Money = _Money;
            ADrhari = _ADrhari;
            Chackflag = _Chack;
        }

        public void ChangeChackflag()
        {
            Chackflag = false;
        }

        public static readonly ArticleData Base = new ArticleData("Title", "Content", "Attribute_1\nAttribute_2\nAttribute_3", PolicyData.Base, new QuarantineData(), new Popular(), 0, 0, true);

    }


}