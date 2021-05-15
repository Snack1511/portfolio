using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Threading.Tasks;


/*
 리스너 소켓 생성 -> 바인드 -> 연결대기 -> 연결수락

http://www.csharpstudy.com/net/article/10-Socket-%ec%84%9c%eb%b2%84
https://docs.microsoft.com/ko-kr/dotnet/api/system.net.ipaddress?view=net-5.0
https://docs.microsoft.com/ko-kr/dotnet/api/system.net.sockets.addressfamily?view=net-5.0
 */
public class Network_Server : MonoBehaviour
{
    Socket Listener_Sock;
    public static ManualResetEvent allDone = new ManualResetEvent(false);
    Socket Cli_Sock;
    IPHostEntry hostEntry;
    IPAddress ipAdd;
    IPEndPoint Ep;
    Text txt;
    // Start is called before the first frame update
    private void Awake()
    {
        txt = GameObject.Find("Debug_Text").GetComponent<Text>();
        Listener_Sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        Ep = new IPEndPoint(IPAddress.Any, 7777);
        Debug.developerConsoleVisible = true;
        


    }
    void Start()
    {
        Listener_Sock.Bind(Ep);
        Task.Run(() => AsyncListen(Listener_Sock));
        Debug.Log("Hello");
        //Listener_Sock.Listen(1);
    }

    // Update is called once per frame
    void Update()
    {

    }
    private void OnDestroy()
    {
        Cli_Sock.Close();
        Listener_Sock.Close();
    }

    async Task AsyncListen(Socket sock) {
        if (!sock.Connected)
        {
            Debug.Log(sock + ".IsConnnect" +" : "+ !sock.Connected);

            sock.Listen(3);
            Debug.Log("Listen Complete");

            //await Task.Delay(3000);
            //Debug.Log("Delay 3Second");

            await AsyncAccept(sock);
            Debug.Log("Cli_Sock -> ListenSock.Accept");
        }
        Debug.Log("Connecting End");
        
    }
    async Task AsyncAccept(Socket sock) {
        Cli_Sock = sock.Accept();
        //await Task.Delay(3000);
    }
    /*
     루프백 주소에 클라이언트가 접속을 몬함 시벌
    왜일까는 모르겠고 암튼안됨
    생각해라 프로그래머
     */
}
