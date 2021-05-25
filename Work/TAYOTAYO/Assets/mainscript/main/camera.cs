

using UnityEngine;
using System.Collections;



public class camera : MonoBehaviour {
    public GameObject A;
    Transform AT;
    public static GameObject B ;
    Hashtable ht = new Hashtable();
   
	// Use this for initialization
	void Start () {
        AT = A.transform;
    }
	
	// Update is called once per frame
	void Update () {
        

        CameraMove(gameroot.EdeadFlag);
        //transform.position = Vector2.Lerp(transform.position, AT.position, 2f * Time.deltaTime);
        //카메라 이동을 좀더 부드럽게(Lerp함수는 Update에 넣어야 프레임이 어긋나지 않음)
        //3D도 가능
        transform.Translate(0, 0, -10);




    }
    void CameraMove(bool a)
    {
        
        switch (a) {

            case false:
                transform.position = Vector2.Lerp(transform.position, AT.position, 2.0f * Time.deltaTime);
                
                break;
                
            case true:
                for (int i = 0; i < 10; i++) {

                    transform.position = Vector2.Lerp(transform.position, AT.position, 2f * Time.deltaTime*-1.0f) ;
                }

                gameroot.EdeadFlag = false;

                break;
        }
        
    }
}

