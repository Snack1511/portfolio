using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

public class DataMGr : MonoBehaviour {
    [System.Serializable]
    public class Person
    {
        public string Weapon;
        public string Name;
        public int Level;
        public int Hp;
        public int Sp;
        public int statpoint;

        /*public Person(string _weapon, string _name, int _level, int _hp, int _sp, int _statpoint) 
        {
            Weapon = _weapon;
            Name = _name;
            Level = _level;
            Hp = _hp;
            Sp = _sp;
            statpoint = _statpoint;
        }*/
        public string show() 
        {
            return "Weapon Kind : " + Weapon + 
            "\nName : " + Name +
            "\nLevel : " + Level+
            "\nHp : " + Hp +
            "\nSp : " + Sp +
            "\nstatpoint : " + statpoint;
        }
        
    }


    string filePath = string.Empty;
    Person person;
    int n = 0;

	// Use this for initialization
	void Start () {
        filePath = Application.dataPath + "/test"+n+".txt";
        person = new Person();
        //person = new Person ("칼", "Player", 99, 100, 50, 99);
	}


    public void OnClickSave() 
    {
        n++;
        filePath = Application.dataPath + "/test" + n + ".txt";
        BinarySerialize<Person>(person, filePath);
    }
    public void OnClickLoad()
    {
        if (System.IO.File.Exists(filePath)) 
        {
            person = BinaryDeserialzie<Person>(filePath);
            Debug.Log(person.show());
        }
    }

    public void BinarySerialize<T>(T t, string _filePath) //<제너릭클래스>바이너리 파일저장
    {
        BinaryFormatter formatter = new BinaryFormatter();//바이너리 포맷클래스 생성
        FileStream stream = new FileStream(filePath, FileMode.Create);//파일스트림 클래스 및 파일생성(경로, 파일모드)
        formatter.Serialize(stream, t);//_person 클래스 기록
        stream.Close();//스트림 클래스 제거
    }
    public T BinaryDeserialzie<T>(string _filePath) //<제너릭클래스>바이너리 파일읽기
    {
        BinaryFormatter formatter = new BinaryFormatter();
        FileStream stream = new FileStream(_filePath, FileMode.Open);
        T t = (T)formatter.Deserialize(stream);
        stream.Close();

        return t;
    }
}
