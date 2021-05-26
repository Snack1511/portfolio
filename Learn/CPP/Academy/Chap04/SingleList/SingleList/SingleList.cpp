#include<iostream>
#include<string>

using namespace std;

struct Node 
{
	int data;
	Node* next;
};

class SingleList 
{
public:
	Node* Head;
	SingleList() 
	{
		Head = nullptr;
	}
	void addNode(int _data) 
	{
		Node* newNode = new Node();		//새로운 노드 생성

		newNode->data = _data;			//새로운 Node의 data에 _data적용
		newNode->next = nullptr;		//새로운 Node의 Next에 nullptr적용

		Node* temPoint = Head;			//tempPoint에 Head 값으로 초기화

		//temPoint가 nullptr이면
		if (temPoint == nullptr) 
		{
			Head = newNode; //Head에 newNode 적용
		}
		else 
		{
			//temPoint next가 nullptr이 아닐 때 까지
			while (temPoint->next != nullptr) 
			{
				temPoint = temPoint->next;//temPoint에다가 next node적용
			}

			temPoint->next = newNode;//temPoint의 next에다가 newNode적용
		}

	}

	void DeleteNode(int _data)
	{
		Node* temPoint = Head;//tempPoint에 Head 값으로 초기화
		Node* prevNode; //이전 노드를 가리키게 하는 노드

		//temPoint 가 nullptr이 아닐때까지
		while (temPoint != nullptr) 
		{
			//data가 temPoint의 data와 같다면
			if (_data == temPoint->data) 
			{
				//temPoint 가 Head라면
				if (temPoint == Head)
				{
					//Head는 temPoint의 next적용
					Head = temPoint->next;
				}
				else //아닐경우
				{
					//prevNode next sms temPoint의 next;
					prevNode->next = temPoint->next;
				}

				//temPoint 지워주고 꺠고 나가기
				delete temPoint;
				temPoint = nullptr;
				break;
			}
			//prevNode는 temPoint
			prevNode = temPoint;
			//temPoint는 temPointNext
			temPoint = temPoint->next;
		}

	}
public:
	SingleList();
	~SingleList();

private:

};

SingleList::SingleList() 
{
	
}
SingleList::~SingleList() 
{

}