
using UnityEngine;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public class CSVParsing
{
    //문자열의 키워드는 https://docs.microsoft.com/ko-kr/dotnet/api/system.text.regularexpressions.regex?view=netframework-4.8 여기 참조
    //코드는 http://minpaprograming.blogspot.com/2019/06/unity-csv-file-read-csv-android-possible.html 여기 참조
    /*정규표현식 위키백과 참조
     *.         -> 1개의 문자와 일치,   단일행 모드에서는 새줄문자 제외
     * []       -> [ 와 ] 사이의 문자 중 하나선택   |를 여러개 쓴것과 같은 의미    또한 -를 쓰면 범위지정 가능
     * [^ ]     -> 문자 클래스 내의 문자를 제외한 나머지 선택
     * ^        -> 문자열이나 행의 처음을 의미
     * $        -> 문자열이나 행의 끝을 의미
     * ()       -> 하위식으로, 여러식을 하나로 묶을 수 있다.
     * \n       -> 일치하는 패턴들 중 n번째를 선택   1 - 9 중 하나가 올수 있다
     * *        -> 0개 이상의 문자 포함
     * {m, n}   -> m회 이상 n회 이하 문자 선택
     * 

    */
    public static string Split_Re = @",(?=(?=:[^""]*""[^""]*"")*(?![^""]*""))";//정규식형태 정의 => Split_re는 왼쪽의 형태로 정의

    public static string Line_Splite_Re = @"\r\n|\n\r|\n\r";//줄단위로 끊음

    public static char[] Trim_Chars = { '\"' };//큰떠옴표 = 문자열 종료문자

    public static List<Dictionary<string, object>> Read(string file)
    {
        var list = new List<Dictionary<string, object>>();
        TextAsset data = Resources.Load(file) as TextAsset;
        var lines = Regex.Split(data.text, Line_Splite_Re);
        if (lines.Length <= 1) return list;
        var header = Regex.Split(lines[0], Split_Re);
        for (var i = 1; i < lines.Length; i++)
        {
            var values = Regex.Split(lines[i], Split_Re);
            if (values.Length == 0 || values[0] == "") continue;
            var entry = new Dictionary<string, object>();
            for (var j = 0; j < header.Length && j < values.Length; j++)
            {
                string value = values[j];
                value = value.TrimStart(Trim_Chars).TrimEnd(Trim_Chars).Replace("\\", "");
                object finalvalue = value;
                int n;
                float f;
                if (int.TryParse(value, out n))
                {
                    finalvalue = n;
                }
                else if (float.TryParse(value, out f))
                {
                    finalvalue = f;
                }
                entry[header[j]] = finalvalue;
            }
            list.Add(entry);
        }
        return list;
    }


}
