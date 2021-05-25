using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// * -> 책과 다르게 친 부분
//! -> 처음 본 구문
public class RFscript : MonoBehaviour {
    //생성위치 담을 배열
    public Transform[] points;
    //생성할 객체의 프리팹
    public GameObject resourcefab;
    //객체를 미리 생성해 저장할 리스트자료형
    public List<GameObject> resourcepool = new List<GameObject>();

    //발생 주기
    public float CreateTime = 0.5f;
    //최대 발생 갯수
    public int maxResource = 15;
    //게임 종료 여부 변수
    public bool isGameOver = false;
    //싱글톤 패턴을 위한 인스턴수 변수 선언
    public static RFscript instance = null;//(자기 자신을 선언하기 위한 변수)
    public int maxCount = 0;


    void Awake()
    {
        CreateTime = Random.Range(1.5f, 3.0f);
        //RFscript 클래스를 인스턴스에 대입
        instance = this;
    }

    // Use this for initialization
    void Start () {
        //하이라키 뷰의 SpawnPoint를 찾아 하위에 있는 모든 Transform 컴포넌트를 찾아옴!
        points = GameObject.Find("SpawnPoint").GetComponentsInChildren<Transform>();

        //자원을 생성해 오브젝트 풀에 저장
        for (int i = 0; i < maxResource; i++)
        {
            //자원 프리팹을 생성
            GameObject resource = (GameObject)Instantiate(resourcefab);
            //생성한 자원 비활성화
            resource.SetActive(false);
            //생성한 자원을 오브젝트 풀에 추가
            resourcepool.Add(resource);
        }

        if (points.Length > 0) {
            //자원의 생성 코루틴 함수 호출!
            StartCoroutine(this.CreateResource());
        }

	}

    //자원 생성 코루틴 함수!
    IEnumerator CreateResource()
    {
        //게임 종료시 까지 루프
        while (!isGameOver) {
            //자원 생성 주기 시간 만큼 메인 루프에 양보
            yield return new WaitForSeconds(CreateTime);
            //게임 종료시 코루틴을 종료해 다음 루틴을 진행하지 않음
            if (isGameOver) yield break;
            //오브젝트 풀의 처음부터 끝까지 순회
            foreach (GameObject resource in resourcepool) {//!
                //비 활성화 여부로 사용 가능한 자원을 판단
                if (!resource.activeSelf) {//!
                    //자원을 출현 시킬 위치의 인덱스값을 추출
                    int idx = Random.Range(1, points.Length);
                    //자원의 출현 위치 설정
                    resource.transform.position = points[idx].position + 
                                                new Vector3(Random.Range(-1.0f, 1.0f), Random.Range(-1.0f, 1.0f), 0.0f);
                    //자원 활성화
                    resource.SetActive(true);
                    if (maxCount != maxResource)
                    {
                        maxCount++;
                    }
                    //오브젝트 풀에서 몬스터 프리팹 하나를 활성화 한 후 for 루프 빠져나감
                    break;
                }
            }
           
        }
    }

    

	// Update is called once per frame
	void Update () {
		

	}


	
    

}
