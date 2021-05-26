#pragma once
#include"Struct.h"
class SingleLinkedList
{
public:
	/*struct SNode
	{
		int iVal;
		SNode* pNext;
	};*/

private:
	SNode* m_pHead;
public:
	void Push_Back(int _data);
	SNode* GetLastNode();

public:
	SingleLinkedList();
	~SingleLinkedList();
};

