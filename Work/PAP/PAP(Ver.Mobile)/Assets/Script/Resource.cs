using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Resource : MonoBehaviour {

    
	// Update is called once per frame
	void Update () {
        //자원의 태그가 Untagged일 때
        if (gameObject.tag == "Untagged")
        {
            //자원 오브젝트폴로 환원시키는 코루틴 함수 호출
            StartCoroutine(this.PushObjectPool());
        }
	}

    IEnumerator PushObjectPool()
    {
        yield return new WaitForSeconds(0.0f);

        //각종 변수 초기화
        gameObject.SetActive(false);
        gameObject.tag = "Resource";
        
    }



}
