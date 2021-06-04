using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Net;
using System.Net.Sockets;
using System.Threading;


/*
 비동기적 클라이언트 데이터를 읽기위한 StateObject정의
 */
public class StateObject{
    public const int Buffersize = 1024;
    //받을 버퍼의 크기

    public byte[] buffer = new byte[Buffersize];
    //수신용 버퍼 설정및 초기화

    public System.Text.StringBuilder sb = new System.Text.StringBuilder();
    //받을 데이터 문자열

    public Socket WorkSocket = null;
    //클라이언트 소켓
}
//https://docs.microsoft.com/ko-kr/dotnet/framework/network-programming/asynchronous-server-socket-example
//https://www.google.com/search?q=C%23+socket%EB%B9%84%EB%8F%99%EA%B8%B0+%EC%84%9C%EB%B2%84&oq=C%23+socket%EB%B9%84%EB%8F%99%EA%B8%B0+%EC%84%9C%EB%B2%84&aqs=chrome..69i64j0i333l3j69i57.3763j0j9&sourceid=chrome&ie=UTF-8
public class AsynchronousSocketListener {
    public static ManualResetEvent allDone = new ManualResetEvent(false);
    //쓰레드 신호

    public AsynchronousSocketListener(){}

    public static void StartListening() {
        
    }
}
public class Prac_Network : MonoBehaviour
{
    
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
