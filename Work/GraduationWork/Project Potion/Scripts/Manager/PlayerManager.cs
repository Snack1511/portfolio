using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using Custom;
/*
 * 플레이어 생성 및 읽기 전용
 */
public class PlayerManager
{
    
    public const float Dist = 20;//플레이어 스폰 위치정보
    public int Leaveplayer;//남은 플레이어 수
    public int PlayerCount = 0;//전체 플레이어 수
    PlayerSet[] PlayerDatas;//플레이어들의 데이터 읽기용
    public PlayerInput[] InputPlayers;//플레이어들의 조작관련 읽기용
    // -> ControlMgr로 뺄 수 있을듯
    public GameObject Winner;//승자 저장용
    Vector3[] pos = {
        new Vector3(-Dist, 3, 0), new Vector3(Dist, 3, 0), new Vector3(0, 3, -Dist), new Vector3(0, 3, Dist)
    };//사전생성위치

    //List<Player_Cal> PlayersCalculates = new List<Player_Cal>();
    public PlayerManager(SelectData[] Selected)
    {
        InputPlayers = new PlayerInput[4];
        PlayerDatas = new PlayerSet[4];
        for (int i = 0; i < Selected.Length; i++)
        {
            if (Selected[i].IsActive())
            {
                InputPlayers[i] = PlayerInput.Instantiate(Resources.Load<GameObject>("Prefabs/PlayerObj"), Selected[i].GetIndex(), GetScheme.GetSchemeDatas(Selected[i].GetDVName()), -1, Selected[i].GetInputDv());
                InputPlayers[i].GetComponent<PlayerSet>().ModelName = Selected[i].GetName();
                InputPlayers[i].GetComponent<PlayerSet>().ColorNum = Selected[i].GetIndex();
                PlayerDatas[i] = InputPlayers[i].GetComponent<PlayerSet>();
                //PlayersCalculates.Add(InputPlayers[i].GetComponent<Player_Cal>());

                PlayerCount++;

            }
        }
    }

    
    public void ResetPlayerMgr()
    {
        for (int i = 0; i < PlayerCount; i++)
        {
            //Debug.Log(PlayersCalculates[i]);
            /*if (PlayersCalculates[i] != null)
            {
                PlayersCalculates[i].gameObject.transform.position = pos[i];
                PlayersCalculates[i].GetComponent<PlayerSet>().ResetData();
                PlayersCalculates[i].gameObject.SetActive(true);
                
            }*/
            if (PlayerDatas[i] != null)
            {
                PlayerDatas[i].gameObject.transform.position = pos[i];
                PlayerDatas[i].GetComponent<PlayerSet>().ResetData();
                PlayerDatas[i].gameObject.SetActive(true);

            }
        }
        Leaveplayer = 0;
    }//플레이어변수들 초기화

    public void GivePointToPlayer(int RoundNum)
    {
        for (int i = 0; i < PlayerCount; i++)
        {
            /*if (PlayersCalculates[i].gameObject.activeSelf)
            {
                PlayerDatas[i].GetPlayerData().POINT = 1;
                PlayerDatas[i].GetPlayerData().CalTotalPoint(RoundNum);
            }*/
            if (PlayerDatas[i].gameObject.activeSelf)
            {
                PlayerDatas[i].GetPlayerData().POINT = 1;
                PlayerDatas[i].GetPlayerData().CalTotalPoint(RoundNum);
            }
        }
    }//플레이어변수에 점수할당

    public bool GetWinner()
    {
        for (int i = 0; i < PlayerCount; i++)
        {
            if (/*PlayerDatas[i] != null && */PlayerDatas[i].GetPlayerData().POINT >= 15)
            {
                Winner = PlayerDatas[i].gameObject;
                return false;
            }
        }
        return true;
    }//승자설정

    public bool InputNextButton()
    {
        if (InputPlayers[0].currentControlScheme == "Keyboard")
        {
            if (InputPlayers[0].actions["Attack"].phase == InputActionPhase.Waiting)
            {
                return true;
            }
        }
        else
        {
            if (InputPlayers[0].actions["Dash"].phase == InputActionPhase.Waiting)
            {
                return true;
            }
        }
        return false;
    }//플레이어확인버튼 입력

    public bool InputAnyButton()
    {
        if ((Gamepad.current.IsPressed() && Gamepad.current.wasUpdatedThisFrame)
            || (Keyboard.current.IsPressed() && Keyboard.current.wasUpdatedThisFrame))
        {
            return true;
        }
        else return false;
    }

    public bool IsLeaveBiggerThanPlayer()
    {
        
        if (Leaveplayer >= PlayerCount - 1) return true;
        else return false;
    }

    public PlayerSet[] ReadPlyerDatas()
    {
        return PlayerDatas;
    }
    public int SetLeavePlayer()
    {
        Leaveplayer++;
        return PlayerCount - (Leaveplayer - 1);
    }
    public void SetGamePause()
    {
        for (int i = 0; i < PlayerDatas.Length; i++) {
            if(PlayerDatas[i].CALLMENU != GameManager.GM.GamePauseflg)
            {
                PlayerDatas[i].CALLMENU = GameManager.GM.GamePauseflg;
            }
        }
    }
}
