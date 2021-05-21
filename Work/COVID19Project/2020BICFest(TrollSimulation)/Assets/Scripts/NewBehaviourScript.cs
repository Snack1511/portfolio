using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour
{
    public string m_strCSVFilename = string.Empty;

    class Tempdata
    {
        public int index;
        public string testString;
        public int testInt;
        public float testFloat;
        public int usertestInt2;

    }

    List<Tempdata> m_tempData = new List<Tempdata>();

    void Start()
    {
        List<Dictionary<string, object>> m_dictionaryData = CSVParsing.Read(m_strCSVFilename);
        for (int i = 0; i < m_dictionaryData.Count; i++)
         
        {

            m_tempData.Add(new Tempdata());



            m_tempData[i].index = int.Parse((m_dictionaryData[i]["Index"].ToString()));

            m_tempData[i].testString = m_dictionaryData[i]["TestString"].ToString();

            m_tempData[i].testInt = int.Parse(m_dictionaryData[i]["TestInt"].ToString());

            m_tempData[i].testFloat = float.Parse(m_dictionaryData[i]["TestFloat"].ToString());

            m_tempData[i].usertestInt2 = int.Parse(m_dictionaryData[i]["UserTestInt2"].ToString());

        }



        for (int i = 0; i < m_tempData.Count; i++)

        {

            Debug.Log("Index : " + m_tempData[i].index 
                + ", TestString : " + m_tempData[i].testString 
                + ", TestInt : " + m_tempData[i].testInt 
                + ", TestFloat : " + m_tempData[i].testFloat
                +", UserTestInt2 : " + m_tempData[i].usertestInt2);

        }

    }
}

