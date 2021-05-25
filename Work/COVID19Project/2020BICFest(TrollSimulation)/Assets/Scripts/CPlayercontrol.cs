using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class CPlayercontrol : MonoBehaviour
{
    Camera MainCam, SubCam, TargetingCam;
    Ray Mousepoint;
    RaycastHit target;
    float mousewheelInput;
    public string OnMouseCity, OnClickCity;
    public bool TogglePanelfalg, ClickFlag;
    public Vector3 PanelPos;
    public Rect FloatingPanelPos;
    public Vector3 CompareCitiesCenterPos;

    void Start()
    {
        MainCam = GameObject.Find("MainCamera").gameObject.GetComponent<Camera>();
        SubCam = GameObject.Find("SubCamera").gameObject.GetComponent<Camera>();
        CompareCitiesCenterPos = GameObject.Find("Cities").transform.position;
        TargetingCam = MainCam;

        OnClickCity = "NoneData";

        TogglePanelfalg = false;
        ClickFlag = false;
    }
    
    void Update()
    {
        TargetingCam = SetCam(Input.mousePosition.x);
        Mousepoint = TargetingCam.ScreenPointToRay(Input.mousePosition);
        mousewheelInput = Input.GetAxis("Mouse ScrollWheel");

        OnMouse(TargetingCam, Mousepoint, out target);
        zoominout(TargetingCam, mousewheelInput);
        
        
    }

    bool ChackRay(Ray _ray, out RaycastHit _hit)
    {
        if (Physics.Raycast(_ray, out _hit))
        {
            //Debug.Log(_hit.collider.gameObject.name);
            //city = _hit.collider.gameObject.name;
            return true;
        }
        else return false;
    }//오브젝트 확인용 레이발사함수

    Camera SetCam(float posx) {
        if (posx <= MainCam.pixelRect.max.x)
        {
            return MainCam;
            
        }
        else {
            return SubCam;
        }
        
    }//마우스가 위치한 스크린을 비춰주는 카메라 타겟팅함수

    void SetCamRotate(bool flag)
    {
        if (flag && TargetingCam == MainCam)
        {
            MainCam.GetComponent<Transform>().rotation = Quaternion.Euler(41, -4, 0);
        }
        else
        {
            MainCam.GetComponent<Transform>().rotation = Quaternion.Euler(41, 0, 0);
        }
    }//클릭시 카메라 회전

    string GetCitiesName(Ray _ray, out RaycastHit _hit) {
        if (ChackRay(_ray, out _hit)) { return _hit.collider.gameObject.name; }
        else { return "None"; }
    }//mousepos에 있는 obj의 이름 저장

    void zoominout(Camera cam, float wheel) {
        if (cam.gameObject.name == "MainCamera")
        {
            cam.fieldOfView -= mousewheelInput;
        }
        else if (cam.gameObject.name == "SubCamera")
        {

        }
    }//마우스스크롤시 동작함수

    public void OnMouse(Camera cam, Ray ray, out RaycastHit hit) {
        if (Input.GetMouseButtonDown(0))
        {
            ClickFlag = true;
            OnClick(cam, ray, out hit);
        }
        else
        {
            ClickFlag = false;
            if (ChackRay(ray, out hit))
            {
                if (hit.collider.CompareTag("TAG_CITY"))
                {
                    OnMouseCity = hit.collider.gameObject.name;
                    PanelPos = Input.mousePosition+ new Vector3(50, 0, 0);
                    FloatingPanelPos.xMin = Input.mousePosition.x - 80;
                    FloatingPanelPos.xMax = Input.mousePosition.x + 80;
                    FloatingPanelPos.yMin = Input.mousePosition.y - 45;
                    FloatingPanelPos.yMax = Input.mousePosition.y + 45;
                    TogglePanelfalg = true;

                }
            }
            else
            {
                OnMouseCity = "None";
                //PanelPos = Input.mousePosition + new Vector3(50, 0, 0);
                TogglePanelfalg = false;
            }
        }
    }//마우스 위치 시

    public void OnClick(Camera cam, Ray ray, out RaycastHit hit) {
        if (cam.gameObject.name == "MainCamera")
        {
            if (ChackRay(ray, out hit)) {
                if (hit.collider.CompareTag("TAG_CITY"))
                {
                    OnClickCity = hit.collider.gameObject.name;
                    SetCamRotate(true);
                }
            }
            else
            {
                OnClickCity = "NoneData";
                SetCamRotate(false);
            }
        }
        else if (cam.gameObject.name == "SubCamera")
        {
            if (ChackRay(ray, out hit)) { }
            
        }
        else hit = new RaycastHit();
    }//마우스클릭시 동작함수
    //메인뷰 클릭시 패널 토글
    //서브뷰 클릭시 기타동작


    


}
