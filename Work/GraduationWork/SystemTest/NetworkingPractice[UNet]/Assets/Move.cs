using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class Move : NetworkBehaviour
{
    int count = 0;

    [ClientRpc]
    public void RpcPlayerConnected() {//Rpc라는 접두사 추가해야함
        Debug.Log("Client Rpc Call.");
    }

    [Command]//클라이언트의 플레이어오브젝트 -> 서버의 플레이어오브젝트
    public void CmdTestFunction(int i) {//Cmd라는 접두사 추가해야함
        Debug.Log("Command Function Call. " + i);
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.A)) {
            CmdTestFunction(count++);
            Debug.Log("InputA. " + count);
        }
    }
}
