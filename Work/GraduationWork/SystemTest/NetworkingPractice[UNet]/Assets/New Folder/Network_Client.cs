using System;
using System.Collections;
using System.Collections.Generic;

using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Threading.Tasks;

using UnityEngine;
using UnityEngine.UI;


/*
 소켓 객체 생성 -> 서버 연결 -> 데이터 송신및 수신 -> 소켓 해제
 */
public class Network_Client : MonoBehaviour
{
    Socket Cli_Sock;
    IPHostEntry hostEntry;
    IPAddress ipAdd;
    IPEndPoint Ep;

    Text IP_String;
    InputField inputText_IPstring;
    byte[] bytes;
    IPAddress ipAdd_custom;
    IPEndPoint EP_Custom;

    private void Awake()
    {
        inputText_IPstring = GameObject.Find("InputField").GetComponent<InputField>();
        Cli_Sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        hostEntry = Dns.GetHostEntry("localhost");
        Debug.Log(hostEntry.HostName);
        ipAdd = new IPAddress(hostEntry.AddressList[0].GetAddressBytes());
        Ep = new IPEndPoint(ipAdd.MapToIPv4(), 7777);
        //Cli_Sock.Connect(Ep);
    }
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.A)){
            Debug.Log(EP_Custom);
            Cli_Sock.Connect(EP_Custom);
        }
    }

    

    private void OnDestroy()
    {
        Cli_Sock.Disconnect(false);
        Cli_Sock.Close();
    }


    public void SetIP() {

        //inputText_IPstring.text;

        ipAdd_custom = IPAddress.Parse(inputText_IPstring.text);
        EP_Custom = new IPEndPoint(ipAdd_custom, 7777);


    }
}
