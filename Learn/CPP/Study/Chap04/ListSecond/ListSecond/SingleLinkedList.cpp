#include "SingleLinkedList.h"



void SingleLinkedList::Push_Back(int _data) 
{
	SNode* newNode = new SNode;
	newNode->iVal = _data;

	SNode*lastNode = GetLastNode();
	lastNode->pNext = newNode;
}

//SingleLinkedList::SNode* SingleLinkedList::GetLastNode()
//{
//	SNode* pTempNode = m_pHead;
//	while (pTempNode->pNext != nullptr) 
//	{
//		pTempNode = pTempNode->pNext;
//	}
//	return pTempNode;
//}

SNode* SingleLinkedList::GetLastNode()
{
	SNode* pTempNode = m_pHead;
	while (pTempNode->pNext != nullptr)
	{
		pTempNode = pTempNode->pNext;
	}
	return pTempNode;
}

SingleLinkedList::SingleLinkedList():m_pHead(nullptr)
{
	m_pHead = new SNode;
}


SingleLinkedList::~SingleLinkedList()
{

}
